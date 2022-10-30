/*

Introduction
You may know and love your normal unit circle. But mathematicans are crazy and thus they have abstracted the concept to any point that satisfies x*x+y*y=1.
Because Cryptographers [1] are also weird, they love finite fields and sometimes finite rings (it is not like they have much choice though), so let's combine this!

The Challenge
Input
A positive integer larger than one in your favorite encoding. Let's call this number n.

Output
You will output the "picture" (which consists of n times n characters) of the unit circle modulo the input integer as ASCII-Art using "X" (upper-case latin X) and " " (a space). Trailing spaces and newlines are allowed.

More Details
You have to span a coordinate system from bottom-left to top-right. Whenever a point fulfills the circle equation, place an X at the position, otherwise place a space.

The condition for a point to be considered part of the circle border is:
mod(x*x+y*y,n)==1.

Here a quick illustration of the coordinate-system:

(0,4)(1,4)(2,4)(3,4)(4,4)
(0,3)(1,3)(2,3)(3,3)(4,3)
(0,2)(1,2)(2,2)(3,2)(4,2)
(0,1)(1,1)(2,1)(3,1)(4,1)
(0,0)(1,0)(2,0)(3,0)(4,0)
If it helps you, you may also invert the direction of any of the axes, but the examples assume this orientation.

Who wins?
This is code-golf so the shortest code in byte wins! Only the default I/O methods are allowed and all standard loopholes are banned.

Examples
Input: 2

X
 X
Input: 3

X
X
 XX
Input: 5

X


X
 X  X
Input: 7

X
  X  X


  X  X
X
 X    X
Input: 11

X

     XX

   X    X
   X    X

     XX

X
 X        X
Input: 42

X
         X                       X


            X                 X
       X                           X
      X                             X
                     X
  X             X         X             X


     X             X   X             X
X
               X           X
              X             X
         X                       X


            X                 X
                     X
        X           X X           X
                     X
            X                 X


         X                       X
              X             X
               X           X
X
     X             X   X             X


  X             X         X             X
                     X
      X                             X
       X                           X
            X                 X


         X                       X
X
 X           X               X           X
1 I suggest you take a look at my profile if you're wondering here.

*/

#include <stdio.h>

void
weirdcircle(int n)
{
	int x, y;

	printf("N=%d\n", n);
	for (y = n - 1; y >= 0; y--) {
		for (x = 0; x < n; x++) {
			if (((x * x) + (y * y)) % n == 1)
				printf("X");
			else
				printf(" ");
		}
		printf("\n");
	}
	printf("\n");
}

int
main(void)
{
	weirdcircle(2);
	weirdcircle(3);
	weirdcircle(5);
	weirdcircle(7);
	weirdcircle(11);
	weirdcircle(42);

	return 0;
}
