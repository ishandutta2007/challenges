#define _GNU_SOURCE
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdarg.h>
#include <math.h>
#include <errno.h>
#include <getopt.h>
#include <cairo.h>

#define nelem(x) (sizeof(x) / sizeof(x[0]))
#define deg2rad(x) ((x)*M_PI / 180)

typedef struct {
	int width;
	int height;
	float linewidth;
	char output[512];
} Flags;

typedef struct {
	cairo_surface_t *surface;
	cairo_t *cr;

	float x, y;
	float lw;
	float dir;
	int pen;
} Turtle;

Flags flags = {
    .width = 640,
    .height = 480,
    .linewidth = 2,
    .output = "logo.png",
};

void
fatal(const char *fmt, ...)
{
	va_list ap;

	va_start(ap, fmt);
	vfprintf(stderr, fmt, ap);
	va_end(ap);
	fprintf(stderr, "\n");
	exit(1);
}

void
usage(void)
{
	fprintf(stderr, "usage: [options] code.txt\n");
	fprintf(stderr, "\t-w\tcanvas width (default: %d)\n", flags.width);
	fprintf(stderr, "\t-h\tcanvas height (default: %d)\n", flags.height);
	fprintf(stderr, "\t-l\tline width (default: %.2f)\n", flags.linewidth);
	fprintf(stderr, "\t-o\toutput to file (default: %s)\n", flags.output);
	exit(2);
}

void
parseflags(int *argc, char ***argv)
{
	int c;

	while ((c = getopt(*argc, *argv, "h:l:o:w:")) != -1) {
		switch (c) {
		case 'h':
			flags.height = atoi(optarg);
			break;
		case 'l':
			flags.linewidth = atof(optarg);
			break;
		case 'o':
			snprintf(flags.output, sizeof(flags.output), "%s", optarg);
			break;
		case 'w':
			flags.width = atoi(optarg);
			break;
		}
	}

	*argc -= optind;
	*argv += optind;

	if (*argc < 1)
		usage();

	if (flags.width <= 0 || flags.height <= 0)
		fatal("invalid canvas dimension %dx%d\n", flags.width, flags.height);
}

void
alloc(Turtle *turtle, int width, int height, float dir, float linewidth)
{
	turtle->surface = cairo_image_surface_create(CAIRO_FORMAT_ARGB32, width, height);
	turtle->cr = cairo_create(turtle->surface);
	turtle->x = width * 0.5;
	turtle->y = height * 0.5;
	turtle->dir = dir;
	turtle->lw = linewidth;
}

void
destroy(Turtle *turtle)
{
	cairo_surface_destroy(turtle->surface);
	cairo_destroy(turtle->cr);
}

void
reset(Turtle *turtle)
{
	cairo_t *cr;

	cr = turtle->cr;
	cairo_set_source_rgb(cr, 0, 0, 0);
	cairo_paint(cr);
	cairo_identity_matrix(cr);
	cairo_translate(cr, turtle->x, turtle->y);
	cairo_move_to(cr, 0, 0);
	cairo_rotate(cr, turtle->dir);
	turtle->pen = 1;
}

int
decode(FILE *fp, int *op, float *val)
{
	static const struct {
		int op;
		int args;
		const char *cmd;
	} xec[] = {
	    {'f', 1, "fd"},
	    {'b', 1, "bd"},
	    {'r', 1, "rt"},
	    {'l', 1, "lt"},
	    {'u', 0, "pu"},
	    {'d', 0, "pd"},
	    {'w', 1, "lw"},
	};

	char cmd[8];
	size_t i;

	*op = 0;
	*val = 0;
	if (fscanf(fp, "%7s", cmd) != 1)
		return 0;

	for (i = 0; i < nelem(xec); i++) {
		if (!strcmp(cmd, xec[i].cmd)) {
			*op = xec[i].op;
			if (xec[i].args)
				fscanf(fp, "%f", val);

			return 1;
		}
	}
	return 0;
}

void
forward(Turtle *turtle, float val)
{
	cairo_t *cr;

	cr = turtle->cr;
	if (turtle->pen) {
		cairo_set_source_rgb(cr, 1, 1, 1);
		cairo_set_line_width(cr, turtle->lw);
		cairo_line_to(cr, val, 0);
		cairo_stroke(cr);
	}
	cairo_move_to(cr, val, 0);
	cairo_translate(cr, val, 0);
}

void
turn(Turtle *turtle, float angle)
{
	cairo_rotate(turtle->cr, angle);
}

void
interpret(Turtle *turtle, int op, float val)
{
	switch (op) {
	case 'f':
		forward(turtle, val);
		break;
	case 'b':
		forward(turtle, -val);
		break;
	case 'r':
		turn(turtle, deg2rad(val));
		break;
	case 'l':
		turn(turtle, deg2rad(val));
		break;
	case 'u':
		turtle->pen = 0;
		break;
	case 'd':
		turtle->pen = 1;
		break;
	case 'w':
		turtle->lw = val;
		break;
	}
}

void
run(Turtle *turtle, const char *name)
{
	FILE *fp;
	int op;
	float val;

	fp = fopen(name, "rb");
	if (!fp)
		fatal("Failed to open file %s: %s", strerror(errno));

	for (;;) {
		if (!decode(fp, &op, &val))
			break;
		interpret(turtle, op, val);
	}

	fclose(fp);
}

int
main(int argc, char *argv[])
{
	Turtle turtle[1];

	parseflags(&argc, &argv);
	alloc(turtle, flags.width, flags.height, 0, flags.linewidth);
	reset(turtle);
	run(turtle, argv[0]);
	cairo_surface_write_to_png(turtle->surface, flags.output);
	destroy(turtle);

	return 0;
}
