/*

This is similar to this question. However, I have a different goal in mind: Reduce the wordlist to words that could appear. The easy part is to delete hyphens and similar.

The hard part, however: Remove words containing more than seven letters.

So, the problem:
Given a set of words containing only lowercase (or uppercase) ASCII letters, remove the words containing eight or more different letters.

Any input and output format is acceptable.

Standard loophole rules apply.

Shortest byte count wins.

Clever solutions are better, and faster is better as well.

My solution (implementing a quite clever O(n) algorithm, noncompetitive ref implementation):

#include <stdio.h>
#include <stdint.h>

int main(void) {
  char str[1024];
  while(scanf("%s\n", str) == 1) {
    uint32_t st = 0;
    int s = 0;
    for(char *p = str; *p && s <= 7; p++) {
      s += ~st >> (*p - 'a') & 1;
      st |= 1 << (*p - 'a');
    }
    if(s <= 7)
      printf("%s\n", str);
  }
}

*/

#include <stdio.h>

int
fewchars(const char *b)
{
	const char *p;
	long c, s, t;

	s = t = 0;
	for (p = b; *p && s <= 7; p++) {
		c = *p & 0xff;
		if (!('a' <= c && c <= 'z'))
			continue;
		c -= 'a';

		s += (~t >> c) & 1;
		t |= 1 << c;
	}
	return s <= 7;
}

void
filter(FILE *in, FILE *out)
{
	char b[1024];

	while (fgets(b, sizeof(b), in)) {
		if (fewchars(b))
			fprintf(out, "%s", b);
	}
}

int
main(void)
{
	filter(stdin, stdout);
	return 0;
}
