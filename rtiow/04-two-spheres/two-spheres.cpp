#include "lib.h"

color ray_color(const ray &r, const hittable &world)
{
	hit_record rec;
	if (world.hit(r, 0, infinity, rec))
	{
		return 0.5 * (rec.normal + color(1, 1, 1));
	}
	vec3 unit_direction = normalize(r.direction);
	auto t = 0.5 * (unit_direction.y + 1.0);
	return (1.0 - t) * color(1.0, 1.0, 1.0) + t * color(0.5, 0.7, 1.0);
}

void render(int width, int height)
{
	hittable_list world;
	world.add(make_shared<sphere>(point3(0, 0, -1), 0.5, nullptr));
	world.add(make_shared<sphere>(point3(0, -100.5, -1), 100, nullptr));

	auto aspect = width * 1.0 / height;
	auto viewport_height = 2.0;
	auto viewport_width = aspect * viewport_height;
	auto focal_length = 1.0;

	auto origin = point3(0);
	auto horizontal = vec3(viewport_width, 0, 0);
	auto vertical = vec3(0, viewport_height, 0);
	auto lower_left_corner = origin - horizontal / 2 - vertical / 2 - vec3(0, 0, focal_length);

	printf("P3\n");
	printf("%d\n%d\n%d\n", width, height, 255);
	for (int y = height - 1; y >= 0; y--)
	{
		fprintf(stderr, "Scanlines remaining: %d\n", y + 1);
		for (int x = 0; x < width; x++)
		{
			auto u = x * 1.0 / (width - 1);
			auto v = y * 1.0 / (height - 1);
			ray r(origin, lower_left_corner + u * horizontal + v * vertical);
			color col = ray_color(r, world);
			write_color(stdout, col, 1, 1);
		}
	}
}

int main()
{
	render(1024, 576);
	return 0;
}