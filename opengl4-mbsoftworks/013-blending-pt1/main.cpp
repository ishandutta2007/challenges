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
	{ -30.0f, 0.0f, -40.0f },
	{ -30.0f, 0.0f, 0.0f },
	{ -30.0f, 0.0f, 40.0f },
	{ -30.0f, 0.0f, 80.0f },
	{ 30.0f, 0.0f, -80.0f },
	{ 30.0f, 0.0f, -40.0f },
	{ 30.0f, 0.0f, 0.0f },
	{ 30.0f, 0.0f, 40.0f },
	{ 30.0f, 0.0f, 80.0f },
};

class HUD013 : public HUD
{
public:
	void init(GLWindow *window);
	void render(bool use_depth_mask);
};

void HUD013::init(GLWindow *glwindow)
{
	HUD::init(glwindow);

	static once_flag once;
	call_once(once, [&]() {
		auto &fm = FontManager::get_instance();
		fm.load("default", "data/fonts/Roboto-Medium.ttf", 24);
	});
}

void HUD013::render(bool use_depth_mask)
{
	auto &fm = FontManager::get_instance();

	auto &font = fm.fonts["default"];
	auto x = 10.0f, y = 20.0f;
	font.print(x, y, "FPS: %d", glwindow->fps);
	y += font.pixel_size;
	font.print(x, y, "Paused: %s (Space to toggle)", (glwindow->paused) ? "Yes" : "No");
	y += font.pixel_size;
	font.print(x, y, "Depth Mask: %s (F4 to toggle)", (use_depth_mask) ? "On" : "Off");
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
	Pyramid pyramid;
	PlainGround plain_ground;
	float theta;

	HUD013 *hud;
	bool use_depth_mask;

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

	sm.add_shader("tut007_main_vertex", "data/shaders/tut007/shader.vert", GL_VERTEX_SHADER);
	sm.add_shader("tut007_main_fragment", "data/shaders/tut007/shader.frag", GL_FRAGMENT_SHADER);
	sm.make_program("main", { "tut007_main_vertex", "tut007_main_fragment" });

	pm.create_sampler("main", MAG_FILTER_BILINEAR, MIN_FILTER_TRILINEAR);
	tm.add_texture("grass", "data/textures/grass.jpg");
	tm.add_texture("crate", "data/textures/crate.png");
	tm.add_texture("diamond", "data/textures/diamond.png");

	cube.init(true, true, false);
	pyramid.init(true, true, false);
	plain_ground.init(true, true, false);

	hud = new HUD013();
	hud->init(this);

	auto err = glGetError();
	if (err)
		printf("GL error: %d\n", err);
}

void App::begin()
{
	load();
	glClearColor(0.02f, 0.682f, 1.0f, 1.0f);
	glEnable(GL_DEPTH_TEST);
	glClearDepth(1.0);

	camera.init({ 0.0f, 10.0f, -60.0f }, { 0.0f, 10.0f, -59.0f }, { 0.0f, 1.0f, 0.0f }, 50.0f);
	theta = 0.0f;
	use_depth_mask = true;
}

void App::render()
{
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
	program["matrices.modelMatrix"] = Mat4f::eye(1.0f);
	program["color"] = Vec4f{ 1.0f, 1.0f, 1.0f, 1.0f };
	program["sampler"] = 0;

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
		program["matrices.modelMatrix"] = model;

		tm.textures["crate"].bind(0);
		cube.render();
	}

	glEnable(GL_BLEND);
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

	// Turn also depth mask back off, if it's desired
	if (!use_depth_mask)
		glDepthMask(0);

	// Change the color of diamond pyramids to white with 50% transparency (alpha is 0.5)
	program["color"] = Vec4f{ 1.0f, 1.0f, 1.0f, 0.5f };

	// Proceed with rendering diamond pyramids
	for (auto &position : pyramid_positions)
	{
		auto pyramid_size = 10.0f;
		auto model = Mat4f::translate(Mat4f::eye(1.0f), position);
		model = Mat4f::translate(model, { 0.0f, pyramid_size / 2.0f, 0.0f });
		model = Mat4f::rotate(model, theta, { 0.0f, 1.0f, 0.0f });
		model = Mat4f::scale(model, { pyramid_size, pyramid_size, pyramid_size });

		program["matrices.modelMatrix"] = model;

		tm.textures["diamond"].bind(0);
		pyramid.render();
	}

	// Turn depth mask back on, if it has been turned off
	if (use_depth_mask)
		glDepthMask(1);
	glDisable(GL_BLEND);

	hud->render(use_depth_mask);

	theta += sof(radians(45.0f));
}

void App::event(SDL_Event *ev)
{
	switch (ev->type)
	{
	case SDL_KEYDOWN:
		switch (ev->key.keysym.sym)
		{
		case SDLK_F4:
			use_depth_mask = !use_depth_mask;
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
	cube.release();
	plain_ground.release();
	delete hud;
}

int main()
{
	auto title = "013.) Blending pt. 1 - Tutorial by Michal Bubnar (www.mbsoftworks.sk)";
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
