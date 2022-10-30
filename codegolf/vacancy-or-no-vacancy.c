/*

We've all seen the signs on motels telling us if there's a vacancy or not:

Typically, these will permanently have the letters of VACANCY lit up, and have the letters of NO lit up if there isn't any room in the motel.
The challenge

The average motel in the U.S. has 200 rooms.

You will write a program/function that takes an integer T (for taken rooms) as its only input.
Your program will then display the words NO VACANCY. The letters of VACANCY will be printed in red.
If T ≥ 200, the letters of NO will also be printed in red.

For example, assuming a.out is your program and "input" = command line argument:
enter image description here
(I typo'd and my system ignores case.)
The rules

    Your program/function must display (or, if lambda, return) the exact string NO VACANCY, including case.
    Your program/function may only set the text foreground color to red and not the background.
    If you wish, you may use ANSI escape codes to print the red color - \x1b[31m will work.
    Your program/function may not change the text color of your shell after it finishes.
    Your program/function must terminate normally.
    Your program/function must print only to standard output.
    Your program/function must use your shell/terminal/IDE's default background color. (If you choose to have graphical output you may choose whatever color you like, except red.)
    If T ≤ 200, the letters of NO must be printed in your shell/terminal/IDE's default foreground color. (If you choose to have graphical output, once again you may choose whatever color you like)
    If for some reason your shell/terminal/IDE's default foreground/background color is red, you must print with a black background and a default white foreground.
    If you choose to use graphical output, red may only be used when specified in the program (e.g. your background color or default text color may not be red).

The winner

As usual with code-golf, the shortest program wins! Brownie points for graphical output.
I'll accept the shortest answer in a week. Happy golfing!

*/

#include <stdio.h>

void
vacancy(unsigned n)
{
	if (n >= 200)
		printf("\033[31;1m%s", "NO VACANCY");
	else
		printf("\033[37;1m%s \033[31;1m%s", "NO", "VACANCY");
	printf("\033[0m\n");
}

int
main(void)
{
	vacancy(200);
	vacancy(50);
	return 0;
}
