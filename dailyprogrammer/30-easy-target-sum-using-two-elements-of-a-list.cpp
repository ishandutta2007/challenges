/*

Write a program that takes a list of integers and a target number and determines if any two integers in the list sum to the target number.
If so, return the two numbers. If not, return an indication that no such integers exist.

*/

#include <cassert>
#include <cstdio>
#include <climits>
#include <vector>
#include <utility>
#include <unordered_map>

using namespace std;

pair<int, int> target_sum(const vector<int> &a, int t)
{
	unordered_map<int, bool> m;
	for (auto v : a)
		m[v] = true;
	for (auto v : a)
	{
		if (m[t - v])
		{
			auto x = min(v, t - v);
			auto y = max(v, t - v);
			return make_pair(x, y);
		}
	}
	return make_pair(INT_MAX, INT_MAX);
}

int main()
{
	assert(target_sum({ 1, 2, 3 }, 4) == make_pair(1, 3));
	assert(target_sum({ 1, 2, 3 }, 5) == make_pair(2, 3));
	assert(target_sum({ 1, 2, 3 }, 10) == make_pair(INT_MAX, INT_MAX));
	return 0;
}
