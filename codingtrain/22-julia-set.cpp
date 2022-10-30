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

	uint32_t start;
	bool paused;

	double angle;
	double view;
	int iterations;

	void resize(int new_width, int new_height);

	void init();
	void reset();

	void event();
	void update();
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

// h[0-360], sv[0-1]
// rgb [0-1]
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

	SDL_SetWindowTitle(window, "Julia Set");

	resize(width, height);
	reset();
}

void App::reset()
{
	angle = 0;
	view = 6;
	iterations = 50;
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
			case SDLK_UP:
				view -= 0.05;
				break;
			case SDLK_DOWN:
				view += 0.05;
				break;
			case SDLK_RETURN:
				paused = !paused;
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

void App::render()
{
	void *data;
	int pitch;
	SDL_LockTexture(texture, NULL, &data, &pitch);
	auto pixels = (uint32_t *)data;

	auto ca = cos(angle * 3.213);
	auto cb = sin(angle);

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
				float aa = a * a;
				float bb = b * b;
				if (aa + bb > 4.0)
					break;

				float twoab = 2.0 * a * b;
				a = aa - bb + ca;
				b = twoab + cb;
			}

			if (n == iterations)
				pixels[j * width + i] = color(0, 0, 0);
			else
			{
				double cr, cg, cb;
				auto hue = sqrt(n * 1.0 / iterations) * 360;
				hsv2rgb(cr, cg, cb, hue, 1, 0.88);

				pixels[j * width + i] = color(cr, cg, cb);
			}

			x += dx;
		}
		y += dy;
	}

	SDL_UnlockTexture(texture);
}

void App::update()
{
	auto now = SDL_GetTicks();
	if (now - start < 10)
		return;

	if (!paused)
		angle += 0.01;

	start = now;
}

void App::draw()
{
	SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
	SDL_RenderClear(renderer);

	render();

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
		app->update();
		app->draw();
	}

	return 0;
}
