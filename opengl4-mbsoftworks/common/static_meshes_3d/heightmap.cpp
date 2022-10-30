#include "lib.h"

Heightmap::~Heightmap()
{
}

void Heightmap::init(HillAlgorithmParameters &params, bool has_positions, bool has_texcoords, bool has_normals)
{
	StaticMeshIndexed3D::init(has_positions, has_texcoords, has_normals);
	create_from_height_data(gen_random_height_data(params));
}

void Heightmap::init(const char *name, bool has_positions, bool has_texcoords, bool has_normals)
{
	StaticMeshIndexed3D::init(has_positions, has_texcoords, has_normals);
	create_from_height_data(get_height_data_from_image(name));
}

void Heightmap::prepare_multi_layer_shader_program()
{
	static once_flag once;
	call_once(once, [&]() {
		auto &sm = ShaderManager::get_instance();
		sm.add_shader("multilayer_heightmap_vertex", "data/shaders/heightmap/multilayer.vert", GL_VERTEX_SHADER);
		sm.add_shader("multilayer_heightmap_fragment", "data/shaders/heightmap/multilayer.frag", GL_FRAGMENT_SHADER);
		sm.make_program("multilayer_heightmap", {
													"multilayer_heightmap_vertex",
													"multilayer_heightmap_fragment",
													"ambientLight_fragment",
													"diffuseLight_fragment",
													"utility_fragment",
												});
	});
}

vector<vector<float> > Heightmap::get_height_data_from_image(const char *name)
{
	printf("Loading heightmap %s\n", name);

	stbi_set_flip_vertically_on_load(1);
	int width, height, bpp;
	auto data = stbi_load(name, &width, &height, &bpp, 0);
	if (!data)
	{
		printf("Failed to load heightmap image: %s\n", name);
		return vector<vector<float> >();
	}

	vector<vector<float> > result(height, vector<float>(width));
	auto pixels = &data[0];
	for (auto i = 0; i < height; i++)
	{
		for (auto j = 0; j < width; j++)
		{
			result[i][j] = float(*pixels) / 255.0f;
			pixels += bpp;
		}
	}

	stbi_image_free(data);
	return result;
}

void Heightmap::create_from_height_data(const vector<vector<float> > &height_data)
{
	this->height_data = height_data;
	rows = height_data.size();
	cols = height_data[0].size();
	num_vertices = rows * cols;

	// First, prepare VAO and VBO for vertex data
	glGenVertexArrays(1, &vao);
	glBindVertexArray(vao);
	vbo.create(num_vertices * get_vertex_byte_size()); // Preallocate memory
	vbo.bind();

	if (has_positions)
		setup_vertices();

	if (has_texcoords)
		setup_texcoords();

	if (has_normals)
	{
		if (!has_positions)
			setup_vertices();

		setup_normals();
	}

	// Send data to GPU, they're ready now
	vbo.upload(GL_STATIC_DRAW);
	set_vertex_attrib_pointers(num_vertices);

	// Vertex data are in, set up the index buffer
	setup_index_buffer();

	// Clear the data, we won't need it anymore
	vertices.clear();
	texcoords.clear();
	normals.clear();
}

void Heightmap::setup_vertices()
{
	vertices = vector<vector<Vec3f> >(rows, std::vector<Vec3f>(cols));

	for (auto i = 0; i < rows; i++)
	{
		for (auto j = 0; j < cols; j++)
		{
			auto factor_row = float(i) / float(rows - 1);
			auto factor_column = float(j) / float(cols - 1);
			auto &vertex_height = height_data[i][j];
			vertices[i][j] = { -0.5f + factor_column, vertex_height, -0.5f + factor_row };
		}
		vbo.add(vertices[i].data(), cols * sizeof(Vec3f));
	}
}

void Heightmap::setup_texcoords()
{
	texcoords = vector<vector<Vec2f> >(rows, vector<Vec2f>(cols));

	auto texture_step_u = 0.1f;
	auto texture_step_v = 0.1f;
	for (auto i = 0; i < rows; i++)
	{
		for (auto j = 0; j < cols; j++)
			texcoords[i][j] = { texture_step_u * j, texture_step_v * i };
		vbo.add(texcoords[i].data(), cols * sizeof(Vec2f));
	}
}

void Heightmap::setup_normals()
{
	normals = vector<vector<Vec3f> >(rows, vector<Vec3f>(cols));

	vector<vector<Vec3f> > temp_normals[2];
	for (auto i = 0; i < 2; i++)
		temp_normals[i] = vector<vector<Vec3f> >(rows - 1, vector<Vec3f>(cols - 1));

	for (auto i = 0; i < rows - 1; i++)
	{
		for (auto j = 0; j < cols - 1; j++)
		{
			auto &va = vertices[i][j];
			auto &vb = vertices[i][j + 1];
			auto &vc = vertices[i + 1][j + 1];
			auto &vd = vertices[i + 1][j];

			auto triangle_normal_a = Vec3f::cross(vb - va, va - vd);
			auto triangle_normal_b = Vec3f::cross(vd - vc, vc - vb);

			temp_normals[0][i][j] = Vec3f::normalize(triangle_normal_a);
			temp_normals[1][i][j] = Vec3f::normalize(triangle_normal_b);
		}
	}

	for (auto i = 0; i < rows; i++)
	{
		for (auto j = 0; j < cols; j++)
		{
			// Now we wanna calculate final normal for [i][j] vertex. We will have a look at all triangles this vertex is part of, and then we will make average vector
			// of all adjacent triangles' normals

			auto is_first_row = i == 0;
			auto is_first_col = j == 0;
			auto is_last_row = i == rows - 1;
			auto is_last_col = j == cols - 1;

			auto final_vertex_normal = Vec3f{ 0.0f, 0.0f, 0.0f };

			// Look for triangle to the upper-left
			if (!is_first_row && !is_first_col)
				final_vertex_normal += temp_normals[0][i - 1][j - 1];

			// Look for triangles to the upper-right
			if (!is_first_row && !is_last_col)
			{
				for (auto k = 0; k < 2; k++)
					final_vertex_normal += temp_normals[k][i - 1][j];
			}

			// Look for triangle to the bottom-right
			if (!is_last_row && !is_last_col)
				final_vertex_normal += temp_normals[0][i][j];

			// Look for triangles to the bottom-right
			if (!is_last_row && !is_first_col)
			{
				for (auto k = 0; k < 2; k++)
					final_vertex_normal += temp_normals[k][i][j - 1];
			}

			// Store final normal of j-th vertex in i-th row
			normals[i][j] = Vec3f::normalize(final_vertex_normal);
		}
		vbo.add(normals[i].data(), cols * sizeof(Vec3f));
	}
}

