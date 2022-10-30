#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <cstdarg>
#include <algorithm>
#include <SDL.h>

using namespace std;

struct Segment
{
	SDL_FPoint a;
	SDL_FPoint b;
	float t;
	float len;
	float angle;
	float self_angle;
	Segment *parent;
	Segment *child;

	Segment(Segment *parent, float len, float angle, float t);
	Segment(float x, float y, float len, float angle, float t);
	~Segment();

	void wiggle();
	void calculate_b();
	void update();
};

struct App
{
	SDL_Window *window;
	SDL_Renderer *renderer;
	Segment *tentacle;

	Uint32 start;

	int width;
	int height;

	void init();
	void reset();

	void event();
	void update_and_draw();
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

float unlerp(float t, float a, float b)
{
	return (t - a) / (b - a);
}

float linear_remap(float x, float a, float b, float c, float d)
{
	return lerp(c, d, unlerp(x, a, b));
}

Segment::Segment(Segment *parent, float len, float angle, float t)
{
	this->parent = parent;
	this->child = nullptr;
	this->a = parent->b;
	this->len = len;
	this->angle = angle;
	this->self_angle = angle;
	calculate_b();
	this->t = t;
}

Segment::Segment(float x, float y, float len, float angle, float t)
{
	this->a = { x, y };
	this->len = len;
	this->angle = angle;
	this->self_angle = angle;
	calculate_b();
	this->parent = nullptr;
	this->child = nullptr;
	this->t = t;
}

Segment::~Segment()
{
	if (parent)
		return;

	auto current = child;
	while (current)
	{
		auto next = current->child;
		delete current;
		current = next;
	}
}

void Segment::wiggle()
{
	auto maxangle = 0.3f;
	auto minangle = -0.3f;
	self_angle = linear_remap(sin(t), -1, 1, minangle, maxangle);
	t += 0.1;
}

void Segment::calculate_b()
{
	auto dx = len * cos(angle);
	auto dy = len * sin(angle);
	b = { a.x + dx, a.y + dy };
}

void Segment::update()
{
	angle = self_angle;
	if (parent != nullptr)
	{
		a = parent->b;
		angle += parent->angle;
	}
	else
		angle -= M_PI / 2;

	calculate_b();
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

	SDL_SetWindowTitle(window, "Forward Kinematics");
	SDL_SetRenderDrawBlendMode(renderer, SDL_BLENDMODE_BLEND);

	reset();
}

void App::reset()
{
	delete tentacle;

	auto t = 0.0f;
	auto len = width / 12;
	tentacle = new Segment(width / 2, height, len, 0, t);
	auto current = tentacle;
	for (auto i = 0; i < 20; i++)
	{
		t += 0.1;
		len *= 0.75;
		auto next = new Segment(current, len, 0, t);
		current->child = next;
		current = next;
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

void App::update_and_draw()
{
	SDL_SetRenderDrawColor(renderer, 51, 51, 51, 255);
	SDL_RenderClear(renderer);

	auto update = false;
	auto now = SDL_GetTicks();
	if (now - start >= 50)
	{
		update = true;
		start = now;
	}

	SDL_SetRenderDrawColor(renderer, 200, 200, 200, 255);
	for (auto segment = tentacle; segment; segment = segment->child)
	{
		if (update)
		{
			segment->wiggle();
			segment->update();
		}
		SDL_RenderDrawLineF(renderer, segment->a.x, segment->a.y, segment->b.x, segment->b.y);
	}

	SDL_RenderPresent(renderer);
}

int main()
{
	auto app = new App();
	app->init();
	for (;;)
	{
		app->event();
		app->update_and_draw();
	}

	return 0;
}
