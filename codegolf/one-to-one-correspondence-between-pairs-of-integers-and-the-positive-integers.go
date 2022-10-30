/*

It is well-known that there are one-to-one correspondences between pairs of integers and the positive integers. Your task is to write code defining such a correspondence (by defining a pair of functions/programs that are inverses of each other) in your programming language of choice, plus a correctness check (see below) with the smallest number of bytes for the correspondence definition (not taking the correctness check into account).

The solution must include :

    the definition of a function/program f having two integer arguments and returning an integer (that's one direction of the bijection).

    either the definition of a function/program g having one integer argument and returning a pair of integers (might be an array, a list, the concatenation of the two integers separated by something ...) or two functions/programs a and b having an integer argument and returning an integer (that's the other direction).

    an additional code snippet checking that for the f and g (or f and a,b) you defined above, you have g(f(x,y))=(x,y) (or a(f(x,y))=x and b(f(x,y))=y) for any integers x,y in the range -100 < x < 100,-100 < y < 100. Note that f and g have to work for values outside of this range as well.

You may rename a,b,f or g of course. The two solutions do not have to be written in the same language.

Below is a not-optimal-at-all solution in PARI/GP, with 597 characters for the function definitions.

plane_to_line(x,y)={
my(ax,ay,z);
ax=abs(x);
ay=abs(y);
if((ax<=ay)*(y<0),        z=4*y*y-2*y+x+2;);
if((ax<=ay)*(y>=0),       z=4*y*y-2*y-x+2;);
if((ay<=ax)*(x<0),        z=4*x*x    -y+2;);
if((ay<=ax)*(x>=0)*(y<0), z=4*x*x+4*x+y+2;);
if((ay<=ax)*(x>=0)*(y>=0),z=4*x*x-4*x+y+2;);
if((x==0)*(y==0),z=1;);
return(z);
}


line_to_plane(z)={
my(l,d,x,y);
l=floor((1+sqrt(z-1))/2);
d=z-(4*l*l-4*l+2);
if(d<=l,x=l;y=d;);
if((l<d)*(d<=3*l),x=2*l-d;y=l;);
if((3*l<d)*(d<=5*l),x=(-l);y=4*l-d;);
if((5*l<d)*(d<=7*l),x=d-6*l;y=(-l););
if((7*l<d)*(d<8*l) ,x=l;y=d-8*l;);
if(z==1,x=0;y=0;);
return([x,y]);
}

and the correctness-check code :

accu=List([])
m=100;
for(x=-m,m,for(y=-m,m,if(line_to_plane(plane_to_line(x,y))!=[x,y],\
listput(accu,[x,y]);)))
Vec(accu)

*/

package main

import (
	"fmt"
	"math"
)

func main() {
	const N = 10000
	for y := -N; y <= N; y++ {
		for x := -N; x <= N; x++ {
			nx, ny := line2plane(plane2line(x, y))
			if x != nx || y != ny {
				fmt.Println("MISMATCH:", x, y, nx, ny)
			}
		}
	}
}

func plane2line(x, y int) (z int) {
	ax := abs(x)
	ay := abs(y)
	switch {
	case x == 0 && y == 0:
		z = 1
	case ax <= ay && y < 0:
		z = 4*y*y - 2*y + x + 2
	case ax <= ay && y >= 0:
		z = 4*y*y - 2*y - x + 2
	case ay <= ax && x < 0:
		z = 4*x*x - y + 2
	case ay <= ax && x >= 0 && y < 0:
		z = 4*x*x + 4*x + y + 2
	case ay <= ax && x >= 0 && y >= 0:
		z = 4*x*x - 4*x + y + 2
	}
	return
}

func line2plane(z int) (x, y int) {
	l := int((1 + math.Sqrt(float64(z)-1)) / 2)
	d := z - (4*l*l - 4*l + 2)
	switch {
	case z == 1:
		x, y = 0, 0
	case d <= l:
		x, y = l, d
	case l < d && d <= 3*l:
		x, y = 2*l-d, l
	case 3*l < d && d <= 5*l:
		x, y = -l, 4*l-d
	case 5*l < d && d <= 7*l:
		x, y = d-6*l, -l
	case 7*l < d && d < 8*l:
		x, y = l, d-8*l
	}
	return
}

func abs(x int) int {
	if x < 0 {
		x = -x
	}
	return x
}
