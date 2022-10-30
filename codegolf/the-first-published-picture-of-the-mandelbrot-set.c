/*

Here’s the picture of the first published picture of the Mandelbrot set.

Use the fewest bytes possible to write a program or function that outputs the following.

the Mandelbrot set

A trailing new line is permitted. Character * cannot be replaced by any other character.

Useful information: Center is (−0.75,0), Δx=0.035, and Δy=1.66Δx. Iteration count is 250.

As text (for checking):

                                                     *
                                                   ****
                                                  ******
                                                   *****
                                              * *********
                                         *** ****************
                                           ******************** **
                                        *************************
                                       ****************************
                                     *******************************
                                     ******************************
                        * *****     ********************************
                       ***********  ********************************
                      ************* *******************************
                  ** ************** ******************************
****************************************************************
                  ** ************** ******************************
                      ************* *******************************
                       ***********  ********************************
                        * *****     ********************************
                                     ******************************
                                     *******************************
                                       ****************************
                                        *************************
                                           ******************** **
                                         *** ****************
                                              * *********
                                                   *****
                                                  ******
                                                   ****
                                                     *

Thanks @Sisyphus for providing the parameters.

*/

#include <stdio.h>
#include <complex.h>

void
mandelbrot(int w, int h, double complex c, double complex s, int n)
{
	double complex z0, z;
	double x, y, dx, dy;
	int i, j, k;

	dx = creal(s);
	dy = cimag(s);

	y = cimag(c) - dy * h / 2;
	for (i = 0; i < h; i++) {
		x = creal(c) - dx * w / 2;
		for (j = 0; j < w; j++) {
			z0 = x + y * I;
			z = 0;
			for (k = 0; k < n; k++) {
				if (cabs(z) > 2)
					break;
				z = (z * z) + z0;
			}
			printf("%c", (k >= n) ? '*' : ' ');
			x += dx;
		}
		printf("\n");
		y += dy;
	}
}

int
main(void)
{
	mandelbrot(68, 32, -0.75, 0.035 + 0.0581 * I, 250);
	return 0;
}
