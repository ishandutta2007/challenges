/*

Emma is playing a new mobile game that starts with consecutively numbered clouds. Some of the clouds are thunderheads and others are cumulus. She can jump on any cumulus cloud having a number that is equal to the number of the current cloud plus 1 or 2. She must avoid the thunderheads. Determine the minimum number of jumps it will take Emma to jump from her starting postion to the last cloud. It is always possible to win the game. 

*/

#include <stdio.h>

#define nelem(x) (sizeof(x) / sizeof(x[0]))

size_t
jumps(int *a, size_t n)
{
	size_t i, j;

	// idea is to be always be greedy to minimize the number of jumps
	// always jump 2 times unless there is a thunderhead
	for (i = j = 0; i < n - 1;) {
		if (i + 2 < n && a[i + 2] == 0)
			i += 2;
		else
			i++;
		j++;
	}
	return j;
}

int
main(void)
{
	int a[] = {0, 1, 0, 0, 0, 1, 0};
	printf("%zu\n", jumps(a, nelem(a)));

	int b[] = {0, 0, 1, 0, 0, 1, 0};
	printf("%zu\n", jumps(b, nelem(b)));

	int c[] = {0, 0, 0, 0, 1, 0};
	printf("%zu\n", jumps(c, nelem(c)));

	return 0;
}
