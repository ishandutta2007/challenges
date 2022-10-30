/*

Introduction

One day, you were showing your kid how to draw on a computer. You type mspaint.exe in the run bar. To your horror, it says "No items match your search". You must create a simple version of paint so your kid can draw!
Challenge

You must create a simple drawing program. To do this, open a white display window (larger than 99x99 pixels). Anytime the mouse is pressed down, change the pixel that the mouse is on to black.

This is code-golf, so shortest answer in bytes wins!

*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <SDL.h>

#define min(a, b) (((a) < (b)) ? (a) : (b))

SDL_Window *window;
SDL_Renderer *renderer;
SDL_Texture *texture;

int pointsize;

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
	SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
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

	SDL_SetWindowTitle(window, "Paint");
	SDL_SetRenderDrawBlendMode(renderer, SDL_BLENDMODE_BLEND);
	resize(w, h);
}

void
reset(void)
{
	pointsize = 10;
	clear(texture);
}

void
pencil(int x, int y, int size, int clear)
{
	SDL_Rect r;
	int c;

	r = (SDL_Rect){x, y, size, size};
	c = (clear) ? 255 : 0;
	SDL_SetRenderTarget(renderer, texture);
	SDL_SetRenderDrawColor(renderer, c, c, c, 255);
	SDL_RenderFillRect(renderer, &r);
}

void
setpointsize(int size)
{
	pointsize = size;
	if (pointsize < 0)
		pointsize = 0;
	else if (pointsize > 100)
		pointsize = 100;
	printf("Point size: %d\n", pointsize);
}

void
event(void)
{
	SDL_Event ev;
	int mousex, mousey;
	int button;

	while (SDL_PollEvent(&ev)) {
		switch (ev.type) {
		case SDL_QUIT:
			exit(0);

		case SDL_KEYDOWN:
			switch (ev.key.keysym.sym) {
			case SDLK_ESCAPE:
				exit(0);

			case SDLK_SPACE:
				reset();
				break;

			case SDLK_UP:
				setpointsize(pointsize + 1);
				break;

			case SDLK_DOWN:
				setpointsize(pointsize - 1);
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

	button = SDL_GetMouseState(&mousex, &mousey);
	if (button & SDL_BUTTON_LMASK)
		pencil(mousex, mousey, pointsize, 0);
	if (button & SDL_BUTTON_RMASK)
		pencil(mousex, mousey, pointsize, 1);
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
	initsdl();
	reset();

	for (;;) {
		event();
		draw();
	}
	return 0;
}
