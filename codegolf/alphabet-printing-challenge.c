/*

Challenge
Your task is to write as many programs/snippets as you can, where each one outputs/prints/ returns an alphabet.
The first program must output the letter A or a, the second one B or b and so on.

You can not reuse any characters between the programs (Except Whitespace, it can be reused through snippets).
So, if the first program is: 0==0, then you may not use the characters 0 and = again in any of the other programs.
Note: It's allowed to use the same character many times in one program.

Scoring:
The winner will be the submission that can print alphabets up to the highest, if anyone can print upto Z or z, it will receive an extra +50 bounty from me.
In case there's a tie, the winner will be the submission that used the fewest number of bytes in total.

Rules:
You can only use a single language for all alphabets, polygots not supported
Snippets are allowed! But quine snippets like A which prints A are not allowed.
leading and trailing spaces are not allowed. But newlines are allowed
You may disregard STDERR, as long as the correct output is returned to STDOUT
You cannot choose to output the letters to STDERR.
Letters are case sensitive a != A.
The programs/snippets must be independent
Whitespace can be reused
Output is case-insensitive, you may choose to either output a or A but not both!
You can't use a function, that does not print anything, such as f(){print a} will print a when it is called, but if you don't call the function, then that snippet/program is invalid.
Minimum submission length should be 1 byte, but again quines are not allowed

*/

#include <stdio.h>

void
gen(FILE *fp, int c)
{
	fprintf(fp, "#include <stdio.h>\n");
	fprintf(fp, "int main(void) { printf(\"%%c\\n\", '%c'); }\n", c);
	fprintf(fp, "\n");
}

int
main(void)
{
	char name[32];
	FILE *fp;
	int i;

	for (i = 'a'; i <= 'z'; i++) {
		snprintf(name, sizeof(name), "%c.c", i);
		fp = fopen(name, "wb");
		if (fp) {
			gen(fp, i);
			fclose(fp);
		}
	}

	return 0;
}
