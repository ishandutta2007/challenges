/*

Without taking any input, output this exact text:

                         A
                        B A
                       C B A
                      D C B A
                     E D C B A
                    F E D C B A
                   G F E D C B A
                  H G F E D C B A
                 I H G F E D C B A
                J I H G F E D C B A
               K J I H G F E D C B A
              L K J I H G F E D C B A
             M L K J I H G F E D C B A
            N M L K J I H G F E D C B A
           O N M L K J I H G F E D C B A
          P O N M L K J I H G F E D C B A
         Q P O N M L K J I H G F E D C B A
        R Q P O N M L K J I H G F E D C B A
       S R Q P O N M L K J I H G F E D C B A
      T S R Q P O N M L K J I H G F E D C B A
     U T S R Q P O N M L K J I H G F E D C B A
    V U T S R Q P O N M L K J I H G F E D C B A
   W V U T S R Q P O N M L K J I H G F E D C B A
  X W V U T S R Q P O N M L K J I H G F E D C B A
 Y X W V U T S R Q P O N M L K J I H G F E D C B A
Z Y X W V U T S R Q P O N M L K J I H G F E D C B A

Rules

    Output can be given by any convenient method.
    You can print it to STDOUT or return it as a function result.
    Either a full program or a function are acceptable.
    A single trailing newline is acceptable, but no other formatting changes are allowed.
    Capital letters are required.
    Standard loopholes are forbidden.
    This is code-golf so all usual golfing rules apply, and the shortest code (in bytes) wins.

*/

#include <stdio.h>

void
gen(void)
{
	int i, j;

	for (i = 'A'; i <= 'Z'; i++) {
		for (j = 'Z'; j > i; j--)
			printf(" ");
		for (j = i; j >= 'A'; j--) {
			printf("%c", j);
			if (j != 'A')
				printf(" ");
		}
		printf("\n");
	}
}

int
main(void)
{
	gen();
	return 0;
}
