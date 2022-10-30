#include "lib.h"

Skybox::~Skybox()
{
}

void Skybox::init(const char *basedir, const char *imgext,
				  bool has_positions, bool has_texcoords, bool has_normals)
{
	Cube::init(has_positions, has_texcoords, has_normals);
	snprintf(this->basedir, sizeof(this->basedir), "%s", basedir);
	snprintf(this->imgext, sizeof(this->imgext), "%s", imgext);

	load_texture(Cube::FRONT_FACE);
	load_texture(Cube::BACK_FACE);
	load_texture(Cube::LEFT_FACE);
	load_texture(Cube::RIGHT_FACE);
	load_texture(Cube::TOP_FACE);
	load_texture(Cube::BOTTOM_FACE);

	static once_flag once;
	call_once(once, [&]() {
		auto &pm = SamplerManager::get_instance();
		auto &sampler = pm.create_sampler("skybox", MAG_FILTER_BILINEAR, MIN_FILTER_TRILINEAR);
		sampler.set_repeat(false);
	});
}

const char *Skybox::get_side_filename(int side)
{
	if (side & Cube::FRONT_FACE)
		return "front";
	if (side & Cube::BACK_FACE)
		return "back";
	if (side & Cube::LEFT_FACE)
		return "left";
	if (side & Cube::RIGHT_FACE)
		return "right";
	if (side & Cube::TOP_FACE)
		return "top";
	return "bottom";
}

char *Skybox::get_texture_key(int side, char *buf, size_t len)
{
	snprintf(buf, len, "%s/%s", basedir, get_side_filename(side));
	return buf;
}

void Skybox::load_texture(int side)
{
	auto &tm = TextureManager::get_instance();

	char key[PATH_MAX], file[PATH_MAX];
	get_texture_key(side, key, sizeof(key));
	snprintf(file, sizeof(file), "%s.%s", key, imgext);
	tm.add_texture(key, file);
}

void Skybox::render_at(Vec3f position, Program &program)
{
	// Get all texture keys
	char front_key[PATH_MAX];
	char back_key[PATH_MAX];
	char left_key[PATH_MAX];
	char right_key[PATH_MAX];
	char top_key[PATH_MAX];
	char bottom_key[PATH_MAX];

	get_texture_key(Cube::FRONT_FACE, front_key, sizeof(front_key));
	get_texture_key(Cube::BACK_FACE, back_key, sizeof(back_key));
	get_texture_key(Cube::LEFT_FACE, left_key, sizeof(left_key));
	get_texture_key(Cube::RIGHT_FACE, right_key, sizeof(right_key));
	get_texture_key(Cube::TOP_FACE, top_key, sizeof(top_key));
	get_texture_key(Cube::BOTTOM_FACE, bottom_key, sizeof(bottom_key));

	auto &tm = TextureManager::get_instance();
	auto &pm = SamplerManager::get_instance();

	auto &sampler = pm.samplers["skybox"];
	sampler.bind();

	// Turn off depth mask (don't write to depth buffer)
	glDepthMask(GL_FALSE);

	// Enlarge default cube by some factor, that's not further then far clipping plane (100 is fine)
	auto skybox_model_matrix = Mat4f::translate(Mat4f::eye(1.0f), position);
	skybox_model_matrix = Mat4f::scale(skybox_model_matrix, { 900.0f, 900.0f, 900.0f });
	program.set_model_and_normal_matrix(skybox_model_matrix);

	// Render front side if texture has been loaded
	if (tm.contains_texture(front_key))
	{
		tm.textures[front_key].bind();
		render_faces(Cube::FRONT_FACE);
	}

	// Render back side if texture has been loaded
	if (tm.contains_texture(back_key))
	{
		tm.textures[back_key].bind();
		render_faces(Cube::BACK_FACE);
	}

	// Render left side if texture has been loaded
	if (tm.contains_texture(left_key))
	{
		tm.textures[left_key].bind();
		render_faces(Cube::LEFT_FACE);
	}

	// Render right side if texture has been loaded
	if (tm.contains_texture(right_key))
	{
		tm.textures[right_key].bind();
		render_faces(Cube::RIGHT_FACE);
	}

	// Render top side if texture has been loaded
	if (tm.contains_texture(top_key))
	{
		tm.textures[top_key].bind();
		render_faces(Cube::TOP_FACE);
	}

	// Render bottom side if texture has been loaded
	if (tm.contains_texture(bottom_key))
	{
		tm.textures[bottom_key].bind();
		render_faces(Cube::BOTTOM_FACE);
	}

	// Turn the depth mask back on
	glDepthMask(GL_TRUE);
}
