#ifndef _POINT_LIGHT_H_
#define _POINT_LIGHT_H_

struct PointLight : public ShaderStruct
{
	static const PointLight &none();

	void init(Vec3f position, Vec3f color, float ambient_factor,
			  float constant_attenuation, float linear_attenuation, float exponential_attenuation,
			  bool enabled = true);

	void set_uniform(Program &program, const char *uniform) const;

	static GLsizeiptr get_shader_data_size(int);

	Vec3f position; // Position of the point light
	float __DUMMY_PADDING0__; // This is just needed because of std140 layout padding rules
	Vec3f color; // Color of the point light
	float ambient_factor; // Ambient factor (how much this light contributes to the global lighting in any case)
	float constant_attenuation; // Constant attenuation factor of light with rising distance
	float linear_attenuation; // Linear attenuation factor of light with rising distance
	float exponential_attenuation; // Constant attenuation factor of light with rising distance
	bool enabled; // Flag telling, if the light is on
};

#endif