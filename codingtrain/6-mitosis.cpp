#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <cstdarg>
#include <cstdint>
#include <algorithm>
#include <vector>
#include <SDL.h>
#include <cairo.h>

using namespace std;

struct Cell
{
	SDL_FPoint position;
	float radius;
	float color[4];

	static Cell make(int width, int height);
	Cell mitosis();

	bool clicked(int x, int y);
	void move();
	void draw(cairo_t *cr);
};

struct App
{
	SDL_Window *window;
	SDL_Renderer *renderer;
	SDL_Texture *texture;

	cairo_surface_t *canvas;
	cairo_t *cr;

	vector<Cell> cells;

	Uint32 start;
	bool paused;

	int width, height;

	void resize(int new_width, int new_height);

	void init();
	void reset();

	void handle_mitosis(int x, int y);
	void event();
	void update();
	void draw_cells();
	void upload();
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

float unlerp(float t, float a, float b)
{
	return (t - a) / (b - a);
}

float linear_remap(float x, float a, float b, float c, float d)
{
	return lerp(c, d, unlerp(x, a, b));
}

Cell Cell::make(int width, int height)
{
	Cell c = {};
	c.position = { (float)(drand48() * width), (float)(drand48() * height) };
	c.radius = 60;
	c.color[0] = drand48();
	c.color[2] = drand48();
	c.color[3] = 0.39;
	return c;
}

Cell Cell::mitosis()
{
	Cell c = {};
	c.position = position;
	c.radius = radius * 0.8;
	memcpy(c.color, color, sizeof(color));
	return c;
}

bool Cell::clicked(int x, int y)
{
	auto dist = hypot(position.x - x, position.y - y);
	return dist < radius;
}

void Cell::move()
{
	position.x += linear_remap(drand48(), 0, 1, -1, 1);
	position.y += linear_remap(drand48(), 0, 1, -1, 1);
}

void Cell::draw(cairo_t *cr)
{
	cairo_set_source_rgba(cr, color[0], color[1], color[2], color[3]);
	cairo_arc(cr, position.x, position.y, radius, 0, 2 * M_PI);
	cairo_fill(cr);
}

void App::resize(int new_width, int new_height)
{
	width = new_width;
	height = new_height;

	if (texture)
		SDL_DestroyTexture(texture);

	if (canvas)
	{
		cairo_surface_destroy(canvas);
		cairo_destroy(cr);
	}

	texture = SDL_CreateTexture(renderer, SDL_PIXELFORMAT_ARGB8888, SDL_TEXTUREACCESS_STREAMING, width, height);
	if (!texture)
		fatal("Failed to create texture: %s", SDL_GetError());

	canvas = cairo_image_surface_create(CAIRO_FORMAT_ARGB32, width, height);
	cr = cairo_create(canvas);
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

	SDL_SetWindowTitle(window, "Mitosis");
	SDL_SetRenderDrawBlendMode(renderer, SDL_BLENDMODE_BLEND);

	resize(width, height);
}

void App::reset()
{
	cells.clear();
	for (int i = 0; i < 10; i++)
		cells.push_back(Cell::make(width, height));
	start = SDL_GetTicks();
}

void App::handle_mitosis(int x, int y)
{
	vector<Cell> new_cells;
	for (ssize_t i = cells.size() - 1; i >= 0; i--)
	{
		auto &c = cells[i];
		if (c.clicked(x, y))
		{
			new_cells.push_back(c.mitosis());
			new_cells.push_back(c.mitosis());
		}
		else
			new_cells.push_back(c);
	}
	cells = new_cells;
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
				paused = !paused;
				break;
			case SDLK_SPACE:
				reset();
				break;
			}
			break;

		case SDL_MOUSEBUTTONDOWN:
			handle_mitosis(ev.button.x, ev.button.y);
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

void App::update()
{
	auto now = SDL_GetTicks();
	if (now - start < 16)
		return;

	if (!paused)
	{
		for (auto &cell : cells)
			cell.move();
	}

	start = now;
}

void App::upload()
{
	void *pixels, *data;
	int pitch;
	SDL_LockTexture(texture, NULL, &pixels, &pitch);
	data = cairo_image_surface_get_data(canvas);
	memcpy(pixels, data, pitch * height);
	SDL_UnlockTexture(texture);
}

void App::draw()
{
	SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
	SDL_RenderClear(renderer);

	cairo_set_source_rgb(cr, 0.78, 0.78, 0.78);
	cairo_paint(cr);
	for (auto &cell : cells)
		cell.draw(cr);

	upload();

	SDL_RenderCopy(renderer, texture, NULL, NULL);
	SDL_RenderPresent(renderer);
}

int main()
{
	srand48(time(NULL));
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
