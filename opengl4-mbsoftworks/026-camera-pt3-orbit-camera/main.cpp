#include "lib.h"

class HUD026 : public HUD
{
public:
	void init(GLWindow *window, OrbitCamera *camera);
	void render(bool wireframe);

	OrbitCamera *camera;
};

void HUD026::init(GLWindow *glwindow, OrbitCamera *camera)
{
	HUD::init(glwindow);
	this->camera = camera;

	static once_flag once;
	call_once(once, [&]() {
		auto &fm = FontManager::get_instance();
		fm.load("default", "data/fonts/Roboto-Medium.ttf", 24);
	});
}

void HUD026::render(bool wireframe)
{
	auto &fm = FontManager::get_instance();

	auto &font = fm.fonts["default"];
	auto x = 10.0f, y = 20.0f;
	font.print(x, y, "FPS: %d", glwindow->fps);
	y += font.pixel_size;
	font.print(x, y, "Paused: %s (Space to toggle)", (glwindow->paused) ? "Yes" : "No");

	y += font.pixel_size;
	font.print(x, y, "Orbit Camera (rotate with LMB pressed, move with RMB pressed):");

	y += font.pixel_size;
	font.print(x, y, "  - Polar angle: %.3f deg", degrees(camera->polar));

	y += font.pixel_size;
	font.print(x, y, "  - Azimuth angle: %.3f deg", degrees(camera->azimuth));

	y += font.pixel_size;
	font.print(x, y, " - Zoom (or radius): %.3f (change by scrolling with mouse wheel)", camera->radius);

	y += font.pixel_size;
	font.print(x, y, " - Center (%.3f %.3f %.3f)", camera->center.x, camera->center.y, camera->center.z);

	y += font.pixel_size;
	font.print(x, y, "Wireframe mode: %d (Press 'X' to toggle)", wireframe);
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
	Cylinder cylinder;
	Sphere sphere;
	Torus torus;

	HUD026 *hud;
	Skybox *skybox;

	Material shiny_material;
	Material dim_material;
	AmbientLight ambient_light;
	DiffuseLight diffuse_light;

	OrbitCamera camera;
	bool wireframe;
	bool rotating;
	bool moving;

	Vec2i prev_mouse;
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

	sm.add_shader("tut026_main_vertex", "data/shaders/tut021-specular-highlight/shader.vert", GL_VERTEX_SHADER);
	sm.add_shader("tut026_main_fragment", "data/shaders/tut021-specular-highlight/shader.frag", GL_FRAGMENT_SHADER);
	sm.add_shader("ambientLight_fragment", "data/shaders/lighting/ambientLight.frag", GL_FRAGMENT_SHADER);
	sm.add_shader("diffuseLight_fragment", "data/shaders/lighting/diffuseLight.frag", GL_FRAGMENT_SHADER);
	sm.add_shader("specularHighlight_fragment", "data/shaders/lighting/specularHighlight.frag", GL_FRAGMENT_SHADER);
	sm.add_shader("utility_fragment", "data/shaders/common/utility.frag", GL_FRAGMENT_SHADER);
	sm.make_program("main", { "tut026_main_vertex", "tut026_main_fragment", "ambientLight_fragment",
							  "diffuseLight_fragment", "specularHighlight_fragment", "utility_fragment" });

	pm.create_sampler("main", MAG_FILTER_BILINEAR, MIN_FILTER_TRILINEAR);
	tm.add_texture("cobblestone_mossy", "data/textures/cobblestone_mossy.png");
	tm.add_texture("crate", "data/textures/crate.png");
	tm.add_texture("white_marble", "data/textures/white_marble.jpg");
	tm.add_texture("scifi_metal", "data/textures/scifi_metal.jpg");

	cube.init(true, true, true);
	cylinder.init(2.0f, 100, 4.0f, true, true, true);
	sphere.init(2.0f, 20, 20, true, true, true);
	torus.init(20, 20, 1.5f, 0.75f, true, true, true);

	skybox = new Skybox();
	skybox->init("data/skyboxes/jajlands1", "jpg", true, true, true);

	hud = new HUD026();
	hud->init(this, &camera);

	auto err = glGetError();
	if (err)
		printf("GL error: %d\n", err);
}

