/*

Your open-plan office building has a scrolling message screen on the far wall. One day, you notice that the messages are starting to glitch. Some of the lower case letters are being replaced by their position in the alphabet ("a" = 1, "b" = 2, ..., "z" = 26). Given the glitched text, return the corrected message.

Notes

Each group of numbers will always refer to one letter only (e.g. 14 = "n", not "ad").

*/

#include <assert.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

char *
deglitch(char *s)
{
	char b[3];
	size_t i, j;

	for (i = j = 0; s[i]; i++) {
		if (isdigit(s[i])) {
			b[0] = s[i];
			b[1] = b[2] = '\0';
			if (isdigit(s[i + 1]))
				b[1] = s[++i];

			s[j++] = 'a' + atoi(b) - 1;
		} else
			s[j++] = s[i];
	}
	s[j] = '\0';
	return s;
}

int
main(void)
{
	char s1[] = "T8e c1f5 23i12l b5 3l15s9n7 5a18l25 15n T8u18s4a25. L1s20 6o15d o18d5r19 1t n15o14.";
	char t1[] = "The cafe will be closing early on Thursday. Last food orders at noon.";

	char s2[] = "H5a22y s14o23 6o18e3a19t f15r t8i19 5v5n9n7. B5 3a18e6u12 15n t8e r15a4s!";
	char t2[] = "Heavy snow forecast for this evening. Be careful on the roads!";

	char s3[] = "T8r5e n5w c1r p1r11i14g p1s19e19 1r5 1v1i12a2l5. S16e1k t15 19e3u18i20y i6 9n20e18e19t5d.";
	char t3[] = "Three new car parking passes are available. Speak to security if interested.";

	char s4[] = "V15l21n20e5r19 18e17u9r5d t15 15r7a14i19e t8e C8r9s20m1s p1r20y.";
	char t4[] = "Volunteers required to organise the Christmas party.";

	char s5[] = "A b12a3k w1l12e20 8a19 2e5n f15u14d o21t19i4e. Pl5a19e c15n20a3t HR 20o r5c12a9m.";
	char t5[] = "A black wallet has been found outside. Please contact HR to reclaim.";

	char s6[] = "C12i5n20s w9l12 2e v9s9t9n7 20h5 6i6t8 6l15o18 20h9s a6t5r14o15n. Re13o22e a14y c15n6i4e14t9a12 4o3u13e14t19 6r15m v9e23.";
	char t6[] = "Clients will be visiting the fifth floor this afternoon. Remove any confidential documents from view.";

	char s7[] = "T8e18e a18e l5f20-15v5r d15u7h14u20s a20 18e3e16t9o14. F9r19t-c15m5, f9r19t-s5r22e.";
	char t7[] = "There are left-over doughnuts at reception. First-come, first-serve.";

	char s8[] = "R5m5m2e18 20o w1s8 1n25 13u7s l5f20 9n t8e k9t3h5n19.";
	char t8[] = "Remember to wash any mugs left in the kitchens.";

	char s9[] = "T8e w5e11l25 6i18e a12a18m t5s20 23i12l n15w b5 15n W5d14e19d1y m15r14i14g19.";
	char t9[] = "The weekly fire alarm test will now be on Wednesday mornings.";

	char s10[] = "N5w p18o4u3t l1u14c8 14e24t m15n20h! De20a9l19 20o f15l12o23.";
	char t10[] = "New product launch next month! Details to follow.";

	char s11[] = "S5c15n4 18e13i14d5r: 4o14'20 13i3r15w1v5 6i19h i14 20h5 20h9r4 6l15o18 11i20c8e14. S5r9o21s12y, 13y c21b9c12e i19 18i7h20 14e24t d15o18.";
	char t11[] = "Second reminder: don't microwave fish in the third floor kitchen. Seriously, my cubicle is right next door.";

	char s12[] = "N5w b21s9n5s19 3a18d19 1r5 1v1i12a2l5. P12e1s5 3o14t1c20 25o21r l9n5 13a14a7e18 6o18 4e20a9l19.";
	char t12[] = "New business cards are available. Please contact your line manager for details.";

	char s13[] = "D21e t15 20h5 9n3i4e14t l1s20 13o14t8, d18e19s-d15w14 Fr9d1y h1s b5e14 20e13p15r1r9l25 3a14c5l12e4.";
	char t13[] = "Due to the incident last month, dress-down Friday has been temporarily cancelled.";

	char s14[] = "T8e s5c15n4 6l15o18 16h15t15c15p9e18 9s o21t o6 19e18v9c5 (a7a9n). A14 5n7i14e5r h1s b5e14 3a12l5d.";
	char t14[] = "The second floor photocopier is out of service (again). An engineer has been called.";

	char s15[] = "A f18i5n4l25 18e13i14d5r t8a20 16h15t15c15p25i14g a14y n15n-p1p5r i20e13s i19 19t18i3t12y p18o8i2i20e4.";
	char t15[] = "A friendly reminder that photocopying any non-paper items is strictly prohibited.";

	char s16[] = "I n15w k14o23 20h5 16e18s15n t8a20'19 2e5n m9c18o23a22i14g t8e f9s8. I'l12 8u14t y15u d15w14 1n4 5n4 25o21 9f i20 8a16p5n19 1g1i14. I r5t9r5 14e24t w5e11, s15 I'22e n15t8i14g t15 12o19e a14d a12l t8e t9m5 9n t8e w15r12d.";
	char t16[] = "I now know the person that's been microwaving the fish. I'll hunt you down and end you if it happens again. I retire next week, so I've nothing to lose and all the time in the world.";

	assert(!strcmp(deglitch(s1), t1));
	assert(!strcmp(deglitch(s2), t2));
	assert(!strcmp(deglitch(s3), t3));
	assert(!strcmp(deglitch(s4), t4));
	assert(!strcmp(deglitch(s5), t5));
	assert(!strcmp(deglitch(s6), t6));
	assert(!strcmp(deglitch(s7), t7));
	assert(!strcmp(deglitch(s8), t8));
	assert(!strcmp(deglitch(s9), t9));
	assert(!strcmp(deglitch(s10), t10));
	assert(!strcmp(deglitch(s11), t11));
	assert(!strcmp(deglitch(s12), t12));
	assert(!strcmp(deglitch(s13), t13));
	assert(!strcmp(deglitch(s14), t14));
	assert(!strcmp(deglitch(s15), t15));
	assert(!strcmp(deglitch(s16), t16));

	return 0;
}
