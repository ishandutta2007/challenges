%{

Inspired by this video of Infinite Series.
Introduction

Pi is defined as the ratio of the circumference to the diameter of a circle. But how is a circle defined? Usually a circle is defined as the points with constant distance to the centerpoint (let us assume that the center is at (0,0)).
The next question would be: How do we define the distance? In the following we are considering different notions of distances (induced by the Lp-norms):

Given a norm (=something that measures a length) we can easily construct a distance (=distance between two points) as follows:

dist(A,B) := norm (A-B)

The euclidean norm is given by:

norm((x,y)) = (x^2 + y^2)^(1/2)

This is also called the L2-norm. The other Lp-norms are constructed by replacing the 2 in the above formula by other values between 1 and infinity:

norm_p((x,y)) = (|x|^p + |y|^p)^(1/p)

The unit circles for those different norms have quite distinct shapes:

Challenge

Given a p >= 1, calculate the ratio of circumference to diameter of a Lp-circle with respect to the Lp-norm with an accuracy of four significant figures.
Testcases

We can use that for p,q with 1 = 1/p + 1/q we get the same ratio for the Lp as well as the Lq norm. Furthermore for p = q = 2 the ratio is minimal, and for p = 1, q = infinity we get a ratio of 4, so the ratios are always between pi and 4.

p   or  q            ratio
1       infinity     4
2       2            3.141592
1.623   2.60513      3.200
1.5     3            3.25976
4       1.33333      3.39693

%}

% https://math.stackexchange.com/questions/254620/pi-in-arbitrary-metric-spaces
function r = pim(p)
	f = @(u) (u**(1-p) + (1-u)**(1-p))**(1/p);
	r = 2/p * quad(f, 0, 1);
end

pim(1)
pim(2)
pim(1.623)
pim(1.5)
pim(4)
