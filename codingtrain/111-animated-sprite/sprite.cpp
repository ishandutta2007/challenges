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

struct Sprite
{
	SDL_Texture *image;
	vector<SDL_Rect> *animation;
	float x, y;
	float speed;
	float index;
	int *width;

	void move();
	void show(SDL_Renderer *renderer);
};

struct App
{
	SDL_Window *window;
	SDL_Renderer *renderer;
	int width, height;

	SDL_Texture *image;
	vector<SDL_Rect> animation;

	vector<Sprite> sprites;
	size_t max_sprites;

	uint32_t start;
	bool paused;

	void init();
	void reset();

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

void load_animation(const char *name, vector<SDL_Rect> &animation)
{
	animation.clear();

	auto fp = fopen(name, "rb");
	if (!fp)
		fatal("Failed to load sprite: %s", name);

	char line[128];
	while (fgets(line, sizeof(line), fp))
	{
		SDL_Rect rect;
		char str[32];

		if (sscanf(line, "%31s %d %d %d %d", str, &rect.x, &rect.y, &rect.w, &rect.h) == 5)
			animation.push_back(rect);
	}
	if (animation.size() == 0)
		fatal("No animation found");

	fclose(fp);
}

void Sprite::move()
{
	index += speed;
	x += speed * 15;
	if (x > *width)
		x = -(*animation)[0].w;
}

void Sprite::show(SDL_Renderer *renderer)
{
	auto i = ((int)index) % animation->size();
	SDL_Rect src = (*animation)[i];
	SDL_FRect dst = { x, y, (float)src.w, (float)src.h };
	SDL_RenderCopyF(renderer, image, &src, &dst);
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

	SDL_SetWindowTitle(window, "Animated Sprites");
	SDL_SetRenderDrawBlendMode(renderer, SDL_BLENDMODE_BLEND);

	int image_width, image_height;
	image = load_image(renderer, "horse.png", image_width, image_height);
	load_animation("horse.txt", animation);

	max_sprites = 5;

	reset();
}

void App::reset()
{
	default_random_engine generator;
	uniform_real_distribution<double> distribution(0.1, 0.4);

	sprites.resize(max_sprites);
	for (auto i = 0u; i < sprites.size(); i++)
	{
		auto &sprite = sprites[i];
		sprite.x = 0;
		sprite.y = i * 75;
		sprite.speed = distribution(generator);
		sprite.index = 0;
		sprite.width = &width;
		sprite.animation = &animation;
		sprite.image = image;
	}

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
			case SDLK_LEFT:
				if (max_sprites > 1)
					max_sprites--;
				reset();
				break;
			case SDLK_RIGHT:
				if (max_sprites < 100)
					max_sprites++;
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
				break;
			}
			break;
		}
	}
}

void App::update()
{
	auto now = SDL_GetTicks();
	if (now - start < 16)
		return;

	if (!paused)
	{
		for (auto &sprite : sprites)
			sprite.move();
	}

	start = now;
}

void App::draw()
{
	SDL_SetRenderDrawColor(renderer, 50, 60, 70, 255);
	SDL_RenderClear(renderer);

	for (auto &sprite : sprites)
		sprite.show(renderer);

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
