/*

You are given a sequence of n characters S = s1, s2, ..., sn in such a way that for i ≠ j we have also si ≠ sj.
Your task is to substitute every si with si+1 for i in {1, 2, ... n-1} and sn with s1 in the given plain text.

Input
In the first line you are given one integer 2<=n<=26, and in the following line n characters.

In the third line you are given one integer 2<=m<=100, and in the following m lines you are given a plaintext to be encoded.
Plaintext contains only white spaces and small letters from the Latin alphabet. The whole plain text is at most 1000 characters long.

Output
Encoded text, as specified above.

Example 1
Input:
6
spojit
3
after this training
we will solve even
difficult and tricky problems easily

Output:
afser shtp sratntng
we wtll pjlve even
dtfftculs and srtcky orjblemp eaptly

Example 2
Input:
10
dontgiveup
3
after this training
we will solve even
difficult and tricky problems easily

Output:
afgur ghvs gravtvti
wu wvll snleu ueut
ovffvcplg ato grvcky drnblums uasvly

*/

#include <assert.h>
#include <stdio.h>
#include <string.h>

void
build(const char *t, int m[256])
{
	size_t i;
	int a, b;

	for (i = 0; i < 256; i++)
		m[i] = i;

	for (i = 0; t[i]; i++) {
		a = t[i] & 0xff;
		b = t[i + 1] & 0xff;
		if (!b)
			b = t[0] & 0xff;
		m[a] = b;
	}
}

char *
apply(const char *s, int m[256], char *b)
{
	size_t i;

	for (i = 0; s[i]; i++)
		b[i] = m[s[i] & 0xff];
	b[i] = '\0';
	return b;
}

char *
substitution(const char *t, const char *s, char *b)
{
	int m[256];

	build(t, m);
	return apply(s, m, b);
}

void
test(const char *t, const char *s, const char *r)
{
	char b[128];

	substitution(t, s, b);
	printf("%s\n", b);
	assert(!strcmp(b, r));
}

int
main(void)
{
	test("spojit", "after this training", "afser shtp sratntng");
	test("spojit", "we will solve even", "we wtll pjlve even");
	test("spojit", "difficult and tricky problems easily", "dtfftculs and srtcky orjblemp eaptly");

	test("dontgiveup", "after this training", "afgur ghvs gravtvti");
	test("dontgiveup", "we will solve even", "wu wvll snleu ueut");
	test("dontgiveup", "difficult and tricky problems easily", "ovffvcplg ato grvcky drnblums uasvly");

	return 0;
}
