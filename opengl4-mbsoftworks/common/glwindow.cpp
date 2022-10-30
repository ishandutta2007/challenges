#define STB_TRUETYPE_IMPLEMENTATION
#define STB_IMAGE_IMPLEMENTATION
#include "lib.h"

GLWindow::GLWindow()
{
	last_frame_time = 0;
	last_frame_fps = 0;
	time_delta = 0.0f;
	next_fps = 0;
	fps = 0;
	vsync = true;
	paused = false;
}

int GLWindow::create(const char *title, int major, int minor, bool fullscreen)
{
	auto ret = SDL_Init(SDL_INIT_TIMER | SDL_INIT_VIDEO);
	if (ret < 0)
		return ret;

	SDL_GL_SetAttribute(SDL_GL_CONTEXT_MAJOR_VERSION, major);
	SDL_GL_SetAttribute(SDL_GL_CONTEXT_MINOR_VERSION, minor);
	SDL_GL_SetAttribute(SDL_GL_DOUBLEBUFFER, 1);

	auto dblbuf = 0;
	auto wflag = SDL_WINDOW_OPENGL | SDL_WINDOW_SHOWN | SDL_WINDOW_RESIZABLE;
	if (fullscreen)
		wflag |= SDL_WINDOW_FULLSCREEN;
	window = SDL_CreateWindow(title, SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 1024, 768, wflag);
	if (!window)
		goto error;

	glctx = SDL_GL_CreateContext(window);
	if (!glctx)
		goto error;

	SDL_GL_MakeCurrent(window, glctx);
	if ((SDL_GL_GetAttribute(SDL_GL_DOUBLEBUFFER, &dblbuf) == -1) || (!dblbuf))
		goto error;

	set_vsync(true);
	recalc_projection_matrix();
	snprintf(this->title, sizeof(this->title), "%s", title);

	SDL_ShowCursor(0);

	return 0;

error:
	SDL_Quit();
	return -1;
}

void GLWindow::recalc_projection_matrix()
{
	int w, h;
	SDL_GetWindowSize(window, &w, &h);

	glViewport(0, 0, w, h);
	proj = Mat4f::perspective(45.0f, w * 1.0f / h, 0.5f, 1500.0f);
	ortho = Mat4f::ortho(0.0f, w, 0.0f, h, 1.0f, -1.0f);
	orthoyn = Mat4f::ortho(0.0f, w, h, 0.0f, 1.0f, -1.0f);
}

float GLWindow::sof(float v)
{
	return v * time_delta;
}

void GLWindow::set_vsync(bool on)
{
	if (on)
	{
		if (SDL_GL_SetSwapInterval(-1) == -1)
			SDL_GL_SetSwapInterval(1);
	}
	else
		SDL_GL_SetSwapInterval(0);
}

void GLWindow::tick()
{
	auto now = SDL_GetPerformanceCounter();
	auto fps_delta = (now - last_frame_fps) * 1.0 / SDL_GetPerformanceFrequency();

	time_delta = (now - last_frame_time) * 1.0 / SDL_GetPerformanceFrequency();
	last_frame_time = now;
	next_fps++;

	if (fps_delta > 1.0)
	{
		last_frame_fps = now;
		fps = next_fps;
		next_fps = 0;

		char buf[512];
		snprintf(buf, sizeof(buf), "%s FPS: %d", title, fps);
		SDL_SetWindowTitle(window, buf);
	}
}

void GLWindow::run()
{
	last_frame_fps = SDL_GetPerformanceCounter();
	last_frame_time = last_frame_fps;
	running = true;

	begin();
	while (running)
	{
		tick();
		render();
		SDL_GL_SwapWindow(window);

		SDL_Event ev;
		while (SDL_PollEvent(&ev))
		{
			switch (ev.type)
			{
			case SDL_QUIT:
				running = false;
				continue;

			case SDL_KEYDOWN:
				switch (ev.key.keysym.sym)
				{
				case SDLK_F3:
					vsync = !vsync;
					printf("Toggling VSYNC: %d\n", vsync);
					set_vsync(vsync);
					continue;
				case SDLK_ESCAPE:
					running = false;
					continue;
				case SDLK_SPACE:
					paused = !paused;
					SDL_ShowCursor(paused);
					break;
				}
				break;

			case SDL_WINDOWEVENT:
				switch (ev.window.event)
				{
				case SDL_WINDOWEVENT_RESIZED:
					recalc_projection_matrix();
					continue;
				}
				break;
			}

			event(&ev);
		}
	}

	release();
}
