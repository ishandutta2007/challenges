#include "lib.h"

vector<Vec3f> pyramid_positions{
	{ 0.0f, 0.0f, -100.0f },
	{ 0.0f, 0.0f, -60.0f },
	{ 0.0f, 0.0f, -20.0f },
	{ 0.0f, 0.0f, 20.0f },
	{ 0.0f, 0.0f, 60.0f },
};

vector<Vec3f> crate_positions{
	{ -30.0f, 0.0f, -80.0f },
	{ 30.0f, 0.0f, -40.0f },
	{ -30.0f, 0.0f, 0.0f },
	{ 30.0f, 0.0f, 40.0f },
	{ -30.0f, 0.0f, 80.0f },
};

vector<Vec3f> tori_positions{
	{ 30.0f, 5.0f, -80.0f },
	{ -30.0f, 5.0f, -40.0f },
	{ 30.0f, 5.0f, 0.0f },
	{ -30.0f, 5.0f, 40.0f },
	{ 30.0f, 5.0f, 80.0f },
};

class HUD014 : public HUD
{
public:
	void init(GLWindow *window, FlyingCamera *camera);
	void render(AmbientLight &ambient_light, DiffuseLight &diffuse_light);

	FlyingCamera *camera;
};

void HUD014::init(GLWindow *glwindow, FlyingCamera *camera)
{
	HUD::init(glwindow);
	this->camera = camera;

	static once_flag once;
	call_once(once, [&]() {
		auto &fm = FontManager::get_instance();
		fm.load("default", "data/fonts/Roboto-Medium.ttf", 24);
	});
}

