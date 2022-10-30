/*

The previous version of Quicksort was easy to understand, but it was not optimal. It required copying the numbers into other arrays, which takes up space and time. To make things faster, one can create an "in-place" version of Quicksort, where the numbers are all sorted within the array itself.

Challenge
Create an in-place version of Quicksort. You need to follow Lomuto Partitioning method. 

*/
#include <iostream>
#include <algorithm>

using namespace std;

#define nelem(x) (sizeof(x) / sizeof(x[0]))

template <typename T>
void print(T a[], size_t n)
{
	for (size_t i = 0; i < n; i++)
		cout << a[i] << " ";
	cout << endl;
}

template <typename T>
ssize_t partition(T a[], ssize_t lo, ssize_t hi)
{
	auto p = a[hi];
	auto i = lo;
	for (auto j = lo; j <= hi - 1; j++)
	{
		if (a[j] < p)
		{
			if (i != j)
				swap(a[i], a[j]);
			i++;
		}
	}
	swap(a[i], a[hi]);
	return i;
}

template <typename T>
void quicksort(T a[], ssize_t lo, ssize_t hi, size_t len)
{
	if (lo < hi)
	{
		auto p = partition<T>(a, lo, hi);
		print<T>(a, len);
		quicksort(a, lo, p - 1, len);
		quicksort(a, p + 1, hi, len);
	}
}

template <typename T>
void quicksort(T a[], size_t len)
{
	quicksort(a, 0, len - 1, len);
}

int main()
{
	int a[] = {1, 3, 9, 8, 2, 7, 5};
	quicksort(a, nelem(a));

	int b[] = {2, 3, 4, 1, 8, 9, 10, 11, 12, 1, 1, 1, 1, 1, 1, 1};
	quicksort(b, nelem(b));

	return 0;
}
