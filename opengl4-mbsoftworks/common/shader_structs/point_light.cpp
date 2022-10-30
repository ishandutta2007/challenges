#include "lib.h"

void PointLight::init(Vec3f position, Vec3f color, float ambient_factor,
					  float constant_attenuation, float linear_attenuation, float exponential_attenuation,
					  bool enabled)
{
	this->position = position;
	this->color = color;
	this->ambient_factor = ambient_factor;
	this->constant_attenuation = constant_attenuation;
	this->linear_attenuation = linear_attenuation;
	this->exponential_attenuation = exponential_attenuation;
	this->enabled = enabled;
}

void PointLight::set_uniform(Program &program, const char *uniform) const
{
	program[stprint("%s.position", uniform)] = position;
	program[stprint("%s.color", uniform)] = color;
	program[stprint("%s.ambientFactor", uniform)] = ambient_factor;
	program[stprint("%s.constantAttenuation", uniform)] = constant_attenuation;
	program[stprint("%s.linearAttenuation", uniform)] = linear_attenuation;
	program[stprint("%s.exponentialAttenuation", uniform)] = exponential_attenuation;
	program[stprint("%s.isOn", uniform)] = enabled;
}

const PointLight &PointLight::none()
{
	static PointLight none;
	return none;
}

GLsizeiptr PointLight::get_shader_data_size(int)
{
	// Here it's three times size of vec4 because:
	// - position + dummy padding make first vec4
	// - color + ambient factor make second vec4
	// - attenuation factors + isOn make third vec4
	return sizeof(Vec4f) * 3;
}
