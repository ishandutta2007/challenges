#ifndef _CYLINDER_H_
#define _CYLINDER_H_

class Cylinder : public StaticMesh3D
{
public:
	void init(float radius, int num_slices, float height,
			  bool has_positions, bool has_texcoords, bool has_normals);
	void render();
	void render_points();

	float radius; // Cylinder radius (distance from the center of cylinder to surface)
	int num_slices; // Number of cylinder slices
	float height; // Height of the cylinder

	int num_vertices_side; // How many vertices to render side of the cylinder
	int num_vertices_top_bottom; // How many vertices to render top / bottom of the cylinder
	int num_vertices_total; // Just a sum of both numbers above
};

#endif