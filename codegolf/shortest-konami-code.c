/*

The Problem

You must write a program that, when the Konami Code is typed in during runtime, prints the string "+30 lives" and sounds a noise of your choice from the computer's speaker.
Definition

The "Konami Code" is defined as UUDDLRLRBA followed by pressing the enter key.
The Rules

    You may choose to use the up arrow for U, down for D, left for L, and right for R, as long as your code is consistent with either arrows or letters.

    Your input may be accepted from a controller or a keyboard, but does not need to support both.

    Existing answers may continue to use BABA instead of BA, but may also shorten it if they wish to do so. Future answers should all use BA for consistency.

    Empty input doesn't need to be supported.

*/

#include <stdio.h>
#include <string.h>

int
main(void)
{
	char b[128];

	while (fgets(b, sizeof(b), stdin)) {
		if (!strcmp(b, "UUDDLRLRBA\n")) {
			printf("\a+30 lives\n");
			break;
		}
	}
	return 0;
}
