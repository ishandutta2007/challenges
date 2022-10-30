/*

Write a script that writes to standard output, or your language's equivalent, 100 lines of (valid) Java code that begins with:

class Tuple1 {public Object _0;}
class Tuple2 {public Object _0,_1;}
class Tuple3 {public Object _0,_1,_2;}
class Tuple4 {public Object _0,_1,_2,_3;}
class Tuple5 {public Object _0,_1,_2,_3,_4;}
class Tuple6 {public Object _0,_1,_2,_3,_4,_5;}
class Tuple7 {public Object _0,_1,_2,_3,_4,_5,_6;}
class Tuple8 {public Object _0,_1,_2,_3,_4,_5,_6,_7;}
class Tuple9 {public Object _0,_1,_2,_3,_4,_5,_6,_7,_8;}
class Tuple10 {public Object _0,_1,_2,_3,_4,_5,_6,_7,_8,_9;}
class Tuple11 {public Object _0,_1,_2,_3,_4,_5,_6,_7,_8,_9,_10;}
class Tuple12 {public Object _0,_1,_2,_3,_4,_5,_6,_7,_8,_9,_10,_11;}

The last line should begin with class Tuple100.

This is code-golf, so the shortest code in bytes wins!

*/

#include <stdio.h>

void
gen(int n)
{
	int i, j;

	for (i = 0; i < n; i++) {
		printf("class Tuple%d {public Object ", i + 1);
		for (j = 0; j <= i; j++) {
			printf("_%d", j);
			if (j + 1 <= i)
				printf(",");
		}
		printf(";}\n");
	}
}

int
main(void)
{
	gen(100);
	return 0;
}
