/*

Inspired by a bug in a solution to this challenge, your challenge is to produce this exact text:

                         ZYXWVUTSRQPONMLKJIHGFEDCBA
                        YXWVUTSRQPONMLKJIHGFEDCBA
                       XWVUTSRQPONMLKJIHGFEDCBA
                      WVUTSRQPONMLKJIHGFEDCBA
                     VUTSRQPONMLKJIHGFEDCBA
                    UTSRQPONMLKJIHGFEDCBA
                   TSRQPONMLKJIHGFEDCBA
                  SRQPONMLKJIHGFEDCBA
                 RQPONMLKJIHGFEDCBA
                QPONMLKJIHGFEDCBA
               PONMLKJIHGFEDCBA
              ONMLKJIHGFEDCBA
             NMLKJIHGFEDCBA
            MLKJIHGFEDCBA
           LKJIHGFEDCBA
          KJIHGFEDCBA
         JIHGFEDCBA
        IHGFEDCBA
       HGFEDCBA
      GFEDCBA
     FEDCBA
    EDCBA
   DCBA
  CBA
 BA
A

    The first line will have 25 spaces, then the alphabet backwards starting from the 26th letter (ZYXWVUTSRQPONMLKJIHGFEDCBA), then a newline.
    The second line will have 24 spaces, then the alphabet backwards starting from the 25th letter (YXWVUTSRQPONMLKJIHGFEDCBA), then a newline.
    ...
    The last (26th) line will have no spaces, then the alphabet backwards starting from the 1st letter (A), then a newline.

Additional rules:

    Your program may use any allowed output methods.
    One trailing newline and/or one leading newline is allowed.
    There must be one newline between lines containing the letters, no more.
    The letters must be all uppercase.

As with code-golf, the shortest submission wins. Good luck!

*/

#include <stdio.h>

void
searchlight(void)
{
	int i, j;

	for (i = 'Z'; i >= 'A'; i--) {
		for (j = 0; j < i - 'A'; j++)
			printf(" ");
		for (j = i; j >= 'A'; j--)
			printf("%c", j);
		printf("\n");
	}
}

int
main(void)
{
	searchlight();
	return 0;
}
