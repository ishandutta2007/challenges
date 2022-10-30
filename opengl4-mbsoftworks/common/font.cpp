#include "lib.h"

void Font::init()
{
	color = Vec4f{ 1, 1, 1, 1 };

	static once_flag once;
	call_once(once, [&]() {
		auto &sm = ShaderManager::get_instance();
		sm.add_shader("freetype_font_vertex", "data/shaders/tut012/font2D.vert", GL_VERTEX_SHADER);
		sm.add_shader("freetype_font_fragment", "data/shaders/tut012/font2D.frag", GL_FRAGMENT_SHADER);
		sm.make_program("freetype_font", { "freetype_font_vertex", "freetype_font_fragment" });

		auto &pm = SamplerManager::get_instance();
		auto &sampler = pm.create_sampler("freetype_font", MAG_FILTER_BILINEAR, MIN_FILTER_NEAREST);
		sampler.set_repeat(false);
	});
}

int Font::load(const char *name, int pixel_size)
{
	printf("Loading font %s\n", name);
	if (pixel_size < 1 || pixel_size > Font::TEXTURE_SIZE)
	{
		printf("Invalid texture size\n");
		return -1;
	}
	this->pixel_size = pixel_size;

	glGenVertexArrays(1, &vao);
	glBindVertexArray(vao);
	vbo.create();
	vbo.bind();

	auto data = file2str(name, NULL);
	if (!data)
	{
		printf("Failed to load font file: %s: %s\n", name, strerror(errno));
		return -1;
	}
	auto bmp = new uint8_t[Font::TEXTURE_SIZE * Font::TEXTURE_SIZE];
	auto ret = stbtt_BakeFontBitmap((unsigned char *)data, 0, pixel_size, bmp, Font::TEXTURE_SIZE, Font::TEXTURE_SIZE, 32, 127, cdata);
	if (ret < 0)
	{
		printf("Failed to bake font bitmap: %s\n", name);
		return ret;
	}
	texture.create(bmp, Font::TEXTURE_SIZE, Font::TEXTURE_SIZE, 1, true);

	// Setup vertex positions pointers
	glEnableVertexAttribArray(0);
	glVertexAttribPointer(0, 2, GL_FLOAT, GL_FALSE, sizeof(Vec2f) * 2, (void *)(0));

	// Setup texture coordinates pointers
	glEnableVertexAttribArray(1);
	glVertexAttribPointer(1, 2, GL_FLOAT, GL_FALSE, sizeof(Vec2f) * 2, (void *)sizeof(Vec2f));

	delete[] bmp;
	free(data);
	return 0;
}

void Font::print(float x, float y, const char *fmt, ...)
{
	char text[1024];
	va_list ap;
	va_start(ap, fmt);
	vsnprintf(text, sizeof(text), fmt, ap);
	va_end(ap);

	glDisable(GL_DEPTH_TEST);
	glDepthMask(0);
	glEnable(GL_BLEND);
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

	auto &sm = ShaderManager::get_instance();
	auto &pm = SamplerManager::get_instance();
	auto &mm = MatrixManager::get_instance();

	auto &program = sm.programs["freetype_font"];
	auto &sampler = pm.samplers["freetype_font"];
	program.use();
	program["matrices.projectionMatrix"] = mm.orthoyn;
	program["matrices.modelMatrix"] = Mat4f::eye(1);
	program["color"] = color;
	sampler.bind();
	program["sampler"] = 0;

	glBindVertexArray(vao);
	vbo.bind();
	texture.bind();

	auto pos = Vec2f{ x, y };
	for (size_t i = 0; text[i]; i++)
	{
		auto ch = text[i];
		if (ch == '\n')
		{
			pos.x = x;
			pos.y += pixel_size;
			continue;
		}

		stbtt_aligned_quad q;
		stbtt_GetBakedQuad(cdata, Font::TEXTURE_SIZE, Font::TEXTURE_SIZE,
						   ch - 32, &pos.x, &pos.y, &q, 1);

		auto p0 = Vec2f{ q.x0, q.y0 };
		auto t0 = Vec2f{ q.s0, q.t0 };

		auto p1 = Vec2f{ q.x1, q.y0 };
		auto t1 = Vec2f{ q.s1, q.t0 };

		auto p2 = Vec2f{ q.x0, q.y1 };
		auto t2 = Vec2f{ q.s0, q.t1 };

		auto p3 = Vec2f{ q.x1, q.y1 };
		auto t3 = Vec2f{ q.s1, q.t1 };

		vbo.add(&p0, sizeof(Vec2f));
		vbo.add(&t0, sizeof(Vec2f));
		vbo.add(&p1, sizeof(Vec2f));
		vbo.add(&t1, sizeof(Vec2f));
		vbo.add(&p2, sizeof(Vec2f));
		vbo.add(&t2, sizeof(Vec2f));
		vbo.upload(GL_DYNAMIC_DRAW);
		glDrawArrays(GL_TRIANGLES, 0, 3);

		vbo.add(&p1, sizeof(Vec2f));
		vbo.add(&t1, sizeof(Vec2f));
		vbo.add(&p2, sizeof(Vec2f));
		vbo.add(&t2, sizeof(Vec2f));
		vbo.add(&p3, sizeof(Vec2f));
		vbo.add(&t3, sizeof(Vec2f));
		vbo.upload(GL_DYNAMIC_DRAW);
		glDrawArrays(GL_TRIANGLES, 0, 3);
	}

	glDisable(GL_BLEND);
	glDepthMask(1);
	glEnable(GL_DEPTH_TEST);
}

void Font::release()
{
	vbo.release();
	glDeleteVertexArrays(1, &vao);
}
