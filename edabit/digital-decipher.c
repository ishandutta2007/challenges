/*

In Digital Decipher, decoding is done by the simple subtraction of numbers in the key and the corresponding characters on a given array. You may want to solve this challenge before proceeding further.

Create a function that takes two arguments; a positive integer and an array of integers and returns a decoded message as string.

Assign a unique number to each letter of the alphabet.

 a  b  c  d  e  f  g  h  i  j  k  l  m
 1  2  3  4  5  6  7  8  9  10 11 12 13
 n  o  p  q  r  s  t  u  v  w  x  y  z
 14 15 16 17 18 19 20 21 22 23 24 25 26

There are some variations on the rules of encipherment. One version of the cipher rules are outlined below:

eMessage = [20, 12, 18, 30, 21]
key = 1939

digitalDecipher(eMessage, key) ➞ "scout"

Subtract each key digit from eMessage consecutive digits:

  20 12 18 30 21
-  1  9  3  9  1
 ---------------
  19  3 15 21 20

Write the corresponding number against each character:

 s  c  o  u  t
19  3 15 21 20

See the below example for a better understanding:

eMessage = [14, 10, 22, 29, 6, 27, 19, 18, 6, 12, 8]
key = 1939

digitalDecipher(eMessage, key) ➞ "masterpiece"

  14 10 22 29  6 27 19 18  6  12 8
-  1  9  3  9  1  9  3  9  1  9  3
  --------------------------------
  13  1 19 20  5 18 16  9  5  3  5
   m  a  s  t  e  r  p  i  e  c  e

Examples

digitalDecipher([20, 12, 18, 30, 21], 1939) ➞ "scout"

digitalDecipher([14, 30, 11, 1, 20, 17, 18, 18], 1990) ➞ "mubashir"

digitalDecipher([6, 4, 1, 3, 9, 20], 100) ➞ "edabit"

Notes

N/A


*/

#include <assert.h>
#include <stdio.h>
#include <string.h>
#include <limits.h>

#define nelem(x) (sizeof(x) / sizeof(x[0]))

char *
decipher(int *a, size_t n, int k, char *b)
{
	int d[sizeof(k) * CHAR_BIT];
	size_t i, j, l, m;

	m = 0;
	do {
		d[m++] = k % 10;
		k /= 10;
	} while (k);

	l = m;
	for (i = j = 0; i < n; i++) {
		b[j++] = (a[i] - d[--l]) + 'a' - 1;
		if (l == 0)
			l = m;
	}
	b[j] = '\0';

	return b;
}

void
test(int *a, size_t n, int k, const char *r)
{
	char b[128];

	decipher(a, n, k, b);
	printf("%s\n", b);
	assert(!strcmp(b, r));
}

int
main(void)
{
	int a1[] = {20, 12, 18, 30, 21};
	int a2[] = {14, 10, 22, 29, 6, 27, 19, 18, 6, 12, 8};
	int a3[] = {15, 17, 14, 17, 19, 7, 21, 7, 2, 20, 20};
	int a4[] = {14, 30, 11, 1, 20, 17, 18, 18};
	int a5[] = {17, 10, 15, 16, 20, 29, 5, 21};
	int a6[] = {17, 10, 17, 14, 20, 29, 7, 19, 2, 18, 24, 11, 16, 27, 9, 10};
	int a7[] = {6, 4, 1, 3, 9, 20};

	test(a1, nelem(a1), 1939, "scout");
	test(a2, nelem(a2), 1939, "masterpiece");
	test(a3, nelem(a3), 12, "nomoretears");
	test(a4, nelem(a4), 1990, "mubashir");
	test(a5, nelem(a5), 1947, "pakistan");
	test(a6, nelem(a6), 1965, "pakistanairforce");
	test(a7, nelem(a7), 100, "edabit");

	return 0;
}
