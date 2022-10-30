/*

When coloring a striped pattern, you may start by coloring each square sequentially, meaning you spend time needing to switch coloring pencils.

Create a function where given an array of colors cols, return how long it takes to color the whole pattern. Note the following times:

    It takes 1 second to switch between pencils.
    It takes 2 seconds to color a square.

See the example below for clarification.

color_pattern_times(["Red", "Blue", "Red", "Blue", "Red"]) ➞ 14

// There are 5 colors so it takes 2 seconds to color each one (2 x 5 = 10).
// You need to switch the pencils 4 times and it takes 1 second to switch (1 x 4 = 4).
// 10 + 4 = 14

Examples

colorPatternTimes(["Blue"]) ➞ 2

colorPatternTimes(["Red", "Yellow", "Green", "Blue"]) ➞ 11

colorPatternTimes(["Blue", "Blue", "Blue", "Red", "Red", "Red"]) ➞ 13

Notes

    Only change coloring pencils if the next color is different to the color before it.
    Return a number in seconds.

*/

#include <assert.h>
#include <stdio.h>
#include <string.h>

#define nelem(x) (sizeof(x) / sizeof(x[0]))

unsigned
colortimes(const char **s, size_t n)
{
	size_t i;
	unsigned r;

	r = n << 1;
	for (i = 1; i < n; i++) {
		if (strcmp(s[i], s[i - 1]))
			r++;
	}
	return r;
}

