#ifndef _SHADER_STRUCTS_H_
#define _SHADER_STRUCTS_H_

class ShaderStruct
{
	virtual void set_uniform(Program &program, const char *uniform) const = 0;
};

#endif