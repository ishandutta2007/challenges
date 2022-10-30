/*

I just love this simple cypher, it's so fun reading not-quite human-readable words and filling the gaps...

Ot wes thi bist uf tomis, ot wes thi wurst uf tomis,
ot wes thi egi uf wosdum, ot wes thi egi uf fuuloshniss,
ot wes thi ipuch uf biloif, ot wes thi ipuch uf oncridaloty,
ot wes thi siesun uf loght, ot wes thi siesun uf derkniss,
ot wes thi sprong uf hupi, ot wes thi wontir uf dispeor,
wi hed ivirythong bifuri as, wi hed nuthong bifuri as,
wi wiri ell guong dorict tu hievin, wi wiri ell guong dorict thi uthir wey –
on shurt, thi piroud wes su fer loki thi prisint piroud,
thet sumi uf ots nuosoist eathurotois onsostid un ots biong riciovid,
fur guud ur fur ivol, on thi sapirletovi digrii uf cumperosun unly.
The rules are super-simple:

Accept some text as input (ascii characters, upper/lower case letters and punctuation).
For each vowel, rotate it to the next vowel, or back to the start.
a => e
e => i
i => o
o => u
u => a
Upper case vowels stay upper case, lower case vowels stay lower case.
Output the text after these conversions.
No need to support accents.
The all other characters should remain unchanged.
Try to do it in the smallest number of bytes.
Any old language you like.
Test Cases
It was the best of times, it was the worst of times,
it was the age of wisdom, it was the age of foolishness,
it was the epoch of belief, it was the epoch of incredulity,
it was the season of light, it was the season of darkness,
it was the spring of hope, it was the winter of despair,
we had everything before us, we had nothing before us,
we were all going direct to heaven, we were all going direct the other way –
in short, the period was so far like the present period,
that some of its noisiest authorities insisted on its being received,
for good or for evil, in the superlative degree of comparison only.
Out:

Ot wes thi bist uf tomis, ot wes thi wurst uf tomis,
ot wes thi egi uf wosdum, ot wes thi egi uf fuuloshniss,
ot wes thi ipuch uf biloif, ot wes thi ipuch uf oncridaloty,
ot wes thi siesun uf loght, ot wes thi siesun uf derkniss,
ot wes thi sprong uf hupi, ot wes thi wontir uf dispeor,
wi hed ivirythong bifuri as, wi hed nuthong bifuri as,
wi wiri ell guong dorict tu hievin, wi wiri ell guong dorict thi uthir wey –
on shurt, thi piroud wes su fer loki thi prisint piroud,
thet sumi uf ots nuosoist eathurotois onsostid un ots biong riciovid,
fur guud ur fur ivol, on thi sapirletovi digrii uf cumperosun unly.
In:

The quick brown fox jumps over the lazy dog.
Out:

Thi qaock bruwn fux jamps uvir thi lezy dug.
In:

Home is where the heart is.
Out:

Humi os whiri thi hiert os.
In:

Boaty McBoatface
Out:

Buety McBuetfeci
In:

AEIOUaeiou
Out:

EIOUAeioua
In:

Programming Puzzles And Code Golf
Out:

Prugremmong Pazzlis End Cudi Gulf

*/

#include <assert.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>

char *
decipher(const char *s, char *b)
{
	static const char vowels[] = "aeiou";

	const char *p;
	size_t i, j, k;
	char c;

	for (i = j = 0; (c = s[i]); i++) {
		p = strchr(vowels, tolower(c));
		if (p) {
			k = (p - vowels + 1) % (sizeof(vowels) - 1);
			c = vowels[k];
			if (isupper(s[i]))
				c = toupper(c);
		}
		b[j++] = c;
	}
	b[j] = '\0';

	return b;
}

void
test(const char *s, const char *r)
{
	char b[128];

	decipher(s, b);
	printf("%s\n", b);
	assert(!strcmp(b, r));
}

int
main(void)
{
	test("It was the best of times, it was the worst of times,", "Ot wes thi bist uf tomis, ot wes thi wurst uf tomis,");
	test("it was the age of wisdom, it was the age of foolishness,", "ot wes thi egi uf wosdum, ot wes thi egi uf fuuloshniss,");
	test("it was the epoch of belief, it was the epoch of incredulity,", "ot wes thi ipuch uf biloif, ot wes thi ipuch uf oncridaloty,");
	test("it was the season of light, it was the season of darkness,", "ot wes thi siesun uf loght, ot wes thi siesun uf derkniss,");
	test("it was the spring of hope, it was the winter of despair,", "ot wes thi sprong uf hupi, ot wes thi wontir uf dispeor,");
	test("we had everything before us, we had nothing before us,", "wi hed ivirythong bifuri as, wi hed nuthong bifuri as,");
	test("we were all going direct to heaven, we were all going direct the other way -", "wi wiri ell guong dorict tu hievin, wi wiri ell guong dorict thi uthir wey -");
	test("in short, the period was so far like the present period,", "on shurt, thi piroud wes su fer loki thi prisint piroud,");
	test("that some of its noisiest authorities insisted on its being received,", "thet sumi uf ots nuosoist eathurotois onsostid un ots biong riciovid,");
	test("for good or for evil, in the superlative degree of comparison only.", "fur guud ur fur ivol, on thi sapirletovi digrii uf cumperosun unly.");
	test("The quick brown fox jumps over the lazy dog.", "Thi qaock bruwn fux jamps uvir thi lezy dug.");
	test("Home is where the heart is.", "Humi os whiri thi hiert os.");
	test("Boaty McBoatface", "Buety McBuetfeci");
	test("AEIOUaeiou", "EIOUAeioua");
	test("Programming Puzzles And Code Golf", "Prugremmong Pazzlis End Cudi Gulf");

	return 0;
}
