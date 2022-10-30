/*

HackerLand Enterprise is adopting a new viral advertising strategy. When they launch a new product, they advertise it to exactly 5 people on social media. 

On the first day, half of those 5 people (i.e., floor(5/2)=2) like the advertisement and each shares it with of their friends.
At the beginning of the second day, floor(5/2)*3 = 2*3=6 people receive the advertisement.

Each day, floor(recipients/2) of the recipients like the advertisement and will share it with 3 friends on the following day.
Assuming nobody receives the advertisement twice, determine how many people have liked the ad by the end of a given day, beginning with launch day as day 1.

For example, assume you want to know how many have liked the ad by the end of the 5th day.

Day Shared Liked Cumulative
1      5     2       2
2      6     3       5
3      9     4       9
4     12     6      15
5     18     9      24

The cumulative number of likes is 24.

*/

#include <stdio.h>

int
viral(int n)
{
	int i, p, c;

	if (n <= 0)
		return 0;

	p = 2;
	c = 2;
	for (i = 2; i <= n; i++) {
		p = p * 3 / 2;
		c += p;
	}
	return c;
}

int
main(void)
{
	int i;
	for (i = 0; i <= 10; i++)
		printf("%d %d\n", i, viral(i));
	return 0;
}
