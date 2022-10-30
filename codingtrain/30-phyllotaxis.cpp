#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <cstdarg>
#include <cstdint>
#include <climits>
#include <algorithm>
#include <vector>
#include <SDL.h>
#include <cairo.h>

#define deg2rad(x) (((x)*M_PI) / 180)

using namespace std;

struct App
{
	SDL_Window *window;
	SDL_Renderer *renderer;
	SDL_Texture *texture;

	cairo_surface_t *canvas;
	cairo_t *cr;

	float dots;
	float radius;
	float phase;

	int width, height;

	uint32_t start;
	bool paused;

	void resize(int new_width, int new_height);

	void init();
	void reset();

	void event();
	void update();
	void draw_phyllotaxis();
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

void hsv2rgb(double &R, double &G, double &B, double H, double S, double V)
{
	auto C = V * S;
	auto HP = fmod(H / 60.0, 6);
	auto X = C * (1 - fabs(fmod(HP, 2) - 1));
	auto M = V - C;

	if (0 <= HP && HP < 1)
	{
		R = C;
		G = X;
		B = 0;
	}
	else if (1 <= HP && HP < 2)
	{
		R = X;
		G = C;
		B = 0;
	}
	else if (2 <= HP && HP < 3)
	{
		R = 0;
		G = C;
		B = X;
	}
	else if (3 <= HP && HP < 4)
	{
		R = 0;
		G = X;
		B = C;
	}
	else if (4 <= HP && HP < 5)
	{
		R = X;
		G = 0;
		B = C;
	}
	else if (5 <= HP && HP < 6)
	{
		R = C;
		G = 0;
		B = X;
	}
	else
	{
		R = 0;
		G = 0;
		B = 0;
	}

	R += M;
	G += M;
	B += M;
}

float unlerp(float t, float a, float b)
{
	return (t - a) / (b - a);
}

float linear_remap(float x, float a, float b, float c, float d)
{
	return lerp(c, d, unlerp(x, a, b));
}

void transform(float x, float y, float xc, float yc, float t, float *nx, float *ny)
{
	auto si = sin(t);
	auto co = cos(t);
	*nx = (co * x - si * y) + xc;
	*ny = (si * x + co * y) + yc;
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

	SDL_SetWindowTitle(window, "Phyllotaxis");

	resize(width, height);
}

void App::reset()
{
	start = SDL_GetTicks();
	radius = 5;
	dots = 0;
	phase = 0;
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
	if (now - start < 50)
		return;

	if (!paused)
	{
		if (dots < INT_MAX / 2)
			dots += 5;
		phase += 5;
		if (phase >= 1000)
			phase = 0;
	}

	start = now;
}

void App::draw_phyllotaxis()
{
	cairo_set_source_rgb(cr, 0, 0, 0);
	cairo_paint(cr);

	for (auto i = 0; i < dots; i++)
	{
		float a = i * deg2rad(137.5);
		float r = radius * sqrt(i);
		float x = r * cos(a);
		float y = r * sin(a);

		double H = fmod((i + phase) / 3, 360);
		double R, G, B;
		hsv2rgb(R, G, B, H, 1, 1);

		transform(x, y, width / 2, height / 2, dots * 0.3, &x, &y);

		cairo_set_source_rgb(cr, R, G, B);
		cairo_arc(cr, x, y, 3, 0, 2 * M_PI);
		cairo_fill(cr);
	}
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

	draw_phyllotaxis();
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
