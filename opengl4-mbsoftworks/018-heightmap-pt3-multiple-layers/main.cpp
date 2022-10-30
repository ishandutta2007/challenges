#include "lib.h"

vector<Vec3f> crate_positions{
	{ -30.0f, 0.0f, -80.0f },
	{ 30.0f, 0.0f, -40.0f },
	{ -30.0f, 0.0f, 0.0f },
	{ 30.0f, 0.0f, 40.0f },
	{ -30.0f, 0.0f, 80.0f },
};

vector<Vec3f> tori_positions{
	{ 30.0f, 0.0f, -80.0f },
	{ -30.0f, 0.0f, -40.0f },
	{ 30.0f, 0.0f, 0.0f },
	{ -30.0f, 0.0f, 40.0f },
	{ 30.0f, 0.0f, 80.0f },
};

class HUD018 : public HUD
{
public:
	void init(GLWindow *window, FlyingCamera *camera);
	void render(bool display_normals);

	FlyingCamera *camera;
};

void HUD018::init(GLWindow *glwindow, FlyingCamera *camera)
{
	HUD::init(glwindow);
	this->camera = camera;

	static once_flag once;
	call_once(once, [&]() {
		auto &fm = FontManager::get_instance();
		fm.load("default", "data/fonts/Roboto-Medium.ttf", 24);
	});
}

void HUD018::render(bool display_normals)
{
	auto &fm = FontManager::get_instance();

	auto &font = fm.fonts["default"];
	auto x = 10.0f, y = 20.0f;
	font.print(x, y, "FPS: %d", glwindow->fps);
	y += font.pixel_size;
	font.print(x, y, "Paused: %s (Space to toggle)", (glwindow->paused) ? "Yes" : "No");

	y += font.pixel_size;
	font.print(x, y, "Display normals: %s (Press 'N' to toggle)", (display_normals) ? "Yes" : "No");
}

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

	void get_heightmap_row_and_column(Vec3f position, int &row, int &col);

	Cube cube;
	Torus torus;
	PlainGround plain_ground;
	float theta;

	Heightmap *heightmap;
	Vec3f heightmap_size;

	HUD018 *hud;
	Skybox *skybox;

	bool display_normals;

	AmbientLight ambient_light;
	DiffuseLight diffuse_light;

	FlyingCamera camera;
};

App::App()
{
}

App::~App()
{
}

void App::load()
{
	auto &sm = ShaderManager::get_instance();
	auto &pm = SamplerManager::get_instance();
	auto &tm = TextureManager::get_instance();

	sm.add_shader("tut014_main_vertex", "data/shaders/tut014-diffuse-lighting/shader.vert", GL_VERTEX_SHADER);
	sm.add_shader("tut014_main_fragment", "data/shaders/tut014-diffuse-lighting/shader.frag", GL_FRAGMENT_SHADER);
	sm.add_shader("ambientLight_fragment", "data/shaders/lighting/ambientLight.frag", GL_FRAGMENT_SHADER);
	sm.add_shader("diffuseLight_fragment", "data/shaders/lighting/diffuseLight.frag", GL_FRAGMENT_SHADER);
	sm.add_shader("utility_fragment", "data/shaders/common/utility.frag", GL_FRAGMENT_SHADER);
	sm.make_program("main", { "tut014_main_vertex", "tut014_main_fragment", "ambientLight_fragment", "diffuseLight_fragment", "utility_fragment" });

	sm.add_shader("normals_vertex", "data/shaders/normals/normals.vert", GL_VERTEX_SHADER);
	sm.add_shader("normals_geometry", "data/shaders/normals/normals.geom", GL_GEOMETRY_SHADER);
	sm.add_shader("normals_fragment", "data/shaders/normals/normals.frag", GL_FRAGMENT_SHADER);
	sm.make_program("normals", { "normals_vertex", "normals_geometry", "normals_fragment" });

	pm.create_sampler("main", MAG_FILTER_BILINEAR, MIN_FILTER_TRILINEAR);
	tm.add_texture("crate", "data/textures/crate.png");
	tm.add_texture("white_marble", "data/textures/white_marble.jpg");
	tm.add_texture("grass", "data/textures/grass.jpg");
	tm.add_texture("rocky_terrain", "data/textures/rocky_terrain.jpg");
	tm.add_texture("snow", "data/textures/snow.png");

	cube.init(true, true, true);
	torus.init(20, 20, 3.0f, 1.5f, true, true, true);
	plain_ground.init(true, true, true);

	heightmap_size = { 200.0f, 10.0f, 200.0f };
	heightmap = new Heightmap();
	Heightmap::prepare_multi_layer_shader_program();
	heightmap->init("data/heightmaps/tut018.png", true, true, true);

	skybox = new Skybox();
	skybox->init("data/skyboxes/desert", "png", true, true, true);

	hud = new HUD018();
	hud->init(this, &camera);

	auto err = glGetError();
	if (err)
		printf("GL error: %d\n", err);
}

