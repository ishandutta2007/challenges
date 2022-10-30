#include "lib.h"

vector<Vec3f> classic_house_positions{
	{ 80.0f, 0.0f, -80.0f },
	{ -80.0f, 0.0f, 80.0f },
};

vector<Vec3f> medieval_house_positions{
	{ -80.0f, 0.0f, -80.0f },
	{ 82.0f, 0.0f, 75.0f },
	{ -5.0f, 0.0f, 00.0f },
};

class HUD020 : public HUD
{
public:
	void init(GLWindow *window, FlyingCamera *camera);
	void render(FogParameters &fog_params);

	FlyingCamera *camera;
};

void HUD020::init(GLWindow *glwindow, FlyingCamera *camera)
{
	HUD::init(glwindow);
	this->camera = camera;

	static once_flag once;
	call_once(once, [&]() {
		auto &fm = FontManager::get_instance();
		fm.load("default", "data/fonts/Roboto-Medium.ttf", 24);
	});
}

void HUD020::render(FogParameters &fog_params)
{
	auto &fm = FontManager::get_instance();

	auto &font = fm.fonts["default"];
	auto x = 10.0f, y = 20.0f;
	font.print(x, y, "FPS: %d", glwindow->fps);
	y += font.pixel_size;
	font.print(x, y, "Paused: %s (Space to toggle)", (glwindow->paused) ? "Yes" : "No");

	y += font.pixel_size;
	font.print(x, y, "Fog: %s (Press 'X' to toggle)", (fog_params.enabled) ? "Yes" : "No");
	y += font.pixel_size;
	font.print(x, y, "Fog equation: %s (Press 'F' to change)", fog_params.get_equation_name());
	if (fog_params.equation == FogParameters::EQUATION_LINEAR)
	{
		y += font.pixel_size;
		font.print(x, y, "Start distance: %.3f (Press '1' and '2' to change)", fog_params.linear_start);
		y += font.pixel_size;
		font.print(x, y, "End distance: %.3f (Press '3' and '4' to change)", fog_params.linear_end);
	}
	else if (fog_params.equation == FogParameters::EQUATION_EXP || fog_params.equation == FogParameters::EQUATION_EXP2)
	{
		y += font.pixel_size;
		font.print(x, y, "Density: %.3f (Press '1' and '2' to change)", fog_params.density);
	}
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

	Model classic_house_model;
	Model medieval_house_model;

	HeightmapWithFog *heightmap_with_fog;
	Vec3f heightmap_size;

	HUD020 *hud;
	Skybox *skybox;

	AmbientLight ambient_light;
	DiffuseLight diffuse_light;
	FogParameters fog_params;

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

	sm.add_shader("tut020_fog_main_vertex", "data/shaders/tut020-fog/shader.vert", GL_VERTEX_SHADER);
	sm.add_shader("tut020_fog_main_fragment", "data/shaders/tut020-fog/shader.frag", GL_FRAGMENT_SHADER);
	sm.add_shader("ambientLight_fragment", "data/shaders/lighting/ambientLight.frag", GL_FRAGMENT_SHADER);
	sm.add_shader("diffuseLight_fragment", "data/shaders/lighting/diffuseLight.frag", GL_FRAGMENT_SHADER);
	sm.add_shader("utility_fragment", "data/shaders/common/utility.frag", GL_FRAGMENT_SHADER);
	sm.add_shader("fog_fragment", "data/shaders/fog/fog.frag", GL_FRAGMENT_SHADER);
	sm.make_program("main", { "tut020_fog_main_vertex", "tut020_fog_main_fragment", "ambientLight_fragment", "diffuseLight_fragment", "utility_fragment", "fog_fragment" });

	pm.create_sampler("main", MAG_FILTER_BILINEAR, MIN_FILTER_TRILINEAR);
	tm.add_texture("grass", "data/textures/grass.jpg");
	tm.add_texture("rocky_terrain", "data/textures/rocky_terrain.jpg");
	tm.add_texture("snow", "data/textures/snow.png");

	heightmap_size = { 200.0f, 40.0f, 200.0f };
	heightmap_with_fog = new HeightmapWithFog();
	HeightmapWithFog::prepare_multi_layer_shader_program_with_fog();
	heightmap_with_fog->init("data/heightmaps/tut019.png", true, true, true);

	skybox = new Skybox();
	skybox->init("data/skyboxes/jajlands1", "jpg", true, true, true);

	classic_house_model.init("data/models/house/house.3ds", "", true, true, true, Mat4f::eye(1.0f));
	medieval_house_model.init("data/models/medieval_house/medieval_house.obj", "medieval_house_diff.png", true, true, true, Mat4f::eye(1.0f));

	hud = new HUD020();
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

	camera.init({ 0.0f, 25.0f, -60.0f }, { 0.0f, 25.0f, -59.0f }, { 0.0f, 1.0f, 0.0f }, 50.0f);

	ambient_light.init({ 0.60f, 0.60f, 0.60f });
	diffuse_light.init({ 1.0f, 1.0f, 1.0f }, { 0.0f, -1.0f, -1.0f }, 0.4f);
	fog_params.init({ 0.7f, 0.7f, 0.7f }, 20.0f, 75.0f, 0.01f, FogParameters::EQUATION_EXP2);
}

