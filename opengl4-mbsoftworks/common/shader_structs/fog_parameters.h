#ifndef _FOG_PARAMETERS_H_
#define _FOG_PARAMETERS_H_

struct FogParameters : public ShaderStruct
{
	enum
	{
		EQUATION_LINEAR = 0,
		EQUATION_EXP = 1,
		EQUATION_EXP2 = 2,
	};

	static const FogParameters &no_fog();

	void init(Vec3f color, float linear_start, float linear_end, float density, int equation, bool enabled = true);

	void set_uniform(Program &program, const char *uniform) const;

	const char *get_equation_name();

	Vec3f color; // Color to be used with fog, usually grayish
	float linear_start; // This is where linear fog starts (valid for linear equation only)
	float linear_end; // This is where linear fog ends (valid for linear equation only)
	float density; // Density of the fog, used by exp and exp2 equation

	int equation; // Used fog equation
	bool enabled; // Flag telling if fog is enabled or not
};

#endif