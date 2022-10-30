#ifndef _POINT_LIGHT_EXTENDED_H_
#define _POINT_LIGHT_EXTENDED_H_

class PointLightExtended : public PointLight
{
public:
	static const double MAX_TRAVEL_DISTANCE;

	virtual ~PointLightExtended()
	{
	}

	void init(Vec3f position, Vec3f direction, Vec3f color, float ambient_factor,
			  float constant_attenuation, float linear_attenuation, float exponential_attenuation,
			  bool enabled = true);

	void update(float speed, const float y);

	static PointLightExtended create_random_point_light(Vec3f position, Vec3f direction);

	Vec3f direction; // current direction of light
};

#endif