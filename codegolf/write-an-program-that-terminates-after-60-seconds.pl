#!/usr/bin/env perl

=begin comment

This is a cops and robbers challenge - Robber's Thread

Write a program that terminates after exactly 60 seconds (or as close to it as possible). For example:

#include <unistd.h>
int main(int argc, char **argv){
    sleep(60);
    return 0;
}

However, your goal is to write this program such that terminating after exactly 1 minute is essentially inherent to the program's execution -
it should be difficult to change the program to predictably run for a different amount of time without overhauling the algorithm.
The robbers will attempt to change your program such that it terminates after 31 seconds instead of 60, and they will have to do so with a solution whose Levenshtein edit distance is up to half of the length of your submission.

If you do not wish to take advantage of system interrupts or the system clock, you can use either of the following:

The speed of printing to stdout is controlled by the baud rate of the terminal you are printing to.
If you wish, you can control the speed of your program by printing to stdout with a set baud rate.
However, you must also cite an actual piece of hardware or terminal program that has that baud rate as default (e.g. a serial printer with a default print speed of 300 baud).
If you are working in a language where all operations take some constant amount of time (such as assembly language), you can control the speed of your program by specifying the processor's clock rate.
However, this too must be accompanied with a citation of an actual processor chip that runs at that speed (e.g. the 1 MHz 6502 put inside Apple //e and NES boards).
This is cops and robbers, so prepare to rigorously defend your algorithm! If your solution has been cracked, put [Cracked](link to cracker) in your header.
If your solution remains uncracked after exactly 2 weeks, it is safe from future cracking attempts - put Safe in your header and explain how your algorithm works.

The winner of this challenge is the Safe solution with the most upvotes.

=end comment
=cut

sleep 60;
