#include "lib.h"

void SimpleWalkingCamera::init(Vec3f position, Vec3f viewpoint, Vec3f up, float move_speed, float rotation_speed)
{
	this->position = position;
	this->viewpoint = viewpoint;
	this->up = up;
	this->move_speed = move_speed;
	this->rotation_speed = rotation_speed;
	set_controls(SDLK_w, SDLK_s, SDLK_a, SDLK_d);
}

void SimpleWalkingCamera::set_controls(int forward, int backward, int rotate_left, int rotate_right)
{
	keys[0] = forward;
	keys[1] = backward;
	keys[2] = rotate_left;
	keys[3] = rotate_right;
}

Mat4f SimpleWalkingCamera::get_view_matrix()
{
	return Mat4f::lookAt(position, viewpoint, up);
}

Vec3f SimpleWalkingCamera::get_normalized_view_vector()
{
	return Vec3f::normalize(viewpoint - position);
}

void SimpleWalkingCamera::move(float distance)
{
	Vec3f offset = get_normalized_view_vector();
	offset *= distance;
	position += offset;
	viewpoint += offset;
}

void SimpleWalkingCamera::rotate(float deg)
{
	auto rotation_matrix = Mat4f::rotate(Mat4f::eye(1.0f), radians(deg), { 0.0f, 1.0f, 0.0f });
	auto rotated_view_vector = rotation_matrix * Vec4f(get_normalized_view_vector(), 0.0f);
	viewpoint = position + rotated_view_vector.xyz();
}

void SimpleWalkingCamera::update(const function<bool(int)> &key_input, const function<float(float)> &speed_correction)
{
	if (key_input(keys[0]))
		move(speed_correction(move_speed));

	if (key_input(keys[1]))
		move(-speed_correction(move_speed));

	if (key_input(keys[2]))
		rotate(speed_correction(rotation_speed));

	if (key_input(keys[3]))
		rotate(-speed_correction(rotation_speed));
}
