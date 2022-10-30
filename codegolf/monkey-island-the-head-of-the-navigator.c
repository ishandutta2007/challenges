/*

Warning: This challenge contains some mild spoilers for The Secret of Monkey Island.

Towards the end of the game, you're being led through the catacombs by a magically preserved head of a navigator:

enter image description here

You need its eyeball necklace, but the Head is reluctant to give it to you. One way to get it is just to keep begging:

Guybrush: May I please have that necklace?
Head: No, but thanks for asking so politely.
Guybrush: Oh come on, pleeeeease?
Head: You can beg all you want, but you can't have it.
Guybrush: Pretty please?
Head: You can beg all you want, but you can't have it.
Guybrush: Pretty PRETTY please?
Head: You can beg all you want, but you can't have it.
Guybrush: Pretty please with sugar on top?
Head: Oh, all right, you big baby. You can have it. Hey, what good's a necklace if you don't have shoulders?

The Challenge
Write a full program which prints the above dialogue.
The catch is that each time the program is called it should only print two lines (one pleading by Guybrush and the Head's response).
E.g. if your submission is written in Python, usage should look like this:

$> python please.py
Guybrush: May I please have that necklace?
Head: No, but thanks for asking so politely.
$> python please.py
Guybrush: Oh come on, pleeeeease?
Head: You can beg all you want, but you can't have it.
$> python please.py
Guybrush: Pretty please?
Head: You can beg all you want, but you can't have it.
$> python please.py
Guybrush: Pretty PRETTY please?
Head: You can beg all you want, but you can't have it.
$> python please.py
Guybrush: Pretty please with sugar on top?
Head: Oh, all right, you big baby. You can have it. Hey, what good's a necklace if you don't have shoulders?
Invoking the program more than 5 times may result in undefined behaviour, so you could either loop, keep printing the last two lines or the program could even be broken after the 5th invocation.

You may write to a file in the working directory, or you can modify the source code of the program itself to keep track of invocations.
In the latter case, your program must not depend its own filename. (In the former case, you can assume that your program's file name will not clash with any file names your program depends on.)

You must not assume a REPL-like environment or that any data is kept in RAM between invocations. E.g. if you answer in Mathematica, you have to assume that I quit the kernel between invocations.

This is code golf, the shortest answer (in bytes) wins. If your program depends on any additional files to exist before the first invocation, add its name and contents to your byte count.

*/

#include <stdio.h>

#define nelem(x) (sizeof(x) / sizeof(x[0]))

unsigned
get(void)
{
	FILE *fp;
	unsigned i;

	i = 0;
	fp = fopen("monkey-island-choice.txt", "rb");
	if (fp) {
		fscanf(fp, "%u", &i);
		fclose(fp);
	}
	return i;
}

int
store(unsigned i)
{
	FILE *fp;

	fp = fopen("monkey-island-choice.txt", "wb");
	if (!fp)
		return -1;

	fprintf(fp, "%u\n", i);
	fclose(fp);
	return 0;
}

void
please(void)
{
	static const char *lines[] = {
	    "Guybrush: May I please have that necklace?",
	    "Head: No, but thanks for asking so politely.",

	    "Guybrush: Oh come on, pleeeeease?",
	    "Head: You can beg all you want, but you can't have it.",

	    "Guybrush: Pretty please?",
	    "Head: You can beg all you want, but you can't have it.",

	    "Guybrush: Pretty PRETTY please?",
	    "Head: You can beg all you want, but you can't have it.",

	    "Guybrush: Pretty please with sugar on top?",
	    "Head: Oh, all right, you big baby. You can have it. Hey, what good's a necklace if you don't have shoulders?",
	};

	unsigned i, l;

	l = get();
	for (i = 0; i < 2; i++)
		printf("%s\n", lines[(i + l) % nelem(lines)]);
	store((i + l) % nelem(lines));
}

int
main(void)
{
	please();
	return 0;
}
