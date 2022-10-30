#include "lib.h"

constexpr int MAX_POINT_LIGHTS = 20;

vector<Vec3f> triple_tori_positions{
	{ -140.0f, 0.0f, -140.0f },
	{ 140.0f, 0.0f, -140.0f },
	{ 140.0f, 0.0f, 140.0f },
	{ -140.0f, 0.0f, 140.0f }
};

vector<Vec3f> barn_positions{
	{ 0.0f, 0.0f, -160.0f },
	{ -170.0f, 0.0f, 0.0f },
	{ 0.0f, 0.0f, 160.0f },
	{ 170.0f, 0.0f, 0.0f },
	{ -20.0f, 40.0f, 0.0f }
};

class HUD024 : public HUD
{
public:
	void init(GLWindow *window, FlyingCamera *camera);
	void render(AmbientLight &ambient_light, PointLight &point_light, size_t num_point_lights);

	FlyingCamera *camera;
};

void HUD024::init(GLWindow *glwindow, FlyingCamera *camera)
{
	HUD::init(glwindow);
	this->camera = camera;

	static once_flag once;
	call_once(once, [&]() {
		auto &fm = FontManager::get_instance();
		fm.load("default", "data/fonts/Roboto-Medium.ttf", 24);
	});
}

void HUD024::render(AmbientLight &ambient_light, PointLight &point_light, size_t num_point_lights)
{
	auto &fm = FontManager::get_instance();

	auto &font = fm.fonts["default"];
	auto x = 10.0f, y = 20.0f;
	font.print(x, y, "FPS: %d", glwindow->fps);
	y += font.pixel_size;
	font.print(x, y, "Paused: %s (Space to toggle)", (glwindow->paused) ? "Yes" : "No");

	y += font.pixel_size;
	font.print(x, y, "Ambient light: {%.3f %.3f %.3f} (Press '+' and '-' to change)",
			   ambient_light.color.r, ambient_light.color.g, ambient_light.color.b);

	y += font.pixel_size;
	font.print(x, y, "Point light position {%.3f %.3f %.3f}",
			   point_light.position.x, point_light.position.y, point_light.position.z);

	y += font.pixel_size;
	font.print(x, y, "Point light properties (both are same):");
	y += font.pixel_size;
	font.print(x, y, "   - count: %d (press 'R' to reset)",
			   num_point_lights);
	y += font.pixel_size;
	font.print(x, y, "   - constant attenuation: %.3f (press '1' and '2' to change)",
			   point_light.constant_attenuation);
	y += font.pixel_size;
	font.print(x, y, "   - linear attenuation: %.3f (press '3' and '4' to change)",
			   point_light.linear_attenuation);
	y += font.pixel_size;
	font.print(x, y, "   - exponential attenuation: %.3f (press '5' and '6' to change)",
			   point_light.exponential_attenuation);
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

	Sphere sphere;
	Torus torus;
	float theta;

	Model barn;

	Heightmap *heightmap;
	Vec3f heightmap_size;

	HUD024 *hud;
	Skybox *skybox;

	UBO ubo_matrices;
	UBO ubo_point_lights;

	deque<PointLightExtended> point_lights;

	Material shiny_material;
	AmbientLight ambient_light;

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

	// Create UBO for matrices and bind it to the MATRICES_BLOCK_BINDING_POINT
	ubo_matrices.create(sizeof(Mat4f) * 2);
	ubo_matrices.set_binding_point(UBO::MATRICES);

	// Create UBO for point lights and bind it to the POINT_LIGHTS_BLOCK_BINDING_POINT
	ubo_point_lights.create(MAX_POINT_LIGHTS * PointLight::get_shader_data_size(140));
	ubo_point_lights.set_binding_point(UBO::POINT_LIGHTS);

	sm.add_shader("tut024_main_vertex", "data/shaders/tut024-ubos/shader.vert", GL_VERTEX_SHADER);
	sm.add_shader("tut024_main_fragment", "data/shaders/tut024-ubos/shader.frag", GL_FRAGMENT_SHADER);
	sm.add_shader("ambientLight_fragment", "data/shaders/lighting/ambientLight.frag", GL_FRAGMENT_SHADER);
	sm.add_shader("diffuseLight_fragment", "data/shaders/lighting/diffuseLight.frag", GL_FRAGMENT_SHADER);
	sm.add_shader("specularHighlight_fragment", "data/shaders/lighting/specularHighlight.frag", GL_FRAGMENT_SHADER);
	sm.add_shader("pointLight_fragment", "data/shaders/lighting/pointLight.frag", GL_FRAGMENT_SHADER);
	sm.add_shader("utility_fragment", "data/shaders/common/utility.frag", GL_FRAGMENT_SHADER);
	sm.make_program("main", { "tut024_main_vertex", "tut024_main_fragment", "ambientLight_fragment",
							  "diffuseLight_fragment", "specularHighlight_fragment", "pointLight_fragment", "utility_fragment" });

	pm.create_sampler("main", MAG_FILTER_BILINEAR, MIN_FILTER_TRILINEAR);
	tm.add_texture("grass", "data/textures/grass.jpg");
	tm.add_texture("ice", "data/textures/ice.png");
	tm.add_texture("cobblestone_mossy", "data/textures/cobblestone_mossy.png");
	tm.add_texture("rocky_terrain", "data/textures/rocky_terrain.jpg");
	tm.add_texture("scifi_metal", "data/textures/scifi_metal.jpg");

	sphere.init(2.0f, 8, 8, true, true, true);
	torus.init(20, 20, 8.0f, 2.0f, true, true, true);

	skybox = new Skybox();
	skybox->init("data/skyboxes/jajsundown1", "jpg", true, true, true);

	sm.add_shader("multilayer_heightmap_vertex", "data/shaders/tut024-ubos/multilayer_heightmap.vert", GL_VERTEX_SHADER);
	sm.add_shader("multilayer_heightmap_fragment", "data/shaders/tut024-ubos/multilayer_heightmap.frag", GL_FRAGMENT_SHADER);
	sm.make_program("multilayer_heightmap", {
												"multilayer_heightmap_vertex",
												"multilayer_heightmap_fragment",
												"ambientLight_fragment",
												"diffuseLight_fragment",
												"pointLight_fragment",
												"utility_fragment",
											});
	heightmap_size = { 400.0f, 40.0f, 400.0f };
	heightmap = new Heightmap();
	heightmap->init("data/heightmaps/tut019.png", true, true, true);

	// Load barn, but transform the model a bit, as it's strangely rotated and a bit too big
	auto barn_matrix = Mat4f::rotate(Mat4f::eye(1.0f), radians(-90.0f), { 1.0f, 0.0f, 0.0f });
	barn_matrix = Mat4f::scale(barn_matrix, { 0.05f, 0.05f, 0.05f });
	barn.init("data/models/scheune_3ds/scheune.3ds", "", true, true, true, barn_matrix);

	hud = new HUD024();
	hud->init(this, &camera);

	// Bind uniform blocks with binding points for main program
	auto &program = sm.programs["main"];
	program.bind_uniform_block("MatricesBlock", UBO::MATRICES);
	program.bind_uniform_block("PointLightsBlock", UBO::POINT_LIGHTS);

	// Bind uniform blocks with binding points for custom multilayer heightmap shader program
	auto &heightmap_program = sm.programs["multilayer_heightmap"];
	heightmap_program.bind_uniform_block("MatricesBlock", UBO::MATRICES);
	heightmap_program.bind_uniform_block("PointLightsBlock", UBO::POINT_LIGHTS);

	// Create two initial point lights
	point_lights.push_back(PointLightExtended::create_random_point_light({ -60.0f, 20.0f, 0.0f }, { 0.0f, 0.0f, -1.0f }));
	point_lights.push_back(PointLightExtended::create_random_point_light({ 60.0f, 20.0f, 0.0f }, { 0.0f, 0.0f, 1.0f }));

	auto err = glGetError();
	if (err)
		printf("GL error: %d\n", err);
}

