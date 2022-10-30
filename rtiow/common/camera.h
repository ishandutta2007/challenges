#ifndef _CAMERA_H_
#define _CAMERA_H_

struct camera
{
	camera(int width, int height)
		: camera(width, height, 90)
	{
	}

	camera(int width, int height, double fovy)
		: camera(width, height, fovy, point3(0, 0, 0), point3(0, 0, -1), vec3(0, 1, 0))
	{
	}

	camera(int width, int height, double fovy, point3 lookfrom, point3 lookat, vec3 vup)
		: camera(width, height, fovy, lookfrom, lookat, vup, 0, 1)
	{
	}

	camera(int width, int height, double fovy, point3 lookfrom, point3 lookat, vec3 vup, double aperture, double focus_dist)
	{
		auto theta = deg2rad(fovy);
		auto h = tan(theta / 2);
		auto aspect_ratio = width * 1.0 / height;
		auto viewport_height = 2.0 * h;
		auto viewport_width = aspect_ratio * viewport_height;

		w = normalize(lookfrom - lookat);
		u = normalize(cross(vup, w));
		v = normalize(cross(w, u));

		origin = lookfrom;
		horizontal = focus_dist * viewport_width * u;
		vertical = focus_dist * viewport_height * v;
		lower_left_corner = origin - horizontal / 2 - vertical / 2 - focus_dist * w;

		lens_radius = aperture / 2;
	}

	ray get_ray(double s, double t) const
	{
		vec3 rd = lens_radius * random_in_unit_disk();
		vec3 offset = u * rd.x + v * rd.y;

		return ray(
			origin + offset,
			lower_left_corner + s * horizontal + t * vertical - origin - offset);
	}

	point3 origin;
	point3 lower_left_corner;
	vec3 horizontal;
	vec3 vertical;
	vec3 u, v, w;
	double lens_radius;
};

#endif