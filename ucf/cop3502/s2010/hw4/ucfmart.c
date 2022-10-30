// Simulates a market using queues

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <errno.h>

#define INPUT_FILE "customer.txt"

/* limits based on the assignment */
enum {
	MAX_EXPRESS = 1,
	MAX_LINE = 3,
	MAX_PEOPLE = 8,
	MAX_NAME_LEN = 30,
	MAX_ITEMS = 1000,
	MAX_EXPRESS_ITEMS = 10,
	MAX_TIME = 25200,
};

/* the struct of the person entering
 * the line, linked list based */
struct person_info {
	char name[MAX_NAME_LEN];
	int items, line;
	long checkin_time, checkout_time;
	struct person_info *next;
};

/* this is to save memory for a linked
 * list that points to a linked list
 * of person, this makes it easy to keep
 * all the lines in sorted order
 * (since we do it incrementally) */
struct person_info_p {
	struct person_info *person;
	struct person_info_p *next;
};

/* the queue struct */
struct queue_info {
	struct person_info *person[MAX_LINE];
	struct person_info *front[MAX_LINE], *back[MAX_LINE];
	struct person_info_p *sorted_line;
	int curline;
	int line_size[MAX_LINE];
};

/* function prototypes */
static struct queue_info *queue_alloc(void);
static void ll_free(struct person_info *p);
static void queue_free(struct queue_info *q);
static int enqueue(struct queue_info *q, struct person_info *p);
static void queue_check_and_flush(struct queue_info *q,
                                  struct person_info *p);
static void queue_flush(struct queue_info *q);
static void run_simulation(const char *filename);
static void print_checkin(struct person_info *p);
static void print_checkout(struct person_info *p);

int
main(void)
{
	/* run the simulation */
	run_simulation(INPUT_FILE);
	return 0;
}

/* allocate memory for one queue */
static struct queue_info *
queue_alloc(void)
{
	struct queue_info *q;
	if (!(q = calloc(1, sizeof(struct queue_info))))
		return NULL;
	q->curline = MAX_EXPRESS;

	return q;
}

/* frees a linked list */
static void
ll_free(struct person_info *p)
{
	void *temp = p;
	while (temp) {
		temp = p->next;
		free(p);
		p = temp;
	}
}

/* free one queue_alloc */
static void
queue_free(struct queue_info *q)
{
	int i;
	void *temp;
	/* free the person linked list in the queue */
	for (i = 0; i != MAX_LINE; ++i)
		ll_free(q->person[i]);
	/* free the sorted line linked list */
	while (q->sorted_line) {
		temp = q->sorted_line;
		q->sorted_line = q->sorted_line->next;
		free(temp);
	}
	/* free the queue itself */
	free(q);
}

