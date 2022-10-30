/*

Your task is to improvise a hardware random-number generator with whatever hardware you have lieing around.

Challenge

Write a program with the following properties:

It prints either 0 or 1 (and nothing else).
The output depends on a physical process and not just the internal state of the computer.
There is no relation between outputs of subsequent runs (one minute apart).
The output is not predictable with any realistic effort.
The probability of the output being 0 is between 0.2 and 0.8.
It runs in less than a minute with a reasonably high probability.
You must explain why your program has these properties, if it is not obvious.

Clarifications and Restrictions
The following may seem like an awful lot of restrictions for a popularity contest, but ultimatively it’s all to ensure that the program remains within the spirit of the question,
somewhat works and to avoid solutions which are popular due to being a total overkill but are ultimatively rather boring.

The system time does not count as a physical process.
You may use any consumer-grade hardware you like from 8-inch floopy-disk drives to a USB rocket launcher to headphones – unless it is intended for random-number generation.
A piece of hardware is consumer-grade, if it is mass-produced and costs less than 1000 $/€/£, so you cannot use radio telescopes, the CERN, MRIs or your home-built particle detector.
You can only make the most basic assumptions on the state and alignment of the hardware such as being switched on (if it has a power switch) and being properly installed and functional.
For example you can assume a CD drive to be generally capable of reading a disk and not to be jammed, but you cannot assume it to be open or closed or to contain a disk.
In another example you cannot assume two pieces of hardware to be aligned to allow for a special interaction, but you can assume them to be in the same room.
You may leave the hardware in any state you like, unless you break it.
You can and must assume the hardware to be in a natural environment, but nothing more.
For example you can assume that the hardware is not positioned in a in tank of liquid helium nor in an extremely sound- and lightproof room nor in space.
However, you cannot assume any sound- and lightsources to be present except those that are only avoidable with radical efforts.
Your program must run on a standard desktop computer with a non-esoteric operating system of your choice. You may employ any software that is not specifically designed for random-number generation.
You cannot assume Internet access.
You can neither assume humans to be present nor absent, but you can assume that nobody intentionally interfers with your program, e.g., by manually stopping a fan or running a program that does nothing but switching off the microphone as often as possible.
You can only make the most basic assumptions about the software settings. For example, you can assume drivers to be installed and activated but you must be prepared for the sound to be muted.
You may leave the software settings in any state you like.

Bonus

A special bounty was awarded to a particularly short solution. This was rather by numbers of instructions and similar than by characters. The winners were (tied according to my criteria):

This answer by Franki.
This answer by Tejas Kale.
I could only award one answer and Tejas Kale’s answer won by lot.

*/

#define _GNU_SOURCE
#include <stdio.h>
#include <unistd.h>

int
main(void)
{
	char b[1];

	while (getentropy(b, sizeof(b)))
		sleep(1);
	printf("%d\n", b[0] & 1);
	return 0;
}
