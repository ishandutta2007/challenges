/*

Recently, Chef's College Examination has concluded. He was enrolled in 3 courses and he scored A,B,C in them, respectively.
To pass the semester, he must score at least Amin,Bmin,Cmin marks in the respective subjects along with a cumulative score of at least Tmin, i.e, A+B+C≥Tmin.

Given seven integers Amin,Bmin,Cmin,Tmin,A,B,C, tell whether Chef passes the semester or not.

Input:

The first line will contain T, number of testcases. Then the testcases follow.
Each testcase contains of a single line of input, seven integers Amin,Bmin,Cmin,Tmin,A,B,C each separated by aspace.

Output:

Output in a single line, the answer, which should be "YES" if Chef passes the semester and "NO" if not.
You may print each character of the string in uppercase or lowercase (for example, the strings "yEs", "yes", "Yes" and "YES" will all be treated as identical).

Constraints

1≤T≤100
1≤Amin,Bmin,Cmin,A,B,C≤100
Amin+Bmin+Cmin≤Tmin≤300

*/

#include <assert.h>
#include <stdbool.h>

bool
passed(int am, int bm, int cm, int tm, int a, int b, int c)
{
	return a >= am && b >= bm && c >= cm && (a + b + c) >= tm;
}

int
main(void)
{
	assert(passed(1, 1, 1, 300, 2, 2, 2) == false);
	assert(passed(3, 2, 2, 6, 2, 2, 2) == false);
	assert(passed(2, 3, 2, 6, 2, 2, 2) == false);
	assert(passed(2, 2, 3, 6, 2, 2, 2) == false);
	assert(passed(100, 100, 100, 300, 100, 100, 100) == true);

	return 0;
}