void Heightmap::setup_index_buffer()
{
	// Create a VBO with heightmap indices
	indices.create();
	indices.bind(GL_ELEMENT_ARRAY_BUFFER);
	primitive_restart_index = num_vertices;

	for (auto i = 0; i < rows - 1; i++)
	{
		for (auto j = 0; j < cols; j++)
		{
			for (auto k = 0; k < 2; k++)
			{
				auto row = i + k;
				auto index = row * cols + j;
				indices.add(&index, sizeof(int));
			}
		}
		// Restart triangle strips
		indices.add(&primitive_restart_index, sizeof(int));
	}

	// Send indices to GPU
	indices.upload(GL_STATIC_DRAW);

	// Calculate total count of indices
	num_indices = (rows - 1) * cols * 2 + rows - 1;
}

vector<vector<float> > Heightmap::gen_random_height_data(HillAlgorithmParameters &params)
{
	vector<vector<float> > height_data(params.rows, vector<float>(params.cols, 0.0f));

	random_device rd;
	mt19937 generator(rd());
	uniform_int_distribution<int> hill_radius_distribution(params.hill_radius_min, params.hill_radius_max);
	uniform_real_distribution<float> hill_height_distribution(params.hill_min_height, params.hill_max_height);
	uniform_int_distribution<int> hill_center_row_int_distribution(0, params.rows - 1);
	uniform_int_distribution<int> hill_center_col_int_distribution(0, params.cols - 1);

	for (int i = 0; i < params.num_hills; i++)
	{
		auto hill_center_row = hill_center_row_int_distribution(generator);
		auto hill_center_col = hill_center_col_int_distribution(generator);
		auto hill_radius = hill_radius_distribution(generator);
		auto hill_height = hill_height_distribution(generator);

		for (auto r = hill_center_row - hill_radius; r < hill_center_row + hill_radius; r++)
		{
			for (auto c = hill_center_col - hill_radius; c < hill_center_col + hill_radius; c++)
			{
				if (r < 0 || r >= params.rows || c < 0 || c >= params.cols)
					continue;

				auto r2 = hill_radius * hill_radius; // r*r term
				auto x2x1 = hill_center_col - c; // (x2-x1) term
				auto y2y1 = hill_center_row - r; // (y2-y1) term
				auto height = float(r2 - x2x1 * x2x1 - y2y1 * y2y1);
				if (height < 0.0f)
					continue;

				auto factor = height / r2;
				height_data[r][c] += hill_height * factor;
				if (height_data[r][c] > 1.0f)
					height_data[r][c] = 1.0f;
			}
		}
	}
	return height_data;
}

void Heightmap::render()
{
	glBindVertexArray(vao);
	glEnable(GL_PRIMITIVE_RESTART);
	glPrimitiveRestartIndex(primitive_restart_index);

	glDrawElements(GL_TRIANGLE_STRIP, num_indices, GL_UNSIGNED_INT, 0);
	glDisable(GL_PRIMITIVE_RESTART);
}

void Heightmap::render_multi_layered(const vector<string> &texture_keys, const vector<float> levels)
{
	auto &sm = ShaderManager::get_instance();
	auto &tm = TextureManager::get_instance();

	// If there are less than 2 textures, does not even make sense to render heightmap in multilayer way
	if (texture_keys.size() < 2)
		return;

	// Number of levels defined must be correct
	if ((texture_keys.size() - 1) * 2 != levels.size())
		return;

	// Bind chosen textures first
	auto &heightmap_program = sm.programs["multilayer_heightmap"];
	for (auto i = 0; i < int(texture_keys.size()); i++)
	{
		auto key = stprint("terrainSampler[%d]", i);
		tm.textures[texture_keys[i]].bind(i);
		heightmap_program[key] = i;
	}

	// Set uniform levels
	heightmap_program["numLevels"] = int(levels.size());
	heightmap_program["levels"] = levels;

	// Finally render heightmap
	render();
}

void Heightmap::render_points()
{
	glBindVertexArray(vao);

	// Render points only
	glDrawArrays(GL_POINTS, 0, num_vertices);
}

float Heightmap::get_height(int row, int col)
{
	if (row < 0 || row >= rows || col < 0 || col >= cols)
		return 0.0f;

	return height_data[row][col];
}

float Heightmap::get_rendered_height_at_position(Vec3f render_size, Vec3f position)
{
	const auto half_width = render_size.x / 2.0f;
	const auto half_depth = render_size.z / 2.0f;

	const auto row = (rows * (position.z + half_depth) / render_size.z);
	const auto column = (cols * (position.x + half_width) / render_size.x);

	return get_height(row, column) * render_size.y;
}