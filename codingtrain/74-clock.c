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

float
lerp(float t, float a, float b)
{
	return a + t * (b - a);
}

float
unlerp(float t, float a, float b)
{
	return (t - a) / (b - a);
}

float
linear_remap(float x, float a, float b, float c, float d)
{
	return lerp(unlerp(x, a, b), c, d);
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

	SDL_SetWindowTitle(window, "Clock");

	resize(w, h);
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
draw_clock(void)
{
	struct tm tm;
	time_t t;
	float ha, ma, sa;

	t = time(NULL);
	localtime_r(&t, &tm);

	sa = linear_remap(tm.tm_sec, 0, 60, 0, 2 * M_PI);
	ma = linear_remap(tm.tm_min, 0, 60, 0, 2 * M_PI);
	ha = linear_remap(tm.tm_hour % 12, 0, 12, 0, 2 * M_PI);

	cairo_identity_matrix(cr);
	cairo_translate(cr, width / 2.0, height / 2.0);
	cairo_rotate(cr, -M_PI / 2);

	cairo_set_line_width(cr, 8);
	cairo_set_source_rgb(cr, 1, 0.39, 0.59);

	cairo_save(cr);
	cairo_rotate(cr, sa);
	cairo_set_source_rgb(cr, 1, 0.39, 0.59);
	cairo_move_to(cr, 0, 0);
	cairo_line_to(cr, 100, 0);
	cairo_stroke(cr);
	cairo_restore(cr);

	cairo_save(cr);
	cairo_rotate(cr, ma);
	cairo_set_source_rgb(cr, 0.59, 0.39, 1);
	cairo_move_to(cr, 0, 0);
	cairo_line_to(cr, 75, 0);
	cairo_stroke(cr);
	cairo_restore(cr);

	cairo_save(cr);
	cairo_rotate(cr, ha);
	cairo_set_source_rgb(cr, 0.59, 1, 0.39);
	cairo_move_to(cr, 0, 0);
	cairo_line_to(cr, 50, 0);
	cairo_stroke(cr);
	cairo_restore(cr);

	cairo_set_source_rgb(cr, 0.5, 0.6, 0.7);
	cairo_arc(cr, 0, 0, 100, 0, 2 * M_PI);
	cairo_stroke(cr);
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

	cairo_set_source_rgb(cr, 0, 0, 0);
	cairo_paint(cr);

	draw_clock();
	upload();

	SDL_RenderCopy(renderer, texture, NULL, NULL);
	SDL_RenderPresent(renderer);
}

int
main(void)
{
	initsdl();
	for (;;) {
		event();
		draw();
	}
	return 0;
}
