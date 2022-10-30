#ifndef _SKYBOX_H_
#define _SKYBOX_H_

class Skybox : public Cube
{
public:
	virtual ~Skybox();

	void init(const char *basedir, const char *imgext,
			  bool has_positions = true, bool has_texcoords = true, bool has_normals = true);

	char *get_texture_key(int side, char *buf, size_t len);
	const char *get_side_filename(int side);

	void load_texture(int side);

	void render_at(Vec3f position, Program &program);

	char basedir[PATH_MAX];
	char imgext[32];
};

#endif
