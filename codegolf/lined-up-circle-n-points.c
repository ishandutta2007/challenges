/*

Draw lines between every pair of distinct points for n points arranged in a circle, producing something like the below result. Shortest code (in bytes) wins!
Your lines don't have to be transparent, but it looks better that way.
The output must be a vector graphic, or be an image at least 600 pixels by 600 pixels (either saved to a file or displayed on the screen).
To complete the challenge you must draw at least 20.

https://i.stack.imgur.com/erAyJ.jpg

*/

#define _GNU_SOURCE
#include <stdio.h>
#include <string.h>
#include <errno.h>
#include <math.h>
#include <complex.h>
#include <SDL.h>

typedef struct {
	SDL_FPoint center;
	float radius;
	int npoints;
} Region;

SDL_Window *window;
SDL_Renderer *renderer;
Region region;

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
	if (SDL_Init(SDL_INIT_VIDEO) < 0)
		fatal("Failed to init SDL: %s", strerror(errno));

	if (SDL_CreateWindowAndRenderer(800, 800, SDL_WINDOW_RESIZABLE, &window, &renderer) < 0)
		fatal("Failed to create SDL window: %s", strerror(errno));

	SDL_SetHint(SDL_HINT_RENDER_SCALE_QUALITY, "best");
}

void
resize(void)
{
	char title[80];
	int w, h;

	SDL_GetRendererOutputSize(renderer, &w, &h);
	region.center = (SDL_FPoint){w / 2.0, h / 2.0};
	region.radius = SDL_min(w, h) / 2;

	snprintf(title, sizeof(title), "Circle Complete Graph: %d", region.npoints);
	SDL_SetWindowTitle(window, title);
}

void
reset(void)
{
	region.npoints = 20;
	resize();
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
			case SDLK_LEFT:
				region.npoints--;
				goto resize;
			case SDLK_RIGHT:
				region.npoints++;
				goto resize;
			}
			break;

		case SDL_WINDOWEVENT:
			if (ev.window.event == SDL_WINDOWEVENT_RESIZED)
				goto resize;
			break;
		}

		if (0) {
		resize:
			resize();
		}
	}
}

SDL_FPoint
rootsofunity(Region *r, int i)
{
	float complex c;

	c = cexpf(2 * M_PI * I * i / r->npoints);
	return (SDL_FPoint){
	    .x = r->center.x + r->radius * crealf(c),
	    .y = r->center.y + r->radius * cimagf(c),
	};
}

void
drawregion(Region *r)
{
	SDL_FPoint p, q;
	int i, j;

	SDL_SetRenderDrawColor(renderer, 122, 143, 175, 255);
	for (i = 0; i < r->npoints; i++) {
		p = rootsofunity(r, i);
		for (j = i + 1; j < r->npoints; j++) {
			q = rootsofunity(r, j);
			SDL_RenderDrawLineF(renderer, p.x, p.y, q.x, q.y);
		}
	}
}

void
draw(void)
{
	SDL_SetRenderDrawColor(renderer, 50, 70, 80, 255);
	SDL_RenderClear(renderer);
	drawregion(&region);
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
