// Program that sorts to get nearest birthday

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#include <errno.h>
#define ARRAY_SIZE(x) (sizeof(x) / sizeof(x[0]))

/* default specifications based on the homework */
#define INPUT_FILE "birthday.txt"

enum {
	MAX_NAME_LEN = 30,
	MAX_STUDENTS = 1000,
};

/* the struct to store the student info */
struct student_info {
	char first[MAX_NAME_LEN];
	char last[MAX_NAME_LEN];
	int day, month, year;
	int birthday_sum;
};

/* the functions prototypes */
static void run_simulation(const char *filename);
static void quicksort(struct student_info *students, int start, int end);
static int partition(struct student_info *students, int start, int end);
static void swap(struct student_info *a, struct student_info *b);
static void build_table(void);
static int min(int a, int b);

enum {
	JANUARY,
	FEBRUARY,
	MARCH,
	APRIL,
	MAY,
	JUNE,
	JULY,
	AUGUST,
	SEPTEMBER,
	OCTOBER,
	NOVEMBER,
	DECEMBER
};

/* this is a table to convert months string into a number */
static const char *months[] = {
    "JANUARY",
    "FEBRUARY",
    "MARCH",
    "APRIL",
    "MAY",
    "JUNE",
    "JULY",
    "AUGUST",
    "SEPTEMBER",
    "OCTOBER",
    "NOVEMBER",
    "DECEMBER",
};

static int scale_factor_normal[12];
static int scale_factor_leap[12];

int
main(void)
{
	build_table();
	run_simulation(INPUT_FILE);
	return 0;
}

/* build the table for the scaling of the month
 * as we read them in */
