/*

The scenario
Lately you have been noticing some strange behavior with your favorite text editor.
At first it seemed that it was ignoring random characters in your code when writing to disk.
After a while you noticed a pattern; characters with odd ASCII values were being ignored.
Under further inspection you discovered that you can only write to files properly if every eighth bit is zero.
Now you need to know if your valuable files have been affected by this strange bug.

The task
You must write a complete program that determines if a file contains any odd bytes (demonstrating it is uncorrupted).
But because of your text editor you cannot write any odd bytes in your source code.
You may assume any pre-existing encoding for input, however you must still check every individual byte, not just characters.

Input
Your program will take the contents of or the path to a file from either stdin or command line.

Output
Your program will output to stdout either a truthy value if the given file contains an odd byte or a falsy if every eighth bit is zero.

Criteria
This is code golf, shortest program that completes the task wins. To be a valid submission every eighth bit in the files source code must be a zero. I would recommend including a copy of your source code's binaries in your submission.

Standard loopholes apply.

Test Cases
(In ASCII encoding) Input:

"$&(*,.02468:<>@BDFHJLNPRTVXZ\^`bdfhjlnprtvxz|~

Output:
falsy

Input:
!#%')+-/13579;=?ACEGIKMOQSUWY[]_acegikmoqsuwy{}

Output:
truthy

Input:
LOREMIPSVMDOLORSITAMETCONSECTETVRADIPISCINGELITSEDDOEIVSMODTEMPORINCIDIDVNTVTLABOREETDOLOREMAGNAALIQVA
VTENIMADMINIMVENIAMQVISNOSTRVDEXERCITATIONVLLAMCOLABORISNISIVTALIQVIPEXEACOMMODOCONSEQVAT
DVISAVTEIRVREDOLORINREPREHENDERITINVOLVPTATEVELITESSECILLVMDOLOREEVFVGIATNVLLAPARIATVR
EXCEPTEVRSINTOCCAECATCVPIDATATNONPROIDENTSVNTINCVLPAQVIOFFICIADESERVNTMOLLITANIMIDESTLABORVM

Output:
truthy
Tips
Choose language wisely this challenge might not be possible in every language

The Unix command xxd -b <file name> will print the binaries of a file to the console (along with some extra formatting stuff)

You may use other encodings other than ASCII such as UTF-8 as long as all other rules are followed

*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <errno.h>

int
odd(FILE *fp)
{
	int c;

	while ((c = fgetc(fp)) != EOF) {
		if (c >= 0x80)
			return 1;
	}
	return 0;
}

int
main(int argc, char *argv[])
{
	FILE *fp;

	fp = stdin;
	if (argc >= 2)
		fp = fopen(argv[1], "rb");

	if (!fp) {
		fprintf(stderr, "Failed to open file: %s\n", strerror(errno));
		return 1;
	}

	printf("Odd File: %s\n", (odd(fp)) ? "true" : "false");
	fclose(fp);

	return 0;
}
