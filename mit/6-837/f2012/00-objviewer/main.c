#include "lib.h"

typedef struct {
	const char *model_file;
	Model model;
	float4 last_color;
	float4 color;
} UC;

static size_t
gen_axes(void *buf)
{
	static const float4 axes[] = {
	    {{0, 0, 0, 1}},
	    {{1, 0, 0, 1}},
	    {{0, 1, 0, 1}},
	    {{0, 0, 1, 1}},
	    {{-1, 0, 0, 1}},
	    {{0, -1, 0, 1}},
	    {{0, 0, -1, 1}},
	};
	static const float4 nrm = {{1, 1, 1, 1}};

	char *s, *p;
	size_t i;

	s = p = buf;
	for (i = 1; i < nelem(axes); i++) {
		memcpy(p, &axes[0], sizeof(axes[0]));
		p += sizeof(axes[0]);

		memcpy(p, &nrm, sizeof(nrm));
		p += sizeof(nrm);

		memcpy(p, &axes[i], sizeof(axes[i]));
		p += sizeof(axes[i]);

		memcpy(p, &nrm, sizeof(nrm));
		p += sizeof(nrm);
	}
	return p - s;
}

void
usage(void)
{
	fprintf(stderr, "usage: model.obj\n");
	exit(2);
}

void
begin(GC *gc)
{
	Model *md;
	UC *uc;
	char *data;
	size_t i, j, len, off, stride;
	int err, rv;
	float4 *vtx, *nrm;

	uc = gc->opaque;
	md = &uc->model;
	if ((rv = load_obj(md, uc->model_file)) < 0)
		fatal("Failed to load model %s: %s", uc->model_file, strerror(-rv));

	printf("Model Statistics\n");
	printf("v %zu vt %zu vn %zu f %zu\n", md->nvertices, md->ntexcoords, md->nnormals, md->nfaces);
	printf("b [%.6f %.6f %.6f] [%.6f %.6f %.6f]\n",
	       md->extents.min.x, md->extents.min.y, md->extents.min.z,
	       md->extents.max.x, md->extents.max.y, md->extents.max.z);

	stride = 2 * sizeof(float4);
	len = md->nfaces * 6 * sizeof(float4);
	len += 64 * sizeof(float4);
	data = xcalloc(1, len);

	off = 0;
	for (i = 0; i < md->nfaces; i++) {
		for (j = 0; j < 3; j++) {
			vtx = &md->vertices[md->faces[9 * i + j]];
			memcpy(data + off, vtx, sizeof(*vtx));
			off += sizeof(*vtx);

			nrm = &md->normals[md->faces[9 * i + 6 + j]];
			memcpy(data + off, nrm, sizeof(*nrm));
			off += sizeof(*nrm);
		}
	}
	off += gen_axes(data + off);

	glBindVertexArray(gc->vao);
	glBindBuffer(GL_ARRAY_BUFFER, gc->vbo);
	glBufferData(GL_ARRAY_BUFFER, len, data, GL_STATIC_DRAW);

	glEnableVertexAttribArray(0);
	glEnableVertexAttribArray(1);
	glVertexAttribPointer(0, 4, GL_FLOAT, GL_FALSE, stride, 0);
	glVertexAttribPointer(1, 4, GL_FLOAT, GL_FALSE, stride, (void *)sizeof(float4));

	glClearColor(0.3, 0.4, 0.5, 1);
	glEnable(GL_DEPTH_TEST);

	err = glGetError();
	if (err)
		printf("GL Error: %d\n", err);

	uc->color = (float4){{.2, .3, .4, 1}};
	uc->last_color = uc->color;

	free(data);
}

void
event(GC *gc, SDL_Event *ev)
{
	static const float step = 0.05;

	UC *uc;
	float4 col;

	uc = gc->opaque;
	col = uc->color;

	switch (ev->type) {
	case SDL_KEYDOWN:
		switch (ev->key.keysym.sym) {
		case SDLK_UP:
			col.r += step;
			break;

		case SDLK_DOWN:
			col.r -= step;
			break;

		case SDLK_LEFT:
			col.g -= step;
			break;

		case SDLK_RIGHT:
			col.g += step;
			break;

		case SDLK_1:
			col.b -= step;
			break;

		case SDLK_2:
			col.b += step;
			break;
		}
	}

	uc->color = saturate4(col);
}

void
render_axes(Camera *cam, int off)
{
	float4x4 s, t, tf;

	glUniform1i(4, GL_FALSE);

	glLineWidth(5);
	scale4x3(s, (float3){{5, 5, 5}});
	translate4x3(t, scale3(cam->center, 1));
	mul4x4(tf, t, s);
	glUniformMatrix4fv(0, 1, GL_TRUE, &tf[0][0]);

	glUniform4f(3, 1, 0, 0, 1);
	glDrawArrays(GL_LINES, off, 2);
	off += 2;

	glUniform4f(3, 0, 1, 0, 1);
	glDrawArrays(GL_LINES, off, 2);
	off += 2;

	glUniform4f(3, 0, 0, 1, 1);
	glDrawArrays(GL_LINES, off, 2);
	off += 2;

	glUniform4f(3, 0.5, 0.5, 0.5, 1);
	glDrawArrays(GL_LINES, off, 2 * 3);
}

void
update_and_render(GC *gc)
{
	UC *uc;
	Model *md;
	Camera *cam;
	float4x4 tf;

	uc = gc->opaque;
	md = &uc->model;
	cam = &gc->camera;

	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glUseProgram(gc->program[0]);
	glBindVertexArray(gc->vao);

	eye4x4(tf);
	camera_matrix(cam, gc->modelview);
	glUniformMatrix4fv(0, 1, GL_TRUE, &tf[0][0]);
	glUniformMatrix4fv(1, 1, GL_TRUE, &gc->modelview[0][0]);
	glUniformMatrix4fv(2, 1, GL_TRUE, &gc->projection[0][0]);

	glUniform4f(3, uc->last_color.r, uc->last_color.g, uc->last_color.b, uc->last_color.a);
	glUniform1i(4, GL_TRUE);
	glLineWidth(2);
	glDrawArrays(GL_TRIANGLES, 0, md->nfaces * 3);

	if (gc->picking)
		render_axes(cam, md->nfaces * 3);

	if (gc->pause)
		return;

	uc->last_color = lerp4(0.1, uc->last_color, uc->color);
}

void
cleanup(GC *gc)
{
	UC *uc;

	uc = gc->opaque;
	free_model(&uc->model);
}

UC uc;
GC gc = {
    .title = "Basic OBJ Viewer",
    .width = 1024,
    .height = 768,
    .begin = begin,
    .event = event,
    .update_and_render = update_and_render,
    .cleanup = cleanup,
    .shader_files = {
        "data/shaders/objviewer_vs.glsl",
        "data/shaders/objviewer_fs.glsl",
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
	uc.model_file = argv[1];
	run(&gc);
	return 0;
}
