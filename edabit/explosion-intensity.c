/*

Given a number, return a string of the word "Boom", which varies in the following ways:

    The string should include n number of "o"s, unless n is below 2 (in that case, return "boom").
    If n is evenly divisible by 2, add an exclamation mark to the end.
    If n is evenly divisible by 5, return the string in ALL CAPS.
    If n is evenly divisible by both 2 and 5, return the string in ALL CAPS and add an exclamation mark to the end.

The example below should help clarify these instructions.
Examples

boomIntensity(4) ➞ "Boooom!"
// There are 4 "o"s and 4 is divisible by 2 (exclamation mark included)

boomIntensity(1) ➞ "boom"
// 1 is lower than 2, so we return "boom"

boomIntensity(5) ➞ "BOOOOOM"
// There are 5 "o"s and 5 is divisible by 5 (all caps)

boomIntensity(10) ➞ "BOOOOOOOOOOM!"
// There are 10 "o"s and 10 is divisible by 2 and 5 (all caps and exclamation mark included)

Notes

    A number which is evenly divisible by 2 and 5 will have both effects applied (see example #4).
    "Boom" will always start with a capital "B", except when n is less than 2, then return a minature explosion as "boom".

*/

#include <assert.h>
#include <stdio.h>
#include <string.h>
#include <stdarg.h>

int
snprint(char *str, size_t size, const char *fmt, ...)
{
	va_list ap;
	size_t n;

	va_start(ap, fmt);
	n = vsnprintf(str, size, fmt, ap);
	va_end(ap);
	return (size < n) ? size : n;
}

char *
boomintensity(unsigned x, char *b, size_t n)
{
	size_t l;
	int m2, m5;
	size_t i;

	if (x < 2) {
		snprintf(b, n, "boom");
		return b;
	}

	m2 = (x % 2 == 0);
	m5 = (x % 5 == 0);

	l = 0;
	l += snprint(b + l, n - l, "B");
	for (i = 0; i < x; i++)
		l += snprint(b + l, n - l, "%c", (m5) ? 'O' : 'o');
	l += snprint(b + l, n - l, "%c", (m5) ? 'M' : 'm');
	if (m2)
		l += snprint(b + l, n - l, "!");
	return b;
}

