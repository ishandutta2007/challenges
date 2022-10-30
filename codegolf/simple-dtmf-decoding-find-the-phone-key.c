/*

This is a simple challenge which hopefully may lead to some creative answers.

Quoting Wikipedia: "Dual-tone multi-frequency signaling (DTMF) is an in-band telecommunication signaling system using the voice-frequency band over telephone lines between telephone equipment and other communications devices and switching centers."

Task

Given two integers representing the column and row frequencies in the following table, your task is to output the corresponding key:

       | 1209 Hz | 1336 Hz | 1477 Hz
-------+---------+---------+---------
697 Hz |    1    |    2    |    3
770 Hz |    4    |    5    |    6
852 Hz |    7    |    8    |    9
941 Hz |    *    |    0    |    #

Examples

If the input is [ 1209, 852 ], the expected output is "7".
If the input is [ 1477, 941 ], the expected output is "#".

Rules

You must take input as integers in any reasonable format, such as two separate variables or an array of two variables. Please specify in which order your program is expecting them (either column_freq, row_freq or row_freq, column_freq).
The input is guaranteed to be valid.
You must print or output a character. However, you're also allowed to output an integer for digit keys.
This is code-golf, so the shortest answer in bytes wins!

*/

#include <assert.h>
#include <stdio.h>

#define nelem(x) (sizeof(x) / sizeof(x[0]))

int
find(int v, const int *a, size_t n)
{
	size_t i;

	for (i = 0; i < n; i++) {
		if (v == a[i])
			return i;
	}
	return -1;
}

int
dtmfdec(int f1, int f2)
{
	static const int cols[] = {1209, 1336, 1477};
	static const int rows[] = {697, 770, 852, 941};
	static const int keys[4][3] = {
	    {'1', '2', '3'},
	    {'4', '5', '6'},
	    {'7', '8', '9'},
	    {'*', '0', '#'},
	};

	int r, c;

	c = find(f1, cols, nelem(cols));
	r = find(f2, rows, nelem(rows));
	if (r < 0 || c < 0)
		return -1;

	return keys[r][c];
}

int
main(void)
{
	assert(dtmfdec(1209, 852) == '7');
	assert(dtmfdec(1477, 941) == '#');

	return 0;
}
