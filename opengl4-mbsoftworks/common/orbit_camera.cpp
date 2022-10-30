#include "lib.h"

void OrbitCamera::init(Vec3f center, Vec3f up, float radius, float min_radius, float polar, float azimuth)
{
	this->center = center;
	this->up = up;
	this->radius = radius;
	this->min_radius = min_radius;
	this->polar = polar;
	this->azimuth = azimuth;
}

void OrbitCamera::rotate_polar(float rad)
{
	polar += rad;

	// Keep polar angle within range <0..2PI) - it's not necessary, just to have it nicely output
	const auto full_circle = 2.0f * M_PI;
	polar = fmodf(polar, full_circle);
	if (polar < 0.0f)
		polar = full_circle + polar;
}

void OrbitCamera::rotate_azimuth(float rad)
{
	azimuth += rad;

	// Check if the angle hasn't exceeded quarter of a circle to prevent flip, add a bit of epsilon like 0.001 radians
	const float azimuth_cap = M_PI / 2.0f - 0.001f;
	azimuth = clamp(azimuth, -azimuth_cap, azimuth_cap);
}

void OrbitCamera::zoom(float speed)
{
	radius -= speed;
	if (radius < min_radius)
		radius = min_radius;
}

void OrbitCamera::move_horizontal(float speed)
{
	auto position = get_eye();
	auto view_vector = Vec3f::normalize(center - position);
	auto strafe_vector = Vec3f::normalize(Vec3f::cross(view_vector, up));
	center += strafe_vector * speed;
}

void OrbitCamera::move_vertical(float speed)
{
	center += up * speed;
}

Mat4f OrbitCamera::get_view_matrix()
{
	// https://stackoverflow.com/questions/19740463/lookat-function-im-going-crazy
	const auto position = get_eye();

	const auto f = get_normalized_view_vector();
	auto u = Vec3f::normalize(up);
	const auto s = Vec3f::normalize(Vec3f::cross(f, u));
	u = Vec3f::cross(s, f);

	auto m = Mat4f::eye(1.0f);
	m[0][0] = s.x;
	m[1][0] = s.y;
	m[2][0] = s.z;
	m[0][1] = u.x;
	m[1][1] = u.y;
	m[2][1] = u.z;
	m[0][2] = -f.x;
	m[1][2] = -f.y;
	m[2][2] = -f.z;
	m[3][0] = -Vec3f::dot(s, position);
	m[3][1] = -Vec3f::dot(u, position);
	m[3][2] = Vec3f::dot(f, position);
	return Mat4f::transpose(m);
}

Vec3f OrbitCamera::get_eye()
{
	// Calculate sines / cosines of angles
	const auto sine_polar = sin(polar);
	const auto cosine_polar = cos(polar);
	const auto sine_azimuth = sin(azimuth);
	const auto cosine_azimuth = cos(azimuth);

	// Calculate eye position out of them
	const auto t = radius * cosine_azimuth;
	const auto y = center.y + radius * sine_azimuth;
	const auto x = center.x + t * cosine_polar;
	const auto z = center.z + t * sine_polar;

	return { x, y, z };
}

Vec3f OrbitCamera::get_viewpoint()
{
	return center;
}

Vec3f OrbitCamera::get_normalized_view_vector()
{
	return Vec3f::normalize(get_viewpoint() - get_eye());
}
