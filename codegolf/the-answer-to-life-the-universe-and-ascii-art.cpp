/*

Simple challenge: try to output the following text in as few bytes as you can:

       the        answer
      toli      fetheuniv
     ersea     nde     ver
    ything     the     ans
   wer tol     ife     the
  uni  ver           sean
 dev   ery         thin
gth    ean       swer
tolifetheuni    ver
seandeveryth   ing
       the     ans      wer
       tol     ifetheuniver
       sea     ndeverything

The original drawing contains 332 characters.

Rules

No input or an unused input.
Output can be in any reasonable format (string, list of strings, matrix of chars and so on).
You can use uppercase instead of lowercase for the drawing if your prefer so.
Trailing whitespaces and newlines allowed.
This is code-golf, so may the shortest program/function for each language win!

Notes

This has been identified as a possible duplicate of We're no strangers to code golf, you know the rules, and so do I.
That question was about searching and replacing text. Here you have to draw a shape using a given text, and at least two of the current answers demonstrate that golfing languages can beat plain compression algorithms in this case.

*/

#include <iostream>

using namespace std;

const auto text = R"(
       the        answer
      toli      fetheuniv
     ersea     nde     ver
    ything     the     ans
   wer tol     ife     the
  uni  ver           sean
 dev   ery         thin
gth    ean       swer
tolifetheuni    ver
seandeveryth   ing
       the     ans      wer
       tol     ifetheuniver
       sea     ndeverything
)";

int main()
{
	cout << text << endl;
	return 0;
}
