/*

Trump needs the wall constructed and you are going to do it! To most efficiently build his wall I have created a simple, repeatable pattern for you to use:

    __   __    
   |  |_|  |   
___|       |___
-   -   -   -  
 - - - - - - - 
- - - - - - - -
———————————————

Trump will tell you how many wall segments he needs and you will build them to look just like this.

Here is the pattern:

    __   __     <-- 4-2-3-2-4          ' _ _ '
   |  |_|  |    <-- 3-1-2-1-1-1-2-1-3  ' | |_| | '
___|       |___ <-- 3-1-7-1-3          '_| |_'
-   -   -   -   <-- 1-3-1-3-1-3-1-1    '- - - - '
 - - - - - - -  <-- 1-1-...-1-1        ' - -...- - '
- - - - - - - - <-- 1-1-...-1-1        '- - ... - -'
——————————————— <-- 15                 Unicode U+2014

Input will always be an integer >0.

Test cases:

1
    __   __    
   |  |_|  |   
___|       |___
-   -   -   -  
 - - - - - - - 
- - - - - - - -
———————————————

2
    __   __        __   __    
   |  |_|  |      |  |_|  |   
___|       |______|       |___
-   -   -   -  -   -   -   -  
 - - - - - - -  - - - - - - - 
- - - - - - - -- - - - - - - -
——————————————————————————————

5
    __   __        __   __        __   __        __   __        __   __
   |  |_|  |      |  |_|  |      |  |_|  |      |  |_|  |      |  |_|  |
___|       |______|       |______|       |______|       |______|       |___
-   -   -   -  -   -   -   -  -   -   -   -  -   -   -   -  -   -   -   -
 - - - - - - -  - - - - - - -  - - - - - - -  - - - - - - -  - - - - - - - 
- - - - - - - -- - - - - - - -- - - - - - - -- - - - - - - -- - - - - - - -
———————————————————————————————————————————————————————————————————————————

Since you need to do this fast, write the shortest program possible!

If it helps, I wrote the challenge first, title last ;)

*/

#include <stdio.h>

#define nelem(x) (sizeof(x) / sizeof(x[0]))

void
wall(unsigned n)
{
	static const char *tab[] = {
	    "    __   __    ",
	    "   |  |_|  |   ",
	    "___|       |___",
	    "-   -   -   -  ",
	    " - - - - - - - ",
	    "- - - - - - - -",
	    "———————————————",
	};

	unsigned i, j;

	printf("N=%u\n", n);
	for (i = 0; i < nelem(tab); i++) {
		for (j = 0; j < n; j++)
			printf("%s", tab[i]);
		printf("\n");
	}
	printf("\n");
}

int
main(void)
{
	wall(1);
	wall(2);
	wall(5);
	wall(10);

	return 0;
}
