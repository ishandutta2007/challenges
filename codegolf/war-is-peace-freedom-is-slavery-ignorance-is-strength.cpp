/*

As George Orwell wrote in 1984:

War is peace
Freedom is slavery
Ignorance is strength

Write a program or function that takes in one of the six main words from the Orwell quote and outputs its counterpart.

Specifically:

[input] -> [output]
war -> peace
peace -> war
freedom -> slavery
slavery -> freedom
ignorance -> strength
strength -> ignorance
No other input/output pairs are required.

You should assume the words are always fully lowercase, as above. Alternatively, you may assume the words are always fully uppercase: WAR -> PEACE, PEACE -> WAR, etc.

*/

#include <iostream>
#include <string>
#include <map>

using namespace std;

string translate(const string &word)
{
	static const map<string, string> lut = {
	    {"WAR", "PEACE"},
	    {"PEACE", "WAR"},
	    {"FREEDOM", "SLAVERY"},
	    {"SLAVERY", "FREEDOM"},
	    {"IGNORANCE", "STRENGTH"},
	    {"STRENGTH", "IGNORANCE"},
	};

	auto it = lut.find(word);
	if (it == lut.end())
		return word;
	return it->second;
}

int main()
{
	cout << translate("WAR") << endl;
	cout << translate("PEACE") << endl;
	cout << translate("FREEDOM") << endl;
	cout << translate("SLAVERY") << endl;
	cout << translate("IGNORANCE") << endl;
	cout << translate("STRENGTH") << endl;

	return 0;
}
