#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <cstdarg>
#include <cstdint>
#include <algorithm>
#include <vector>
#include <random>
#include <chrono>
#include <SDL.h>

#define deg2rad(x) (((x)*M_PI) / 180)

using namespace std;

struct Boundary
{
	SDL_FPoint a, b;

	void show(SDL_Renderer *renderer);
};

struct Ray
{
	SDL_FPoint *pos;
	SDL_FPoint dir;

	void init(SDL_FPoint *position, float angle);
	SDL_FPoint cast(Boundary &wall);
	void show(SDL_Renderer *renderer);
};

struct Particle
{
	SDL_FPoint pos;
	vector<Ray> rays;

	void init(int width, int height);
	void look(SDL_Renderer *renderer, vector<Boundary> &walls);
	void show(SDL_Renderer *renderer);
};

struct App
{
	SDL_Window *window;
	SDL_Renderer *renderer;

	int width;
	int height;

	vector<Boundary> walls;
	size_t max_walls;

	Ray ray;
	Particle particle;

	void init();
	void reset();

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

void ellipse(SDL_Renderer *renderer, float cx, float cy, float a, float b, SDL_Color col)
{
	auto thickness = 1.5f / min(a, b);
	for (auto x = 0.0f; x <= a + 1; x++)
	{
		for (auto y = 0.0f; y <= b + 1; y++)
		{
			auto one = (x * x) / (a * a) + (y * y) / (b * b);
			auto error = (one - 1) / thickness;

			if (error > 1)
				break;
			if (error < -1)
				continue;

			SDL_SetRenderDrawColor(renderer, col.r, col.g, col.b, col.a);
			SDL_RenderDrawPointF(renderer, cx + x, cy + y);
			SDL_RenderDrawPointF(renderer, cx - x, cy + y);
			SDL_RenderDrawPointF(renderer, cx - x, cy - y);
			SDL_RenderDrawPointF(renderer, cx + x, cy - y);
		}
	}
}

void Boundary::show(SDL_Renderer *renderer)
{
	SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
	SDL_RenderDrawLineF(renderer, a.x, a.y, b.x, b.y);
}

void Ray::init(SDL_FPoint *position, float angle)
{
	pos = position;
	dir = { cos(angle), sin(angle) };
}

SDL_FPoint Ray::cast(Boundary &wall)
{
	auto x1 = wall.a.x;
	auto y1 = wall.a.y;
	auto x2 = wall.b.x;
	auto y2 = wall.b.y;

	auto x3 = pos->x;
	auto y3 = pos->y;
	auto x4 = pos->x + dir.x;
	auto y4 = pos->y + dir.y;

	auto den = (x1 - x2) * (y3 - y4) - (y1 - y2) * (x3 - x4);
	if (den == 0)
		return { -1, -1 };

	auto t = ((x1 - x3) * (y3 - y4) - (y1 - y3) * (x3 - x4)) / den;
	auto u = -((x1 - x2) * (y1 - y3) - (y1 - y2) * (x1 - x3)) / den;
	if (t > 0 && t < 1 && u > 0)
	{
		SDL_FPoint pt;
		pt.x = x1 + t * (x2 - x1);
		pt.y = y1 + t * (y2 - y1);
		return pt;
	}

	return { -1, -1 };
}

void Ray::show(SDL_Renderer *renderer)
{
	SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
	SDL_RenderDrawLineF(renderer, pos->x, pos->y, pos->x + (dir.x * 10), pos->y + (dir.y * 10));
}

void Particle::init(int width, int height)
{
	pos = { width / 2.0f, height / 2.0f };
	rays.resize(360);
	for (auto a = 0u; a < rays.size(); a++)
		rays[a].init(&pos, deg2rad(a));
}

void Particle::look(SDL_Renderer *renderer, vector<Boundary> &walls)
{
	for (auto i = 0u; i < rays.size(); i++)
	{
		auto &ray = rays[i];
		auto closest = SDL_FPoint{ -1, -1 };
		auto record = FLT_MAX;
		for (auto &wall : walls)
		{
			auto pt = ray.cast(wall);
			if (pt.x != -1)
			{
				auto d = hypot(pos.x - pt.x, pos.y - pt.y);
				if (d < record)
				{
					record = d;
					closest = pt;
				}
			}
		}

		if (closest.x != -1)
		{
			SDL_SetRenderDrawColor(renderer, 255, 255, 255, 100);
			SDL_RenderDrawLineF(renderer, pos.x, pos.y, closest.x, closest.y);
		}
	}
}

void Particle::show(SDL_Renderer *renderer)
{
	ellipse(renderer, pos.x, pos.y, 4, 4, { 255, 255, 255, 255 });
	for (auto &ray : rays)
		ray.show(renderer);
}

void App::init()
{
	if (SDL_Init(SDL_INIT_VIDEO | SDL_INIT_TIMER) < 0)
		fatal("Failed to init SDL: %s", SDL_GetError());

	width = 1024;
	height = 768;
	window = SDL_CreateWindow("Raycasting", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, width, height, SDL_WINDOW_RESIZABLE);
	if (!window)
		fatal("Failed to create window: %s", SDL_GetError());

	renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_PRESENTVSYNC | SDL_RENDERER_ACCELERATED);
	if (!renderer)
		fatal("Failed to create renderer: %s", SDL_GetError());

	SDL_SetRenderDrawBlendMode(renderer, SDL_BLENDMODE_BLEND);

	max_walls = 5;
	reset();
}

void App::reset()
{
	auto seed = chrono::system_clock::now().time_since_epoch().count();
	default_random_engine generator(seed);
	uniform_real_distribution<float> x_distribution(0.0, width);
	uniform_real_distribution<float> y_distribution(0.0, height);

	walls.resize(max_walls + 4);
	for (auto i = 0u; i < max_walls; i++)
	{
		auto x1 = x_distribution(generator);
		auto x2 = x_distribution(generator);
		auto y1 = y_distribution(generator);
		auto y2 = y_distribution(generator);
		walls[i] = { { x1, y1 }, { x2, y2 } };
	}

	float w = width;
	float h = height;
	walls[max_walls + 3] = { { 0, 0 }, { w, 0 } };
	walls[max_walls + 2] = { { w, 0 }, { w, h } };
	walls[max_walls + 1] = { { w, h }, { 0, h } };
	walls[max_walls] = { { 0, h }, { 0, 0 } };

	particle.init(width / 2, height / 2);
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
			case SDLK_LEFT:
				if (max_walls > 1)
					max_walls--;
				printf("Walls: %zu\n", max_walls);
				reset();
				break;
			case SDLK_RIGHT:
				printf("Walls: %zu\n", ++max_walls);
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

void App::draw()
{
	SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
	SDL_RenderClear(renderer);

	for (auto &wall : walls)
		wall.show(renderer);

	int mousex, mousey;
	SDL_GetMouseState(&mousex, &mousey);
	particle.pos = { (float)mousex, (float)mousey };

	particle.show(renderer);
	particle.look(renderer, walls);

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
