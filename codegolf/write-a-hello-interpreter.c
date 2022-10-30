/*

Background

Hello is a language "written" by Anne Veling, which errors if the program does not contain only h, and will print Hello World for every h

Task

You are to write an interpreter/compiler for Hello.
Example in Python

import os
i = input("Program: ")
for a in i:
    if a != 'h':
        print("err")
        quit()
    else:
        print("Hello World")

Details

    If the program is not only hs, it must print err or error (case-insensitive)
    It's okay if you print "Hello World"s before your program discovers a non-h character and errors, however, the program must halt if a non-h
    You may throw an error, as long as you print err/error before throwing, or by using a custom error builtin, like raise SyntaxError('err') in python. (basically, you have to purposefully error with err/error
    Assume the program will not be empty
    Output can have a trailing newline, space, or nothing to separate Hello Worlds
    If a program has multiple lines, it should error (due to \n not being an h)
    You can assume that input will always be ASCII 33-126 and 10 (decimal)
    The hs are case sensitive (so H is not a valid program) instruction is found
    This is code-golf, shortest answer wins

Test cases

Input:

h

Output:

Hello World

Input:

hhhhhh

Output:

Hello WorldHello WorldHello WorldHello WorldHello WorldHello World

(again, it doesn't matter whether it's spaces, newlines, or nothing to separate `Hello World`s

Input:

rubbish

Output:

err

Input:

huh

Output:

Hello Worlderr

Or

err

First challenge so please have mercy

*/

#include <stdio.h>

void
interpret(const char *s)
{
	size_t i;

	for (i = 0; s[i]; i++) {
		if (s[i] == 'h')
			printf("Hello World");
		else {
			printf("err");
			break;
		}
	}
	printf("\n");
}

int
main(void)
{
	interpret("h");
	interpret("hhhhhh");
	interpret("rubbish");
	interpret("huh");

	return 0;
}
