#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <cstdarg>
#include <cstdint>
#include <algorithm>
#include <vector>
#include <SDL.h>
#include <cairo.h>

using namespace std;

struct App
{
	SDL_Window *window;
	SDL_Renderer *renderer;
	SDL_Texture *texture;

	cairo_surface_t *canvas;
	cairo_t *cr;

	vector<SDL_FPoint> points;
	size_t max_points;

	float percent;
	SDL_FPoint previous;
	SDL_FPoint current;

	Uint32 start;
	bool paused;

	int width, height;

	void resize(int new_width, int new_height);

	void init();
	void reset();

	void event();
	void next_iteration();
	void upload();
	void update_and_draw();
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

	SDL_SetWindowTitle(window, "Fractal Dynamics");
	SDL_SetRenderDrawBlendMode(renderer, SDL_BLENDMODE_BLEND);

	resize(width, height);

	max_points = 5;
	percent = 0.5;
	paused = false;
}

void App::reset()
{
	points.resize(max_points);
	for (size_t i = 0; i < max_points; i++)
	{
		float t = (i * 2 * M_PI) / max_points;
		points[i] = {
			(width * 0.5f * cos(t)) + (width * 0.5f),
			(height * 0.5f * sin(t)) + (height * 0.5f),
		};
	}

	cairo_set_source_rgb(cr, 0, 0, 0);
	cairo_paint(cr);
	cairo_set_source_rgb(cr, 1, 1, 1);
	for (auto &point : points)
	{
		cairo_arc(cr, point.x, point.y, 8, 0, 2 * M_PI);
		cairo_fill(cr);
	}

	start = SDL_GetTicks();
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
			case SDLK_LEFT:
				if (max_points > 0)
					max_points--;
				reset();
				break;
			case SDLK_RIGHT:
				max_points++;
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
				reset();
				break;
			}
			break;
		}
	}
}

void App::next_iteration()
{
	auto now = SDL_GetTicks();
	if (now - start < 20)
		return;

	if (!paused)
	{
		for (auto i = 0; i < 1000; i++)
		{
			cairo_set_source_rgb(cr, 1, 1, 1);
			SDL_FPoint next = points[floor(drand48() * points.size())];
			if (next.x != previous.x || next.y != previous.y)
			{
				current.x = lerp(current.x, next.x, percent);
				current.y = lerp(current.y, next.y, percent);
				cairo_arc(cr, current.x, current.y, 1, 0, 2 * M_PI);
				cairo_fill(cr);
			}
			previous = next;
		}
	}

	start = now;
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

void App::update_and_draw()
{
	SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
	SDL_RenderClear(renderer);

	next_iteration();

	upload();

	SDL_RenderCopy(renderer, texture, NULL, NULL);
	SDL_RenderPresent(renderer);
}

int main()
{
	srand48(time(NULL));
	auto app = new App();
	app->init();
	app->reset();
	for (;;)
	{
		app->event();
		app->update_and_draw();
	}

	return 0;
}
