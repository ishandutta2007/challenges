/*

This challenge's concept is pretty simple. All you have to do is write a program that will compile as both valid C and valid C++! Well, there are some catches.
The program must behave differently when compiled in each language. The program must have different output for each language in order to be considered "behaving differently".

Rules
The program must be both valid C and C++
The program must have different outputs based on the language it was compiled in.
#ifdef __cplusplus or other "easy" preprocessor tricks are discouraged! (Other preprocessor operations are perfectly fine, though.)
Try not to make it look completely obvious that the program does something different.
This is a popularity-contest, so whoever has the most interesting and surprising solution wins. Have fun!

Example:
I created my own program to see if this was even possible to do with out #ifdef tricks:

#include <stdio.h>
#include <string.h>

char *m="C++ rules!";

int t[11]={0,0,0,0,1,-1,-3,9,-8,82,0};

char tr(char c,int i)
{
    return c+((sizeof('!')+1)&1)*t[i];
}

int main()
{
    int i = 0;
    for(;i<strlen(m);i++)
    {
        printf("%c",tr(m[i],i));
    }
    printf("\n");
    return 0;
}

This program outputs C++ rules! when compiled in C++ and C++ stinks when compiled in C.

Explanation:

What causes the difference between languages is the tr() function. It takes advantage of one of the differences between C and C++, specifically, how char literals are treated.
In C, they are treated as integers, so sizeof('!') returns 4, as opposed to 1 in C++. The ((...+1)&1) part is just part of a simple bitwise operation that will return 1 if sizeof('!') returns 4, and 0 if it returns 1.
That resulting number is multiplied by the ints in array t and then that product is finally added to the specific character being transformed. In C++ the product will always be zero, so the string C++ rules! remains unchanged.
In C, the product will always be the value in t, and so the string changes to C++ stinks.

*/

#include <stdio.h>

#ifdef __cplusplus
#define STRING "C++"
#else
#define STRING "C"
#endif

int main()
{
	printf("%s\n", STRING);
	return 0;
}
