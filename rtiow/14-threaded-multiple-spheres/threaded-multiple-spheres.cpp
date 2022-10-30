#include "lib.h"

hittable_list random_scene()
{
	hittable_list world;

	auto ground_material = make_shared<lambertian>(color(0.5, 0.5, 0.5));
	world.add(make_shared<sphere>(point3(0, -1000, 0), 1000, ground_material));

	for (int a = -11; a < 11; a++)
	{
		for (int b = -11; b < 11; b++)
		{
			auto choose_mat = random_double();
			point3 center(a + 0.9 * random_double(), 0.2, b + 0.9 * random_double());

			if (length(center - point3(4, 0.2, 0)) > 0.9)
			{
				shared_ptr<material> sphere_material;

				if (choose_mat < 0.8)
				{
					// diffuse
					auto albedo = random_vec3() * random_vec3();
					sphere_material = make_shared<lambertian>(albedo);
					world.add(make_shared<sphere>(center, 0.2, sphere_material));
				}
				else if (choose_mat < 0.95)
				{
					// metal
					auto albedo = random_vec3(0.5, 1);
					auto fuzz = random_double(0, 0.5);
					sphere_material = make_shared<metal>(albedo, fuzz);
					world.add(make_shared<sphere>(center, 0.2, sphere_material));
				}
				else
				{
					// glass
					sphere_material = make_shared<dielectric>(1.5);
					world.add(make_shared<sphere>(center, 0.2, sphere_material));
				}
			}
		}
	}

	auto material1 = make_shared<dielectric>(1.5);
	world.add(make_shared<sphere>(point3(0, 1, 0), 1.0, material1));

	auto material2 = make_shared<lambertian>(color(0.4, 0.2, 0.1));
	world.add(make_shared<sphere>(point3(-4, 1, 0), 1.0, material2));

	auto material3 = make_shared<metal>(color(0.7, 0.6, 0.5), 0.0);
	world.add(make_shared<sphere>(point3(4, 1, 0), 1.0, material3));

	return world;
}

color ray_color(const ray &r, const hittable &world, int depth)
{
	hit_record rec;

	// If we've exceeded the ray bounce limit, no more light is gathered.
	if (depth <= 0)
		return color(0, 0, 0);

	if (world.hit(r, 0.001, infinity, rec))
	{
		ray scattered;
		color attenuation;
		if (rec.mat_ptr->scatter(r, rec, attenuation, scattered))
			return attenuation * ray_color(scattered, world, depth - 1);
		return color(0, 0, 0);
	}

	vec3 unit_direction = normalize(r.direction);
	auto t = 0.5 * (unit_direction.y + 1.0);
	return (1.0 - t) * color(1.0, 1.0, 1.0) + t * color(0.5, 0.7, 1.0);
}

struct workdata
{
	camera &cam;
	hittable_list &world;

	int width;
	int height;
	int samples_per_pixel;

	atomic<int> scanline;
	uint8_t *pixels;
};

void render_scanline(uint8_t *pixels, int y, int width, int height, int samples_per_pixel, camera &cam, hittable_list &world)
{
	auto p = &pixels[(y * width) * 3];
	for (int x = 0; x < width; x++)
	{
		color pixel_color(0, 0, 0);
		for (int s = 0; s < samples_per_pixel; s++)
		{
			auto u = (x + random_double()) / (width - 1);
			auto v = (y + random_double()) / (height - 1);
			ray r = cam.get_ray(u, v);
			pixel_color += ray_color(r, world, 50);
		}
		get_color(pixel_color, samples_per_pixel, 2.0, p);
		p += 3;
	}
}

void worker(workdata *wd)
{
	seed_rng();

	for (;;)
	{
		int scanline = wd->scanline++;
		if (scanline >= wd->height)
			break;

		render_scanline(wd->pixels, scanline, wd->width, wd->height, wd->samples_per_pixel, wd->cam, wd->world);
		fprintf(stderr, "Scanline %d finished\n", scanline);
	}
}

void render(int width, int height, int samples_per_pixel, int nthreads)
{
	auto world = random_scene();

	point3 lookfrom(13, 2, 3);
	point3 lookat(0, 0, 0);
	vec3 vup(0, 1, 0);
	auto dist_to_focus = 10.0;
	auto aperture = 0.1;

	camera cam(width, height, 20, lookfrom, lookat, vup, aperture, dist_to_focus);
	workdata wd = { cam, world, width, height, samples_per_pixel, 0, new uint8_t[width * height * 3] };

	vector<thread> th;
	for (int i = 0; i < nthreads; i++)
		th.push_back(thread(worker, &wd));
	for (int i = 0; i < nthreads; i++)
		th[i].join();

	write_image(stdout, wd.pixels, width, height);
	delete[] wd.pixels;
}

int main()
{
	seed_rng();
	render(1200, 800, 500, 16);
	return 0;
}
