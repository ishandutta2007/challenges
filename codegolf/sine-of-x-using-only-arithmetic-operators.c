/*

The challenge.

Implement a sin function without using any builtin sin function. The sin function must be implemented using only these +, -, ×, ÷ (basic arithmetic operators) and must have an accuracy of upto 3 decimal places.
NOTE: Other functions like exponentiation and factorial etc; are just other forms of the 4 arithmetic operators; so they are allowed

Example

NOTE: The input is radians and the range is -2π to 2π

sin(π)     ->  0.000
sin(3*π/2) -> -1.000
sin(π/2)   ->  1.000
sin(1)     ->  0.841

Rules

    The program which you write will be provided an input (in radians) from the STDIN and the program must output on the STDOUT.
    This is code golf; the answer with the shortest amount of bytes wins.
    Use any programming language you like / are familiar with.
    Standard rules apply for your answer, so you are allowed to use STDIN/STDOUT, functions/method with the proper parameters and return-type, full programs.
    Default Loopholes are forbidden.
    If possible, please add a link with a test for your code.
    Also, please add an explanation.

*/

#define _GNU_SOURCE
#include <stdio.h>
#include <math.h>

// https://gist.github.com/publik-void/067f7f2fef32dbe5c27d6e215f824c91#sin-abs-error-minimized-degree-33
// 33 degree abs error min
double
xsin(double x)
{
	double x1, x2;

	x1 = x;
	x2 = x * x;
	return x1 * (1. + x2 * (-0.166666666666666666666666666666666667 + x2 * (0.00833333333333333333333333333333333333 + x2 * (-0.000198412698412698412698412698412698391 + x2 * (2.75573192239858906525573192239844806e-6 + x2 * (-2.50521083854417187750521083848472947e-8 + x2 * (1.60590438368216145993923769996397832e-10 + x2 * (-7.64716373181981647590109722915908442e-13 + x2 * (2.81145725434552076319376582531091405e-15 + x2 * (-8.22063524662432971120933376991172232e-18 + x2 * (1.95729410633912564384267263771198416e-20 + x2 * (-3.86817017063038299631930987571173923e-23 + x2 * (6.4469502842428826022931795893278841e-26 + x2 * (-9.18368981471916803573077288615983239e-29 + x2 * (1.13099507260187617461053670403005966e-31 + x2 * (-1.21592124202981493418420109807105932e-34 + 1.1309232145353729608313042496143056e-37 * x2))))))))))))))));
}

int
main(void)
{
	printf("%.3f\n", xsin(M_PI));
	printf("%.3f\n", xsin(3 * M_PI / 2));
	printf("%.3f\n", xsin(M_PI / 2));
	printf("%.3f\n", xsin(1));

	return 0;
}
