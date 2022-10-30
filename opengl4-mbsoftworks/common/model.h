#ifndef _MODEL_H_
#define _MODEL_H_

class Model : public StaticMesh3D
{
public:
	void init(const char *name, const char *default_texture,
			  bool has_positions, bool has_texcoords, bool has_normals,
			  const Mat4f &model_matrix);

	int load(const char *name, const char *default_texture, const Mat4f &model_matrix);
	void load_material_texture(int material_index, const char *texture_filename);

	void render();
	void render_points();

	char rootdir[PATH_MAX]; // Path of the directory where model (and possibly its assets) is located
	vector<int> mesh_start_indices; // Indices of where the meshes start in the VBO
	vector<int> mesh_vertices_count; // How many vertices are there for every mesh
	vector<int> mesh_material_indices; // Index of material for every mesh
	map<int, string> material_texture_keys; // Map for index of material -> texture key to be retrieved from TextureManager
};

#endif