#ifndef _GLWINDOW_H_
#define _GLWINDOW_H_

class GLWindow
{
public:
	GLWindow();
	int create(const char *title, int major, int minor, bool fullscreen);
	void recalc_projection_matrix();
	float sof(float v);

	void tick();
	void run();
	void set_vsync(bool on);

	virtual void begin() = 0;
	virtual void event(SDL_Event *ev) = 0;
	virtual void render() = 0;
	virtual void release() = 0;

	SDL_Window *window;
	SDL_GLContext glctx;
	char title[256];

	Mat4f orthoyn;
	Mat4f ortho;
	Mat4f proj;

	bool running;
	bool vsync;
	bool paused;

	uint64_t last_frame_time; // Time of last frame
	uint64_t last_frame_fps; // Time of last FPS Update
	float time_delta; // Time delta between last frame and current frame

	int fps;
	int next_fps;
};

#endif
