#ifndef _SAMPLER_MANAGER_H_
#define _SAMPLER_MANAGER_H_

class SamplerManager
{
public:
	static SamplerManager &get_instance();

	Sampler &create_sampler(const char *key, MagnificationFilter mag_filter, MinificationFilter min_filter);

	void release();

	map<string, Sampler> samplers;
};

#endif