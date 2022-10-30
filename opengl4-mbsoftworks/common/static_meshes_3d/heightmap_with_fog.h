#ifndef _HEIGHTMAP_WITH_FOG_H_
#define _HEIGHTMAP_WITH_FOG_H_

class HeightmapWithFog : public Heightmap
{
public:
	static void prepare_multi_layer_shader_program_with_fog();

	void render_multi_layered(const vector<string> &texture_keys, const vector<float> levels);
};

#endif