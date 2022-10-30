#include "lib.h"

const FogParameters &FogParameters::no_fog()
{
	static FogParameters none;
	return none;
}

void FogParameters::init(Vec3f color, float linear_start, float linear_end, float density, int equation, bool enabled)
{
	this->color = color;
	this->linear_start = linear_start;
	this->linear_end = linear_end;
	this->density = density;
	this->equation = equation;
	this->enabled = enabled;
}

void FogParameters::set_uniform(Program &program, const char *uniform) const
{
	program[stprint("%s.isEnabled", uniform)] = enabled;
	if (!enabled)
		return;

	program[stprint("%s.color", uniform)] = color;
	program[stprint("%s.linearStart", uniform)] = linear_start;
	program[stprint("%s.linearEnd", uniform)] = linear_end;
	program[stprint("%s.density", uniform)] = density;
	program[stprint("%s.equation", uniform)] = equation;
}

const char *FogParameters::get_equation_name()
{
	return equation == EQUATION_LINEAR ? "Linear" : equation == EQUATION_EXP ? "Exp" : "Exp2";
}
