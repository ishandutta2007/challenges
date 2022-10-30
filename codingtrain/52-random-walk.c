#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <SDL.h>

#define min(a, b) (((a) < (b)) ? (a) : (b))

SDL_Window *window;
SDL_Renderer *renderer;
SDL_Texture *texture;

Uint32 start;

int pause;
int pointsize;

SDL_Point pos;

int
randn(int n)
{
	int r;

	if (n == 0)
		return 0;

	do {
		r = rand();
	} while (r >= (RAND_MAX - (RAND_MAX % n)));

	return (r % n) + 1;
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

void
clear(SDL_Texture *t)
{
	SDL_SetRenderTarget(renderer, t);
	SDL_SetRenderDrawColor(renderer, 51, 51, 51, 255);
	SDL_RenderClear(renderer);
}

void
resize(int w, int h)
{
	SDL_Texture *t;
	SDL_Rect r;
	int tw, th;

	t = SDL_CreateTexture(renderer, SDL_PIXELFORMAT_ARGB8888, SDL_TEXTUREACCESS_TARGET, w, h);
	if (!t)
		fatal("Failed to create texture: %s", SDL_GetError());
	SDL_SetTextureBlendMode(t, SDL_BLENDMODE_BLEND);

	if (texture) {
		clear(t);

		SDL_QueryTexture(texture, NULL, NULL, &tw, &th);
		tw = min(w, tw);
		th = min(h, th);

		r = (SDL_Rect){0, 0, tw, th};
		SDL_RenderCopy(renderer, texture, &r, &r);
		SDL_DestroyTexture(texture);
	}

	texture = t;
}

void
initsdl(void)
{
	int w, h;

	if (SDL_Init(SDL_INIT_VIDEO | SDL_INIT_TIMER) < 0)
		fatal("Failed to init SDL: %s", SDL_GetError());

	w = 1024;
	h = 768;
	if (SDL_CreateWindowAndRenderer(w, h, SDL_WINDOW_RESIZABLE, &window, &renderer) < 0)
		fatal("Failed to create window: %s", SDL_GetError());

	SDL_SetWindowTitle(window, "Random Walk");
	SDL_SetRenderDrawBlendMode(renderer, SDL_BLENDMODE_BLEND);
	resize(w, h);
}

void
reset(void)
{
	int w, h;

	pointsize = 2;

	SDL_GetRendererOutputSize(renderer, &w, &h);
	pos.x = (w / 2) / pointsize;
	pos.y = (h / 2) / pointsize;

	clear(texture);
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
move(void)
{
	SDL_Rect r;

	switch (randn(4) & 3) {
	case 0:
		pos.x--;
		break;
	case 1:
		pos.x++;
		break;
	case 2:
		pos.y--;
		break;
	case 3:
		pos.y++;
		break;
	}

	r = (SDL_Rect){
	    pos.x * pointsize,
	    pos.y * pointsize,
	    pointsize,
	    pointsize,
	};

	SDL_SetRenderTarget(renderer, texture);
	SDL_SetRenderDrawColor(renderer, 255, 255, 255, 100);
	SDL_RenderFillRect(renderer, &r);
}

void
update(void)
{
	Uint32 ticks;

	ticks = SDL_GetTicks();
	if (ticks - start < 20)
		return;

	if (!pause)
		move();

	start = ticks;
}

void
draw(void)
{
	clear(NULL);
	SDL_RenderCopy(renderer, texture, NULL, NULL);
	SDL_RenderPresent(renderer);
}

int
main(void)
{
	srand(time(NULL));
	initsdl();
	reset();

	for (;;) {
		event();
		update();
		draw();
	}
	return 0;
}
