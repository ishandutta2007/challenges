/*

MoEngage noticed that some users are not aware of the practice page on CodeChef, and some others are not aware of the rated contests on CodeChef. So, MoEngage wants to send an email to the users depending on which of the following groups they fall into:

If the user has never submitted on the practice page then send an email with the text:

https://www.codechef.com/practice

If the user has submitted on the practice page, but never participated in a contest then send an email with the text:

https://www.codechef.com/contests

If the user has submitted on the practice page as well as participated in a contest then send an email with the text:

https://discuss.codechef.com

so that they may discuss with other members of the community.

Help MoEngage by writing a program that takes as input two integers A and B where:

A=1 if the user has submitted on the practice page and 0 otherwise.
B=1 if the user has participated in a contest and 0 otherwise.
Output the appropriate link to be displayed in the email.

Input Format

The input consists of a single line with two space-separated integers A and B.

Output Format

Print one of the following strings as per the problem statement.
https://www.codechef.com/practice
https://www.codechef.com/contests
https://discuss.codechef.com

Constraints

A is either 0 or 1.
B is either 0 or 1.

*/

#include <assert.h>
#include <string.h>

const char *
page(int a, int b)
{
	if (a && b)
		return "https://discuss.codechef.com";
	if (a)
		return "https://www.codechef.com/contests";
	return "https://www.codechef.com/practice";
}

int
main(void)
{
	assert(!strcmp(page(0, 1), "https://www.codechef.com/practice"));
	assert(!strcmp(page(1, 0), "https://www.codechef.com/contests"));
	assert(!strcmp(page(0, 0), "https://www.codechef.com/practice"));

	return 0;
}
