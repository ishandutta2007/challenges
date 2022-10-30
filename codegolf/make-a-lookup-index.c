/*

Given a string, return a table where the first column has the unique letters of the string in order of occurrence and subsequent columns list the indices of that letter in the string, using zero or one-based indexing. Horizontal whitespace does not matter, as long as the left-most column is vertically aligned. Indices must be in ascending order from left to right.

Examples

Using zero-based indexing and given "abracadabra", return

a 0 3 5 7 10
b 1 8       
r 2 9       
c 4         
d 6   

Using one-based indexing and given "3141592653589793238462643383279503", return:

3  1 10 16 18 25 26 28 34
1  2  4                  
4  3 20 24               
5  5  9 11 32            
9  6 13 15 31            
2  7 17 22 29            
6  8 21 23               
8 12 19 27               
7 14 30                  
0 33                     

*/

#include <stdio.h>
#include <string.h>
#include <ctype.h>

void
lookindex(const char *s)
{
	size_t h[256];
	size_t i, j;

	memset(h, 0, sizeof(h));
	for (i = 0; s[i]; i++) {
		if (++h[s[i] & 0xff] != 1)
			continue;

		if (isprint(s[i]))
			printf("%c", s[i]);
		else
			printf("'%#x'", s[i] & 0xff);

		for (j = i; s[j]; j++) {
			if (s[i] == s[j])
				printf(" %zu", j);
		}
		printf("\n");
	}
	printf("\n");
}

int
main(void)
{
	lookindex("abracadabra");
	lookindex("3141592653589793238462643383279503");

	return 0;
}
