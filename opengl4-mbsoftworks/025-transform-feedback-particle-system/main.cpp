#include "lib.h"

struct Barn
{
	Vec3f position;
	float angle;
};

vector<Barn> barns{
	{ { -120.0f, 0.0f, -110.0f }, radians(45.0f) },
	{ { 55.0f, 0.0f, 170.0f }, radians(-90.0f) },
	{ { -65.0f, 0.0f, 50.0f }, radians(0.0f) },
	{ { 140.0f, 0.0f, 50.0f }, radians(180.0f) },
	{ { 40.0f, 0.0f, -150.0f }, radians(0.0f) }
};

class HUD025 : public HUD
{
public:
	void init(GLWindow *window, FlyingCamera *camera);
	void render(AmbientLight &ambient_light, int num_fire_particles, int num_snow_particles, bool is_fog_enabled, bool is_fire_dragged);

	FlyingCamera *camera;
};

void HUD025::init(GLWindow *glwindow, FlyingCamera *camera)
{
	HUD::init(glwindow);
	this->camera = camera;

	static once_flag once;
	call_once(once, [&]() {
		auto &fm = FontManager::get_instance();
		fm.load("default", "data/fonts/Roboto-Medium.ttf", 24);
	});
}

void HUD025::render(AmbientLight &ambient_light, int num_fire_particles, int num_snow_particles, bool is_fog_enabled, bool is_fire_dragged)
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
	font.print(x, y, "Particles on scene:");

	y += font.pixel_size;
	font.print(x, y, "  - Fire: %d", num_fire_particles);

	y += font.pixel_size;
	font.print(x, y, "  - Snow: %d", num_snow_particles);

	y += font.pixel_size;
	font.print(x, y, "Fog: %d (Press 'F' to toggle)", is_fog_enabled);

	y += font.pixel_size;
	font.print(x, y, "Drag fire: %d (Press 'X' to toggle)", is_fire_dragged);
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

	Model barn;

	HUD025 *hud;
	Skybox *skybox;

	UBO ubo_matrices;

	AmbientLight ambient_light;
	DiffuseLight diffuse_light;
	FogParameters fog_parameters;

	FireParticleSystem *fire_particle_system;
	SnowParticleSystem *snow_particle_system;
	bool is_fire_dragged;

	SnowCoveredPlainGround *snow_covered_plain_ground;

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

	sm.add_shader("tut025_main_vertex", "data/shaders/tut025-particle-system-tf/shader.vert", GL_VERTEX_SHADER);
	sm.add_shader("tut025_main_fragment", "data/shaders/tut025-particle-system-tf/shader.frag", GL_FRAGMENT_SHADER);
	sm.add_shader("ambientLight_fragment", "data/shaders/lighting/ambientLight.frag", GL_FRAGMENT_SHADER);
	sm.add_shader("diffuseLight_fragment", "data/shaders/lighting/diffuseLight.frag", GL_FRAGMENT_SHADER);
	sm.add_shader("pointLight_fragment", "data/shaders/lighting/pointLight.frag", GL_FRAGMENT_SHADER);
	sm.add_shader("fog_fragment", "data/shaders/fog/fog.frag", GL_FRAGMENT_SHADER);
	sm.add_shader("utility_fragment", "data/shaders/common/utility.frag", GL_FRAGMENT_SHADER);
	sm.add_shader("random_geometry", "data/shaders/common/random.glsl", GL_GEOMETRY_SHADER);
	sm.make_program("main", { "tut025_main_vertex", "tut025_main_fragment", "ambientLight_fragment",
							  "diffuseLight_fragment", "pointLight_fragment", "fog_fragment", "utility_fragment" });

	pm.create_sampler("main", MAG_FILTER_BILINEAR, MIN_FILTER_TRILINEAR);
	tm.add_texture("grass", "data/textures/grass.jpg");
	tm.add_texture("ice", "data/textures/ice.png");
	tm.add_texture("cobblestone_mossy", "data/textures/cobblestone_mossy.png");
	tm.add_texture("rocky_terrain", "data/textures/rocky_terrain.jpg");
	tm.add_texture("scifi_metal", "data/textures/scifi_metal.jpg");

	skybox = new Skybox();
	skybox->init("data/skyboxes/jajsnow1", "jpg", true, true, true);

	// Load barn, but transform the model a bit, as it's strangely rotated and a bit too big
	auto barn_matrix = Mat4f::rotate(Mat4f::eye(1.0f), radians(-90.0f), { 1.0f, 0.0f, 0.0f });
	barn_matrix = Mat4f::scale(barn_matrix, { 0.05f, 0.05f, 0.05f });
	barn.init("data/models/scheune_3ds/scheune.3ds", "", true, true, true, barn_matrix);

	// Create and initialize fire particle system
	fire_particle_system = new FireParticleSystem();
	fire_particle_system->init(10000, &camera, &fog_parameters);

	fire_particle_system->set_generated_amount(40, 0.01f);
	fire_particle_system->set_particles_color({ 0.83f, 0.435f, 0.0f });
	fire_particle_system->set_generated_position_min_max({ 50.0f, 0.0f, 16.0f }, { 54.0f, 0.0f, 20.0f });
	fire_particle_system->set_generated_velocity_min_max({ -2.5f, 0.0f, -2.5f }, { 2.5f, 8.0f, 2.5f });
	fire_particle_system->set_generated_lifetime_min_max(1.5f, 4.0f);
	fire_particle_system->set_generated_size_min_max(0.2f, 0.7f);

	// Create and initialize snow particle system
	snow_particle_system = new SnowParticleSystem();
	snow_particle_system->init(50000, &camera, &fog_parameters);

	snow_particle_system->set_generated_amount(40, 0.005f);
	snow_particle_system->set_particles_color({ 0.85f, 0.85f, 0.85f });
	snow_particle_system->set_generated_size_min_max(0.15f, 0.4f);
	snow_particle_system->set_generated_alpha_min_max(0.5f, 0.8f);

	snow_covered_plain_ground = new SnowCoveredPlainGround();
	snow_covered_plain_ground->init(&ambient_light, &diffuse_light, &fire_particle_system->point_light, &fog_parameters);

	hud = new HUD025();
	hud->init(this, &camera);

	// Bind uniform blocks with binding points for main program
	auto &program = sm.programs["main"];
	program.bind_uniform_block("MatricesBlock", UBO::MATRICES);

	auto err = glGetError();
	if (err)
		printf("GL error: %d\n", err);
}

