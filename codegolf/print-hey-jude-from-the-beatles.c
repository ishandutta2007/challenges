/*

Your task is to write a program which prints following four verses extracted from the lyrics from The Beatles' song "Hey Jude" (© Sony/ATV Music Publishing LLC):

Hey Jude, don't make it bad\n
Take a sad song and make it better\n
Remember to let her into your heart\n
Then you can start to make it better\n
\n
Hey Jude, don't be afraid\n
You were made to go out and get her\n
The minute you let her under your skin\n
Then you begin to make it better\n
\n
Hey Jude, don't let me down\n
You have found her, now go and get her\n
Remember to let her into your heart\n
Then you can start to make it better\n
\n
Hey Jude, don't make it bad\n
Take a sad song and make it better\n
Remember to let her under your skin\n
Then you'll begin to make it\n
\n
BUT

The only input you are allowed to use to construct these four verses is this list of tokens:

"Hey Jude, don't"
" make it bad"
" be afraid"
" let me down"
"Take a sad song and make it better"
"You"
" were made to go out"
" and get her"
" have found her, now go"
"Remember to"
"The minute you"
" let her"
" into your heart"
" under your skin"
"Then"
" you"
" can start"
"'ll"
" begin"
" to make it"
" better"
Note that some tokens have a space preceded and that enclosing quotes are not part of the tokens. You are free to use any format for the list and to rearrange the order of the tokens.

Your generated output has to exactly match the above four verses. Note that\n is used for newlines and an extra newline is added after each verse. You can use this file (MD5: 4551829c84a370fc5e6eb1d5c854cbec) to check your output against.

You can use following railroad diagram to understand the structure of the verses (each element represents a token): enter image description here

Shortest code in bytes wins. Happy golfing.

*/

#include <stdio.h>

int
main(void)
{
	static const char *txt = "Hey Jude, don't make it bad\n"
	                         "Take a sad song and make it better\n"
	                         "Remember to let her into your heart\n"
	                         "Then you can start to make it better\n"
	                         "\n"
	                         "Hey Jude, don't be afraid\n"
	                         "You were made to go out and get her\n"
	                         "The minute you let her under your skin\n"
	                         "Then you begin to make it better\n"
	                         "\n"
	                         "Hey Jude, don't let me down\n"
	                         "You have found her, now go and get her\n"
	                         "Remember to let her into your heart\n"
	                         "Then you can start to make it better\n"
	                         "\n"
	                         "Hey Jude, don't make it bad\n"
	                         "Take a sad song and make it better\n"
	                         "Remember to let her under your skin\n"
	                         "Then you'll begin to make it\n"
	                         "\n";

	printf("%s", txt);
	return 0;
}
