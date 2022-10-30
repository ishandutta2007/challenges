/*

Challenge
Print or return the Stack Exchange favicon, as provided below:

 ___________________
/                   \
---------------------
|                   |
---------------------
|                   |
---------------------
\__________    _____/
           |  /
           | /
           |/
This is code-golf, so the shortest answer in each language wins.

*/

#include <stdio.h>

int
main(void)
{
	static const char icon[] =
	    " ___________________\n"
	    "/                   \\\n"
	    "---------------------\n"
	    "|                   |\n"
	    "---------------------\n"
	    "|                   |\n"
	    "---------------------\n"
	    "\\__________    _____/\n"
	    "           |  /\n"
	    "           | /\n"
	    "           |/\n";

	printf("%s", icon);
	return 0;
}
