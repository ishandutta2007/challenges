#ifndef _CONE_H_
#define _CONE_H_

class Cone : public StaticMesh3D
{
public:
	void init(Vec3f directix, Vec3f apex, float height, float radius, int num_slices,
			  bool has_positions, bool has_texcoords, bool has_normals);
	void render();
	void render_points();

	Vec3f directix; // Axis defined as normalized vector from base to apex
	Vec3f apex; // Point at the top of the cone
	float radius; // Directix radius
	int num_slices; // Number of slices
	float height; // Height of the cone

	int num_vertices_side; // How many vertices to render sides of the cone (represented by line connecting the apex point to the rotation of the directix vector)
	int num_vertices_bottom; // How many vertices to render bottom circular portion of the cone
	int num_vertices_total; // Number of vertices which is the sum of the above
};

#endif
