#define _GNU_SOURCE
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <SDL.h>
#include <cairo.h>

typedef struct {
	float n1, n2, n3;
	float a, b, m;
} Shape;

SDL_Window *window;
SDL_Renderer *renderer;
SDL_Texture *texture;

cairo_surface_t *canvas;
cairo_t *cr;

int width, height;

Shape shape;
float osc;

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

	SDL_SetWindowTitle(window, "Supershape");

	resize(w, h);
}

void
reset(void)
{
	shape = (Shape){
	    .n1 = 0.3,
	    .n2 = 0.3,
	    .n3 = 0.3,
	    .m = 0,
	    .a = 1,
	    .b = 1,
	};
	osc = 0;
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
update(void)
{
	Uint32 ticks;
	int dt;

	ticks = SDL_GetTicks();
	dt = ticks - start;
	if (dt < 30)
		return;

	if (!pause) {
		shape.m = linear_remap(sin(osc), -1, 1, 0, 10);
		osc += 0.02;
	}

	start = ticks;
}

float
supershape(float theta, float a, float b, float m, float n1, float n2, float n3)
{
	float x1, x2, x3;

	x1 = (1 / a) * cos(theta * m / 4);
	x1 = fabs(x1);
	x1 = pow(x1, n2);

	x2 = (1 / b) * sin(theta * m / 4);
	x2 = fabs(x2);
	x2 = pow(x2, n3);

	x3 = pow(x1 + x2, 1 / n1);
	if (x3 == 0)
		return 0;

	return (1 / x3);
}

void
draw_supershape(void)
{
	float radius;
	float angle;
	float increment;
	float r, x, y;
	int total;

	radius = 100;
	total = 200;
	increment = (2 * M_PI) / total;

	cairo_set_source_rgb(cr, 0.2, 0.2, 0.2);
	cairo_paint(cr);

	cairo_identity_matrix(cr);
	cairo_translate(cr, width / 2, height / 2);

	cairo_set_source_rgb(cr, 1, 1, 1);
	for (angle = 0; angle < 2 * M_PI; angle += increment) {
		r = supershape(angle, shape.a, shape.b, shape.m, shape.n1, shape.n2, shape.n3);
		x = radius * r * cos(angle);
		y = radius * r * sin(angle);

		cairo_line_to(cr, x, y);
	}
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

	draw_supershape();
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
