#define STB_IMAGE_IMPLEMENTATION
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <cstdarg>
#include <cstdint>
#include <chrono>
#include <vector>
#include <random>
#include <SDL.h>
#include "stb_image.h"

using namespace std;

struct App
{
	SDL_Window *window;
	SDL_Renderer *renderer;
	int width, height;

	SDL_Texture *dvd;
	int dvd_width, dvd_height;

	uint32_t start;
	bool paused;

	SDL_Point pos;
	SDL_Point vel;
	SDL_Color col;

	void init();
	void reset();

	void move();

	void event();
	void update();
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
	default_random_engine engine;
	engine.seed(chrono::system_clock::now().time_since_epoch().count());
	uniform_int_distribution<int> distribution(100, 255);

	SDL_Color col = {};
	col.r = distribution(engine);
	col.g = distribution(engine);
	col.b = distribution(engine);
	col.a = 255;
	return col;
}

SDL_Texture *load_image(SDL_Renderer *re, const char *name, int &width, int &height)
{
	int comp;
	auto data = stbi_load(name, &width, &height, &comp, STBI_default);
	if (!data)
		fatal("Failed to load image: %s", name);

	auto texture = SDL_CreateTexture(re, SDL_PIXELFORMAT_RGBA32, SDL_TEXTUREACCESS_STATIC, width, height);
	if (!texture)
		fatal("Failed to create texture: %s", SDL_GetError());

	SDL_UpdateTexture(texture, NULL, data, width * comp);
	SDL_SetTextureBlendMode(texture, SDL_BLENDMODE_BLEND);
	free(data);

	return texture;
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

	SDL_SetWindowTitle(window, "Bouncing DVD Logo");
	SDL_SetRenderDrawBlendMode(renderer, SDL_BLENDMODE_BLEND);

	dvd = load_image(renderer, "dvd_logo.png", dvd_width, dvd_height);

	reset();
}

void App::reset()
{
	pos = { (width - dvd_width) / 2, (height - dvd_height) / 2 };
	vel = { 5, 5 };
	col = random_color();

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
				width = ev.window.data1;
				height = ev.window.data2;
				break;
			}
			break;
		}
	}
}

void App::move()
{
	pos.x += vel.x;
	pos.y += vel.y;

	if (pos.x + dvd_width >= width)
	{
		vel.x = -vel.x;
		pos.x = width - dvd_width;
		col = random_color();
	}
	else if (pos.x <= 0)
	{
		vel.x = -vel.x;
		pos.x = 0;
		col = random_color();
	}

	if (pos.y + dvd_height >= height)
	{
		vel.y = -vel.y;
		pos.y = height - dvd_height;
		col = random_color();
	}
	else if (pos.y <= 0)
	{
		vel.y = -vel.y;
		pos.y = 0;
		col = random_color();
	}
}

void App::update()
{
	auto now = SDL_GetTicks();
	if (now - start < 30)
		return;

	if (!paused)
		move();

	start = now;
}

void App::draw()
{
	SDL_SetRenderDrawColor(renderer, 50, 60, 70, 255);
	SDL_RenderClear(renderer);

	auto dstrect = SDL_Rect{ pos.x, pos.y, dvd_width, dvd_height };
	SDL_SetTextureColorMod(dvd, col.r, col.g, col.b);
	SDL_RenderCopy(renderer, dvd, NULL, &dstrect);

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
