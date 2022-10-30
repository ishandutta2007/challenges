#include "lib.h"

int
load_obj(Model *md, const char *name)
{
	FILE *fp;
	char line[1024];
	long len;
	int rv;
	float f[4];
	int i[9], j;

	memset(md, 0, sizeof(*md));
	rv = 0;
	fp = fopen(name, "rb");
	if (!fp)
		goto error;

	fseek(fp, 0, SEEK_END);
	len = ftell(fp);
	fseek(fp, 0, SEEK_SET);
	if (len < 0)
		goto error;

	md->vertices = xcalloc(len, sizeof(*md->vertices));
	md->texcoords = xcalloc(len, sizeof(*md->texcoords));
	md->normals = xcalloc(len, sizeof(*md->normals));
	md->faces = xcalloc(len * 9, sizeof(*md->faces));
	md->extents = (Extents){
	    .min = {.x = FLT_MAX, .y = FLT_MAX, .z = FLT_MAX},
	    .max = {.x = -FLT_MAX, .y = -FLT_MAX, .z = -FLT_MAX},
	};
	while (fgets(line, sizeof(line), fp)) {
		if (md->nvertices >= (size_t)len)
			break;
		if (md->ntexcoords >= (size_t)len)
			break;
		if (md->nnormals >= (size_t)len)
			break;
		if (md->nfaces >= (size_t)len)
			break;

		if (sscanf(line, "v %f %f %f", f, f + 1, f + 2) == 3) {
			md->vertices[md->nvertices++] = V4(f[0], f[1], f[2], 1);
			md->extents.min = min4(md->extents.min, md->vertices[md->nvertices - 1]);
			md->extents.max = max4(md->extents.max, md->vertices[md->nvertices - 1]);
		} else if (sscanf(line, "vt %f %f", f, f + 1) == 2) {
			md->texcoords[md->ntexcoords++] = V4(f[0], f[1], 0, 1);
		} else if (sscanf(line, "vn %f %f %f", f, f + 1, f + 2) == 3) {
			md->normals[md->nnormals++] = V4(f[0], f[1], f[2], 1);
		} else if (sscanf(line, "f %d/%d/%d %d/%d/%d %d/%d/%d", i, i + 1, i + 2, i + 3, i + 4, i + 5, i + 6, i + 7, i + 8) == 9) {
			for (j = 0; j < 9; j++) {
				if (i[j] > 0)
					i[j]--;
				if (i[j] < 0 || i[j] >= len)
					goto einval;
			}
			md->faces[md->nfaces * 9 + 0] = i[0];
			md->faces[md->nfaces * 9 + 1] = i[3];
			md->faces[md->nfaces * 9 + 2] = i[6];
			md->faces[md->nfaces * 9 + 3] = i[1];
			md->faces[md->nfaces * 9 + 4] = i[4];
			md->faces[md->nfaces * 9 + 5] = i[7];
			md->faces[md->nfaces * 9 + 6] = i[2];
			md->faces[md->nfaces * 9 + 7] = i[5];
			md->faces[md->nfaces * 9 + 8] = i[8];
			md->nfaces++;
		}
	}

	if (0) {
	einval:
		errno = EINVAL;
	error:
		rv = -errno;
		free_model(md);
	}

	if (fp)
		fclose(fp);

	return rv;
}

void
free_model(Model *md)
{
	if (!md)
		return;
	free(md->vertices);
	free(md->texcoords);
	free(md->normals);
	free(md->faces);
}