/* this adds one new person to the queue */
static int
enqueue(struct queue_info *q, struct person_info *p)
{
	int i, k;
	struct person_info *temp = NULL;
	struct person_info_p *ptemp = NULL, *pstore, *piter;

	/* allocate memory for a sorted line node and a node
	 * for the person for the linked lists */
	if (!(temp = malloc(sizeof(struct person_info))) ||
	    !(ptemp = malloc(sizeof(struct person_info_p)))) {
		free(temp);
		free(ptemp);
		return -1;
	}

	/* if the items are less than or equal to max express items
	 * we go to the express line */
	if (p->items <= MAX_EXPRESS_ITEMS)
		p->line = 0;
	else /* else alternate between the normal lines */
		p->line = q->curline;

	/* if the current line is full, the person
	 * will go to the next free line */
	if (q->line_size[p->line] == MAX_PEOPLE) {
		/* this for line in the express line */
		if (p->line < MAX_EXPRESS) {
			/* try to find the next free express line */
			for (k = 0, i = (p->line + 1) % MAX_EXPRESS; k != MAX_EXPRESS;
			     i = (i + 1) % MAX_EXPRESS, ++k) {
				if (q->line_size[i] < MAX_PEOPLE) {
					p->line = i;
					break;
				}
			}
			/* if we can't find any express, the person should go to the
			 * next free normal line */
			if (k == MAX_EXPRESS) {
				for (k = 0, i = q->curline; k != MAX_LINE - MAX_EXPRESS;
				     ++k) {
					if (q->line_size[i] < MAX_PEOPLE) {
						/* found the free line break out */
						p->line = i;
						break;
					}
					/* this is so that the indices reset
					 * so it can go around a ring trying to find
					 * all the normal line */
					if ((i += 1) == MAX_LINE)
						i = MAX_EXPRESS;
				}
				/* this is when all the normal lines are also full,
				 * though it should never happened since we are
				 * guaranteed that no more lines will be needed to
				 * serve all the customers */
				if (k == MAX_LINE - MAX_EXPRESS)
					return -2;
			}
		} else /* this is for the person in a current normal line */
		{
			/* first we search through the normal line */
			for (k = 0; k != MAX_LINE - MAX_EXPRESS - 1; ++k) {
				i = p->line + 1;
				if (i == MAX_LINE)
					i = MAX_EXPRESS;

				if (q->line_size[i] < MAX_PEOPLE) {
					p->line = i;
					break;
				}
			}
			/* this is if we can't find any
			 * free normal line, we go to the express
			 * line */
			if (k == MAX_LINE - MAX_EXPRESS) {
				for (i = 0; i != MAX_EXPRESS; ++i) {
					if (q->line_size[i] < MAX_PEOPLE) {
						/* found it break out */
						p->line = i;
						break;
					}
				}
				/* should never happened, since
				 * we are guaranteed that no more
				 * customers will use up all the line
				 * so break out */
				if (i == MAX_EXPRESS)
					return -2;
			}
		}
	}
	/* this is for alternating between the normal lines
	 * after a person has entered a line */

	/* make sure the current person is in the normal line */
	if (p->line >= MAX_EXPRESS) {
		/* if they are, alternate the line so the next customer
		 * in the normal line will go into it */
		if ((q->curline = p->line + 1) == MAX_LINE)
			q->curline = MAX_EXPRESS;
	}
	/* copy the data into the temp linked list */
	*temp = *p;
	temp->next = NULL;
	ptemp->next = NULL;
	ptemp->person = temp;

	/* if the line is initially empty we make it front and
	 * the checkout time is simply checkin + blah */
	if (!q->back[p->line]) {
		temp->checkout_time = temp->checkin_time +
		                      (temp->items * 6) + 40;
		/* since this is the initial front is equal to back */
		q->front[p->line] = temp;
	} else /* the current line is not empty */
	{
		/* so the checkout time for that person is the checkout
		 * time of the previous customer added with how many items
		 * the guy have based on the formula in the assignment */
		temp->checkout_time = q->back[p->line]->checkout_time +
		                      (temp->items * 6) + 40;
		q->back[p->line]->next = temp;
	}

	/* if the sorted line is empty
	 * linked list the first one */
	if (!q->sorted_line)
		q->sorted_line = ptemp;
	else /* it is not so we do some stuff here */
	{
		/* go from the beginning to the end finding the first
		 * node whose checkout time is greater than the current
		 * customer checkout time */
		for (pstore = piter = q->sorted_line; piter != NULL;
		     pstore = piter, piter = piter->next) {
			if (piter->person->checkout_time > temp->checkout_time) {
				ptemp->next = piter;
				if (pstore != piter)
					pstore->next = ptemp;
				else
					q->sorted_line = ptemp;
				break;
			}
		}
		if (!piter)
			pstore->next = ptemp;
	}

	/* print the checkin */
	print_checkin(p);
	/* add it to the back, since queues are FIFO */
	q->back[p->line] = temp;
	/* increment the line size */
	++q->line_size[p->line];
	return 0;
}

/* this is run whenever a new customer enters the line,
 * flushing out any older person, to keep the timestamps
 * in order */
static void
queue_check_and_flush(struct queue_info *q,
                      struct person_info *p)
{
	void *temp, *line[MAX_LINE];
	int i;
	for (i = 0; i != MAX_LINE; ++i)
		line[i] = q->front[i];

	/* for every nodes that has a less checkout time than
	 * the current checkin time, print out that node
	 * (which is the customer) and dequeue it from the line */
	while (q->sorted_line &&
	       q->sorted_line->person->checkout_time < p->checkin_time) {
		/* print out the checkout time */
		print_checkout(q->sorted_line->person);

		/* we store the current front customer in the temp array
		 * for relinking the front and back later on */
		line[q->sorted_line->person->line] = q->sorted_line->person->next;

		/* decrease the line size for every person in that
		 * line is freed */
		--q->line_size[q->sorted_line->person->line];

		/* free that customer */
		temp = q->sorted_line;
		free(q->sorted_line->person);
		q->sorted_line = q->sorted_line->next;
		free(temp);
	}
	/* we relink all the nodes here to keep the line
	 * in order, and make sure all the freed customers
	 * are out */
	for (i = 0; i != MAX_LINE; ++i) {
		/* if the front is NULL, meaning
		 * all the customers for that line
		 * is freed, make sure the back is NULL too */
		if ((q->front[i] = line[i]) == NULL)
			q->back[i] = NULL;
	}
}

