#include "lib.h"

void
default_camera(Camera *c)
{
	c->rotation = qeye();
	c->center = V3(0, 0, 0);
	c->distance = 10;
	c->fovy = deg2rad(50);

	c->center0 = c->center;
	c->rotation0 = c->rotation;
	c->distance0 = c->distance;
}

void
camera_matrix(Camera *c, float4x4 m)
{
	float4x4 l, t, r;

	lookat4x4(l, V3(0, 0, c->distance), V3(0, 0, 0), V3(0, 1, 0));
	qmat4x4(r, c->rotation);
	translate4x3(t, scale3(c->center, -1));

	mul4x4(m, r, t);
	mul4x4(m, l, m);
}

void
camera_direction(Camera *c, float3 *forward, float3 *up, float3 *side)
{
	float4x4 r;

	qmat4x4(r, c->rotation);
	if (forward)
		*forward = scale3(xyz4(row4x4(r, 2)), -1);
	if (up)
		*up = xyz4(row4x4(r, 1));
	if (side)
		*side = xyz4(row4x4(r, 0));
}

void
arcball_rotate_camera(Camera *c, float2 p, float s)
{
	float sx, sy, ex, ey;
	float sl, el, sz, ez;
	float scale, angle, d;
	float3 axis;

	sx = c->click.x - Dx(c->viewport) / 2;
	sy = -c->click.y + Dy(c->viewport) / 2;
	ex = p.x - Dx(c->viewport) / 2;
	ey = -p.y + Dy(c->viewport) / 2;

	scale = s / min(Dx(c->viewport), Dy(c->viewport));
	sx *= scale;
	sy *= scale;
	ex *= scale;
	ey *= scale;

	sl = hypotf(sx, sy);
	el = hypotf(ex, ey);

	if (sl > 1) {
		sx /= sl;
		sy /= sl;
		sl = 1;
	}
	if (el > 1) {
		ex /= el;
		ey /= el;
		el = 1;
	}

	sz = sqrtf(1 - sl * sl);
	ez = sqrtf(1 - el * el);
	d = sx * ex + sy * ey + sz * ez;
	if (d != 1) {
		axis = V3(sy * ez - ey * sz, sz * ex - ex * sx, sx * ey - ey * sy);
		axis = normalize3(axis);
		angle = 2 * acosf(d);
		c->rotation = normalize4(qmul(c->rotation, qaxis(axis, angle)));
	} else
		c->rotation = c->rotation0;
}

void
plane_translate_camera(Camera *c, float2 p, float s)
{
	float3 dirx, diry;
	float2 move;
	float sx, sy, cx, cy;
	float su, cu, sr, cr;
	float d;

	sx = c->click.x - c->viewport.min.x;
	sy = c->click.y - c->viewport.min.y;

	cx = p.x - c->viewport.min.x;
	cy = p.y - c->viewport.min.y;

	d = Dy(c->viewport) * 0.5 / tanf(c->fovy * 0.5);

	su = -sy + Dy(c->viewport) / 2;
	cu = -cy + Dy(c->viewport) / 2;

	sr = sx - Dx(c->viewport) / 2;
	cr = cx - Dx(c->viewport) / 2;

	move = V2(cr - sr, cu - su);
	move = scale2(move, -c->distance / d * s);

	camera_direction(c, NULL, &diry, &dirx);
	dirx = scale3(dirx, move.x);
	diry = scale3(diry, move.y);

	c->center = add3(add3(c->center0, dirx), diry);
}

void
distance_zoom_camera(Camera *c, float2 p, float s)
{
	float sy, cy, dy;

	sy = c->click.y - c->viewport.min.y;
	cy = p.y - c->viewport.min.y;

	dy = (cy - sy) / c->viewport.max.y;
	dy *= s;

	c->distance = c->distance0 * exp(dy);
}

void
recalc_projection_matrix(GC *gc)
{
	Camera *cam;

	cam = &gc->camera;
	cam->viewport = V4(0, 0, gc->width, gc->height);
	persp4x4(gc->projection, cam->fovy, Dx(cam->viewport) / Dy(cam->viewport), 0.1, 1000);
	glViewport(0, 0, gc->width, gc->height);
}
