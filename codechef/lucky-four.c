/*

Kostya likes the number 4 much. Of course! This number has such a lot of properties, like:

    Four is the smallest composite number;
    It is also the smallest Smith number;
    The smallest non-cyclic group has four elements;
    Four is the maximal degree of the equation that can be solved in radicals;
    There is four-color theorem that states that any map can be colored in no more than four colors in such a way that no two adjacent regions are colored in the same color;
    Lagrange's four-square theorem states that every positive integer can be written as the sum of at most four square numbers;
    Four is the maximum number of dimensions of a real division algebra;
    In bases 6 and 12, 4 is a 1-automorphic number;
    And there are a lot more cool stuff about this number!

Impressed by the power of this number, Kostya has begun to look for occurrences of four anywhere.
He has a list of T integers, for each of them he wants to calculate the number of occurrences of the digit 4 in the decimal representation. He is too busy now, so please help him.

*/
#include <stdio.h>

int
fours(int n)
{
	char b[80];
	int i, l, c;

	c = 0;
	l = snprintf(b, sizeof(b), "%d", n);
	for (i = 0; i <= l; i++) {
		if (b[i] == '4')
			c++;
	}
	return c;
}

int
main(void)
{
	printf("%d\n", fours(447474));
	printf("%d\n", fours(228));
	printf("%d\n", fours(6664));
	printf("%d\n", fours(40));
	printf("%d\n", fours(81));
	return 0;
}