static void
build_table(void)
{
	int i;
	const int tbl[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

	scale_factor_normal[0] = 0;
	scale_factor_leap[0] = 0;

	for (i = 1; i != ARRAY_SIZE(tbl); ++i) {
		scale_factor_normal[i] += scale_factor_normal[i - 1] + tbl[i - 1];
		scale_factor_leap[i] = scale_factor_normal[i] + 1;
	}
	scale_factor_leap[1] = 31;
}

/* quicksort algorithm based on the professor guha's notes */
static void
quicksort(struct student_info *students, int start, int end)
{
	int split;
	if (start < end) {
		split = partition(students, start, end);
		quicksort(students, start, split - 1);
		quicksort(students, split + 1, end);
	}
}

static int
partition(struct student_info *students, int start, int end)
{
	int low, high, temp;
	int pivot = (start + end) / 2;

	swap(&students[start], &students[pivot]);

	if (start >= end)
		return end;

	low = start + 1;
	high = end;

	while (low <= high) {
		while (low <= high &&
		       students[low].birthday_sum < students[start].birthday_sum)
			++low;

		while (high >= low) {
			if (students[high].birthday_sum > students[start].birthday_sum)
				--high;
			/* standard quicksort as usual up until here, where we
			 * have to handle the case where the students have the same
			 * birthday, we check their last name and first name */
			else if (students[high].birthday_sum ==
			         students[start].birthday_sum) {
				/* this works by checking last name first, then first name,
				 * if strcmp returns less than 0, we know the name is
				 * supposed to be to the right of the current pivot,
				 * so we keep going as usual like above, if not,
				 * then we swap low with high and then increment low */
				temp = strcmp(students[start].last, students[high].last);
				if (temp < 0)
					--high;
				else if (temp == 0) /* last name are equal, check first */
				{
					temp = strcmp(students[start].first,
					              students[high].first);
					if (temp <= 0)
						--high;
					else
						goto swap_case;
				} else /* the swap case where the names differ */
				{
				swap_case:
					swap(&students[low], &students[high]);
					++low;
					break;
				}
			} else if (low < high) /* swap the birthdays */
			{
				swap(&students[low], &students[high]);
				break;
			}
		}
	}
	/* put the pivot into the right place at the end */
	swap(&students[start], &students[high]);

	return high;
}

/* standard swap function */
static void
swap(struct student_info *a, struct student_info *b)
{
	struct student_info temp;
	temp = *a;
	*a = *b;
	*b = temp;
}

static int
min(int a, int b)
{
	return (a < b) ? a : b;
}

/* run the simulation */
static void
run_simulation(const char *filename)
{
	int leap, *scale_factor;
	int i, k, j, x, y, runs, num_students, num_queries, temp[6];
	char str[80], str1[80];
	FILE *fp;
	struct student_info *students;

	if (!(fp = fopen(filename, "r"))) {
		printf("Error opening the file: %s\n", strerror(errno));
		return;
	}

	if (!(students = malloc(sizeof(struct student_info) *
	                        (MAX_STUDENTS + 1)))) {
		printf("Cannot allocate enough memory for operation! Exiting!\n");
		goto done;
	}

	fscanf(fp, "%d", &runs);
	for (i = 0; i < runs; i++) {
		fscanf(fp, "%d", &num_students);
		/* shouldn't happen but as a precaution */
		if (num_students > MAX_STUDENTS) {
			printf("%d students found, ", num_students);
			printf("but only %d students can be handled! ", MAX_STUDENTS);
			printf("Exiting!\n");
			goto done;
		} else if (num_students < 2) {
			printf("%d students found. ", num_students);
			printf("At least n > 1 students is needed to run! ");
			printf("Exiting!\n");
			goto done;
		}

		leap = 0;
		for (k = 0; k < num_students; k++) {
			fscanf(fp, "%29s %29s %29s %d %d", students[k].first,
			       students[k].last, str,
			       &students[k].day, &students[k].year);

			/* convert month string into a number, since it's only
			 * 12 months, binary search isn't really needed here */
			for (j = 0; j != ARRAY_SIZE(months); ++j) {
				if (!strcmp(months[j], str)) {
					students[k].month = j;
					break;
				}
			}
			if (j == ARRAY_SIZE(months)) {
				printf("%s not valid month! Exiting!\n", str);
				goto done;
			}

			/* is the input a leap year? */
			if (students[k].month == FEBRUARY &&
			    students[k].day == 29)
				leap = 1;
		}

		/* we combine the month and day into one number to make it easier
		 * to sort */
		scale_factor = (leap) ? scale_factor_leap : scale_factor_normal;
		for (k = 0; k < num_students; k++)
			students[k].birthday_sum = scale_factor[students[k].month] +
			                           students[k].day;

		fscanf(fp, "%d", &num_queries);

		/* shouldn't happen but as a precaution */
		if (num_queries > num_students) {
			printf("Too much queries for the given student size! ");
			printf("Exiting!\n");
			goto done;
		}

		/* sort the student birthday */
		quicksort(students, 0, num_students - 1);

		leap += 365;

		printf("Class #%d:\n\n", i + 1);

		for (k = 0; k < num_queries; k++) {
			fscanf(fp, "%29s %29s", str, str1);
			/* find the student name, then we
			 * take the left or the right */
			for (j = 0; j != num_students; ++j) {
				if (!(strcmp(students[j].first, str) ||
				      strcmp(students[j].last, str1))) {
					/* found the name, now we do
					 * some checking */
					x = j - 1;
					y = (j + 1) % num_students;
					if (x < 0)
						x = num_students - 1;

					/* get the distances forward */
					temp[0] = abs(students[j].birthday_sum -
					              students[x].birthday_sum);
					temp[1] = abs(students[j].birthday_sum -
					              students[y].birthday_sum);

					/* get the distances backwards and forward
					 * that wrap arounds */
					temp[2] = students[j].birthday_sum + leap -
					          students[x].birthday_sum;
					temp[3] = students[j].birthday_sum + leap -
					          students[y].birthday_sum;

					temp[4] = leap - students[j].birthday_sum +
					          students[x].birthday_sum;
					temp[5] = leap - students[j].birthday_sum +
					          students[y].birthday_sum;

					/* take the minimum distances out of the 3 */
					temp[0] = min(temp[0], min(temp[2], temp[4]));
					temp[1] = min(temp[1], min(temp[3], temp[5]));

					/* if the one to the left is farther/equal
					 * than the one to the right */
					if (temp[0] >= temp[1])
						x = y;

					printf("%s %s has the closest birthday to %s %s.\n",
					       students[x].first, students[x].last,
					       str, str1);
					break;
				}
			}
		}
		printf("\n");
	}

/* cleanup */
done:
	free(students);
	fclose(fp);
}
