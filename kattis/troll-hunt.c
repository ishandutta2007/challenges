/*

Once upon a time in a land of yore, there was a troll who lived ’neath one of the land’s many stone bridges.
This troll was quite a mischievous troll, for you see, it had a habit of accusing anyone crossing the bridge of having stolen the troll’s property
(which was a somewhat curious accusation given that the troll had no property), the punishment of which was to be eaten alive.
Unfortunately for the troll, eventually the king got wind of its questionable business model, and sent out the valiant knights of the High Tavern to go, shall we say, Queen of Hearts, on the troll.

Apprehensive of its imminent decapitation, the troll fled, and did not have the decency to even leave a forwarding address.
Being a troll, it was clear that the troll was hiding under some other stone bridge than the one it had used for its shady business practice, but which?
The knights decided to split up in groups and go search. Since a group needed to be able to avoid being eaten once the troll was found, each group had to consist of at least a certain number of knights.
Each group of knights could search under one stone bridge per day (and travelling between bridges was done at lightning speed, thanks to the knights’ renowned iTravel™ technology).
While clever enough to flee from its hunting ground, the troll is not bright enough to keep moving between different bridges: once the hunt starts, the troll stays in the same place.
How many days would it take until the troll would surely have been found?


Input

The input consists of a single line containing three integers b, k and g, where 2≤b≤1000 is the number of stone bridges in the land, 1≤k≤100 is the number of knights, and 1≤g≤k is the number of knights needed in each group.

Output

Output a line containing a single integer d, the number of days until the troll is sure to have met its destiny.


*/

#include <assert.h>
#include <stdio.h>

unsigned
deliverance(unsigned b, unsigned k, unsigned g)
{
	unsigned d;

	if (k == 0 || g > k)
		return 0;

	d = k / g;
	if ((b - 1) % d == 0)
		return (b - 1) / d;
	return (b - 1) / d + 1;
}

int
main(void)
{
	assert(deliverance(5, 2, 1) == 2);
	assert(deliverance(10, 5, 2) == 5);
	return 0;
}
