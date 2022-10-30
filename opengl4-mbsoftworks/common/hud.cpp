#include "lib.h"

void HUD::init(GLWindow *glwindow)
{
	textured_quad.init(true, true);
	this->glwindow = glwindow;

	static once_flag once;
	call_once(once, [&]() {
		auto &sm = ShaderManager::get_instance();
		auto &pm = SamplerManager::get_instance();
		sm.add_shader("ortho_2D_vertex", "data/shaders/tut009/ortho2D.vert", GL_VERTEX_SHADER);
		sm.add_shader("ortho_2D_fragment", "data/shaders/tut009/ortho2D.frag", GL_FRAGMENT_SHADER);
		sm.make_program("ortho_2D", { "ortho_2D_vertex", "ortho_2D_fragment" });
		pm.create_sampler("HUD", MAG_FILTER_BILINEAR, MIN_FILTER_BILINEAR);
	});
}

void HUD::render_textured_quad_2d(int x, int y, int width, int height, bool from_right, bool from_top)
{
	int window_width, window_height;
	SDL_GetWindowSize(glwindow->window, &window_width, &window_height);
	if (from_right)
		x = window_width - x - width;
	if (from_top)
		y = window_height - y - height;

	auto &sm = ShaderManager::get_instance();
	auto &program = sm.programs["ortho_2D"];
	auto model = Mat4f::translate(Mat4f::eye(1.0), { (float)x, (float)y, 0.0f });
	model = Mat4f::scale(model, { (float)width, (float)height, 1.0f });
	program["matrices.modelMatrix"] = model;

	textured_quad.render();
}