/*

--- Day 2: Password Philosophy ---
Your flight departs in a few days from the coastal airport; the easiest way down to the coast from here is via toboggan.

The shopkeeper at the North Pole Toboggan Rental Shop is having a bad day. "Something's wrong with our computers; we can't log in!" You ask if you can take a look.

Their password database seems to be a little corrupted: some of the passwords wouldn't have been allowed by the Official Toboggan Corporate Policy that was in effect when they were chosen.

To try to debug the problem, they have created a list (your puzzle input) of passwords (according to the corrupted database) and the corporate policy when that password was set.

For example, suppose you have the following list:

1-3 a: abcde
1-3 b: cdefg
2-9 c: ccccccccc
Each line gives the password policy and then the password. The password policy indicates the lowest and highest number of times a given letter must appear for the password to be valid.
For example, 1-3 a means that the password must contain a at least 1 time and at most 3 times.

In the above example, 2 passwords are valid. The middle password, cdefg, is not; it contains no instances of b, but needs at least 1. The first and third passwords are valid: they contain one a or nine c, both within the limits of their respective policies.

How many passwords are valid according to their policies?

--- Part Two ---
While it appears you validated the passwords correctly, they don't seem to be what the Official Toboggan Corporate Authentication System is expecting.

The shopkeeper suddenly realizes that he just accidentally explained the password policy rules from his old job at the sled rental place down the street! The Official Toboggan Corporate Policy actually works a little differently.

Each policy actually describes two positions in the password, where 1 means the first character, 2 means the second character, and so on.
(Be careful; Toboggan Corporate Policies have no concept of "index zero"!) Exactly one of these positions must contain the given letter. Other occurrences of the letter are irrelevant for the purposes of policy enforcement.

Given the same example list from above:

1-3 a: abcde is valid: position 1 contains a and position 3 does not.
1-3 b: cdefg is invalid: neither position 1 nor position 3 contains b.
2-9 c: ccccccccc is invalid: both position 2 and position 9 contain c.
How many passwords are valid according to the new interpretation of the policies?

*/

#include <stdio.h>
#include <string.h>

typedef unsigned uint;

int
valid1(const char *s, uint i, uint j, int c)
{
	size_t h[256];
	size_t n;

	memset(h, 0, sizeof(h));
	for (n = 0; s[n]; n++)
		h[s[n] & 0xff]++;

	return i <= h[c] && h[c] <= j;
}

int
valid2(const char *s, uint i, uint j, int c)
{
	size_t n;
	int r;

	n = strlen(s);
	if (i > n || j > n)
		return 0;

	r = (s[i - 1] == c);
	r += (s[j - 1] == c);
	return r == 1;
}

int
count(const char *name, int (*valid)(const char *, uint, uint, int))
{
	FILE *fp;
	char b[128], s[64];
	char c;
	uint i, j;
	int r;

	fp = fopen(name, "rb");
	if (!fp)
		return -1;

	r = 0;
	while (fgets(b, sizeof(b), fp)) {
		if (sscanf(b, "%u-%u %c: %63s", &i, &j, &c, s) == 4)
			r += valid(s, i, j, c & 0xff);
	}

	fclose(fp);
	return r;
}

int
main(void)
{
	printf("%d\n", count("2.txt", valid1));
	printf("%d\n", count("2.txt", valid2));

	return 0;
}
