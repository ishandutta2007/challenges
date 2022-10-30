#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <cstdarg>
#include <cstdint>
#include <chrono>
#include <fstream>
#include <iostream>
#include <sstream>
#include <string>
#include <random>
#include <vector>
#include <SDL.h>

using namespace std;

struct App
{
	SDL_Window *window;
	SDL_Renderer *renderer;
	int width;
	int height;

	uint32_t start;

	string digits;
	size_t index;

	void init();
	void reset();

	void event();
	void next_line();
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

string read_file(const char *filename)
{
	ifstream in;
	stringstream ss;
	in.open(filename);
	ss << in.rdbuf();
	return ss.str();
}

float unlerp(float t, float a, float b)
{
	return (t - a) / (b - a);
}

float linear_remap(float x, float a, float b, float c, float d)
{
	return lerp(c, d, unlerp(x, a, b));
}

float randn(float a, float b)
{
	default_random_engine engine;
	engine.seed(chrono::system_clock::now().time_since_epoch().count());
	uniform_real_distribution<float> distribution(a, b);
	return distribution(engine);
}

void circle(SDL_Renderer *renderer, float centerx, float centery, float radius, SDL_Color col)
{
	auto iterations = radius * 20.0;
	auto dt = (2 * M_PI) / iterations;

	SDL_SetRenderDrawColor(renderer, col.r, col.g, col.b, col.a);
	for (auto t = 0.0f; t < 2 * M_PI; t += dt)
	{
		auto x1 = radius * cos(t);
		auto y1 = radius * sin(t);
		auto x2 = radius * cos(t + dt);
		auto y2 = radius * sin(t + dt);

		x1 += centerx;
		y1 += centery;

		x2 += centerx;
		y2 += centery;

		SDL_RenderDrawLineF(renderer, x1, y1, x2, y2);
	}
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

	SDL_SetWindowTitle(window, "Visualizing Digits of PI");
	SDL_SetRenderDrawBlendMode(renderer, SDL_BLENDMODE_BLEND);

	digits = read_file("pi-1million.txt");
}

void App::reset()
{
	SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
	SDL_RenderClear(renderer);
	circle(renderer, width / 2, height / 2, min(width, height) / 2 - 10, { 255, 255, 255, 255 });

	index = 0;
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
				width = ev.window.data1;
				height = ev.window.data2;
				reset();
				break;
			}
			break;
		}
	}
}

void App::next_line()
{
	if (index + 1 >= digits.length())
		return;

	auto d1 = digits[index] - '0';
	auto d2 = digits[index + 1] - '0';

	auto diff = (2 * M_PI) / 10;

	auto a1 = linear_remap(d1, 0, 10, 0, 2 * M_PI) + randn(-diff, diff);
	auto a2 = linear_remap(d2, 0, 10, 0, 2 * M_PI) + randn(-diff, diff);

	auto radius = min(width, height) / 2 - 10;

	auto x1 = radius * cos(a1);
	auto y1 = radius * sin(a1);

	auto x2 = radius * cos(a2);
	auto y2 = radius * sin(a2);

	x1 += width / 2;
	y1 += height / 2;

	x2 += width / 2;
	y2 += height / 2;

	SDL_SetRenderDrawColor(renderer, 255, 255, 255, 50);
	SDL_RenderDrawLineF(renderer, x1, y1, x2, y2);

	index++;
}

void App::draw()
{
	auto now = SDL_GetTicks();
	if (now - start > 20)
	{
		next_line();
		start = now;
	}

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
