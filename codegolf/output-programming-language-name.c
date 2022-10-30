/*

Challenge:

In the programming language of your choice, take no input and output your programming language's name.

Fair enough, right?

Restrictions:

    You can't use any character that is included in your programming language's name in your code. E.g., if I use Batch, I must not use the chars 'B' 'a' t' 'c' 'h' in my code. Note that this is case sensitive.
        I can still use the char 'b' because it's different from 'B'.
    You can have "junk output" before or after the name of the language
    Version number doesn't count as part of the name of the language. E.g., I can use the number 3 in the code in my answer if it's in Python 3
    The output of the programming language name is not case sensitive.
    Brute-forcing all possible letter combinations and hoping you get your language name is forbidden.

Example outputs: (let's say my programming language is called Language) (✔ if valid, else ✖)

    Language ✔
    Body language is a type of non-verbal communication in which physical behavior, as opposed to words, is used to express or convey information. Such behavior includes facial expressions, body posture, gestures, eye movement, touch and the use of space. ✔
    Language 2.0 - © 1078 AD some company ✔
    foobar ✖

*/

#include <stdio.h>

int
main(void)
{
	puts("C");
	return 0;
}
