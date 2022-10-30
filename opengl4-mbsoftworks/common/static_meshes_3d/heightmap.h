#ifndef _HEIGHTMAP_H_
#define _HEIGHTMAP_H_

class Heightmap : public StaticMeshIndexed3D
{
public:
	struct HillAlgorithmParameters
	{
		int rows; // Number of desired heightmap rows
		int cols; // Number of desired heightmap columns
		int num_hills; // Number of generated hills
		int hill_radius_min; // Minimal radius of generated hill (in terms of number of heightmap rows / columns)
		int hill_radius_max; // Maximal radius of generated hill (in terms of number of heightmap rows / columns)
		float hill_min_height; // Minimal height of generated hill
		float hill_max_height; // Maximal height of generated hill
	};

	virtual ~Heightmap();

	void init(HillAlgorithmParameters &params, bool has_positions = true, bool has_texcoords = true, bool has_normals = true);
	void init(const char *name, bool has_positions = true, bool has_texcoords = true, bool has_normals = true);

	vector<vector<float> > get_height_data_from_image(const char *name);
	void create_from_height_data(const vector<vector<float> > &height_data);

	static void prepare_multi_layer_shader_program();

	void render();
	void render_points();
	void render_multi_layered(const vector<string> &texture_keys, const vector<float> levels);

	vector<vector<float> > gen_random_height_data(HillAlgorithmParameters &params);

	void setup_vertices();
	void setup_texcoords();
	void setup_normals();
	void setup_index_buffer();

	float get_height(int row, int col);
	float get_rendered_height_at_position(Vec3f render_size, Vec3f position);

	vector<vector<float> > height_data; // Height data representing the current heightmap
	vector<vector<Vec3f> > vertices; // Vertices data heightmap is generated with (only valid during creation phase)
	vector<vector<Vec2f> > texcoords; // Texture coordinates data heightmap is generated with (only valid during creation phase)
	vector<vector<Vec3f> > normals; // Normals data heightmap is generated with (only valid during creation phase)
	int rows; // Number of heightmap rows
	int cols; // Number of heightmap columns
};

#endif