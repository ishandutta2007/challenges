#ifndef _HOUSE_H_
#define _HOUSE_H_

class House : StaticMesh3D
{
public:
	virtual ~House();

	void init(bool has_positions, bool has_texcoords, bool has_normals);

	void render();
	void render(Vec3f position, float rotation_angle);

	Cube cube; // Cube static mesh used to render house with
	Pyramid pyramid; // Pyramid static mesh used to render house with
};

#endif