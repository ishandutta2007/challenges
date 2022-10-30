#ifndef _SNOW_COVERED_PLAIN_GROUND_H_
#define _SNOW_COVERED_PLAIN_GROUND_H_

class SnowCoveredPlainGround : public PlainGround
{
public:
	virtual ~SnowCoveredPlainGround()
	{
		release();
	}

	void init(AmbientLight *ambient_light, DiffuseLight *diffuse_light, PointLight *fire_point_light, FogParameters *fog_parameters,
			  bool has_positions = true, bool has_texcoords = true, bool has_normals = true);

	virtual void render() override;

	AmbientLight *ambient_light;
	DiffuseLight *diffuse_light;
	PointLight *fire_point_light;
	FogParameters *fog_parameters;
};

#endif