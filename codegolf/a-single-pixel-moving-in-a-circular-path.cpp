/*

This is a graphical output challenge where the task is to give the shortest code per language.

Task

Your code should plot a single purple pixel (hex value #800080 or rgb(128, 0, 128)), moving clockwise round a circle.
It should take exactly 60 seconds to make a full journey round the circle and should continue indefinitely.
Nothing else should be shown on the screen or window except for the pixel.
The width of the circle should be 0.75 (rounding suitably) the width of the screen or window and the background should be white.
To prevent silly solutions, the screen or window should be at least 100 pixels wide.

*/

#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cerrno>
#include <SDL.h>

struct Vec2
{
	float x, y;
};

struct Thing
{
	Vec2 center;
	float radius;
	float phase;
	float size;
	double tick;
	SDL_Color color;

	void update(double dt)
	{
		tick += dt;
		if (tick >= 0.01)
		{
			phase = fmod(phase + 2e-2, 2 * M_PI);
			tick = 0;
		}
	}

	void draw(SDL_Renderer *re)
	{
		auto r = SDL_FRect{
			center.x + radius * cosf(phase),
			center.y + radius * sinf(phase),
			size,
			size,
		};
		auto &c = color;

		SDL_SetRenderDrawColor(re, c.r, c.g, c.b, c.a);
		SDL_RenderFillRectF(re, &r);
	}
};

SDL_Window *window;
SDL_Renderer *renderer;
Thing thing;
Uint32 start_time;

void fatal(const char *fmt, ...)
{
	va_list ap;

	va_start(ap, fmt);
	vfprintf(stderr, fmt, ap);
	va_end(ap);
	fprintf(stderr, "\n");
	exit(1);
}

void init_sdl()
{
	if (SDL_Init(SDL_INIT_VIDEO | SDL_INIT_TIMER) < 0)
		fatal("Failed to init SDL: %s", strerror(errno));

	if (SDL_CreateWindowAndRenderer(800, 600, SDL_WINDOW_RESIZABLE, &window, &renderer) < 0)
		fatal("Failed to create window: %s", strerror(errno));

	SDL_SetWindowTitle(window, "Circular Path");
}

void reset()
{
	int w, h;
	SDL_GetRendererOutputSize(renderer, &w, &h);

	thing.center = Vec2{ w / 2.0f, h / 2.0f };
	thing.radius = 100;
	thing.phase = 0;
	thing.size = 10;
	thing.color = SDL_Color{ 100, 150, 200, 255 };

	start_time = SDL_GetTicks();
}

void event()
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
		}
	}
}

void update()
{
	auto now = SDL_GetTicks();
	double dt = (now - start_time) / 1e3;
	thing.update(dt);
	start_time = now;
}

void draw()
{
	SDL_SetRenderDrawColor(renderer, 50, 60, 70, 255);
	SDL_RenderClear(renderer);
	thing.draw(renderer);
	SDL_RenderPresent(renderer);
}

int main()
{
	init_sdl();
	reset();
	for (;;)
	{
		event();
		update();
		draw();
	}
	return 0;
}
