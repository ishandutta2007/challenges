/*

Create a function that takes a list of strings and return a list, sorted from shortest to longest.

Notes

All test cases contain lists with strings of different lengths, so you won't have to deal with multiple strings of the same length.

*/

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

int main()
{
	auto print = [](auto &l)
	{
		for (auto &s : l)
			cout << s << " ";
		cout << endl;
	};

	auto cmp = [](const auto &a, const auto &b)
	{
		if (a.length() == b.length())
			return a < b;
		return a.length() < b.length();
	};

	auto test = [&](auto &l)
	{
		sort(l.begin(), l.end(), cmp);
		print(l);
	};

	vector<string> l1 = {"Google", "Apple", "Microsoft"};
	test(l1);

	vector<string> l2 = {"Leonardo", "Michelangelo", "Raphael", "Donatello"};
	test(l2);

	vector<string> l3 = {"Turing", "Einstein", "Jung"};
	test(l3);

	vector<string> l4 = {"Tatooine", "Hoth", "Yavin", "Dantooine"};
	test(l4);

	vector<string> l5 = {"Mario", "Bowser", "Link"};
	test(l5);

	vector<string> l6 = {"xxx", "zz", "y"};
	test(l6);

	return 0;
}
