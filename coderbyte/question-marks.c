/*

Questions Marks

Have the function QuestionsMarks(str) take the str string parameter, which will contain single digit numbers, letters, and question marks, and check if there are exactly 3 question marks between every pair of two numbers that add up to 10.
If so, then your program should return the string true, otherwise it should return the string false. If there aren't any two numbers that add up to 10 in the string, then your program should return false as well.

For example: if str is "arrb6???4xxbl5???eee5" then your program should return true because there are exactly 3 question marks between 6 and 4, and 3 question marks between 5 and 5 at the end of the string.

Examples
Input: "aa6?9"
Output: false
Input: "acc?7??sss?3rr1??????5"
Output: true

*/

#include <assert.h>
#include <stdbool.h>
#include <stdio.h>
#include <ctype.h>

int
scan(const char *s, size_t *i, size_t *q)
{
	for (*q = 0; !isdigit(s[*i]); *i += 1) {
		if (s[*i] == '\0')
			return EOF;
		*q += (s[*i] == '?');
	}
	return s[*i] - '0';
}

bool
marks(const char *s)
{
	size_t i, c, q;
	int x, y;

	for (i = c = 0; s[i]; i++) {
		x = scan(s, &i, &q);
		if (x == EOF)
			break;

		i++;
		y = scan(s, &i, &q);
		if (y == EOF)
			return false;

		if (x + y == 10) {
			if (q != 3)
				return false;
			c++;
		}
	}
	return c > 0;
}

int
main(void)
{
	assert(marks("aa6?9") == false);
	assert(marks("acc?7??sss?3rr1??????5") == true);
	assert(marks("arrb6???4xxbl5???eee5") == true);

	return 0;
}
