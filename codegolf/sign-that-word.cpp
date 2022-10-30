/*

What is a Word Signature?
The signature of a word are all of it's letters put in order - the signatures of this, hist and hits are all hist.

The Challenge
Write a program program should ask for an input, then print out the signature of that word. So an example program run might look like this:

Give me a string: this
The signature signature of 'this' is hist.
There is no required interaction, as long as it takes an input and prints the signature, it is OK.

Scoring
The program with the smallest byte count wins!

*/

#include <algorithm>
#include <iostream>
#include <string>

using namespace std;

string signature(string word)
{
	sort(word.begin(), word.end());
	return word;
}

int main()
{
	string word;
	cout << "Give me a string: ";
	cin >> word;
	cout << "The signature of '" << word << "' is " << signature(word) << endl;

	return 0;
}
