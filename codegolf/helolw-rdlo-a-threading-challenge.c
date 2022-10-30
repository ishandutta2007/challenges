/*

I have a challenge for you:

    Print "Hello World" using any language.
    Each character must be printed from its own, unique thread

That's it. Obviously, as there's no guarantee that the threads will operate in the order you start them, you have to make your program thread safe to ensure the output is printed in the right order.

And, because this is code golf, the shortest program wins.

Update:

The winner is Marinus' APL entry, at 34 characters. It also wins the prize for the least readable entry.

*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <threads.h>

typedef struct {
	char *b;
	char c;
} ch_t;

int
worker(void *ud)
{
	ch_t *ch;

	ch = ud;
	ch->b[0] = ch->c;
	return 0;
}

char *
thrstr(const char *s)
{
	thrd_t *th;
	ch_t *ch;
	char *b;
	size_t i, n;

	n = strlen(s);
	b = calloc(n + 1, sizeof(*b));
	ch = calloc(n, sizeof(*ch));
	th = calloc(n, sizeof(*th));
	if (!b || !ch || !th)
		goto error;

	for (i = 0; i < n; i++) {
		ch[i].b = b + i;
		ch[i].c = s[i];
		thrd_create(&th[i], worker, &ch[i]);
	}
	for (i = 0; i < n; i++)
		thrd_join(th[i], NULL);

	if (0) {
	error:
		free(b);
		b = NULL;
	}
	free(ch);
	free(th);

	return b;
}

void
test(const char *s)
{
	char *p;

	p = thrstr(s);
	if (p) {
		printf("%s\n", p);
		free(p);
	}
}

int
main(void)
{
	test("Hello World");
	return 0;
}
