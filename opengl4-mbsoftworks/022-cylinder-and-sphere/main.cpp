#include "lib.h"

class HUD022 : public HUD
{
public:
	void init(GLWindow *window, FlyingCamera *camera);
	void render(Vec3f diffuse_light_direction, bool display_normals, bool update_space_entities, int sphere_slices, int sphere_stacks);

	FlyingCamera *camera;
};

void HUD022::init(GLWindow *glwindow, FlyingCamera *camera)
{
	HUD::init(glwindow);
	this->camera = camera;

	static once_flag once;
	call_once(once, [&]() {
		auto &fm = FontManager::get_instance();
		fm.load("default", "data/fonts/Roboto-Medium.ttf", 24);
	});
}

void HUD022::render(Vec3f diffuse_light_direction, bool display_normals, bool update_space_entities, int sphere_slices, int sphere_stacks)
{
	auto &fm = FontManager::get_instance();

	auto &font = fm.fonts["default"];
	auto x = 10.0f, y = 20.0f;
	font.print(x, y, "FPS: %d", glwindow->fps);
	y += font.pixel_size;
	font.print(x, y, "Paused: %s (Space to toggle)", (glwindow->paused) ? "Yes" : "No");

	y += font.pixel_size;
	font.print(x, y, "Diffuse light direction: {%.3f %.3f %.3f} (Press 'L' to lock)",
			   diffuse_light_direction.x, diffuse_light_direction.y, diffuse_light_direction.z);

	y += font.pixel_size;
	font.print(x, y, "Sphere parameters:");
	y += font.pixel_size;
	font.print(x, y, "Slices: %d (Press '1' and '2' to alter)", sphere_slices);
	y += font.pixel_size;
	font.print(x, y, "Stacks: %d (Press '3' and '4' to alter)", sphere_stacks);

	y += font.pixel_size;
	font.print(x, y, "Update space entities: %s (Press 'X' to toggle)", (update_space_entities) ? "On" : "Off");

	y += font.pixel_size;
	font.print(x, y, "Display Normals: %s (Press 'N' to toggle)", (display_normals) ? "On" : "Off");
}

class Planet
{
public:
	void init(GLWindow *window, const char *texture_key, Material &material,
			  float radius, float distance_from_center, float orbital_period_days,
			  float rotation_angle_speed, float initial_orbit_angle);

	void render();
	void render_points();

	void update();

	static void init_geometry(int slices, int stacks);
	static void release_geometry();

	Mat4f get_model_matrix();

	static Sphere sphere_mesh; // Sphere mesh

	GLWindow *window;

	const char *texture_key; // Texture key used to render this planet
	Material material; // Material used

	float radius; // Radius of the planet
	float distance_from_center; // Distance from the center of solar system (from sun)

	float travel_angle_speed; // How fast planet orbits (in radians)
	float rotation_angle_speed; // How fast planet rotates around its axis (in radians)

	float orbit_angle; // Current orbit angle
	float rotation_angle; // Current rotation angle
};

Sphere Planet::sphere_mesh;

void Planet::init(GLWindow *window, const char *texture_key, Material &material,
				  float radius, float distance_from_center, float orbital_period_days,
				  float rotation_angle_speed, float initial_orbit_angle)
{
	this->window = window;
	this->texture_key = texture_key;
	this->material = material;
	this->radius = radius;
	this->distance_from_center = distance_from_center;
	this->rotation_angle_speed = rotation_angle_speed;
	this->orbit_angle = initial_orbit_angle;
	this->travel_angle_speed = (orbital_period_days == 0.0f) ? 0.0f : 0.25f * 365.0f / orbital_period_days;
	this->rotation_angle = 0.0f;
}

void Planet::render()
{
	auto &sm = ShaderManager::get_instance();
	auto &tm = TextureManager::get_instance();
	auto &main_program = sm.programs["main"];

	tm.textures[texture_key].bind();
	material.set_uniform(main_program, "material");

	main_program.set_model_and_normal_matrix(get_model_matrix());
	Planet::sphere_mesh.render();
}

