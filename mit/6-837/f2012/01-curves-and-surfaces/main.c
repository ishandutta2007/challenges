#include "lib.h"

typedef struct {
	float3 position;
	float3 normal;
	float3 color;
} Vertex;

typedef struct {
	Geometry geometry;
	const char *geometry_file;
	int curve_mode;
} UC;

void
usage(void)
{
	fprintf(stderr, "usage: geometry.swp\n");
	exit(2);
}

static void
get_axis_vertices(Vertex *v)
{
	static const Vertex tab[] = {
	    {{{0, 0, 0}}, {{0, 0, 0}}, {{1, 0, 0}}},
	    {{{1, 0, 0}}, {{0, 0, 0}}, {{1, 0, 0}}},

	    {{{0, 0, 0}}, {{0, 0, 0}}, {{0, 1, 0}}},
	    {{{0, 1, 0}}, {{0, 0, 0}}, {{0, 1, 0}}},

	    {{{0, 0, 0}}, {{0, 0, 0}}, {{0, 0, 1}}},
	    {{{0, 0, 1}}, {{0, 0, 0}}, {{0, 0, 1}}},

	    {{{0, 0, 0}}, {{0, 0, 0}}, {{0.5, 0.5, 0.5}}},
	    {{{-1, 0, 0}}, {{0, 0, 0}}, {{0.5, 0.5, 0.5}}},

	    {{{0, 0, 0}}, {{0, 0, 0}}, {{0.5, 0.5, 0.5}}},
	    {{{0, -1, 0}}, {{0, 0, 0}}, {{0.5, 0.5, 0.5}}},

	    {{{0, 0, 0}}, {{0, 0, 0}}, {{0.5, 0.5, 0.5}}},
	    {{{0, 0, -1}}, {{0, 0, 0}}, {{0.5, 0.5, 0.5}}},
	};
	memcpy(v, tab, sizeof(tab));
}

void
draw_axes(Camera *cam)
{
	Vertex verts[12];
	float4x4 s, t, tf;

	scale4x3(s, (float3){{5, 5, 5}});
	translate4x3(t, scale3(cam->center, 1));
	mul4x4(tf, t, s);
	get_axis_vertices(verts);

	glLineWidth(5);
	glUniformMatrix4fv(0, 1, GL_TRUE, &tf[0][0]);
	glBufferSubData(GL_ARRAY_BUFFER, 0, sizeof(verts), verts);
	glDrawArrays(GL_LINES, 0, 2 * 6);
}

void
draw_control_points(float3 *cps, size_t cpslen)
{
	Vertex v;
	size_t i, off;
	float4x4 tf;

	off = 0;
	v.normal = (float3){{1, 1, 1}};
	v.color = (float3){{1, 1, 0}};
	for (i = 0; i < cpslen; i++) {
		v.position = cps[i];
		glBufferSubData(GL_ARRAY_BUFFER, off, sizeof(v), &v);
		off += sizeof(v);
	}
	eye4x4(tf);

	glPointSize(4);
	glLineWidth(1);
	glUniformMatrix4fv(0, 1, GL_TRUE, &tf[0][0]);
	glDrawArrays(GL_POINTS, 0, cpslen);
	glDrawArrays(GL_LINE_STRIP, 0, cpslen);
}

void
draw_curves(Curve *c, float framesize)
{
	Vertex v, verts[12];
	float4x4 tf, s, m;
	size_t i, off;

	glLineWidth(1);
	off = 0;
	v.normal = (float3){{1, 1, 1}};
	v.color = (float3){{1, 1, 1}};
	for (i = 0; i < c->npoints; i++) {
		v.position = c->vertices[i];
		glBufferSubData(GL_ARRAY_BUFFER, off, sizeof(v), &v);
		off += sizeof(v);
	}
	eye4x4(tf);
	glUniformMatrix4fv(0, 1, GL_TRUE, &tf[0][0]);
	glDrawArrays(GL_LINE_STRIP, 0, c->npoints);

	if (framesize == 0.0)
		return;

	get_axis_vertices(verts);
	glBufferSubData(GL_ARRAY_BUFFER, 0, sizeof(verts), verts);

	for (i = 0; i < c->npoints; i++) {
		setcol4x4(m, 0, xyzw3(c->normals[i], 0));
		setcol4x4(m, 1, xyzw3(c->binormals[i], 0));
		setcol4x4(m, 2, xyzw3(c->tangents[i], 0));
		setcol4x4(m, 3, xyzw3(c->vertices[i], 1));

		scale4x3(s, (float3){{framesize, framesize, framesize}});
		mul4x4(tf, m, s);

		glUniformMatrix4fv(0, 1, GL_TRUE, &tf[0][0]);
		glDrawArrays(GL_LINES, 0, 2 * 3);
	}
}

