#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <cstdarg>
#include <cstdint>
#include <algorithm>
#include <vector>
#include <SDL.h>

using namespace std;

struct Segment
{
	SDL_FPoint a, b;

	vector<Segment> subdivide();
};

struct App
{
	SDL_Window *window;
	SDL_Renderer *renderer;

	vector<Segment> segments;

	int width, height;

	void resize(int new_width, int new_height);

	void init();
	void reset();

	void next_generation();

	void event();
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

SDL_FPoint rotate(SDL_FPoint p, float x, float y, float c)
{
	auto si = sin(c);
	auto co = cos(c);
	auto nx = co * (p.x - x) - si * (p.y - y) + x;
	auto ny = si * (p.x - x) + co * (p.y - y) + y;
	p.x = nx;
	p.y = ny;
	return p;
}

vector<Segment> Segment::subdivide()
{
	SDL_FPoint v = { (b.x - a.x) / 3, (b.y - a.y) / 3 };
	SDL_FPoint b1 = { a.x + v.x, a.y + v.y };
	SDL_FPoint a1 = { b.x - v.x, b.y - v.y };
	v = rotate(v, 0, 0, -M_PI / 3);
	SDL_FPoint c = { b1.x + v.x, b1.y + v.y };

	return {
		{ a, b1 },
		{ a1, b },
		{ b1, c },
		{ c, a1 },
	};
}

void App::resize(int new_width, int new_height)
{
	width = new_width;
	height = new_height;
}

void App::init()
{
	if (SDL_Init(SDL_INIT_VIDEO | SDL_INIT_TIMER) < 0)
		fatal("Failed to init SDL: %s", SDL_GetError());

	width = 600;
	height = 800;
	auto wflag = SDL_WINDOW_RESIZABLE;
	if (SDL_CreateWindowAndRenderer(width, height, wflag, &window, &renderer) < 0)
		fatal("Failed to create a window: %s", SDL_GetError());

	SDL_SetWindowTitle(window, "Koch Snowflake");
	SDL_SetRenderDrawBlendMode(renderer, SDL_BLENDMODE_BLEND);

	resize(width, height);
}

void App::reset()
{
	SDL_FPoint a = { 0, 100 };
	SDL_FPoint b = { width * 1.0f, 100 };
	float l = hypot(a.x - b.x, a.y - b.y);
	float h = l * sqrt(3) * 0.5;
	SDL_FPoint c = { width * 0.5f, 100 + h };

	segments.clear();
	segments.push_back({ a, b });
	segments.push_back({ b, c });
	segments.push_back({ c, a });
}

void App::next_generation()
{
	vector<Segment> list;
	for (auto &segment : segments)
	{
		auto childrens = segment.subdivide();
		for (auto children : childrens)
			list.push_back(children);
	}
	segments = list;
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

		case SDL_MOUSEBUTTONDOWN:
			next_generation();
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

void App::draw()
{
	SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
	SDL_RenderClear(renderer);

	SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
	for (auto &segment : segments)
		SDL_RenderDrawLine(renderer, segment.a.x, segment.a.y + 100, segment.b.x, segment.b.y + 100);

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
