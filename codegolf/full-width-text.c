/*

Full width text is text that has a space after every character, including the last one. For instance, the first sentence of this question becomes:

F u l l   w i d t h   t e x t   i s   t e x t   t h a t   h a s   a   s p a c e   a f t e r   e v e r y   c h a r a c t e r ,   i n c l u d i n g   t h e   l a s t   o n e . 

Write a program that takes a line in text from standard input and outputs it as full-width text to standard out. 

*/

#include <stdio.h>

void
fullwidth(FILE *fp)
{
	int ch;

	while ((ch = fgetc(fp)) != EOF) {
		printf("%c", ch);
		if (ch != '\r' && ch != '\n')
			printf(" ");
	}
}

int
main(void)
{
	fullwidth(stdin);
	return 0;
}
