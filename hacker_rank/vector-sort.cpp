/*
You are given N integers. Sort the N integers and print the sorted order.
Store the N integers in a vector.
Vectors are sequence containers representing arrays that can change in size.

    Declaration:

    vector<int>v; (creates an empty vector of integers)

    Size:

    int size=v.size();

    Pushing an integer into a vector:

    v.push_back(x);(where x is an integer.The size increases by 1 after this.)

    Popping the last element from the vector:

    v.pop_back(); (After this the size decreases by 1)

    Sorting a vector:

    sort(v.begin(),v.end()); (Will sort all the elements in the vector)

To know more about vectors, Click Here
*/
#include <cstdio>
#include <algorithm>
#include <vector>

using namespace std;

int main()
{
	auto a = vector<int>{1, 6, 10, 8, 4};
	sort(a.begin(), a.end());
	for (auto x : a)
		printf("%d ", x);
	printf("\n");
	return 0;
}
