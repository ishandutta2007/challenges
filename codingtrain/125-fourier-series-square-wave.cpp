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

	int harmonics;
	vector<float> wave;
	size_t max_waves;

	float wave_time;

	bool paused;
	Uint64 start;

	void init();
	void reset();

	void event();
	void update();
	void draw_epicycles_and_waves();
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

void App::init()
{
	if (SDL_Init(SDL_INIT_VIDEO | SDL_INIT_TIMER) < 0)
		fatal("Failed to init SDL: %s", SDL_GetError());

	auto width = 1024;
	auto height = 768;
	window = SDL_CreateWindow("Fourier Series of Square Wave", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, width, height, 0);
	if (!window)
		fatal("Failed to create window: %s", SDL_GetError());

	renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_PRESENTVSYNC | SDL_RENDERER_ACCELERATED);
	if (!renderer)
		fatal("Failed to create renderer: %s", SDL_GetError());

	SDL_SetRenderDrawBlendMode(renderer, SDL_BLENDMODE_BLEND);

	reset();
}

void App::reset()
{
	harmonics = 10;
	max_waves = 500;
	wave_time = 0.0;
	start = SDL_GetPerformanceCounter();
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
				reset();
				break;
			case SDLK_SPACE:
				paused = !paused;
				break;
			case SDLK_LEFT:
				if (harmonics > 1)
					harmonics--;
				printf("Harmonics: %d\n", harmonics);
				break;
			case SDLK_RIGHT:
				harmonics++;
				printf("Harmonics: %d\n", harmonics);
				break;
			}
			break;
		}
	}
}

void App::update()
{
	auto now = SDL_GetPerformanceCounter();
	auto dt = ((now - start) * 1000.0) / SDL_GetPerformanceFrequency();
	start = now;
	if (!paused)
		wave_time += dt * 0.002;
}

void App::draw_epicycles_and_waves()
{
	auto xoff = 350.0;
	auto yoff = 300.0;

	auto x = 0.0;
	auto y = 0.0;
	for (auto i = 0; i < harmonics; i++)
	{
		auto prevx = x;
		auto prevy = y;

		auto n = (2 * i) + 1;
		auto radius = 125 * (4 / (n * M_PI));
		x += radius * cos(n * wave_time);
		y += radius * sin(n * wave_time);

		ellipse(renderer, prevx + xoff, prevy + yoff, radius / 2, radius / 2, { 255, 255, 255, 100 });

		SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
		SDL_RenderDrawLineF(renderer, prevx + xoff, prevy + yoff, x + xoff, y + yoff);
	}

	if (!paused)
	{
		wave.insert(wave.begin(), y);
		wave.resize(max_waves);
	}

	xoff += 200;
	SDL_RenderDrawLineF(renderer, x + xoff - 200, y + yoff, xoff, wave[0] + yoff);
	for (auto i = 0u; i < wave.size() - 1; i++)
		SDL_RenderDrawLineF(renderer, i + xoff, wave[i] + yoff, i + xoff, wave[i + 1] + yoff);
}

void App::draw()
{
	SDL_SetRenderDrawColor(renderer, 30, 30, 30, 255);
	SDL_RenderClear(renderer);

	draw_epicycles_and_waves();

	SDL_RenderPresent(renderer);
}

int main()
{
	auto app = new App();
	app->init();
	for (;;)
	{
		app->event();
		app->update();
		app->draw();
	}

	return 0;
}
