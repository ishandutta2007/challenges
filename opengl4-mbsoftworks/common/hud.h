#ifndef _HUD_H_
#define _HUD_H_

class HUD
{
public:
	void init(GLWindow *window);

	void render_textured_quad_2d(int x, int y, int width, int height, bool from_right = false, bool from_top = false);

	GLWindow *glwindow;
	Quad textured_quad;
};

#endif