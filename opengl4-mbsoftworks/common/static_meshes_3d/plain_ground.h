#ifndef _PLAIN_GROUND_H_
#define _PLAIN_GROUND_H_

class PlainGround : public StaticMesh3D
{
public:
	static Vec3f vertices[4]; //!< Array of mesh vertices
	static Vec2f texcoords[4]; //!< Array of mesh texture coordinates

	void init(bool has_position, bool has_texcoord, bool has_normals);

	virtual void render() override;
};

#endif