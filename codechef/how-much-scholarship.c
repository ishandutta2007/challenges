/*

The ZCO Scholarship Contest has just finished, and you finish with a rank of R.
You know that Rank 1 to Rank 50 will get 100% scholarship on the ZCO exam fee and Rank 51 to Rank 100 will get 50% percentage scholarship on the ZCO exam fee.
The rest do not get any scholarship.
What percentage of scholarship will you get ?

Input

Input consist of single line of input containing one integer R.

Output

Output a single line containing one integer — the percentage of scholarship you will get.

Constraints
1≤R≤10^9

*/

#include <assert.h>

int
percentage(int r)
{
	if (1 <= r && r <= 50)
		return 100;
	if (51 <= r && r <= 100)
		return 50;
	return 0;
}

int
main(void)
{
	assert(percentage(49) == 100);
	assert(percentage(317) == 0);

	return 0;
}
