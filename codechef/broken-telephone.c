/*

Chef is judging a game called "Broken telephone". There are total N players taking part in the game. They are all sitting in a line. In the start of the game, first player is given a secret message written on a sheet of paper. Then they keep sending the message by whispering it to the player sitting immediate right to one and so on until it reaches the last person.

Finally, the message received by the last player is compared with the message said by first player. If these messages aren't equal, there is someone who has misheard the message or whispered it wrongly to the next player. If messages is equal, then the players win and receive a tasty chocolate.

Note that first player receives the message on a sheet of paper, thus he cannot mishear it.

As Chef wants to be sure that every player has fulfilled his/ her role in the game, so he asks everyone to state their received messages after the end of the game. You are given an array A of N integers denoting messages received by each person.

Please help Chef to find the number of players that could mishear the message or whisper it wrongly.

*/
#include <stdio.h>

#define nelem(x) (sizeof(x) / sizeof(x[0]))

size_t
misheard(int *a, size_t n)
{
	size_t i, m;

	m = 0;
	for (i = 0; i < n; i++) {
		if (i < n - 1 && a[i] != a[i + 1])
			m++;
		else if (i > 0 && a[i] != a[i - 1])
			m++;
	}
	return m;
}

int
main(void)
{
	int a[] = {1, 1, 1, 3, 3, 3, 2};
	printf("%zu\n", misheard(a, nelem(a)));

	int b[] = {1, 3, 1, 1, 1};
	printf("%zu\n", misheard(b, nelem(b)));

	int c[] = {5, 5, 5, 5};
	printf("%zu\n", misheard(c, nelem(c)));
	return 0;
}
