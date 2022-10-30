/*

Jon Marius is the computer expert at his company and has now been tasked to find some software for erasing data properly.
It is very important that the data should not be recoverable afterwards, so it should be overwritten on the hard drive several times.
Unable to find any free program up to the task, Jon Marius decides to write such a program himself.
The user interface is simple, it only asks for the file to be destroyed and n, the number of times it should be overwritten.
This number can range from 1 (quick deletion) to 20 (maximum security).
Jon Marius processes the file bit by bit and does not consider writing a zero where there was already a zero as really overwriting. So for each of the n sweeps, he overwrites each zero with a one, and each one with a zero, respectively.

Jon Marius knows that independent testing is important, so he has asked you to write the verification routine. He will not listen to your objections to the algorithm so eventually you give in.

Input

The first line of the input contains a single integer 1≤N≤20.
The two following lines each contain a string containing only the characters 0 and 1.
The first of these lines represent the bits of the file before deletion and the second the bits on the same position on the hard drive after the file has been deleted.
The length of these strings are the same and between 1 and 1000 characters.

Output

Output a single line containing either the words “Deletion succeeded” if each bit is switched N times or “Deletion failed” if this is not the case.

*/

#include <assert.h>
#include <stdio.h>
#include <string.h>

const char *
erasure(const char *s, const char *t, unsigned n)
{
	size_t i;

	for (i = 0; s[i] && t[i]; i++) {
		if ((n & 1) && s[i] == t[i])
			return "Deletion failed";
		else if (!(n & 1) && s[i] != t[i])
			return "Deletion failed";
	}
	if (s[i] || t[i])
		return "Deletion failed";
	return "Deletion succeeded";
}

void
test(const char *s, const char *t, unsigned n, const char *r)
{
	const char *p;

	p = erasure(s, t, n);
	printf("%s\n", p);
	assert(!strcmp(p, r));
}

int
main(void)
{
	test("10001110101000001111010100001110", "01110001010111110000101011110001", 1, "Deletion succeeded");
	test("0001100011001010", "0001000011000100", 20, "Deletion failed");

	return 0;
}
