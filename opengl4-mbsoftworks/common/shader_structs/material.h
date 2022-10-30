#ifndef _MATERIAL_H_
#define _MATERIAL_H_

struct Material : public ShaderStruct
{
	static const Material &none();

	void init(float specular_intensity, float specular_power, bool enabled = true);

	void set_uniform(Program &program, const char *uniform) const;

	float specular_intensity;
	float specular_power;
	bool enabled;
};

#endif