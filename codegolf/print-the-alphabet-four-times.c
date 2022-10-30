/*

The program must print the alphabet four times: first in the normal alphabetical order, second in the order of a qwerty keyboard, third in the order of a dvorak keyboard, and lastly in reverse alphabetical order. The output should resemble this:

abcdefghijklmnopqrstuvwxyz
qwertyuiopasdfghjklzxcvbnm
pyfgcrlaoeuidhtnsqjkxbmwvz
zyxwvutsrqponmlkjihgfedcba

The output is not case-sensitive, and you can add or omit newlines or spaces wherever you wish.

The catch: the program must be less than 104 characters, or, in other words, smaller than the length of the alphabet times four.

I will accept the answer with the shortest code, unless I see something really clever or interesting that I am more impressed with.

EDIT: I will accept the shortest answer on Wednesday, 4/27/2011.

EDIT2: And the winner is (as usual) Golfscript in 64 chars! Second place, which is behind by only three chars, is also in Golfscript, with 67 chars, followed by Bash in third place with 72 chars.

But there were a few others I wanted to mention, such as this one, which, depending on your definition, only used 52 "characters", and this one where he wrote it in a language he created.

There were a few people who broke an unwritten rule and did not qualify, but I will mention them just for their way of thinking without the box.

*/

#include <stdio.h>

void
kbl(void)
{
	printf("abcdefghijklmnopqrstuvwxyz\n");
	printf("qwertyuiopasdfghjklzxcvbnm\n");
	printf("pyfgcrlaoeuidhtnsqjkxbmwvz\n");
	printf("zyxwvutsrqponmlkjihgfedcba\n");
}

int
main(void)
{
	kbl();
	return 0;
}
