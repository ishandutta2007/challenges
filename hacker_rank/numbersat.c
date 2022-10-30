// Given a string of digits, insert +, *, or concat adjacent digits to see if it equals the target value

#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <errno.h>
#include <limits.h>
#include <stdbool.h>

long binadd(long, long, bool *);
long binsub(long, long, bool *);

#define nelem(x) (sizeof(x) / sizeof(x[0]))

bool all;
bool brute;

void *
ecalloc(size_t nmemb, size_t size)
{
	void *p;

	p = calloc(nmemb, size);
	if (p == NULL) {
		perror("calloc");
		exit(1);
	}

	return p;
}

long
xatol(const char *str)
{
	char *endptr;
	bool err;
	long v;

	err = false;
	v = strtol(str, &endptr, 10);
	if ((errno == ERANGE && (v == LONG_MAX || v == LONG_MIN)) || (errno != 0 && v != 0)) {
		perror("strtol");
		err = true;
	} else if (endptr == str) {
		fprintf(stderr, "strtol: no digit were found: '%s'\n", str);
		err = true;
	} else if (*endptr != '\0') {
		fprintf(stderr, "strtol: further characters after number: '%s'\n", str);
		err = true;
	}

	if (err)
		exit(1);

	return v;
}

int
precedence(int op)
{
	switch (op) {
	case '+':
		return 0;
	case '*':
		return 1;
	case '.':
		return 2;
	}

	return -1;
}

long
binadd(long a, long b, bool *overflow)
{
	if (b < 0)
		return binsub(a, -b, overflow);

	if (LONG_MAX - b < a) {
		*overflow = true;
		return LONG_MAX;
	}

	return a + b;
}

long
binsub(long a, long b, bool *overflow)
{
	if (b < 0)
		return binadd(a, -b, overflow);

	if (LONG_MIN + b > a) {
		*overflow = true;
		return LONG_MIN;
	}

	return a - b;
}

long
binmul(long a, long b, bool *overflow)
{
	int sign;

	if (a == 0 || b == 0)
		return 0;

	sign = 1;
	if (a < 0) {
		a = -a;
		sign = -sign;
	}
	if (b < 0) {
		b = -b;
		sign = -sign;
	}

	if (LONG_MAX / b < a) {
		*overflow = true;
		return (sign > 0) ? LONG_MAX : LONG_MIN;
	}

	return sign * a * b;
}

long
binop(int op, long a, long b, bool *overflow)
{
	switch (op) {
	case '+':
		return binadd(a, b, overflow);

	case '*':
		return binmul(a, b, overflow);

	case '.':
		return binadd(binmul(a, 10, overflow), b, overflow);
	}

	return -1;
}

long
eval(const char *expr, long *operand, char *operator, bool *overflow)
{
	const char *p;
	size_t i, j;

	*overflow = false;
	if (expr == NULL)
		return 0;

	operand[0] = 0;
	i = j = 0;
	for (p = expr; *p != '\0'; p++) {
		switch (*p) {
		case '0':
		case '1':
		case '2':
		case '3':
		case '4':
		case '5':
		case '6':
		case '7':
		case '8':
		case '9':
			operand[i++] = *p - '0';
			break;

		case '+':
		case '*':
		case '.':
			while (j > 0 && precedence(operator[j - 1]) >= precedence(*p)) {
				assert(i >= 2);
				operand[i - 2] = binop(operator[j - 1], operand[i - 2], operand[i - 1], overflow);
				i--;
				j--;
			}
			operator[j++] = *p;
			break;

		default:
			assert(0);
		}
	}

	for (; j > 0; j--, i--) {
		assert(i >= 2);
		operand[i - 2] = binop(operator[j - 1], operand[i - 2], operand[i - 1], overflow);
	}

	assert(i == 1);

	return operand[0];
}

void
printsolution(const char *digit, long target, const char *array)
{
	const char *p;

	printf("\"%s\", %ld -> \"", digit, target);
	for (p = array; *p != '\0'; p++) {
		if (p[0] == '+' || p[0] == '*') {
			printf("%c", p[0]);
			continue;
		}

		assert(isdigit(p[0]));

		while (p[0] == '0' && p[1] == '.')
			p++;

		for (;;) {
			if (isdigit(p[0]))
				printf("%c", p[0]);

			if (p[1] != '.')
				break;

			p += 2;
		}
	}
	printf("\"\n");
}

