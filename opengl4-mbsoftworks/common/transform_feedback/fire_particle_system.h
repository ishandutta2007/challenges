#ifndef _FIRE_PARTICLE_SYSTEM_H_
#define _FIRE_PARTICLE_SYSTEM_H_

class FireParticleSystem : public TransformFeedbackParticleSystem
{
public:
	virtual ~FireParticleSystem()
	{
	}

	void init(int max_particles, FlyingCamera *camera, FogParameters *fog_parameters);

	virtual bool initialize_shaders_and_recorded_variables() override;

	virtual void prepare_update_particles(float dt) override;
	virtual void prepare_render_particles() override;

	void set_particles_color(Vec3f particles_color);
	void set_generated_position_min_max(Vec3f generated_position_min, Vec3f generated_position_max);
	void set_generated_velocity_min_max(Vec3f generated_velocity_min, Vec3f generated_velocity_max);
	void set_generated_lifetime_min_max(float generated_lifetime_min, float generated_lifetime_max);
	void set_generated_size_min_max(float generated_size_min, float generated_size_max);
	void set_generated_amount(int num_particles, float generate_time);

	Vec3f get_center_of_generated_fire();

	FlyingCamera *camera; // Used camera in the scene
	FogParameters *fog_parameters; // Fog parameters to be set for shader program

	Vec3f particles_color; // Color of generated particles

	float remaining_time; // How many seconds remain until next generation batch in seconds
	float generate_time; // How often is one batch of particles generated (in seconds)
	int num_particles; // Number of generated particles in one batch

	Vec3f generated_position_min; // Minimal position of generated particles
	Vec3f generated_position_range; // Maximal position of generated particles

	Vec3f generated_velocity_min; // Minimal velocity of generated particles
	Vec3f generated_velocity_range; // Maximal velocity of generated particles

	float generated_lifetime_min; // Minimal lifetime of generated particles
	float generated_lifetime_range; // Maximal lifetime of generated particles

	float generated_size_min; // Minimal size of generated particles
	float generated_size_range; // Maximal size of generated particles

	PointLight point_light;
};

#endif