/*

A known problem with some microphones is the “hissing s”. That is, sometimes the sound of the letter s is particularly pronounced; it stands out from the rest of the word in an unpleasant way.

Of particular annoyance are words that contain the letter s twice in a row. Words like amiss, kiss, mississippi and even hiss itself.

Input

The input contains a single string on a single line. This string consists of only lowercase letters (no spaces) and has between 1 and 30 characters.

Output

Output a single line. If the input string contains two consecutive occurrences of the letter s, then output hiss. Otherwise, output no hiss.

*/

#include <cassert>
#include <string>

using namespace std;

string hiss(const string &s)
{
	if (s.find("ss") != string::npos)
		return "hiss";
	return "no hiss";
}

int main()
{
	assert(hiss("kiss") == "hiss");
	assert(hiss("mississippi") == "hiss");
	assert(hiss("amiss") == "hiss");
	assert(hiss("octopuses") == "no hiss");
	assert(hiss("hiss") == "hiss");

	return 0;
}