void Planet::render_points()
{
	auto &sm = ShaderManager::get_instance();
	auto &normals_program = sm.programs["normals"];
	normals_program.set_model_and_normal_matrix(get_model_matrix());
	Planet::sphere_mesh.render_points();
}

void Planet::update()
{
	orbit_angle += window->sof(travel_angle_speed);
	rotation_angle += window->sof(rotation_angle_speed);
}

void Planet::init_geometry(int slices, int stacks)
{
	Planet::sphere_mesh.init(1.0f, slices, stacks, true, true, true);
}

void Planet::release_geometry()
{
	Planet::sphere_mesh.release();
}

Mat4f Planet::get_model_matrix()
{
	auto model_matrix = Mat4f::eye(1.0f);
	model_matrix = Mat4f::rotate(model_matrix, orbit_angle, { 0.0f, 1.0f, 0.0f });
	model_matrix = Mat4f::translate(model_matrix, { 0.0f, 0.0f, distance_from_center });
	model_matrix = Mat4f::rotate(model_matrix, rotation_angle, { 0.0f, 1.0f, 0.0f });
	model_matrix = Mat4f::scale(model_matrix, { radius, radius, radius });
	return model_matrix;
}

class SpaceStation
{
public:
	static void init_geometry();
	static void release_geometry();

	void init(GLWindow *window, Vec3f position, float sphere_radius, float cylinder_radius);

	void render();
	void render_points();

	void update();

	Mat4f get_sphere_model_matrix();

	Mat4f get_front_cylinder_matrix();
	Mat4f get_right_cylinder_matrix();
	Mat4f get_back_cylinder_matrix();
	Mat4f get_left_cylinder_matrix();
	Mat4f get_top_cylinder_matrix();
	Mat4f get_bottom_cylinder_matrix();
	vector<Mat4f> get_all_cylinder_matrices();

	static Material material; // Material used (shiny)
	static Sphere sphere_mesh; // Sphere mesh
	static Cylinder cylinder_mesh; // Cylinder mesh

	GLWindow *window;

	Vec3f position; // Position of the space station
	float sphere_radius; // Radius of sphere
	float cylinder_radius; // Radius of its cylinders

	float sphere_angle; // Sphere rotation angle
	float cylinders_angle; // Cylinders rotation angle

	float cylinder_height; // Cached height of cylinder based on sphere radius
};

Material SpaceStation::material;
Sphere SpaceStation::sphere_mesh;
Cylinder SpaceStation::cylinder_mesh;

void SpaceStation::init(GLWindow *window, Vec3f position, float sphere_radius, float cylinder_radius)
{
	this->window = window;
	this->position = position;
	this->sphere_radius = sphere_radius;
	this->cylinder_radius = cylinder_radius;
	this->cylinder_height = sphere_radius * 1.25f;
}

void SpaceStation::render()
{
	auto &sm = ShaderManager::get_instance();
	auto &tm = TextureManager::get_instance();
	auto &main_program = sm.programs["main"];

	tm.textures["scifi_metal"].bind();

	main_program.set_model_and_normal_matrix(get_sphere_model_matrix());
	SpaceStation::sphere_mesh.render();

	for (auto &cylinder_matrix : get_all_cylinder_matrices())
	{
		main_program.set_model_and_normal_matrix(cylinder_matrix);
		SpaceStation::cylinder_mesh.render();
	}
}

void SpaceStation::render_points()
{
	auto &sm = ShaderManager::get_instance();
	auto &normals_program = sm.programs["normals"];
	normals_program.set_model_and_normal_matrix(get_sphere_model_matrix());
	SpaceStation::sphere_mesh.render_points();

	for (auto &cylinder_matrix : get_all_cylinder_matrices())
	{
		normals_program.set_model_and_normal_matrix(cylinder_matrix);
		SpaceStation::cylinder_mesh.render_points();
	}
}

