/*

You've gotten out of Earth's gravity well - good for you! However, you're feeling a bit uncomfortable in zero-gravity, and you want to replicate 1 g of force in a centrifuge.
Use the equation for force in a centrifuge:
RCF = r_m*(2*pi*N_rpm/60)^2 / g
Where

RCF is "relative centrifugal force", or the force relative to 1 g; in this case we want this to be 1.
rm is the radius of the centrifuge in meters. You can take this, or a similar quantity - for example, taking it in millimeters.
NRPM is the rotational speed in revolutions per minute. You're going to output this.
g is the local gravitational field of Earth - for this challenge, use the standard value of 9.80665m/s2.
In alternate form, when RCF=1:
NRPM = 60*sqrt(g/r_m)/(2*pi)

To clarify: take the radius of the centrifuge, output rotational speed in RPMs, with precision to 6 significant digits. Scoring is standard for code-golf. Test cases (calculated using SpinCalc):

1 -> 29.904167719726267
10 -> 9.456528152601877
50 -> 4.229087956071661
87 -> 3.206063305621029
100 -> 2.9904167719726273
103 -> 2.946545199338184
167 -> 2.314053973112157
200 -> 2.1145439780358304
224 -> 1.9980562507828685
250 -> 1.8913056305203755
264 -> 1.8404742955585696
300 -> 1.726517928287568
328 -> 1.651181438643768
400 -> 1.4952083859863137
409 -> 1.4786659280153986
1000 -> 0.9456528152601877
2000 -> 0.6686775183186282
10000 -> 0.2990416771972627

*/

#define _GNU_SOURCE
#include <assert.h>
#include <stdio.h>
#include <math.h>

double
rpms(double r)
{
	static const double g = 9.80665;
	return (60 * sqrt(g / r)) / (2 * M_PI);
}

void
test(double r, double p)
{
	double v;

	v = rpms(r);
	printf("%f\n", v);
	assert(fabs(v - p) < 1e-12);
}

int
main(void)
{
	test(1, 29.904167719726267);
	test(10, 9.456528152601877);
	test(50, 4.229087956071661);
	test(87, 3.206063305621029);
	test(100, 2.9904167719726273);
	test(103, 2.946545199338184);
	test(167, 2.314053973112157);
	test(200, 2.1145439780358304);
	test(224, 1.9980562507828685);
	test(250, 1.8913056305203755);
	test(264, 1.8404742955585696);
	test(300, 1.726517928287568);
	test(400, 1.4952083859863137);
	test(409, 1.4786659280153986);
	test(1000, 0.9456528152601877);
	test(2000, 0.6686775183186282);
	test(10000, 0.2990416771972627);

	return 0;
}
