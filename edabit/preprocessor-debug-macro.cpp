/*

In this challenge you are not supposed to write a function but two C/C++ preprocessor macros. It was supposed to be just one macro, but since there is no direct access to the compiler or the source files, it was not possible.

Anyway, these macros are supposed to be simple debugging macros. The first one (DOUT) prints/streams the input it gets to std::cout. The second one (NDOUT) ignores all input and does nothing.

These macros are supposed to be function-like macros. They each receive one argument, which may include stream operators ( operator<< ). After each use of these macros there is a semicolon: DOUT( input );

Examples

DOUT( "Hello " << "World!" ); ➞ "Hello World!"

DOUT( 1 << '+' << 2 << '=' << 1+2 ); ➞ "1+2=3"

NDOUT( "Hello" << "World!" ); ➞ ""

Notes

    Remember to stream the output to std::cout. Don't use printf or anything else. Don't try to return a string.
    To spread macro definitions over multiple lines you can use backslashes \ as the last character on a line:

#define N \
123

std::cout << N << std::endl;         // prints "123"

Nothing Important

My original plan was to conditionally compile the DOUT macro based on whether DEBUG was defined or not ( ➞ #ifdef ... ). As mentioned earlier, that was not possible, since I have no access to the source files of your code or the tests and no access to the compiler itself. That is why you have to implement two distinct macros and not just one.

*/

#include <cassert>
#include <cstdio>
#include <cstdarg>
#include <iostream>
#include <sstream>

#define DOUT(...) std::cout << __VA_ARGS__
#define NDOUT(...) std::cout << "";

#define TEST(FUN, STR, ...)                     \
	do                                          \
	{                                           \
		std::stringstream buffer;               \
		cout_redirect redirect(buffer.rdbuf()); \
		FUN(__VA_ARGS__);                       \
		printf("%s\n", buffer.str().c_str());   \
		assert(buffer.str() == STR);            \
	} while (0);

struct cout_redirect
{
	cout_redirect(std::streambuf *new_buffer)
		: old(std::cout.rdbuf(new_buffer))
	{
	}

	~cout_redirect()
	{
		std::cout.rdbuf(old);
	}

private:
	std::streambuf *old;
};

int main()
{
	TEST(DOUT, "Hello World\n", "Hello "
									<< "World" << std::endl);

	TEST(DOUT, "1+2=3\n", 1 << '+' << 2 << "=" << '3' << '\n');

	int a = 2, b = 3;
	TEST(DOUT, "2 + 3 = 5\n", a << " + " << b << " = " << a + b << std::endl);

	a = 0x2a;
	TEST(DOUT, "a=42, which equals 0x2a in hexadecimal format\n", "a=" << a << ", which equals 0x" << std::hex << a << " in hexadecimal format\n");

	TEST(NDOUT, "", "Hello "
						<< "World" << std::endl);

	return 0;
}
