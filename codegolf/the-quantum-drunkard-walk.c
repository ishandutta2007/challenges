/*

It is well known that a person on a grid under the influence of alcohol has an equal chance of going in any available directions.
However, this common-sense statement does not hold in the realm of very small drunkards, whose behavior is very much as if they take every available path at once, and the possible paths they take can interfere with each other.
Your task is to display the possible positions of such a quantum drunkard after n steps.
Specification

The drunkard in question occupies a square grid, and may be considered to be a 3-state cellular automaton using a Von Neumann (plus-shaped) neighborhood which follows these simple rules:

    Empty goes to Awake if it is adjacent to exactly one Awake, and otherwise goes to Empty
    Awake goes to Sleeping
    Sleeping goes to Sleeping

The initial state of the board is a single Awake surrounded by an infinite field of Emptys.
Challenge

Given a nonnegative integer n, create an ASCII representation of the drunkard after n steps. Each state should be represented by a different character, and solutions should state which character means which state.
If you use spaces for Empty, you don't need to include a run of them at the end of a line.

This is code-golf, so shortest answer wins. Standard loopholes apply, leading and trailing whitespace is allowed, string array/2d char array output is allowed, etc.
Examples

These examples use for Empty, @ for Awake, and # for Sleeping.

n=0
@

n = 1
 @
@#@
 @

n = 2
  @
  #
@###@
  #
  @

n = 3
   @
  @#@
 @ # @
@#####@
 @ # @
  @#@
   @

n=6

      @
      # 
    @###@
     @#@  
  @  ###  @
  #@# # #@#
@###########@
  #@# # #@#
  @  ###  @
     @#@
    @###@
      #
      @

n=10
          @
          #
        @###@
         @#@
         ###
        # # #
       #######
      #  ###  #
  @  ##  ###  ##  @
  #@# ### # ### #@#
@###################@
  #@# ### # ### #@#
  @  ##  ###  ##  @
      #  ###  #
       #######
        # # #
         ###
         @#@
        @###@
          #
          @

Interesting Note

By looking up the sequence of the number of occupied cells in the OEIS, I found that the quantum drunkard is isomorphic to the much better-studied toothpick sequence. If you can incorporate that knowledge into a better golf, I will be suitably impressed.

*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <errno.h>

typedef struct {
	int w, h;
	char *p;
} FB;

int
alloc(FB *fb, int w, int h)
{
	fb->p = calloc(w, h);
	if (!fb->p)
		return -errno;
	fb->w = w;
	fb->h = h;
	return 0;
}

void
dealloc(FB *fb)
{
	if (!fb)
		return;
	free(fb->p);
}

int
at(FB *fb, int x, int y)
{
	if (x < 0 || y < 0 || x >= fb->w || y >= fb->h)
		return 0;
	return fb->p[y * fb->w + x];
}

void
set(FB *fb, int x, int y, int c)
{
	if (x < 0 || y < 0 || x >= fb->w || y >= fb->h)
		return;
	fb->p[y * fb->w + x] = c;
}

void
clear(FB *fb, int c)
{
	int x, y;

	for (y = 0; y < fb->h; y++) {
		for (x = 0; x < fb->w; x++)
			set(fb, x, y, c);
	}
}

void
reset(FB *fb)
{
	clear(fb, ' ');
	set(fb, fb->w / 2, fb->h / 2, '@');
}

void
evolve(FB *rp, FB *wp)
{
	int x, y, c;

	for (y = 0; y < rp->h; y++) {
		for (x = 0; x < rp->w; x++) {
			switch (at(rp, x, y)) {
			case ' ':
				c = (at(rp, x - 1, y) == '@');
				c += (at(rp, x, y - 1) == '@');
				c += (at(rp, x + 1, y) == '@');
				c += (at(rp, x, y + 1) == '@');
				set(wp, x, y, (c == 1) ? '@' : ' ');
				break;

			case '@':
			case '#':
				set(wp, x, y, '#');
				break;
			}
		}
	}
	memcpy(rp->p, wp->p, rp->w * rp->h);
}

void
draw(FB *fb)
{
	int x, y;

	for (y = 0; y < fb->h; y++) {
		for (x = 0; x < fb->w; x++)
			printf("%c", at(fb, x, y));
		printf("\n");
	}
}

int
drunkard(int n)
{
	FB rp[1], wp[1];
	int i, r, s;

	if (n < 0)
		return -1;

	s = 2 * n + 1;
	r = alloc(rp, s, s);
	r |= alloc(wp, s, s);
	if (r)
		goto error;

	reset(rp);
	for (i = 0; i < n; i++)
		evolve(rp, wp);

	printf("n=%d\n", n);
	draw(rp);
	printf("\n");

	if (0) {
	error:
		r = -errno;
	}

	dealloc(rp);
	dealloc(wp);
	return r;
}

int
main(void)
{
	int i;

	for (i = 0; i <= 10; i++)
		drunkard(i);
	return 0;
}
