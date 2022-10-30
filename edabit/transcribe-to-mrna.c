/*

Transcribe the given DNA strand into corresponding mRNA - a type of RNA, that will be formed from DNA after transcription.
DNA has the bases A, T, G and C, while RNA has U in place of T and all of the other bases remains the same.
Examples

dnaToRna("ATTAGCGCGATATACGCGTAC") ➞ "UAAUCGCGCUAUAUGCGCAUG"

dnaToRna("CGATATA") ➞ "GCUAUAU"

dnaToRna("GTCATACGACGTA") ➞ "CAGUAUGCUGCAU"

Notes

    Transcription is the process of making complementary strand.
    A, T, G and C in DNA converts to U, A, C and G respectively in mRNA.

*/

#include <assert.h>
#include <stdio.h>
#include <string.h>

char *
dna2rna(char *s)
{
	static const char tab[256] = {
		['A'] = 'U',
		['T'] = 'A',
		['G'] = 'C',
		['C'] = 'G',
	};

	size_t i;
	char c;

	for (i = 0; s[i]; i++) {
		if ((c = tab[s[i] & 0xff]))
			s[i] = c;
	}
	return s;
}

int
main(void)
{
	char s1[] = "ATTAGCGCGATATACGCGTAC";
	char r1[] = "UAAUCGCGCUAUAUGCGCAUG";

	char s2[] = "CGATATA";
	char r2[] = "GCUAUAU";

	char s3[] = "GTCATACGACGTA";
	char r3[] = "CAGUAUGCUGCAU";

	char s4[] = "GCGTAC";
	char r4[] = "CGCAUG";

	char s5[] = "CAGTATGCTGCAT";
	char r5[] = "GUCAUACGACGUA";

	char s6[] = "GCAGCTACA";
	char r6[] = "CGUCGAUGU";

	assert(!strcmp(dna2rna(s1), r1));
	assert(!strcmp(dna2rna(s2), r2));
	assert(!strcmp(dna2rna(s3), r3));
	assert(!strcmp(dna2rna(s4), r4));
	assert(!strcmp(dna2rna(s5), r5));
	assert(!strcmp(dna2rna(s6), r6));

	return 0;
}
