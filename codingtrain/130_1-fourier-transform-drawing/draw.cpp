/*

The idea of drawing a picture with the fourier transform is as follows:
Take the fourier transform of x-coordinates and y-coordinates of the drawing separately.
This gives two list of phasors waves that trace out to the original x/y signal when evolved from [0, 2*pi]
For every value in [0, 2*pi], add up the phasor at that time to get the x/y coordinates.
This is very time step sensitive, the picture will be very different with different sized time steps.

*/

#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <cstdarg>
#include <cstdint>
#include <algorithm>
#include <vector>
#include <SDL.h>

using namespace std;

struct Phasor
{
	float amplitude;
	float frequency;
	float phase;

	SDL_FPoint state(float t, float offset);

	static int compare_amplitude(const void *a, const void *b);
};

struct App
{
	SDL_Window *window;
	SDL_Renderer *renderer;

	vector<SDL_FPoint> path;
	vector<Phasor> x_phasors;
	vector<Phasor> y_phasors;
	float phasor_time;
	float phasor_tick;
	bool finished;

	int coarseness;

	Uint64 start;

	void init();
	void reset();
	void reload();

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

void dft(const vector<float> &in, vector<Phasor> &out)
{
	auto N = in.size();

	out.resize(N);
	for (auto k = 0u; k < N; k++)
	{
		auto re = 0.0f;
		auto im = 0.0f;
		for (auto n = 0u; n < N; n++)
		{
			auto phi = (2 * M_PI * k * n) / N;
			re += in[n] * cos(phi);
			im -= in[n] * sin(phi);
		}
		re /= N;
		im /= N;

		float freq = k;
		auto amp = sqrt((re * re) + (im * im));
		auto phase = atan2(im, re);

		out[k] = { amp, freq, phase };
	}
}

vector<SDL_FPoint> load_points(const char *name)
{
	vector<SDL_FPoint> pts;
	auto fp = fopen(name, "rb");
	if (!fp)
		return pts;

	float x, y;
	while (fscanf(fp, "%f %f", &x, &y) == 2)
		pts.push_back({ x, y });

	fclose(fp);
	return pts;
}

void load_train(const char *name, int skip, vector<Phasor> &X, vector<Phasor> &Y)
{
	auto pts = load_points(name);
	auto len = pts.size();

	vector<float> x, y;
	for (auto i = 0u; i < len; i += skip)
	{
		x.push_back(pts[i].x);
		y.push_back(pts[i].y);
	}

	dft(x, X);
	dft(y, Y);

	if (X.size() > 0)
	{
		qsort(&X[0], X.size(), sizeof(X[0]), Phasor::compare_amplitude);
		qsort(&Y[0], Y.size(), sizeof(Y[0]), Phasor::compare_amplitude);
	}
}

void ellipse(SDL_Renderer *renderer, float cx, float cy, float a, float b, SDL_Color col)
{
	auto thickness = 1.5f / min(a, b);
	for (auto x = 0.0f; x <= a + 1; x++)
	{
		for (auto y = 0.0f; y <= b + 1; y++)
		{
			auto one = (x * x) / (a * a) + (y * y) / (b * b);
			auto error = (one - 1) / thickness;

			if (error > 1)
				break;
			if (error < -1)
				continue;

			SDL_SetRenderDrawColor(renderer, col.r, col.g, col.b, col.a);
			SDL_RenderDrawPointF(renderer, cx + x, cy + y);
			SDL_RenderDrawPointF(renderer, cx - x, cy + y);
			SDL_RenderDrawPointF(renderer, cx - x, cy - y);
			SDL_RenderDrawPointF(renderer, cx + x, cy - y);
		}
	}
}

SDL_FPoint epicycles(SDL_Renderer *renderer, float x, float y, vector<Phasor> &phasors, float t, float rotation)
{
	for (auto &phasor : phasors)
	{
		auto oldx = x;
		auto oldy = y;

		auto vec = phasor.state(t, rotation);
		x += vec.x;
		y += vec.y;

		ellipse(renderer, oldx, oldy, phasor.amplitude, phasor.amplitude, { 52, 52, 52, 255 });

		SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
		SDL_RenderDrawLineF(renderer, oldx, oldy, x, y);
	}

	ellipse(renderer, x, y, 5, 5, { 255, 255, 255, 255 });
	return { x, y };
}

SDL_FPoint Phasor::state(float t, float offset)
{
	float theta = (frequency * t) + phase + offset;
	return { amplitude * cos(theta), amplitude * sin(theta) };
}

int Phasor::compare_amplitude(const void *a, const void *b)
{
	auto p = (Phasor *)a;
	auto q = (Phasor *)b;
	if (p->amplitude < q->amplitude)
		return 1;
	if (p->amplitude > q->amplitude)
		return -1;
	return 0;
}

void App::init()
{
	if (SDL_Init(SDL_INIT_VIDEO | SDL_INIT_TIMER) < 0)
		fatal("Failed to init SDL: %s", SDL_GetError());

	auto width = 1024;
	auto height = 768;
	window = SDL_CreateWindow("Fourier Transform Drawing", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, width, height, 0);
	if (!window)
		fatal("Failed to create window: %s", SDL_GetError());

	renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_PRESENTVSYNC | SDL_RENDERER_ACCELERATED);
	if (!renderer)
		fatal("Failed to create renderer: %s", SDL_GetError());

	SDL_SetRenderDrawBlendMode(renderer, SDL_BLENDMODE_BLEND);

	reset();
}

void App::reset()
{
	coarseness = 5;
	reload();
}

void App::reload()
{
	printf("Coarseness: %d\n", coarseness);

	load_train("train.txt", coarseness, x_phasors, y_phasors);

	path.clear();
	phasor_time = 0;
	phasor_tick = (2 * M_PI) / x_phasors.size();
	finished = false;

	start = SDL_GetPerformanceCounter();
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
				reset();
				break;
			case SDLK_LEFT:
				if (coarseness > 1)
					coarseness--;
				reload();
				break;
			case SDLK_RIGHT:
				coarseness++;
				reload();
				break;
			case SDLK_SPACE:
				reset();
				break;
			}
			break;
		}
	}
}

void App::update_and_draw()
{
	if (finished)
		return;

	int width, height;
	SDL_GetRendererOutputSize(renderer, &width, &height);

	SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
	SDL_RenderClear(renderer);

	auto vx = epicycles(renderer, width / 2.0, 100, x_phasors, phasor_time, 0);
	auto vy = epicycles(renderer, 100, height / 2.0, y_phasors, phasor_time, M_PI / 2);

	auto now = SDL_GetPerformanceCounter();
	auto dt = ((now - start)) * 1000.0 / SDL_GetPerformanceFrequency();
	if (dt >= 16)
	{
		phasor_time += phasor_tick;
		if (phasor_time >= (2 * M_PI))
			finished = true;

		path.push_back({ vx.x, vy.y });

		start = now;
	}

	SDL_RenderDrawLineF(renderer, vx.x, 0, vx.x, height);
	SDL_RenderDrawLineF(renderer, 0, vy.y, width, vy.y);

	for (auto i = 0u; i < path.size(); i++)
	{
		auto j = (i + 1) % path.size();
		SDL_RenderDrawLineF(renderer, path[i].x, path[i].y, path[j].x, path[j].y);
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