void App::begin()
{
	load();
	glEnable(GL_DEPTH_TEST);

	camera.init({ 0.0f, 0.0f, 0.0f }, { 0.0f, 1.0f, 0.0f }, 15.0f, 3.0f, M_PI * 0.5f, 0.0f);

	ambient_light.init({ 0.25f, 0.25f, 0.25f });
	diffuse_light.init({ 1.0f, 1.0f, 1.0f }, { 0.0f, 0.0f, -1.0f }, 0.75f);
	shiny_material.init(1.0f, 32.0f);
	dim_material.init(0.1f, 64.0f);
	wireframe = false;
	rotating = false;
	moving = false;
	prev_mouse = { 0, 0 };
}

void App::render()
{
	glClearColor(1.0f, 1.0f, 1.0f, 1.0f);
	glClearDepth(1.0);
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
	skybox->render_at(camera.get_eye(), program);

	// After rendering skybox, set ambient and diffuse light from our variables
	program["eyePosition"] = camera.get_eye();
	ambient_light.set_uniform(program, "ambientLight");
	diffuse_light.set_uniform(program, "diffuseLight");

	// Also set our main sampler, that doesn't clamp textures unlike skybox
	pm.samplers["main"].bind();

	// If wireframe mode is on, we need to set polygon mode to GL_LINE
	if (wireframe)
		glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);

	// Render torus in the top-left corner
	tm.textures["scifi_metal"].bind();
	shiny_material.set_uniform(program, "material");
	auto model_matrix = Mat4f::translate(Mat4f::eye(1.0f), { -3.0f, 3.0f, 0.0f });
	program.set_model_and_normal_matrix(model_matrix);
	torus.render();

	// Render cube in top-right corner
	tm.textures["cobblestone_mossy"].bind();
	dim_material.set_uniform(program, "material");
	model_matrix = Mat4f::translate(Mat4f::eye(1.0f), { 3.0f, 3.0f, 0.0f });
	model_matrix = Mat4f::scale(model_matrix, { 4.0f, 4.0f, 4.0f });
	program.set_model_and_normal_matrix(model_matrix);
	cube.render();

	// Render sphere in bottom-right corner
	tm.textures["white_marble"].bind();
	shiny_material.set_uniform(program, "material");
	model_matrix = Mat4f::translate(Mat4f::eye(1.0f), { 3.0f, -3.0f, 0.0f });
	program.set_model_and_normal_matrix(model_matrix);
	sphere.render();

	// Render cylinder in bottom-left corner
	tm.textures["crate"].bind();
	dim_material.set_uniform(program, "material");
	model_matrix = Mat4f::translate(Mat4f::eye(1.0f), { -3.0f, -3.0f, 0.0f });
	program.set_model_and_normal_matrix(model_matrix);
	cylinder.render();

	// Render HUD and restore normal drawing mode
	glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
	hud->render(wireframe);
}

void App::event(SDL_Event *ev)
{
	switch (ev->type)
	{
	case SDL_KEYDOWN:
		switch (ev->key.keysym.sym)
		{
		case SDLK_x:
			wireframe = !wireframe;
			break;
		}
		break;

	case SDL_MOUSEWHEEL:
		camera.zoom(ev->wheel.y * 0.5f);
		break;
	}

	if (paused)
		return;

	// Check if user started to rotate orbit camera with left mouse button
	int mb, mx, my;
	mb = SDL_GetMouseState(&mx, &my);
	if (mb & SDL_BUTTON(SDL_BUTTON_LEFT))
	{
		if (!rotating && !moving)
		{
			rotating = true;
			prev_mouse = { mx, my };
		}
	}
	else
		rotating = false;

	// Check if user started to move with orbit camera with right mouse button
	if (mb & SDL_BUTTON(SDL_BUTTON_RIGHT))
	{
		if (!rotating && !moving)
		{
			moving = true;
			prev_mouse = { mx, my };
		}
	}
	else
		moving = false;

	// Update light direction with camera everytime
	diffuse_light.direction = camera.get_normalized_view_vector();

	if (!rotating && !moving)
		return;

	// Only if we're rotating or moving we should calculate delta of mouse movement
	float dx = mx - prev_mouse.x;
	float dy = my - prev_mouse.y;
	if (rotating)
	{
		camera.rotate_polar(dx * 0.01f);
		camera.rotate_azimuth(dy * 0.01f);
		prev_mouse = { mx, my };
	}
	else if (moving)
	{
		camera.move_horizontal(-dx * 0.05f);
		camera.move_vertical(dy * 0.05f);
		prev_mouse = { mx, my };
	}
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
	cube.release();
	cylinder.release();
	sphere.release();
	torus.release();
	delete skybox;
	delete hud;
}

int main()
{
	auto title = "026.) Camera pt.3 - Orbit Camera - Tutorial by Michal Bubnar (www.mbsoftworks.sk)";
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
