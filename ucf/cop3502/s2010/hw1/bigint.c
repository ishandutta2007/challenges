// Bignum addition

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <errno.h>

struct integer {
	int *digits;
	int size;
};

// Preconditions: the first parameter is string that stores
//                only contains digits, doesn't start with
//                0, and is 200 or fewer characters long.
// Postconditions: The function will read the digits of the
//	large integer character by character,
//	convert them into integers and return a
//              pointer to the appropriate struct integer.
struct integer *convert_integer(char *stringInt);

// Preconditions: p is a pointer to a big integer.
// Postconditions: The big integer pointed to by p is
//                 printed out.
void print(struct integer *p);

// Preconditions: p and q are pointers to struct integers.
// Postconditions: A new struct integer is created that
//                 stores the sum of the integers pointed to
//                 by p and q and a pointer to it is
//                 returned.
struct integer *add(struct integer *p, struct integer *q);

// Preconditions: p and q are pointers to struct integers.
// Postconditions: A new struct integer is created that
//                 stores the absolute value of the
//                 difference between the two and a pointer
//                 to this is returned.
struct integer *subtract(struct integer *p, struct integer *q);

// Preconditions: Both parameters of the function are
//	  pointers to struct integer.
// Postconditions: The function compares the digits of two
//	numbers and returns:
//     -1 if the first number is smaller than the second,
//      0 if the first number is equal to the second number,
//    1 if the first number is greater than the second.
int compare(struct integer *p, struct integer *q);

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

void
free_integer(struct integer *p)
{
	free(p->digits);
	free(p);
}

struct integer *
convert_integer(char *stringInt)
{
	struct integer *p = NULL;
	int i, len;
	char t[2] = {'\0'};
	len = strlen(stringInt);
	// allocate memory

	if (!(p = (struct integer *)calloc(1, sizeof(struct integer))))
		return NULL;

	if (!(p->digits = (int *)malloc(len * sizeof(int))))
		goto fail;

	// go from end to start, since the assignment specifies
	// the numbers are stored lsb to msb
	for (i = 0; --len >= 0;) {
		// for locales
		if (!isdigit(stringInt[len]))
			goto fail;
		t[0] = stringInt[len];
		p->digits[i++] = strtol(t, NULL, 10);
		++p->size;
	}
	return p;

	// any fail case winds up here
fail:
	free(p->digits);
	free(p);
	return NULL;
}

void
print(struct integer *p)
{
	int i;
	if (!p)
		return;
	// loop through the array printing out the numbers
	for (i = p->size; --i >= 0;)
		printf("%d", p->digits[i]);
}

struct integer *
add(struct integer *p, struct integer *q)
{
	int i, maximum, minimum, *big;
	struct integer *result;
	// sanity check
	if (!(p && q))
		return NULL;

	// figure out which is the bigger number, used for adding later numbers
	if (p->size > q->size) {
		maximum = p->size;
		minimum = q->size;
		big = p->digits;
	} else {
		maximum = q->size;
		minimum = p->size;
		big = q->digits;
	}

	if (!(result = (struct integer *)calloc(1, sizeof(struct integer))))
		return NULL;

	// allocate enough for the largest possible sum
	result->digits = (int *)calloc(1, (maximum + 1) * sizeof(int));

	if (!result->digits) {
		free(result);
		return NULL;
	}

	for (i = 0; i != maximum; ++i) {
		// the smaller number to add, so do the big one only
		if (i >= minimum)
			result->digits[i] += big[i];
		else // still have enough places to add the 2 numbers
			result->digits[i] += p->digits[i] + q->digits[i];
		// carry
		if (result->digits[i] > 9) {
			result->digits[i] %= 10;
			++result->digits[i + 1];
		}
	}
	// store size
	result->size = maximum + result->digits[maximum];
	return result;
}

struct integer *
subtract(struct integer *p, struct integer *q)
{
	int i, maximum, minimum, temp, borrow;
	int *big, *small;
	struct integer *result;
	// sanity check
	if (!(p && q))
		return NULL;

	// figure out which is the bigger number and smaller number
	// to subtract
	i = compare(p, q);
	big = p->digits;
	small = q->digits;
	maximum = p->size;
	minimum = q->size;

	if (i == -1) {
		small = p->digits;
		big = q->digits;
		maximum = q->size;
		minimum = p->size;
	}

	if (!(result = (struct integer *)calloc(1, sizeof(struct integer))))
		return NULL;

	// allocate enough for the largest largest possible difference
	result->digits = (int *)calloc(1, (maximum + 1) * sizeof(int));

	if (!result->digits) {
		free(result);
		return NULL;
	}

	for (borrow = i = 0; i != minimum; ++i) {
		temp = big[i] + result->digits[i]; // add the borrow here
		if (temp < small[i])               // for a[n] < b[n] in a - b
		{
			if (temp < 0) // for 0 since it will borrow no matter what
				borrow = 1;
			result->digits[i] = -(temp + 10 - small[i]);

		} else
			result->digits[i] = temp - small[i];

		if (result->digits[i] < 0 || borrow) // check for underflow or borrow
		{
			// do borrows here and fix the sign
			result->digits[i] = -result->digits[i];
			--result->digits[i + 1];
			borrow = 0;
		}
	}

	// ran out of place to subtract for smaller number so only
	// do bigger number here
	for (; i != maximum; ++i) {
		if (big[i] + result->digits[i] < 0) {
			result->digits[i] = result->digits[i] + 10 + big[i];
			--result->digits[i + 1];
		} else
			result->digits[i] += big[i];
	}

	// figure out the size of it by going backwards to the first
	// non zero digit
	while (--i) {
		if (result->digits[i] > 0)
			break;
	}
	result->size = i + 1; // of course we need to add 1
	return result;
}

int
compare(struct integer *p, struct integer *q)
{
	int i;
	// size is all that matters
	if (p->size > q->size)
		return 1;
	else if (q->size > p->size)
		return -1;

	// or not, loop backwards, breaking out of the first digit found to
	// be greater. for same number of digit case
	i = p->size;
	while (--i >= 0) {
		if (p->digits[i] > q->digits[i])
			return 1;
		else if (q->digits[i] > p->digits[i])
			return -1;
	}
	return 0;
}
