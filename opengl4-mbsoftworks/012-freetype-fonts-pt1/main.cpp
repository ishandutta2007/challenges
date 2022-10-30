#include "lib.h"

vector<Vec3f> object_positions{
	{ -30.0f, 0.0f, -50.0f },
	{ -30.0f, 0.0f, -25.0f },
	{ -30.0f, 0.0f, 0.0f },
	{ -30.0f, 0.0f, 25.0f },
	{ -30.0f, 0.0f, 50.0f },
	{ 30.0f, 0.0f, -50.0f },
	{ 30.0f, 0.0f, -25.0f },
	{ 30.0f, 0.0f, 0.0f },
	{ 30.0f, 0.0f, 25.0f },
	{ 30.0f, 0.0f, 50.0f },
};

class HUD012 : public HUD
{
public:
	void init(GLWindow *window);
	void render();
};

void HUD012::init(GLWindow *glwindow)
{
	HUD::init(glwindow);

	static once_flag once;
	call_once(once, [&]() {
		auto &fm = FontManager::get_instance();
		fm.load("default", "data/fonts/Roboto-Medium.ttf", 24);
	});
}

void HUD012::render()
{
	auto &fm = FontManager::get_instance();

	auto &font = fm.fonts["default"];
	auto x = 10.0f, y = 20.0f;
	font.print(x, y, "FPS: %d", glwindow->fps);
	y += font.pixel_size;
	font.print(x, y, "Paused: %s (Space to toggle)", (glwindow->paused) ? "Yes" : "No");
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

	Pyramid pyramid;
	Torus torus;
	PlainGround plain_ground;
	float theta;

	HUD012 *hud;

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
	tm.add_texture("diamond", "data/textures/diamond.png");
	tm.add_texture("metal", "data/textures/metal.png");
	tm.add_texture("ice", "data/textures/ice.png");

	pyramid.init(true, true, false);
	torus.init(20, 20, 3.0f, 1.5f, true, true, false);
	plain_ground.init(true, true, false);

	hud = new HUD012();
	hud->init(this);

	auto err = glGetError();
	if (err)
		printf("GL error: %d\n", err);
}

void App::begin()
{
	load();
	glClearColor(0.18f, 0.0f, 0.356f, 1.0f);
	glEnable(GL_DEPTH_TEST);
	glClearDepth(1.0);

	camera.init({ 0.0f, 10.0f, -60.0f }, { 0.0f, 10.0f, -59.0f }, { 0.0f, 1.0f, 0.0f }, 50.0f);
	theta = 0.0f;
}

void App::render()
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	auto &sm = ShaderManager::get_instance();
	auto &pm = SamplerManager::get_instance();
	auto &tm = TextureManager::get_instance();
	auto &mm = MatrixManager::get_instance();

	mm.proj = proj;
	mm.ortho = ortho;
	mm.orthoyn = orthoyn;
	mm.view = camera.get_view_matrix();

	// Set up some common properties in the main shader program
	auto &main_program = sm.programs["main"];
	main_program.use();
	pm.samplers["main"].bind();
	main_program["matrices.projectionMatrix"] = mm.proj;
	main_program["matrices.viewMatrix"] = mm.view;
	main_program["matrices.modelMatrix"] = Mat4f::eye(1.0f);
	main_program["color"] = Vec4f{ 1.0f, 1.0f, 1.0f, 1.0f };
	main_program["sampler"] = 0;

	// Render icy ground
	tm.textures["ice"].bind(0);
	plain_ground.render();

	for (auto &position : object_positions)
	{
		// Render diamond pyramid on bottom
		auto pyramid_size = 10.0f;
		auto pos_model_matrix = Mat4f::translate(Mat4f::eye(1.0f), position);
		auto model = Mat4f::translate(pos_model_matrix, { 0.0f, pyramid_size / 2.0f, 0.0f });
		model = Mat4f::scale(model, { pyramid_size, pyramid_size, pyramid_size });
		main_program["matrices.modelMatrix"] = model;

		tm.textures["diamond"].bind(0);
		pyramid.render();

		// Render metal torus on top of the pyramid
		auto torus_offset = pyramid_size + torus.main_radius + torus.tube_radius;
		model = Mat4f::translate(pos_model_matrix, { 0.0f, torus_offset, 0.0f });
		model = Mat4f::rotate(model, theta, { 0.0f, 1.0f, 0.0f });
		main_program["matrices.modelMatrix"] = model;

		tm.textures["metal"].bind(0);
		torus.render();
	}

	hud->render();

	theta += sof(radians(135.0f));
}

void App::event(SDL_Event *ev)
{
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
	plain_ground.release();
	delete hud;
}

int main()
{
	auto title = "012.) FreeType Fonts pt. 1 - Tutorial by Michal Bubnar (www.mbsoftworks.sk)";
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
