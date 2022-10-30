/*

Our fleet managed to get one of the enemy's top-secret codes from the remains of its fallen ship.
The codes were immediately sent over to our code-breaking base over at Bleckley Park ;) for analysis.
The team found that each code contains 25 numbers with one missing.
The missing number corresponds to a letter in the English alphabet.
Your job is to find a more efficient Method of decrypting the messages by digitizing the process.

Write a function that takes an array, detects the missing number (in the array), and returns its corresponding letter.

Examples

decrypt([24, 12, 2, ..., 25]) ➞ 'N'
// The missing number is 14.

decrypt([24, 12, 2, ..., 25]) ➞ 'O'
// The missing number is 15.

decrypt([24, 12, 2, ..., 25]) ➞ 'P'
// The missing number is 16.

Notes

    The array will only contain positive integers from 1 to 26 with one missing.
    There will be no duplicate numbers.
    Return the capital letter.

*/

#include <assert.h>

int
decrypt(int a[25])
{
	int i, v;

	for (i = v = 0; i < 25; i++)
		v ^= a[i];
	return 'A' + (v ^ 0x1b) - 1;
}

int
main(void)
{
	int a1[] = {21, 2, 5, 25, 7, 20, 15, 3, 6, 9, 16, 19, 1, 4, 11, 22, 10, 13, 12, 18, 24, 17, 23, 14, 26};
	int a2[] = {22, 7, 2, 15, 10, 4, 11, 25, 1, 8, 23, 12, 17, 16, 14, 13, 3, 21, 20, 6, 19, 9, 24, 18, 26};
	int a3[] = {17, 3, 15, 6, 21, 7, 18, 5, 13, 23, 24, 16, 8, 19, 25, 2, 9, 11, 22, 10, 20, 14, 1, 4, 26};
	int a4[] = {8, 6, 23, 4, 25, 13, 7, 19, 15, 3, 14, 5, 21, 11, 1, 2, 24, 18, 22, 16, 9, 20, 10, 17, 26};
	int a5[] = {19, 12, 14, 21, 22, 3, 11, 20, 9, 16, 24, 17, 2, 10, 13, 18, 7, 8, 4, 5, 1, 6, 25, 23, 26};

	assert(decrypt(a1) == 'H');
	assert(decrypt(a2) == 'E');
	assert(decrypt(a3) == 'L');
	assert(decrypt(a4) == 'L');
	assert(decrypt(a5) == 'O');

	return 0;
}