int
main(void)
{
	char b[256];

	assert(!strcmp(boomintensity(0, b, sizeof(b)), "boom"));
	assert(!strcmp(boomintensity(1, b, sizeof(b)), "boom"));
	assert(!strcmp(boomintensity(2, b, sizeof(b)), "Boom!"));
	assert(!strcmp(boomintensity(3, b, sizeof(b)), "Booom"));
	assert(!strcmp(boomintensity(4, b, sizeof(b)), "Boooom!"));
	assert(!strcmp(boomintensity(5, b, sizeof(b)), "BOOOOOM"));
	assert(!strcmp(boomintensity(6, b, sizeof(b)), "Boooooom!"));
	assert(!strcmp(boomintensity(7, b, sizeof(b)), "Booooooom"));
	assert(!strcmp(boomintensity(8, b, sizeof(b)), "Boooooooom!"));
	assert(!strcmp(boomintensity(9, b, sizeof(b)), "Booooooooom"));
	assert(!strcmp(boomintensity(10, b, sizeof(b)), "BOOOOOOOOOOM!"));
	assert(!strcmp(boomintensity(11, b, sizeof(b)), "Booooooooooom"));
	assert(!strcmp(boomintensity(12, b, sizeof(b)), "Boooooooooooom!"));
	assert(!strcmp(boomintensity(13, b, sizeof(b)), "Booooooooooooom"));
	assert(!strcmp(boomintensity(14, b, sizeof(b)), "Boooooooooooooom!"));
	assert(!strcmp(boomintensity(15, b, sizeof(b)), "BOOOOOOOOOOOOOOOM"));
	assert(!strcmp(boomintensity(16, b, sizeof(b)), "Boooooooooooooooom!"));
	assert(!strcmp(boomintensity(17, b, sizeof(b)), "Booooooooooooooooom"));
	assert(!strcmp(boomintensity(18, b, sizeof(b)), "Boooooooooooooooooom!"));
	assert(!strcmp(boomintensity(19, b, sizeof(b)), "Booooooooooooooooooom"));
	assert(!strcmp(boomintensity(20, b, sizeof(b)), "BOOOOOOOOOOOOOOOOOOOOM!"));
	assert(!strcmp(boomintensity(21, b, sizeof(b)), "Booooooooooooooooooooom"));
	assert(!strcmp(boomintensity(22, b, sizeof(b)), "Boooooooooooooooooooooom!"));
	assert(!strcmp(boomintensity(23, b, sizeof(b)), "Booooooooooooooooooooooom"));
	assert(!strcmp(boomintensity(24, b, sizeof(b)), "Boooooooooooooooooooooooom!"));
	assert(!strcmp(boomintensity(25, b, sizeof(b)), "BOOOOOOOOOOOOOOOOOOOOOOOOOM"));
	assert(!strcmp(boomintensity(26, b, sizeof(b)), "Boooooooooooooooooooooooooom!"));
	assert(!strcmp(boomintensity(27, b, sizeof(b)), "Booooooooooooooooooooooooooom"));
	assert(!strcmp(boomintensity(28, b, sizeof(b)), "Boooooooooooooooooooooooooooom!"));
	assert(!strcmp(boomintensity(29, b, sizeof(b)), "Booooooooooooooooooooooooooooom"));
	assert(!strcmp(boomintensity(30, b, sizeof(b)), "BOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOM!"));
	assert(!strcmp(boomintensity(31, b, sizeof(b)), "Booooooooooooooooooooooooooooooom"));
	assert(!strcmp(boomintensity(32, b, sizeof(b)), "Boooooooooooooooooooooooooooooooom!"));
	assert(!strcmp(boomintensity(33, b, sizeof(b)), "Booooooooooooooooooooooooooooooooom"));
	assert(!strcmp(boomintensity(34, b, sizeof(b)), "Boooooooooooooooooooooooooooooooooom!"));
	assert(!strcmp(boomintensity(35, b, sizeof(b)), "BOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOM"));
	assert(!strcmp(boomintensity(36, b, sizeof(b)), "Boooooooooooooooooooooooooooooooooooom!"));
	assert(!strcmp(boomintensity(37, b, sizeof(b)), "Booooooooooooooooooooooooooooooooooooom"));
	assert(!strcmp(boomintensity(38, b, sizeof(b)), "Boooooooooooooooooooooooooooooooooooooom!"));
	assert(!strcmp(boomintensity(39, b, sizeof(b)), "Booooooooooooooooooooooooooooooooooooooom"));
	assert(!strcmp(boomintensity(40, b, sizeof(b)), "BOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOM!"));
	assert(!strcmp(boomintensity(41, b, sizeof(b)), "Booooooooooooooooooooooooooooooooooooooooom"));
	assert(!strcmp(boomintensity(42, b, sizeof(b)), "Boooooooooooooooooooooooooooooooooooooooooom!"));
	assert(!strcmp(boomintensity(43, b, sizeof(b)), "Booooooooooooooooooooooooooooooooooooooooooom"));
	assert(!strcmp(boomintensity(44, b, sizeof(b)), "Boooooooooooooooooooooooooooooooooooooooooooom!"));
	assert(!strcmp(boomintensity(45, b, sizeof(b)), "BOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOM"));
	assert(!strcmp(boomintensity(46, b, sizeof(b)), "Boooooooooooooooooooooooooooooooooooooooooooooom!"));
	assert(!strcmp(boomintensity(47, b, sizeof(b)), "Booooooooooooooooooooooooooooooooooooooooooooooom"));
	assert(!strcmp(boomintensity(48, b, sizeof(b)), "Boooooooooooooooooooooooooooooooooooooooooooooooom!"));
	assert(!strcmp(boomintensity(49, b, sizeof(b)), "Booooooooooooooooooooooooooooooooooooooooooooooooom"));
	assert(!strcmp(boomintensity(50, b, sizeof(b)), "BOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOM!"));
	assert(!strcmp(boomintensity(51, b, sizeof(b)), "Booooooooooooooooooooooooooooooooooooooooooooooooooom"));
	assert(!strcmp(boomintensity(52, b, sizeof(b)), "Boooooooooooooooooooooooooooooooooooooooooooooooooooom!"));
	assert(!strcmp(boomintensity(53, b, sizeof(b)), "Booooooooooooooooooooooooooooooooooooooooooooooooooooom"));
	assert(!strcmp(boomintensity(54, b, sizeof(b)), "Boooooooooooooooooooooooooooooooooooooooooooooooooooooom!"));
	assert(!strcmp(boomintensity(55, b, sizeof(b)), "BOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOM"));
	assert(!strcmp(boomintensity(56, b, sizeof(b)), "Boooooooooooooooooooooooooooooooooooooooooooooooooooooooom!"));
	assert(!strcmp(boomintensity(57, b, sizeof(b)), "Booooooooooooooooooooooooooooooooooooooooooooooooooooooooom"));
	assert(!strcmp(boomintensity(58, b, sizeof(b)), "Boooooooooooooooooooooooooooooooooooooooooooooooooooooooooom!"));
	assert(!strcmp(boomintensity(59, b, sizeof(b)), "Booooooooooooooooooooooooooooooooooooooooooooooooooooooooooom"));
	assert(!strcmp(boomintensity(60, b, sizeof(b)), "BOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOM!"));
	assert(!strcmp(boomintensity(61, b, sizeof(b)), "Booooooooooooooooooooooooooooooooooooooooooooooooooooooooooooom"));
	assert(!strcmp(boomintensity(62, b, sizeof(b)), "Boooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooom!"));
	assert(!strcmp(boomintensity(63, b, sizeof(b)), "Booooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooom"));
	assert(!strcmp(boomintensity(64, b, sizeof(b)), "Boooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooom!"));
	assert(!strcmp(boomintensity(65, b, sizeof(b)), "BOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOM"));
	assert(!strcmp(boomintensity(66, b, sizeof(b)), "Boooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooom!"));
	assert(!strcmp(boomintensity(67, b, sizeof(b)), "Booooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooom"));
	assert(!strcmp(boomintensity(68, b, sizeof(b)), "Boooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooom!"));
	assert(!strcmp(boomintensity(69, b, sizeof(b)), "Booooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooom"));
	assert(!strcmp(boomintensity(70, b, sizeof(b)), "BOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOM!"));
	assert(!strcmp(boomintensity(71, b, sizeof(b)), "Booooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooom"));
	assert(!strcmp(boomintensity(72, b, sizeof(b)), "Boooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooom!"));
	assert(!strcmp(boomintensity(73, b, sizeof(b)), "Booooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooom"));
	assert(!strcmp(boomintensity(74, b, sizeof(b)), "Boooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooom!"));
	assert(!strcmp(boomintensity(75, b, sizeof(b)), "BOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOM"));
	assert(!strcmp(boomintensity(76, b, sizeof(b)), "Boooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooom!"));
	assert(!strcmp(boomintensity(77, b, sizeof(b)), "Booooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooom"));
	assert(!strcmp(boomintensity(78, b, sizeof(b)), "Boooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooom!"));
	assert(!strcmp(boomintensity(79, b, sizeof(b)), "Booooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooom"));
	assert(!strcmp(boomintensity(80, b, sizeof(b)), "BOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOM!"));
	assert(!strcmp(boomintensity(81, b, sizeof(b)), "Booooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooom"));
	assert(!strcmp(boomintensity(82, b, sizeof(b)), "Boooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooom!"));
	assert(!strcmp(boomintensity(83, b, sizeof(b)), "Booooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooom"));
	assert(!strcmp(boomintensity(84, b, sizeof(b)), "Boooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooom!"));
	assert(!strcmp(boomintensity(85, b, sizeof(b)), "BOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOM"));
	assert(!strcmp(boomintensity(86, b, sizeof(b)), "Boooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooom!"));
	assert(!strcmp(boomintensity(87, b, sizeof(b)), "Booooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooom"));
	assert(!strcmp(boomintensity(88, b, sizeof(b)), "Boooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooom!"));
	assert(!strcmp(boomintensity(89, b, sizeof(b)), "Booooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooom"));
	assert(!strcmp(boomintensity(90, b, sizeof(b)), "BOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOM!"));
	assert(!strcmp(boomintensity(91, b, sizeof(b)), "Booooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooom"));
	assert(!strcmp(boomintensity(92, b, sizeof(b)), "Boooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooom!"));
	assert(!strcmp(boomintensity(93, b, sizeof(b)), "Booooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooom"));
	assert(!strcmp(boomintensity(94, b, sizeof(b)), "Boooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooom!"));
	assert(!strcmp(boomintensity(95, b, sizeof(b)), "BOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOM"));
	assert(!strcmp(boomintensity(96, b, sizeof(b)), "Boooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooom!"));
	assert(!strcmp(boomintensity(97, b, sizeof(b)), "Booooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooom"));
	assert(!strcmp(boomintensity(98, b, sizeof(b)), "Boooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooom!"));
	assert(!strcmp(boomintensity(99, b, sizeof(b)), "Booooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooom"));
	assert(!strcmp(boomintensity(100, b, sizeof(b)), "BOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOM!"));

	return 0;
}
