#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <SDL.h>

SDL_Window *window;
SDL_Renderer *renderer;
SDL_Texture *texture;

int width, height;

float **current;
float **previous;
float dampening;

Uint32 start;

int pause;

Uint32
color(float col)
{
	Uint32 r, g, b, a;

	if (col < 0 || col > 255)
		col = 0;
	r = col;
	g = col;
	b = col;
	a = 255;
	return b | g << 8 | r << 16 | a << 24;
}

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

void
resize(int w, int h)
{
	int y;

	if (texture)
		SDL_DestroyTexture(texture);

	texture = SDL_CreateTexture(renderer, SDL_PIXELFORMAT_ARGB8888, SDL_TEXTUREACCESS_STREAMING, w, h);
	if (!texture)
		fatal("Failed to create texture: %s", SDL_GetError());

	for (y = 0; y < height; y++) {
		free(current[y]);
		free(previous[y]);
	}
	free(current);
	free(previous);

	current = xcalloc(h, sizeof(*current));
	previous = xcalloc(h, sizeof(*previous));
	for (y = 0; y < h; y++) {
		current[y] = xcalloc(w, sizeof(*current[y]));
		previous[y] = xcalloc(w, sizeof(*previous[y]));
	}

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

	SDL_SetWindowTitle(window, "Water Ripple");
	SDL_SetRenderDrawBlendMode(renderer, SDL_BLENDMODE_BLEND);

	resize(w, h);
}

void
reset(void)
{
	int x, y;

	for (y = 0; y < height; y++) {
		for (x = 0; x < width; x++) {
			current[y][x] = 0;
			previous[y][x] = 0;
		}
	}
	dampening = 0.99;

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
				break;
			}
			break;
		}
	}
}

void
updateripples(void)
{
	Uint32 button;
	float **temp;
	int mx, my;
	int x, y;

	button = SDL_GetMouseState(&mx, &my) & SDL_BUTTON_LMASK;
	if (button) {
		if (mx > 0 && my > 0 && mx < width - 1 && my < height - 1)
			previous[my][mx] = 500;
	}

	for (y = 1; y < height - 1; y++) {
		for (x = 1; x < width - 1; x++) {
			current[y][x] = (previous[y - 1][x] + previous[y + 1][x] + previous[y][x - 1] + previous[y][x + 1]) / 2 - current[y][x];
			current[y][x] *= dampening;
		}
	}

	temp = previous;
	previous = current;
	current = temp;
}

void
update(void)
{
	Uint32 ticks;
	int dt;

	ticks = SDL_GetTicks();
	dt = ticks - start;
	if (dt < 16)
		return;

	if (!pause)
		updateripples();

	start = ticks;
}

void
drawripples(void)
{
	Uint32 *pixels;
	void *data;
	int pitch;
	int x, y;

	SDL_LockTexture(texture, NULL, &data, &pitch);
	pixels = data;

	for (y = 0; y < height; y++) {
		for (x = 0; x < width; x++) {
			pixels[y * width + x] = color(current[y][x]);
		}
	}
	SDL_UnlockTexture(texture);
}

void
draw(void)
{
	SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
	SDL_RenderClear(renderer);
	drawripples();
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
