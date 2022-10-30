/*

In information theory, a "prefix code" is a dictionary where none of the keys are a prefix of another.
In other words, this means that none of the strings starts with any of the other.

For example, {"9", "55"} is a prefix code, but {"5", "9", "55"} is not.

The biggest advantage of this, is that the encoded text can be written down with no separator between them, and it will still be uniquely decipherable.
This shows up in compression algorithms such as Huffman coding, which always generates the optimal prefix code.

Your task is simple: Given a list of strings, determine whether or not it is a valid prefix code.

Your input:

    Will be a list of strings in any reasonable format.

    Will only contain printable ASCII strings.

    Will not contain any empty strings.

Your output will be a truthy/falsey value: Truthy if it's a valid prefix code, and falsey if it isn't.

Here are some true test cases:

["Hello", "World"]                      
["Code", "Golf", "Is", "Cool"]
["1", "2", "3", "4", "5"]
["This", "test", "case", "is", "true"]          

["111", "010", "000", "1101", "1010", "1000", "0111", "0010", "1011", 
 "0110", "11001", "00110", "10011", "11000", "00111", "10010"]

Here are some false test cases:

["4", "42"]                             
["1", "2", "3", "34"]                   
["This", "test", "case", "is", "false", "t"]
["He", "said", "Hello"]
["0", "00", "00001"]
["Duplicate", "Duplicate", "Keys", "Keys"]

This is code-golf, so standard loopholes apply, and shortest answer in bytes wins.

*/

#include <assert.h>
#include <stdbool.h>
#include <stdio.h>
#include <string.h>

#define nelem(x) (sizeof(x) / sizeof(x[0]))

bool
prefix(const char **s, size_t n)
{
	size_t i, j, l;

	for (i = 0; i < n; i++) {
		l = strlen(s[i]);
		for (j = 0; j < n; j++) {
			if (i != j && !strncmp(s[i], s[j], l))
				return false;
		}
	}
	return true;
}

int
main(void)
{
	const char *s1[] = {"Hello", "World"};
	const char *s2[] = {"Code", "Golf", "Is", "Cool"};
	const char *s3[] = {"1", "2", "3", "4", "5"};
	const char *s4[] = {"This", "test", "case", "is", "true"};
	const char *s5[] = {"111", "010", "000", "1101", "1010", "1000", "0111", "0010", "1011", "0110", "11001", "00110", "10011", "11000", "00111", "10010"};

	const char *s6[] = {"4", "42"};
	const char *s7[] = {"1", "2", "3", "34"};
	const char *s8[] = {"This", "test", "case", "is", "false", "t"};
	const char *s9[] = {"He", "said", "Hello"};
	const char *s10[] = {"0", "00", "00001"};
	const char *s11[] = {"Duplicate", "Duplicate", "Keys", "Keys"};

	assert(prefix(s1, nelem(s1)) == true);
	assert(prefix(s2, nelem(s2)) == true);
	assert(prefix(s3, nelem(s3)) == true);
	assert(prefix(s4, nelem(s4)) == true);
	assert(prefix(s5, nelem(s5)) == true);

	assert(prefix(s6, nelem(s6)) == false);
	assert(prefix(s7, nelem(s7)) == false);
	assert(prefix(s8, nelem(s8)) == false);
	assert(prefix(s9, nelem(s9)) == false);
	assert(prefix(s10, nelem(s10)) == false);
	assert(prefix(s11, nelem(s11)) == false);

	return 0;
}
