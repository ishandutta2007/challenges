#define _GNU_SOURCE
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <getopt.h>
#include <cairo.h>

typedef struct {
	float x, y;
} Vec2;

typedef struct {
	int frames;
	int size;
} Option;

float
lerp(float t, float a, float b)
{
	return a + t * (b - a);
}

float
unlerp(float t, float a, float b)
{
	return (t - a) / (b - a);
}

float
linear_remap(float x, float a, float b, float c, float d)
{
	return lerp(unlerp(x, a, b), c, d);
}

void *
xcalloc(size_t size, size_t nmemb)
{
	void *p;

	if (size == 0)
		size = 1;
	if (nmemb == 0)
		nmemb = 1;
	p = calloc(size, nmemb);
	if (!p)
		abort();
	return p;
}

void
usage(Option *o)
{
	fprintf(stderr, "usage: [options]\n");
	fprintf(stderr, "\t-f\tnumber of frames (default: %d)\n", o->frames);
	fprintf(stderr, "\t-h\tshow this message\n");
	fprintf(stderr, "\t-s\tsize of images (default: %d)\n", o->size);
	exit(2);
}

void
parseopt(Option *o, int *argc, char ***argv)
{
	int c;

	o->size = 512;
	o->frames = 120;
	while ((c = getopt(*argc, *argv, "f:hs:")) != -1) {
		switch (c) {
		case 'f':
			o->frames = atoi(optarg);
			break;
		case 'h':
			usage(o);
			break;
		case 's':
			o->size = atoi(optarg);
			break;
		}
	}
	*argc -= optind;
	*argv += optind;

	if (o->size <= 0 || o->frames <= 0) {
		fprintf(stderr, "invalid option specified\n");
		exit(1);
	}
}

void
render(cairo_t *cr, int width, int height, float percent, Vec2 *points, size_t npoints)
{
	Vec2 v;
	float a, r;
	size_t n;

	cairo_set_source_rgb(cr, 0, 0, 0);
	cairo_paint(cr);

	cairo_identity_matrix(cr);
	cairo_translate(cr, width / 2.0, height / 2.0);

	cairo_set_source_rgb(cr, 1, 1, 1);
	cairo_set_line_width(cr, 4);

	for (n = 0; n < npoints; n++) {
		a = linear_remap(percent, 0, 1, 0, 2 * M_PI);
		r = linear_remap(sin(a), -1, 1, height / 80.0, height / 40.0);
		v = points[n];
		cairo_line_to(cr, r * v.x, r * v.y);
	}
	cairo_stroke_preserve(cr);

	cairo_set_source_rgb(cr, 0.58, 0, 0.39);
	cairo_fill(cr);
}

void
update(float percent, Vec2 **points, size_t *npoints)
{
	float a;
	Vec2 v;

	if (percent < 0.5) {
		a = linear_remap(percent, 0, 0.5, 0, 2 * M_PI);
		v.x = 16 * pow(sin(a), 3);
		v.y = -(13 * cos(a) - 5 * cos(2 * a) - 2 * cos(3 * a) - cos(4 * a));

		(*points)[*npoints] = v;
		*npoints += 1;
	} else {
		*points += 1;
		*npoints -= 1;
	}
}

void
animate(int width, int height, int frames)
{
	cairo_surface_t *surface;
	cairo_t *cr;

	Vec2 *heart;
	Vec2 *points;
	size_t npoints;

	char name[128];
	float percent;
	int pad;
	int i;

	heart = xcalloc(frames, sizeof(*heart));
	points = heart;
	npoints = 0;

	surface = cairo_image_surface_create(CAIRO_FORMAT_ARGB32, width, height);
	cr = cairo_create(surface);

	pad = ceil(log10(frames));

	for (i = 0; i < frames; i++) {
		percent = (i * 1.0) / frames;
		render(cr, width, height, percent, points, npoints);
		update(percent, &points, &npoints);

		snprintf(name, sizeof(name), "frame-%0*d.png", pad, i);
		cairo_surface_write_to_png(surface, name);
	}

	cairo_surface_destroy(surface);
	cairo_destroy(cr);
	free(heart);
}

int
main(int argc, char *argv[])
{
	Option opt;

	parseopt(&opt, &argc, &argv);
	animate(opt.size, opt.size, opt.frames);

	return 0;
}
