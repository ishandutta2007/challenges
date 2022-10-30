#include "lib.h"

void DiffuseLight::init(Vec3f color, Vec3f direction, float factor, bool on)
{
	this->color = color;
	this->direction = direction;
	this->factor = factor;
	this->on = on;
}

void DiffuseLight::set_uniform(Program &program, const char *uniform) const
{
	program[stprint("%s.color", uniform)] = color;
	program[stprint("%s.direction", uniform)] = direction;
	program[stprint("%s.factor", uniform)] = factor;
	program[stprint("%s.isOn", uniform)] = on;
}

const DiffuseLight &DiffuseLight::none()
{
	static DiffuseLight none;
	none.init({ 0.0f, 0.0f, 0.0f }, { 0.0f, 0.0f, 0.0f }, 0.0f, false);
	return none;
}