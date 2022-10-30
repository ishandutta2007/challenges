/*

This wasn't originally intended for code-golf, just as a little debugging routine to roughly visualize something "goofy" going on in a model of some (irrelevant here) physical process.
But when I saw how surprisingly short it was, compared to my expectations, I just wondered if it can be further shortened. And that's primarily with respect to #statements (rather than #chars just by shortening variable names).

So, the function's void asciigraph ( double *f, int n ) where f[] contains n doubles representing values of some more-or-less continuous function to be illustrated/graphed on your terminal.
My implementation is below, along with a test driver, whose output is below that. Can you do better/shorter?...

#include <stdio.h>
#include <math.h>
// --- entry point ---
void asciigraph ( double *f, int n ) {
  int    row=0,nrows=24, col=0,ncols=78;
  double bigf=0.0;
  for ( col=0; col<n; col++ )
    if ( fabs(f[col]) > bigf ) bigf = fabs(f[col]);
  for ( row=0; row<nrows; row++ ) {
    double yval = bigf*((double)(nrows/2-row))/((double)(nrows/2));
    for ( col=0; col<ncols; col++ )
      printf("%c",(yval*f[(col*(n-1))/(ncols-1)]>=yval*yval? '*':' '));
    printf("\n"); }
  } // --- end-of-function asciigraph()

#ifdef TESTDRIVE
int main ( int argc, char *argv[] ) {
  double f[999], pi=3.14159;    // stored function to be graphed
  int    i=0, N=511;            // f[] index
  void   asciigraph();
  for ( i=0; i<N; i++ ) {
    double x = 2.0*pi*((double)i)/((double)(N-1));
    f[i] = .5*sin(2.*x+pi/3.) + 1.*sin(1.*x+pi/2.); }
  asciigraph(f,N);
  } // --- end-of-function main() ---
#endif

Compile it (for linux) as cc -DTESTDRIVE asciigraph.c -lm -o asciigraph and then the sample output is

******                                                                      **
********                                                                  ****
*********                                                                *****
**********                                                              ******
***********                                                            *******
************                                                          ********
*************                                                        *********
*************                                                       **********
**************                                                     ***********
***************                                                   ************
****************                                                 *************
******************************************************************************
                  *********************************************
                  *******************************************
                   *****************************************
                    *********************          *****
                     *****************
                       ************
                         ********
So, the eleven lines comprising asciigraph() above can be reduced two ways:
(a) just "syntactically compressing" the code (e.g., put the final } on the same line as the final statement), or
(b) by finding a niftier algorithm than mine, which compares each f-value to the yval "level line" (in which case maybe your algorithm wouldn't need to find that bigf at all).
Obviously (I'd think it's obvious), the "niftier algorithm" approach is what I'm more interested in.

Replacing the test driver with the following will yield a moving wave:

int main ( int argc, char *argv[] ) {
  double f[999], pi=3.14159;            // stored function to be graphed
  double t=0.0, dt=0.05, w1=16.,w2=3.;  int Nt=50;
  int    i=0, N=511;                    // f[] index
  void   asciigraph();
  while ( --Nt > 0 ) {
    for ( i=0; i<N; i++ ) {
      double x = 2.0*pi*((double)i)/((double)(N-1));
      f[i] = .75*sin(2.*x+pi/3.+w1*t) + 1.*sin(1.*x+pi/2.+w2*t); }
    system("sleep 0.25; clear");
    asciigraph(f,N);
    t += dt; }
  } // --- end-of-function main() ---

*/

package main

import (
	"fmt"
	"math"
)

func main() {
	f := make([]float64, 511)
	N := len(f)
	for i := range f {
		x := 2 * math.Pi * float64(i) / float64(N-1)
		f[i] = 0.5*math.Sin(2.0*x+math.Pi/3.0) + 1.0*math.Sin(1.0*x+math.Pi/2.0)
	}
	asciigraph(f)
}

func asciigraph(f []float64) {
	const (
		ROWS = 24
		COLS = 78
	)

	ymax := 0.0
	for _, v := range f {
		v = math.Abs(v)
		if v > ymax {
			ymax = v
		}
	}

	n := len(f)
	for r := 0; r < ROWS; r++ {
		y := ymax * (float64(ROWS/2 - r)) / (float64(ROWS / 2))
		for c := 0; c < COLS; c++ {
			if y*f[(c*(n-1))/(COLS-1)] >= y*y {
				fmt.Printf("*")
			} else {
				fmt.Printf(" ")
			}
		}
		fmt.Printf("\n")
	}
}
