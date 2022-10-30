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

	VBO shapes;
	VBO colors;
	GLuint vao;

	float theta;
};

App::App()
{
}

App::~App()
{
}

void App::load()
{
	vertex.load("data/shaders/tut004/shader.vert", GL_VERTEX_SHADER);
	fragment.load("data/shaders/tut004/shader.frag", GL_FRAGMENT_SHADER);
	program.create();
	program.attach(vertex);
	program.attach(fragment);
	program.link();

	glGenVertexArrays(1, &vao);
	glBindVertexArray(vao);

	shapes.create();
	shapes.bind();
	shapes.add(static_geometry::cube_vertices, sizeof(static_geometry::cube_vertices));
	shapes.add(static_geometry::pyramid_vertices, sizeof(static_geometry::pyramid_vertices));
	shapes.upload(GL_STATIC_DRAW);

	glEnableVertexAttribArray(0);
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, sizeof(Vec3f), 0);

	colors.create();
	colors.bind();
	for (auto i = 0; i < 6; i++)
		colors.add(static_geometry::cube_face_colors, sizeof(static_geometry::cube_face_colors));
	for (auto i = 0; i < 4; i++)
		colors.add(static_geometry::pyramid_face_colors, sizeof(static_geometry::pyramid_face_colors));
	colors.upload(GL_STATIC_DRAW);

	glEnableVertexAttribArray(1);
	glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, sizeof(Vec3f), 0);

	auto err = glGetError();
	if (err)
		printf("GL error: %d\n", err);
}

void App::begin()
{
	load();
	glClearColor(0.0f, 0.28f, 0.57f, 1.0f);
	glEnable(GL_DEPTH_TEST);
	glClearDepth(1.0);

	theta = 0.0;
}

void App::render()
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	program.use();
	glBindVertexArray(vao);

	program["matrices.projectionMatrix"] = proj;
	program["matrices.viewMatrix"] = Mat4f::lookAt({ 0.0f, 0.0f, 20.0f }, { 0.0f, 0.0f, 0.0f }, { 0.0f, 1.0f, 0.0f });

	// Render rotating cube in the middle
	auto model_matrix_cube = Mat4f::eye(1.0);
	model_matrix_cube = Mat4f::rotate(model_matrix_cube, theta, { 1.0f, 0.0f, 0.0f });
	model_matrix_cube = Mat4f::rotate(model_matrix_cube, theta, { 0.0f, 1.0f, 0.0f });
	model_matrix_cube = Mat4f::rotate(model_matrix_cube, theta, { 0.0f, 0.0f, 1.0f });
	model_matrix_cube = Mat4f::scale(model_matrix_cube, { 5.0f, 5.0f, 5.0f });

	program["matrices.modelMatrix"] = model_matrix_cube;
	glDrawArrays(GL_TRIANGLES, 0, 36);

	// Render 4 pyramids around the cube with the positions defined in the following array
	Vec3f pyramid_translations[] = {
		{ -12.0f, 7.0f, 0.0f },
		{ 12.0f, 7.0f, 0.0f },
		{ 12.0f, -7.0f, 0.0f },
		{ -12.0f, -7.0f, 0.0f },
	};
	for (auto translation : pyramid_translations)
	{
		auto model_matrix_pyramid = Mat4f::eye(1.0);
		model_matrix_pyramid = Mat4f::translate(model_matrix_pyramid, translation);
		model_matrix_pyramid = Mat4f::rotate(model_matrix_pyramid, theta, { 0.0f, 1.0f, 0.0f });
		model_matrix_pyramid = Mat4f::scale(model_matrix_pyramid, { 3.0f, 3.0f, 3.0f });

		program["matrices.modelMatrix"] = model_matrix_pyramid;
		glDrawArrays(GL_TRIANGLES, 36, 12); // Pyramid vertices start after cube, that is on index 36
	}

	theta += radians(sof(90.0f));
}

void App::event(SDL_Event *)
{
}

void App::release()
{
	program.release();
	vertex.release();
	fragment.release();
	shapes.release();
	colors.release();
	glDeleteVertexArrays(1, &vao);
}

int main()
{
	auto title = "004.) Entering third dimension - Tutorial by Michal Bubnar (www.mbsoftworks.sk)";
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
