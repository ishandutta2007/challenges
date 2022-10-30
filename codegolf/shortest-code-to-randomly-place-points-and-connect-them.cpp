/*

The Task

This is quite a simple coding task, all your program has to do is place a point on a canvas (or your alternative in another coding language) and connect it to all the dots already placed. Your program must take in one input, the number of dots that should be placed, and output some sort of display with the dots connected. Example

Requirements

I have to be able to run it, which means that it has to have a compiler/tool to run it either online, or publicly available to download.
You are allowed to use any library created before this challenge was set, as long as it wasn't designed for the sole purpose of solving this.
This is a shortest code task, which means characters. Comments, code that changes colour (for prettiness) and libraries will be ignored.
Your answer must be unique, don't steal other peoples code, shorten it a few characters and repost it.
It must be able to run in less than 5 minutes, for the values of 5 and 100. It must also use a resolution of at least 200*200 and put each dot in a random location on the canvas using a non-trivial distribution.

*/

#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <cstdarg>
#include <algorithm>
#include <chrono>
#include <vector>
#include <random>
#include <SDL.h>

using namespace std;

struct App
{
	SDL_Window *window;
	SDL_Renderer *renderer;

	vector<SDL_Point> points;
	vector<SDL_Color> colors;
	vector<bool> occupied;

	int pointsize;
	int numpoints;

	int width;
	int height;

	SDL_Point sample_point();

	void mark_occupied(int x, int y, int n);
	bool is_occupied(int x, int y);

	void init();
	void reset();
	void regenerate();

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

SDL_Color random_color()
{
	random_device rd;
	mt19937 gen(rd());
	uniform_int_distribution<> dis(0, 255);
	return {
		(Uint8)dis(gen),
		(Uint8)dis(gen),
		(Uint8)dis(gen),
		255,
	};
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

	SDL_SetWindowTitle(window, "Network of Dots");
	SDL_SetRenderDrawBlendMode(renderer, SDL_BLENDMODE_BLEND);

	reset();
}

void App::reset()
{
	numpoints = 50;
	pointsize = 10;
	regenerate();
}

void App::mark_occupied(int x, int y, int n)
{
	for (auto i = 0; i < n; i++)
	{
		for (auto j = 0; j < n; j++)
		{
			size_t z = (y + i) * width + (x + j);
			if (z < occupied.size())
				occupied[z] = true;
		}
	}
}

bool App::is_occupied(int x, int y)
{
	size_t i = y * width + x;
	if (i >= occupied.size())
		return true;
	return occupied[i];
}

SDL_Point App::sample_point()
{
	random_device rd;
	mt19937 gen(rd());
	uniform_int_distribution<> xdis(0, width);
	uniform_int_distribution<> ydis(0, height);

	auto tries = width * height;
	for (auto i = 0; i < tries; i++)
	{
		auto x = xdis(gen);
		auto y = ydis(gen);
		if (!is_occupied(x, y))
		{
			mark_occupied(x, y, pointsize * 5);
			return { x, y };
		}
	}

	for (auto y = 0; y < height; y++)
	{
		for (auto x = 0; x < width; x++)
		{
			if (!is_occupied(x, y))
			{
				mark_occupied(x, y, pointsize * 5);
				return { x, y };
			}
		}
	}

	return { -1, -1 };
}

void App::regenerate()
{
	printf("Number of points: %d\n", numpoints);

	points.resize(numpoints);
	colors.resize(numpoints);
	occupied.resize(width * height);

	for (auto i = 0u; i < occupied.size(); i++)
		occupied[i] = false;

	for (auto i = 0; i < numpoints; i++)
	{
		points[i] = sample_point();
		colors[i] = random_color();
	}

	render();
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
				regenerate();
				break;
			case SDLK_LEFT:
				if (numpoints > 0)
					numpoints--;
				regenerate();
				break;
			case SDLK_RIGHT:
				numpoints++;
				regenerate();
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
				regenerate();
				break;
			}
			break;
		}
	}
}

void App::render()
{
	SDL_SetRenderDrawColor(renderer, 30, 30, 30, 255);
	SDL_RenderClear(renderer);

	SDL_SetRenderDrawColor(renderer, 89, 151, 187, 255);
	for (auto i = 0u; i < points.size(); i++)
	{
		for (auto j = i + 1; j < points.size(); j++)
			SDL_RenderDrawLine(renderer, points[i].x, points[i].y, points[j].x, points[j].y);
	}

	for (auto i = 0u; i < points.size(); i++)
	{
		auto rect = SDL_Rect{ points[i].x, points[i].y, pointsize, pointsize };
		SDL_SetRenderDrawColor(renderer, colors[i].r, colors[i].g, colors[i].b, colors[i].a);
		SDL_RenderFillRect(renderer, &rect);
	}
}

void App::draw()
{
	SDL_RenderPresent(renderer);
}

int main()
{
	auto app = new App();
	app->init();
	for (;;)
	{
		app->event();
		app->draw();
	}

	return 0;
}
