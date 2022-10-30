/*

Task

Given a string s, output a truthy value if the ASCII code of each letter is divisible by the length of s, and a falsey otherwise.

Input/Output

Input is a nonempty string containing only ASCII [32-126].
Output is a standard truthy/falsey value.
Note that you can switch the values, for example returning 0/False if divisible and vice versa

Test cases
Input         Output

Hello         False       (72 101 108 108 111), 5
lol           True        (108 111 108), 3
Codegolf      False       (67 111 100 101 103 111 108 102), 8
A             True        (65), 1
nope          False       (110 111 112 101),4
8  8          True        (56 32 32 56), 4

*/

#include <assert.h>
#include <stdbool.h>
#include <string.h>

bool
divisible(const char *s)
{
	size_t i, n;

	n = strlen(s);
	for (i = 0; s[i]; i++) {
		if (s[i] % n)
			return false;
	}
	return true;
}

int
main(void)
{
	assert(divisible("Hello") == false);
	assert(divisible("lol") == true);
	assert(divisible("Codegolf") == false);
	assert(divisible("A") == true);
	assert(divisible("nope") == false);
	assert(divisible("8  8") == true);

	return 0;
}
