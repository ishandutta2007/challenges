#include "lib.h"

void Material::init(float specular_intensity, float specular_power, bool enabled)
{
	this->specular_intensity = specular_intensity;
	this->specular_power = specular_power;
	this->enabled = enabled;
}

const Material &Material::none()
{
	static Material none;
	none.init(0.0f, 0.0f, false);
	return none;
}

void Material::set_uniform(Program &program, const char *uniform) const
{
	program[stprint("%s.isEnabled", uniform)] = enabled;
	if (!enabled)
		return;

	program[stprint("%s.specularIntensity", uniform)] = specular_intensity;
	program[stprint("%s.specularPower", uniform)] = specular_power;
}