void App::begin()
{
	load();
	glEnable(GL_DEPTH_TEST);
	glClearDepth(1.0);

	camera.init({ 0.0f, 10.0f, -60.0f }, { 0.0f, 10.0f, -59.0f }, { 0.0f, 1.0f, 0.0f }, 50.0f);
	theta = 0.0f;

	display_normals = true;

	ambient_light.init({ 0.50f, 0.50f, 0.50f });
	diffuse_light.init({ 1.0f, 1.0f, 1.0f }, { 0.0f, 0.0f, -1.0f }, 0.5f);
}

void App::render()
{
	auto clear_color = Vec4f{ 0.02f, 0.682f, 1.0f, 1.0f } * Vec4f{ ambient_light.get_color_contribution(), 1.0f };
	glClearColor(clear_color.r, clear_color.g, clear_color.b, clear_color.a);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	auto &sm = ShaderManager::get_instance();
	auto &pm = SamplerManager::get_instance();
	auto &tm = TextureManager::get_instance();
	auto &mm = MatrixManager::get_instance();

	// Set matrices in matrix manager
	mm.proj = proj;
	mm.ortho = ortho;
	mm.orthoyn = orthoyn;
	mm.view = camera.get_view_matrix();

	// Set up some common properties in the main shader program
	auto &program = sm.programs["main"];

	program.use();
	program["matrices.projectionMatrix"] = mm.proj;
	program["matrices.viewMatrix"] = mm.view;
	program.set_model_and_normal_matrix(Mat4f::eye(1.0f));
	program["color"] = Vec4f{ 1.0f, 1.0f, 1.0f, 1.0f };
	program["sampler"] = 0;

	// Render skybox first with only ambient light
	AmbientLight skybox_ambient_light;
	DiffuseLight skybox_diffuse_light;
	skybox_ambient_light.init({ 0.8f, 0.8f, 0.8f }, true);
	skybox_diffuse_light = DiffuseLight::none();
	skybox_ambient_light.set_uniform(program, "ambientLight");
	skybox_diffuse_light.set_uniform(program, "diffuseLight");
	skybox->render_at(camera.position, program);

	// Set up ambient and diffuse light in the shader program
	auto &sampler = pm.samplers["main"];
	sampler.bind();
	ambient_light.set_uniform(program, "ambientLight");
	diffuse_light.set_uniform(program, "diffuseLight");

	// Render all the crates (as simple cubes)
	vector<Mat4f> crate_model_matrices;
	for (auto &position : crate_positions)
	{
		auto crate_size = 8.0f;
		auto model = Mat4f::translate(Mat4f::eye(1.0f), position);
		auto row = 0, col = 0;
		get_heightmap_row_and_column(position, row, col);
		model = Mat4f::translate(model, { 0.0f, 1.5f + crate_size / 2.0f + heightmap->get_height(row, col) * heightmap_size.y, 0.0f });
		model = Mat4f::rotate(model, theta, { 1.0f, 0.0f, 0.0f });
		model = Mat4f::rotate(model, theta, { 0.0f, 1.0f, 0.0f });
		model = Mat4f::rotate(model, theta, { 0.0f, 0.0f, 1.0f });
		model = Mat4f::scale(model, { crate_size, crate_size, crate_size });
		crate_model_matrices.push_back(model);
		program.set_model_and_normal_matrix(model);

		tm.textures["crate"].bind(0);
		cube.render();
	}

	// Render tori
	vector<Mat4f> torus_model_matrices;
	for (auto &position : tori_positions)
	{
		auto model = Mat4f::translate(Mat4f::eye(1.0f), position);
		auto row = 0, col = 0;
		get_heightmap_row_and_column(position, row, col);
		model = Mat4f::translate(model, { 0.0f, 4.5f + heightmap->get_height(row, col) * heightmap_size.y, 0.0f });
		model = Mat4f::rotate(model, theta + 90.0f, { 0.0f, 1.0f, 0.0f });
		torus_model_matrices.push_back(model);
		program.set_model_and_normal_matrix(model);

		tm.textures["white_marble"].bind(0);
		torus.render();
	}

	// Render heightmap
	auto &heightmap_program = sm.programs["multilayer_heightmap"];
	heightmap_program.use();
	heightmap_program["matrices.projectionMatrix"] = mm.proj;
	heightmap_program["matrices.viewMatrix"] = mm.view;
	heightmap_program.set_model_and_normal_matrix(Mat4f::eye(1.0f));
	heightmap_program["color"] = Vec4f{ 1.0f, 1.0f, 1.0f, 1.0f };
	ambient_light.set_uniform(heightmap_program, "ambientLight");
	diffuse_light.set_uniform(heightmap_program, "diffuseLight");

	auto heightmap_model_matrix = Mat4f::scale(Mat4f::eye(1.0f), heightmap_size);
	heightmap_program.set_model_and_normal_matrix(heightmap_model_matrix);
	heightmap->render_multi_layered({ "rocky_terrain", "grass", "snow" }, { 0.2f, 0.3f, 0.55f, 0.7f });

	if (display_normals)
	{
		// Set up some common properties in the normals shader program
		auto &normals_program = sm.programs["normals"];
		normals_program.use();
		normals_program["matrices.projectionMatrix"] = mm.proj;
		normals_program["matrices.viewMatrix"] = mm.view;
		normals_program["normalLength"] = 0.5f;

		// Render all the crates points
		auto matrix_it = crate_model_matrices.cbegin();
		for (size_t i = 0; i < crate_positions.size(); i++)
		{
			normals_program.set_model_and_normal_matrix(*matrix_it++);
			cube.render_points();
		}

		// Finally render tori points
		matrix_it = torus_model_matrices.cbegin();
		for (size_t i = 0; i < tori_positions.size(); i++)
		{
			normals_program.set_model_and_normal_matrix(*matrix_it++);
			torus.render_points();
		}

		normals_program.set_model_and_normal_matrix(heightmap_model_matrix);
		heightmap->render_points();
	}

	// Render HUD
	hud->render(display_normals);

	theta += sof(radians(45.0f));
}

void App::event(SDL_Event *ev)
{
	switch (ev->type)
	{
	case SDL_KEYDOWN:
		switch (ev->key.keysym.sym)
		{
		case SDLK_n:
			display_normals = !display_normals;
			break;
		}
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
	auto &sm = ShaderManager::get_instance();
	auto &pm = SamplerManager::get_instance();
	auto &tm = TextureManager::get_instance();
	auto &fm = FontManager::get_instance();

	sm.release();
	tm.release();
	pm.release();
	fm.release();
	torus.release();
	cube.release();
	plain_ground.release();
	heightmap->release();
	delete heightmap;
	delete skybox;
	delete hud;
}

void App::get_heightmap_row_and_column(Vec3f position, int &row, int &col)
{
	auto half_width = heightmap_size.x / 2.0f;
	auto half_depth = heightmap_size.z / 2.0f;

	row = int(heightmap->rows * (position.z + half_depth) / heightmap_size.z);
	col = int(heightmap->cols * (position.x + half_width) / heightmap_size.x);
}

int main()
{
	auto title = "018.) Heightmap Pt.3 - Multiple Layers - Tutorial by Michal Bubnar (www.mbsoftworks.sk)";
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
