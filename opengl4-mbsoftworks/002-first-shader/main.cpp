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

	void load();

	Shader vertex;
	Shader fragment;
	Program program;

	VBO vbo;
	GLuint vao;
};

App::App()
{
}

App::~App()
{
}

void App::load()
{
	vertex.load("data/shaders/tut002/shader.vert", GL_VERTEX_SHADER);
	fragment.load("data/shaders/tut002/shader.frag", GL_FRAGMENT_SHADER);
	program.create();
	program.attach(vertex);
	program.attach(fragment);
	program.link();

	glGenVertexArrays(1, &vao);
	glBindVertexArray(vao);

	Vec3f triangle[] = {
		{ -0.4f, 0.1f, 0.0f },
		{ 0.4f, 0.1f, 0.0f },
		{ 0.0f, 0.7f, 0.0f },
	};
	Vec3f quad[] = {
		{ -0.2f, -0.1f, 0.0f },
		{ -0.2f, -0.6f, 0.0f },
		{ 0.2f, -0.1f, 0.0f },
		{ 0.2f, -0.6f, 0.0f },
	};
	vbo.create();
	vbo.bind();
	vbo.add(triangle, sizeof(triangle));
	vbo.add(quad, sizeof(quad));
	vbo.upload(GL_STATIC_DRAW);

	glEnableVertexAttribArray(0);
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, sizeof(Vec3f), 0);

	auto err = glGetError();
	if (err)
		printf("GL error: %d\n", err);
}

void App::begin()
{
	load();
	glClearColor(0, 0.5, 1, 1);
}

void App::render()
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	program.use();
	glBindVertexArray(vao);
	glDrawArrays(GL_TRIANGLES, 0, 3);
	glDrawArrays(GL_TRIANGLE_STRIP, 3, 4);
}

void App::event(SDL_Event *)
{
}

void App::release()
{
	program.release();
	vertex.release();
	fragment.release();
	vbo.release();
	glDeleteVertexArrays(1, &vao);
}

int main()
{
	auto title = "002.) First Shader - Tutorial by Michal Bubnar (www.mbsoftworks.sk)";
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
