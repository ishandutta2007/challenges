/*

The Monty Hall Problem is a probability puzzle that has a very non-intuitive answer for the average person. Here's the problem description taken from Wikipedia:

"Suppose you're on a game show, and you're given the choice of three doors: Behind one door is a car; behind the others, goats.
You pick a door, say No. 1, and the host, who knows what's behind the doors, opens another door, say No. 3, which has a goat.
He then says to you, "Do you want to pick door No. 2?" Is it to your advantage to switch your choice?"

AsapScience has a great YouTube video describing this game. If you don't understand why switching doors is the best tactic, feel free to discuss it here or on other great subreddits, like r/Math, r/ComputerScience, or even r/AskScience!

Your goal is to simulate two tactics to this puzzle, and return the percentage of successful results. The first tactic is where you stick with your initial choice. The second tactic is where you always switch doors.

Edit: Make sure to actually simulate both techniques. Write that code out in its entirety, don't compute the second result being '100% - first techniques percentage', though that's certainly true mathematically.

Formal Inputs & Outputs

Input Description
On standard console input, you will be given a single integer ranging inclusively from 1 to 4,294,967,295 (unsigned 32-bit integer).
This integer is the number of times you should simulate the game for both tactics. Remember that a single "game simulation" is your program randomly placing a car behind one door and two goats behind the two remaining doors.
You must then randomly pick a door, have one of the two remaining doors open, but only open if it's a goat behind said door!
After that, if using the first tactic, you may open the picked door, or if using the second tactic, you may open the other remaining door. Keep track if your success rates in both simulations.

Output Description
On two seperate lines, print "Tactic 1: X% winning chance" and "Tactic 2: Y% winning chance", where X and Y are the percentages of success for the respective tactics

Sample Inputs & Outputs
Sample Input
1000000
Sample Output
Tactic 1: 33.3% winning chance
Tactic 2: 66.6% winning chance

Difficulty++
For an extra challenge, visualize the simulation! Using whatever tools and platform you want, let the simulation visually show you the doors it's picking over time. Try to aim for one simulation a second, keeping it fast-paced.

*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

int
randn(int n)
{
	int r;

	if (n == 0)
		return 0;

	do {
		r = rand();
	} while (r >= (RAND_MAX - (RAND_MAX % n)));

	return (r % n);
}

int
mod(int x, int m)
{
	x %= m;
	if (x < 0)
		x += m;
	return x;
}

void
sim(int n)
{
	int r[2];
	int g[2];
	int c, s;
	int p, q;
	int i;

	memset(r, 0, sizeof(r));
	for (i = 0; i < n; i++) {
		p = randn(3);
		c = randn(3);
		g[0] = mod(c + 1, 3);
		g[1] = mod(c - 1, 3);

		if (p == c || p == g[1])
			s = g[0];
		else
			s = g[1];

		if (p == c)
			q = (s == g[0]) ? g[1] : g[0];
		else
			q = c;

		r[0] += (p == c);
		r[1] += (q == c);
	}

	printf("Tactic 1: %.2f%% winning chance\n", r[0] * 100.0 / n);
	printf("Tactic 2: %.2f%% winning chance\n", r[1] * 100.0 / n);
}

int
main(void)
{
	srand(time(NULL));
	sim(1000000);

	return 0;
}
