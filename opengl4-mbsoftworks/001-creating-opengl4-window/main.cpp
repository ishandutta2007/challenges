#include "lib.h"

class App : public GLWindow
{
public:
	App();
	virtual ~App();

	void begin();
	void event(SDL_Event *ev);
	void render();
	void release();
};

App::App()
{
}

App::~App()
{
}

void App::begin()
{
	glClearColor(0, 0.5, 1, 1);
}

void App::render()
{
	glClear(GL_COLOR_BUFFER_BIT);
}

void App::event(SDL_Event *)
{
}

void App::release()
{
}

int main()
{
	auto title = "001.) Creating OpenGL4 Window - Tutorial by Michal Bubnar (www.mbsoftworks.sk)";
	auto major = 4;
	auto minor = 4;
	auto fullscreen = false;

	auto app = new App();
	auto ret = app->create(title, major, minor, fullscreen);
	if (ret < 0)
		fatal("Failed to create window: %s", SDL_GetError());
	app->run();
	delete app;
	return 0;
}
