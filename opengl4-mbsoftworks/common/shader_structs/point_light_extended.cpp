#include "lib.h"

const double PointLightExtended::MAX_TRAVEL_DISTANCE{ 200.0 };

void PointLightExtended::init(Vec3f position, Vec3f direction, Vec3f color, float ambient_factor,
							  float constant_attenuation, float linear_attenuation, float exponential_attenuation,
							  bool enabled)
{
	PointLight::init(position, color, ambient_factor, constant_attenuation, linear_attenuation, exponential_attenuation, enabled);
	this->direction = direction;
}

void PointLightExtended::update(float speed, float y)
{
	auto new_position = position + direction * speed;
	position += direction * speed;

	if (new_position.x >= MAX_TRAVEL_DISTANCE || new_position.x <= -MAX_TRAVEL_DISTANCE || new_position.z >= MAX_TRAVEL_DISTANCE || new_position.z <= -MAX_TRAVEL_DISTANCE)
	{
		// Reverse light direction in case we would go beyong the world edges
		direction *= -1.0f;
	}
	else
	{
		// Otherwise simply update the position
		position = new_position;
		position.y = y;
	}
}

PointLightExtended PointLightExtended::create_random_point_light(Vec3f position, Vec3f direction)
{
	// Color table and index of next color when generating point light
	static thread_local size_t next_color_index = 0;
	static const Vec3f colors[] = {
		{ 1.0f, 0.0f, 0.0f },
		{ 0.0f, 1.0f, 0.0f },
		{ 0.0f, 0.0f, 1.0f },
		{ 1.0f, 1.0f, 1.0f },
		{ 1.0f, 0.0f, 1.0f },
		{ 0.0f, 1.0f, 1.0f },
		{ 0.5f, 0.0f, 1.0f },
		{ 1.0f, 0.5f, 0.0f }
	};

	// Clamp the position to the world edges
	if (position.x < -MAX_TRAVEL_DISTANCE)
		position.x = -MAX_TRAVEL_DISTANCE;

	if (position.x > MAX_TRAVEL_DISTANCE)
		position.x = MAX_TRAVEL_DISTANCE;

	if (position.z < -MAX_TRAVEL_DISTANCE)
		position.z = -MAX_TRAVEL_DISTANCE;

	if (position.z > MAX_TRAVEL_DISTANCE)
		position.z = MAX_TRAVEL_DISTANCE;

	// Ignore Y component of the direction vector
	direction.y = 0.0f;
	direction = Vec3f::normalize(direction);

	// Take next color and advance next color index
	auto color = colors[next_color_index];
	next_color_index = (next_color_index + 1) % nelem(colors);

	PointLightExtended p;
	p.init(position, direction, color, 0.0f, 0.3f, 0.007f, 0.00008f);
	return p;
}
