/*

Given no input, your task is to generate the following:

a
 b
  c
   d
    e
     f
      g
       h
        i
         j
          k
           l
            m
             n
              o
               p
                q
                 r
                  s
                   t
                    u
                     v
                      w
                       x
                        y
                         z

Nonvisually, your task is to generate each letter in the alphabet, with spaces before it equal to its position in the alphabet minus one.

If you print this, it must appear like the above. Extraneous whitespace that does not affect appearance, as well as a trailing newline, is allowed. You can use all lowercase, or all uppercase.

You may also return this from a function as per usual rules, either as a string with newlines, or a list of strings.

This is code-golf, so shortest answer in bytes wins!

*/

#include <stdio.h>

void
diagonal(void)
{
	int i, j;

	for (i = 0; i < 26; i++) {
		for (j = 0; j < i; j++)
			printf(" ");
		printf("%c\n", 'a' + i);
	}
}

int
main(void)
{
	diagonal();
	return 0;
}
