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

	FlyingCamera camera;
	VBO shapes;
	VBO texcoords;
	GLuint vao;

	Texture ground_texture;
	Texture house_texture;
	Texture roof_texture;

	Texture filter_textures[10];
	Sampler samplers_show_case[10];
	int ground_sampler_index;

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
	vertex.load("data/shaders/tut007/shader.vert", GL_VERTEX_SHADER);
	fragment.load("data/shaders/tut007/shader.frag", GL_FRAGMENT_SHADER);
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

	texcoords.create();
	texcoords.bind();
	texcoords.add(static_geometry::plain_ground_texcoords, sizeof(static_geometry::plain_ground_texcoords));
	texcoords.add(static_geometry::cube_texcoords, sizeof(static_geometry::cube_texcoords), 6);
	texcoords.add(static_geometry::pyramid_texcoords, sizeof(static_geometry::pyramid_texcoords), 4);

	texcoords.upload(GL_STATIC_DRAW);
	glEnableVertexAttribArray(1);
	glVertexAttribPointer(1, 2, GL_FLOAT, GL_FALSE, sizeof(Vec2f), (void *)0);

	ground_texture.load("data/textures/clay.png");
	house_texture.load("data/textures/brick.png");
	roof_texture.load("data/textures/prismarine_dark.png");

	filter_textures[0].load("data/textures/tut007/mag_nearest_min_nearest.png");
	filter_textures[1].load("data/textures/tut007/mag_nearest_min_bilinear.png");
	filter_textures[2].load("data/textures/tut007/mag_nearest_min_nearest_mipmap.png");
	filter_textures[3].load("data/textures/tut007/mag_nearest_min_linear_mipmap.png");
	filter_textures[4].load("data/textures/tut007/mag_nearest_min_linear_mipmap_linear.png");

	filter_textures[5].load("data/textures/tut007/mag_linear_min_nearest.png");
	filter_textures[6].load("data/textures/tut007/mag_linear_min_linear.png");
	filter_textures[7].load("data/textures/tut007/mag_linear_min_nearest_mipmap.png");
	filter_textures[8].load("data/textures/tut007/mag_linear_min_linear_mipmap.png");
	filter_textures[9].load("data/textures/tut007/mag_linear_min_linear_mipmap_linear.png");

	for (auto &sampler : samplers_show_case)
		sampler.create();

	samplers_show_case[0].bind();
	samplers_show_case[0].set_magnification_filter(MAG_FILTER_NEAREST);
	samplers_show_case[0].set_minification_filter(MIN_FILTER_NEAREST);

	samplers_show_case[1].bind();
	samplers_show_case[1].set_magnification_filter(MAG_FILTER_NEAREST);
	samplers_show_case[1].set_minification_filter(MIN_FILTER_BILINEAR);

	samplers_show_case[2].bind();
	samplers_show_case[2].set_magnification_filter(MAG_FILTER_NEAREST);
	samplers_show_case[2].set_minification_filter(MIN_FILTER_NEAREST_MIPMAP);

	samplers_show_case[3].bind();
	samplers_show_case[3].set_magnification_filter(MAG_FILTER_NEAREST);
	samplers_show_case[3].set_minification_filter(MIN_FILTER_BILINEAR);

	samplers_show_case[4].bind();
	samplers_show_case[4].set_magnification_filter(MAG_FILTER_NEAREST);
	samplers_show_case[4].set_minification_filter(MIN_FILTER_TRILINEAR);

	samplers_show_case[5].bind();
	samplers_show_case[5].set_magnification_filter(MAG_FILTER_BILINEAR);
	samplers_show_case[5].set_minification_filter(MIN_FILTER_NEAREST);

	samplers_show_case[6].bind();
	samplers_show_case[6].set_magnification_filter(MAG_FILTER_BILINEAR);
	samplers_show_case[6].set_minification_filter(MIN_FILTER_BILINEAR);

	samplers_show_case[7].bind();
	samplers_show_case[7].set_magnification_filter(MAG_FILTER_BILINEAR);
	samplers_show_case[7].set_minification_filter(MIN_FILTER_NEAREST_MIPMAP);

	samplers_show_case[8].bind();
	samplers_show_case[8].set_magnification_filter(MAG_FILTER_BILINEAR);
	samplers_show_case[8].set_minification_filter(MIN_FILTER_BILINEAR);

	samplers_show_case[9].bind();
	samplers_show_case[9].set_magnification_filter(MAG_FILTER_BILINEAR);
	samplers_show_case[9].set_minification_filter(MIN_FILTER_TRILINEAR);

	ground_sampler_index = 9;

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
	program["color"] = Vec4f{ 1.0f, 1.0f, 1.0f, 1.0f };
	ground_texture.bind();
	samplers_show_case[ground_sampler_index].bind();
	program["sampler"] = 0;

	glDrawArrays(GL_TRIANGLE_STRIP, 0, 4);

	// Lets predefine some sizes
	auto start_point_left = Vec3f{ -40.0f, 0.0f, 75.0f };
	auto start_point_right = Vec3f{ 40.0f, 0.0f, 0.0f };
	auto house_bottom_size = 10.0f;
	auto rooftop_size = 12.0f;

	// Render "houses" on the left
	for (auto i = 0; i < 10; i++)
	{
		// First, calculate the basic position of house
		auto model_matrix_house = Mat4f::eye(1.0);
		auto house_position = start_point_left + Vec3f{ 0.0f, 0.0f, -i * 25.0f };
		model_matrix_house = Mat4f::translate(model_matrix_house, { -40.0f, 0.0f, -125.0f + i * 25.0f });

		// Render bottom cube of the house
		auto model_matrix_bottom = Mat4f::translate(model_matrix_house, { 0.0f, house_bottom_size / 2.0f, 0.0f });
		model_matrix_bottom = Mat4f::rotate(model_matrix_bottom, theta, { 0.0f, 1.0f, 0.0f });
		model_matrix_bottom = Mat4f::scale(model_matrix_bottom, { house_bottom_size, house_bottom_size, house_bottom_size });
		program["matrices.modelMatrix"] = model_matrix_bottom;
		program["color"] = i == ground_sampler_index ? Vec4f{ 0.25f, 0.8f, 1.0f, 1.0f } : Vec4f{ 1.0f, 1.0f, 1.0f, 1.0f };
		house_texture.bind();
		glDrawArrays(GL_TRIANGLES, 4, 36);
		glDrawArrays(GL_TRIANGLES, 28, 6);

		filter_textures[i].bind();
		glDrawArrays(GL_TRIANGLES, 22, 6);

		// Render top (roof) of the house
		roof_texture.bind();
		auto translate_top_y = house_bottom_size + rooftop_size / 2.0f - 1.0f;
		auto model_matrix_top = Mat4f::translate(model_matrix_house, { 0.0f, translate_top_y, 0.0f });
		model_matrix_top = Mat4f::rotate(model_matrix_top, theta, { 0.0f, 1.0f, 0.0f });
		model_matrix_top = Mat4f::scale(model_matrix_top, { rooftop_size, rooftop_size, rooftop_size });
		program["matrices.modelMatrix"] = model_matrix_top;
		glDrawArrays(GL_TRIANGLES, 40, 12);

		if (Vec3f::distance(camera.position, house_position) < house_bottom_size * 0.66f)
			ground_sampler_index = i;
	}

	// Render "houses" on the right
	for (auto i = 5, j = 0; i < 10; i++, j++)
	{
		samplers_show_case[i].bind();

		// First, calculate the basic position of house
		auto model_matrix_house = Mat4f::eye(1.0);
		auto house_position = start_point_right + Vec3f{ 0.0f, 0.0f, -j * 25.0f };
		model_matrix_house = Mat4f::translate(model_matrix_house, house_position);

		// Render bottom cube of the house
		auto model_matrix_bottom = Mat4f::translate(model_matrix_house, Vec3f{ 0.0f, house_bottom_size / 2.0f, 0.0f });
		model_matrix_bottom = Mat4f::scale(model_matrix_bottom, Vec3f{ house_bottom_size, house_bottom_size, house_bottom_size });
		program["matrices.modelMatrix"] = model_matrix_bottom;
		program["color"] = i == ground_sampler_index ? Vec4f{ 0.25f, 0.8f, 1.0f, 1.0f } : Vec4f{ 1.0f, 1.0f, 1.0f, 1.0f };

		house_texture.bind();
		glDrawArrays(GL_TRIANGLES, 4, 12);
		glDrawArrays(GL_TRIANGLES, 22, 12);

		filter_textures[i].bind();
		glDrawArrays(GL_TRIANGLES, 16, 6);

		roof_texture.bind();
		auto translate_top_y = house_bottom_size + rooftop_size / 2.0f - 0.25f;
		auto model_matrix_top = Mat4f::translate(model_matrix_house, Vec3f{ 0.0f, translate_top_y, 0.0f });
		model_matrix_top = Mat4f::scale(model_matrix_top, Vec3f{ rooftop_size, rooftop_size, rooftop_size });
		program["matrices.modelMatrix"] = model_matrix_top;
		glDrawArrays(GL_TRIANGLES, 40, 12);

		if (Vec3f::distance(camera.position, house_position) < house_bottom_size * 0.66f)
			ground_sampler_index = i;
	}

	theta += radians(sof(45.0f));
}