void App::begin()
{
	load();
	glEnable(GL_DEPTH_TEST);
	glClearDepth(1.0);

	camera.init({ -160.0f, 15.0f, 150.0f }, { -160.0f, 15.0f, 149.0f }, { 0.0f, 1.0f, 0.0f }, 75.0f);

	ambient_light.init({ 0.2f, 0.2f, 0.2f });
	diffuse_light.init({ 1.0f, 1.0f, 1.0f }, Vec3f::normalize({ 0.0f, -1.0f, -1.0f }), 0.2f);
	fog_parameters.init({ 0.7f, 0.7f, 0.7f }, 20.0f, 75.0f, 0.002f, FogParameters::EQUATION_EXP, false);
	is_fire_dragged = false;
}

void App::render()
{
	glClearDepth(1.0);
	glClearColor(1.0f, 1.0f, 1.0f, 1.0f);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	auto &sm = ShaderManager::get_instance();
	auto &pm = SamplerManager::get_instance();
	auto &mm = MatrixManager::get_instance();

	// Set matrices in matrix manager
	mm.proj = proj;
	mm.ortho = ortho;
	mm.orthoyn = orthoyn;
	mm.view = camera.get_view_matrix();

	// Set matrices uniform buffer object data - we just set projection and view matrix here, they are
	// consistent across all shader programs
	auto tproj = Mat4f::transpose(mm.proj);
	auto tview = Mat4f::transpose(mm.view);
	ubo_matrices.bind();
	ubo_matrices.set(0, &tproj, sizeof(Mat4f));
	ubo_matrices.set(sizeof(Mat4f), &tview, sizeof(Mat4f));

	// Set up some common properties in the main shader program
	auto &program = sm.programs["main"];
	program.use();
	program.set_model_and_normal_matrix(Mat4f::eye(1.0f));
	program["color"] = Vec4f{ 1.0f, 1.0f, 1.0f, 1.0f };
	program["sampler"] = 0;

	// Render skybox first with only ambient light and without point lights
	// Btw it's a cool effect if you leave point lights here, looks like the sky is illuminated :)
	ambient_light.set_uniform(program, "ambientLight");
	auto skybox_diffuse_light = DiffuseLight::none();
	skybox_diffuse_light.set_uniform(program, "diffuseLight");
	auto skybox_point_light = PointLight::none();
	skybox_point_light.set_uniform(program, "firePointLight");
	fog_parameters.set_uniform(program, "fogParams");
	skybox->render_at(camera.position, program);

	// Set up material properties for specular highlights and restore point light effects
	auto &sampler = pm.samplers["main"];
	sampler.bind();
	diffuse_light.set_uniform(program, "diffuseLight");
	fire_particle_system->point_light.set_uniform(program, "firePointLight");

	// Render barns with no specular reflections
	for (const auto &bn : barns)
	{
		auto basic_model_matrix = Mat4f::translate(Mat4f::eye(1.0f), bn.position);
		basic_model_matrix = Mat4f::rotate(basic_model_matrix, bn.angle, { 0.0f, 1.0f, 0.0f });
		program.set_model_and_normal_matrix(basic_model_matrix);
		barn.render();
	}

	// Render ground
	snow_covered_plain_ground->render();

	// Enable blending to render particles and disable writing to depth buffer
	glEnable(GL_BLEND);
	glBlendFunc(GL_SRC_ALPHA, GL_ONE);
	glDepthMask(GL_FALSE);

	// Update generated position of fire particles when it's dragged
	if (is_fire_dragged)
	{
		const auto new_fire_position = camera.position + camera.get_normalized_view_vector() * 20.0f;
		const auto new_generated_position_min = Vec3f{ new_fire_position.x - 2.0f, new_fire_position.y, new_fire_position.z - 2.0f };
		const auto new_generated_position_max = Vec3f{ new_fire_position.x + 2.0f, new_fire_position.y, new_fire_position.z + 2.0f };
		fire_particle_system->set_generated_position_min_max(new_generated_position_min, new_generated_position_max);
	}

	// Render particles
	fire_particle_system->render_particles();
	snow_particle_system->render_particles();

	// Re-enable writing to depth buffer and disable blending
	glDepthMask(GL_TRUE);
	glDisable(GL_BLEND);

	// Render HUD
	hud->render(ambient_light,
				fire_particle_system->num_particles, snow_particle_system->num_particles,
				fog_parameters.enabled, is_fire_dragged);

	// Update fire particles
	fire_particle_system->update_particles(sof(1.0f));

	// Update and render snow, also set generated position of snow to always revolve around player
	snow_particle_system->set_generated_position_min_max(camera.position + Vec3f{ -200.0f, 50.0f, -200.0f }, camera.position + Vec3f{ 200.0f, 50.0f, 200.0f });
	snow_particle_system->update_particles(sof(1.0f));
}

void App::event(SDL_Event *ev)
{
	switch (ev->type)
	{
	case SDL_KEYDOWN:
		switch (ev->key.keysym.sym)
		{
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
		case SDLK_f:
			fog_parameters.enabled = !fog_parameters.enabled;
			break;
		case SDLK_x:
			is_fire_dragged = !is_fire_dragged;
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
	auto &sm = ShaderManager::get_instance();
	auto &pm = SamplerManager::get_instance();
	auto &tm = TextureManager::get_instance();
	auto &fm = FontManager::get_instance();

	sm.release();
	tm.release();
	pm.release();
	fm.release();
	delete skybox;
	delete hud;
	delete fire_particle_system;
	delete snow_particle_system;
	delete snow_covered_plain_ground;
}

int main()
{
	auto title = "025.) Transform Feedback Particle System - Tutorial by Michal Bubnar (www.mbsoftworks.sk)";
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
