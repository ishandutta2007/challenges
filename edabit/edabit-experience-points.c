/*

As you complete questions on Edabit, you gain experience points depending on the difficulty of the question. The points for each difficulty are as follows:
Difficulty	Experience Points
Very Easy	5XP
Easy	10XP
Medium	20XP
Hard	40XP
Very Hard	80XP

Given an object of how many questions a person has completed of each difficulty, return how many experience points they'll have.
Examples

getXP({
  "Very Easy" : 89,
  "Easy" : 77,
  "Medium" : 30,
  "Hard" : 4,
  "Very Hard" : 1
}) ➞ "2055XP"


getXP({
  "Very Easy" : 254,
  "Easy" : 32,
  "Medium" : 65,
  "Hard" : 51,
  "Very Hard" : 34
}) ➞ "7650XP"


getXP({
  "Very Easy" : 11,
  "Easy" : 0,
  "Medium" : 2,
  "Hard" : 0,
  "Very Hard" : 27
}) ➞ "2255XP"

Notes

Return values as a string and make sure to add "XP" to the end.

*/

#include <assert.h>

unsigned
getxp(unsigned q[5])
{
	static const unsigned tab[] = {
		5,
		10,
		20,
		40,
		80,
	};
	unsigned xp, i;

	xp = 0;
	for (i = 0; i < 5; i++)
		xp += q[i] * tab[i];
	return xp;
}

int
main(void)
{
	unsigned q1[] = { 89, 77, 30, 4, 1 };
	unsigned q2[] = { 254, 32, 65, 51, 34 };
	unsigned q3[] = { 11, 0, 2, 0, 27 };

	assert(getxp(q1) == 2055);
	assert(getxp(q2) == 7650);
	assert(getxp(q3) == 2255);

	return 0;
}
