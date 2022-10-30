/*

You are given the scores of N students in three different subjects - Mathematics,*Physics* and Chemistry; 
all of which have been graded on a scale of 0 to 100.
Your task is to compute the Pearson product-moment correlation coefficient between the scores of different pairs of subjects (Mathematics and Physics, Physics and Chemistry, Mathematics and Chemistry) based on this data.
This data is based on the records of the CBSE K-12 Examination - a national school leaving examination in India, for the year 2013.

*/
#include <stdio.h>
#include <math.h>

#define nelem(x) (sizeof(x) / sizeof(x[0]))

double
mean(double *x, size_t n)
{
	double s;
	size_t i;

	s = 0;
	for (i = 0; i < n; i++)
		s += x[i];
	return s / n;
}

double
stddev(double *x, size_t n)
{
	double m, s;
	size_t i;

	m = mean(x, n);
	s = 0;
	for (i = 0; i < n; i++)
		s += (x[i] - m) * (x[i] - m);
	return sqrt(s / (n - 1));
}

double
cov(double *x, double *y, size_t n)
{
	double mx, my, s;
	size_t i;

	mx = mean(x, n);
	my = mean(y, n);
	s = 0;
	for (i = 0; i < n; i++)
		s += (x[i] - mx) * (y[i] - my);
	return s / (n - 1);
}

double
pearson(double *x, double *y, size_t n)
{
	return cov(x, y, n) / (stddev(x, n) * stddev(y, n));
}

int
main(void)
{
	double m[] = {
	    73,
	    48,
	    95,
	    95,
	    33,
	    47,
	    98,
	    91,
	    95,
	    93,
	    70,
	    85,
	    33,
	    47,
	    95,
	    84,
	    43,
	    95,
	    54,
	    72,
	};
	double p[] = {
	    72,
	    67,
	    92,
	    95,
	    59,
	    58,
	    95,
	    94,
	    84,
	    83,
	    70,
	    79,
	    67,
	    73,
	    87,
	    86,
	    63,
	    92,
	    80,
	    76,
	};
	double c[] = {
	    76,
	    76,
	    95,
	    96,
	    79,
	    74,
	    97,
	    97,
	    90,
	    90,
	    78,
	    91,
	    76,
	    90,
	    95,
	    95,
	    75,
	    100,
	    87,
	    90,
	};
	printf("%.2lf\n", pearson(m, p, nelem(m)));
	printf("%.2lf\n", pearson(p, c, nelem(p)));
	printf("%.2lf\n", pearson(c, m, nelem(c)));
	return 0;
}
