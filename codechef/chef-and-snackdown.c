/*

Chef is interested in the history of SnackDown contests. He needs a program to verify if SnackDown was hosted in a given year.

SnackDown was hosted by CodeChef in the following years: 2010, 2015, 2016, 2017 and 2019.

Input

The first line contain the number of test-cases T.

The first line of each test-case contains a single integer N.

Output

For each test case print a single line containing the string "HOSTED" if SnackDown was hosted in year N or "NOT HOSTED" otherwise (without quotes).

Constraints
1≤T≤10
2010≤N≤2019

*/

#include <assert.h>
#include <stdbool.h>

bool
hosted(int y)
{
	switch (y) {
	case 2010:
	case 2015:
	case 2016:
	case 2017:
	case 2019:
		return true;
	}
	return false;
}

int
main(void)
{
	assert(hosted(2019) == true);
	assert(hosted(2018) == false);

	return 0;
}
