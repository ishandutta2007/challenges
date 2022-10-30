/*

Create a virtual machine. Cause the virtual machine to enter an unbootable state, also known as 'bricked'.
Do so using the least possible characters in the language of your choice.

*/

typedef struct {
	unsigned bricked;
	unsigned pc;
} Computer;

void
reset(Computer *c)
{
	c->bricked = 1;
	c->pc = 0;
}

void
run(Computer *c)
{
	for (;;) {
		if (c->bricked) {
			c->pc = 0;
			continue;
		}

		c->pc++;
	}
}

int
main(void)
{
	Computer c[1];

	reset(c);
	run(c);

	return 0;
}
