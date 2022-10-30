#ifndef _PYRAMID_H_
#define _PYRAMID_H_

class Pyramid : public StaticMesh3D
{
public:
	static Vec3f vertices[12]; // Array of mesh vertices
	static Vec2f texcoords[3]; // Array of mesh texture coordinates

	void init(bool has_positions, bool has_texcoords, bool has_normals);
	void render();
	void render_points();
};

#endif