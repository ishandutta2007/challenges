#include "lib.h"

void FireParticleSystem::init(int max_particles, FlyingCamera *camera, FogParameters *fog_parameters)
{
	particles_color = { 0.83f, 0.435f, 0.0f };

	remaining_time = 0.0f;
	generate_time = 0.05f;
	num_particles = 40;

	generated_position_min = { -5.0f, 0.0f, -5.0f };
	generated_position_range = { 10.0f, 0.0f, 10.0f };

	generated_velocity_min = { -3, 0, -3 };
	generated_velocity_range = { 6, 10, 6 };

	generated_lifetime_min = 1.5f;
	generated_lifetime_range = 2.5f;

	generated_size_min = 0.4f;
	generated_size_range = 0.75f;

	// Point light of fire
	point_light.init(get_center_of_generated_fire(), particles_color, 0.0f, 0.3f, 0.007f, 0.00008f);

	TransformFeedbackParticleSystem::init(max_particles);
	this->camera = camera;
	this->fog_parameters = fog_parameters;
}

bool FireParticleSystem::initialize_shaders_and_recorded_variables()
{
	auto &sm = ShaderManager::get_instance();
	auto &tm = TextureManager::get_instance();

	// Record velocity, lifetime and size
	add_recorded_vec3("outVelocity", false);
	add_recorded_float("outLifetime", true);
	add_recorded_float("outSize", true);

	// Create shader program for updating particles
	// Before linking the program, we have to tell OpenGL which output variables we want to record during transform feedback
	sm.add_shader("fire_particle_system_update_vertex", "data/shaders/tut025-particle-system-tf/fire_update.vert", GL_VERTEX_SHADER);
	sm.add_shader("fire_particle_system_update_geometry", "data/shaders/tut025-particle-system-tf/fire_update.geom", GL_GEOMETRY_SHADER);
	sm.make_program_with_feedback("fire_particle_system_update",
								  { "fire_particle_system_update_vertex", "fire_particle_system_update_geometry", "random_geometry" },
								  get_recorded_variables_names());

	// Create shader program for rendering particles
	sm.add_shader("fire_particle_system_render_vertex", "data/shaders/tut025-particle-system-tf/fire_render.vert", GL_VERTEX_SHADER);
	sm.add_shader("fire_particle_system_render_geometry", "data/shaders/tut025-particle-system-tf/fire_render.geom", GL_GEOMETRY_SHADER);
	sm.add_shader("fire_particle_system_render_fragment", "data/shaders/tut025-particle-system-tf/fire_render.frag", GL_FRAGMENT_SHADER);
	sm.make_program("fire_particle_system_render",
					{ "fire_particle_system_render_vertex", "fire_particle_system_render_geometry",
					  "fire_particle_system_render_fragment", "fog_fragment" });

	// Load texture for fire particles
	tm.add_texture("fire_particle", "data/textures/particles/fire.bmp");

	auto &render_program = sm.programs["fire_particle_system_render"];
	render_program.bind_uniform_block("MatricesBlock", UBO::MATRICES);
	return true;
}

void FireParticleSystem::prepare_update_particles(float dt)
{
	// Get and use program for updating fire particles
	auto &sm = ShaderManager::get_instance();
	auto &sp = sm.programs["fire_particle_system_update"];
	sp.use();

	// Update time passed since last frame
	sp["deltaTime"] = dt;

	// Set uniform variables for generated position boundaries
	sp["generatedPositionMin"] = generated_position_min;
	sp["generatedPositionRange"] = generated_position_range;

	// Set uniform variables for generated velocity boundaries
	sp["generatedVelocityMin"] = generated_velocity_min;
	sp["generatedVelocityRange"] = generated_velocity_range;

	// Set uniform variables for generated lifetime boundaries
	sp["generatedLifetimeMin"] = generated_lifetime_min;
	sp["generatedLifetimeRange"] = generated_lifetime_range;

	// Set uniform variables for generated size boundaries
	sp["generatedSizeMin"] = generated_size_min;
	sp["generatedSizeRange"] = generated_size_range;

	// Update remaining time to generate particles and then decide how many particles will be generated
	remaining_time -= dt;
	if (remaining_time <= 0.0f)
	{
		sp["numParticlesToGenerate"] = num_particles;
		sp["initialRandomGeneratorSeed"] = generate_random_number_generator_seed();
		remaining_time += generate_time;
	}
	else
		sp["numParticlesToGenerate"] = 0;
}

void FireParticleSystem::prepare_render_particles()
{
	auto &tm = TextureManager::get_instance();
	auto &sm = ShaderManager::get_instance();

	// Get and use program for rendering snow particles
	auto &sp = sm.programs["fire_particle_system_render"];
	sp.use();

	// Calculate and set billboarding vectors from our flying camera
	calc_billboarding_vectors(camera->get_normalized_view_vector(), camera->up);
	sp["billboardHorizontalVector"] = billboard_horizontal_vector;
	sp["billboardVerticalVector"] = billboard_vertical_vector;

	// Set sampler, particles color and fog uniforms
	sp["sampler"] = 0;
	sp["particlesColor"] = particles_color;
	fog_parameters->set_uniform(sp, "fogParams");

	// Bind fire particle texture
	tm.textures["fire_particle"].bind();

	sp.bind_uniform_block("MatricesBlock", UBO::MATRICES);
}

void FireParticleSystem::set_particles_color(Vec3f particles_color)
{
	this->particles_color = particles_color;
	this->point_light.color = particles_color;
}

void FireParticleSystem::set_generated_position_min_max(Vec3f generated_position_min, Vec3f generated_position_max)
{
	this->generated_position_min = generated_position_min;
	this->generated_position_range = generated_position_max - generated_position_min;
	this->point_light.position = get_center_of_generated_fire();
}

void FireParticleSystem::set_generated_velocity_min_max(Vec3f generated_velocity_min, Vec3f generated_velocity_max)
{
	this->generated_velocity_min = generated_velocity_min;
	this->generated_velocity_range = generated_velocity_max - generated_velocity_min;
}

void FireParticleSystem::set_generated_lifetime_min_max(float generated_lifetime_min, float generated_lifetime_max)
{
	this->generated_lifetime_min = generated_lifetime_min;
	this->generated_lifetime_range = generated_lifetime_max - generated_lifetime_min;
}

void FireParticleSystem::set_generated_size_min_max(float generated_size_min, float generated_size_max)
{
	this->generated_size_min = generated_size_min;
	this->generated_size_range = generated_size_max - generated_size_min;
}

void FireParticleSystem::set_generated_amount(int num_particles, float generate_time)
{
	this->num_particles = num_particles;
	this->generate_time = generate_time;
}

Vec3f FireParticleSystem::get_center_of_generated_fire()
{
	auto result = generated_position_min + generated_position_range * 0.5f;
	result.y += 3.0f;
	return result;
}
