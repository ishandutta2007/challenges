/*

Given an int, figure out how many ones, threes and nines you could fit into the number. You must create a class. You will make variables(self.ones, self.threes, self.nines) to do this.
Examples

n1 = ones_threes_nines(5)
n1.nines ➞ 0

n1.ones ➞ 5

n1.threes ➞ 1

Notes

    Do not use the math module.
    See version #2 of this series.

*/

#include <assert.h>
#include <string.h>

typedef struct {
	int ones;
	int threes;
	int nines;
} Fit;

Fit
ones_threes_nines(int x)
{
	Fit f;

	memset(&f, 0, sizeof(f));
	if (x <= 0)
		return f;
	f.ones = x;
	f.threes = x / 3;
	f.nines = x / 9;
	return f;
}

int
main(void)
{
	Fit n1 = ones_threes_nines(0);
	Fit n2 = ones_threes_nines(1);
	Fit n3 = ones_threes_nines(2);
	Fit n4 = ones_threes_nines(3);
	Fit n5 = ones_threes_nines(4);
	Fit n6 = ones_threes_nines(10);
	Fit n7 = ones_threes_nines(13);
	Fit n8 = ones_threes_nines(15);
	Fit n9 = ones_threes_nines(17);
	Fit n10 = ones_threes_nines(20);

	assert(n1.ones == 0);
	assert(n2.threes == 0);
	assert(n3.nines == 0);
	assert(n4.ones == 3);
	assert(n5.threes == 1);
	assert(n6.nines == 1);
	assert(n7.ones == 13);
	assert(n8.threes == 5);
	assert(n9.nines == 1);
	assert(n10.nines == 2);

	return 0;
}
