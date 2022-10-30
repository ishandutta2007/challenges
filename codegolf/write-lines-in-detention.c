/*

Introduction

Bad news guys - you got detention. Your English teacher doesn't understand this site and wants you to "stop doing math on your digital dohickeys, this is English class!"

She sentenced you to write her favorite saying on the blackboard 25 times, which will give a total of 100 lines on the blackboard.

The eighteen-hundreds were a time for rum.
The nineteen-hundreds were a time for fun.
The two-thousands are a time to run
a civilized classroom.

Lucky for you, you are an avid reader (not to mention an expert code-golfer)! You have a read about a trick that might possibly get you off easy.

foxtrot

(Foxtrot by Bill Amend)

Unfortunately for Jason, it didn't work out. But you have a better idea! Since your English teacher thinks you're doing math, if you leave all the numbers out of your program it just might work! You also want to keep your program as short as possible because you are a lazy student and don't want to write a lot on the board.
Write a program that complies with the following rules:

    Your program must print the 4 above lines 25 times. The lines must be outputted in that order, repeating. Total exactly 100 lines of output (a trailing newline at the very end or a leading newline at the very beginning is okay).
    You cannot use the characters 0123456789. Your teacher gets confused by math and will call you out!
    You can use any imports and external libraries without counting the imports. Your English teacher doesn't know about programming. Jason could have saved a lot of work by not writing #include <stdio.h> and you don't want to make his same mistakes!
    Score your program by byte count. Lowest score wins!

*/

#include <stdio.h>

void
recurse(int c)
{
	if (c == 'z')
		return;
	printf("The eighteen-hundreds were a time for rum.\n");
	printf("The nineteen-hundreds were a time for fun.\n");
	printf("The two-thousands are a time to run\n");
	printf("a civilized classroom.\n");
	recurse(++c);
}

int
main(void)
{
	recurse('a');
	return 'a' - 'a';
}