void App::begin()
{
	load();
	glEnable(GL_DEPTH_TEST);
	glClearDepth(1.0);

	camera.init({ 160.0f, 50.0f, -150.0f }, { 160.0f, 50.0f, -149.0f }, { 0.0f, 1.0f, 0.0f }, 125.0f);
	theta = 0.0f;

	ambient_light.init({ 0.1f, 0.1f, 0.1f });
	shiny_material.init(1.0f, 32.0f);
}

void App::render()
{
	glClearDepth(1.0);
	glClearColor(1.0f, 1.0f, 1.0f, 1.0f);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	auto &sm = ShaderManager::get_instance();
	auto &pm = SamplerManager::get_instance();
	auto &tm = TextureManager::get_instance();
	auto &mm = MatrixManager::get_instance();

	// Set matrices in matrix manager
	mm.proj = Mat4f::transpose(proj);
	mm.ortho = ortho;
	mm.orthoyn = orthoyn;
	mm.view = Mat4f::transpose(camera.get_view_matrix());

	// Set matrices uniform buffer object data - we just set projection and view matrix here, they are
	// consistent across all shader programs
	ubo_matrices.bind();
	ubo_matrices.set(0, &mm.proj, sizeof(Mat4f));
	ubo_matrices.set(sizeof(Mat4f), &mm.view, sizeof(Mat4f));

	// Set point lights uniform buffer object data - in our case the poing lights are same across all shader programs
	ubo_point_lights.bind();
	GLsizeiptr offset = 0;
	for (const auto &point_light : point_lights)
	{
		ubo_point_lights.set(offset, (void *)&point_light.position, point_light.get_shader_data_size(140));
		offset += point_light.get_shader_data_size(140);
	}

	// Set up some common properties in the main shader program
	auto &program = sm.programs["main"];
	program.use();
	program.set_model_and_normal_matrix(Mat4f::eye(1.0f));
	program["color"] = Vec4f{ 1.0f, 1.0f, 1.0f, 1.0f };
	program["sampler"] = 0;

	// Render skybox first with only ambient light and without point lights
	// Btw it's a cool effect if you leave point lights here, looks like the sky is illuminated :)
	ambient_light.set_uniform(program, "ambientLight");
	auto diffuse_light = DiffuseLight::none();
	diffuse_light.set_uniform(program, "diffuseLight");
	auto material = Material::none();
	material.set_uniform(program, "material");
	program["numPointLights"] = 0;
	skybox->render_at(camera.position, program);

	// Set up material properties for specular highlights and restore point light effects
	auto &sampler = pm.samplers["main"];
	sampler.bind();
	program["eyePosition"] = camera.position;
	shiny_material.set_uniform(program, "material");
	program["numPointLights"] = (int)point_lights.size();
	tm.textures["scifi_metal"].bind(0);

	// Render triple tori on their positions
	int i = 0;
	for (auto &position : triple_tori_positions)
	{
		auto basic_model_matrix = Mat4f::translate(Mat4f::eye(1.0f), position);
		basic_model_matrix = Mat4f::translate(basic_model_matrix, { 0.0f, torus.main_radius + torus.tube_radius, 0.0f });
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
		third_tori_model_matrix = Mat4f::rotate(third_tori_model_matrix, radians(90.0f), { 1.0f, 0.0f, 0.0f });
		program.set_model_and_normal_matrix(third_tori_model_matrix);
		torus.render();

		i++;
	}

	// Render barns with no specular reflections
	material = Material::none();
	material.set_uniform(program, "material");
	for (auto &barn_position : barn_positions)
	{
		auto basic_model_matrix = Mat4f::translate(Mat4f::eye(1.0f), barn_position);
		program.set_model_and_normal_matrix(basic_model_matrix);
		barn.render();
	}

	// Render all point lights
	for (auto &point_light : point_lights)
	{
		auto point_light_model_matrix = Mat4f::translate(Mat4f::eye(1.0f), point_light.position);
		program.set_model_and_normal_matrix(point_light_model_matrix);
		program["color"] = Vec4f{ point_light.color.x, point_light.color.y, point_light.color.z, 1.0f };
		tm.textures["ice"].bind();
		point_light.update(sof(20.0f), heightmap->get_rendered_height_at_position(heightmap_size, point_light.position) + sphere.radius + 1.0f);
	}

	// Render heightmap
	auto &heightmap_program = sm.programs["multilayer_heightmap"];
	heightmap_program.use();

	// Use common properties like lighting setup
	heightmap_program["color"] = Vec4f{ 1.0f, 1.0f, 1.0f, 1.0f };
	ambient_light.set_uniform(heightmap_program, "ambientLight");
	diffuse_light.set_uniform(heightmap_program, "diffuseLight");

	// Set number of point lights
	heightmap_program["numPointLights"] = (int)point_lights.size();

	// Finally set heightmap model matrix and render it
	const auto heightmap_model_matrix = Mat4f::scale(Mat4f::eye(1.0f), heightmap_size);
	heightmap_program.set_model_and_normal_matrix(heightmap_model_matrix);
	heightmap->render_multi_layered({ "cobblestone_mossy", "grass", "rocky_terrain" }, { 0.2f, 0.3f, 0.55f, 0.7f });

	// Render HUD
	hud->render(ambient_light, *point_lights.begin(), point_lights.size());
}

