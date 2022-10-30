/*

Everyone knows that C is a lovely, safe, high level programming language. However you, as a coder are set the following task.

    Write a program to add two numbers.

    Input: Two space separated integers.
    Output: The sum of the two numbers in the input.

The twist is that your code must be 100% safe. In other words, it must behave properly no matter what the input is. If the input is indeed two space separated integers, both of which are less than 100 digits long, it must output the sum. Otherwise, it must output an error message and quit safely.

How hard can it be after all?

General kudos will be given to pathological input cases which break other people's answers :)

The code must compile without warnings using gcc -Wall -Wextra on ubuntu.

Clarification.

    Input is from stdin.
    Horizontal whitespace is only a single space character. There should be nothing before the first number and the input should be terminated with either newline+EOF or just EOF.
    the only valid input, specified in Augmented Backus-Naur Form, is:

    NONZERODIGIT = "1" / "2" / "3" / "4" / "5" / "6" / "7" / "8" / "9"
    POSITIVENUMBER = NONZERODIGIT *98DIGIT
    NEGATIVENUMBER = "-" POSITIVENUMBER
    NUMBER = NEGATIVENUMBER / POSITIVENUMBER / "0"
    VALIDINPUT = NUMBER SP NUMBER *1LF EOF

    The error message is the single letter 'E', followed by a new line.
    The code must terminate cleanly in less than 0.5s no matter what the input is.

*/

#include <stdio.h>
#include <gmp.h>

void
add(const char *s, const char *t)
{
	mpz_t a, b, c;

	mpz_init(a);
	mpz_init(b);
	mpz_init(c);

	mpz_set_str(a, s, 0);
	mpz_set_str(b, t, 0);
	mpz_add(c, a, b);

	mpz_out_str(stdout, 10, c);
	printf("\n");

	mpz_clear(a);
	mpz_clear(b);
	mpz_clear(c);
}

int
main(void)
{
	add("109493758397628976963206832978693275691769", "1904829572497629476924769327692376923760317957672096729307626");
	add("149255929525295925929429429529059215929529529592592529520592049039512305153126938623068222222167831258236", "9999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999");
	add("-254363", "-25256362626245");

	return 0;
}
