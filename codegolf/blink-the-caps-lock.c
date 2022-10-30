/*

Most computer keyboards feature a small integrated LED light, indicating the current input mode, as controlled with the CAPS LOCK button.

enter image description here

Your task is to blink it:

Turn it on;
Wait for 0.5 (+/-0.1) seconds;
Turn it off again.
Video footage of the LED blinking is highly appreciated !

Rules
You can blink a different LED (e.g. Scroll Lock, Num Lock, Wi-Fi status etc), if you wish, but it must be physically located on your keyboard;

If your language is missing a subsecond sleep command, your program may use a 1 second delay instead, at a penalty of +2 bytes (that's for 0.);

Your program must blink at least once, what happens afterward is up to you, i.e. it can continue to blink (in which case you must wait for the same delay, before turning it on again), or halt e.t.c.;

If the chosen LED is ON by default, on your system, you can assume that it has been explicitly switched off (e.g. manually), before the program is run;

This is code-golf, the shortest answer in bytes wins.

*/

#define _GNU_SOURCE
#include <stdio.h>
#include <time.h>
#include <err.h>
#include <X11/Xlib.h>
#include <X11/XKBlib.h>

enum {
	SCRLOCK = 1,
	CAPSLOCK = 2,
	NUMLOCK = 16,
};

int
toggle(Display *d, int led, int on)
{
	XkbLockModifiers(d, XkbUseCoreKbd, led, (on) ? led : 0);
	XFlush(d);
	return !on;
}

int
main(void)
{
	struct timespec rq;
	Display *d;
	int t;

	rq.tv_sec = 0;
	rq.tv_nsec = 500000000l;

	d = XOpenDisplay(NULL);
	if (!d)
		errx(1, "Failed to open X display");

	t = 1;
	for (;;) {
		printf("CAPSLOCK: %d\n", t);
		t = toggle(d, CAPSLOCK, t);
		clock_nanosleep(CLOCK_MONOTONIC, 0, &rq, NULL);
	}
	XCloseDisplay(d);
	return 0;
}
