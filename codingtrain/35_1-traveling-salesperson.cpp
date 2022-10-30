#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <cstdarg>
#include <cstdint>
#include <chrono>
#include <algorithm>
#include <vector>
#include <random>
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

	vector<SDL_FPoint> best;
	float record;

	vector<SDL_FPoint> cities;
	size_t num_cities;

	int width, height;

	uint32_t start;
	bool paused;

	void resize(int new_width, int new_height);

	void init();
	void reset();

	float calc_distance(const vector<SDL_FPoint> &points);

	void gen_cities();
	void next_tour();

	void event();
	void update();
	void draw_tour();
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

	SDL_SetWindowTitle(window, "Traveling Salesman Problem");

	resize(width, height);

	num_cities = 10;
}

void App::reset()
{
	start = SDL_GetTicks();
	gen_cities();
}

float App::calc_distance(const vector<SDL_FPoint> &points)
{
	auto sum = 0.0;
	for (auto i = 0u; i < points.size() - 1; i++)
		sum += hypot(points[i].x - points[i + 1].x, points[i].y - points[i + 1].y);
	return sum;
}

void App::gen_cities()
{
	auto seed = chrono::system_clock::now().time_since_epoch().count();
	default_random_engine generator(seed);
	uniform_real_distribution<float> x_distribution(0.0, width);
	uniform_real_distribution<float> y_distribution(0.0, height);

	cities.resize(num_cities);
	for (auto i = 0u; i < cities.size(); i++)
		cities[i] = { x_distribution(generator), y_distribution(generator) };

	record = calc_distance(cities);
	best = cities;

	printf("%zu cities\n", num_cities);
}

void App::next_tour()
{
	auto seed = chrono::system_clock::now().time_since_epoch().count();
	default_random_engine generator(seed);

	uniform_int_distribution<> distribution(0, cities.size() - 1);
	auto i = distribution(generator);
	auto j = distribution(generator);
	swap(cities[i], cities[j]);

	auto dist = calc_distance(cities);
	if (dist < record)
	{
		record = dist;
		best = cities;
	}
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
				if (num_cities > 1)
					num_cities--;
				gen_cities();
				break;
			case SDLK_RIGHT:
				num_cities++;
				gen_cities();
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
	if (now - start < 500)
		return;

	if (!paused)
		next_tour();

	start = now;
}

void App::draw_tour()
{
	cairo_set_source_rgb(cr, 0, 0, 0);
	cairo_paint(cr);

	cairo_set_source_rgb(cr, 1, 1, 1);
	cairo_set_line_width(cr, 2);
	for (auto city : cities)
		cairo_line_to(cr, city.x, city.y);
	cairo_stroke(cr);

	cairo_set_source_rgb(cr, 1, 0, 1);
	cairo_set_line_width(cr, 4);
	for (auto city : best)
		cairo_line_to(cr, city.x, city.y);
	cairo_stroke(cr);

	cairo_set_source_rgb(cr, 1, 1, 1);
	for (auto city : cities)
	{
		cairo_arc(cr, city.x, city.y, 8, 0, 2 * M_PI);
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

	draw_tour();
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
