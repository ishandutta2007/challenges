/*

Python is the fastest-growing major programming language today. It is the most wanted language for the third year in a row, meaning that developers who do not yet use it say they want to learn it.[1]

The reason for Python's popularity is its many versions.[citation needed] There are in fact 116 versions of Python, including two development versions.

Your task is to output/print a list of all the Python versions, in whatever order you like, and on whatever format you like. You may not use any built-in functions that have this information stored.

You are free to choose the output format, but each version must be identified on the standard way: 1.1, 2.3.0, 2.7.10 and so on.

The complete list2 of Python versions, comma-separated is shown below:

1.1, 1.2, 1.3, 1.4, 1.5, 1.5.1, 1.5.2, 1.6, 2.0, 2.0.1, 2.1, 2.1.1, 2.1.2, 2.1.3, 2.2, 2.2.1, 2.2.2, 2.2.3, 2.3, 2.3.1, 2.3.2, 2.3.3, 2.3.4, 2.3.5, 2.4, 2.4.1, 2.4.2, 2.4.3, 2.4.4, 2.5, 2.5.1, 2.5.2, 2.5.3, 2.5.4, 2.6, 2.6.1, 2.6.2, 2.6.3, 2.6.4, 2.6.5, 2.6.6, 2.6.7, 2.6.8, 2.6.9, 2.7, 2.7.1, 2.7.2, 2.7.3, 2.7.4, 2.7.5, 2.7.6, 2.7.7, 2.7.8, 2.7.9, 2.7.10, 2.7.11, 2.7.12, 2.7.13, 2.7.14, 2.7.15, 2.7.16, 3.0, 3.0.1, 3.1, 3.1.1, 3.1.2, 3.1.3, 3.1.4, 3.1.5, 3.2 , 3.2.1, 3.2.2, 3.2.3, 3.2.4, 3.2.5, 3.2.6, 3.3.0, 3.3.1, 3.3.2, 3.3.3, 3.3.4, 3.3.5, 3.3.6, 3.3.7, 3.4.0, 3.4.1, 3.4.2, 3.4.3, 3.4.4, 3.4.5, 3.4.6, 3.4.7, 3.4.8, 3.4.9, 3.4.10, 3.5.0, 3.5.1, 3.5.2, 3.5.3, 3.5.4, 3.5.5, 3.5.6, 3.5.7, 3.6.0, 3.6.1, 3.6.2, 3.6.3, 3.6.4, 3.6.5, 3.6.6, 3.6.7, 3.6.8, 3.7.0, 3.7.1, 3.7.2, 3.7.3
or by major versions:

1.1
1.2
1.3
1.4
1.5, 1.5.1, 1.5.2
1.6
2.0, 2.0.1
2.1, 2.1.1, 2.1.2, 2.1.3
2.2, 2.2.1, 2.2.2, 2.2.3
2.3, 2.3.1, 2.3.2, 2.3.3, 2.3.4, 2.3.5
2.4, 2.4.1, 2.4.2, 2.4.3, 2.4.4
2.5, 2.5.1, 2.5.2, 2.5.3, 2.5.4
2.6, 2.6.1, 2.6.2, 2.6.3, 2.6.4, 2.6.5, 2.6.6, 2.6.7, 2.6.8, 2.6.9
2.7, 2.7.1, 2.7.2, 2.7.3, 2.7.4, 2.7.5, 2.7.6, 2.7.7, 2.7.8, 2.7.9, 2.7.10, 2.7.11, 2.7.12, 2.7.13, 2.7.14, 2.7.15, 2.7.16
3.0, 3.0.1
3.1, 3.1.1, 3.1.2, 3.1.3, 3.1.4, 3.1.5
3.2, 3.2.1, 3.2.2, 3.2.3, 3.2.4, 3.2.5, 3.2.6
3.3.0, 3.3.1, 3.3.2, 3.3.3, 3.3.4, 3.3.5, 3.3.6, 3.3.7
3.4.0, 3.4.1, 3.4.2, 3.4.3, 3.4.4, 3.4.5, 3.4.6, 3.4.7, 3.4.8, 3.4.9, 3.4.10
3.5.0, 3.5.1, 3.5.2, 3.5.3, 3.5.4, 3.5.5, 3.5.6, 3.5.7
3.6.0, 3.6.1, 3.6.2, 3.6.3, 3.6.4, 3.6.5, 3.6.6, 3.6.7, 3.6.8
3.7.0, 3.7.1, 3.7.2, 3.7.3
The challenge is a fixed output challenge, and very close to a kolmogorov-challenge, except that the output format is optional.

2The list is taken from the official Python website, here and here. There are some versions that aren't included, such as 0.9.0 .. 0.9.9 and 1.5.1p1.
You must use the list above, even if you find versions that aren't included. I've decided to stick with the official lists, since otherwise someone would probably find a 2.1.0.1.2 version or something like that.

*/

#include <stdio.h>

int
main(void)
{
	static const char versions[] = "1.1, 1.2, 1.3, 1.4, 1.5, 1.5.1, 1.5.2, 1.6, 2.0, 2.0.1, 2.1, 2.1.1, 2.1.2, 2.1.3, 2.2, 2.2.1, 2.2.2, 2.2.3, 2.3, 2.3.1, 2.3.2, 2.3.3, 2.3.4, 2.3.5, 2.4, 2.4.1, 2.4.2, 2.4.3, 2.4.4, 2.5, 2.5.1, 2.5.2, 2.5.3, 2.5.4, 2.6, 2.6.1, 2.6.2, 2.6.3, 2.6.4, 2.6.5, 2.6.6, 2.6.7, 2.6.8, 2.6.9, 2.7, 2.7.1, 2.7.2, 2.7.3, 2.7.4, 2.7.5, 2.7.6, 2.7.7, 2.7.8, 2.7.9, 2.7.10, 2.7.11, 2.7.12, 2.7.13, 2.7.14, 2.7.15, 2.7.16, 3.0, 3.0.1, 3.1, 3.1.1, 3.1.2, 3.1.3, 3.1.4, 3.1.5, 3.2 , 3.2.1, 3.2.2, 3.2.3, 3.2.4, 3.2.5, 3.2.6, 3.3.0, 3.3.1, 3.3.2, 3.3.3, 3.3.4, 3.3.5, 3.3.6, 3.3.7, 3.4.0, 3.4.1, 3.4.2, 3.4.3, 3.4.4, 3.4.5, 3.4.6, 3.4.7, 3.4.8, 3.4.9, 3.4.10, 3.5.0, 3.5.1, 3.5.2, 3.5.3, 3.5.4, 3.5.5, 3.5.6, 3.5.7, 3.6.0, 3.6.1, 3.6.2, 3.6.3, 3.6.4, 3.6.5, 3.6.6, 3.6.7, 3.6.8, 3.7.0, 3.7.1, 3.7.2, 3.7.3";

	printf("%s\n", versions);
	return 0;
}
