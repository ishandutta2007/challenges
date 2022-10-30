/*

Your friend has been caught sleeping in class again! As punishment, his computer science teacher has assigned him homework, knowing that he will not be able to solve it due to not having paid any attention.

The assignment seems deceiving simple at first; all that is required is to output the string:

John Doe
Unfortunately, the teacher is intent on making the simple assignment much more difficult.
Since your friend was not listening when the teacher explained the concept of strings and numbers, the teacher forbids him from using any number character (0-9) or the quotes (", ', `).

Can you help your friend solve this problem with the shortest code possible, and save his computer science grade in the process?

Try to find the shortest code in each language!

Note: it is encouraged to try to solve this problem in languages where string/character literals exist but cannot be used due to the restrictions (most mainstream languages are like this, e.g. C++).

*/

#include <stdio.h>

#define R1(x) x;
#define R2(x) R1(x) R1(x)
#define R4(x) R2(x) R2(x)
#define R8(x) R4(x) R4(x)
#define R10(x) R8(x) R2(x)
#define R16(x) R8(x) R8(x)
#define R32(x) R16(x) R16(x)

#define P(x) putchar(*#x)

int
main(void)
{
	static int sp;
	static int nl;

	R10(nl++);
	R32(sp++);

	P(J);
	P(o);
	P(h);
	P(n);
	putchar(sp);
	P(D);
	P(o);
	P(e);
	putchar(nl);

	return !nl ^ !sp;
}
