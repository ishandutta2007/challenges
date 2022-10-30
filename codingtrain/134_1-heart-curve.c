#define _GNU_SOURCE
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <SDL.h>
#include <cairo.h>

#define nelem(x) (sizeof(x) / sizeof(x[0]))

SDL_Window *window;
SDL_Renderer *renderer;
SDL_Texture *texture;

cairo_surface_t *canvas;
cairo_t *cr;

int width, height;

SDL_FPoint heart[512];
size_t nheart;
float angle;

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

	SDL_SetWindowTitle(window, "Heart");

	resize(w, h);
}

void
reset(void)
{
	angle = 0;
	nheart = 0;
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
				reset();
				break;
			}
			break;
		}
	}
}

void
update(void)
{
	SDL_FPoint p;
	float r;
	Uint32 ticks;
	int dt;

	ticks = SDL_GetTicks();
	dt = ticks - start;
	if (dt < 20)
		return;

	if (!pause) {
		r = height / 40;
		p.x = r * 16 * pow(sin(angle), 3);
		p.y = -r * (13 * cos(angle) - 5 * cos(2 * angle) - 2 * cos(3 * angle) - cos(4 * angle));
		if (angle < 2 * M_PI && nheart < nelem(heart)) {
			heart[nheart++] = p;
			angle += 0.05;
		}

		start = ticks;
	}
}

void
drawheart(void)
{
	size_t i;

	cairo_set_source_rgb(cr, 0, 0, 0);
	cairo_paint(cr);

	cairo_identity_matrix(cr);
	cairo_translate(cr, width / 2, height / 2);

	cairo_set_source_rgb(cr, 1, 1, 1);
	cairo_set_line_width(cr, 4);
	for (i = 0; i < nheart; i++)
		cairo_line_to(cr, heart[i].x, heart[i].y);
	cairo_stroke_preserve(cr);

	cairo_set_source_rgb(cr, 0.58, 0, 0.39);
	cairo_fill(cr);
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

	drawheart();
	upload();

	SDL_RenderCopy(renderer, texture, NULL, NULL);
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
