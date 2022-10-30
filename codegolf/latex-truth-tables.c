/*

Write a program or a function that accepts the list of outputs from a logic function and outputs the LaTeX code for its truth table.

The inputs should be labeled as lowercase letters a-z, and the output should be labelled as F.
The length of list of inputs will always be shorter than 2^25, which means that number of inputs will always be less than 25, so you can use letters from lowercase alphabet for input names.

Input
A number n of inputs and list of length 2^n of binary numbers which represents the outputs of a logical function.

Output
LaTeX code that produces the truth table for that function. Input and output values should be centered in rows.
There must be a line between table header and its values and between inputs and output, so the code should be similar to that below.

\begin{tabular}{c * <NUMBER OF INPUTS>|c}
<INPUTS>&F\\
\hline
<INPUT VECTOR i>&<OUTPUT>\\
\end{tabular}
Example
Input:

2
[0, 0, 0, 1]
Output:

\begin{tabular}{cc|c}
a & b & F \\
\hline
0 & 0 & 0 \\
0 & 1 & 0 \\
1 & 0 & 0 \\
1 & 1 & 1 \\
\end{tabular}
Which when displayed in LaTeX shows the following truth table

Truth table

General rules
This is code-golf, so shortest answer in bytes wins.
Default Loopholes are forbidden.

*/

#include <stdio.h>

typedef unsigned uint;

char *
mkname(char *b, uint i, uint n)
{
	if (n < 26)
		sprintf(b, "%c", 'a' + i);
	else
		sprintf(b, "x%u", i);
	return b;
}

void
gen(uint n, uint *a)
{
	char b[128];
	uint i, j, l;

	printf("\\begin{tabular}{");
	for (i = 0; i < n; i++)
		printf("c");
	printf("|c}\n");

	for (i = 0; i < n; i++)
		printf("%s & ", mkname(b, i, n));
	printf("F \\\\\n");

	printf("\\hline\n");

	l = 1u << n;
	for (i = 0; i < l; i++) {
		for (j = n; j > 0; j--)
			printf("%u & ", !!(i & (1u << (j - 1))));
		printf("%u \\\\\n", a[i]);
	}

	printf("\\end{tabular}\n");
}

int
main(void)
{
	uint a1[] = {0, 0, 0, 1};

	gen(2, a1);
	return 0;
}
