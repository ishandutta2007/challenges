/*

Challenge Description
You have to show a simulation of rain in terminal.

In the example given below its adding 100 raindrops at random (use the default random function which your language offers) coordinates, waiting for 0.2 seconds and then redrawing again until the given time expires.
Any character can be used for representing the raindrop.

Parameters
Wait time between redrawing in seconds.
Time for which the rain will be visible. This is just an integer representing the number of iterations. [So, the net time for which the rain will be visible is this integer multiplied by the wait time]
Message to be displayed when the rain ends. (This has to be centered)
Number of raindrops to be displayed on the screen.

Rules
A single byte should be used for representing a rain drop, and it can be anything, even cats and dogs.
It doesn't have to be responsive to terminal size which means you don't have to handle the bug for varied terminal sizes. You can specify the terminal width and height on your own.
Standard rules of golfing apply.
Code Sample and Output
This is an ungolfed version written in python 2.7 using ncurses.

import curses
import random
import time

myscreen = curses.initscr()
curses.curs_set(0) # no cursor please
HEIGHT, WIDTH = myscreen.getmaxyx()
RAIN = '/' # this is what my rain drop looks like
TIME = 10

def make_it_rain(window, tot_time, msg, wait_time, num_drops):
    """
    window    :: curses window
    time      :: Total time for which it rains
    msg       :: Message displayed when it stops raining
    wait_time :: Time between redrawing scene
    num_drops :: Number of rain drops in the scene
    """
    for _ in range(tot_time):
        for i in range(num_drops):
            x,y=random.randint(1, HEIGHT-2),random.randint(1,WIDTH-2)
            window.addstr(x,y,RAIN)
        window.refresh()
        time.sleep(wait_time)
        window.erase()

    window.refresh()
    window.addstr(HEIGHT/2, int(WIDTH/2.7), msg)


if __name__ == '__main__':
    make_it_rain(myscreen, TIME, 'IT HAS STOPPED RAINING!', 0.2, 100)
    myscreen.getch()
    curses.endwin()

*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <err.h>
#include <curses.h>

void
rain(WINDOW *win, int iters, int drops, const char *msg, int wait, const char *rain)
{
	struct timespec req;
	int x, y, w, h;
	int i, n;

	req.tv_nsec = (wait % 1000) * 1000000;
	req.tv_sec = wait / 1000;

	start_color();
	init_pair(1, COLOR_GREEN, COLOR_BLACK);
	attron(COLOR_PAIR(1));
	wbkgd(win, COLOR_PAIR(1));

	getmaxyx(win, w, h);
	for (n = 0; n < iters; n++) {
		for (i = 0; i < drops; i++) {
			x = rand() % w;
			y = rand() % h;
			mvwaddstr(win, y, x, rain);
		}
		wrefresh(win);
		clock_nanosleep(CLOCK_MONOTONIC, 0, &req, NULL);
		werase(win);
	}
	mvwaddstr(win, 0, 0, msg);
	wrefresh(win);
	getchar();
}

int
main(void)
{
	WINDOW *win;

	srand(time(NULL));
	win = initscr();
	if (!win)
		errx(1, "Failed to init screen");
	curs_set(0);
	rain(win, 10, 200, "IT HAS STOPPED RAINING", 120, "/");
	endwin();

	return 0;
}
