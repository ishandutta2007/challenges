/*

You are given N integers in the sorted order.
Then you are given Q queries. In each query you will be given an integer
and you have to tell whether that integer is present in the array, 
if so you have to tell at which index it is present and if it is
not present you have to tell the index at which the smallest integer
that is just greater than the given number is present.
Lower bound is a function that can be used with a sorted vector.

*/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

size_t query(vector<int> &a, int v)
{
	auto n = lower_bound(a.begin(), a.end(), v) - a.begin();
	if (a[n] == v)
		cout << "YES " << n + 1 << endl;
	else
		cout << "NO " << n + 1 << endl;
	return n;
}

int main()
{
	vector<int> a = {1, 1, 2, 2, 6, 9, 9, 15};
	query(a, 1);
	query(a, 4);
	query(a, 9);
	query(a, 15);
	return 0;
}
