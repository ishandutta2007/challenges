/*

Description:

Today we will be making some simple 8x8 bitmap pictures. You will be given 8 hex values that can be 0-255 in decimal value (so 1 byte). Each value represents a row. So 8 rows of 8 bits so a 8x8 bitmap picture.
Input:

8 Hex values.
example:

18 3C 7E 7E 18 18 18 18
Output:

A 8x8 picture that represents the values you read in.

For example say you got the hex value FF. This is 1111 1111 . "1" means the bitmap at that location is on and print something. "0" means nothing is printed so put a space. 1111 1111 would output this row:

xxxxxxxx

if the next hex value is 81 it would be 1000 0001 in binary and so the 2nd row would output (with the first row)

xxxxxxxx
x      x

Example output based on example input:

   xx
  xxxx
 xxxxxx
 xxxxxx
   xx
   xx
   xx
   xx

Challenge input:

Here are 4 pictures to process and display:

FF 81 BD A5 A5 BD 81 FF
AA 55 AA 55 AA 55 AA 55
3E 7F FC F8 F8 FC 7F 3E
93 93 93 F3 F3 93 93 93

Output Character:

I used "x" but feel free to use any ASCII value you want. Heck if you want to display it using graphics, feel free to be creative here.

*/

#include <stdio.h>
#include <stdint.h>

#define nelem(x) (sizeof(x) / sizeof(x[0]))

void
hexpic(uint8_t *p, size_t n)
{
	size_t i, j;

	for (i = 0; i < n; i++) {
		for (j = 0; j < 8; j++) {
			if (p[i] & (1 << j))
				printf("X");
			else
				printf(" ");
		}
		printf("\n");
	}
	printf("\n");
}

int
main(void)
{
	uint8_t p1[] = {0x18, 0x3C, 0x7E, 0x7E, 0x18, 0x18, 0x18, 0x18};
	uint8_t p2[] = {0xFF, 0x81, 0xBD, 0xA5, 0xA5, 0xBD, 0x81, 0xFF};
	uint8_t p3[] = {0xAA, 0x55, 0xAA, 0x55, 0xAA, 0x55, 0xAA, 0x55};
	uint8_t p4[] = {0x3E, 0x7F, 0xFC, 0xF8, 0xF8, 0xFC, 0x7F, 0x3E};
	uint8_t p5[] = {0x93, 0x93, 0x93, 0xF3, 0xF3, 0x93, 0x93, 0x93};

	hexpic(p1, nelem(p1));
	hexpic(p2, nelem(p2));
	hexpic(p3, nelem(p3));
	hexpic(p4, nelem(p4));
	hexpic(p5, nelem(p5));

	return 0;
}
