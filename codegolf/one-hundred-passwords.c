/*

I have one hundred vaults, each one within another. Each vault has a password, consisting of a single number.

95 43 81 89 56 89 57 67 7 45 34 34 78 88 14 40 81 23 26 78 46 8 96 11 28 3 74 6 23 89 54 37 6 99 45 1 45 87 80 12 92 20 49 72 9 92 15 76 13 3 5 32 96 87 38 87 31 10 34 8 57 73 59 33 72 95 80 84 11 4 11 11 37 71 77 91 49 21 52 48 43 11 77 52 64 3 9 21 38 65 69 84 96 78 7 71 80 78 3 97

It's too hard to memorize all these passwords, and it's not safe to keep the passwords on a piece of paper.
The only solution I can think of is to use a program with exactly one hundred characters.
The password to the nth vault will be found by treating the first n characters of the code as a program.

Thus, the first character of the program, if run as a program by itself, must output 95. The first two characters by themselves must output 43. The entire program must output 97.

I admit that this is really hard. So just do your best. Try to make your program work for as many vaults as possible, and I'll memorize the passwords to the rest.

Rules

If there is a tie, the winner is the earliest submission.
Standard loopholes forbidden. That includes reading from other files or from the Internet.
You have a few options for the code:
A full program which prints the correct number
A function which returns or prints it
An expression which evaluates to it (e.g. in C, 4+3 evaluates to 7)
You may assume a REPL environment
You may use different techniques for each value of n. For example, you can use different languages for each n, or sometimes use a full program and sometimes a function.
Note: This scenario is completely fictional. If you have a similar issue, do not post your passwords online.

*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int
vault(int n)
{
	static const char text[] = "95 43 81 89 56 89 57 67 7 45 34 34 78 88 14 40 81 23 26 78 46 8 96 11 28 3 74 6 23 89 54 37 6 99 45 1 45 87 80 12 92 20 49 72 9 92 15 76 13 3 5 32 96 87 38 87 31 10 34 8 57 73 59 33 72 95 80 84 11 4 11 11 37 71 77 91 49 21 52 48 43 11 77 52 64 3 9 21 38 65 69 84 96 78 7 71 80 78 3 97";

	const char *p;
	int i;

	if (n < 1 || n > 100)
		return -1;

	p = text;
	for (i = 1; i < n; i++)
		p = strchr(p, ' ') + 1;
	return atoi(p);
}

int
main(int argc, char *argv[])
{
	int n;

	n = 1;
	if (argc >= 2)
		n = atoi(argv[1]);

	printf("%d\n", vault(n));
	return 0;
}
