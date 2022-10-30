#ifndef _TORUS_H_
#define _TORUS_H_

class Torus : public StaticMeshIndexed3D
{
public:
	void init(int main_segments, int tube_segments, float main_radius, float tube_radius,
			  bool has_positions, bool has_texcoords, bool has_normals);

	void render();
	void render_points();

	int main_segments;
	int tube_segments;
	float main_radius;
	float tube_radius;
};

#endif