Mat4f SpaceStation::get_sphere_model_matrix()
{
	auto model_matrix = Mat4f::eye(1.0f);
	model_matrix = Mat4f::translate(model_matrix, position);
	model_matrix = Mat4f::scale(model_matrix, { sphere_radius, sphere_radius * 0.25f, sphere_radius });
	model_matrix = Mat4f::rotate(model_matrix, sphere_angle, { 0.0f, 1.0f, 0.0f });
	return model_matrix;
}

Mat4f SpaceStation::get_front_cylinder_matrix()
{
	auto model_matrix = Mat4f::eye(1.0f);
	model_matrix = Mat4f::translate(model_matrix, position);
	model_matrix = Mat4f::translate(model_matrix, { 0.0f, 0.0f, -cylinder_height });
	model_matrix = Mat4f::rotate(model_matrix, radians(90.0f), { 1.0f, 0.0f, 0.0f });
	model_matrix = Mat4f::rotate(model_matrix, cylinders_angle, { 0.0f, 1.0f, 0.0f });
	model_matrix = Mat4f::scale(model_matrix, { cylinder_radius, cylinder_height, cylinder_radius });
	return model_matrix;
}

Mat4f SpaceStation::get_right_cylinder_matrix()
{
	auto model_matrix = Mat4f::eye(1.0f);
	model_matrix = Mat4f::translate(model_matrix, position);
	model_matrix = Mat4f::translate(model_matrix, { cylinder_height, 0.0f, 0.0f });
	model_matrix = Mat4f::rotate(model_matrix, radians(90.0f), { 1.0f, 0.0f, 0.0f });
	model_matrix = Mat4f::rotate(model_matrix, radians(90.0f), { 0.0f, 0.0f, 1.0f });
	model_matrix = Mat4f::rotate(model_matrix, cylinders_angle, { 0.0f, 1.0f, 0.0f });
	model_matrix = Mat4f::scale(model_matrix, { cylinder_radius, cylinder_height, cylinder_radius });
	return model_matrix;
}

Mat4f SpaceStation::get_back_cylinder_matrix()
{
	auto model_matrix = Mat4f::eye(1.0f);
	model_matrix = Mat4f::translate(model_matrix, position);
	model_matrix = Mat4f::translate(model_matrix, { 0.0f, 0.0f, cylinder_height });
	model_matrix = Mat4f::rotate(model_matrix, radians(90.0f), { 1.0f, 0.0f, 0.0f });
	model_matrix = Mat4f::rotate(model_matrix, cylinders_angle, { 0.0f, 1.0f, 0.0f });
	model_matrix = Mat4f::scale(model_matrix, { cylinder_radius, cylinder_height, cylinder_radius });
	return model_matrix;
}

Mat4f SpaceStation::get_left_cylinder_matrix()
{
	auto model_matrix = Mat4f::eye(1.0f);
	model_matrix = Mat4f::translate(model_matrix, position);
	model_matrix = Mat4f::translate(model_matrix, { -cylinder_height, 0.0f, 0.0f });
	model_matrix = Mat4f::rotate(model_matrix, radians(90.0f), { 1.0f, 0.0f, 0.0f });
	model_matrix = Mat4f::rotate(model_matrix, radians(90.0f), { 0.0f, 0.0f, 1.0f });
	model_matrix = Mat4f::rotate(model_matrix, cylinders_angle, { 0.0f, 1.0f, 0.0f });
	model_matrix = Mat4f::scale(model_matrix, { cylinder_radius, cylinder_height, cylinder_radius });
	return model_matrix;
}

Mat4f SpaceStation::get_top_cylinder_matrix()
{
	auto model_matrix = Mat4f::eye(1.0f);
	model_matrix = Mat4f::translate(model_matrix, position);
	model_matrix = Mat4f::translate(model_matrix, { 0.0f, sphere_radius * 0.25f + cylinder_height * 0.4f, 0.0f });
	model_matrix = Mat4f::scale(model_matrix, { cylinder_radius, cylinder_height, cylinder_radius });
	model_matrix = Mat4f::rotate(model_matrix, cylinders_angle, { 0.0f, 1.0f, 0.0f });
	return model_matrix;
}

