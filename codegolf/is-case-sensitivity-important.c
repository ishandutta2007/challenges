/*

Tom is going to implement a new programming language of his invention. But before actually starting working on it, he wants to know whether his language should be case sensitive or not.

On one hand, case insensitivity seems more easy to implement to him, but he worries that it could cause a lack in the possibilities of combinations of characters that form a variable,
meaning that longer variable names should then be used to avoid naming clashes (for an example, you can use Hello, HEllo, heLLo and a bunch of other possibilities if the language is case sensitive, but only HELLO if not).

But Tom is a meticulous person, so just a worry isn't enough for him. He wants to know the numbers.

The challenge

Write a function (or a full program if your language doesn't support them) that, given an integer n as the input, outputs (or returns) the difference in the number of permutations possible for a string of length n with case sensitivity and without.

In Tom's language, variable names can include all alphabet letters, underscores and, starting from the second character, digits.

Testcases

Input (length of the variable) -> Output (difference between the possibilities with case sensitivity and the possibilities with case insensitivity)
0 -> 0
1 -> 26
2 -> 2340
5 -> 784304586
8 -> 206202813193260
9 -> 13057419408922746

Non-competing C++ reference implementation

void diff(int n) {
    long long total[2] = {0, 0}; //array holding the result for case insensivity ([0]) and case sensitivity ([1])

    for (int c = 1; c <= 2; c ++) //1 = insensitivity, 2 = sensitivity
        for (int l = 1; l <= n; l ++) //each character of the name
            if (l == 1)
                total[c - 1] = 26 * c + 1; //first character can't be a number
            else
                total[c - 1] *= 26 * c + 1 + 10; //starting from the second character, characters can include numbers

    std::cout << total[1] - total[0] << std::endl;
}

Scoring

Tom likes golf, so the shortest program in bytes wins.

Note

It's okay if maybe the last two testcases aren't right because of numerical precision. After all, I am not even sure my code handled number 9 correctly.

*/

#include <assert.h>

typedef unsigned long long uvlong;

uvlong
diff(uvlong n)
{
	uvlong r[2];
	uvlong c, l;

	r[0] = r[1] = 0;
	for (c = 1; c <= 2; c++) {
		for (l = 1; l <= n; l++) {
			if (l == 1)
				r[c - 1] = 26 * c + 1;
			else
				r[c - 1] *= 26 * c + 11;
		}
	}
	return r[1] - r[0];
}

int
main(void)
{
	assert(diff(0) == 0);
	assert(diff(1) == 26);
	assert(diff(2) == 2340);
	assert(diff(5) == 784304586ULL);
	assert(diff(8) == 206202813193260ULL);
	assert(diff(9) == 13057419408922746ULL);

	return 0;
}
