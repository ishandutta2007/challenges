#define _GNU_SOURCE
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <errno.h>
#include <SDL.h>
#include <cairo.h>

SDL_Window *window;
SDL_Renderer *renderer;
SDL_Texture *texture;

cairo_surface_t *canvas;
cairo_t *cr;

int width, height;

SDL_FPoint control[4];

Uint32 start;

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

int
randn(int n)
{
	int r;

	if (n == 0)
		return 0;

	do {
		r = rand();
	} while (r >= (RAND_MAX - (RAND_MAX % n)));

	return (r % n) + 1;
}

float
lerp(float t, float a, float b)
{
	return a + t * (b - a);
}

void
resize(int w, int h)
{
	if (texture)
		SDL_DestroyTexture(texture);

	if (canvas) {
		cairo_surface_destroy(canvas);
		cairo_destroy(cr);
	}

	texture = SDL_CreateTexture(renderer, SDL_PIXELFORMAT_ARGB8888, SDL_TEXTUREACCESS_STREAMING, w, h);
	if (!texture)
		fatal("Failed to create texture: %s", SDL_GetError());

	canvas = cairo_image_surface_create(CAIRO_FORMAT_ARGB32, w, h);
	cr = cairo_create(canvas);

	width = w;
	height = h;
}

void
initsdl(void)
{
	int w, h;

	if (SDL_Init(SDL_INIT_VIDEO | SDL_INIT_TIMER) < 0)
		fatal("Failed to init SDL: %s", SDL_GetError());

	w = 800;
	h = 600;
	if (SDL_CreateWindowAndRenderer(w, h, SDL_WINDOW_RESIZABLE, &window, &renderer) < 0)
		fatal("Failed to create window: %s", SDL_GetError());

	SDL_SetWindowTitle(window, "Sierpinski Triangle");

	resize(w, h);
}

void
reset(void)
{
	SDL_FPoint *cp;
	int i;

	control[0] = (SDL_FPoint){width / 2.0, 0};
	control[1] = (SDL_FPoint){0, height};
	control[2] = (SDL_FPoint){width, height};
	control[3] = (SDL_FPoint){randn(width) - 1, randn(height) - 1};

	cairo_set_source_rgb(cr, 0, 0, 0);
	cairo_paint(cr);
	cairo_set_source_rgb(cr, 1, 1, 1);
	for (i = 0; i < 3; i++) {
		cp = &control[i];
		cairo_arc(cr, cp->x, cp->y, 8, 0, 2 * M_PI);
		cairo_fill(cr);
	}

	start = SDL_GetTicks();
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
				pause = !pause;
				break;

			case SDLK_RETURN:
				reset();
				break;
			}
			break;

		case SDL_WINDOWEVENT:
			switch (ev.window.event) {
			case SDL_WINDOWEVENT_RESIZED:
			case SDL_WINDOWEVENT_SIZE_CHANGED:
				resize(ev.window.data1, ev.window.data2);
				break;
			}
			break;
		}
	}
}

void
step(int iterations)
{
	static const float cols[3][3] = {
	    {1, 0, 1},
	    {0, 1, 1},
	    {1, 1, 0},
	};

	SDL_FPoint *cp, *cc;
	const float *col;
	int i, n;

	cc = &control[3];
	for (i = 0; i < iterations; i++) {
		n = randn(3) - 1;
		cp = &control[n];
		col = cols[n];

		cairo_set_source_rgb(cr, col[0], col[1], col[2]);
		cairo_arc(cr, cc->x, cc->y, 2, 0, 2 * M_PI);
		cairo_fill(cr);

		cc->x = lerp(0.5, cc->x, cp->x);
		cc->y = lerp(0.5, cc->y, cp->y);
	}
}

void
update(void)
{
	Uint32 ticks;
	int dt;

	ticks = SDL_GetTicks();
	dt = ticks - start;
	if (dt < 16)
		return;

	if (!pause)
		step(100);

	start = ticks;
}

void
upload(void)
{
	void *pixels, *data;
	int pitch;

	SDL_LockTexture(texture, NULL, &pixels, &pitch);
	data = cairo_image_surface_get_data(canvas);
	memcpy(pixels, data, pitch * height);
	SDL_UnlockTexture(texture);
}

void
draw(void)
{
	SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
	SDL_RenderClear(renderer);

	upload();

	SDL_RenderCopy(renderer, texture, NULL, NULL);
	SDL_RenderPresent(renderer);
}

int
main(void)
{
	srand(time(NULL));
	initsdl();
	reset();

	for (;;) {
		event();
		update();
		draw();
	}
	return 0;
}
