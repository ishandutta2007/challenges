/*

Aristid is the mayor of a town called Linden. He and the townsfolk love fractals.
One day, Aristid decides to genetically alter trees so that they have mathematically pleasing structures.
It turns out that the people of Linden will support this idea only if the trees are sufficiently “tree-like.”
So Aristid came up with the following system to generate realistic looking trees. Since he’s a little vain, he decided to call it the Linden Mayor System.

Start with a sequence of letters S0. This is the seed that will be used to generate the rest of the tree.
Next define some rules to model the branching behavior of the tree. A rule will have the form x→y, indicating that the letter x will be replaced with the sequence y.
By applying these rules to S0, the new sequence S1 is created. These rules can be applied over and over to produce new sequences.
In general, to create Sn+1 from Sn, replace all the letters in sequence Sn according to the rules. Some letters may not have a rule associated with them.
Such terminal letters are not replaced.

As an example, consider the starting sequence A with rules:

A →AB and B →A. The first four iterations are as follows:

S0: A
	
Starting sequence.

S1: AB       A is replaced with AB by rule A → AB. Note that rule B → A couldn’t be applied.
S2: ABA      Again, A is replaced by AB but B is replaced with A (rule B → A).
S3: ABAAB    Keep applying rule A → AB for A’s and rule B → A for B’s...
S4: ABAABABA This is the resulting sequence after four iterations.

Input

The first line will contain two positive integers n and m where 0≤n≤26 and 0≤m≤5.
Following this will be n lines defining the rules for a Linden Mayor System.
Each line is of the form: x -> y, indicating that x is replaced by y. x is an uppercase letter from A to Z, and y will contain between one and five uppercase letters from A to Z.
The last line will contain the starting sequence S0, which is non-empty and no longer than 30 characters and will contain only uppercase letters from A to Z.

Output

Output the resulting sequence Sm which is produced after m iterations.

*/

#include <cassert>
#include <iostream>
#include <string>
#include <unordered_map>

using namespace std;

string evolve(unordered_map<char, string> &rules, const string &seed, unsigned iters)
{
	auto p = seed;
	auto q = string("");
	for (auto i = 0u; i < iters; i++)
	{
		q = "";
		for (auto c : p)
			q += rules[c];

		swap(p, q);
	}
	return p;
}

void test(unordered_map<char, string> &rules, const string &seed, unsigned iters, const string &result)
{
	auto str = evolve(rules, seed, iters);
	cout << str << endl;
	assert(str == result);
}

int main()
{
	unordered_map<char, string> rules_1 = { { 'A', "AB" }, { 'B', "A" } };

	test(rules_1, "A", 4, "ABAABABA");

	return 0;
}
