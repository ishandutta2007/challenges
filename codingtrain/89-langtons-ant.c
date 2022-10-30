#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <SDL.h>

typedef struct {
	int x, y;
	int dir;
} Ant;

SDL_Window *window;
SDL_Renderer *renderer;
SDL_Texture *texture;

int width, height;

int **grid;
Ant ant;

Uint32 start;

int pause;

void
fatal(const char *fmt, ...)
{
	va_list ap;

	va_start(ap, fmt);
	vfprintf(stderr, fmt, ap);
	va_end(ap);
	fprintf(stderr, "\n");
	exit(1);
}

void *
xcalloc(size_t nmemb, size_t size)
{
	void *p;

	if (!nmemb)
		nmemb = 1;
	if (!size)
		size = 1;
	p = calloc(nmemb, size);
	if (!p)
		abort();
	return p;
}

int
wrap(int x, int a, int b)
{
	if (x < a)
		x = b;
	else if (x > b)
		x = a;
	return x;
}

void
resize(int w, int h)
{
	int y;

	if (texture)
		SDL_DestroyTexture(texture);

	texture = SDL_CreateTexture(renderer, SDL_PIXELFORMAT_ARGB8888, SDL_TEXTUREACCESS_STREAMING, w, h);
	if (!texture)
		fatal("Failed to create texture: %s", SDL_GetError());

	for (y = 0; y < height; y++)
		free(grid[y]);
	free(grid);

	grid = xcalloc(h, sizeof(*grid));
	for (y = 0; y < h; y++)
		grid[y] = xcalloc(w, sizeof(*grid[y]));

	width = w;
	height = h;
}

void
initsdl(void)
{
	int w, h;

	if (SDL_Init(SDL_INIT_VIDEO | SDL_INIT_TIMER) < 0)
		fatal("Failed to init SDL: %s", SDL_GetError());

	w = 800;
	h = 600;
	if (SDL_CreateWindowAndRenderer(w, h, SDL_WINDOW_RESIZABLE, &window, &renderer) < 0)
		fatal("Failed to create window: %s", SDL_GetError());

	SDL_SetWindowTitle(window, "Langstons Ant");
	SDL_SetRenderDrawBlendMode(renderer, SDL_BLENDMODE_BLEND);

	resize(w, h);
}

void
reset(void)
{
	int x, y;

	ant.x = width / 2;
	ant.y = height / 2;
	ant.dir = 0;
	for (y = 0; y < height; y++) {
		for (x = 0; x < width; x++) {
			grid[y][x] = 1;
		}
	}

	start = SDL_GetTicks();
}

void
event(void)
{
	SDL_Event ev;

	while (SDL_PollEvent(&ev)) {
		switch (ev.type) {
		case SDL_QUIT:
			exit(0);

		case SDL_KEYDOWN:
			switch (ev.key.keysym.sym) {
			case SDLK_ESCAPE:
				exit(0);

			case SDLK_SPACE:
				pause = !pause;
				break;

			case SDLK_RETURN:
				reset();
				break;
			}
			break;

		case SDL_WINDOWEVENT:
			switch (ev.window.event) {
			case SDL_WINDOWEVENT_RESIZED:
			case SDL_WINDOWEVENT_SIZE_CHANGED:
				resize(ev.window.data1, ev.window.data2);
				reset();
				break;
			}
			break;
		}
	}
}

void
step(int n)
{
	int state;
	int i;

	for (i = 0; i < n; i++) {
		state = grid[ant.y][ant.x];
		if (state == 0) {
			ant.dir = (ant.dir + 1) & 3;
			grid[ant.y][ant.x] = 1;
		} else if (state == 1) {
			ant.dir = (ant.dir > 0) ? ant.dir - 1 : 3;
			grid[ant.y][ant.x] = 0;
		}

		switch (ant.dir) {
		case 0:
			ant.y--;
			break;
		case 1:
			ant.x++;
			break;
		case 2:
			ant.y++;
			break;
		case 3:
			ant.x--;
			break;
		default:
			assert(0);
		}

		ant.x = wrap(ant.x, 0, width - 1);
		ant.y = wrap(ant.y, 0, height - 1);
	}
}

void
update(void)
{
	Uint32 ticks;
	int dt;

	ticks = SDL_GetTicks();
	dt = ticks - start;
	if (dt < 100)
		return;

	if (!pause)
		step(100000);

	start = ticks;
}

void
upload(void)
{
	Uint32 *pixels;
	void *data;
	int pitch;
	int x, y;

	SDL_LockTexture(texture, NULL, &data, &pitch);
	pixels = data;

	for (y = 0; y < height; y++) {
		for (x = 0; x < width; x++) {
			pixels[y * width + x] = (grid[y][x]) ? 0xFFFFFFFFUL : 0;
		}
	}
	SDL_UnlockTexture(texture);
}

void
draw(void)
{
	SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
	SDL_RenderClear(renderer);
	upload();
	SDL_RenderCopy(renderer, texture, NULL, NULL);
	SDL_RenderPresent(renderer);
}

int
main(void)
{
	initsdl();
	reset();

	for (;;) {
		event();
		update();
		draw();
	}
	return 0;
}
