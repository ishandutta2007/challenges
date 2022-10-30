/*

Input:

Two decimal integers m and n that respectively give the number of rows and columns of the table. m and n are greater than or equal to 1.
Output:

A table in HTML that has m rows and n columns.

The table should be displayable by a modern browser of your choice. Most browsers will display everything properly even if tags are not closed. Proper indentation and spacing is optional.

There should be at least one (non-whitespace) printable character in each cell.

Cells on the first line should use <th> tags while the ones on the following lines should use <td>tags.
Win condition :

This is code-golf so the shortest source-code for each language wins.
Input example :

2 3

Output example:

<table>
 <tr>
   <th>A</th>
   <th>A</th>
   <th>A</th>
 </tr>
 <tr>
   <td>A</td>
   <td>A</td>
   <td>A</td>
 </tr>
</table>

or : <table><tr><th>A<th>A<th>A<tr><td>A<td>A<td>A

*/

#include <stdio.h>

void
gen(int m, int n)
{
	int i, j;

	printf("<table>\n");
	for (i = 0; i < m; i++) {
		printf("\t<tr>\n");
		for (j = 0; j < n; j++)
			printf("\t\t<th>%d</th>\n", i * n + j);
		printf("\t</tr>\n");
	}
	printf("</table>\n");
}

int
main(void)
{
	gen(2, 3);
	return 0;
}
