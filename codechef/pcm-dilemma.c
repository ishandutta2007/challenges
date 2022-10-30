/*

After mastering the art of Coding , Chef has decided to master Physics(P) , Chemistry(C) and Maths(M).
Luckily he has three sisters where each sister is known to be master of exactly one subject.
Now you are given a string of size 3 where character at index 1 denotes the subject known to sister I, character at index 2 denotes the subject known to sister II and character at index 3 denotes the subject known to sister III.
You have to answer with either "YES" if chef can master "PCM" from his sisters or "NO" if he cannot.

Note
String will only contain characters from the set { P , C , M }.

Input

The first line of the input contains an integer T denoting the number of test cases. The description of T test cases follows.
First and only line of each testcase contains the string mentioned.

Output

For each test case, output a single line containing either "YES" or "NO".

Constraints
1 ≤ T ≤ 50
Length of string  = 3

*/

#include <assert.h>
#include <stdio.h>
#include <stdbool.h>

bool
learnable(const char *s)
{
	size_t i;
	int f;

	f = 0;
	for (i = 0; s[i]; i++) {
		switch (s[i]) {
		case 'P':
			f |= 1;
			break;
		case 'C':
			f |= 2;
			break;
		case 'M':
			f |= 4;
			break;
		}
	}
	return f == 7;
}

int
main(void)
{
	assert(learnable("PCM") == true);
	assert(learnable("CCP") == false);
	assert(learnable("CPM") == true);

	return 0;
}
