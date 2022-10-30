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

	SimpleWalkingCamera camera;
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
	shapes.add(static_geometry::plain_ground_vertices, sizeof(static_geometry::plain_ground_vertices));
	shapes.add(static_geometry::cube_vertices, sizeof(static_geometry::cube_vertices));
	shapes.add(static_geometry::pyramid_vertices, sizeof(static_geometry::pyramid_vertices));
	shapes.upload(GL_STATIC_DRAW);

	glEnableVertexAttribArray(0);
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, sizeof(Vec3f), 0);

	colors.create();
	colors.bind();
	colors.add(static_geometry::plain_ground_colors, sizeof(static_geometry::plain_ground_colors));
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

	camera.init({ 0.0f, 8.0f, 20.0f }, { 0.0f, 8.0f, 19.0f }, { 0.0f, 1.0f, 0.0f });
	theta = 0.0;
}

void App::render()
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	program.use();
	glBindVertexArray(vao);

	program["matrices.projectionMatrix"] = proj;
	program["matrices.viewMatrix"] = camera.get_view_matrix();

	// Render ground
	program["matrices.modelMatrix"] = Mat4f::eye(1.0);
	glDrawArrays(GL_TRIANGLE_STRIP, 0, 4);

	// Render "houses" on the left
	for (auto i = 0; i < 10; i++)
	{
		// Lets predefine some sizes
		auto house_bottom_size = 10.0f;
		auto rooftop_size = 12.0f;

		// First, calculate the basic position of house
		auto model_matrix_house = Mat4f::eye(1.0);
		model_matrix_house = Mat4f::translate(model_matrix_house, { -40.0f, 0.0f, -125.0f + i * 25.0f });

		// Render bottom cube of the house
		auto model_matrix_bottom = Mat4f::translate(model_matrix_house, { 0.0f, house_bottom_size / 2.0f, 0.0f });
		model_matrix_bottom = Mat4f::rotate(model_matrix_bottom, theta, { 0.0f, 1.0f, 0.0f });
		model_matrix_bottom = Mat4f::scale(model_matrix_bottom, { house_bottom_size, house_bottom_size, house_bottom_size });
		program["matrices.modelMatrix"] = model_matrix_bottom;
		glDrawArrays(GL_TRIANGLES, 4, 36);

		// Render top (roof) of the house
		auto translateTopY = house_bottom_size + rooftop_size / 2.0f - 1.0f;
		auto model_matrix_top = Mat4f::translate(model_matrix_house, { 0.0f, translateTopY, 0.0f });
		model_matrix_top = Mat4f::rotate(model_matrix_top, theta, { 0.0f, 1.0f, 0.0f });
		model_matrix_top = Mat4f::scale(model_matrix_top, { rooftop_size, rooftop_size, rooftop_size });
		program["matrices.modelMatrix"] = model_matrix_top;
		glDrawArrays(GL_TRIANGLES, 40, 12);
	}

	// Render "skyscrapers" on the right
	for (auto i = 0; i < 10; i++)
	{
		auto house_bottom_size = 10.0f;
		auto house_middle_size = 7.0f;
		auto house_top_size = 4.0f;

		// First, calculate the basic position of skyscraper
		auto model_matrix_house = Mat4f::eye(1.0);
		model_matrix_house = Mat4f::translate(model_matrix_house, { 40.0f, 0.0f, -125.0f + i * 25.0f });

		// Render the bottom part of skyscraper
		auto model_matrix_bottom = Mat4f::translate(model_matrix_house, { 0.0f, house_bottom_size / 2.0f, 0.0f });
		model_matrix_bottom = Mat4f::rotate(model_matrix_bottom, theta, { 0.0f, 1.0f, 0.0f });
		model_matrix_bottom = Mat4f::scale(model_matrix_bottom, { house_bottom_size, house_bottom_size, house_bottom_size });
		program["matrices.modelMatrix"] = model_matrix_bottom;
		glDrawArrays(GL_TRIANGLES, 4, 36);

		// Render the middle part of skyscraper
		auto translate_middle_y = house_bottom_size + house_middle_size / 2.0f;
		auto model_matrix_middle = Mat4f::translate(model_matrix_house, { 0.0f, translate_middle_y, 0.0f });
		model_matrix_middle = Mat4f::rotate(model_matrix_middle, theta, { 0.0f, 1.0f, 0.0f });
		model_matrix_middle = Mat4f::scale(model_matrix_middle, { house_middle_size, house_middle_size, house_middle_size });
		program["matrices.modelMatrix"] = model_matrix_middle;
		glDrawArrays(GL_TRIANGLES, 4, 36);

		// Render the top part of skyscraper
		auto translate_top_y = house_middle_size + house_bottom_size + house_top_size / 2.0f;
		auto model_matrix_top = Mat4f::translate(model_matrix_house, { 0.0f, translate_top_y, 0.0f });
		model_matrix_top = Mat4f::rotate(model_matrix_top, theta, { 0.0f, 1.0f, 0.0f });
		model_matrix_top = Mat4f::scale(model_matrix_top, { house_top_size, house_top_size, house_top_size });
		program["matrices.modelMatrix"] = model_matrix_top;
		glDrawArrays(GL_TRIANGLES, 4, 36);
	}

	theta += radians(sof(45.0f));
}

void App::event(SDL_Event *ev)
{
	auto key_input = [&](int key) {
		return ev->type == SDL_KEYDOWN && ev->key.keysym.sym == key;
	};
	auto speed_correction = [&](float f) { return sof(f); };
	camera.update(key_input, speed_correction);
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
	auto title = "005.) Camera pt. 1 - Simple Walking Camera - Tutorial by Michal Bubnar (www.mbsoftworks.sk)";
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
