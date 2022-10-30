#define _GNU_SOURCE
#include <stdio.h>
#include <string.h>
#include <errno.h>
#include <math.h>
#include <SDL.h>

SDL_Window *window;
SDL_Renderer *renderer;

float radius;
float petals;
float degrees;

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

void
initsdl(void)
{
	if (SDL_Init(SDL_INIT_VIDEO | SDL_INIT_TIMER) < 0)
		fatal("Failed to init SDL: %s", strerror(errno));

	if (SDL_CreateWindowAndRenderer(800, 800, SDL_WINDOW_RESIZABLE, &window, &renderer) < 0)
		fatal("Failed to create SDL window: %s", strerror(errno));

	SDL_SetWindowTitle(window, "Roses");
	SDL_SetHint(SDL_HINT_RENDER_SCALE_QUALITY, "best");
}

void
reset(void)
{
	radius = 200;
	petals = 5;
	degrees = 8;
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
				reset();
				break;
			}
			break;
		}
	}
}

void
rose(float n, float d, float R)
{
	float px, py;
	float x, y;
	float k, a, r;
	int w, h;

	SDL_GetRendererOutputSize(renderer, &w, &h);
	SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);

	k = n / d;
	for (a = 0; a < 2 * M_PI * d; a += 0.02) {
		r = R * cos(k * a);
		x = (r * cos(a)) + (w / 2);
		y = (r * sin(a)) + (h / 2);

		if (a > 0)
			SDL_RenderDrawLineF(renderer, px, py, x, y);

		px = x;
		py = y;
	}
}

void
draw(void)
{
	SDL_SetRenderDrawColor(renderer, 51, 51, 51, 255);
	SDL_RenderClear(renderer);
	rose(petals, degrees, radius);
	SDL_RenderPresent(renderer);
}

int
main(void)
{
	initsdl();
	reset();
	for (;;) {
		event();
		draw();
	}
	return 0;
}
