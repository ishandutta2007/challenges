#ifndef _CUBE_H_
#define _CUBE_H_

class Cube : public StaticMesh3D
{
public:
	static const int FRONT_FACE = 1; // Bitmask to render cube front face
	static const int BACK_FACE = 1 << 1; // Bitmask to render cube back face
	static const int LEFT_FACE = 1 << 2; // Bitmask to render cube left face
	static const int RIGHT_FACE = 1 << 3; // Bitmask to render cube right face
	static const int TOP_FACE = 1 << 4; // Bitmask to render cube top face
	static const int BOTTOM_FACE = 1 << 5; // Bitmask to render cube bottom face

	static Vec3f vertices[36]; // Array of mesh vertices
	static Vec2f texcoords[6]; // Array of mesh texture coordinates
	static Vec3f normals[6]; // Array of mesh normals

	void init(bool has_position, bool has_texcoords, bool has_normals);
	void render();
	void render_faces(int mask);
	void render_points();
};

#endif