/*

Your boss wants you to write code like this:

public static boolean isPowerOfTen(long input) {
  return
    input == 1L
  || input == 10L
  || input == 100L
  || input == 1000L
  || input == 10000L
  || input == 100000L
  || input == 1000000L
  || input == 10000000L
  || input == 100000000L
  || input == 1000000000L
  || input == 10000000000L
  || input == 100000000000L
  || input == 1000000000000L
  || input == 10000000000000L
  || input == 100000000000000L
  || input == 1000000000000000L
  || input == 10000000000000000L
  || input == 100000000000000000L
  || input == 1000000000000000000L;
}

(Martin Smith, at https://codereview.stackexchange.com/a/117294/61929)

which is efficient and so, but not that fun to type. Since you want to minimize the number of keypresses you have to do, you write a shorter program or function (or method) that outputs this function for you (or returns a string to output). And since you have your very own custom full-range unicode keyboard with all 120,737 keys required for all of unicode 8.0, we count unicode characters, instead of keypresses. Or bytes, if your language doesn't use unicode source code.

Any input your program or function takes counts towards your score, since you obviously have to type that in as well.

Clarifications and edits:

    Removed 3 trailing spaces after the last }
    Removed a single trailing space after return
    Returning a string of output from a function/method is ok

*/

#include <stdio.h>

typedef unsigned long long uvlong;

void
gen(int n)
{
	uvlong p;
	int i;

	p = 1;
	printf("public static boolean isPowerOfTen(long input) {\n");
	printf("\treturn ");
	for (i = 0; i < n; i++) {
		printf("%s", (i) ? "\t\t|| " : "");
		printf("input == %lluL", p);
		printf("%s\n", (i + 1 >= n) ? ";" : "");
		p *= 10;
	}
	printf("}\n");
}

int
main(void)
{
	gen(19);
	return 0;
}
