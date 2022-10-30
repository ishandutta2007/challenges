/*

Using your language of choice, write a function that takes a variable number of arguments and returns the number of arguments it was called with.

Specifics:

    Your language needs to support variadic argument functions: something callable that takes an arbitrary number of arguments and returns a value.
    Parameters must be able to be passed individually. This means that passing an array would only count for one parameter. You can use an "all passed arguments" array if your language supports it; the restriction is on how the function is called.
    Code that calls this function must not be required to pass the number of arguments in its source. If a compiler inserts the number of arguments as part of a calling convention, that is allowed.
    The arguments can be of any type you want. You can support only a single type (e.g. only supporting int is still valid), arbitrary types (any type of argument is allowed), or any combination of argument types (e.g. first arg is int, rest are strings).
    Your function may have a maximum number of arguments (especially since resources are finite), but must support at least 2 arguments.

Samples:

    f() returns 0
    f(1) or f("a") returns 1
    f([1, 2, 3]) returns 1 as it is passed an array, not 3 arguments
    f(1, 10) or f(1, "a") returns 2

As this is code-golf, the winning solution is the one that uses the fewest number of bytes.

*/

#include <iostream>
#include <vector>

using namespace std;

int args()
{
	return 0;
}

template <typename T, typename... Targs>
int args(T, Targs... n)
{
	return 1 + args(n...);
}

int main()
{
	cout << args() << endl;
	cout << args(1) << endl;
	cout << args("a") << endl;
	cout << args(vector<int>{1, 2, 3}) << endl;
	cout << args(1, 10) << endl;
	cout << args(1, "a") << endl;

	return 0;
}
