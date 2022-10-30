/*

Your task is simple, just remove the odd indices and double the even indices

Example
the input is Hello, World! and we get indices

H e l l o , _ W o r  l  d  !
1 2 3 4 5 6 7 8 9 10 11 12 13
and remove the odd indices

el,Wrd
Double!

eell,,WWrrdd
and you are done

1-Indexing

Test cases
abcdef => bbddff
umbrella => mmrrllaa
looooooooong text => ooooooooooggttxx
abc => bb
xkcd => kkdd
Hello, World! => eell,,WWrrdd
D => <empty>
KK => KK
Hi => ii
odd_length! => dd__eegghh
<empty> => <empty>
The input can be list if you want.

*/

#include <assert.h>
#include <stdio.h>
#include <string.h>

char *
rode(const char *s, char *b)
{
	size_t i, j;

	for (i = j = 0; s[i]; i++) {
		if (i & 1) {
			b[j++] = s[i];
			b[j++] = s[i];
		}
	}
	b[j] = '\0';

	return b;
}

void
test(const char *s, const char *r)
{
	char b[128];

	rode(s, b);
	printf("%s\n", b);
	assert(!strcmp(b, r));
}

int
main(void)
{
	test("abcdef", "bbddff");
	test("umbrella", "mmrrllaa");
	test("looooooooong text", "ooooooooooggttxx");
	test("abc", "bb");
	test("xkcd", "kkdd");
	test("Hello, World!", "eell,,WWrrdd");
	test("D", "");
	test("KK", "KK");
	test("Hi", "ii");
	test("odd_length!", "dd__eegghh");
	test("", "");

	return 0;
}