void HUD014::render(AmbientLight &ambient_light, DiffuseLight &diffuse_light)
{
	auto &fm = FontManager::get_instance();

	auto &font = fm.fonts["default"];
	auto x = 10.0f, y = 20.0f;
	font.print(x, y, "FPS: %d", glwindow->fps);
	y += font.pixel_size;
	font.print(x, y, "Paused: %s (Space to toggle)", (glwindow->paused) ? "Yes" : "No");

	y += font.pixel_size;
	font.print(x, y, "Position: {%.3f %.3f %.3f}", camera->position.x, camera->position.y, camera->position.z);
	y += font.pixel_size;
	font.print(x, y, "Viewpoint: {%.3f %.3f %.3f}", camera->viewpoint.x, camera->viewpoint.y, camera->viewpoint.z);

	// Print information about ambient light
	y += font.pixel_size;
	font.print(x, y, "Ambient light: %s (Press 'Z' to toggle)", (ambient_light.on) ? "On" : "Off");
	y += font.pixel_size;
	font.print(x, y, " - color: (%.3f %.3f %.3f) (Press '1' and '2' to change)",
			   ambient_light.color.r, ambient_light.color.g, ambient_light.color.b);

	// Print information about diffuse light
	y += font.pixel_size;
	font.print(x, y, "Diffuse light: %s (Press 'X' to toggle)", (diffuse_light.on) ? "On" : "Off");
	y += font.pixel_size;
	font.print(x, y, " - factor: %.3f (Press '3' and '4' to change)", diffuse_light.factor);
	y += font.pixel_size;
	font.print(x, y, " - direction: {%.3f %.3f %.3f} (Press 'L' to lock)",
			   diffuse_light.direction.x, diffuse_light.direction.y, diffuse_light.direction.z);
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

	Cube cube;
	Torus torus;
	Pyramid pyramid;
	PlainGround plain_ground;
	float theta;

	HUD014 *hud;

	bool is_direction_locked;
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

	pm.create_sampler("main", MAG_FILTER_BILINEAR, MIN_FILTER_TRILINEAR);
	tm.add_texture("grass", "data/textures/grass.jpg");
	tm.add_texture("crate", "data/textures/crate.png");
	tm.add_texture("rocky_terrain", "data/textures/rocky_terrain.jpg");
	tm.add_texture("white_marble", "data/textures/white_marble.jpg");

	cube.init(true, true, true);
	pyramid.init(true, true, true);
	torus.init(20, 20, 3.0f, 1.5f, true, true, true);
	plain_ground.init(true, true, true);

	hud = new HUD014();
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

	is_direction_locked = false;
	ambient_light.init({ 0.50f, 0.50f, 0.50f });
	diffuse_light.init({ 1.0f, 1.0f, 1.0f }, { 0.0f, 0.0f, -1.0f }, 0.75f);
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
	auto &sampler = pm.samplers["main"];
	program.use();
	sampler.bind();
	program["matrices.projectionMatrix"] = mm.proj;
	program["matrices.viewMatrix"] = mm.view;
	program.set_model_and_normal_matrix(Mat4f::eye(1.0f));
	program["color"] = Vec4f{ 1.0f, 1.0f, 1.0f, 1.0f };
	program["sampler"] = 0;

	// Set up ambient light in the shader programs
	ambient_light.set_uniform(program, "ambientLight");

	// Set up diffuse light and set the light's direction to the camera direction
	if (!is_direction_locked)
		diffuse_light.direction = Vec3f::normalize(camera.viewpoint - camera.position);
	diffuse_light.set_uniform(program, "diffuseLight");

	// Render grass ground
	tm.textures["grass"].bind(0);
	plain_ground.render();

	// Render all the crates (as simple cubes)
	for (auto &position : crate_positions)
	{
		auto crate_size = 8.0f;
		auto model = Mat4f::translate(Mat4f::eye(1.0f), position);
		model = Mat4f::translate(model, { 0.0f, crate_size / 2.0f + 3.0f, 0.0f });
		model = Mat4f::rotate(model, theta, { 1.0f, 0.0f, 0.0f });
		model = Mat4f::rotate(model, theta, { 0.0f, 1.0f, 0.0f });
		model = Mat4f::rotate(model, theta, { 0.0f, 0.0f, 1.0f });
		model = Mat4f::scale(model, { crate_size, crate_size, crate_size });
		program.set_model_and_normal_matrix(model);

		tm.textures["crate"].bind(0);
		cube.render();
	}

	// Proceed with rendering rocky pyramids
	for (auto &position : pyramid_positions)
	{
		auto pyramid_size = 10.0f;
		auto model = Mat4f::translate(Mat4f::eye(1.0f), position);
		model = Mat4f::translate(model, { 0.0f, pyramid_size / 2.0f, 0.0f });
		model = Mat4f::scale(model, { pyramid_size, pyramid_size, pyramid_size });
		program.set_model_and_normal_matrix(model);

		tm.textures["rocky_terrain"].bind(0);
		pyramid.render();
	}

	// Finally render tori
	for (auto &position : tori_positions)
	{
		auto model = Mat4f::translate(Mat4f::eye(1.0f), position);
		model = Mat4f::rotate(model, theta + 90.0f, { 0.0f, 1.0f, 0.0f });
		program.set_model_and_normal_matrix(model);

		tm.textures["white_marble"].bind(0);
		torus.render();
	}

	// Render HUD
	hud->render(ambient_light, diffuse_light);

	theta += sof(radians(45.0f));
}

void App::event(SDL_Event *ev)
{
	switch (ev->type)
	{
	case SDL_KEYDOWN:
		switch (ev->key.keysym.sym)
		{
		case SDLK_1:
			ambient_light.color -= Vec3f{ sof(0.25f) };
			if (ambient_light.color.r < 0.0f)
				ambient_light.color = Vec3f{ 0.0f };
			break;

		case SDLK_2:
			ambient_light.color += Vec3f{ sof(0.25f) };
			if (ambient_light.color.r > 1.0f)
				ambient_light.color = Vec3f{ 1.0f };
			break;

		case SDLK_3:
			diffuse_light.factor -= sof(0.25f);
			if (diffuse_light.factor < 0.0f)
				diffuse_light.factor = 0.0f;
			break;

		case SDLK_4:
			diffuse_light.factor += sof(0.25f);
			if (diffuse_light.factor > 1.0f)
				diffuse_light.factor = 1.0f;
			break;

		case SDLK_z:
			ambient_light.on = !ambient_light.on;
			break;

		case SDLK_x:
			diffuse_light.on = !diffuse_light.on;
			break;

		case SDLK_l:
			is_direction_locked = !is_direction_locked;
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
	pyramid.release();
	torus.release();
	cube.release();
	plain_ground.release();
	delete hud;
}

int main()
{
	auto title = "014.) Normals and Diffuse Lighting - Tutorial by Michal Bubnar (www.mbsoftworks.sk)";
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
