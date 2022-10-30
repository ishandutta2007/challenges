/*

--- Day 1: Report Repair ---
After saving Christmas five years in a row, you've decided to take a vacation at a nice resort on a tropical island. Surely, Christmas will go on without you.

The tropical island has its own currency and is entirely cash-only. The gold coins used there have a little picture of a starfish; the locals just call them stars. None of the currency exchanges seem to have heard of them, but somehow, you'll need to find fifty of these coins by the time you arrive so you can pay the deposit on your room.

To save your vacation, you need to get all fifty stars by December 25th.

Collect stars by solving puzzles. Two puzzles will be made available on each day in the Advent calendar; the second puzzle is unlocked when you complete the first. Each puzzle grants one star. Good luck!

Before you leave, the Elves in accounting just need you to fix your expense report (your puzzle input); apparently, something isn't quite adding up.

Specifically, they need you to find the two entries that sum to 2020 and then multiply those two numbers together.

For example, suppose your expense report contained the following:

1721
979
366
299
675
1456
In this list, the two entries that sum to 2020 are 1721 and 299. Multiplying them together produces 1721 * 299 = 514579, so the correct answer is 514579.

Of course, your expense report is much larger. Find the two entries that sum to 2020; what do you get if you multiply them together?

--- Part Two ---
The Elves in accounting are thankful for your help; one of them even offers you a starfish coin they had left over from a past vacation. They offer you a second one if you can find three numbers in your expense report that meet the same criteria.

Using the above example again, the three entries that sum to 2020 are 979, 366, and 675. Multiplying them together produces the answer, 241861950.

In your expense report, what is the product of the three entries that sum to 2020?

*/

#include <cstdint>
#include <fstream>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

int getints(const string &name, vector<int64_t> &res)
{
	ifstream fin(name);
	if (!fin.is_open())
		return -1;

	int64_t val;
	while (fin >> val)
		res.push_back(val);

	return 0;
}

int64_t part1(const vector<int64_t> &vals)
{
	for (auto a : vals)
	{
		for (auto b : vals)
			if (a + b == 2020)
				return a * b;
	}
	return 0;
}

int64_t part2(const vector<int64_t> &vals)
{
	for (auto a : vals)
	{
		for (auto b : vals)
		{
			for (auto c : vals)
				if (a + b + c == 2020)
					return a * b * c;
		}
	}
	return 0;
}

int main()
{
	vector<int64_t> vals;
	getints("1.txt", vals);

	cout << part1(vals) << endl;
	cout << part2(vals) << endl;

	return 0;
}
