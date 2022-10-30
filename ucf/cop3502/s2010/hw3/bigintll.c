// bignum addition

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <errno.h>

struct integer {
	int digit;
	struct integer *next;
};

// Preconditions: the first parameter is string that stores
//                only contains digits, doesn't start with
//                0, and is 200 or fewer characters long.
// Postconditions: The function will read the digits of the
//	large integer character by character,
//	convert them into integers and place them in
//	nodes of a linked list. The pointer to the //	head of the list is returned.
struct integer *convert_integer(char *stringInt);

// Preconditions: p is a pointer to a big integer, stored in
//                reverse order, least to most significant
//                digit, with no leading zeros.
// Postconditions: The big integer pointed to by p is
//                 printed out.
void print(struct integer *p);

// Preconditions: p and q are pointers to big integers,
//                stored in reverse order, least to most
//                significant digit, with no leading zeros.
// Postconditions: A new big integer is created that stores
//                 the sum of the integers pointed to by p
//                 and q and a pointer to it is returned.
struct integer *add(struct integer *p, struct integer *q);

// Preconditions: p and q are pointers to big integers,
//                stored in reverse order, least to most
//                significant digit, with no leading zeros.
// Postconditions: A new big integer is created that stores
//                 the absolute value of the difference
//                 between the two and a pointer to this is
//                 returned.
struct integer *subtract(struct integer *p, struct integer *q);

// Preconditions: Both parameters of the function are
//	pointers to struct integer.
// Postconditions: The function compares the digits of two
//	numbers recursively and returns:
//     -1 if the first number is smaller than the second,
//      0 if the first number is equal to the second number,
//    1 if the first number is greater than the second.
int compare(struct integer *p, struct integer *q);

struct integer *alloc_integer(int size);
int integer_size(struct integer *p);
void free_integer(struct integer *p);

// assume input is a positive number so don't check
// for negatives or anything, from assignment specifications.
// MAIN
#define READ_FILE "bigint.txt"
int
main(void)
{
	// assume max digits is 200
	char digit[256], digit1[256];
	int i, n = 0, type, type1;
	FILE *fp;
	struct integer *p, *q, *r;

	fp = fopen(READ_FILE, "r");
	if (!fp) {
		printf("Error opening file %s: %s\n", READ_FILE, strerror(errno));
		return 1;
	}
	// assume all inputs are proper (from assign. spec.)
	fscanf(fp, "%d", &n);
	// loop to the number specified in the first element of file
	for (i = 0; i != n; ++i) {
		// get the data
		fscanf(fp, "%d %200s %200s", &type, digit, digit1);
		// convert to bignum representation
		p = convert_integer(digit);
		q = convert_integer(digit1);
		// figure out type
		if (type == 1)
			r = add(p, q);
		else if (type == 2)
			r = subtract(p, q);
		else
			continue;
		// if can't allocate memory, just quit
		if (!r) {
			printf("Failed to allocate memory for this operation!\n");
			free_integer(p);
			free_integer(q);
			free_integer(r);
			break;
		}
		// print out the info
		if (type == 1)
			print(p);
		else {
			type1 = compare(p, q);
			print((type1 > 0) ? p : q);
		}
		printf(" %c ", (type == 1) ? '+' : '-');
		if (type == 1)
			print(q);
		else
			print((type1 > 0) ? q : p);
		printf(" = ");
		print(r);
		printf("\n");
		// free the memory for the next data
		free_integer(p);
		free_integer(q);
		free_integer(r);
	}

	fclose(fp);
	return 0;
}

// function to allocate a linked list
// of 'size' nodes
struct integer *
alloc_integer(int size)
{
	struct integer *p = NULL, *temp, *current;
	int i;

	if (!size)
		return NULL;

	if (!(p = malloc(sizeof(struct integer))))
		return NULL;

	p->digit = 0;

	for (current = p, i = 1; i != size; ++i) {
		temp = malloc(sizeof(struct integer));
		if (!(current->next = temp))
			goto fail;
		temp->digit = 0;
		current = current->next;
	}
	current->next = NULL;
	return p;

fail:
	free_integer(p);
	return NULL;
}

// get the size of a linked list
int
integer_size(struct integer *p)
{
	int counter = 0;
	while (p) {
		++counter;
		p = p->next;
	}
	return counter;
}

// delete a linked list
void
free_integer(struct integer *p)
{
	struct integer *temp = p;
	while (temp != NULL) {
		temp = p->next;
		free(p);
		p = temp;
	}
}