int
main(void)
{
	const char *s1[] = {"Red", "Blue", "Red", "Blue", "Red"};
	const char *s2[] = {"Blue"};
	const char *s3[] = {"Red", "Yellow", "Green", "Blue"};
	const char *s4[] = {"Blue", "Blue", "Blue", "Red", "Red", "Red"};
	const char *s5[] = {"Red", "Green", "Blue", "Yellow", "Red", "Red", "Yellow", "Green", "Green", "Green", "Red", "Blue", "Yellow", "Blue", "Green", "Green", "Red", "Red", "Red", "Blue", "Green", "Red", "Blue", "Blue", "Red", "Blue"};
	const char *s6[] = {"Red", "Blue", "Yellow", "Blue", "Green", "Green", "Yellow", "Green", "Blue", "Blue", "Blue", "Red", "Blue", "Red", "Green", "Red"};
	const char *s7[] = {"Yellow", "Green", "Blue"};
	const char *s8[] = {"Green", "Green", "Red", "Green", "Yellow", "Red", "Red", "Green", "Red", "Green"};
	const char *s9[] = {"Red"};
	const char *s10[] = {"Red", "Red", "Blue", "Red", "Green", "Red", "Blue", "Green", "Green", "Yellow", "Red"};
	const char *s11[] = {"Green", "Green", "Blue", "Red", "Red", "Blue", "Yellow", "Red", "Red", "Green", "Yellow", "Red", "Yellow", "Red", "Green", "Yellow", "Red", "Green", "Yellow", "Blue", "Yellow", "Red", "Green", "Green", "Blue", "Yellow", "Green", "Green", "Green", "Blue"};
	const char *s12[] = {"Red", "Blue", "Red", "Blue", "Green", "Blue", "Yellow", "Blue", "Yellow", "Yellow", "Yellow", "Red"};
	const char *s13[] = {"Yellow", "Green", "Yellow", "Yellow"};
	const char *s14[] = {"Blue", "Blue", "Yellow", "Green", "Green", "Red", "Blue", "Yellow", "Red", "Yellow", "Green", "Red", "Yellow", "Green", "Yellow", "Blue", "Yellow", "Green", "Green", "Blue"};
	const char *s15[] = {"Red", "Blue", "Yellow", "Blue", "Green", "Yellow", "Yellow", "Yellow", "Yellow", "Red", "Red", "Yellow", "Yellow"};
	const char *s16[] = {"Blue", "Red", "Red"};
	const char *s17[] = {"Red", "Blue", "Yellow", "Green", "Blue", "Yellow", "Blue", "Yellow", "Red", "Green", "Green", "Blue", "Blue", "Green", "Green", "Red", "Green", "Red", "Green", "Red", "Red", "Green", "Red", "Red", "Green", "Red", "Blue", "Yellow", "Red", "Red"};
	const char *s18[] = {"Yellow", "Blue", "Yellow", "Yellow", "Yellow", "Blue", "Blue"};
	const char *s19[] = {"Yellow", "Red", "Green", "Green", "Yellow", "Green", "Green", "Yellow", "Yellow", "Red", "Green", "Green", "Blue", "Green", "Red", "Yellow"};
	const char *s20[] = {"Red", "Red", "Blue", "Yellow", "Red", "Red", "Red", "Yellow", "Blue", "Blue", "Yellow", "Yellow", "Red", "Yellow", "Red", "Blue", "Blue", "Yellow", "Yellow", "Blue", "Blue", "Yellow", "Red", "Blue", "Red", "Blue", "Red", "Yellow", "Blue"};
	const char *s21[] = {"Yellow", "Red", "Green"};
	const char *s22[] = {"Green", "Red", "Yellow", "Yellow", "Blue", "Red", "Blue", "Blue", "Yellow", "Red", "Yellow", "Green", "Green", "Red", "Green", "Blue", "Green", "Red", "Blue", "Yellow", "Red"};
	const char *s23[] = {"Yellow", "Red", "Blue", "Green", "Red", "Green", "Yellow", "Yellow", "Yellow", "Red", "Green", "Blue", "Blue"};
	const char *s24[] = {"Green", "Blue", "Blue", "Red", "Yellow", "Red", "Red", "Yellow", "Red", "Red", "Blue", "Red", "Red"};
	const char *s25[] = {"Yellow", "Yellow", "Red", "Blue"};
	const char *s26[] = {"Green", "Red", "Red", "Blue", "Yellow", "Blue", "Yellow", "Yellow", "Green", "Red", "Red", "Green", "Red", "Yellow", "Yellow", "Green", "Green", "Yellow", "Blue", "Blue", "Red", "Yellow", "Red", "Blue", "Red", "Blue", "Blue", "Yellow", "Blue", "Yellow"};
	const char *s27[] = {"Red", "Blue", "Green", "Yellow", "Yellow", "Yellow", "Yellow", "Blue"};
	const char *s28[] = {"Green", "Red", "Green", "Red", "Yellow", "Green", "Green", "Red", "Red", "Yellow", "Green", "Yellow", "Yellow", "Yellow"};
	const char *s29[] = {"Yellow", "Red", "Green", "Blue", "Blue", "Red", "Red", "Yellow", "Red", "Green", "Red"};
	const char *s30[] = {"Yellow", "Yellow", "Blue", "Yellow", "Green", "Yellow", "Green", "Green", "Red", "Yellow", "Blue", "Green", "Green", "Green"};
	const char *s31[] = {"Green", "Green", "Red", "Green", "Blue", "Blue", "Red", "Yellow", "Red", "Yellow", "Green"};
	const char *s32[] = {"Yellow", "Green", "Yellow", "Green", "Yellow", "Green", "Blue", "Green", "Blue", "Green", "Red", "Red", "Blue", "Yellow", "Green", "Blue"};
	const char *s33[] = {"Red", "Green", "Green", "Blue", "Red", "Green", "Green", "Red", "Yellow", "Blue", "Red", "Red", "Yellow", "Blue", "Blue"};
	const char *s34[] = {"Yellow", "Yellow", "Red", "Yellow", "Blue", "Blue", "Blue", "Red", "Blue", "Red", "Yellow", "Red", "Red", "Red", "Yellow", "Blue", "Green", "Blue", "Blue", "Yellow", "Green"};
	const char *s35[] = {"Green", "Green", "Red", "Green", "Blue"};
	const char *s36[] = {"Red", "Yellow", "Red", "Green", "Blue", "Red", "Red", "Red", "Green", "Blue"};
	const char *s37[] = {"Blue", "Blue", "Blue", "Blue", "Blue", "Green", "Yellow", "Red", "Yellow", "Red", "Red", "Green", "Blue", "Yellow", "Green", "Yellow", "Green"};
	const char *s38[] = {"Blue", "Blue", "Blue", "Blue", "Green", "Green", "Yellow", "Blue", "Blue", "Red", "Yellow", "Green", "Yellow", "Red", "Blue", "Red", "Yellow"};
	const char *s39[] = {"Blue", "Blue", "Blue", "Red", "Yellow", "Red", "Blue", "Blue", "Blue", "Yellow"};
	const char *s40[] = {"Green", "Red", "Green", "Blue", "Blue", "Blue"};
	const char *s41[] = {"Red", "Yellow", "Red", "Yellow", "Green", "Blue", "Yellow", "Yellow"};
	const char *s42[] = {"Blue", "Red", "Red", "Blue", "Yellow", "Red", "Yellow", "Yellow", "Blue", "Yellow", "Blue", "Red", "Blue", "Green", "Yellow", "Red", "Red", "Red", "Green", "Yellow", "Red", "Blue", "Green"};
	const char *s43[] = {"Blue", "Blue", "Blue", "Yellow"};
	const char *s44[] = {"Red", "Red", "Blue"};
	const char *s45[] = {"Green", "Blue", "Blue", "Blue", "Yellow", "Yellow", "Red", "Yellow", "Blue", "Red", "Yellow", "Blue"};
	const char *s46[] = {"Green", "Red", "Green", "Yellow", "Green", "Yellow", "Green"};
	const char *s47[] = {"Green", "Red", "Blue", "Green", "Green", "Yellow", "Red", "Green", "Blue", "Green", "Yellow", "Yellow", "Red", "Green", "Yellow", "Green", "Green", "Blue", "Yellow", "Green", "Green", "Blue", "Yellow", "Red", "Red", "Red", "Green", "Green"};
	const char *s48[] = {"Blue", "Blue", "Red", "Yellow", "Green", "Yellow", "Green", "Red", "Blue", "Blue", "Red", "Green", "Blue", "Yellow", "Yellow", "Green", "Blue", "Red", "Yellow", "Red", "Green", "Yellow", "Green", "Green", "Green", "Yellow", "Red"};
	const char *s49[] = {"Blue", "Red", "Red", "Yellow", "Red", "Yellow", "Yellow", "Yellow", "Yellow", "Red", "Yellow", "Red", "Blue", "Red", "Blue", "Red", "Red", "Yellow", "Green", "Red", "Red", "Blue", "Red", "Yellow", "Yellow", "Blue", "Green", "Green", "Yellow", "Red"};
	const char *s50[] = {"Yellow", "Yellow", "Yellow", "Red", "Green", "Red"};
	const char *s51[] = {"Blue", "Red", "Yellow"};
	const char *s52[] = {"Blue", "Red", "Red", "Green", "Red", "Yellow", "Red", "Red", "Green", "Yellow", "Blue", "Yellow", "Yellow", "Red", "Yellow", "Red", "Blue", "Yellow"};
	const char *s53[] = {"Yellow", "Green", "Red", "Green", "Green", "Blue", "Blue", "Blue", "Yellow", "Green", "Yellow", "Yellow", "Yellow", "Red", "Green", "Green", "Blue", "Green", "Yellow", "Red", "Green", "Blue", "Green", "Red", "Green", "Red"};
	const char *s54[] = {"Green", "Blue", "Yellow", "Yellow", "Red", "Red", "Red", "Red", "Red", "Green", "Blue", "Blue", "Red", "Yellow", "Red", "Red", "Red", "Red", "Blue", "Yellow", "Yellow"};
	const char *s55[] = {"Yellow", "Red", "Blue", "Red", "Green", "Yellow", "Red", "Blue", "Blue", "Green", "Green", "Blue", "Blue", "Green", "Blue", "Red", "Yellow"};
	const char *s56[] = {"Yellow", "Yellow", "Blue", "Yellow", "Green", "Green", "Yellow", "Green", "Green", "Green", "Green", "Yellow", "Blue", "Blue", "Blue", "Green", "Green", "Green", "Yellow", "Blue", "Red"};
	const char *s57[] = {"Green", "Yellow", "Yellow"};
	const char *s58[] = {"Blue", "Yellow", "Yellow", "Green", "Blue", "Yellow", "Green", "Green", "Green", "Yellow", "Red", "Yellow", "Green", "Red", "Red", "Blue", "Yellow", "Blue", "Blue", "Red"};
	const char *s59[] = {"Green"};
	const char *s60[] = {"Green", "Blue"};
	const char *s61[] = {"Green", "Blue", "Red", "Blue", "Yellow", "Yellow", "Green", "Green", "Yellow", "Blue", "Green", "Red", "Green", "Yellow", "Green", "Blue", "Red", "Red", "Red", "Red", "Red"};
	const char *s62[] = {"Blue", "Yellow", "Blue", "Red", "Green", "Blue", "Yellow", "Red", "Blue", "Red", "Yellow", "Green", "Green", "Yellow", "Green", "Red", "Blue", "Red", "Red", "Blue", "Red", "Blue", "Yellow", "Blue", "Red", "Green", "Blue", "Yellow", "Yellow"};
	const char *s63[] = {"Yellow", "Yellow", "Green", "Yellow", "Green", "Blue", "Yellow", "Red", "Red", "Yellow", "Blue", "Blue", "Blue", "Blue", "Green", "Red", "Red", "Yellow", "Green", "Red", "Red", "Yellow"};
	const char *s64[] = {"Blue", "Red"};
	const char *s65[] = {"Blue", "Red", "Red", "Blue", "Red", "Green", "Green"};
	const char *s66[] = {"Red", "Green", "Green", "Yellow", "Yellow", "Yellow", "Red", "Green", "Yellow", "Yellow", "Green", "Blue", "Blue", "Blue", "Blue", "Yellow", "Blue", "Blue", "Blue", "Red", "Red", "Yellow", "Blue", "Red", "Blue", "Green", "Red", "Red"};
	const char *s67[] = {"Yellow", "Green", "Green", "Green", "Yellow", "Yellow", "Yellow", "Green", "Yellow", "Yellow", "Blue", "Green", "Yellow", "Blue", "Red", "Red", "Green", "Yellow", "Blue", "Red", "Blue", "Yellow"};
	const char *s68[] = {"Blue", "Green", "Blue", "Green", "Green", "Blue", "Red", "Green", "Red"};
	const char *s69[] = {"Yellow"};
	const char *s70[] = {"Green", "Yellow", "Red", "Green", "Yellow", "Blue", "Yellow", "Red", "Green", "Green", "Red", "Red", "Blue", "Red"};
	const char *s71[] = {"Blue", "Blue", "Blue"};
	const char *s72[] = {"Green", "Blue", "Blue", "Green", "Blue", "Green", "Blue", "Green", "Red", "Red", "Yellow", "Blue", "Blue", "Blue", "Blue", "Green", "Blue", "Green", "Blue", "Green", "Green", "Blue"};
	const char *s73[] = {"Blue", "Blue", "Blue", "Blue"};
	const char *s74[] = {"Red", "Blue", "Red", "Red", "Yellow", "Blue", "Yellow", "Blue", "Red", "Blue", "Green", "Yellow", "Green", "Yellow", "Red", "Red", "Red", "Green", "Red", "Yellow", "Blue", "Yellow", "Green", "Yellow", "Blue", "Green", "Blue", "Red", "Yellow", "Yellow"};

	assert(colortimes(s1, nelem(s1)) == 14);
	assert(colortimes(s2, nelem(s2)) == 2);
	assert(colortimes(s3, nelem(s3)) == 11);
	assert(colortimes(s4, nelem(s4)) == 13);
	assert(colortimes(s5, nelem(s5)) == 70);
	assert(colortimes(s6, nelem(s6)) == 44);
	assert(colortimes(s7, nelem(s7)) == 8);
	assert(colortimes(s8, nelem(s8)) == 27);
	assert(colortimes(s9, nelem(s9)) == 2);
	assert(colortimes(s10, nelem(s10)) == 30);
	assert(colortimes(s11, nelem(s11)) == 83);
	assert(colortimes(s12, nelem(s12)) == 33);
	assert(colortimes(s13, nelem(s13)) == 10);
	assert(colortimes(s14, nelem(s14)) == 56);
	assert(colortimes(s15, nelem(s15)) == 33);
	assert(colortimes(s16, nelem(s16)) == 7);
	assert(colortimes(s17, nelem(s17)) == 83);
	assert(colortimes(s18, nelem(s18)) == 17);
	assert(colortimes(s19, nelem(s19)) == 43);
	assert(colortimes(s20, nelem(s20)) == 78);
	assert(colortimes(s21, nelem(s21)) == 8);
	assert(colortimes(s22, nelem(s22)) == 59);
	assert(colortimes(s23, nelem(s23)) == 35);
	assert(colortimes(s24, nelem(s24)) == 34);
	assert(colortimes(s25, nelem(s25)) == 10);
	assert(colortimes(s26, nelem(s26)) == 82);
	assert(colortimes(s27, nelem(s27)) == 20);
	assert(colortimes(s28, nelem(s28)) == 37);
	assert(colortimes(s29, nelem(s29)) == 30);
	assert(colortimes(s30, nelem(s30)) == 37);
	assert(colortimes(s31, nelem(s31)) == 30);
	assert(colortimes(s32, nelem(s32)) == 46);
	assert(colortimes(s33, nelem(s33)) == 40);
	assert(colortimes(s34, nelem(s34)) == 56);
	assert(colortimes(s35, nelem(s35)) == 13);
	assert(colortimes(s36, nelem(s36)) == 27);
	assert(colortimes(s37, nelem(s37)) == 45);
	assert(colortimes(s38, nelem(s38)) == 45);
	assert(colortimes(s39, nelem(s39)) == 25);
	assert(colortimes(s40, nelem(s40)) == 15);
	assert(colortimes(s41, nelem(s41)) == 22);
	assert(colortimes(s42, nelem(s42)) == 64);
	assert(colortimes(s43, nelem(s43)) == 9);
	assert(colortimes(s44, nelem(s44)) == 7);
	assert(colortimes(s45, nelem(s45)) == 32);
	assert(colortimes(s46, nelem(s46)) == 20);
	assert(colortimes(s47, nelem(s47)) == 76);
	assert(colortimes(s48, nelem(s48)) == 75);
	assert(colortimes(s49, nelem(s49)) == 81);
	assert(colortimes(s50, nelem(s50)) == 15);
	assert(colortimes(s51, nelem(s51)) == 8);
	assert(colortimes(s52, nelem(s52)) == 50);
	assert(colortimes(s53, nelem(s53)) == 71);
	assert(colortimes(s54, nelem(s54)) == 52);
	assert(colortimes(s55, nelem(s55)) == 47);
	assert(colortimes(s56, nelem(s56)) == 53);
	assert(colortimes(s57, nelem(s57)) == 7);
	assert(colortimes(s58, nelem(s58)) == 54);
	assert(colortimes(s59, nelem(s59)) == 2);
	assert(colortimes(s60, nelem(s60)) == 5);
	assert(colortimes(s61, nelem(s61)) == 56);
	assert(colortimes(s62, nelem(s62)) == 83);
	assert(colortimes(s63, nelem(s63)) == 58);
	assert(colortimes(s64, nelem(s64)) == 5);
	assert(colortimes(s65, nelem(s65)) == 18);
	assert(colortimes(s66, nelem(s66)) == 72);
	assert(colortimes(s67, nelem(s67)) == 59);
	assert(colortimes(s68, nelem(s68)) == 25);
	assert(colortimes(s69, nelem(s69)) == 2);
	assert(colortimes(s70, nelem(s70)) == 39);
	assert(colortimes(s71, nelem(s71)) == 6);
	assert(colortimes(s72, nelem(s72)) == 59);
	assert(colortimes(s73, nelem(s73)) == 8);
	assert(colortimes(s74, nelem(s74)) == 85);

	return 0;
}
