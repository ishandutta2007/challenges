/*

create a program that will remind you to stop procrastinating every two hours with a pop up message! :)

This program has the potential of helping many people :D

*/

#include <stdio.h>
#include <stdarg.h>
#include <SDL.h>

void
fatal(const char *fmt, ...)
{
	va_list ap;

	va_start(ap, fmt);
	vfprintf(stderr, fmt, ap);
	va_end(ap);
	fprintf(stderr, "\n");
	exit(1);
}

int
main(void)
{
	if (SDL_Init(SDL_INIT_VIDEO | SDL_INIT_TIMER) < 0)
		fatal("Failed to init SDL: %s", SDL_GetError());

	for (;;) {
		SDL_ShowSimpleMessageBox(SDL_MESSAGEBOX_INFORMATION, "PRODUCTIVITY", "STOP PROCRASTINATING", NULL);
		SDL_Delay(2000 * 60 * 60);
	}
	return 0;
}
