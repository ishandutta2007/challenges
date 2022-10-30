/*

Here is a simple challenge for you: You must produce this ASCII representation of a chess board. White is represented by uppercase characters, and black is represented by lowercase. Empty tiles are represented by a .. Here is the full board:

rnbqkbnr
pppppppp
........
........
........
........
PPPPPPPP
RNBQKBNR

Since this is a kolmogorov-complexity question, you may not take any input and you must output this board by any default method, for example, saving a file, printing to STDOUT or returning from a function. You may optionally produce one trailing newline. Standard loopholes apply, and the shortest program in bytes!

However, remember this is equally as much a competition between submissions in the same language. While it's unlikely that a languages like Java could beat a language like perl, or a golfing language like pyth or cjam, having the shortest Java answer is still really impressive! To help you track the shortest answer in each language, you may use this leaderboard, which will show the shortest submission by language and overall.
Leaderboards

To make sure that your answer shows up, please start your answer with a headline, using the following Markdown template:

# Language Name, N bytes

where N is the size of your submission. If you improve your score, you can keep old scores in the headline, by striking them through. For instance:

# Ruby, <s>104</s> <s>101</s> 96 bytes

If there you want to include multiple numbers in your header (e.g. because your score is the sum of two files or you want to list interpreter flag penalties separately), make sure that the actual score is the last number in the header:

# Perl, 43 + 2 (-p flag) = 45 bytes

You can also make the language name a link which will then show up in the leaderboard snippet:

# [><>](http://esolangs.org/wiki/Fish), 121 bytes

Show code snippet

*/

#include <stdio.h>

int
main(void)
{
	const char *text =
	    "rnbqkbnr\n"
	    "pppppppp\n"
	    "........\n"
	    "........\n"
	    "........\n"
	    "........\n"
	    "PPPPPPPP\n"
	    "RNBQKBNR\n";

	printf("%s", text);
	return 0;
}
