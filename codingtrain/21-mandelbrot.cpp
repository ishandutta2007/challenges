#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <cstdarg>
#include <cstdint>
#include <algorithm>
#include <vector>
#include <SDL.h>

using namespace std;

struct App
{
	SDL_Window *window;
	SDL_Renderer *renderer;
	SDL_Texture *texture;

	int width, height;

	double view;
	int iterations;

	void resize(int new_width, int new_height);

	void init();
	void reset();

	void event();
	void render();
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

uint32_t color(double fr, double fg, double fb)
{
	uint32_t r, g, b, a;

	r = clamp(fr * 255.0, 0.0, 255.0);
	g = clamp(fg * 255.0, 0.0, 255.0);
	b = clamp(fb * 255.0, 0.0, 255.0);
	a = 255;
	return b | g << 8 | r << 16 | a << 24;
}

void App::resize(int new_width, int new_height)
{
	width = new_width;
	height = new_height;

	if (texture)
		SDL_DestroyTexture(texture);

	texture = SDL_CreateTexture(renderer, SDL_PIXELFORMAT_ARGB8888, SDL_TEXTUREACCESS_STREAMING, width, height);
	if (!texture)
		fatal("Failed to create texture: %s", SDL_GetError());
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

	SDL_SetWindowTitle(window, "Mandelbrot");

	resize(width, height);
	reset();
}

void App::reset()
{
	view = 5;
	iterations = 100;
	render();
}

void App::event()
{
	auto dirty = false;
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
			case SDLK_SPACE:
				reset();
				break;
			case SDLK_UP:
				view -= 0.05;
				dirty = true;
				break;
			case SDLK_DOWN:
				view += 0.05;
				dirty = true;
				break;
			}
			break;

		case SDL_WINDOWEVENT:
			switch (ev.window.event)
			{
			case SDL_WINDOWEVENT_RESIZED:
			case SDL_WINDOWEVENT_SIZE_CHANGED:
				resize(ev.window.data1, ev.window.data2);
				dirty = true;
				break;
			}
			break;
		}
	}

	if (dirty)
		render();
}

void App::render()
{
	void *data;
	int pitch;
	SDL_LockTexture(texture, NULL, &data, &pitch);
	auto pixels = (uint32_t *)data;

	auto vw = view;
	auto vh = vw * height / width;

	auto xmin = -vw / 2;
	auto ymin = -vh / 2;

	auto xmax = xmin + vw;
	auto ymax = ymin + vh;

	auto dx = (xmax - xmin) / width;
	auto dy = (ymax - ymin) / height;

	auto y = ymin;
	for (auto j = 0; j < height; j++)
	{
		auto x = xmin;
		for (auto i = 0; i < width; i++)
		{
			auto a = x;
			auto b = y;
			auto n = 0;
			for (; n < iterations; n++)
			{
				auto aa = a * a;
				auto bb = b * b;
				auto twoab = 2.0 * a * b;
				a = aa - bb + x;
				b = twoab + y;
				if (a * a + b * b > 16.0)
					break;
			}

			if (n == iterations)
				pixels[j * width + i] = color(0, 0, 0);
			else
				pixels[j * width + i] = color(0.1, 0.2, 0.6 + n * 1.0 / iterations);

			x += dx;
		}
		y += dy;
	}

	SDL_UnlockTexture(texture);
}

void App::draw()
{
	SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
	SDL_RenderClear(renderer);

	auto dimension = SDL_Rect{ 0, 0, width, height };
	SDL_RenderCopy(renderer, texture, &dimension, &dimension);

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
		app->draw();
	}

	return 0;
}
