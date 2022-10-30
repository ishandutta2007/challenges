#include "lib.h"

void FlyingCamera::init(Vec3f position, Vec3f viewpoint, Vec3f up, float move_speed, float mouse_sensitivity)
{
	this->position = position;
	this->viewpoint = viewpoint;
	this->up = up;
	this->move_speed = move_speed;
	this->mouse_sensitivity = mouse_sensitivity;
	set_controls(SDLK_w, SDLK_s, SDLK_a, SDLK_d);
}

void FlyingCamera::set_controls(int forward, int backward, int strafe_left, int strafe_right)
{
	keys[0] = forward;
	keys[1] = backward;
	keys[2] = strafe_left;
	keys[3] = strafe_right;
}

Vec3f FlyingCamera::get_normalized_view_vector()
{
	return Vec3f::normalize(viewpoint - position);
}

Mat4f FlyingCamera::get_view_matrix()
{
	return Mat4f::lookAt(position, viewpoint, up);
}

void FlyingCamera::move(float distance)
{
	auto offset = get_normalized_view_vector();
	offset *= distance;
	position += offset;
	viewpoint += offset;
}

void FlyingCamera::strafe(float distance)
{
	auto view_vector = get_normalized_view_vector();
	auto strafe_vector = Vec3f::normalize(Vec3f::cross(view_vector, up));
	strafe_vector *= distance;

	position += strafe_vector;
	viewpoint += strafe_vector;
}

void FlyingCamera::rotate_left_right(float deg)
{
	auto rotation_matrix = Mat4f::rotate(Mat4f::eye(1.0f), radians(deg), { 0.0f, 1.0f, 0.0f });
	auto rotated_view_vector = rotation_matrix * Vec4f(get_normalized_view_vector(), 0.0f);
	viewpoint = position + rotated_view_vector.xyz();
}

void FlyingCamera::rotate_up_down(float deg)
{
	auto view_vector = get_normalized_view_vector();
	auto view_vector_no_y = Vec3f::normalize({ view_vector.x, 0.0f, view_vector.z });

	float current_angle_degrees = degrees(acos(Vec3f::dot(view_vector_no_y, view_vector)));
	if (view_vector.y < 0.0f)
		current_angle_degrees = -current_angle_degrees;

	float new_angle_degrees = current_angle_degrees + deg;
	if (new_angle_degrees > -85.0f && new_angle_degrees < 85.0f)
	{
		auto view_vector = get_normalized_view_vector();
		auto rotation_axis = Vec3f::cross(view_vector, up);
		rotation_axis = Vec3f::normalize(rotation_axis);

		auto rotation_matrix = Mat4f::rotate(Mat4f::eye(1.0f), radians(deg), rotation_axis);
		auto rotated_view_vector = rotation_matrix * Vec4f(view_vector, 0.0f);

		viewpoint = position + rotated_view_vector.xyz();
	}
}

void FlyingCamera::update(const function<bool(int)> &key_input,
						  const function<Vec2i()> &get_cursor_pos,
						  const function<void(Vec2i &)> &set_cursor_pos,
						  const function<float(float)> &speed_correction)
{
	if (key_input(keys[0]))
		move(speed_correction(move_speed));

	if (key_input(keys[1]))
		move(-speed_correction(move_speed));

	if (key_input(keys[2]))
		strafe(-speed_correction(move_speed));

	if (key_input(keys[3]))
		strafe(speed_correction(move_speed));

	auto current_mouse_position = get_cursor_pos();
	auto delta = window_center_position - current_mouse_position;

	if (delta.x != 0)
		rotate_left_right(float(delta.x) * mouse_sensitivity);

	if (delta.y != 0)
		rotate_up_down(float(delta.y) * mouse_sensitivity);

	set_cursor_pos(window_center_position);
}
