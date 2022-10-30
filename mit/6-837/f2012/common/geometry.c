#include "lib.h"

static void
alloc_curve(Curve *c, size_t n)
{
	c->vertices = xcalloc(n, sizeof(*c->vertices));
	c->tangents = xcalloc(n, sizeof(*c->tangents));
	c->normals = xcalloc(n, sizeof(*c->normals));
	c->binormals = xcalloc(n, sizeof(*c->binormals));
	c->npoints = n;
}

static void
gen_circle_curve(Curve *c, float r, size_t n)
{
	float t;
	size_t i;

	alloc_curve(c, n + 1);
	for (i = 0; i <= n; i++) {
		t = 2.0 * M_PI * i / n;
		c->vertices[i] = V3(r * cos(t), r * sin(t), 0);
		c->tangents[i] = V3(-sin(t), cos(t), 0);
		c->normals[i] = V3(-cos(t), -sin(t), 0);
		c->binormals[i] = V3(0, 0, 1);
	}
}

// Assume that all Bezier curves that are received have G1 continuity.
// Otherwise, the TNB will not be be defined at points where this does not hold.
static void
eval_bezier(Curve *c, float3 *cps, size_t cpslen, size_t steps)
{
	size_t i, j, k;

	if (cpslen < 4 || (cpslen % 3) != 1)
		return;

	alloc_curve(c, (cpslen / 3) * (steps + 1));
	for (i = k = 0; i < cpslen - 1; i += 3) {
		for (j = 0; j <= steps; j++, k++) {
			c->vertices[k] = cubic_bezier(j * 1.0 / steps, cps[i], cps[i + 1], cps[i + 2], cps[i + 3]);
			c->tangents[k] = cubic_bezier_tangent(j * 1.0 / steps, cps[i], cps[i + 1], cps[i + 2], cps[i + 3]);
		}
	}
}

static void
eval_bspline(Curve *c, float3 *cps, size_t cpslen, size_t steps)
{

	size_t i, j, k;
	float3 p[4];

	if (cpslen < 4)
		return;

	alloc_curve(c, (cpslen - 3) * (steps + 1));
	for (i = k = 0; i < cpslen - 3; i++) {
		cubic_bspline_to_bezier(&cps[i], p);
		for (j = 0; j <= steps; j++, k++) {
			c->vertices[k] = cubic_bezier(j * 1.0 / steps, p[0], p[1], p[2], p[3]);
			c->tangents[k] = cubic_bezier_tangent(j * 1.0 / steps, p[0], p[1], p[2], p[3]);
		}
	}
}

static float3 *
read_cps(FILE *fp, int dim, size_t len)
{
	size_t i;
	float3 *v;

	v = xcalloc(len, sizeof(*v));
	for (i = 0; i < len; i++) {
		memset(&v[i], 0, sizeof(v[i]));
		if (dim == 2)
			fscanf(fp, " [ %f %f ] ", &v[i].x, &v[i].y);
		else if (dim == 3)
			fscanf(fp, " [ %f %f %f ] ", &v[i].x, &v[i].y, &v[i].z);
		else
			assert(0);
	}

	return v;
}

static void
read_curve(int dim, FILE *lp, FILE *fp, Geometry *gm, void (*eval)(Curve *, float3 *, size_t, size_t))
{
	size_t steps, cpslen, i;
	float3 *cps;
	Curve *c;

	steps = cpslen = 0;
	fscanf(lp, "%zu %zu", &steps, &cpslen);
	cps = read_cps(fp, dim, cpslen);

	if (cpslen < SIZE_MAX / 2 && steps < SIZE_MAX / 2) {
		c = &gm->curves[gm->ncurves++];
		eval(c, cps, cpslen, steps);
		for (i = 0; i < c->npoints; i++)
			frenet_serret_frame(c->tangents[i], &c->normals[i], &c->binormals[i], 10);
	}

	gm->cps[gm->ncps] = cps;
	gm->cpslen[gm->ncps] = cpslen;
	gm->ncps++;
}

