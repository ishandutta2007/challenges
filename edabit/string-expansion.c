/*

Create a function that takes a string txt and expands it as per the following rules:

    The numeric values represent the occurrence of each letter preceding that numeric value.

string_expansion("3M2u5b2a1s1h2i1r") ➞ "MMMuubbbbbaashiir"

    The first occurrence of a numeric value should be the number of times each character behind it is repeated, until the next numeric value appears.

string_expansion("3Mat")➞ "MMMaaattt"      # correct

string_expansion("3Mat") ➞ "MMMat"          # wrong
string_expansion("3Mat") ➞ "MatMatMat"      # wrong

    If there are consecutive numeric characters, ignore them all except last one.

string_expansion("3M123u42b12a") ➞ "MMMuuubbaa"

    If there are two consecutive alphabetic characters then the string will remain unchanged.

string_expansion("airforce") ➞ "airforce"

    Empty strings should return an empty string.

string_expansion("") ➞ ""

Notes

N/A

*/

#include <assert.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>

char *
strexpand(const char *s, char *b)
{
	size_t i, j, k, l;

	l = 1;
	for (i = j = 0; s[i]; i++) {
		while (isdigit(s[i])) {
			l = s[i] - '0';
			if (s[i + 1])
				i++;
			else {
				l = 0;
				break;
			}
		}

		for (k = 0; k < l; k++)
			b[j++] = s[i];
	}

	b[j] = '\0';
	return b;
}

void
test(const char *s, const char *r)
{
	char b[128];

	strexpand(s, b);
	printf("%s\n", b);
	assert(!strcmp(b, r));
}

int
main(void)
{
	test("3M2u5b2a1s1h2i1r", "MMMuubbbbbaashiir");
	test("3Mat", "MMMaaattt");
	test("3M123u42b12a", "MMMuuubbaa");
	test("3n6s7f3n", "nnnssssssfffffffnnn");
	test("0d4n8d2b", "nnnnddddddddbb");
	test("0c3b1n7m", "bbbnmmmmmmm");
	test("7m3j4ik2a", "mmmmmmmjjjiiiikkkkaa");
	test("3A5m3B3Y", "AAAmmmmmBBBYYY");
	test("5M0L8P1", "MMMMMPPPPPPPP");
	test("2B", "BB");
	test("7M1n3K", "MMMMMMMnKKK");
	test("A4g1b4d", "Aggggbdddd");
	test("111111", "");
	test("4d324n2", "ddddnnnn");
	test("5919nf3u", "nnnnnnnnnfffffffffuuu");
	test("2n1k523n4i", "nnknnniiii");
	test("6o23M32d", "ooooooMMMdd");
	test("1B44n3r", "Bnnnnrrr");
	test("M21d1r32", "Mdr");
	test("23M31r2r2", "MMMrrr");
	test("8494mM25K2A", "mmmmMMMMKKKKKAA");
	test("4A46D6B3C", "AAAADDDDDDBBBBBBCCC");
	test("23D42B3A", "DDDBBAAA");
	test("143D36C1A", "DDDCCCCCCA");
	test("asdf", "asdf");
	test("23jbjl1eb", "jjjbbbjjjllleb");
	test("43ibadsr3", "iiibbbaaadddsssrrr");
	test("123p9cdbjs", "pppcccccccccdddddddddbbbbbbbbbjjjjjjjjjsssssssss");
	test("2309ew7eh", "eeeeeeeeewwwwwwwwweeeeeeehhhhhhh");
	test("312987rfebd", "rrrrrrrfffffffeeeeeeebbbbbbbddddddd");
	test("126cgec", "ccccccggggggeeeeeecccccc");
	test("1chwq3rfb", "chwqrrrfffbbb");
	test("389fg21c", "fffffffffgggggggggc");
	test("239vbsac", "vvvvvvvvvbbbbbbbbbsssssssssaaaaaaaaaccccccccc");
	test("davhb327vuc", "davhbvvvvvvvuuuuuuuccccccc");
	test("cvyb239bved2dv", "cvybbbbbbbbbbvvvvvvvvveeeeeeeeedddddddddddvv");
	test("", "");

	return 0;
}
