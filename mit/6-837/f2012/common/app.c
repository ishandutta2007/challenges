#include "lib.h"

static void
set_vsync(bool on)
{
	if (on) {
		if (SDL_GL_SetSwapInterval(-1) == -1)
			SDL_GL_SetSwapInterval(1);
	} else
		SDL_GL_SetSwapInterval(0);
}

static void
init(GC *gc)
{
	SDL_Window *window;
	SDL_GLContext glctx;
	int wflag, glerr;
	const char *file;
	GLenum shtype;
	GLuint program, vao, vbo;
	size_t i, j;

	if (SDL_Init(SDL_INIT_VIDEO | SDL_INIT_TIMER) < 0)
		fatal("Failed to init SDL: %s", SDL_GetError());

	SDL_GL_SetAttribute(SDL_GL_CONTEXT_PROFILE_MASK, SDL_GL_CONTEXT_PROFILE_CORE);
	SDL_GL_SetAttribute(SDL_GL_CONTEXT_MAJOR_VERSION, 4);
	SDL_GL_SetAttribute(SDL_GL_CONTEXT_MINOR_VERSION, 4);
	SDL_GL_SetAttribute(SDL_GL_DOUBLEBUFFER, 1);

	wflag = SDL_WINDOW_OPENGL | SDL_WINDOW_SHOWN | SDL_WINDOW_RESIZABLE;
	window = SDL_CreateWindow(gc->title, SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, gc->width, gc->height, wflag);
	if (window == NULL)
		fatal("Failed to create window: %s", SDL_GetError());

	glctx = SDL_GL_CreateContext(window);
	SDL_GL_MakeCurrent(window, glctx);

	for (i = 0; i < nelem(gc->shader_files); i++) {
		file = gc->shader_files[i];
		if (file[0] == '\0')
			break;

		shtype = 0;
		if (strstr(file, "_vs.glsl"))
			shtype = GL_VERTEX_SHADER;
		else if (strstr(file, "_fs.glsl"))
			shtype = GL_FRAGMENT_SHADER;
		else if (strstr(file, "_gs.glsl"))
			shtype = GL_GEOMETRY_SHADER;
		else
			fatal("Unsupported shader type %s", file);

		gc->shader[i] = load_shader(file, shtype);
	}

	for (i = 0; i < nelem(gc->shader_links); i++) {
		if (gc->shader_links[i][0] == -1)
			break;

		program = glCreateProgram();
		for (j = 0; gc->shader_links[i][j] != -1; j++)
			glAttachShader(program, gc->shader[gc->shader_links[i][j]]);
		glLinkProgram(program);
		glUseProgram(program);

		gc->program[i] = program;
	}

	glGenVertexArrays(1, &vao);
	glGenBuffers(1, &vbo);

	if ((glerr = glGetError()) != GL_NO_ERROR)
		fatal("Encountered a GL error in setup: %d", glerr);

	gc->window = window;
	gc->glctx = glctx;
	gc->vao = vao;
	gc->vbo = vbo;
	gc->picking = false;
	default_camera(&gc->camera);
	recalc_projection_matrix(gc);
}

static void
event(GC *gc)
{
	static const GLenum wireframe_modes[] = {
	    GL_FILL,
	    GL_LINE,
	    GL_POINT,
	};

	Camera *cam;
	float2 mp;
	SDL_Event ev;

	cam = &gc->camera;
	while (SDL_PollEvent(&ev)) {
		switch (ev.type) {
		case SDL_QUIT:
			gc->running = false;
			return;

		case SDL_KEYDOWN:
			switch (ev.key.keysym.sym) {
			case SDLK_ESCAPE:
				gc->running = false;
				return;
			case SDLK_F1:
				gc->vsync = !gc->vsync;
				set_vsync(gc->vsync);
				break;
			case SDLK_F2:
				gc->wireframe = (gc->wireframe + 1) % nelem(wireframe_modes);
				glPolygonMode(GL_FRONT_AND_BACK, wireframe_modes[gc->wireframe]);
				break;
			case SDLK_SPACE:
				default_camera(cam);
				break;
			case SDLK_RETURN:
				gc->pause = !gc->pause;
				break;
			}
			break;

		case SDL_MOUSEBUTTONDOWN:
			gc->picking = true;
			cam->click = V2(ev.button.x, ev.button.y);
			cam->button = ev.button.button;
			switch (cam->button) {
			case SDL_BUTTON_LEFT:
				cam->rotation = cam->rotation0;
				break;

			case SDL_BUTTON_MIDDLE:
				cam->center = cam->center0;
				break;

			case SDL_BUTTON_RIGHT:
				cam->distance = cam->distance0;
				break;
			}
			break;

		case SDL_MOUSEBUTTONUP:
			gc->picking = false;
			cam->rotation0 = cam->rotation;
			cam->center0 = cam->center;
			cam->distance0 = cam->distance;
			cam->button = 0;
			break;

		case SDL_MOUSEMOTION:
			mp = V2(ev.motion.x, ev.motion.y);
			switch (cam->button) {
			case SDL_BUTTON_LEFT:
				arcball_rotate_camera(cam, mp, 5 * gc->time_delta);
				break;
			case SDL_BUTTON_MIDDLE:
				plane_translate_camera(cam, mp, 150 * gc->time_delta);
				break;
			case SDL_BUTTON_RIGHT:
				distance_zoom_camera(cam, mp, 150 * gc->time_delta);
				break;
			}
			break;

		case SDL_WINDOWEVENT:
			switch (ev.window.event) {
			case SDL_WINDOWEVENT_RESIZED:
				SDL_GetWindowSize(gc->window, &gc->width, &gc->height);
				recalc_projection_matrix(gc);
				continue;
			}
			break;
		}
		gc->event(gc, &ev);
	}
}

static void
tick(GC *gc)
{
	uint64_t now, fps_delta;
	char buf[512];

	now = SDL_GetPerformanceCounter();
	fps_delta = (now - gc->last_frame_fps) * 1.0 / SDL_GetPerformanceFrequency();

	gc->time_delta = (now - gc->last_frame_time) * 1.0 / SDL_GetPerformanceFrequency();
	gc->last_frame_time = now;
	gc->next_fps++;
	if (fps_delta > 1) {
		gc->last_frame_fps = now;
		gc->fps = gc->next_fps;
		gc->next_fps = 0;

		snprintf(buf, sizeof(buf), "%s FPS: %d", gc->title, gc->fps);
		SDL_SetWindowTitle(gc->window, buf);
	}
}

void
run(GC *gc)
{
	init(gc);

	gc->last_frame_fps = SDL_GetPerformanceCounter();
	gc->last_frame_time = gc->last_frame_fps;
	gc->fps = 0;
	gc->next_fps = 0;
	gc->running = true;

	gc->begin(gc);
	while (gc->running) {
		tick(gc);
		gc->update_and_render(gc);
		SDL_GL_SwapWindow(gc->window);

		event(gc);
	}

	gc->cleanup(gc);
	SDL_Quit();
}