void App::event(SDL_Event *ev)
{
	auto &first_point_light = *point_lights.begin();
	auto sync_point_lights_attenuations = [this, &first_point_light]() {
		for (auto &point_light : point_lights)
		{
			point_light.constant_attenuation = first_point_light.constant_attenuation;
			point_light.linear_attenuation = first_point_light.linear_attenuation;
			point_light.exponential_attenuation = first_point_light.exponential_attenuation;
		}
	};

	switch (ev->type)
	{
	case SDL_KEYDOWN:
		switch (ev->key.keysym.sym)
		{
		case SDLK_x:
			shiny_material.enabled = !shiny_material.enabled;
			break;

		case SDLK_1:
			first_point_light.constant_attenuation -= sof(0.2f);
			if (first_point_light.constant_attenuation < 0.0f)
				first_point_light.constant_attenuation = 0.0f;
			break;
		case SDLK_2:
			first_point_light.constant_attenuation += sof(0.2f);
			break;

		case SDLK_3:
			first_point_light.linear_attenuation -= sof(0.01f);
			if (first_point_light.linear_attenuation < 0.0f)
				first_point_light.linear_attenuation = 0.0f;
			break;
		case SDLK_4:
			first_point_light.linear_attenuation += sof(0.01f);
			break;

		case SDLK_5:
			first_point_light.exponential_attenuation -= sof(0.01f);
			if (first_point_light.exponential_attenuation < 0.0f)
				first_point_light.exponential_attenuation = 0.0f;
			break;
		case SDLK_6:
			first_point_light.exponential_attenuation += sof(0.01f);
			break;

		case SDLK_KP_PLUS:
			ambient_light.color += sof(0.2f);
			if (ambient_light.color.r > 1.0f)
				ambient_light.color = Vec3f(1.0f);
			break;
		case SDLK_KP_MINUS:
			ambient_light.color -= sof(0.2f);
			if (ambient_light.color.r < 0.0f)
				ambient_light.color = Vec3f(0.0f);
			break;

		case SDLK_c:
			if (point_lights.size() >= MAX_POINT_LIGHTS)
				point_lights.pop_front();

			point_lights.push_back(PointLightExtended::create_random_point_light(camera.position, camera.viewpoint - camera.position));
			break;

		case SDLK_r:
			while (point_lights.size() != 1)
				point_lights.pop_front();
			break;
		}
		sync_point_lights_attenuations();
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
	auto &sm = ShaderManager::get_instance();
	auto &pm = SamplerManager::get_instance();
	auto &tm = TextureManager::get_instance();
	auto &fm = FontManager::get_instance();

	sm.release();
	tm.release();
	pm.release();
	fm.release();
	sphere.release();
	torus.release();
	heightmap->release();
	delete skybox;
	delete hud;
	delete heightmap;
}

int main()
{
	auto title = "024.) Uniform Buffer Object - Tutorial by Michal Bubnar (www.mbsoftworks.sk)";
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
