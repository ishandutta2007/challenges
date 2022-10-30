#include "lib.h"

vector<Vec3f> triple_tori_positions{
	{ -120.0f, 0.0f, -120.0f },
	{ 120.0f, 0.0f, -120.0f },
	{ 120.0f, 0.0f, 120.0f },
	{ -120.0f, 0.0f, 120.0f },
};

vector<Vec3f> barn_positions{
	{ 0.0f, 0.0f, -120.0f },
	{ -120.0f, 0.0f, 0.0f },
	{ 0.0f, 0.0f, 120.0f },
	{ 120.0f, 0.0f, 0.0f },
};

class HUD023 : public HUD
{
public:
	void init(GLWindow *window, FlyingCamera *camera);
	void render(AmbientLight &ambient_light, PointLight &point_light);

	FlyingCamera *camera;
};

void HUD023::init(GLWindow *glwindow, FlyingCamera *camera)
{
	HUD::init(glwindow);
	this->camera = camera;

	static once_flag once;
	call_once(once, [&]() {
		auto &fm = FontManager::get_instance();
		fm.load("default", "data/fonts/Roboto-Medium.ttf", 24);
	});
}

void HUD023::render(AmbientLight &ambient_light, PointLight &point_light)
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
	PlainGround plain_ground;
	float theta;

	Model barn;

	HUD023 *hud;
	Skybox *skybox;

	Material shiny_material;
	AmbientLight ambient_light;
	PointLight point_light_a;
	PointLight point_light_b;
	Vec3f dir_point_light_a;
	Vec3f dir_point_light_b;

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

	sm.add_shader("tut023_main_vertex", "data/shaders/tut023-point-lights/shader.vert", GL_VERTEX_SHADER);
	sm.add_shader("tut023_main_fragment", "data/shaders/tut023-point-lights/shader.frag", GL_FRAGMENT_SHADER);
	sm.add_shader("ambientLight_fragment", "data/shaders/lighting/ambientLight.frag", GL_FRAGMENT_SHADER);
	sm.add_shader("diffuseLight_fragment", "data/shaders/lighting/diffuseLight.frag", GL_FRAGMENT_SHADER);
	sm.add_shader("specularHighlight_fragment", "data/shaders/lighting/specularHighlight.frag", GL_FRAGMENT_SHADER);
	sm.add_shader("pointLight_fragment", "data/shaders/lighting/pointLight.frag", GL_FRAGMENT_SHADER);
	sm.add_shader("utility_fragment", "data/shaders/common/utility.frag", GL_FRAGMENT_SHADER);
	sm.make_program("main", { "tut023_main_vertex", "tut023_main_fragment", "ambientLight_fragment",
							  "diffuseLight_fragment", "specularHighlight_fragment", "pointLight_fragment", "utility_fragment" });

	pm.create_sampler("main", MAG_FILTER_BILINEAR, MIN_FILTER_TRILINEAR);
	tm.add_texture("grass", "data/textures/grass.jpg");
	tm.add_texture("ice", "data/textures/ice.png");
	tm.add_texture("scifi_metal", "data/textures/scifi_metal.jpg");

	sphere.init(2.0f, 8, 8, true, true, true);
	torus.init(20, 20, 8.0f, 2.0f, true, true, true);
	plain_ground.init(true, true, true);

	skybox = new Skybox();
	skybox->init("data/skyboxes/jajsundown1", "jpg", true, true, true);

	// Load barn, but transform the model a bit, as it's strangely rotated and a bit too big
	auto barn_matrix = Mat4f::rotate(Mat4f::eye(1.0f), radians(-90.0f), { 1.0f, 0.0f, 0.0f });
	barn_matrix = Mat4f::scale(barn_matrix, { 0.05f, 0.05f, 0.05f });
	barn.init("data/models/scheune_3ds/scheune.3ds", "", true, true, true, barn_matrix);

	hud = new HUD023();
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

	camera.init({ 0.0f, 25.0f, -60.0f }, { 0.0f, 25.0f, -59.0f }, { 0.0f, 1.0f, 0.0f }, 125.0f);
	theta = 0.0f;

	ambient_light.init({ 0.50f, 0.50f, 0.50f });
	shiny_material.init(1.0f, 32.0f);
	point_light_a.init({ -60.0f, 20.0f, 0.0f }, { 1.0f, 0.0f, 0.0f }, 0.0f, 0.3f, 0.007f, 0.00008f);
	point_light_b.init({ 60.0f, 20.0f, 0.0f }, { 0.0f, 0.0f, 1.0f }, 0.0f, 0.3f, 0.007f, 0.00008f);
	dir_point_light_a = { 0.0f, 0.0f, -1.0f };
	dir_point_light_b = { 0.0f, 0.0f, 1.0f };
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
	PointLight skybox_pointlight;
	skybox_ambient_light.init({ 0.8f, 0.8f, 0.8f }, true);
	skybox_diffuse_light = DiffuseLight::none();
	skybox_ambient_light.set_uniform(program, "ambientLight");
	skybox_diffuse_light.set_uniform(program, "diffuseLight");
	skybox_material = Material::none();
	skybox_material.set_uniform(program, "material");
	skybox_pointlight = PointLight::none();
	skybox_pointlight.set_uniform(program, "pointLightA");
	skybox_pointlight.set_uniform(program, "pointLightB");
	skybox->render_at(camera.position, program);

	// Now setup all lighting properties
	point_light_a.set_uniform(program, "pointLightA");
	point_light_b.set_uniform(program, "pointLightA");

	// Render ground with only ambient light as well
	pm.samplers["main"].bind();
	program.set_model_and_normal_matrix(Mat4f::eye(1.0f));
	tm.textures["grass"].bind();
	plain_ground.render();

	// Set up material properties for specular highlights and apply scifi metal texture
	program["eyePosition"] = camera.position;
	shiny_material.set_uniform(program, "material");
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
	auto &material = Material::none();
	material.set_uniform(program, "material");

	auto barn_rotation_angle = 0.0f;
	for (auto &barn_position : barn_positions)
	{
		auto basic_model_matrix = Mat4f::translate(Mat4f::eye(1.0f), barn_position);
		basic_model_matrix = Mat4f::rotate(basic_model_matrix, barn_rotation_angle, { 0.0f, 1.0f, 0.0f });
		program.set_model_and_normal_matrix(basic_model_matrix);
		barn.render();
		barn_rotation_angle += M_PI / 2.0f;
	}

	// Render and update point light A
	auto point_light_model_matrix_a = Mat4f::translate(Mat4f::eye(1.0f), point_light_a.position);
	program.set_model_and_normal_matrix(point_light_model_matrix_a);
	program["color"] = Vec4f{ point_light_a.color, 1.0f };
	tm.textures["ice"].bind();
	sphere.render();

	point_light_a.position += dir_point_light_a * sof(10.0f);
	if (point_light_a.position.z <= -100.0f || point_light_a.position.z >= 100.0f)
		dir_point_light_a *= -1.0f;

	// Render and update point light B
	auto point_light_model_matrix_b = Mat4f::translate(Mat4f::eye(1.0f), point_light_b.position);
	program.set_model_and_normal_matrix(point_light_model_matrix_b);
	program["color"] = Vec4f{ point_light_b.color, 1.0f };
	tm.textures["ice"].bind();
	sphere.render();

	point_light_b.position += dir_point_light_b * sof(10.0f);
	if (point_light_b.position.z <= -100.0f || point_light_b.position.z >= 100.0f)
		dir_point_light_b *= -1.0f;

	// Render HUD
	hud->render(ambient_light, point_light_a);

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
			shiny_material.enabled = !shiny_material.enabled;
			break;
		case SDLK_1:
			point_light_a.constant_attenuation -= sof(0.2f);
			if (point_light_a.constant_attenuation < 0.0f)
				point_light_a.constant_attenuation = 0.0f;

			point_light_b.constant_attenuation = point_light_a.constant_attenuation;
			break;
		case SDLK_2:
			point_light_a.constant_attenuation += sof(0.2f);
			point_light_b.constant_attenuation = point_light_a.constant_attenuation;
			break;
		case SDLK_3:
			point_light_a.linear_attenuation -= sof(0.01f);
			if (point_light_a.linear_attenuation < 0.0f)
				point_light_a.linear_attenuation = 0.0f;

			point_light_b.linear_attenuation = point_light_a.linear_attenuation;
			break;
		case SDLK_4:
			point_light_a.linear_attenuation += sof(0.01f);
			point_light_b.linear_attenuation = point_light_a.linear_attenuation;
			break;
		case SDLK_5:
			point_light_a.exponential_attenuation -= sof(0.01f);
			if (point_light_a.exponential_attenuation < 0.0f)
				point_light_a.exponential_attenuation = 0.0f;

			point_light_b.exponential_attenuation = point_light_a.exponential_attenuation;
			break;
		case SDLK_6:
			point_light_a.exponential_attenuation += sof(0.01f);
			point_light_b.exponential_attenuation = point_light_a.exponential_attenuation;
			break;
		case SDLK_KP_PLUS:
			ambient_light.color += sof(0.2f);
			if (ambient_light.color.r > 1.0f)
				ambient_light.color = Vec3f{ 1.0f, 1.0f, 1.0f };
			break;
		case SDLK_KP_MINUS:
			ambient_light.color -= sof(0.2f);
			if (ambient_light.color.r < 0.0f)
				ambient_light.color = Vec3f{ 0.0f, 0.0f, 0.0f };
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
	sphere.release();
	torus.release();
	plain_ground.release();
	delete skybox;
	delete hud;
}

int main()
{
	auto title = "023.) Point Lights - Tutorial by Michal Bubnar (www.mbsoftworks.sk)";
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
