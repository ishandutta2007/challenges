/*

The 80's TV series Knight Rider featured an intelligent, self-aware car called KITT. One distinctive aspect of the car was a front-mounted scanner bar that allowed KITT to "see" (and that looked suspiciously familiar to fans of another, earlier TV series).

The scanner had eight lights as seen in this picture:

enter image description here

The lights "moved" as shown in this animated image.

Your task, as you have guessed by now, it to recreate the scanner bar with the moving lights in ASCII art.
The challenge

Given an integer t, output the state of the scanner bar at that instant, defined as follows:

    The scanner consists of eight lights.
    At any instant one of the lights is active, and is shown as #. The lights that were active at times t-1 and t-2 are now dimmed, and are shown as +; unless they coincide with the current active one. The rest of the lights are off, and are shown as -.
    The active light moves left to right, then right to left.

The exact output for each t is detailed below.

0  -->  #++-----   % The leftmost light is active, and it just came from the right.
                   % The two neighbouring lights are dimmed
1  -->  +#------   % The active light has bounced to the right, and it is covering
                   % one of the two lights that should be dimmed. So there is only
                   % one dimmed light
2  -->  ++#-----   % The active light has moved one more step to the right, and the
                   % two trailing dimmed lights are visible
3  -->  -++#----
7  -->  -----++#
8  -->  ------#+   % The active light has bounced to the left
9  -->  -----#++
10 -->  ----#++-
13 -->  -#++----
14 -->  #++-----   % Same as 0
15 -->  +#------   % Same as 1

For negative values of t the cycle is simply extended:

-1 -->  -#++----   % Same as 13
-2 -->  --#++---   % Same as 12

#Additional rules

You can write a program or function.

Output can contain trailing whitespace and a leading newline.

Shortest code in bytes wins.

*/

#include <stdio.h>

#define nelem(x) (sizeof(x) / sizeof(x[0]))

int
mod(int x, int m)
{
	x %= m;
	if (x < 0)
		x += m;
	return x;
}

const char *
cycle(int n)
{
	static const char *tab[] = {
	    "#++-----",
	    "+#------",
	    "++#-----",
	    "-++#----",
	    "--++#---",
	    "---++#--",
	    "----++#-",
	    "-----++#",
	    "------#+",
	    "-----#++",
	    "----#++-",
	    "---#++--",
	    "--#++---",
	    "-#++----",
	};
	return tab[mod(n, nelem(tab))];
}

int
main(void)
{
	int i;

	for (;;) {
		for (i = 0; i <= 13; i++)
			printf("%s\n", cycle(i));
	}
	return 0;
}
