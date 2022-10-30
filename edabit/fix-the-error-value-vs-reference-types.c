/*

Create a function that returns true if two arrays contain identical values, and false otherwise.

To solve this question, your friend writes the following code:

function checkEquals(arr1, arr2) {
if (arr1 === arr2) {
  return true
 } else {
  return false
 }
}

But testing the code, you see that something is not quite right. Running the code yields the following results:

checkEquals([1, 2], [1, 3]) ➞ false
// Good so far...

checkEquals([1, 2], [1, 2]) ➞ false
// Yikes! What happened?

Rewrite your friend's code so that it correctly checks if two arrays are equal. The tests below should pass:
Examples

checkEquals([1, 2], [1, 3]) ➞ false

checkEquals([1, 2], [1, 2]) ➞ true

checkEquals([4, 5, 6], [4, 5, 6]) ➞ true

checkEquals([4, 7, 6], [4, 5, 6]) ➞ false

Notes

Hint: This has to do with value vs. reference types.

*/

#include <assert.h>
#include <stdbool.h>
#include <stdio.h>
#include <string.h>

#define nelem(x) (sizeof(x) / sizeof(x[0]))

bool
eq(int *a, int *b, size_t n)
{
	return memcmp(a, b, n * sizeof(*a)) == 0;
}

int
main(void)
{
	int a1[] = { 1, 2 };
	int b1[] = { 1, 3 };

	int a2[] = { 1, 2 };
	int b2[] = { 1, 2 };

	int a3[] = { 4, 5, 6 };
	int b3[] = { 4, 5, 6 };

	int a4[] = { 4, 7, 6 };
	int b4[] = { 4, 5, 6 };

	assert(eq(a1, b1, nelem(a1)) == false);
	assert(eq(a2, b2, nelem(a2)) == true);
	assert(eq(a3, b3, nelem(a3)) == true);
	assert(eq(a4, b4, nelem(a4)) == false);

	return 0;
}
