/*

The task is very simple, when given an input, output one of the following spirals:

Input = 1 gives a spiral with the letter A beginning in the top left corner:

A B C D E F
T U V W X G
S 5 6 7 Y H
R 4 9 8 Z I
Q 3 2 1 0 J
P O N M L K
Input = 2 gives a spiral with the letter A beginning in the top right corner:

P Q R S T A
O 3 4 5 U B
N 2 9 6 V C
M 1 8 7 W D
L 0 Z Y X E
K J I H G F
Input = 3 gives a spiral with the letter A beginning in the bottom right corner:

K L M N O P
J 0 1 2 3 Q
I Z 8 9 4 R
H Y 7 6 5 S
G X W V U T
F E D C B A
Input = 4 gives a spiral with the letter A beginning in the bottom left corner:

F G H I J K
E X Y Z 0 L
D W 7 8 1 M
C V 6 9 2 N
B U 5 4 3 O
A T S R Q P
As you can see, the spiral always goes clockwise and moves from the outside to the inside.

The rules are simple:

You need to provide a full program using STDIN and STDOUT, or the nearest equivalent if not possible.
Given an input (1, 2, 3, 4), output the related spiral.
Trailing whitespaces are allowed
Leading whitespaces are allowed when used consistently
You need to use uppercase letter for the output, lowercase letters are not allowed.
This is code-golf, so the program with the least amount of bytes wins!

*/

#include <stdio.h>

#define STRINGIFY(...) #__VA_ARGS__

// clang-format off

static const char *SPIRAL1 = STRINGIFY(
A B C D E F \n\
T U V W X G \n\
S 5 6 7 Y H \n\
R 4 9 8 Z I \n\
Q 3 2 1 0 J \n\
P O N M L K \n\
);

static const char *SPIRAL2 = STRINGIFY(
P Q R S T A \n\
O 3 4 5 U B \n\
N 2 9 6 V C \n\
M 1 8 7 W D \n\
L 0 Z Y X E \n\
K J I H G F \n\
);

static const char *SPIRAL3 = STRINGIFY(
K L M N O P \n\
J 0 1 2 3 Q \n\
I Z 8 9 4 R \n\
H Y 7 6 5 S \n\
G X W V U T \n\
F E D C B A \n\
);

static const char *SPIRAL4 = STRINGIFY(
F G H I J K \n\
E X Y Z 0 L \n\
D W 7 8 1 M \n\
C V 6 9 2 N \n\
B U 5 4 3 O \n\
A T S R Q P \n\
);

// clang-format on

void
spiral(unsigned n)
{
	const char *tab[] = {
	    SPIRAL1,
	    SPIRAL2,
	    SPIRAL3,
	    SPIRAL4,
	};

	printf("%s\n", tab[n & 3]);
}

int
main(void)
{
	unsigned i;

	for (i = 0; i < 4; i++)
		spiral(i);

	return 0;
}
