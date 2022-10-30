#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <cstdarg>
#include <cstdint>
#include <algorithm>
#include <vector>
#include <SDL.h>
#include <cairo.h>
#include <glm/gtc/noise.hpp>

using namespace std;
using namespace glm;

struct App
{
	SDL_Window *window;
	SDL_Renderer *renderer;
	SDL_Texture *texture;

	cairo_surface_t *canvas;
	cairo_t *cr;

	float yoff;

	int width, height;

	uint32_t start;
	bool paused;

	void resize(int new_width, int new_height);

	void init();
	void reset();

	void event();
	void update();
	void draw_butterfly();
	void upload();
	void draw();
};

[[noreturn]] void fatal(const char *fmt, ...)
{
	va_list ap;

	va_start(ap, fmt);
	vfprintf(stderr, fmt, ap);
	va_end(ap);
	fprintf(stderr, "\n");
	exit(1);
}

float unlerp(float t, float a, float b)
{
	return (t - a) / (b - a);
}

float linear_remap(float x, float a, float b, float c, float d)
{
	return lerp(c, d, unlerp(x, a, b));
}

void App::resize(int new_width, int new_height)
{
	width = new_width;
	height = new_height;

	if (texture)
		SDL_DestroyTexture(texture);

	if (canvas)
	{
		cairo_surface_destroy(canvas);
		cairo_destroy(cr);
	}

	texture = SDL_CreateTexture(renderer, SDL_PIXELFORMAT_ARGB8888, SDL_TEXTUREACCESS_STREAMING, width, height);
	if (!texture)
		fatal("Failed to create texture: %s", SDL_GetError());

	canvas = cairo_image_surface_create(CAIRO_FORMAT_ARGB32, width, height);
	cr = cairo_create(canvas);
}

void App::init()
{
	if (SDL_Init(SDL_INIT_VIDEO | SDL_INIT_TIMER) < 0)
		fatal("Failed to init SDL: %s", SDL_GetError());

	width = 800;
	height = 600;
	auto wflag = SDL_WINDOW_RESIZABLE;
	if (SDL_CreateWindowAndRenderer(width, height, wflag, &window, &renderer) < 0)
		fatal("Failed to create a window: %s", SDL_GetError());

	SDL_SetWindowTitle(window, "Butterfly");

	resize(width, height);
}

void App::reset()
{
	start = SDL_GetTicks();
	yoff = 0;
}

void App::event()
{
	SDL_Event ev;
	while (SDL_PollEvent(&ev))
	{
		switch (ev.type)
		{
		case SDL_QUIT:
			exit(0);

		case SDL_KEYDOWN:
			switch (ev.key.keysym.sym)
			{
			case SDLK_ESCAPE:
				exit(0);
			case SDLK_RETURN:
				paused = !paused;
				break;
			case SDLK_SPACE:
				reset();
				break;
			}
			break;

		case SDL_WINDOWEVENT:
			switch (ev.window.event)
			{
			case SDL_WINDOWEVENT_RESIZED:
			case SDL_WINDOWEVENT_SIZE_CHANGED:
				resize(ev.window.data1, ev.window.data2);
				break;
			}
			break;
		}
	}
}

void App::update()
{
	auto now = SDL_GetTicks();
	if (now - start < 10)
		return;

	if (!paused)
		yoff += 0.01;

	start = now;
}

void App::draw_butterfly()
{
	cairo_set_source_rgb(cr, 0.2, 0.2, 0.2);
	cairo_paint(cr);

	cairo_set_source_rgba(cr, 1, 1, 1, 0.2);
	cairo_set_line_width(cr, 1);
	cairo_new_path(cr);
	cairo_identity_matrix(cr);
	cairo_translate(cr, width / 2, height / 2);

	auto da = M_PI / 200;
	auto dx = 0.05;
	auto xoff = 0.0;
	for (auto a = 0.0; a <= 2 * M_PI; a += da)
	{
		auto n = simplex(vec2(xoff, yoff));
		auto r = sin(2 * a) * linear_remap(n, -1, 1, 50, 300);
		auto x = r * cos(a);
		auto y = r * sin(a);
		if (a < M_PI)
			xoff += dx;
		else
			xoff -= dx;
		cairo_line_to(cr, x, y);
	}
	cairo_fill(cr);
}

void App::upload()
{
	void *pixels, *data;
	int pitch;
	SDL_LockTexture(texture, NULL, &pixels, &pitch);
	data = cairo_image_surface_get_data(canvas);
	memcpy(pixels, data, pitch * height);
	SDL_UnlockTexture(texture);
}

void App::draw()
{
	SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
	SDL_RenderClear(renderer);

	draw_butterfly();
	upload();

	SDL_RenderCopy(renderer, texture, NULL, NULL);
	SDL_RenderPresent(renderer);
}

int main()
{
	auto app = new App();
	app->init();
	app->reset();
	for (;;)
	{
		app->event();
		app->update();
		app->draw();
	}

	return 0;
}
