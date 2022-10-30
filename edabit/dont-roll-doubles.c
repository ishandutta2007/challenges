/*

John is playing a dice game. The rules are as follows.

Roll two dice.
Add the numbers on the dice together.
Add the total to your overall score.
Repeat this for three rounds.

But if you roll DOUBLES, your score is instantly wiped to 0 and your game ends immediately!

Create a function which takes in a list of tuples as input, and return John's score after his game has ended.

Notes

Ignore all other tuples in the list if a throw happens to be doubles and go straight to returning 0.
John only has two dice and will always give you outcomes for three rounds.

*/

#include <stdio.h>

#define nelem(x) (sizeof(x) / sizeof(x[0]))

int
dicesim(int (*a)[2], size_t n)
{
	int s;
	size_t i;

	s = 0;
	for (i = 0; i < n; i++) {
		if (a[i][0] == a[i][1])
			return 0;
		s += a[i][0] + a[i][1];
	}
	return s;
}

int
main(void)
{
	int a1[][2] = {{1, 2}, {3, 4}, {5, 6}};
	int a2[][2] = {{1, 1}, {5, 6}, {6, 4}};
	int a3[][2] = {{4, 5}, {4, 5}, {4, 5}};
	int a4[][2] = {{1, 3}, {4, 3}, {5, 2}};
	int a5[][2] = {{1, 3}, {4, 3}, {5, 5}};
	int a6[][2] = {{1, 3}, {4, 4}, {5, 2}};
	int a7[][2] = {{5, 6}, {5, 6}, {5, 6}};

	printf("%d\n", dicesim(a1, nelem(a1)));
	printf("%d\n", dicesim(a2, nelem(a2)));
	printf("%d\n", dicesim(a3, nelem(a3)));
	printf("%d\n", dicesim(a4, nelem(a4)));
	printf("%d\n", dicesim(a5, nelem(a5)));
	printf("%d\n", dicesim(a6, nelem(a6)));
	printf("%d\n", dicesim(a7, nelem(a7)));

	return 0;
}
