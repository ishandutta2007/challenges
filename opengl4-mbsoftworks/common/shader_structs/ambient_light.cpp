#include "lib.h"

void AmbientLight::init(Vec3f color, bool on)
{
	this->color = color;
	this->on = on;
}

void AmbientLight::set_uniform(Program &program, const char *uniform) const
{
	program[stprint("%s.color", uniform)] = color;
	program[stprint("%s.isOn", uniform)] = on;
}

Vec3f AmbientLight::get_color_contribution()
{
	return (on) ? color : Vec3f{ 0.0f };
}