void App::event(SDL_Event *ev)
{
	switch (ev->type)
	{
	case SDL_KEYDOWN:
		switch (ev->key.keysym.sym)
		{
		case SDLK_1:
			ground_sampler_index -= 1;
			if (ground_sampler_index < 0)
				ground_sampler_index = nelem(samplers_show_case) - 1;
			break;
		case SDLK_2:
			ground_sampler_index += 1;
			if ((size_t)ground_sampler_index >= nelem(samplers_show_case))
				ground_sampler_index = 0;
			break;
		}
		break;
	}

	if (paused)
		return;

	int w, h;
	SDL_GetWindowSize(window, &w, &h);
	camera.window_center_position = Vec2i{ w / 2, h / 2 };

	auto key_input = [&](int key) {
		return ev->type == SDL_KEYDOWN && ev->key.keysym.sym == key;
	};
	auto get_cursor_pos = [&]() {
		int x, y;
		SDL_GetMouseState(&x, &y);
		return Vec2i{ x, y };
	};
	auto set_cursor_pos = [&](Vec2i pos) {
		SDL_WarpMouseInWindow(window, pos.x, pos.y);
	};
	auto speed_correction = [&](float f) { return sof(f); };
	camera.update(key_input, get_cursor_pos, set_cursor_pos, speed_correction);
}

void App::release()
{
	program.release();
	vertex.release();
	fragment.release();
	shapes.release();
	texcoords.release();
	ground_texture.release();
	house_texture.release();
	roof_texture.release();
	for (auto &sampler : samplers_show_case)
		sampler.release();
	glDeleteVertexArrays(1, &vao);
}

int main()
{
	auto title = "007.) Textures pt. 1 - Single Texture - Tutorial by Michal Bubnar (www.mbsoftworks.sk)";
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
