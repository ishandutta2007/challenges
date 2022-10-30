#include "lib.h"

SnowCoveredGround::~SnowCoveredGround()
{
	release();
}

void SnowCoveredGround::init(bool has_position, bool has_texcoords, bool has_normals)
{
	PlainGround::init(has_position, has_texcoords, has_normals);

	static once_flag once;
	call_once(once, [&]() {
		auto &sm = ShaderManager::get_instance();
		auto &tm = TextureManager::get_instance();

		sm.add_shader("tut008_ground_vertex", "data/shaders/tut008/ground_shader.vert", GL_VERTEX_SHADER);
		sm.add_shader("tut008_ground_fragment", "data/shaders/tut008/ground_shader.frag", GL_FRAGMENT_SHADER);
		sm.make_program("snow_ground", { "tut008_ground_vertex", "tut008_ground_fragment" });

		tm.add_texture("snow", "data/textures/snow.png");
		tm.add_texture("pavement", "data/textures/pavement.jpg");
		tm.add_texture("tut008_path", "data/textures/tut008/path.png");
	});
}

void SnowCoveredGround::render()
{
	auto &sm = ShaderManager::get_instance();
	auto &pm = SamplerManager::get_instance();
	auto &tm = TextureManager::get_instance();
	auto &mm = MatrixManager::get_instance();

	auto &ground_sampler = pm.samplers["main"];
	auto &ground_program = sm.programs["snow_ground"];
	ground_program.use();
	ground_program["matrices.projectionMatrix"] = mm.proj;
	ground_program["matrices.viewMatrix"] = mm.view;

	// Render ground
	ground_program["matrices.modelMatrix"] = Mat4f::eye(1.0);

	// Setup snow texture
	tm.textures["snow"].bind(0);
	ground_sampler.bind(0);
	ground_program["snowSampler"] = 0;

	// Setup path texture
	tm.textures["tut008_path"].bind(1);
	ground_sampler.bind(1);
	ground_program["pathSampler"] = 1;

	// Setup pavement texture
	tm.textures["pavement"].bind(2);
	ground_sampler.bind(2);
	ground_program["pavementSampler"] = 2;

	PlainGround::render();
}