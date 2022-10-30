/*

Write a program that counts up forever, starting from one.

Rules:

    Your program must log to STDOUT or an acceptable alternative, if STDOUT is not available.
    Your program must be a full, runnable program, and not a function or snippet.
    Your program must output each number with a separating character in between (a newline, space, tab or comma), but this must be consistent for all numbers.
    You may print the numbers in decimal, in unary or in base 256 where each digit is represented by a byte value.
    Your program must count at least as far as 2^128 (inclusive) without problems and without running out of memory on a reasonable desktop PC. In particular, this means if you're using unary, you cannot store a unary representation of the current number in memory.

    Unlike our usual rules, feel free to use a language (or language version) even if it's newer than this challenge. Languages specifically written to submit a 0-byte answer to this challenge are fair game but not particularly interesting.

    Note that there must be an interpreter so the submission can be tested. It is allowed (and even encouraged) to write this interpreter yourself for a previously unimplemented language.
    This is not about finding the language with the shortest solution for this (there are some where the empty program does the trick) - this is about finding the shortest solution in every language. Therefore, no answer will be marked as accepted.

Catalogue

The Stack Snippet at the bottom of this post generates the catalogue from the answers a) as a list of shortest solution per language and b) as an overall leaderboard.

To make sure that your answer shows up, please start your answer with a headline, using the following Markdown template:

## Language Name, N bytes

where N is the size of your submission. If you improve your score, you can keep old scores in the headline, by striking them through. For instance:

## Ruby, <s>104</s> <s>101</s> 96 bytes

If there you want to include multiple numbers in your header (e.g. because your score is the sum of two files or you want to list interpreter flag penalties separately), make sure that the actual score is the last number in the header:

## Perl, 43 + 2 (-p flag) = 45 bytes

You can also make the language name a link which will then show up in the snippet:

## [><>](http://esolangs.org/wiki/Fish), 121 bytes

*/

#include <iostream>
#include <boost/multiprecision/cpp_int.hpp>

using namespace std;
using namespace boost::multiprecision;

void count()
{
	uint1024_t x = 1;
	while (true)
		cout << x++ << endl;
}

int main()
{
	count();
	return 0;
}
