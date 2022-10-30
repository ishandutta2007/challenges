/*

Create a function that counts the number of times a particular letter shows up in the word search.
Examples

letterCounter([
  ["D", "E", "Y", "H", "A", "D"],
  ["C", "B", "Z", "Y", "J", "K"],
  ["D", "B", "C", "A", "M", "N"],
  ["F", "G", "G", "R", "S", "R"],
  ["V", "X", "H", "A", "S", "S"]
], "D") ➞ 3

// "D" shows up 3 times: twice in the first row, once in the third row.

letterCounter([
  ["D", "E", "Y", "H", "A", "D"],
  ["C", "B", "Z", "Y", "J", "K"],
  ["D", "B", "C", "A", "M", "N"],
  ["F", "G", "G", "R", "S", "R"],
  ["V", "X", "H", "A", "S", "S"]
], "H") ➞ 2

Notes

You will always be given an array with five sub-arrays.

*/

#include <assert.h>
#include <stdio.h>

size_t
letters(size_t r, size_t c, char m[r][c], char ch)
{
	size_t i, j, l;

	l = 0;
	for (i = 0; i < r; i++) {
		for (j = 0; j < c; j++)
			l += (m[i][j] == ch);
	}
	return l;
}

int
main(void)
{
	char m1[5][6] = {
		{ 'D', 'E', 'Y', 'H', 'A', 'D' },
		{ 'C', 'B', 'Z', 'Y', 'J', 'K' },
		{ 'D', 'B', 'C', 'A', 'M', 'N' },
		{ 'F', 'G', 'G', 'R', 'S', 'R' },
		{ 'V', 'X', 'H', 'A', 'S', 'S' },
	};

	assert(letters(5, 6, m1, 'D') == 3);
	assert(letters(5, 6, m1, 'H') == 2);
	assert(letters(5, 6, m1, 'Z') == 1);
	assert(letters(5, 6, m1, 'R') == 2);
	assert(letters(5, 6, m1, 'X') == 1);
	assert(letters(5, 6, m1, 'S') == 3);

	return 0;
}
