/*

Take an array of nonnegative integers, such as [1, 0, 0, 1, 2, 4, 2, 0].
Then, draw that as a mountain where the integers represent altitude:

     x  
        
    x x 
x  x    
 xx    x

You may use any printable non-whitespace character in place of x, and adding padding or whitespace after lines or the output is fine (but not required).
You may optionally take one indexed inputs. Transposing the output is not allowed, but returning an array of lines is fine.

This is code-golf, so shortest answer (in bytes) per language wins.

*/

#include <stdio.h>

#define nelem(x) (sizeof(x) / sizeof(x[0]))
#define max(a, b) (((a) > (b)) ? (a) : (b))

void
mountain(unsigned *a, size_t n)
{
	size_t i, j;
	unsigned m;

	m = 0;
	for (i = 0; i < n; i++)
		m = max(m, a[i]);

	for (i = 0; i <= m; i++) {
		for (j = 0; j < n; j++)
			printf("%c", (m - i == a[j]) ? 'x' : ' ');
		printf("\n");
	}
}

int
main(void)
{
	unsigned a1[] = {1, 0, 0, 1, 2, 4, 2, 0};

	mountain(a1, nelem(a1));

	return 0;
}
