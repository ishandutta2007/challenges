/*

Your task: given a number n, generate a '+' sign that is n characters away from its center. If this is confusing, check out the test cases.

Standard methods of input: output must be a string or printed. Standard loopholes apply.

Input: 1
Output: +           ] 1 away from center `+`.

Input: 2
Output:  +          ] 2 away from center `+`.
        +++         ] 1 away from center `+`.
         +

Input: 3
Output:   +         ] 3 away from center `+`.
          +
        +++++
          +
          +
This is code-golf, so shortest code wins!

*/

#include <stdio.h>

void
plusworld(int n)
{
	int i, j, s;

	printf("N=%d\n", n);
	s = (2 * n) - 1;
	for (i = 0; i < s; i++) {
		for (j = 0; j < s; j++) {
			if (i == s / 2 || j == s / 2)
				printf("+");
			else
				printf(" ");
		}
		printf("\n");
	}
	printf("\n");
}

int
main(void)
{
	plusworld(1);
	plusworld(2);
	plusworld(3);

	return 0;
}