Mat4f SpaceStation::get_bottom_cylinder_matrix()
{
	auto model_matrix = Mat4f::eye(1.0f);
	model_matrix = Mat4f::translate(model_matrix, position);
	model_matrix = Mat4f::translate(model_matrix, { 0.0f, -sphere_radius - 0.25f + cylinder_height * 0.4f, 0.0f });
	model_matrix = Mat4f::scale(model_matrix, { cylinder_radius, cylinder_height, cylinder_radius });
	model_matrix = Mat4f::rotate(model_matrix, cylinders_angle, { 0.0f, 1.0f, 0.0f });
	return model_matrix;
}

vector<Mat4f> SpaceStation::get_all_cylinder_matrices()
{
	return {
		get_front_cylinder_matrix(),
		get_right_cylinder_matrix(),
		get_back_cylinder_matrix(),
		get_left_cylinder_matrix(),
		get_top_cylinder_matrix(),
		get_bottom_cylinder_matrix(),
	};
}

void SpaceStation::update()
{
	sphere_angle += window->sof(0.25f);
	cylinders_angle += window->sof(0.5f);
}

void SpaceStation::init_geometry()
{
	SpaceStation::sphere_mesh.init(1.0f, 10, 6, true, true, true);
	SpaceStation::cylinder_mesh.init(1.0f, 20, 1.0f, true, true, true);
}

void SpaceStation::release_geometry()
{
	SpaceStation::sphere_mesh.release();
	SpaceStation::cylinder_mesh.release();
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

	HUD022 *hud;
	Skybox *skybox;

	Material dim_material;
	Material shiny_material;
	int sphere_slices;
	int sphere_stacks;
	bool update_space_entities;
	bool display_normals;

	AmbientLight ambient_light;
	DiffuseLight diffuse_light;
	bool is_direction_locked;

	vector<Planet> planets;
	SpaceStation space_station;

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

	sm.add_shader("normals_vertex", "data/shaders/normals/normals.vert", GL_VERTEX_SHADER);
	sm.add_shader("normals_geometry", "data/shaders/normals/normals.geom", GL_GEOMETRY_SHADER);
	sm.add_shader("normals_fragment", "data/shaders/normals/normals.frag", GL_FRAGMENT_SHADER);
	sm.make_program("normals", { "normals_vertex", "normals_geometry", "normals_fragment" });

	pm.create_sampler("main", MAG_FILTER_BILINEAR, MIN_FILTER_TRILINEAR);
	tm.add_texture("scifi_metal", "data/textures/scifi_metal.jpg");
	tm.add_texture("sun", "data/textures/solar_system/2k_sun.jpg");
	tm.add_texture("mercury", "data/textures/solar_system/2k_mercury.jpg");
	tm.add_texture("venus", "data/textures/solar_system/2k_venus_surface.jpg");
	tm.add_texture("earth", "data/textures/solar_system/2k_earth_daymap.jpg");
	tm.add_texture("mars", "data/textures/solar_system/2k_mars.jpg");
	tm.add_texture("jupiter", "data/textures/solar_system/2k_jupiter.jpg");
	tm.add_texture("saturn", "data/textures/solar_system/2k_saturn.jpg");
	tm.add_texture("uranus", "data/textures/solar_system/2k_uranus.jpg");
	tm.add_texture("neptune", "data/textures/solar_system/2k_neptune.jpg");

	skybox = new Skybox();
	skybox->init("data/skyboxes/space_lightblue", "jpg", true, true, true);

	hud = new HUD022();
	hud->init(this, &camera);

	Planet::init_geometry(sphere_slices, sphere_stacks);
	SpaceStation::init_geometry();

	// The orbital periods of planets are actual periods taken from Wikipedia (in Earth days)
	planets.resize(9);
	planets[0].init(this, "sun", shiny_material, 60.0f, 0.0f, 0.0f, 0.05f, 0.0f); // I know that Sun isn't a planet :P
	planets[1].init(this, "mercury", dim_material, 8.0f, 105.0f, 87.9691f, 1.0f, 2.0f);
	planets[2].init(this, "venus", shiny_material, 18.0f, 160.0f, 224.701f, 0.5f, 2.5f);
	planets[3].init(this, "earth", dim_material, 20.0f, 240.0f, 365.0f, 1.0f, 4.0f);
	planets[4].init(this, "mars", dim_material, 13.0f, 320.0f, 686.971f, 0.7f, 1.0f);
	planets[5].init(this, "jupiter", dim_material, 47.0f, 450.0f, 4332.59f, 0.8f, 0.2f);
	planets[6].init(this, "saturn", dim_material, 35.0f, 570.0f, 10759.22f, 0.5f, 0.3f);
	planets[7].init(this, "uranus", shiny_material, 25.0f, 650.0f, 30688.5f, 0.6f, 0.4f);
	planets[8].init(this, "neptune", shiny_material, 24.0f, 730.0f, 60182.0f, 0.5f, 0.5f);

	space_station.init(this, { 100.0f, 100.0f, -100.0f }, 15.0f, 3.0f);

	auto err = glGetError();
	if (err)
		printf("GL error: %d\n", err);
}

