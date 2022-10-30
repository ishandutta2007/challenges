/*

Den has two four-digit combination locks for protecting his bicycle from thieves.
Every evening he arms the bicycle antitheft alarm and fastens the bicycle to a special stand with one of the locks.
Den never uses the same lock two evenings in a row. One night a thief tried to open the lock using the code 0000.
The alarm went off and the thief hurried away.
The next night the thief decided to try the code 0001, then 0002, and so on in ascending order of the number.
Den never changes the codes of his locks. On the night when the thief came for the first time the bicycle was fastened with the first lock.

Input
The first line contains the combination that opens the first lock and the second line contains the combination that opens the second lock. Both combinations are strings consisting of four digits from 0 to 9.

Output
Output “yes” if the thief will open the lock sooner or later and “no” otherwise.

*/

#include <assert.h>
#include <stdbool.h>

bool
breakable(unsigned l1, unsigned l2)
{
	return !(l1 & 1) && (l2 & 1);
}

int
main(void)
{
	assert(breakable(1, 0) == false);
	assert(breakable(2, 1) == true);

	return 0;
}
