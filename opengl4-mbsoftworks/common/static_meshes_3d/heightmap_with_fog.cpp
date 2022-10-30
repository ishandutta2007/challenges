#include "lib.h"

void HeightmapWithFog::prepare_multi_layer_shader_program_with_fog()
{
	static once_flag once;
	call_once(once, [&]() {
		auto &sm = ShaderManager::get_instance();
		sm.add_shader("multilayer_heightmap_fog_vertex", "data/shaders/heightmap/multilayer_fog.vert", GL_VERTEX_SHADER);
		sm.add_shader("multilayer_heightmap_fog_fragment", "data/shaders/heightmap/multilayer_fog.frag", GL_FRAGMENT_SHADER);
		sm.make_program("multilayer_heightmap_fog", {
														"multilayer_heightmap_fog_vertex",
														"multilayer_heightmap_fog_fragment",
														"ambientLight_fragment",
														"diffuseLight_fragment",
														"utility_fragment",
														"fog_fragment",
													});
	});
}

void HeightmapWithFog::render_multi_layered(const vector<string> &texture_keys, const vector<float> levels)
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
	auto &heightmap_program = sm.programs["multilayer_heightmap_fog"];
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
