/*

Write a program to take a character (C)

as input and check whether the given character is a vowel or a consonant.

NOTE:
Vowels are 'A', 'E', 'I', 'O', 'U'. Rest all alphabets are called consonants.

*/
#include <stdio.h>
#include <ctype.h>

const char *
classify(int c)
{
	switch (toupper(c)) {
	case 'A':
	case 'E':
	case 'I':
	case 'O':
	case 'U':
		return "Vowel";
	}
	return "Consonant";
}

int
main(void)
{
	int i;
	for (i = 'A'; i <= 'Z'; i++)
		printf("%c: %s\n", i, classify(i));
	return 0;
}
