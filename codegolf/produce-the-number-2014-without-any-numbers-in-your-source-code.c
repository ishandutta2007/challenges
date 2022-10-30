/*

Note to challenge writers as per meta consensus: This question was well-received when it was posted, but challenges like this, asking answerers to Do X without using Y are likely to be poorly received.
Try using the sandbox to get feedback on if you want to post a similar challenge.

    It's 2017 2018 2019 2020 2021 already, folks, go home.

So, now that it's 2014, it's time for a code question involving the number 2014.

Your task is to make a program that prints the number 2014, without using any of the characters 0123456789 in your code, and independently of any external variables such as the date or time or a random seed.

The shortest code (counting in bytes) to do so in any language in which numbers are valid tokens wins.

*/

#include <stdio.h>

int
main(void)
{
	printf("%c", ('f' - 'a') * '\n');
	printf("%c", ('e' - 'a') * '\f');
	printf("%c", ('h' - 'a') * '\a');
	printf("%c", ('e' - 'a') * '\r');
	printf("\n");

	return !'a';
}
