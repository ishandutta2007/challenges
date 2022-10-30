/*

Given a pair, return its FIRST value and its SECOND value. Pair will be < int, int >.
Examples

pairs(std::make_pair(51, 21)) ➞ {51, 21}

pairs(std::make_pair(512124, 215)) ➞ {512124, 215}

*/

#include <cassert>
#include <vector>
#include <utility>

using namespace std;

vector<int> pairs(const pair<int, int> &p)
{
	return vector<int>{p.first, p.second};
}

int main()
{
	assert(pairs(make_pair(51, 21)) == vector<int>({51, 21}));
	assert(pairs(make_pair(512124, 215)) == vector<int>({512124, 215}));
	assert(pairs(make_pair(1, 2)) == vector<int>({1, 2}));
	assert(pairs(make_pair(21, 82)) == vector<int>({21, 82}));
	assert(pairs(make_pair(4213, 526)) == vector<int>({4213, 526}));
	return 0;
}
