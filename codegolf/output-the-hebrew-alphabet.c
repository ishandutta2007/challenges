/*

Your task is to print this exact text:

אבגדהוזחטיכךלמםנןסעפףצץקרשת

(You are allowed to print a trailing newline)

SHA256 hash of the UTF-8 encoding of the text:

0ab6f1e0bf216a0db52a4a5a247f95cba6f51496de7a24dfd01f3985dfcf6085

Base64 encoding:

15DXkdeS15PXlNeV15bXl9eY15nXm9ea15zXnted16DXn9eh16LXpNej16bXpden16jXqdeq

Rules

    You can't use a builtin outputting this text.
    Standard loopholes are disallowed.
    This is code-golf, so the shortest answer wins.

Good luck!

*/

#include <stdio.h>

int
main(void)
{
	static const char *txt = u8"אבגדהוזחטיכךלמםנןסעפףצץקרשת";

	printf("%s\n", txt);
	return 0;
}
