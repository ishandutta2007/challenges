/*

ATM machines allow 4 or 6 digit PIN codes and PIN codes cannot contain anything but exactly 4 digits or exactly 6 digits. Your task is to create a function that takes a string and returns true if the PIN is valid and false if it's not.

Notes

    Some test cases contain special characters.
    Empty strings must return false.

*/
#include <stdio.h>
#include <ctype.h>

int
validpin(const char *s)
{
	size_t i;

	for (i = 0; s[i] && i < 7; i++) {
		if (!isdigit(s[i]))
			return 0;
	}
	return i == 4 || i == 6;
}

int
main(void)
{
	printf("%d\n", validpin("1234"));
	printf("%d\n", validpin("12345"));
	printf("%d\n", validpin("a234"));
	printf("%d\n", validpin(""));
	printf("%d\n", validpin("%234"));
	printf("%d\n", validpin("`234"));
	printf("%d\n", validpin("@234"));
	printf("%d\n", validpin("#234"));
	printf("%d\n", validpin("*234"));
	printf("%d\n", validpin("5678"));
	printf("%d\n", validpin("^234"));
	printf("%d\n", validpin("(234"));
	printf("%d\n", validpin(")234"));
	printf("%d\n", validpin("123456"));
	printf("%d\n", validpin("-234"));
	printf("%d\n", validpin("_234"));
	printf("%d\n", validpin("+234"));
	printf("%d\n", validpin("=234"));
	printf("%d\n", validpin("?234"));
	return 0;
}
