/*

Introduction

Every letter in the English alphabet can be represented as an ASCII code. For example, a is 97, and S is 83.
As we all know, the formula for averaging two numbers x and y is (x+y)/2

I'm pretty sure you can see where this is going. Your challenge is to average two letters.

Challenge

Your program must take two letters as input, and output the average of the ASCII values in it. If the average is a decimal, you should truncate it.

Input will always be two ASCII letters. You can assume they will always be valid, but the case may vary.
Basically, both letters will be in the range 97-122 or 65-90. The second letter will always have a greater ASCII value than the first.
If your language has no method of input, you may take input from command line arguments or from a variable.
You must output the ASCII character signified by the average of the two numbers. As stated above, it should always be truncated to 0 decimal places.
If your language has no method of output, you may store it in a variable. Exit codes and return values are considered valid output methods.

*/

#include <stdio.h>

int
ascavg(char a, char b)
{
	return (a + b) / 2;
}

int
main(void)
{
	printf("%c\n", ascavg('A', 'C'));
	printf("%c\n", ascavg('a', 'z'));
	printf("%c\n", ascavg('d', 'j'));
	printf("%c\n", ascavg('B', 'e'));
	printf("%c\n", ascavg('Z', 'a'));
	return 0;
}