/* this is ran whenever there are no more customers
 * coming in the line, it flushes out all the
 * customers in order */
static void
queue_flush(struct queue_info *q)
{
	struct person_info_p *temp;
	/* go through the sorted line linked list
	 * and print the checkout time and free them */
	while (q->sorted_line) {
		print_checkout(q->sorted_line->person);
		temp = q->sorted_line;
		q->sorted_line = q->sorted_line->next;
		free(temp->person);
		free(temp);
	}
	/* since this is a flush of everything, we
	 * reset everything to how it was like in
	 * queue_alloc() */
	memset(q, 0, sizeof(struct queue_info));
	q->curline = MAX_EXPRESS;
}

/* the function to print out the checkout time of a person */
static void
print_checkout(struct person_info *p)
{
	printf("%ld:%02ld:%02ld%s: Customer %s checking out of line %c waited %ld seconds.\n",
	       (1 + (p->checkout_time / 3600)) % 12,
	       (p->checkout_time / 60) % 60,
	       (p->checkout_time % 60),
	       ((((1 + (p->checkin_time / 3600)) / 12) % 2) == 1) ? "am" : "pm",
	       p->name, 'A' + p->line, p->checkout_time - p->checkin_time);
}

/* the function to print out the checkin time of a person */
static void
print_checkin(struct person_info *p)
{
	printf("%ld:%02ld:%02ld%s: Customer %s checking in line %c.\n",
	       (1 + (p->checkin_time / 3600)) % 12,
	       (p->checkin_time / 60) % 60,
	       (p->checkin_time % 60),
	       ((((1 + (p->checkin_time / 3600)) / 12) % 2) == 1) ? "am" : "pm",
	       p->name, 'A' + p->line);
}

/* the function that runs the simulation based on the
 * given input file */
static void
run_simulation(const char *filename)
{
	FILE *fp;
	int i, t, k, number_of_people, runs, line;
	struct queue_info *q;
	struct person_info person;

	/* try opening the input file, if failed, quit */
	if (!(fp = fopen(filename, "r"))) {
		printf("Error: %s\n", strerror(errno));
		goto done;
	}

	/* allocate the queue for the operation */
	if (!(q = queue_alloc())) {
		printf("Failed to allocate enough memory for operation!\n");
		return;
	}

	/* get how many days we are supposed to run */
	fscanf(fp, "%d", &runs);

	for (line = 1, i = 0; i < runs; i++) {
		/* get the number of people */
		fscanf(fp, "%d", &number_of_people);
		/* the number of people has to be at least greater than 1 */
		if (number_of_people < 1) {
			printf("Error reading on line: %d. ", line + 1);
			printf("Too much or too few people than the program can do.\n");
			printf("Exiting!\n");
			break;
		}

		/* print out the day of the simulation that we are on */
		printf("Day #%d:\n\n", i + 1);

		/* loop that reads in all the people for that day */
		for (k = 0; k != number_of_people; ++k) {
			/* get all the info */
			fscanf(fp, "%ld", &person.checkin_time);
			fscanf(fp, "%30s", person.name);
			fscanf(fp, "%d", &person.items);

			/* sanity check for the entered input */
			if (person.checkin_time < 0 || person.checkin_time > MAX_TIME ||
			    person.items < 0 || person.items > MAX_ITEMS) {
				printf("Error at line %d. Exiting.\n", line + 3 + k);
				goto done;
			}
			/* we first check the queue to see if anyone checkout
			 * time is less than this person checkin time and
			 * we flush them out first before adding this person in,
			 * this is to keep the timestamps all correct. */
			queue_check_and_flush(q, &person);
			/* then we add in a person */
			t = enqueue(q, &person);

			/* this is if we failed to add in a person */
			if (t == -1) {
				printf("Cannot allocate memory for adding a person!");
				printf("Exiting!\n");
				goto done;
			} else if (t == -2) {
				printf("Line full! Exiting!\n");
				goto done;
			}
		}
		/* no more person for that day, so
		 * we simply flush out all the customers in the line
		 * printing them in order of time */
		queue_flush(q);
		line += number_of_people;
		printf("\n\n");
	}

	/* we are done, clean up and return */
done:
	if (fp)
		fclose(fp);
	queue_free(q);
}