void App::render()
{
	auto clear_color = Vec4f{ 0.02f, 0.682f, 1.0f, 1.0f } * Vec4f{ ambient_light.get_color_contribution(), 1.0f };
	glClearColor(clear_color.r, clear_color.g, clear_color.b, clear_color.a);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	auto &sm = ShaderManager::get_instance();
	auto &pm = SamplerManager::get_instance();
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
	fog_params.set_uniform(program, "fogParams");
	skybox->render_at(camera.position, program);

	// Set up ambient and diffuse light in the shader program
	auto &sampler = pm.samplers["main"];
	sampler.bind();
	ambient_light.set_uniform(program, "ambientLight");
	diffuse_light.set_uniform(program, "diffuseLight");

	// Set up fog parameters in the shader program
	fog_params.set_uniform(program, "fogParams");

	// Render classic houses
	vector<Mat4f> classic_house_matrices;
	for (auto &position : classic_house_positions)
	{
		auto model = Mat4f::translate(Mat4f::eye(1.0f), position);
		auto row = 0, column = 0;
		get_heightmap_row_and_column(position, row, column);
		model = Mat4f::translate(model, { 0.0f, heightmap_with_fog->get_height(row, column) * heightmap_size.y, 0.0f });
		model = Mat4f::scale(model, { 5.0f, 5.0f, 5.0f });
		classic_house_matrices.push_back(model);

		// Render model with the calculated model matrix
		program.set_model_and_normal_matrix(model);
		classic_house_model.render();
	}

	// Render medieval houses
	vector<Mat4f> medieval_house_matrices;
	for (auto &position : medieval_house_positions)
	{
		auto model = Mat4f::translate(Mat4f::eye(1.0f), position);
		auto row = 0, column = 0;
		get_heightmap_row_and_column(position, row, column);
		model = Mat4f::translate(model, { 0.0f, heightmap_with_fog->get_height(row, column) * heightmap_size.y, 0.0f });
		model = Mat4f::scale(model, { 0.1f, 0.1f, 0.1f });
		medieval_house_matrices.push_back(model);

		// Render model with the calculated model matrix
		program.set_model_and_normal_matrix(model);
		medieval_house_model.render();
	}

	// Render heightmap
	auto &heightmap_program = sm.programs["multilayer_heightmap_fog"];
	heightmap_program.use();
	heightmap_program["matrices.projectionMatrix"] = mm.proj;
	heightmap_program["matrices.viewMatrix"] = mm.view;
	heightmap_program.set_model_and_normal_matrix(Mat4f::eye(1.0f));
	heightmap_program["color"] = Vec4f{ 1.0f, 1.0f, 1.0f, 1.0f };
	ambient_light.set_uniform(heightmap_program, "ambientLight");
	diffuse_light.set_uniform(heightmap_program, "diffuseLight");
	fog_params.set_uniform(heightmap_program, "fogParams");

	auto heightmap_model_matrix = Mat4f::scale(Mat4f::eye(1.0f), heightmap_size);
	heightmap_program.set_model_and_normal_matrix(heightmap_model_matrix);
	heightmap_with_fog->render_multi_layered({ "rocky_terrain", "grass", "snow" }, { 0.2f, 0.3f, 0.55f, 0.7f });

	// Render HUD
	hud->render(fog_params);
}

void App::event(SDL_Event *ev)
{
	switch (ev->type)
	{
	case SDL_KEYDOWN:
		switch (ev->key.keysym.sym)
		{
		case SDLK_f:
			fog_params.equation = (fog_params.equation + 1) % 3;
			break;
		case SDLK_x:
			fog_params.enabled = !fog_params.enabled;
			break;
		default:
			switch (fog_params.equation)
			{
			case FogParameters::EQUATION_LINEAR:
				if (ev->key.keysym.sym == SDLK_1)
					fog_params.linear_start -= sof(10.0f);
				else if (ev->key.keysym.sym == SDLK_2)
					fog_params.linear_start += sof(10.0f);
				else if (ev->key.keysym.sym == SDLK_3)
					fog_params.linear_end -= sof(10.0f);
				else if (ev->key.keysym.sym == SDLK_4)
					fog_params.linear_end += sof(10.0f);
				break;

			default:
				if (ev->key.keysym.sym == SDLK_1)
					fog_params.density -= sof(0.02f);
				else if (ev->key.keysym.sym == SDLK_2)
					fog_params.density += sof(0.02f);
				break;
			}
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
	classic_house_model.release();
	medieval_house_model.release();
	heightmap_with_fog->release();
	delete heightmap_with_fog;
	delete skybox;
	delete hud;
}

void App::get_heightmap_row_and_column(Vec3f position, int &row, int &col)
{
	auto half_width = heightmap_size.x / 2.0f;
	auto half_depth = heightmap_size.z / 2.0f;

	row = int(heightmap_with_fog->rows * (position.z + half_depth) / heightmap_size.z);
	col = int(heightmap_with_fog->cols * (position.x + half_width) / heightmap_size.x);
}

int main()
{
	auto title = "020) Fog - Tutorial by Michal Bubnar (www.mbsoftworks.sk)";
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
