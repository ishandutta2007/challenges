/*

Given a string S that only contains "I" (increase) or "D" (decrease), let N = S.length.

Return any permutation A of [0, 1, ..., N] such that for all i = 0, ..., N-1:

    If S[i] == "I", then A[i] < A[i+1]
    If S[i] == "D", then A[i] > A[i+1]

Note:

    1 <= S.length <= 10000
    S only contains characters "I" or "D".

*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void
print(int *a, size_t n)
{
	size_t i;

	for (i = 0; i < n; i++)
		printf("%d ", a[i]);
	printf("\n");
}

int *
dimatch(const char *s, size_t *l)
{
	size_t i, j, k, n;
	int *p;

	n = *l = strlen(s) + 1;
	p = calloc(n, sizeof(*p));
	if (p == NULL) {
		*l = 0;
		return NULL;
	}

	j = 0;
	k = n - 1;
	for (i = 0; i < n; i++) {
		if (s[i] == 'I')
			p[i] = j++;
		else if (s[i] == 'D')
			p[i] = k--;
		else
			p[i] = j;
	}
	return p;
}

void
test(const char *s)
{
	int *p;
	size_t n;

	p = dimatch(s, &n);
	print(p, n);
	free(p);
}

int
main(void)
{
	test("IDID");
	test("III");
	test("DDI");
	test("IDIDIDIDIDIII");
	test("IIIDDD");
	test("DDDIIID");
	return 0;
}