void App::begin()
{
	camera.init({ 0.0f, 25.0f, -60.0f }, { 0.0f, 25.0f, -59.0f }, { 0.0f, 1.0f, 0.0f }, 50.0f);

	ambient_light.init({ 0.50f, 0.50f, 0.50f });
	diffuse_light.init({ 1.0f, 1.0f, 1.0f }, Vec3f::normalize({ -sqrtf(2) / 2, -sqrtf(2) / 2, 0.0f }), 0.5f);
	dim_material.init(0.5f, 13.0f);
	shiny_material.init(1.0f, 32.0f);
	sphere_slices = 20;
	sphere_stacks = 20;
	is_direction_locked = true;
	update_space_entities = true;
	display_normals = true;

	load();
	glEnable(GL_DEPTH_TEST);
	glClearDepth(1.0);
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

	// Set up material properties for specular highlights
	program["eyePosition"] = camera.position;
	shiny_material.set_uniform(program, "material");

	// Render space entities
	for (auto &planet : planets)
		planet.render();

	space_station.render();

	if (display_normals)
	{
		// Set up some common properties in the normals shader program
		auto &normals_program = sm.programs["normals"];
		normals_program.use();
		normals_program["matrices.projectionMatrix"] = mm.proj;
		normals_program["matrices.viewMatrix"] = mm.view;
		normals_program["normalLength"] = 2.0f;

		// Render space entities normals
		for (auto &planet : planets)
			planet.render_points();

		space_station.render_points();
	}

	// Update space entities
	if (update_space_entities)
	{
		for (auto &planet : planets)
			planet.update();

		space_station.update();
	}

	// Render HUD
	hud->render(diffuse_light.direction, display_normals, update_space_entities, sphere_slices, sphere_stacks);
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
		case SDLK_l:
			is_direction_locked = !is_direction_locked;
			break;
		case SDLK_x:
			update_space_entities = !update_space_entities;
			break;
		case SDLK_1:
			if (sphere_slices > 3)
			{
				sphere_slices--;
				Planet::init_geometry(sphere_slices, sphere_stacks);
			}
			break;
		case SDLK_2:
			sphere_slices++;
			Planet::init_geometry(sphere_slices, sphere_stacks);
			break;
		case SDLK_3:
			if (sphere_stacks > 2)
			{
				sphere_stacks--;
				Planet::init_geometry(sphere_slices, sphere_stacks);
			}
			break;
		case SDLK_4:
			sphere_stacks++;
			Planet::init_geometry(sphere_slices, sphere_stacks);
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

	SpaceStation::release_geometry();
	Planet::release_geometry();
	sm.release();
	tm.release();
	pm.release();
	fm.release();
	delete skybox;
	delete hud;
}

int main()
{
	auto title = "022.) Cylinder And Sphere - Tutorial by Michal Bubnar (www.mbsoftworks.sk)";
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
