/*

Chef opened a company which manufactures cars and bikes. Each car requires 4 tyres while each bike requires 2 tyres. Chef has a total of N tyres (N is even).
He wants to manufacture maximum number of cars from these tyres and then manufacture bikes from the remaining tyres.

Chef's friend went to Chef to purchase a bike. If Chef's company has manufactured even a single bike then Chef's friend will be able to purchase it.

Determine whether he will be able to purchase the bike or not.

Input Format

The first line contains an integer T denoting the number of test cases. The T test cases then follow.
The first line of each test case contains an integer N denoting the number of tyres.

Output Format

For each test case, output YES or NO depending on whether Chef's friend will be able to purchase the bike or not. Output is case insensitive.

Constraints

1≤T≤100
2≤N≤1000
N is even

*/

#include <assert.h>
#include <stdio.h>

int
canbike(unsigned n)
{
	return (n % 4) && (n / 2);
}

int
main(void)
{
	assert(canbike(8) == 0);
	assert(canbike(2) == 1);
	assert(canbike(6) == 1);
	assert(canbike(4) == 0);
	assert(canbike(15) == 1);
	assert(canbike(20) == 0);
	assert(canbike(22) == 1);
	assert(canbike(44) == 0);
	assert(canbike(82) == 1);

	return 0;
}
