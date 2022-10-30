/*

I was expecting to post something more complex as my first puzzle in PCG, but a particular, uh... homework question on Stack Overflow inspired me to post this. They want to:

    print the following pattern for any given word that contains odd number of letters:

    P           M
      R       A   
        O   R    
          G       
        O   R      
      R       A   
    P           M 

    c++

    Notice that letters are a knight's move apart in the pattern you need to print. So, every other column is empty. -- (Thanks xnor for pointing this out.)

Rules

    Using C++ is prohibited. As I may link this question there.
    You may use stdout, or any means of quickly outputting a string (e.g. alert() in JavaScript).
    As always, shortest code wins.

*/

#include <stdio.h>
#include <string.h>

void
charcross(const char *s)
{
	size_t i, j, k, l, n;

	n = strlen(s);
	for (i = 0; i < n; i++) {
		k = 2 * i;
		l = 2 * (n - i - 1);
		for (j = 0; j < 2 * n - 1; j++) {
			if (j == k)
				printf("%c", s[i]);
			else if (j == l)
				printf("%c", s[n - i - 1]);
			else
				printf(" ");
		}
		printf("\n");
	}
	printf("\n");
}

int
main(void)
{
	charcross("PROGRAM");
	charcross("CODE-GOLF");
	charcross("uhm");

	return 0;
}
