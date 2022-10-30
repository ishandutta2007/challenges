/*

Given an RGB(A) CSS color, determine whether its format is valid or not. Create a function that takes a string (e.g. "rgb(0, 0, 0)") and return true if it's format is correct, otherwise return false.

Notes

There are a few edge cases. Check out the Tests tab to know more.

*/
#include <stdio.h>
#include <math.h>

int
between(double r, double g, double b, double a, double l)
{
	double c[4] = {r, g, b, a};
	int i;

	for (i = 0; i < 4; i++) {
		if (ceil(c[i]) - floor(c[i]) == 0) {
			if (!(0 <= c[i] && c[i] <= l))
				return 0;
		} else if (!(0 <= c[i] && c[i] <= 1))
			return 0;
	}
	return 1;
}

int
validrgba(const char *s)
{
	double r, g, b, a;
	char c;

	a = 0;
	if (sscanf(s, "rgb( %lf , %lf , %lf %c", &r, &g, &b, &c) == 4)
		return between(r, g, b, a, 255) && c == ')';
	if (sscanf(s, "rgb( %lf%% , %lf%% , %lf%% %c", &r, &g, &b, &c) == 4)
		return between(r, g, b, a, 100) && c == ')';
	if (sscanf(s, "rgba( %lf , %lf , %lf , %lf %c", &r, &g, &b, &a, &c) == 5)
		return between(r, g, b, a, 255) && c == ')';
	if (sscanf(s, "rgba( %lf%% , %lf%% , %lf%% , %lf%% %c", &r, &g, &b, &a, &c) == 5)
		return between(r, g, b, a, 100) && c == ')';

	return 0;
}

int
main(void)
{
	printf("%d\n", validrgba("rgb(0,0,0)"));
	printf("%d\n", validrgba("rgb(255,255,255)"));
	printf("%d\n", validrgba("rgba(0,0,0,0)"));
	printf("%d\n", validrgba("rgba(255,255,255,1)"));
	printf("%d\n", validrgba("rgba(0,0,0,0.123456789)"));
	printf("%d\n", validrgba("rgba(0,0,0,0.8)"));
	printf("%d\n", validrgba("rgba(	0 , 127	, 255 , 0.1	)"));
	printf("%d\n", validrgba("rgb(0%,50%,100%)"));

	printf("%d\n", validrgba("rgb(0,,0)"));
	printf("%d\n", validrgba("rgb (0,0,0)"));
	printf("%d\n", validrgba("rgb(0,0,0,0)"));
	printf("%d\n", validrgba("rgba(0,0,0)"));
	printf("%d\n", validrgba("rgb(-1,0,0)"));
	printf("%d\n", validrgba("rgb(255,256,255)"));
	printf("%d\n", validrgba("rgb(100%,100%,101%)"));
	printf("%d\n", validrgba("rgba(0,0,0,-1)"));
	printf("%d\n", validrgba("rgba(0,0,0,1.1)"));

	return 0;
}
