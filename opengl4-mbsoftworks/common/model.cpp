#include "lib.h"

void Model::init(const char *name, const char *default_texture,
				 bool has_positions, bool has_texcoords, bool has_normals,
				 const Mat4f &model_matrix)
{
	StaticMesh3D::init(has_positions, has_texcoords, has_normals);
	load(name, default_texture, model_matrix);
}

int Model::load(const char *name, const char *default_texture, const Mat4f &model_matrix)
{
	printf("Loading model %s\n", name);
	Assimp::Importer importer;
	auto scene = importer.ReadFile(name,
								   aiProcess_CalcTangentSpace |
									   aiProcess_GenSmoothNormals |
									   aiProcess_Triangulate |
									   aiProcess_JoinIdenticalVertices |
									   aiProcess_SortByPType);
	if (!scene)
	{
		printf("Failed to load model %s\n", name);
		return -1;
	}

	auto dir = string_utils::getDirectoryPath(name);
	snprintf(rootdir, sizeof(rootdir), "%s", dir.c_str());

	glGenVertexArrays(1, &vao);
	glBindVertexArray(vao);

	vbo.create();
	vbo.bind();

	auto vertex_count = 0;

	if (has_positions)
	{
		for (auto i = 0u; i < scene->mNumMeshes; i++)
		{
			auto mesh = scene->mMeshes[i];
			auto vertex_count_mesh = 0;
			mesh_start_indices.push_back(vertex_count);
			mesh_material_indices.push_back(mesh->mMaterialIndex);

			for (auto j = 0u; j < mesh->mNumFaces; j++)
			{
				auto &face = mesh->mFaces[j];
				if (face.mNumIndices != 3)
					continue; // Skip non-triangle faces for now

				for (auto k = 0u; k < face.mNumIndices; k++)
				{
					auto position = mesh->mVertices[face.mIndices[k]];
					auto vect = model_matrix * Vec3f{ position.x, position.y, position.z };
					vbo.add(&vect, sizeof(vect));
				}

				vertex_count_mesh += face.mNumIndices;
			}

			vertex_count += vertex_count_mesh;
			mesh_vertices_count.push_back(vertex_count_mesh);
		}
	}

	if (has_texcoords)
	{
		for (auto i = 0u; i < scene->mNumMeshes; i++)
		{
			auto mesh = scene->mMeshes[i];
			for (auto j = 0u; j < mesh->mNumFaces; j++)
			{
				auto &face = mesh->mFaces[j];
				if (face.mNumIndices != 3)
					continue; // Skip non-triangle faces for now

				for (auto k = 0u; k < face.mNumIndices; k++)
				{
					auto texcoord = mesh->mTextureCoords[0][face.mIndices[k]];
					auto vect = Vec2f{ texcoord.x, texcoord.y };
					vbo.add(&vect, sizeof(vect));
				}
			}
		}
	}

	if (has_normals)
	{
		auto normal_matrix = Mat3f::transpose(Mat3f::inverse(Mat4f::mat3(model_matrix)));
		for (auto i = 0u; i < scene->mNumMeshes; i++)
		{
			auto mesh = scene->mMeshes[i];
			for (auto j = 0u; j < mesh->mNumFaces; j++)
			{
				auto &face = mesh->mFaces[j];
				if (face.mNumIndices != 3)
					continue; // Skip non-triangle faces for now

				for (auto k = 0u; k < face.mNumIndices; k++)
				{
					auto normal = mesh->HasNormals() ? mesh->mNormals[face.mIndices[k]] : aiVector3D(0.0f, 1.0f, 0.0f);
					auto vect = Vec3f::normalize(normal_matrix * Vec3f{ normal.x, normal.y, normal.z });
					vbo.add(&vect, sizeof(vect));
				}
			}
		}
	}

	for (auto i = 0u; i < scene->mNumMaterials; i++)
	{
		auto material = scene->mMaterials[i];
		aiString aiTexturePath;

		if (!strcmp(default_texture, "") && material->GetTextureCount(aiTextureType_DIFFUSE) > 0)
		{
			if (material->GetTexture(aiTextureType_DIFFUSE, 0, &aiTexturePath) == AI_SUCCESS)
				load_material_texture(i, aiTexturePath.C_Str());
		}
	}

	if (strcmp(default_texture, ""))
		load_material_texture(0, default_texture);

	vbo.upload(GL_STATIC_DRAW);
	set_vertex_attrib_pointers(vertex_count);

	return 0;
}

void Model::load_material_texture(int material_index, const char *texture_filename)
{
	auto &tm = TextureManager::get_instance();

	// If the texture with such path is already loaded, just use it and go on
	char full_texture_path[PATH_MAX];
	snprintf(full_texture_path, sizeof(full_texture_path), "%s/%s", rootdir, texture_filename);

	auto texture_key = tm.contains_texture_with_path(full_texture_path);
	if (strcmp(texture_key, ""))
	{
		material_texture_keys[material_index] = texture_key;
		return;
	}

	// Otherwise load this texture and store it in the manager
	char new_texture_key[PATH_MAX];
	snprintf(new_texture_key, sizeof(new_texture_key), "assimp_%s", full_texture_path);

	tm.add_texture(new_texture_key, full_texture_path);
	material_texture_keys[material_index] = new_texture_key;
}

void Model::render()
{
	auto &tm = TextureManager::get_instance();

	glBindVertexArray(vao);

	string last_used_texture_key = "";
	for (auto i = 0u; i < mesh_start_indices.size(); i++)
	{
		auto used_material_index = mesh_material_indices[i];
		if (material_texture_keys.count(used_material_index) > 0)
		{
			auto texture_key = material_texture_keys.at(used_material_index);
			if (texture_key != last_used_texture_key)
				tm.textures[texture_key].bind();
		}

		glDrawArrays(GL_TRIANGLES, mesh_start_indices[i], mesh_vertices_count[i]);
	}
}

void Model::render_points()
{
	glBindVertexArray(vao);
	for (auto i = 0u; i < mesh_start_indices.size(); i++)
		glDrawArrays(GL_POINTS, mesh_start_indices[i], mesh_vertices_count[i]);
}