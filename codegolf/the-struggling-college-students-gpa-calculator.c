/*

GPA Calculator
(GPA = Grade Point Average)

You are a stressed out college student during finals week. Instead of studying for your exams coming up, you decide it is best to determine what GPA you will have at the end of the semester.
This way you have data to back up your decision of staying up all night to get that A in Calculus instead of a B to remain on the Dean's list!

Being a computer science major you want to find the coolest way to determine this GPA. Of course the coolest way is with the shortest code! This is code-golf, so shortest code in bytes wins!

Details
The college that you go to uses a basic GPA scaled along with credit hours.
A letter grade of A is a 4.0, B is 3.0, C is 2.0, D is 1.0, and F is 0.0
Your GPA is a weighted GPA, so an A in a 4 credit hour class counts 4 times as much as an A in a 1 credit hour class (See examples below for more weight explanantion)
Credit Hours range from 1-4
Your program will need to have a list of two command line inputs, Grade and Credit Hour.
You can determine the best way to input these into your program through the command line.
You do not need to worry about too many inputs, but ensure your code can handle a 19 credit hour semester.

i.e. Input: A 1 B 4 C 2…
Your program must output the GPA, using 3 digits (i.e. X.XX)

Your GPA needs to be rounded to two decimal places. Round in whichever way you like (floor, ceil, base, etc…)
Input Examples(Choose whichever one works best for your design)
A1B3C2F3B4
A1 B3 C2 F3 B4
A 1 B 3 C 2 F 3 B 4
A,1,B,3,C,2,F,3,B,4
A1,B3,C2,F3,B4
Or any of the above combinations where you use the format of listing all grades, then their credit hours:

i.e. A B A A 3 4 1 1
Examples
Input - A 3 B 4 A 1 A 1
Output - 3.56
Explanation: (4.0 * 3 + 3.0 * 4 + 4.0 * 1 + 4.0 * 1)/(3+4+1+1) = 3.555556 rounded off to 3.56

Input - A 4 F 2 C 3 D 4
Output - 2.00
Explanation: (4.0 * 4 + 0.0 * 2 + 2.0 * 3 + 1.0 * 4)/(4+2+3+4) = 2 rounded off to 2.00

*/

#include <assert.h>
#include <stdio.h>
#include <string.h>
#include <math.h>

void
accumulate(const char *s, double *v, double *t)
{
	static const char w1[] = "FDCBA";
	static const char w2[] = "1234";

	const char *p, *q;
	int x, y;

	p = strchr(w1, s[0]);
	q = strchr(w2, s[1]);
	if (!p || !q)
		return;

	x = p - w1;
	y = q - w2 + 1;

	*v += x * y;
	*t += y;
}

double
gpa(const char *s)
{
	double v, t;
	size_t i;

	v = t = 0;
	for (i = 0; s[i] && s[i + 1]; i += 2)
		accumulate(s + i, &v, &t);
	return v / t;
}

void
test(const char *s, double r)
{
	double v;

	v = gpa(s);
	printf("%.2f\n", v);
	assert(fabs(v - r) < 1e-2);
}

int
main(void)
{
	test("A3B4A1A1", 3.56);
	test("A4F2C3D4", 2.00);

	return 0;
}
