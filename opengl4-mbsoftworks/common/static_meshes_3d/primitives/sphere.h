#ifndef _SPHERE_H_
#define _SPHERE_H_

class Sphere : public StaticMeshIndexed3D
{
public:
	void init(float radius, int num_slices, int num_stacks,
			  bool has_positions, bool has_texcoords, bool has_normals);

	void render();
	void render_points();

	float radius; // Sphere radius
	int num_slices; // Number of slices
	int num_stacks; // Number of stacks

	GLuint num_pole_indices; // Number of indices to render poles with GL_TRIANGLES
	GLuint num_body_indices; // Number of indices to render body

	GLuint north_pole_index_offset; // Index offset to render north pole (always 0)
	GLuint body_index_offset; // Index offset to render body
	GLuint south_pole_index_offset; // Index offset to render south pole
};

#endif