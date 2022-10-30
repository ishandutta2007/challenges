/*

Take the string of brackets ]][][[. When you rotate it to the right once, you get []][][. If you rotate it again, you get [[]][]. All brackets in this string are balanced.

The Task:

Your program (or function) will be given a string of brackets, represented in any reasonable format (including using other things in place of the brackets, like -1 and 1).
The numbers of opening and closing brackets will always be equal, so [ or ][] won't be given as inputs.

Output should be a rotation of those brackets which is balanced. You can check this by repeatedly removing pairs of brackets ([]). With a balanced string of brackets, none will be left over.

Rotating a string to the right involves taking the last character, and moving it to the beginning.
For example, 01234567 rotated right 3 times would be 56701234.
The direction of rotation doesn't matter, but no brackets should be added, discarded, mirrored, etc.
If multiple solutions are possible, such as [][[]] or [[]][], you can return any of them.

Test Cases:

[]          ->  []
]][[        ->  [[]]
[][]][      ->  [[][]]
][][[]      ->  [[]][] OR [][[]]
[[[][][]]]  ->  [[[][][]]]
]]][][][[[  ->  [[[]]][][] OR [][[[]]][] OR [][][[[]]]

*/

#include <cassert>
#include <iostream>
#include <string>

using namespace std;

bool balanced(string &s)
{
	auto p = 0;
	for (auto c : s)
	{
		if (c == '[')
			p++;
		else if (c == ']')
		{
			if (p-- <= 0)
				return false;
		}
	}
	return true;
}

void rotl(string &s, int d)
{
	reverse(s.begin(), s.begin() + d);
	reverse(s.begin() + d, s.end());
	reverse(s.begin(), s.end());
}

void rotr(string &s, int d)
{
	rotl(s, s.length() - d);
}

bool rotb(string &s)
{
	size_t n = s.length();
	for (size_t i = 0; i < n; i++)
	{
		rotr(s, 1);
		if (balanced(s))
			return true;
	}
	return false;
}

void test(const string &s, const string &r)
{
	string p = s;
	assert(rotb(p) == true);
	cout << p << endl;
	assert(p == r);
}

int main()
{
	test("[]", "[]");
	test("]][[", "[[]]");
	test("[][]][", "[[][]]");
	test("][][[]", "[[]][]");
	test("[[[][][]]]", "[[[][][]]]");
	test("]]][][][[[", "[[[]]][][]");

	return 0;
}
