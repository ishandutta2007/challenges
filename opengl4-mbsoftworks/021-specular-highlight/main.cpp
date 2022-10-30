#include "lib.h"

vector<Vec3f> triple_tori_positions{
	{ -80.0f, 0.0f, -80.0f },
	{ 80.0f, 0.0f, -80.0f },
	{ -5.0f, 0.0f, 0.0f },
	{ -80.0f, 0.0f, 80.0f },
	{ 82.0f, 0.0f, 75.0f },
};

class HUD021 : public HUD
{
public:
	void init(GLWindow *window, FlyingCamera *camera);
	void render(Material &material, Vec3f diffuse_light_direction);

	FlyingCamera *camera;
};

void HUD021::init(GLWindow *glwindow, FlyingCamera *camera)
{
	HUD::init(glwindow);
	this->camera = camera;

	static once_flag once;
	call_once(once, [&]() {
		auto &fm = FontManager::get_instance();
		fm.load("default", "data/fonts/Roboto-Medium.ttf", 24);
	});
}

void HUD021::render(Material &material, Vec3f diffuse_light_direction)
{
	auto &fm = FontManager::get_instance();

	auto &font = fm.fonts["default"];
	auto x = 10.0f, y = 20.0f;
	font.print(x, y, "FPS: %d", glwindow->fps);
	y += font.pixel_size;
	font.print(x, y, "Paused: %s (Space to toggle)", (glwindow->paused) ? "Yes" : "No");

	y += font.pixel_size;
	font.print(x, y, "Specular highlight:");
	y += font.pixel_size;
	font.print(x, y, "   - calculation: %s (Press 'X' to toggle)", (material.enabled) ? "On" : "Off");

	if (material.enabled)
	{
		y += font.pixel_size;
		font.print(x, y, "   - specular intensity: %.3f (Press '1' and '2' to change)",
				   material.specular_intensity);

		y += font.pixel_size;
		font.print(x, y, "   - specular power: %.3f (Press '3' and '4' to change)",
				   material.specular_power);
	}

	y += font.pixel_size;
	font.print(x, y, "Diffuse light direction: {%.3f %.3f %.3f} (Press 'L' to lock)",
			   diffuse_light_direction.x, diffuse_light_direction.y, diffuse_light_direction.z);
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

	Torus torus;
	float theta;

	Heightmap *heightmap_with_fog;
	Vec3f heightmap_size;

	HUD021 *hud;
	Skybox *skybox;

	Material material;
	AmbientLight ambient_light;
	DiffuseLight diffuse_light;
	bool is_direction_locked;

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

	sm.add_shader("tut021_main_vertex", "data/shaders/tut021-specular-highlight/shader.vert", GL_VERTEX_SHADER);
	sm.add_shader("tut021_main_fragment", "data/shaders/tut021-specular-highlight/shader.frag", GL_FRAGMENT_SHADER);
	sm.add_shader("ambientLight_fragment", "data/shaders/lighting/ambientLight.frag", GL_FRAGMENT_SHADER);
	sm.add_shader("diffuseLight_fragment", "data/shaders/lighting/diffuseLight.frag", GL_FRAGMENT_SHADER);
	sm.add_shader("specularHighlight_fragment", "data/shaders/lighting/specularHighlight.frag", GL_FRAGMENT_SHADER);
	sm.add_shader("utility_fragment", "data/shaders/common/utility.frag", GL_FRAGMENT_SHADER);
	sm.make_program("main", { "tut021_main_vertex", "tut021_main_fragment", "ambientLight_fragment",
							  "diffuseLight_fragment", "specularHighlight_fragment", "utility_fragment" });

	pm.create_sampler("main", MAG_FILTER_BILINEAR, MIN_FILTER_TRILINEAR);
	tm.add_texture("grass", "data/textures/grass.jpg");
	tm.add_texture("rocky_terrain", "data/textures/rocky_terrain.jpg");
	tm.add_texture("snow", "data/textures/snow.png");
	tm.add_texture("scifi_metal", "data/textures/scifi_metal.jpg");

	torus.init(20, 20, 8.0f, 2.0f, true, true, true);

	heightmap_size = { 200.0f, 40.0f, 200.0f };
	heightmap_with_fog = new Heightmap();
	Heightmap::prepare_multi_layer_shader_program();
	heightmap_with_fog->init("data/heightmaps/tut019.png", true, true, true);

	skybox = new Skybox();
	skybox->init("data/skyboxes/jajsnow1", "jpg", true, true, true);

	hud = new HUD021();
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
	theta = 0.0f;

	ambient_light.init({ 0.50f, 0.50f, 0.50f });
	diffuse_light.init({ 1.0f, 1.0f, 1.0f }, Vec3f::normalize({ -sqrtf(2) / 2, -sqrtf(2) / 2, 0.0f }), 0.5f);
	material.init(1.0f, 32.0f);
	is_direction_locked = true;
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
	Material skybox_material;
	skybox_ambient_light.init({ 0.8f, 0.8f, 0.8f }, true);
	skybox_diffuse_light = DiffuseLight::none();
	skybox_ambient_light.set_uniform(program, "ambientLight");
	skybox_diffuse_light.set_uniform(program, "diffuseLight");
	skybox_material = Material::none();
	skybox_material.set_uniform(program, "material");
	skybox->render_at(camera.position, program);

	// Set up ambient and diffuse light in the shader program
	if (!is_direction_locked)
		diffuse_light.direction = Vec3f::normalize(camera.viewpoint - camera.position);
	auto &sampler = pm.samplers["main"];
	sampler.bind();
	ambient_light.set_uniform(program, "ambientLight");
	diffuse_light.set_uniform(program, "diffuseLight");

	// Set up material properties for specular highlights and apply scifi metal texture
	program["eyePosition"] = camera.position;
	material.set_uniform(program, "material");
	tm.textures["scifi_metal"].bind(0);

	// Render triple tori on their positions
	int i = 0;
	for (auto &position : triple_tori_positions)
	{
		auto row = 0, col = 0;
		get_heightmap_row_and_column(position, row, col);
		auto translate_y = heightmap_with_fog->get_height(row, col) * heightmap_size.y + 11.0f;

		auto basic_model_matrix = Mat4f::translate(Mat4f::eye(1.0f), position);
		basic_model_matrix = Mat4f::translate(basic_model_matrix, { 0.0f, translate_y, 0.0f });
		basic_model_matrix = Mat4f::rotate(basic_model_matrix, theta, { 0.0f, 1.0f, 0.0f });

		// Render first torus with the calculated model matrix
		program.set_model_and_normal_matrix(basic_model_matrix);
		torus.render();

		// Rotate by 90 degrees around Y axis and render torus again
		// Also scale slightly, so that the tori won't overlap
		auto second_scale_vector = ((i % 2) == 0) ? Vec3f{ 1.01f, 1.01f, 1.01f } : Vec3f{ 0.6f, 0.6f, 0.6f };
		auto second_tori_model_matrix = Mat4f::scale(basic_model_matrix, second_scale_vector);
		second_tori_model_matrix = Mat4f::rotate(second_tori_model_matrix, radians(90.0f), { 0.0f, 1.0f, 0.0f });
		program.set_model_and_normal_matrix(second_tori_model_matrix);
		torus.render();

		// Rotate by 90 degrees around X axis and render torus again
		// Also scale slightly, so that the tori won't overlap
		auto third_scale_vector = ((i % 2) == 0) ? Vec3f{ 1.02f, 1.02f, 1.02f } : Vec3f{ 0.36f, 0.36f, 0.36f };
		auto third_tori_model_matrix = Mat4f::scale(basic_model_matrix, third_scale_vector);
		third_tori_model_matrix = Mat4f::rotate(third_tori_model_matrix, radians(90.0f), Vec3f{ 1.0f, 0.0f, 0.0f });
		program.set_model_and_normal_matrix(third_tori_model_matrix);
		torus.render();

		i++;
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
	heightmap_with_fog->render_multi_layered({ "snow", "rocky_terrain", "snow" }, { 0.2f, 0.3f, 0.55f, 0.7f });

	// Render HUD
	hud->render(material, diffuse_light.direction);

	theta += sof(radians(30.0f));
}

void App::event(SDL_Event *ev)
{
	switch (ev->type)
	{
	case SDL_KEYDOWN:
		switch (ev->key.keysym.sym)
		{
		case SDLK_x:
			material.enabled = !material.enabled;
			break;
		case SDLK_1:
			material.specular_intensity -= sof(0.5f);
			break;
		case SDLK_2:
			material.specular_intensity += sof(0.5f);
			break;
		case SDLK_3:
			material.specular_power -= sof(10.0f);
			break;
		case SDLK_4:
			material.specular_power += sof(10.0f);
			break;
		case SDLK_l:
			is_direction_locked = !is_direction_locked;
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
	auto title = "021.) Specular Highlight - Tutorial by Michal Bubnar (www.mbsoftworks.sk)";
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
