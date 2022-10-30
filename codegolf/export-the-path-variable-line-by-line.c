/*

Inspired by this question on AskUbuntu.

Your job is extremely simple. Take the PATH environment variable (echo $PATH) and export it such that each entry (separated by the : character) is on its own line.

For example, if the PATH is /bin:/usr/bin:/usr/local/bin, your program should output:

/bin
/usr/bin
/usr/local/bin

Your program may not return a leading newline, but it may return a single trailing newline.
You do not need to check if the PATH is right, or that the directory exists. Your program should take no input, meaning that your program is responsible for getting the PATH itself.
You may safely assume that objects in the PATH do not contain : or newlines. However, spaces are fair game.

Reference implementations are present in the answers to the question above.

Rules
This is (obviously) code-golf, so the shortest answer will win the prized green checkmark.
The accepted answer will be tested to make sure it's actually legit.
Both Windows and *nix entries are accepted.
However, if you don't explicitly specify Windows, I will try running it in Linux and fail. (If it's obvious (hi, Batch!), you don't need to specify explicitly.)
Only have one solution per answer. If you have both a Windows and *nix version, I will count the shorter one.
If two answers have the same length, I will give priority to the one with the higher vote total.
If they have the same vote total, I will count the older one. If the time posted is the same, I will choose the one that executes faster. If they execute in the same amount of time, I don't know.

*/

#include <stdio.h>
#include <stdlib.h>

void
env(const char *name, char sep)
{
	const char *s;

	s = getenv(name);
	if (!s)
		return;

	while (*s) {
		while (*s != sep && *s)
			printf("%c", *s++);

		if (*s == sep)
			s++;

		printf("\n");
	}
}

int
main(void)
{
	env("PATH", ':');

	return 0;
}
