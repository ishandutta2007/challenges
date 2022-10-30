#include "lib.h"

SamplerManager &SamplerManager::get_instance()
{
	static SamplerManager sampler_manager;
	return sampler_manager;
}

Sampler &SamplerManager::create_sampler(const char *key, MagnificationFilter mag_filter, MinificationFilter min_filter)
{
	Sampler sampler;
	sampler.create();
	sampler.bind();
	sampler.set_magnification_filter(mag_filter);
	sampler.set_minification_filter(min_filter);
	samplers[key] = sampler;
	return samplers[key];
}

void SamplerManager::release()
{
	for (auto it = samplers.begin(); it != samplers.end(); it++)
		it->second.release();
}