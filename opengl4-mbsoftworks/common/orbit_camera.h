#ifndef _ORBIT_CAMERA_H_
#define _ORBIT_CAMERA_H_

class OrbitCamera
{
public:
	void init(Vec3f center, Vec3f up, float radius, float min_radius, float polar, float azimuth);
	void rotate_polar(float rad);
	void rotate_azimuth(float rad);
	void zoom(float speed);
	void move_horizontal(float speed);
	void move_vertical(float speed);

	Mat4f get_view_matrix();

	Vec3f get_eye();

	Vec3f get_viewpoint();
	Vec3f get_normalized_view_vector();

	Vec3f center; // Center of the orbit camera sphere (the point upon which the camera looks)
	Vec3f up; // Up vector of the camera
	float radius; // Radius of the orbit camera sphere
	float min_radius; // Minimal radius of the orbit camera sphere (cannot fall below this value)
	float polar; // Polar angle on the orbit camera sphere
	float azimuth; // Azimuth angle on the orbit camera sphere
};

#endif