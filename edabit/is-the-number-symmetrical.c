/*

Create a function that takes a number as an argument and returns true or false depending on whether the number is symmetrical or not. A number is symmetrical when it is the same as its reverse.
Examples

IsSymmetrical(7227) ➞ true

IsSymmetrical(12567) ➞ false

IsSymmetrical(44444444) ➞ true

IsSymmetrical(9939) ➞ false

IsSymmetrical(1112111) ➞ true

*/

#include <assert.h>
#include <stdbool.h>
#include <stdio.h>
#include <inttypes.h>

bool
symmetrical(uintmax_t x)
{
	char b[sizeof(x) * 8];
	int i, l;

	l = snprintf(b, sizeof(b), "%ju", x);
	for (i = 0; i < l / 2; i++) {
		if (b[i] != b[l - i - 1])
			return false;
	}
	return true;
}

int
main(void)
{
	uintmax_t i;

	assert(symmetrical(UINTMAX_C(7227)) == true);
	assert(symmetrical(UINTMAX_C(12567)) == false);
	assert(symmetrical(UINTMAX_C(44444444)) == true);
	assert(symmetrical(UINTMAX_C(9939)) == false);
	assert(symmetrical(UINTMAX_C(1112111)) == true);
	assert(symmetrical(UINTMAX_C(23)) == false);
	assert(symmetrical(UINTMAX_C(9562)) == false);
	assert(symmetrical(UINTMAX_C(10019)) == false);
	assert(symmetrical(UINTMAX_C(1)) == true);
	assert(symmetrical(UINTMAX_C(3223)) == true);
	assert(symmetrical(UINTMAX_C(95559)) == true);
	assert(symmetrical(UINTMAX_C(66566)) == true);

	for (i = 0; i <= 10000; i++) {
		if (symmetrical(i))
			printf("%ju\n", i);
	}

	return 0;
}
