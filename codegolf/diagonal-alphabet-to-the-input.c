/*

Inspired by this post. For those marking this question as a duplicate I urge you to actually read the question to see that mine is a modification of the one linked.
The one linked does not ask for an input and is to just print the alphabet diagonally.

The Challenge

Given an input between 1-26 inclusively, print the alphabet diagonally, but begin printing vertically at the index of the given input.

Examples

Given the input:

16

Your program should output:

a
 b
  c
   d
    e
     f
      g
       h
        i
         j
          k
           l
            m
             n
              o
               p
               q
               r
               s
               t
               u
               v
               w
               x
               y
               z

Input:

4

Output:

a
 b
  c
   d
   e
   f
   g
   h
   i
   j
   k
   l
   m
   n
   o
   p
   q
   r
   s
   t
   v
   w
   x
   y
   z

Input:

1

Output:

a
b
c
d
e
f
g
h
i
j
k
l
m
n
o
p
q
r
s
t
u
v
w
x
y
z

Input:

26

Output:

a
 b
  c
   d
    e
     f
      g
       h
        i
         j
          k
           l
            m
             n
              o
               p
                q
                 r
                  s
                   t
                    u
                     v
                      w
                       x
                        y
                         z

Scoring

This is code-golf, so the shortest answer in each language wins.

Good luck!

*/

#include <stdio.h>

void
diagonal(int n)
{
	int i, j, k;

	for (i = 0; i < 26; i++) {
		k = (i < n) ? i : n - 1;
		for (j = 0; j < k; j++)
			printf(" ");
		printf("%c\n", 'a' + i);
	}
	printf("\n");
}

int
main(void)
{
	diagonal(16);
	diagonal(4);
	diagonal(1);
	diagonal(26);

	return 0;
}
