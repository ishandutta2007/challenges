/*

Grisha N. told his two teammates that he was going to solve all given problems at the subregional contest, even if the teammates wouldn’t show up at the competition.
The teammates didn’t believe Grisha so he told them the plan how he was going to do this.
During the first hour he wants to solve f problems. If there is still some time left to the end of the first hour, Grisha will simply walk along the hall.
Beginning from the second hour Grisha wants to spend exactly 45 minutes on each of the problems left.
If the plan is a success, will Grisha be able to solve all 12 given problems for 5 hours?

Input

The only line contains an integer f that is the number of problems Grisha wants to solve during the first hour of the competition (1 ≤ f ≤ 11).

Output

Output “YES”, if Grisha manages to solve all the given problems alone, and “NO” if he doesn’t.

*/

#include <assert.h>
#include <stdbool.h>

bool
solvable(unsigned f)
{
	if (f >= 12)
		return true;
	return ((12 - f) * 45) <= 240;
}

int
main(void)
{
	assert(solvable(7) == true);
	assert(solvable(5) == false);

	return 0;
}