void
draw_geometry(UC *uc, Geometry *geo)
{
	size_t i;

	for (i = 0; i < geo->ncurves; i++) {
		if (uc->curve_mode == 1)
			draw_curves(&geo->curves[i], 0);
		else if (uc->curve_mode == 2)
			draw_curves(&geo->curves[i], 0.1);
	}

	for (i = 0; i < geo->ncps; i++)
		draw_control_points(geo->cps[i], geo->cpslen[i]);
}

void
begin(GC *gc)
{
	Geometry *geo;
	UC *uc;
	int err, rv;
	size_t i;

	uc = gc->opaque;
	geo = &uc->geometry;
	if ((rv = load_swp(&uc->geometry, uc->geometry_file)) < 0)
		fatal("Failed to load geometry file: %s", strerror(-rv));

	printf("%zu cps %zu curves %zu surfaces\n", geo->ncps, geo->ncurves, geo->nsurfaces);
	for (i = 0; i < geo->ncps; i++)
		printf("cps #%zu %zu\n", i, geo->cpslen[i]);
	for (i = 0; i < geo->ncurves; i++)
		printf("curves #%zu %zu\n", i, geo->curves[i].npoints);

	glBindVertexArray(gc->vao);
	glBindBuffer(GL_ARRAY_BUFFER, gc->vbo);
	glBufferData(GL_ARRAY_BUFFER, geo->total_size + 1024, NULL, GL_STATIC_DRAW);

	glEnableVertexAttribArray(0);
	glEnableVertexAttribArray(1);
	glEnableVertexAttribArray(2);
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, sizeof(Vertex), (void *)offsetof(Vertex, position));
	glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, sizeof(Vertex), (void *)offsetof(Vertex, normal));
	glVertexAttribPointer(2, 3, GL_FLOAT, GL_FALSE, sizeof(Vertex), (void *)offsetof(Vertex, color));

	glClearColor(0.3, 0.4, 0.5, 1);
	glEnable(GL_DEPTH_TEST);
	err = glGetError();
	if (err)
		printf("GL Error: %d\n", err);

	uc->curve_mode = 1;
}

void
event(GC *gc, SDL_Event *ev)
{
	UC *uc;

	uc = gc->opaque;
	switch (ev->type) {
	case SDL_KEYDOWN:
		switch (ev->key.keysym.sym) {
		case SDLK_c:
			uc->curve_mode = (uc->curve_mode + 1) % 3;
			break;
		}
		break;
	}
}

void
update_and_render(GC *gc)
{
	Camera *cam;
	UC *uc;

	uc = gc->opaque;
	cam = &gc->camera;

	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glUseProgram(gc->program[0]);
	glBindVertexArray(gc->vao);

	camera_matrix(cam, gc->modelview);
	glUniformMatrix4fv(1, 1, GL_TRUE, &gc->modelview[0][0]);
	glUniformMatrix4fv(2, 1, GL_TRUE, &gc->projection[0][0]);
	draw_geometry(uc, &uc->geometry);

	if (gc->picking)
		draw_axes(cam);
}

void
cleanup(GC *gc)
{
	UC *uc;

	uc = gc->opaque;
	free_geometry(&uc->geometry);
}

UC uc;
GC gc = {
    .title = "Curves and Surfaces Viewer",
    .width = 1024,
    .height = 768,
    .begin = begin,
    .event = event,
    .update_and_render = update_and_render,
    .cleanup = cleanup,
    .shader_files = {
        "data/shaders/curves_and_surfaces_vs.glsl",
        "data/shaders/curves_and_surfaces_fs.glsl",
    },
    .shader_links = {
        {0, 1, -1},
        {-1},
    },
    .opaque = &uc,
};

int
main(int argc, char *argv[])
{
	if (argc < 2)
		usage();
	uc.geometry_file = argv[1];
	run(&gc);
	return 0;
}
