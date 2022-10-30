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

	void init();

	void event();
	void circles(float x, float y, float d);
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

// https://create.stephan-brumme.com/antialiased-circle/#antialiased-circle-implicit
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

	auto width = 800;
	auto height = 600;
	auto wflag = SDL_WINDOW_RESIZABLE;
	if (SDL_CreateWindowAndRenderer(width, height, wflag, &window, &renderer) < 0)
		fatal("Failed to create a window: %s", SDL_GetError());

	SDL_SetWindowTitle(window, "Recursion");
	SDL_SetRenderDrawBlendMode(renderer, SDL_BLENDMODE_BLEND);

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
			}
			break;

		case SDL_WINDOWEVENT:
			switch (ev.window.event)
			{
			case SDL_WINDOWEVENT_RESIZED:
			case SDL_WINDOWEVENT_SIZE_CHANGED:
				render();
				break;
			}
			break;
		}
	}
}

void App::circles(float x, float y, float d)
{
	ellipse(renderer, x, y, d, d, { 255, 255, 255, 255 });
	if (d > 2)
	{
		auto nd = d * 0.25;
		circles(x + nd, y, nd);
		circles(x - nd, y, nd);
	}
}

void App::render()
{
	SDL_SetRenderDrawColor(renderer, 30, 30, 30, 255);
	SDL_RenderClear(renderer);

	int w, h;
	SDL_GetRendererOutputSize(renderer, &w, &h);
	circles(w / 2, h / 2, w);
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