bool
bruteforce(const char *digit, long target, bool all)
{
	static const char ops[] = {'+', '*', '.'};

	unsigned char *seq;
	char *expr, *operator;
	long *operand, value;
	size_t i, len, seqlen;
	bool overflow, ret;

	expr = NULL;
	operator= NULL;
	operand = NULL;
	seq = NULL;

	if (digit == NULL)
		goto nosolution;

	for (len = 0; digit[len] != '\0'; len++) {
		if (!isdigit(digit[len]))
			goto nosolution;
	}

	if (len == 0)
		goto nosolution;

	expr = ecalloc(len, sizeof(*expr) * 2);
	operand = ecalloc(len, sizeof(*operand));
	operator= ecalloc(len, sizeof(*operator));
	seq = ecalloc(len, sizeof(*seq));

	for (i = 0; i < len; i++) {
		expr[2 * i] = digit[i];
		expr[2 * i + 1] = ops[0];
	}
	expr[2 * (i - 1) + 1] = '\0';

	seqlen = len - 1;
	if (len != 1)
		len = len * 2 - 1;

	ret = false;
	for (;;) {
		value = eval(expr, operand, operator, &overflow);
		if (!overflow && value == target) {
			printsolution(digit, target, expr);
			ret = true;
			if (!all)
				break;
		}

		if (len == 1)
			break;

		for (i = 0; i < seqlen; i++) {
			if (++seq[i] >= nelem(ops))
				seq[i] = 0;
			else
				break;
		}

		for (i = 0; i < seqlen; i++) {
			if (seq[i] != 0)
				break;
		}
		if (i == seqlen)
			break;

		for (i = 0; i < seqlen; i++)
			expr[i * 2 + 1] = ops[seq[i]];
	}

	if (!ret)
		goto nosolution;

out:
	free(expr);
	free(operand);
	free(operator);
	free(seq);

	return ret;

nosolution:
	printf("\"%s\", %ld -> \"no solution\"\n", (digit) ? digit : "(nil)", target);
	ret = false;
	goto out;
}

void
dfs(const char *digits, char *expr, size_t n, size_t len, long target,
    long *operand, char *operator,
    const bool *zeroes,
    bool all, bool *found)
{
	long value;
	bool overflow, toobig;

	value = eval(expr, operand, operator, &overflow);
	if (n + 1 == len && !overflow && value == target) {
		printsolution(digits, target, expr);
		*found = true;
		return;
	}

	if (n + 1 == len)
		return;

	toobig = overflow || (value > target);
	if (toobig && !zeroes[n])
		return;

	expr[2 * n + 1] = '+';
	dfs(digits, expr, n + 1, len, target, operand, operator, zeroes, all, found);
	if (*found && !all)
		return;

	expr[2 * n + 1] = '*';
	dfs(digits, expr, n + 1, len, target, operand, operator, zeroes, all, found);
	if (*found && !all)
		return;

	expr[2 * n + 1] = '.';
	dfs(digits, expr, n + 1, len, target, operand, operator, zeroes, all, found);
	if (*found && !all)
		return;

	expr[2 * n + 1] = '\0';
}

bool
backtrack(const char *digits, long target, bool all)
{
	char *expr, *operator;
	long *operand;
	size_t i, j, len;
	bool *zeroes, found, ret;

	expr = NULL;
	operator= NULL;
	operand = NULL;
	zeroes = NULL;

	if (digits == NULL)
		goto nosolution;

	for (len = 0; digits[len] != '\0'; len++) {
		if (!isdigit(digits[len]))
			goto nosolution;
	}

	if (len == 0)
		goto nosolution;

	expr = ecalloc(len, sizeof(*expr) * 2);
	operand = ecalloc(len, sizeof(*operand));
	operator= ecalloc(len, sizeof(*operator));
	zeroes = ecalloc(len, sizeof(*zeroes));

	for (i = 0; i < len; i++) {
		expr[2 * i] = digits[i];
		expr[2 * i + 1] = '\0';
	}

	j = 0;
	for (i = 0; i < len; i++) {
		switch (digits[i]) {
		case '0':
			for (; j < i; j++)
				zeroes[j] = true;
			break;
		}
	}

	found = false;
	dfs(digits, expr, 0, len, target, operand, operator, zeroes, all, &found);
	if (!found)
		goto nosolution;

out:
	free(expr);
	free(operand);
	free(operator);
	free(zeroes);

	return ret;

nosolution:
	printf("\"%s\", %ld -> \"no solution\"\n", (digits) ? digits : "(nil)", target);
	ret = false;
	goto out;
}

bool
solve(const char *digits, long target)
{
	if (brute)
		return bruteforce(digits, target, all);

	return backtrack(digits, target, all);
}

void
usage(void)
{
	fprintf(stderr, "usage: [options] digits target\n");
	fprintf(stderr, "\t[-a all]        search for all solutions\n");
	fprintf(stderr, "\t[-b bruteforce] use the brute force algorithm instead of backtracking\n");
	fprintf(stderr, "\t[-h help]       prints this usage\n");
	exit(1);
}

int
main(int argc, char *argv[])
{
	int i;

	while (argc >= 2) {
		if (argv[1][0] != '-')
			break;

		for (i = 1; argv[1][i] != '\0'; i++) {
			switch (argv[1][i]) {
			case 'a':
				all = true;
				break;
			case 'b':
				brute = true;
				break;
			case 'h':
				usage();
				break;
			}
		}

		argc--;
		argv++;
	}

	if (argc >= 3) {
		solve(argv[1], xatol(argv[2]));
		return 0;
	}

	solve("1231231234", 11353);
	solve("3456237490", 1185);
	solve("3456237490", 9191);

	solve("0000", 0);
	solve("000", 10);
	solve("001", 1);
	solve("1", 1);
	solve("123", 7);
	solve("123456", 7);
	solve("392892482425", 19);
	solve("392945200141", 120);
	solve("-12", 3);
	solve(NULL, 10);
	solve("12208", -4);

	return 0;
}
