#ifndef _SNOW_PARTICLE_SYSTEM_H_
#define _SNOW_PARTICLE_SYSTEM_H_

class SnowParticleSystem : public TransformFeedbackParticleSystem
{
public:
	virtual ~SnowParticleSystem()
	{
	}

	void init(int max_particles, FlyingCamera *camera, FogParameters *fog_parameters);

	virtual bool initialize_shaders_and_recorded_variables() override;

	virtual void prepare_update_particles(float dt) override;
	virtual void prepare_render_particles() override;

	void set_particles_color(Vec3f particles_color);
	void set_generated_position_min_max(Vec3f generated_position_min, Vec3f generated_position_max);
	void set_generated_size_min_max(float generated_size_min, float generated_size_max);
	void set_generated_alpha_min_max(float generated_alpha_min, float generated_alpha_max);
	void set_generated_amount(int num_generate_particles, float generate_time);

	FlyingCamera *camera; // Used camera in the scene
	FogParameters *fog_parameters; // Fog parameters to be set for shader program

	Vec3f particles_color; // Color of generated particles

	float remaining_time; // How many seconds remain until next generation batch in seconds
	float generate_time; // How often is one batch of particles generated (in seconds)
	int num_generate_particles; // Number of generated particles in one batch

	Vec3f generated_position_min; // Minimal position of generated particles
	Vec3f generated_position_range; // Maximal position of generated particles

	float generated_size_min; // Minimal size of generated particles
	float generated_size_range; // Maximal size of generated particles

	float generated_alpha_min; // Minimal alpha of generated particles
	float generated_alpha_range; // Maximal alpha of generated particles
};

#endif