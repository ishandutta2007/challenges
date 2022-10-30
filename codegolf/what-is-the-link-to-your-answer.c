/*

Goal

Your task is to create a program taking no input that returns the link to your answer. You can find a link to your answer by clicking at the share button on your answer.
Rules

    Standard loopholes apply except for searching for the answer online. In fact, you are expected to find the answer online.
    You are allowed to use curl or the equivalent, but you are not allowed to use any html parser library or built-in. If you need to import the library, the import declaration does NOT count into the code size as long as you don't rename any identifiers.
    You are not allowed to assume, or hardcode, the link to your answer. You have to search this page for your submission. If you remove your submission and re-add it, and your code breaks, you fail the challenge.
    You may still assume your username, the contents of your code, and the programming language/byte count you are using. You are not allowed to assume the description below your code. If you edit the description part of the submission and the code breaks, you fail the challenge. You may assume that the code of each submission is unique and no one copies your submission into another answer.
    Your answer has to be exactly the same as what you get when you clicked on the share button.
    You may post the dummy answer for the prototyping purpose. Just delete it immediately after posting, and edit your answer into it once completed.
    You are not allowed to take an user input

Scoring

This is code-golf so, the shortest answer in bytes wins.

*/

#include <stdio.h>

int
main(void)
{
	static const char *link = "https://codegolf.stackexchange.com/questions/226635/what-is-the-link-to-your-answer";

	printf("%s\n", link);
	return 0;
}
