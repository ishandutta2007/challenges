#ifndef _UTIL_H_
#define _UTIL_H_

const double infinity = numeric_limits<double>::infinity();
const double pi = 3.1415926535897932385;

inline double deg2rad(double degrees)
{
	return degrees * pi / 180.0;
}

inline void get_color(color pixel_color, int samples_per_pixel, double gamma, uint8_t rgb[3])
{
	auto r = pixel_color.x;
	auto g = pixel_color.y;
	auto b = pixel_color.z;

	// Divide the color by the number of samples.
	auto scale = 1.0 / samples_per_pixel;
	r *= scale;
	g *= scale;
	b *= scale;
	r = pow(r, 1.0 / gamma);
	g = pow(g, 1.0 / gamma);
	b = pow(b, 1.0 / gamma);

	// Write the translated [0,255] value of each color component.
	rgb[0] = static_cast<uint8_t>(256 * clamp(r, 0.0, 0.999));
	rgb[1] = static_cast<uint8_t>(256 * clamp(g, 0.0, 0.999));
	rgb[2] = static_cast<uint8_t>(256 * clamp(b, 0.0, 0.999));
}

inline void write_color(FILE *fp, color pixel_color, int samples_per_pixel, double gamma)
{
	uint8_t rgb[3];

	get_color(pixel_color, samples_per_pixel, gamma, rgb);
	fprintf(fp, "%d %d %d\n", rgb[0], rgb[1], rgb[2]);
}

inline void write_image(FILE *fp, const uint8_t *pixels, int width, int height)
{
	fprintf(fp, "P3\n");
	fprintf(fp, "%d\n%d\n%d\n", width, height, 255);
	for (int y = height - 1; y >= 0; y--)
	{
		for (int x = 0; x < width; x++)
		{
			auto p = &pixels[(y * width + x) * 3];
			fprintf(fp, "%d %d %d\n", p[0], p[1], p[2]);
		}
	}
	fflush(fp);
}

inline vec3 random_vec3(double min = 0.0, double max = 1.0)
{
	return vec3(random_double(min, max), random_double(min, max), random_double(min, max));
}

inline vec3 random_in_unit_sphere()
{
	while (true)
	{
		auto p = random_vec3(-1, 1);
		if (dot(p, p) >= 1)
			continue;
		return p;
	}
}

inline vec3 random_unit_vector()
{
	return normalize(random_in_unit_sphere());
}

inline vec3 random_in_hemisphere(const vec3 &normal)
{
	vec3 in_unit_sphere = random_in_unit_sphere();
	if (dot(in_unit_sphere, normal) > 0.0) // In the same hemisphere as the normal
		return in_unit_sphere;
	else
		return -in_unit_sphere;
}

inline vec3 random_in_unit_disk()
{
	while (true)
	{
		auto p = vec3(random_double(-1, 1), random_double(-1, 1), 0);
		if (dot(p, p) >= 1)
			continue;
		return p;
	}
}

#endif