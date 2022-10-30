#ifndef _AMBIENT_LIGHT_H_
#define _AMBIENT_LIGHT_H_

struct AmbientLight : public ShaderStruct
{
	void init(Vec3f color, bool on = true);
	void set_uniform(Program &program, const char *uniform) const;

	Vec3f get_color_contribution();

	Vec3f color;
	bool on;
};

#endif