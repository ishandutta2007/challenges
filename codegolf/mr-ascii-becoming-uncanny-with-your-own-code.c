/*

Let's make a little stupid program that simulates the meme "Mr. incredible becoming uncanny", but in this case, our little ASCII friend is going to react to our code length.

Objective:

Create a program that takes anything (preferably a program) as input and outputs this:

Pov:
<face>   you score X on codegolf
Where X is the length of the input and the face depends on the value of X:

X < 20         = \(^-^)/
20 ≤ X < 50    = -(o_o)-
50 ≤ X < 100   = /(¬_¬)\
100 ≤ X < 250  = /(º-º)\
250 ≤ X < 500  = /(ª@ª)\
X ≥ 500        = /(x_x)\
Example:

I have made my own ungolfed version in C#: Try it online!

using System;
class Program {
static void Main(string[] args) {
    Console.WriteLine("Pov:");

    if(args[0].Length < 20){
        Console.WriteLine("\\(^-^)/   you score "+args[0].Length+" on codegolf");

    }else if(args[0].Length < 50){
        Console.WriteLine("-(o_o)-   you score "+args[0].Length+" on codegolf");

    }else if(args[0].Length < 100){
        Console.WriteLine("/(¬_¬)\\   you score "+args[0].Length+" on codegolf");

    }else if(args[0].Length < 250){
        Console.WriteLine("/(º-º)\\   you score "+args[0].Length+" on codegolf");

    }else if(args[0].Length < 500){
        Console.WriteLine("/(ª@ª)\\   you score "+args[0].Length+" on codegolf");

    }else{
        Console.WriteLine("/(x_x)\\   you score "+args[0].Length+" on codegolf");

    }
}
}

If the program takes itself as input, it will output:

Pov:

/(x_x)\   you score 741 on codegolf

Rules:

The output must have exactly three spaces betwen the face and the text.
The shortest code in bytes wins.

*/

#include <stdio.h>

#define nelem(x) (sizeof(x) / sizeof(x[0]))

void
face(int n)
{
	static const struct {
		int score;
		char mood[128];
	} tab[] = {
	    {20, u8"\\(^-^)/"},
	    {50, u8"-(o_o)-"},
	    {100, u8"/(¬_¬)\\"},
	    {250, u8"/(º-º)\\"},
	    {500, u8"/(ª@ª)\\"},
	    {0, u8"/(x_x)\\"},
	};

	size_t i;

	for (i = 0; i < nelem(tab); i++) {
		if (n < tab[i].score || tab[i].score == 0)
			break;
	}

	printf("%s   you score %d on codegolf\n", tab[i].mood, n);
}

int
main(void)
{
	face(10);
	face(20);
	face(50);
	face(100);
	face(250);
	face(500);
	return 0;
}
