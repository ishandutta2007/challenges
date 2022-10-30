/*

Description

You just got a new garage door installed by the Automata™ Garage Door Company. You are having a lot of fun playing with the remote clicker, opening and closing the door, scaring your pets and annoying the neighbors.

The clicker is a one-button remote that works like this:

    If the door is OPEN or CLOSED, clicking the button will cause the door to move, until it completes the cycle of opening or closing.

    Door: Closed -> Button clicked -> Door: Opening -> Cycle complete -> Door: Open.

    If the door is currently opening or closing, clicking the button will make the door stop where it is. When clicked again, the door will go the opposite direction, until complete or the button is clicked again.

We will assume the initial state is CLOSED.
Formal Inputs & Outputs
Input description

Input will be a series of commands (can be hard coded, no need to parse):

button_clicked
cycle_complete
button_clicked
button_clicked
button_clicked
button_clicked
button_clicked
cycle_complete

Output description

Output should be the state of the door and the input commands, such as:

Door: CLOSED
> Button clicked.
Door: OPENING
> Cycle complete.
Door: OPEN
> Button clicked.
Door: CLOSING
> Button clicked.
Door: STOPPED_WHILE_CLOSING
> Button clicked.
Door: OPENING
> Button clicked.
Door: STOPPED_WHILE_OPENING
> Button clicked.
Door: CLOSING
> Cycle complete.
Door: CLOSED

Notes/Hints

This is an example of a simple Finite State Machine with 6 States and 2 inputs.
Bonus

Bonus challenge - The door has an infrared beam near the bottom, and if something is breaking the beam, (your car, your cat, or a baby in a stroller) the door will be BLOCKED and will add the following rules:

    If the door is currently CLOSING, it will reverse to OPENING until completely OPEN. It will remain BLOCKED, however, until the input BLOCK_CLEARED is called.

    Any other state, it will remain in that position, until the input BLOCK_CLEARED is called, and then it will revert back to it's prior state before it was blocked. Button clicks will be discarded. If the door was already in the process of opening, it will continue to OPEN until CYCLE_COMPLETE is called.

Bonus Challenge Input

button_clicked
cycle_complete
button_clicked
block_detected
button_clicked
cycle_complete
button_clicked
block_cleared
button_clicked
cycle_complete

Bonus Challenge output:

Door: CLOSED
> Button clicked
Door: OPENING
> Cycle complete
Door: OPEN
> Button Clicked
Door: CLOSING
> Block detected!
Door: EMERGENCY_OPENING
> Button clicked.
Door: EMERGENCY_OPENING
> Cycle complete.
Door: OPEN_BLOCKED
> Button clicked
Door: OPEN_BLOCKED
> Block cleared
Door: OPEN
> Button clicked
Door: CLOSING
> Cycle complete
Door: CLOSED

Finally

Have a good challenge idea?

Consider submitting it to r/dailyprogrammer_ideas

Thanks to /u/Philboyd_Studge for this challenge idea.

*/

#include <stdio.h>
#include <string.h>

#define nelem(x) (sizeof(x) / sizeof(x[0]))

enum {
	CLOSED = 0,
	OPENING,
	OPEN,
	CLOSING,
	STOPPED_WHILE_CLOSING,
	STOPPED_WHILE_OPENING,
};

typedef struct {
	char name[32];
	char action[32];
	int transition;
} Cmd;

const char *
state(int t)
{
	switch (t) {
	case CLOSED:
		return "CLOSED";
	case OPENING:
		return "OPENING";
	case OPEN:
		return "OPEN";
	case CLOSING:
		return "CLOSING";
	case STOPPED_WHILE_CLOSING:
		return "STOPPED_WHILE_CLOSING";
	case STOPPED_WHILE_OPENING:
		return "STOPPED_WHILE_OPENING";
	}
	return "ERROR";
}

const Cmd *
cmd(const char *s)
{
	static const Cmd tab[] = {
	    {"button_clicked", "Button Clicked", 0},
	    {"cycle_complete", "Cycle Complete", 1},
	    {"", "Unknown Command", -1},
	};

	const Cmd *c;
	size_t i;

	for (i = 0; i < nelem(tab); i++) {
		c = tab + i;
		if (!strcmp(c->name, s))
			break;
	}
	return c;
}

int
fsm(int t, int c)
{
	static const int tab[6][2] = {
	    [CLOSED] = {OPENING, OPEN},
	    [OPENING] = {STOPPED_WHILE_OPENING, OPEN},
	    [OPEN] = {CLOSING, CLOSED},
	    [CLOSING] = {STOPPED_WHILE_CLOSING, CLOSED},
	    [STOPPED_WHILE_CLOSING] = {OPENING, STOPPED_WHILE_CLOSING},
	    [STOPPED_WHILE_OPENING] = {CLOSING, STOPPED_WHILE_OPENING},
	};

	if (!(0 <= t && t < (int)nelem(tab)))
		return t;
	if (!(0 <= c && c < (int)nelem(tab[c])))
		return t;

	return tab[t][c];
}

void
sim(const char **s, size_t n)
{
	const Cmd *c;
	size_t i;
	int t;

	t = CLOSED;
	for (i = 0; i < n; i++) {
		c = cmd(s[i]);
		printf("Door: %s\n", state(t));
		printf("> %s.\n", c->action);
		t = fsm(t, c->transition);
	}
	printf("Door: %s\n", state(t));
}

int
main(void)
{
	const char *s1[] = {
	    "button_clicked",
	    "cycle_complete",
	    "button_clicked",
	    "button_clicked",
	    "button_clicked",
	    "button_clicked",
	    "button_clicked",
	    "cycle_complete",
	};

	sim(s1, nelem(s1));

	return 0;
}
