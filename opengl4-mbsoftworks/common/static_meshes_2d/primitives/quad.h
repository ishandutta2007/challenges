#ifndef _QUAD_H_
#define _QUAD_H_

class Quad : public StaticMesh2D
{
public:
	static Vec2f vertices[4]; // Array of mesh vertices (and texture coordinates as well)

	void init(bool has_positions, bool has_texcoords);

	void render();
};

#endif