/*

R, a programming language used for Statistics and Data Analysis, has the function order, which returns a list with the indices needed to sort the original vector(∗).

For example:

my_arr = [1, 3, 3, 9, 8]
// Ordered would be: [0, 1, 2, 4, 3]

In plain words, order tells you what elements to look at in your original vector to sort it. The list my_arr[0] + my_arr[1] + my_arr[2] + my_arr[4] + my_arr[3] is equivalent to sorted(my_arr).

If two or more elements have the same order, their original order is preserved. Here, [0, 1, 2, 4, 3] and [0, 2, 1, 4, 3] would both sort the vector, but only the first one preserves the original order for the two 3s.

Implement the function order() so that it works the same way it does in R.

Examples

order([9, 1, 4, 5, 4]) ➞ [1, 2, 4, 3, 0]

order(["z", "c", "f", "b", "c"]) ➞ [3, 1, 4, 2, 0]

order(["order", "my", "words"]) ➞ [1, 0, 2]

Notes

    Expect numbers and lower-case alphabetic characters only.
    Find Part II: Rank here.
    Vectors in R are similar to a list. Although vectors in R are 1-indexed, your function should be 0-indexed. Other differences between vectors and lists will be ignored for the scope of this challenge.
    If you implement your own algorithm, it must be stable, meaning that the order of identical elements doesn't get switched around.

*/

#include <cassert>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <string>

using namespace std;

template <typename T>
struct Element
{
	T value;
	size_t index;
};

template <typename T>
vector<int> order(const vector<T> &a)
{
	vector<Element<T> > p;
	size_t i = 0;
	for (auto &v : a)
		p.push_back({ v, i++ });

	auto cmp = [](auto x, auto y) { return x.value < y.value; };
	stable_sort(p.begin(), p.end(), cmp);

	vector<int> r;
	for (auto &v : p)
		r.push_back(v.index);

	return r;
}

template <typename T>
void test(const vector<T> &a, const vector<int> &r)
{
	auto p = order<T>(a);
	assert(p == r);
}

int main()
{
	test(vector<int>{ 1, 3, 3, 9, 8 }, { 0, 1, 2, 4, 3 });
	test(vector<int>{ 9, 1, 4, 5, 4 }, { 1, 2, 4, 3, 0 });
	test(vector<int>{ 1, 1, 1, 1, 1 }, { 0, 1, 2, 3, 4 });
	test(vector<int>{ 1, 2, 0, 3, 7, 1, 11, 1, 2 }, { 2, 0, 5, 7, 1, 8, 3, 4, 6 });
	test(vector<double>{ 1, -4, 5.5, -1, 4, 7.5 }, { 1, 3, 0, 4, 2, 5 });
	test(vector<string>{ "z", "c", "f", "b", "c" }, { 3, 1, 4, 2, 0 });
	test(vector<string>{ "d", "f", "g", "a", "d", "a", "d", "y" }, { 3, 5, 0, 4, 6, 1, 2, 7 });
	test(vector<string>{ "order", "my", "words" }, { 1, 0, 2 });
	test(vector<string>{ "a", "rose", "is", "a", "rose", "is", "a", "rose" }, { 0, 3, 6, 2, 5, 1, 4, 7 });
	test(vector<string>{ "z", "zz", "zzz" }, { 0, 1, 2 });

	return 0;
}
