/*

You are Desmond Hume. For the last 3 years, you and your partner, Kelvin, have been slave to a computer that requires a very specific sequence to be entered into it every 108 minutes to save the world.

4 8 15 16 23 42

Your partner died 40 days ago (due to an unfortunate accident involving Kelvin's head and a big rock), and you have no one to talk to.
No one to enter the numbers for you. No one to break the monotony. At first it wasn't too bad, but you can't handle the silence anymore.
And if you have to listen to "Make Your Own Kind Of Music" one more time, you're going to scream.

You decide that You need to get out. To escape. You decide that you will build a raft and sail off the island. But then you realize the bad news: you're stuck here. You need to keep saving the world.

But then you realize the good news: You are a programmer! You can automate saving the world! Excited, you run over to the computer, and, using your trusty python skills, you whip up a quick script to enter the numbers for you.

import time

while True:
    print "4 8 15 16 23 42"
    time.sleep(60 * 107)

Quick, simple, reliable, short, and easy. Everything that a good python script should be. But then, when you try to test it, you get an error.

Bad command or file name.

Huh, strange. Oh well, let's try c++.

#include <iostream>
#include <unistd.h> 

int main()
{
    while (true)
    {
        std::cout << "4 8 15 16 23 42" << std::endl;
        sleep(60 * 107);
    }
}

No! C++ isn't found either. You try every language you can think of. Javascript, Ruby, Perl, PHP, C#. Nothing. This computer was made before all of the popular languages of the day.
The Challenge

You must write a program that will:

1) Print exactly this: "4 8 15 16 23 42" (without quotes)

2) Wait some time between 104 and 108 minutes. (According to The Lost Wiki)

3) Repeat forever. (Or until you realize that this is all an elaborate scam, and that you're stuck in a weird limbo due to lazy writing, and asking questions that you don't have answers for. Thanks JJ Abrams!)

However there is a catch: You MUST use a language that the computer in the swan station would actually be capable of running. Assuming that

A) The computer was up to date at the time of construction,

B) There have been no updates to the computers software, and

C) There is no internet connection available (Meaning you can't download Golfscript...),

and making our best guess for the construction date of The Swan Station, (Again, The Lost Wiki.)

This means you have to use a language that was first released on or before Dec 31, 1977.


A few rule clarifications:

    Including libraries is OK, but the same rule applies (libraries must be pre-1977).

    You do not have to worry about OS compatibility.

    If you use system, or your languages equivalent, you must prove that any system commands you use would have been available before 1978. A wikipedia article is probably the best way to prove this.

    It doesn't matter when you start the program, just as long as it ends up in a pattern of alternating printing and sleeping. (print-sleep-print-sleep... and sleep-print-sleep-print... are both acceptable.)

This is Code-Golf, so shortest answer in bytes wins.

*/

#include <stdio.h>
#include <unistd.h>

int
main(void)
{
	for (;;) {
		printf("4 8 15 16 23 42\n");
		sleep(60 * 107);
	}
	return 0;
}
