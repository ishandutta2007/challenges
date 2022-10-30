#define GL_GLEXT_PROTOTYPES
#include <assert.h>
#include <stdint.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdarg.h>
#include <errno.h>
#include <SDL.h>
#include <SDL_opengl.h>
#include <SDL_opengl_glext.h>

#include "linalg.h"

typedef struct GC GC;

typedef struct {
	float3 center;
	float4 rotation;
	float distance;

	float3 center0;
	float4 rotation0;
	float distance0;

	float4 viewport;
	float fovy;

	float2 click;
	int button;
} Camera;

typedef struct {
	float4 min;
	float4 max;
} Extents;

struct GC {
	SDL_Window *window;
	SDL_GLContext glctx;
	int width, height;
	bool fullscreen;
	char title[256];

	char shader_files[8][256];
	int shader_links[8][8];

	GLuint shader[8];
	GLuint program[8];

	GLuint vao;
	GLuint vbo;

	bool running;
	bool vsync;
	bool pause;
	bool picking;
	int wireframe;

	Camera camera;
	float4x4 transform;
	float4x4 modelview;
	float4x4 projection;

	uint64_t last_frame_fps;
	uint64_t last_frame_time;
	double time_delta;

	int fps;
	int next_fps;

	void *opaque;
	void (*begin)(GC *);
	void (*event)(GC *, SDL_Event *);
	void (*update_and_render)(GC *);
	void (*cleanup)(GC *);
};

typedef struct {
	float4 *vertices;
	float4 *texcoords;
	float4 *normals;
	unsigned *faces;
	size_t nvertices;
	size_t ntexcoords;
	size_t nnormals;
	size_t nfaces;
	Extents extents;
} Model;

typedef struct {
	float3 *vertices;
	float3 *tangents;
	float3 *normals;
	float3 *binormals;
	size_t npoints;
} Curve;

typedef struct {
	float3 *vertices;
	float3 *normals;
	unsigned *faces;
	size_t npoints;
} Surface;

typedef struct {
	float3 **cps;
	size_t *cpslen;
	size_t ncps;

	Curve *curves;
	size_t ncurves;

	Surface *surfaces;
	size_t nsurfaces;

	size_t total_size;
} Geometry;

#define nelem(x) (sizeof(x) / sizeof(x[0]))
#define Dx(r) ((r).max.x - (r).min.x)
#define Dy(r) ((r).max.y - (r).min.y)

void run(GC *);

void *xcalloc(size_t, size_t);
void fatal(const char *, ...);
void *read_file(const char *, size_t *);

GLuint load_shader(const char *, GLenum);

int load_obj(Model *, const char *);
int load_swp(Geometry *, const char *);

void free_geometry(Geometry *);
void free_model(Model *);

void cubic_bspline_to_bezier(float3 *, float3 *);
float3 cubic_bspline(float, float3, float3, float3, float3);
float3 cubic_bezier(float, float3, float3, float3, float3);
float3 cubic_bezier_tangent(float, float3, float3, float3, float3);
float3 quadratic_bezier(float, float3, float3, float3);
void frenet_serret_frame(float3, float3 *, float3 *, size_t);

void default_camera(Camera *);
void camera_matrix(Camera *, float4x4);
void camera_direction(Camera *, float3 *, float3 *, float3 *);
void arcball_rotate_camera(Camera *, float2, float);
void plane_translate_camera(Camera *, float2, float);
void distance_zoom_camera(Camera *, float2, float);

void recalc_projection_matrix(GC *);
