/*

Your function will be passed two functions, f and g, that don't take any parameters.
Your function has to call them, and return a string which indicates which function returned the larger number.

    If f returns the larger number, return the string f.
    If g returns the larger number, return the string g.
    If the functions return the same number, return the string neither.

Examples

whichIsLarger(() => 5, () => 10) ➞ "g"

whichIsLarger(() => 25,  () => 25) ➞ "neither"

whichIsLarger(() => 505050, () => 5050) ➞ "f"

Notes

This exercise is designed as an introduction to higher order functions (functions which use other functions to do their work).

*/

#include <cassert>
#include <cstring>

template <int N>
int mk()
{
	return N;
}

const char *larger(int (*f)(), int (*g)())
{
	auto x = f();
	auto y = g();
	if (x > y)
		return "f";
	if (x < y)
		return "g";
	return "neither";
}

int main()
{
	assert(!strcmp(larger(mk<5>, mk<10>), "g"));
	assert(!strcmp(larger(mk<10>, mk<5>), "f"));
	assert(!strcmp(larger(mk<25>, mk<25>), "neither"));
	assert(!strcmp(larger(mk<-100>, mk<-100>), "neither"));
	assert(!strcmp(larger(mk<-100>, mk<0>), "g"));
	assert(!strcmp(larger(mk<505050>, mk<5050>), "f"));
	assert(!strcmp(larger(mk<100>, mk<1000>), "g"));

	return 0;
}
