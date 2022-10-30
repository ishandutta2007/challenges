/*

Your task is to print the hexidecimal times table:

00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 
00 01 02 03 04 05 06 07 08 09 0a 0b 0c 0d 0e 0f 
00 02 04 06 08 0a 0c 0e 10 12 14 16 18 1a 1c 1e 
00 03 06 09 0c 0f 12 15 18 1b 1e 21 24 27 2a 2d 
00 04 08 0c 10 14 18 1c 20 24 28 2c 30 34 38 3c 
00 05 0a 0f 14 19 1e 23 28 2d 32 37 3c 41 46 4b 
00 06 0c 12 18 1e 24 2a 30 36 3c 42 48 4e 54 5a 
00 07 0e 15 1c 23 2a 31 38 3f 46 4d 54 5b 62 69 
00 08 10 18 20 28 30 38 40 48 50 58 60 68 70 78 
00 09 12 1b 24 2d 36 3f 48 51 5a 63 6c 75 7e 87 
00 0a 14 1e 28 32 3c 46 50 5a 64 6e 78 82 8c 96 
00 0b 16 21 2c 37 42 4d 58 63 6e 79 84 8f 9a a5 
00 0c 18 24 30 3c 48 54 60 6c 78 84 90 9c a8 b4 
00 0d 1a 27 34 41 4e 5b 68 75 82 8f 9c a9 b6 c3 
00 0e 1c 2a 38 46 54 62 70 7e 8c 9a a8 b6 c4 d2 
00 0f 1e 2d 3c 4b 5a 69 78 87 96 a5 b4 c3 d2 e1 

Specifications:

    You can print the hex values in uppercase.
    Your lines can end with a trailing space and the program output can end with a trailing newline.
    Every hex value must be padded to 2 digits with 0s as shown.

This is code-golf, so the shortest answer (measured in bytes) wins.

*/

#include <stdio.h>

void
table(void)
{
	int i, j;

	for (i = 0; i < 16; i++) {
		for (j = 0; j < 16; j++)
			printf("%02x ", i * j);
		printf("\n");
	}
	printf("\n");
}

int
main(void)
{
	table();
	return 0;
}
