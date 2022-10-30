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

struct Quadtree
{
	SDL_FRect boundary;
	size_t capacity;
	vector<SDL_FPoint> points;
	bool divided;
	Quadtree *regions[4];

	Quadtree(SDL_FRect boundary, size_t capacity);
	~Quadtree();

	bool insert(SDL_FPoint point);
	void subdivide();

	void dump(int indent = 0);
};

struct App
{
	SDL_Window *window;
	SDL_Renderer *renderer;
	Quadtree *qtree;
	vector<SDL_FPoint> points;

	int width;
	int height;

	void init();
	void reset();
	void rebuild();

	void event();
	void render_quad_tree(Quadtree *qtree);
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

bool inside(SDL_FRect r, SDL_FPoint p)
{
	return ((p.x >= r.x) && (p.x < (r.x + r.w)) &&
			(p.y >= r.y) && (p.y < (r.y + r.h)));
}

Quadtree::Quadtree(SDL_FRect boundary, size_t capacity)
{
	this->boundary = boundary;
	this->capacity = capacity;

	divided = false;
	memset(regions, 0, sizeof(regions));
}

Quadtree::~Quadtree()
{
	for (auto region : regions)
		delete region;
}

bool Quadtree::insert(SDL_FPoint point)
{
	if (!inside(boundary, point))
		return false;

	if (points.size() < capacity)
	{
		points.push_back(point);
		return true;
	}

	if (!divided)
		subdivide();

	for (auto region : regions)
	{
		if (region->insert(point))
			return true;
	}
	return false;
}

void Quadtree::subdivide()
{
	auto x = boundary.x;
	auto y = boundary.y;
	auto w = boundary.w;
	auto h = boundary.h;

	regions[0] = new Quadtree({ x, y, w / 2, h / 2 }, capacity);
	regions[1] = new Quadtree({ x + w / 2, y, w / 2, h / 2 }, capacity);
	regions[2] = new Quadtree({ x, y + h / 2, w / 2, h / 2 }, capacity);
	regions[3] = new Quadtree({ x + w / 2, y + h / 2, w / 2, h / 2 }, capacity);

	divided = true;
}

void Quadtree::dump(int indent)
{
	for (int i = 0; i < indent * 4; i++)
		printf(" ");
	printf("(%f, %f)-(%f, %f)\n", boundary.x, boundary.y, boundary.x + boundary.w, boundary.y + boundary.h);

	for (auto region : regions)
	{
		if (!region)
			continue;

		region->dump(indent + 1);
	}
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

	SDL_SetWindowTitle(window, "Quad Tree");
	SDL_SetRenderDrawBlendMode(renderer, SDL_BLENDMODE_BLEND);

	reset();
}

void App::reset()
{
	default_random_engine generator;
	generator.seed(chrono::system_clock::now().time_since_epoch().count());

	normal_distribution<float> x_distribution(width / 2.0f, width / 8.0f);
	normal_distribution<float> y_distribution(height / 2.0f, height / 8.0f);

	points.clear();
	for (auto i = 0; i < 512; i++)
	{
		auto x = x_distribution(generator);
		auto y = y_distribution(generator);
		points.push_back({ x, y });
	}
	rebuild();
}

void App::rebuild()
{
	delete qtree;

	qtree = new Quadtree({ 0, 0, width * 1.0f, height * 1.0f }, 4);
	for (auto point : points)
		qtree->insert(point);

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
				rebuild();
				break;
			}
			break;
		}
	}
}

void App::render_quad_tree(Quadtree *qtree)
{
	SDL_SetRenderDrawColor(renderer, 200, 200, 200, 255);
	SDL_RenderDrawRectF(renderer, &qtree->boundary);
	if (qtree->divided)
	{
		for (auto region : qtree->regions)
			render_quad_tree(region);
	}

	for (auto point : qtree->points)
	{
		SDL_SetRenderDrawColor(renderer, 10, 150, 10, 255);
		SDL_RenderDrawPointF(renderer, point.x, point.y);
	}
}

void App::render()
{
	SDL_SetRenderDrawColor(renderer, 30, 30, 30, 255);
	SDL_RenderClear(renderer);
	render_quad_tree(qtree);
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
