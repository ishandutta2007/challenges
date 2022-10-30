#ifndef _SNOW_COVERED_GROUND_H_
#define _SNOW_COVERED_GROUND_H_

class SnowCoveredGround : public PlainGround
{
public:
	virtual ~SnowCoveredGround();

	void init(bool has_position, bool has_texcoords, bool has_normals);

	void render();
};

#endif
