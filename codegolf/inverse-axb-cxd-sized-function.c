/*

Let's assume that

f(x)=Ax+BCx+D

Where, x is a variable and A,B,C,D are constants.

Now we have to find out the inverse function of f(x), mathematically f−1(x), To do this first we assume,

y=f(x)
y=(Ax+B)/(Cx+D)
Cxy + Dy = Ax + B
Cxy - Ax = -Dy + B
x(Cy−A) = −Dy + B
x= −Dy + BCy − A

Then, we know that

y=f(x)→f−1(y)=x→f−1(y)=−Dy+BCy−A.....(i)

And from (i) equation, we can write x instead of y

→f−1(x)=(−Dx+B)/(Cx−A)

So, (−Dx+B)/(Cx−A) is the inverse function of f(x)

This is a very long official mathematical solution, but we have a "cool" shortcut to do this:

Swap the position of the first and last constant diagonally, in this example A and D will be swapped, so it becomes:
(Dx+B)/(Cx+A)

Reverse the sign of the replaced constants, in this example A is positive (+A) so it will be negative −A, D is positive (+D) so it will be negative −D
(−Dx+B)/(Cx−A)

And VOILA!! We got the inverse function Ax+BCx+D in just two steps!!

Challenge
(Input of Ax+BCx+D is given like Ax+B/Cx+D)

Now, let's go back to the challenge.

Input of a string representation of a function of Ax+BCx+D size, and output its inverse function in string representation.

I have just shown two ways to that (Second one will be easier for programs), there may be other ways to do this, good luck!

Test cases
(Input of Ax+BCx+D is given like Ax+B/Cx+D)

(4x+6)/(8x+7) -> (-7x+6)/(8x-4)
(2x+3)/(2x-1) -> (x+3)/(2x-2)
(-4x+6)/(8x+7) -> (-7x+6)/(8x+4)
(2x+3)/(2x+1) -> (-x+3)/(2x-2)
Or you can give it using list of A,B,C,D

4,6,8,7 -> -7x+6/8x-4
Or you can output -7,6,8,-4

Rules

Input is always in Ax+BCx+D size, and is guaranteed to be valid.
Standard loopholes are forbidden.
Trailing/Leading whitespace in output is allowed.
If possible, please link to an online interpreter (e.g. TIO) to run your program on.
Please explain your answer. This is not necessary, but it makes it easier for others to understand.
Languages newer than the question are allowed. This means you could create your own language where the empty program calculates this number, but don't expect any upvotes.
This is code-golf, so shortest code in bytes wins!
(Some terminology might be incorrect, feel free ask me if you have problems)

*/

#include <assert.h>
#include <stdio.h>
#include <string.h>

void
inverse(int a, int b, int c, int d, int r[4])
{
	r[0] = -d;
	r[1] = b;
	r[2] = c;
	r[3] = -a;
}

void
test(int a, int b, int c, int d, int r[4])
{
	int p[4];

	inverse(a, b, c, d, p);
	printf("%d %d %d %d\n", p[0], p[1], p[2], p[3]);
	printf("%d %d %d %d\n", r[0], r[1], r[2], r[3]);
	printf("\n");
	assert(!memcmp(r, p, sizeof(p)));
}

int
main(void)
{
	int r1[] = {-7, 6, 8, -4};
	int r2[] = {1, 3, 2, -2};
	int r3[] = {-7, 6, 8, 4};
	int r4[] = {-1, 3, 2, -2};

	test(4, 6, 8, 7, r1);
	test(2, 3, 2, -1, r2);
	test(-4, 6, 8, 7, r3);
	test(2, 3, 2, 1, r4);

	return 0;
}
