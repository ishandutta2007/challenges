#ifndef _DIFFUSE_LIGHT_H_
#define _DIFFUSE_LIGHT_H_

struct DiffuseLight : public ShaderStruct
{
	static const DiffuseLight &none();

	void init(Vec3f color, Vec3f direction, float factor, bool on = true);

	void set_uniform(Program &program, const char *uniform) const;

	Vec3f color; // Color of the diffuse light
	Vec3f direction; // Direction of the diffuse light
	float factor; // Factor to multiply dot product with (strength of light)
	bool on; // Flag telling, if the light is on
};

#endif