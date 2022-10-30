/*

Introduction:

Although we have a lot of challenges where swapping two items in a list is a subtask, like Single swaps of an array; Swap to Sort an Array; n swaps into a nop; etc.,
we don't have the simple challenge of just swapping two items given a list and two indices.

Input:
A list with some positive integers L, and two indices a and b.

Output:
The same list, with the two items at the given indices swapped.
Challenge rules:

    The input-list is guaranteed to contain at least two items.
    The input-list is guaranteed to only contain positive integers.
    The input-indices can be either 0-based or 1-based (please specify in your answer which of the two you've used).
    The input-indices are guaranteed to be valid indices based on the length of the input-list.
    The input-indices are distinct, so will never be the same index. (The values in the input-list won't necessary be distinct.)
    You can assume a<b

    (and you're allowed to take the inputs in reversed order if it helps).
    I/O is flexible. You're allowed to take the input as a list/array/stream, from STDIN, as a delimited string, etc. You're allowed to modify the input-list directly, or return a new one with the two items swapped.

General rules:

    This is code-golf, so shortest answer in bytes wins.
    Don't let code-golf languages discourage you from posting answers with non-codegolfing languages. Try to come up with an as short as possible answer for 'any' programming language.
    Standard rules apply for your answer with default I/O rules, so you are allowed to use STDIN/STDOUT, functions/method with the proper parameters and return-type, full programs. Your call.
    Default Loopholes are forbidden.
    If possible, please add a link with a test for your code (e.g. TIO).
    Also, adding an explanation for your answer is highly recommended.

Test cases

All test cases use 0-based indices.

Inputs: L=[1,2,3,4,5,6,7,8,9,10], a=3, b=7
Output:   [1,2,3,8,5,6,7,4,9,10]

Inputs: L=[ 3, 8, 1, 4,10,10,10,10], a=0, b=5
Output:   [10, 8, 1, 4,10, 3,10,10]

Inputs: L=[5,1,4,2,3], a=0, b=4
Output:   [3,1,4,2,5]

Inputs: L=[5,6], a=0, b=1
Output:   [6,5]

Inputs: L=[2,2,2], a=0, b=1
Output:   [2,2,2]

*/

#include <cassert>
#include <vector>

using namespace std;

void lswap(vector<int> &l, size_t a, size_t b)
{
	if (a < l.size() && b < l.size())
		swap(l[a], l[b]);
}

void test(vector<int> &l, size_t a, size_t b, vector<int> &r)
{
	lswap(l, a, b);
	assert(l == r);
}

int main()
{
	vector<int> l1 = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
	vector<int> r1 = {1, 2, 3, 8, 5, 6, 7, 4, 9, 10};

	vector<int> l2 = {3, 8, 1, 4, 10, 10, 10, 10};
	vector<int> r2 = {10, 8, 1, 4, 10, 3, 10, 10};

	vector<int> l3 = {5, 1, 4, 2, 3};
	vector<int> r3 = {3, 1, 4, 2, 5};

	vector<int> l4 = {5, 6};
	vector<int> r4 = {6, 5};

	vector<int> l5 = {2, 2, 2};
	vector<int> r5 = {2, 2, 2};

	test(l1, 3, 7, r1);
	test(l2, 0, 5, r2);
	test(l3, 0, 4, r3);
	test(l4, 0, 1, r4);
	test(l5, 0, 1, r5);

	return 0;
}
