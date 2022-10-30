/*

After inputting a string [length 1-20], only containing the chars y for yes and n for no, your program should output the result (y or n). Example input: yynynynny would output y.

The result is determined by combining the y's and n's in the following way:

yes and no equals no

yes and yes equals yes

no and no equals yes

If the string contains more than 2 characters (likely...), the calculation would look the same. Examples:

yes and yes and no equals no (because the no merges with the first yes to no. then there are no and yes left and the same thing happens again)

no and no and no equals no (the first two no's merge to yes, then there are yes and no left, which emerge to no)

Example input with output:

yynynynynyyn = n
Tip: have in mind that the order of the chars your program works off doesn't care. (for example you can read the input from back, or from behind, mix the letters, sort it, whatever. What counts is the correct ouptput) have fun!

Winning criteria: this is code-golf, so shortest code in byte wins.

*/

#include <assert.h>
#include <stdio.h>

int
yesno(const char *s)
{
	size_t i;
	int c;

	if (!s[0])
		return 0;

	c = s[0];
	for (i = 1; s[i]; i++)
		c = (c == s[i]) ? 'y' : 'n';
	return c;
}

int
main(void)
{
	assert(yesno("yn") == 'n');
	assert(yesno("yy") == 'y');
	assert(yesno("nn") == 'y');
	assert(yesno("yyn") == 'n');
	assert(yesno("nnn") == 'n');
	assert(yesno("yynynynny") == 'y');
	assert(yesno("yynynynynyyn") == 'n');

	return 0;
}
