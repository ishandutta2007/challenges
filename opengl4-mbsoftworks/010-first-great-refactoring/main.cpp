#include "lib.h"

struct HouseTransformation
{
	Vec3f position;
	float angle;
};

vector<HouseTransformation> house_transformations{
	{ { -140, 0, 94 }, radians(90.0f) },
	{ { -140, 0, 64 }, radians(90.0f) },
	{ { -140, 0, 34 }, radians(90.0f) },
	{ { -140, 0, 4 }, radians(90.0f) },
	{ { -97, 0, 18 }, radians(-90.0f) },
	{ { -97, 0, 48 }, radians(-90.0f) },
	{ { -97, 0, 78 }, radians(-90.0f) },
	{ { -63, 0, -14 }, radians(180.0f) },
	{ { -33, 0, -14 }, radians(180.0f) },
	{ { -3, 0, -14 }, radians(180.0f) },
	{ { 27, 0, -14 }, radians(180.0f) },
	{ { -75, 0, -64 }, radians(0.0f) },
	{ { -45, 0, -64 }, radians(0.0f) },
	{ { -15, 0, -64 }, radians(0.0f) },
	{ { 15, 0, -64 }, radians(0.0f) },
	{ { 45, 0, -64 }, radians(0.0f) },
	{ { -121, 0, -54 }, radians(45.0f) }
};

class HUD010 : public HUD
{
public:
	void init(GLWindow *window);
	void render();

	bool blending_enabled;
};

void HUD010::init(GLWindow *glwindow)
{
	HUD::init(glwindow);
	blending_enabled = true;

	static once_flag once;
	call_once(once, [&]() {
		auto &tm = TextureManager::get_instance();
		tm.add_texture("christmas_tree", "data/textures/tut009/christmas_tree.png", false);
		tm.add_texture("snowflake", "data/textures/tut009/snowflake.png", false);
	});
}

void HUD010::render()
{
	auto &sm = ShaderManager::get_instance();
	auto &tm = TextureManager::get_instance();
	auto &pm = SamplerManager::get_instance();
	auto &mm = MatrixManager::get_instance();

	auto &program = sm.programs["ortho_2D"];
	auto &sampler = pm.samplers["HUD"];
	program.use();
	sampler.bind();

	glDisable(GL_DEPTH_TEST);
	glDepthMask(0);
	if (blending_enabled)
	{
		glEnable(GL_BLEND);
		glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
	}

	program["matrices.projectionMatrix"] = mm.ortho;
	program["color"] = Vec4f{ 1.0f, 1.0f, 1.0f, 1.0f };

	// Render Christmas tree bottom left
	auto &christmas_tree_texture = tm.textures["christmas_tree"];
	christmas_tree_texture.bind();
	render_textured_quad_2d(0, 0, christmas_tree_texture.width, christmas_tree_texture.height);

	// Render snowflake bottom right
	auto &snowflake_texture = tm.textures["snowflake"];
	snowflake_texture.bind();
	render_textured_quad_2d(0, 0, snowflake_texture.width, snowflake_texture.height, true);

	if (blending_enabled)
		glDisable(GL_BLEND);

	glDepthMask(1);
	glEnable(GL_DEPTH_TEST);
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

	HUD010 *hud;

	House *house;
	SnowCoveredGround *snow_covered_ground;

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

	sm.add_shader("tut007_main_vertex", "data/shaders/tut007/shader.vert", GL_VERTEX_SHADER);
	sm.add_shader("tut007_main_fragment", "data/shaders/tut007/shader.frag", GL_FRAGMENT_SHADER);
	sm.make_program("main", { "tut007_main_vertex", "tut007_main_fragment" });

	pm.create_sampler("main", MAG_FILTER_BILINEAR, MIN_FILTER_TRILINEAR);

	hud = new HUD010();
	hud->init(this);

	house = new House();
	house->init(true, true, true);

	snow_covered_ground = new SnowCoveredGround();
	snow_covered_ground->init(true, true, true);

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

	camera.init({ -120.0f, 8.0f, 120.0f }, { -120.0f, 8.0f, 119.0f }, { 0.0f, 1.0f, 0.0f }, 50.0f);
}

void App::render()
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	auto &sm = ShaderManager::get_instance();
	auto &mm = MatrixManager::get_instance();
	auto &pm = SamplerManager::get_instance();

	mm.proj = proj;
	mm.ortho = ortho;
	mm.orthoyn = orthoyn;
	mm.view = camera.get_view_matrix();

	snow_covered_ground->render();

	// Render all houses
	auto &main_program = sm.programs["main"];
	main_program.use();
	pm.samplers["main"].bind();
	main_program["matrices.projectionMatrix"] = mm.proj;
	main_program["matrices.viewMatrix"] = mm.view;
	main_program["color"] = Vec4f{ 1.0f, 1.0f, 1.0f, 1.0f };
	main_program["sampler"] = 0;
	for (auto &house_transformation : house_transformations)
		house->render(house_transformation.position, house_transformation.angle);

	hud->render();
}

void App::event(SDL_Event *ev)
{
	switch (ev->type)
	{
	case SDL_KEYDOWN:
		switch (ev->key.keysym.sym)
		{
		case SDLK_F4:
			hud->blending_enabled = !hud->blending_enabled;
			printf("Blending Enabled: %d\n", hud->blending_enabled);
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
	auto &tm = TextureManager::get_instance();
	auto &pm = SamplerManager::get_instance();

	sm.release();
	tm.release();
	pm.release();
	delete house;
	delete snow_covered_ground;
	delete hud;
}

int main()
{
	auto title = "010.) First Great Refactoring - Tutorial by Michal Bubnar (www.mbsoftworks.sk)";
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
