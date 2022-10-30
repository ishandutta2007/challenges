// The classic one-line Commodore 64 BASIC program, described by the book 10PRINT (https://10print.org/)

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <SDL.h>

SDL_Window *window;
SDL_Renderer *renderer;

Uint32 start;

char *choices;
size_t nchoices;
size_t maxchoices;

void *
xcalloc(size_t nmemb, size_t size)
{
	void *p;

	p = calloc(nmemb, size);
	if (!p)
		abort();
	return p;
}

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

double
drand(void)
{
	return rand() * 1.0 / RAND_MAX;
}

void
initsdl(void)
{
	int w, h;

	if (SDL_Init(SDL_INIT_VIDEO | SDL_INIT_TIMER) < 0)
		fatal("Failed to init SDL: %s", SDL_GetError());

	w = 512;
	h = 512;
	if (SDL_CreateWindowAndRenderer(w, h, SDL_WINDOW_RESIZABLE, &window, &renderer) < 0)
		fatal("Failed to create window: %s", SDL_GetError());

	SDL_SetWindowTitle(window, "10PRINT MAZE");
}

void
genchoices(void)
{
	size_t i;

	if (maxchoices == 0) {
		maxchoices = 2048ULL * 2048ULL;
		choices = xcalloc(maxchoices, sizeof(*choices));
	}

	for (i = 0; i < maxchoices; i++)
		choices[i] = drand() < 0.5;
	nchoices = 0;
}

void
event(void)
{
	SDL_Event ev;

	while (SDL_PollEvent(&ev)) {
		switch (ev.type) {
		case SDL_QUIT:
			exit(0);

		case SDL_KEYDOWN:
			switch (ev.key.keysym.sym) {
			case SDLK_ESCAPE:
				exit(0);

			case SDLK_SPACE:
				genchoices();
				break;

			case SDLK_RETURN:
				nchoices = maxchoices;
				break;
			}
			break;
		}
	}
}

void
update(void)
{
	Uint32 ticks;

	ticks = SDL_GetTicks();
	if (ticks - start < 10)
		return;

	if (nchoices < maxchoices)
		nchoices++;

	start = ticks;
}

void
drawmaze(char *choices, size_t nchoices, size_t maxchoices)
{
	int x, y, w, h;
	int spacing;
	size_t i;

	SDL_GetRendererOutputSize(renderer, &w, &h);
	SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);

	x = y = 0;
	spacing = 10;
	for (i = 0; y < h && i < nchoices; i++) {
		if (choices[i % maxchoices])
			SDL_RenderDrawLine(renderer, x, y, x + 10, y + spacing);
		else
			SDL_RenderDrawLine(renderer, x, y + spacing, x + spacing, y);

		x += spacing;
		if (x >= w) {
			x = 0;
			y += spacing;
		}
	}
}

void
draw(void)
{
	SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
	SDL_RenderClear(renderer);
	drawmaze(choices, nchoices, maxchoices);
	SDL_RenderPresent(renderer);
}

int
main(void)
{
	srand(time(NULL));
	initsdl();
	genchoices();

	for (;;) {
		event();
		update();
		draw();
	}
	return 0;
}
