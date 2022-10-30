/*

Inspired by Silicon Valley's "three-comma club" scenes, like this one, in this challenge you'll be telling ten people the "comma club" to which they each belong.

If you're unfamiliar with the term "comma club," let me explain: you're in the one-comma club if the money you have is in the inclusive range $1,000.00 to $999,999.99;
you're in the two-comma club if it's in the range $1,000,000.00 to $999,999,999.99; these "clubs" repeat through the three-comma club,
since no individual on Earth (AFAIK) owns more than one trillion U.S. dollars (Japanese Yen would be a different story very quickly).
So, the number of commas your bank account has, according to the notation standards most common in the United States and Great Britain, denotes the comma club to which you belong.
The same "comma" rules apply for negative numbers (although you wouldn't want to be in the negative comma club):
negative amounts in the inclusive range [-0.01, -999.99] belong to the zero-comma club, amounts in the range [-1000.00, -999999.99] belong to the one-comma club, etc.

The test cases
Friend    Amount
John      100000
Jamie     0.05
Kylie     1549001.10
Laura     999999999.99
Russ      986000000
Karla     1
Reid      99.99
Mark      999.99
Manson    1000.01
Lonnie    999999999999.00
Nelly     -123.45
The right answers:

John is in the 1-comma club.
Jamie is in the 0-comma club.
Kylie is in the 2-comma club.
Laura is in the 2-comma club.
Russ is in the 2-comma club.
Karla is in the 0-comma club.
Reid is in the 0-comma club.
Mark is in the 0-comma club.
Manson is in the 1-comma club.
Lonnie is in the 3-comma club.
Nelly is in the 0-comma club.
Whatever array setup you need to get a friends array and amounts array does not count towards your score. So for Python, the following code doesn't count:

f = ['John', 'Jamie', 'Kylie', 'Laura', 'Russ', 'Karla', 'Reid', 'Mark', 'Manson', 'Lonnie']
a = ['100000', '0.05', '1549001.10', '999999999.99', '986000000', '1', '99.99', '999.99', '1000.01', '999999999999.00']
Edit: Please see the revised test cases
I removed the actual string commas from the test cases to make things a bit more difficult, as opposed to just counting commas.

*/

#include <assert.h>
#include <stdio.h>
#include <string.h>

char *
commaclub(const char *s, double x, char *b)
{
	int c;

	for (c = 0; x >= 1e3; c++)
		x /= 1e3;
	sprintf(b, "%s is in the %d-comma club.", s, c);
	return b;
}

void
test(const char *s, double x, const char *r)
{
	char b[128];

	commaclub(s, x, b);
	printf("%s\n", b);
	assert(!strcmp(b, r));
}

int
main(void)
{
	test("John", 100000, "John is in the 1-comma club.");
	test("Jamie", 0.05, "Jamie is in the 0-comma club.");
	test("Kylie", 1549001.10, "Kylie is in the 2-comma club.");
	test("Laura", 999999999.99, "Laura is in the 2-comma club.");
	test("Russ", 986000000, "Russ is in the 2-comma club.");
	test("Karla", 1, "Karla is in the 0-comma club.");
	test("Reid", 99.99, "Reid is in the 0-comma club.");
	test("Mark", 999.99, "Mark is in the 0-comma club.");
	test("Manson", 1000.01, "Manson is in the 1-comma club.");
	test("Lonnie", 999999999999.00, "Lonnie is in the 3-comma club.");
	test("Nelly", -123.45, "Nelly is in the 0-comma club.");

	return 0;
}
