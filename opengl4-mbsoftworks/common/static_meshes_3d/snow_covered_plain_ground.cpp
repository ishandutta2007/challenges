#include "lib.h"

void SnowCoveredPlainGround::init(AmbientLight *ambient_light, DiffuseLight *diffuse_light, PointLight *fire_point_light, FogParameters *fog_parameters,
								  bool has_positions, bool has_texcoords, bool has_normals)

{
	PlainGround::init(has_positions, has_texcoords, has_normals);
	this->ambient_light = ambient_light;
	this->diffuse_light = diffuse_light;
	this->fire_point_light = fire_point_light;
	this->fog_parameters = fog_parameters;

	static once_flag once;
	call_once(once, []() {
		auto &sm = ShaderManager::get_instance();
		auto &tm = TextureManager::get_instance();

		sm.add_shader("tut025_ground_vertex", "data/shaders/tut025-particle-system-tf/ground_shader.vert", GL_VERTEX_SHADER);
		sm.add_shader("tut025_ground_fragment", "data/shaders/tut025-particle-system-tf/ground_shader.frag", GL_FRAGMENT_SHADER);
		sm.make_program("tut025_ground", { "tut025_ground_vertex", "tut025_ground_fragment", "ambientLight_fragment",
										   "diffuseLight_fragment", "pointLight_fragment", "fog_fragment", "utility_fragment" });

		tm.add_texture("snow", "data/textures/snow.png");
		tm.add_texture("pavement", "data/textures/pavement.jpg");
		tm.add_texture("tut008_path", "data/textures/tut008/path.png");
	});
}

void SnowCoveredPlainGround::render()
{
	auto &sm = ShaderManager::get_instance();
	auto &tm = TextureManager::get_instance();
	auto &pm = SamplerManager::get_instance();
	auto &mm = MatrixManager::get_instance();

	auto &ground_program = sm.programs["tut025_ground"];
	auto &ground_sampler = pm.samplers["main"];

	ground_program.use();

	ground_program["matrices.projectionMatrix"] = mm.proj;
	ground_program["matrices.viewMatrix"] = mm.view;

	ambient_light->set_uniform(ground_program, "ambientLight");
	diffuse_light->set_uniform(ground_program, "diffuseLight");
	fire_point_light->set_uniform(ground_program, "firePointLight");
	fog_parameters->set_uniform(ground_program, "fogParams");

	// Render ground
	ground_program.set_model_and_normal_matrix(Mat4f::eye(1.0));

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
