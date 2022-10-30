#ifndef _FLYING_CAMERA_H_
#define _FLYING_CAMERA_H_

class FlyingCamera
{
public:
	void init(Vec3f position, Vec3f viewpoint, Vec3f up, float move_speed = 80.0f, float mouse_sensitivity = 0.15f);
	void set_controls(int forward, int backward, int strafe_left, int strafe_right);

	void move(float distance);
	void strafe(float distance);
	void rotate_left_right(float degrees);
	void rotate_up_down(float degrees);
	void update(const function<bool(int)> &key_input,
				const function<Vec2i()> &get_cursor_pos,
				const function<void(Vec2i &)> &set_cursor_pos,
				const function<float(float)> &speed_correction);

	Vec3f get_normalized_view_vector();
	Mat4f get_view_matrix();

	Vec3f position; // camera position (eye position)
	Vec3f viewpoint; // viewpoint - where does the camera look to
	Vec3f up; // up vector of camera

	Vec2i window_center_position; // center of the window (to restore cursor position every frame to)

	float mouse_sensitivity; // mouse sensitivity per pixel
	float move_speed; // how fast to move camera forwards and backwards
	int keys[4]; // keybindings for moving camera
};

#endif