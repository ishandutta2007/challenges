%{

Ram wants to generate some prime numbers for his cryptosystem. Help him please! Your task is to generate all prime numbers between two given numbers.

Input

The first line contains t, the number of test cases (less then or equal to 10).
Followed by t lines which contain two numbers m and n (1 <= m <= n <= 1000000000, n-m<=100000) separated by a space.

Output

For every test case print all prime numbers p such that m <= p <= n, one number per line. Separate the answers for each test case by an empty line.

%}

function p = primerange(m, n)
	p = primes(n);
	p = p(p >= m);
end

primerange(1, 10)
primerange(3, 5)
