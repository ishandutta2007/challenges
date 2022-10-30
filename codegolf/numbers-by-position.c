/*

Numbers by Position

Challenge

Print the numbers:

1
22
333
4444
55555
666666
7777777
88888888
999999999

In that order.

I/O

Takes no input. The numbers can have any delimiters desired (or none). That includes lists, cell arrays, .jpeg, etc.... Example outputs:

122333444455555666666777777788888888999999999

[1,22,333,4444,55555,666666,7777777,88888888,999999999]

etc....

Code Example

This is an un-golfed example that may perhaps act as algorithm guide (or maybe not):
Turing Machine Code, 535 bytes

0 * 1 r L
L * _ r 2
2 * 2 r a
a * 2 r M
M * _ r 3
3 * 3 r b
b * 3 r c
c * 3 r N
N * _ r 4
4 * 4 r d
d * 4 r e
e * 4 r f
f * 4 r O
O * _ r 5
5 * 5 r g
g * 5 r h
h * 5 r i 
i * 5 r j
j * 5 r P
P * _ r 6
6 * 6 r k
k * 6 r l
l * 6 r m
m * 6 r n
n * 6 r o
o * 6 r Q
Q * _ r 7
7 * 7 r p
p * 7 r q
q * 7 r r
r * 7 r s
s * 7 r t
t * 7 r u
u * 7 r R
R * _ r 8
8 * 8 r v
v * 8 r w
w * 8 r x
x * 8 r y
y * 8 r z
z * 8 r A
A * 8 r B
B * 8 r S
S * _ r 9
9 * 9 r C
C * 9 r D
D * 9 r E
E * 9 r F
F * 9 r G
G * 9 r H
H * 9 r I
I * 9 r J
J * 9 r halt

Try it online!

This prints out the numbers with a space delimiter:

1 22 333 4444 55555 666666 7777777 88888888 999999999

Challenge Type

code-golf, so shortest answer in bytes (by language) wins.

Based on a submission in the sandbox.

*/

#include <stdio.h>

void
gen(void)
{
	int i, j;

	for (i = 1; i <= 9; i++) {
		for (j = 0; j < i; j++)
			printf("%d", i);
		printf("\n");
	}
}

int
main(void)
{
	gen();
	return 0;
}
