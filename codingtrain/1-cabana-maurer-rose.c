#define _GNU_SOURCE
#include <stdio.h>
#include <string.h>
#include <errno.h>
#include <math.h>
#include <SDL.h>

#define deg2rad(x) (((x)*M_PI) / 180)

SDL_Window *window;
SDL_Renderer *renderer;

Uint64 start;

float radius;
float petals;
float degrees;

int pause;

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

	SDL_SetWindowTitle(window, "Maurer Rose");
	SDL_SetHint(SDL_HINT_RENDER_SCALE_QUALITY, "best");

	start = SDL_GetPerformanceCounter();
}

void
reset(void)
{
	radius = 200;
	petals = 0;
	degrees = 0;
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
			case SDLK_RETURN:
				pause = !pause;
				break;
			case SDLK_LEFT:
				if (radius > 0)
					radius--;
				break;
			case SDLK_RIGHT:
				radius++;
				break;
			}
			break;
		}
	}
}

void
update(void)
{
	Uint64 now;
	float dt;

	if (pause)
		return;

	now = SDL_GetPerformanceCounter();
	dt = (now - start) * 1000.0 / SDL_GetPerformanceFrequency();
	if (dt >= 10) {
		petals += 0.001;
		degrees += 0.003;
		start = now;
	}
}

void
maurer(float n, float d, float R)
{
	float k, r;
	float x, y;
	float px, py;
	int w, h;
	int i;

	SDL_GetRendererOutputSize(renderer, &w, &h);
	SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);

	px = py = 0;
	for (i = 0; i <= 360; i++) {
		k = i * d;
		r = R * sin(deg2rad(n * k));
		x = (r * cos(deg2rad(k))) + (w / 2);
		y = (r * sin(deg2rad(k))) + (h / 2);

		if (i > 0)
			SDL_RenderDrawLineF(renderer, px, py, x, y);

		px = x;
		py = y;
	}
}

void
draw(void)
{
	SDL_SetRenderDrawColor(renderer, 50, 70, 80, 255);
	SDL_RenderClear(renderer);
	maurer(petals, degrees, radius);
	SDL_RenderPresent(renderer);
}

int
main(void)
{
	initsdl();
	reset();
	for (;;) {
		event();
		update();
		draw();
	}
	return 0;
}
