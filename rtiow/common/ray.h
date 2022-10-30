#ifndef _RAY_H_
#define _RAY_H_

struct ray
{
	point3 origin;
	vec3 direction;

	ray()
		: origin(), direction()
	{
	}

	ray(const point3 &origin, const vec3 &direction)
		: origin(origin), direction(direction)
	{
	}

	point3 at(double t) const
	{
		return origin + t * direction;
	}
};

#endif