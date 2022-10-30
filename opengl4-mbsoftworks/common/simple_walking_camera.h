#ifndef _SIMPLE_WALKING_CAMERA_H_
#define _SIMPLE_WALKING_CAMERA_H_

class SimpleWalkingCamera
{
public:
	void init(Vec3f position, Vec3f viewpoint, Vec3f up, float move_speed = 50.0f, float rotation_speed = 135.0f);
	void set_controls(int forward, int backward, int rotate_left, int rotate_right);

	Mat4f get_view_matrix();
	Vec3f get_normalized_view_vector();
	void move(float distance);
	void rotate(float degrees);

	void update(const function<bool(int)> &key_input_fn, const function<float(float)> &speed_correction_fn);

	Vec3f position;
	Vec3f viewpoint;
	Vec3f up;

	float move_speed;
	float rotation_speed;
	int keys[4];
};

#endif