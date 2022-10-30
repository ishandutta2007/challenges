/*

 Challenge

I've recently gotten into 8-bit computers and are fascinated with the workings of them and others alike; thus the objective of this code golf, is to replicate a portion of the Woz Monitor, designed by Steve Wozniak for the Apple I.

You are to store an array of 22 hexadecimal values with a width of two bytes, (min value $10, max value $FF), and then take in n-amount of inputs. (Normally two; languages like Brainfuck might have a hard time).
The inputs will refer to where in the array to start printing from, and where to stop; an input with defined behaviour will have their starting value less or equal to the ending value.
Your program must then be capable of printing every hexadecimal value between, and including, the hexadecimals inputted.

An example of this:

Array
00 01 02 03 04 05 06 07 08 09 0A 0B 0C 0D 0E 0F 10 11 12 13 14 15

Values
FF F4 B6 D7 40 00 00 A4 F0 00 FF 0D 9C 21 65 C4 02 28 90 E7 D6 A5

input first num:
04
input second num:
14
40 00 00 A4 F0 00 FF 0D 9C 21 65 C4 02 28 90 E7 D6

Now the interesting part of this exercise, is that you can use whatever you want to check the bounds of the users input. Person inputs hello and your program has undefined behaviour? It quits without notice? They are both valid.

The only rules are:

1. You must include the values of the 22 hexadecimal values as part of your program before it starts, (can't ask the user for inputs).
2. The output of the hexadecimal values must follow the exact format: 00 FF 00 FF 00 Trailing spaces, tabs or lines are OK. Characters are not.
3. The program doesn't have to ask for the inputs with a message. Leave the "message" blank if you wish. The user must input the hex-bounds however.
4. As with the values of the 22 hexadecimals are up to you to decide, you must make a program that actually fetches the values from storage, opposed to mimicking a program by simply printing values. (such as a list of $00's).
5. n-amount of inputs, refers to the amount of inputs required for your language of choice to recognise a hexadecimal of two byte-width. eg. (Brainfuck will require two inputs per hex, making it four for the two).

Feel free to comment if you need clarification.

This is code golf, so the shortest answer in the number of bytes is the winner.

*/

#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

#define nelem(x) (sizeof(x) / sizeof(x[0]))

void
dump(uint8_t *a, size_t n, size_t x, size_t y)
{
	size_t i;

	for (i = x; i <= y && i < n; i++)
		printf("%02X ", a[i]);
	printf("\n");
}

int
main(void)
{
	uint8_t a1[] = {0xFF, 0xF4, 0xB6, 0xD7, 0x40, 0x00, 0x00, 0xA4, 0xF0, 0x00, 0xFF, 0x0D, 0x9C, 0x21, 0x65, 0xC4, 0x02, 0x28, 0x90, 0xE7, 0xD6, 0xA5};

	dump(a1, nelem(a1), 0x04, 0x14);
	return 0;
}
