#include "lib.h"

void SnowParticleSystem::init(int max_particles, FlyingCamera *camera, FogParameters *fog_parameters)
{
	remaining_time = 0.0f;
	generate_time = 0.05f;
	num_generate_particles = 40;

	generated_position_min = { -5.0f, 0.0f, -5.0f };
	generated_position_range = { 10.0f, 0.0f, 10.0f };

	particles_color = { 0.83f, 0.435f, 0.0f };

	generated_size_min = 0.4f;
	generated_size_range = 0.75f;

	generated_alpha_min = 0.65f;
	generated_alpha_range = 0.28f;

	TransformFeedbackParticleSystem::init(max_particles);
	this->camera = camera;
	this->fog_parameters = fog_parameters;
}

bool SnowParticleSystem::initialize_shaders_and_recorded_variables()
{
	auto &sm = ShaderManager::get_instance();
	auto &tm = TextureManager::get_instance();

	// Record velocity, lifetime and size
	add_recorded_float("outSize", true);
	add_recorded_float("outAlpha", true);
	add_recorded_int("outSnowflakeIndex", true);

	// Create shader program for updating particles
	// Before linking the program, we have to tell OpenGL which output variables we want to record during transform feedback
	sm.add_shader("snow_particle_system_update_vertex", "data/shaders/tut025-particle-system-tf/snow_update.vert", GL_VERTEX_SHADER);
	sm.add_shader("snow_particle_system_update_geometry", "data/shaders/tut025-particle-system-tf/snow_update.geom", GL_GEOMETRY_SHADER);
	sm.make_program_with_feedback("snow_particle_system_update",
								  { "snow_particle_system_update_vertex", "snow_particle_system_update_geometry", "random_geometry" },
								  get_recorded_variables_names());

	// Create shader program for rendering particles
	sm.add_shader("snow_particle_system_render_vertex", "data/shaders/tut025-particle-system-tf/snow_render.vert", GL_VERTEX_SHADER);
	sm.add_shader("snow_particle_system_render_geometry", "data/shaders/tut025-particle-system-tf/snow_render.geom", GL_GEOMETRY_SHADER);
	sm.add_shader("snow_particle_system_render_fragment", "data/shaders/tut025-particle-system-tf/snow_render.frag", GL_FRAGMENT_SHADER);
	sm.make_program("snow_particle_system_render",
					{ "snow_particle_system_render_vertex", "snow_particle_system_render_geometry",
					  "snow_particle_system_render_fragment", "fog_fragment" });

	// Load texture for snowflake particles
	tm.add_texture("snowflake_particles", "data/textures/particles/snowflakes.bmp");

	auto &render_program = sm.programs["snow_particle_system_render"];
	render_program.bind_uniform_block("MatricesBlock", UBO::MATRICES);
	return true;
}

void SnowParticleSystem::prepare_update_particles(float dt)
{
	// Get and use program for updating fire particles
	auto &sm = ShaderManager::get_instance();
	auto &sp = sm.programs["snow_particle_system_update"];
	sp.use();

	// Update time passed since last frame
	sp["deltaTime"] = dt;

	// Set uniform variables for generated position boundaries
	sp["generatedPositionMin"] = generated_position_min;
	sp["generatedPositionRange"] = generated_position_range;

	// Set uniform variables for generated size boundaries
	sp["generatedSizeMin"] = generated_size_min;
	sp["generatedSizeRange"] = generated_size_range;

	// Set uniform variables for generated alpha boundaries
	sp["generatedAlphaMin"] = generated_alpha_min;
	sp["generatedAlphaRange"] = generated_alpha_range;

	// Update remaining time to generate particles and then decide how many particles will be generated
	remaining_time -= dt;
	if (remaining_time <= 0.0f)
	{
		sp["numParticlesToGenerate"] = num_generate_particles;
		sp["initialRandomGeneratorSeed"] = generate_random_number_generator_seed();
		remaining_time += generate_time;
	}
	else
		sp["numParticlesToGenerate"] = 0;
}

void SnowParticleSystem::prepare_render_particles()
{
	auto &tm = TextureManager::get_instance();
	auto &sm = ShaderManager::get_instance();

	// Get and use program for rendering snow particles
	auto &sp = sm.programs["snow_particle_system_render"];
	sp.use();

	// Calculate and set billboarding vectors from our flying camera
	calc_billboarding_vectors(camera->get_normalized_view_vector(), camera->up);
	sp["billboardHorizontalVector"] = billboard_horizontal_vector;
	sp["billboardVerticalVector"] = billboard_vertical_vector;

	// Set sampler, particles color and fog uniforms
	sp["gSampler"] = 0;
	sp["particlesColor"] = particles_color;
	fog_parameters->set_uniform(sp, "fogParams");

	// Bind snowflake particle texture
	tm.textures["snowflake_particles"].bind();

	sp.bind_uniform_block("MatricesBlock", UBO::MATRICES);
}

void SnowParticleSystem::set_particles_color(Vec3f particles_color)
{
	this->particles_color = particles_color;
}

void SnowParticleSystem::set_generated_position_min_max(Vec3f generated_position_min, Vec3f generated_position_max)
{
	this->generated_position_min = generated_position_min;
	this->generated_position_range = generated_position_max - generated_position_min;
}

void SnowParticleSystem::set_generated_size_min_max(float generated_size_min, float generated_size_max)
{
	this->generated_size_min = generated_size_min;
	this->generated_size_range = generated_size_max - generated_size_min;
}

void SnowParticleSystem::set_generated_alpha_min_max(float generated_alpha_min, float generated_alpha_max)
{
	this->generated_alpha_min = generated_alpha_min;
	this->generated_alpha_range = generated_alpha_max - generated_alpha_min;
}

void SnowParticleSystem::set_generated_amount(int num_generate_particles, float generate_time)
{
	this->num_generate_particles = num_generate_particles;
	this->generate_time = generate_time;
}