struct integer *
convert_integer(char *stringInt)
{
	struct integer *p, *temp;
	int len;
	char t[2] = {'\0'};
	len = strlen(stringInt);

	// allocate before-hand to save
	// alot of trouble doing it one by one
	// as we are converting the digits
	if (!(p = alloc_integer(len)))
		return NULL;
	temp = p;
	// go from end to start, since the assignment specifies
	// the numbers are stored lsb to msb
	while (--len >= 0) {
		// for locales
		if (!isdigit(stringInt[len]))
			goto fail;
		t[0] = stringInt[len];
		temp->digit = strtol(t, NULL, 10);
		temp = temp->next;
	}
	return p;

// any fail case winds up here
fail:
	free_integer(p);
	return NULL;
}

// print out the integers here
// in backward order using recursion
void
print(struct integer *p)
{
	if (p == NULL)
		return;
	print(p->next);
	printf("%d", p->digit);
}

struct integer *
add(struct integer *p, struct integer *q)
{
	int i, k, maximum, minimum;
	struct integer *result, *templl, *big;
	// sanity check
	if (!(p && q))
		return NULL;

	i = integer_size(p);
	k = integer_size(q);
	maximum = compare(p, q);
	// figure out which is the bigger number, used for adding later numbers
	if (maximum > -1) {
		maximum = i;
		minimum = k;
		big = p;
	} else {
		maximum = k;
		minimum = i;
		big = q;
	}

	// allocate enough for the largest possible sum
	result = alloc_integer(maximum + 1);

	if (!result)
		return NULL;

	for (templl = result, i = 0; i != maximum; ++i) {
		// the smaller number to add, so do the big one only
		if (i >= minimum)
			templl->digit += big->digit;
		else // still have enough places to add the 2 numbers
		{
			templl->digit += p->digit + q->digit;
			p = p->next;
			q = q->next;
		}
		// carry
		if (templl->digit > 9) {
			templl->digit %= 10;
			++templl->next->digit;
		}
		// update the linked list location
		templl = templl->next;
		big = big->next;
	}

	// figure out the size of the linked list
	// of result
	struct integer *last = templl = result;
	while (templl) {
		if (templl->digit > 0)
			last = templl;
		templl = templl->next;
	}
	// free the areas that isn't used
	// by the addition, to get printing right
	// and save space
	free_integer(last->next);
	last->next = NULL;
	return result;
}

struct integer *
subtract(struct integer *p, struct integer *q)
{
	int i, maximum, minimum, temp, borrow;
	struct integer *result, *big, *small, *templl;
	// sanity check
	if (!(p && q))
		return NULL;

	// figure out which is the bigger number and smaller number
	// to subtract
	i = compare(p, q);
	big = p;
	small = q;
	maximum = integer_size(p);
	minimum = integer_size(q);

	if (i == -1) {
		small = p;
		big = q;
		maximum = integer_size(q);
		minimum = integer_size(p);
	}
	// allocate enough for the maximum integer
	result = alloc_integer(maximum + 1);

	if (!result)
		return NULL;

	for (templl = result, borrow = i = 0; i != minimum; ++i) {
		temp = big->digit + templl->digit; // add the borrow here
		if (temp < small->digit)           // for a[n] < b[n] in a - b
		{
			if (temp < 0) // for 0 since it will borrow no matter what
				borrow = 1;
			templl->digit = -(temp + 10 - small->digit);
		} else
			templl->digit = temp - small->digit;

		if (templl->digit < 0 || borrow) // check for underflow or borrow
		{
			// do borrows here and fix the sign
			templl->digit = -templl->digit;
			--templl->next->digit;
			borrow = 0;
		}
		templl = templl->next;
		big = big->next;
		small = small->next;
	}
	// ran out of place to subtract for smaller number so only
	// do bigger number here
	for (; i != maximum; ++i) {
		if (big->digit + templl->digit < 0) {
			templl->digit += 10 + big->digit;
			--templl->next->digit;
		} else
			templl->digit += big->digit;
		templl = templl->next;
		big = big->next;
	}

	// figure out the size of it
	struct integer *last = templl = result;
	while (templl) {
		if (templl->digit > 0)
			last = templl;
		templl = templl->next;
	}
	// free space here to get printing
	// right and save memory
	free_integer(last->next);
	last->next = NULL;

	return result;
}

int
compare(struct integer *p, struct integer *q)
{
	int i, k;
	// to compare transverse through the linked list
	// as long as the nodes are not NULL
	while (p && q) {
		// if the digits don't match at this node
		// save the digit for comparison later
		if (p->digit != q->digit) {
			i = p->digit;
			k = q->digit;
		}
		p = p->next;
		q = q->next;
	}
	// p ended before q, meaning q is bigger
	if (!p && q)
		return -1;
	// q ended before p, meaning p is bigger
	if (p && !q)
		return 1;

	// since they have the same number of digits
	// we test the most recent place that have
	// differing digits, that should tell us if
	// which number is bigger
	if (i > k)
		return 1;

	if (k > i)
		return -1;

	// they are equal here
	return 0;
}