int
load_swp(Geometry *gm, const char *name)
{
	char line[512], objtype[512], objname[512];
	FILE *fp, *lp;
	long len;
	int rv;
	float f[2];
	int i[1];
	size_t j;

	memset(gm, 0, sizeof(*gm));
	rv = 0;
	fp = fopen(name, "rb");
	lp = fmemopen(line, sizeof(line), "rb");
	if (!fp || !lp)
		goto error;

	fseek(fp, 0, SEEK_END);
	len = ftell(fp);
	fseek(fp, 0, SEEK_SET);
	if (len < 0)
		goto error;

	gm->curves = xcalloc(len, sizeof(*gm->curves));
	gm->surfaces = xcalloc(len, sizeof(*gm->surfaces));
	gm->cps = xcalloc(len, sizeof(*gm->cps));
	gm->cpslen = xcalloc(len, sizeof(*gm->cpslen));

	while (fgets(line, sizeof(line), fp)) {
		if (gm->ncurves >= (size_t)len)
			break;
		if (gm->ncps >= (size_t)len)
			break;
		if (gm->nsurfaces >= (size_t)len)
			break;

		fseek(lp, 0, SEEK_SET);
		fflush(lp);

		if (fscanf(lp, "%s %s", objtype, objname) != 2)
			continue;

		if (!strcmp(objtype, "bez2"))
			read_curve(2, lp, fp, gm, eval_bezier);
		else if (!strcmp(objtype, "bez3"))
			read_curve(3, lp, fp, gm, eval_bezier);
		else if (!strcmp(objtype, "bsp2"))
			read_curve(2, lp, fp, gm, eval_bspline);
		else if (!strcmp(objtype, "bsp3"))
			read_curve(3, lp, fp, gm, eval_bspline);
		else if (!strcmp(objtype, "circ")) {
			fscanf(lp, "%d %f", i, f);
			gen_circle_curve(&gm->curves[gm->ncurves++], f[0], i[0]);
		}
	}

	gm->total_size = gm->ncurves * sizeof(*gm->curves);
	gm->total_size += gm->nsurfaces * sizeof(*gm->surfaces);
	for (j = 0; j < gm->ncps; j++)
		gm->total_size += gm->cpslen[j] * sizeof(gm->cps[j][0]);
	gm->total_size *= len;

	if (0) {
	error:
		rv = -errno;
		free_geometry(gm);
	}

	if (fp)
		fclose(fp);
	if (lp)
		fclose(lp);

	return rv;
}

void
free_geometry(Geometry *gm)
{
	Curve *c;
	size_t i;

	if (!gm)
		return;

	for (i = 0; i < gm->ncurves; i++) {
		c = &gm->curves[i];
		free(c->vertices);
		free(c->tangents);
		free(c->normals);
		free(c->binormals);
	}

	for (i = 0; i < gm->ncps; i++)
		free(gm->cps[i]);
	free(gm->cpslen);

	free(gm->curves);
	free(gm->surfaces);
}

void
cubic_bspline_to_bezier(float3 *p, float3 *r)
{
	float4x4 Bzi = {{1, 0, 0, 0},
	                {1, 1 / 3.0, 0, 0},
	                {1, 2 / 3.0, 1 / 3.0, 0},
	                {1, 1, 1, 1}};
	float4x4 Bs = {{1 / 6.0, 4 / 6.0, 1 / 6.0, 0 / 6.0},
	               {-3 / 6.0, 0 / 6.0, 3 / 6.0, 0 / 6.0},
	               {3 / 6.0, -6 / 6.0, 3 / 6.0, 0 / 6.0},
	               {-1 / 6.0, 3 / 6.0, -3 / 6.0, 1 / 6.0}};
	float4x4 G = {
	    {p[0].x, p[0].y, p[0].z, 0},
	    {p[1].x, p[1].y, p[1].z, 0},
	    {p[2].x, p[2].y, p[2].z, 0},
	    {p[3].x, p[3].y, p[3].z, 0},
	};

	float4x4 M;
	size_t i;

	mul4x4(M, Bzi, Bs);
	mul4x4(M, M, G);
	for (i = 0; i < 4; i++)
		r[i] = xyz4(row4x4(M, i));
}

float3
cubic_bezier(float t, float3 pa, float3 pb, float3 pc, float3 pd)
{
	float4x4 B = {
	    {1, 0, 0, 0},
	    {-3, 3, 0, 0},
	    {3, -6, 3, 0},
	    {-1, 3, -3, 1},
	};
	float4x4 P = {
	    {pa.x, pa.y, pa.z, 0},
	    {pb.x, pb.y, pb.z, 0},
	    {pc.x, pc.y, pc.z, 0},
	    {pd.x, pd.y, pd.z, 0},
	};
	float4 T = V4(1, t, t * t, t * t * t);

	float4x4 M;

	mul4x4(M, B, P);
	return xyz4(trb4x4(T, M));
}

float3
cubic_bezier_tangent(float t, float3 pa, float3 pb, float3 pc, float3 pd)
{
	float3 p;

	p = quadratic_bezier(t, sub3(pb, pa), sub3(pc, pb), sub3(pd, pc));
	p = normalize3(scale3(p, 3));
	return p;
}

float3
quadratic_bezier(float t, float3 pa, float3 pb, float3 pc)
{
	float3x3 B = {
	    {1, 0, 0},
	    {-2, 2, 0},
	    {1, -2, 1},
	};
	float3x3 P = {
	    {pa.x, pa.y, 0},
	    {pb.x, pb.y, 0},
	    {pc.x, pc.y, 0},
	};
	float3 T = {{1, t, t * t}};

	float3x3 M;

	mul3x3(M, B, P);
	return trb3x3(T, M);
}

void
frenet_serret_frame(float3 T, float3 *N, float3 *B, size_t n)
{
	size_t i;

	*B = V3(0, 0, 1);
	for (i = 0; i < n; i++) {
		*N = normalize3(cross3(*B, T));
		*B = normalize3(cross3(T, *N));
	}
}
