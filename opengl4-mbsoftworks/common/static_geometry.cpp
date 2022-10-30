#include "lib.h"

Vec3f static_geometry::cube_vertices[36] = {
	// Front face
	{ -0.5f, 0.5f, 0.5f },
	{ 0.5f, 0.5f, 0.5f },
	{ 0.5f, -0.5f, 0.5f },
	{ 0.5f, -0.5f, 0.5f },
	{ -0.5f, -0.5f, 0.5f },
	{ -0.5f, 0.5f, 0.5f },
	// Back face
	{ 0.5f, 0.5f, -0.5f },
	{ -0.5f, 0.5f, -0.5f },
	{ -0.5f, -0.5f, -0.5f },
	{ -0.5f, -0.5f, -0.5f },
	{ 0.5f, -0.5f, -0.5f },
	{ 0.5f, 0.5f, -0.5f },
	// Left face
	{ -0.5f, 0.5f, -0.5f },
	{ -0.5f, 0.5f, 0.5f },
	{ -0.5f, -0.5f, 0.5f },
	{ -0.5f, -0.5f, 0.5f },
	{ -0.5f, -0.5f, -0.5f },
	{ -0.5f, 0.5f, -0.5f },
	// Right face
	{ 0.5f, 0.5f, 0.5f },
	{ 0.5f, 0.5f, -0.5f },
	{ 0.5f, -0.5f, -0.5f },
	{ 0.5f, -0.5f, -0.5f },
	{ 0.5f, -0.5f, 0.5f },
	{ 0.5f, 0.5f, 0.5f },
	// Top face
	{ -0.5f, 0.5f, -0.5f },
	{ 0.5f, 0.5f, -0.5f },
	{ 0.5f, 0.5f, 0.5f },
	{ 0.5f, 0.5f, 0.5f },
	{ -0.5f, 0.5f, 0.5f },
	{ -0.5f, 0.5f, -0.5f },
	// Bottom face
	{ -0.5f, -0.5f, 0.5f },
	{ 0.5f, -0.5f, 0.5f },
	{ 0.5f, -0.5f, -0.5f },
	{ 0.5f, -0.5f, -0.5f },
	{ -0.5f, -0.5f, -0.5f },
	{ -0.5f, -0.5f, 0.5f },
};

Vec2f static_geometry::cube_texcoords[6] = {
	{ 0.0f, 1.0f },
	{ 1.0f, 1.0f },
	{ 1.0f, 0.0f },
	{ 1.0f, 0.0f },
	{ 0.0f, 0.0f },
	{ 0.0f, 1.0f },
};

Vec3f static_geometry::cube_face_colors[6] = {
	{ 1.0f, 0.0f, 0.0f },
	{ 0.0f, 1.0f, 0.0f },
	{ 0.0f, 0.0f, 1.0f },
	{ 0.0f, 0.0f, 1.0f },
	{ 1.0f, 1.0f, 0.0f },
	{ 1.0f, 0.0f, 0.0f },
};

Vec3f static_geometry::pyramid_vertices[12] = {
	// Front face
	{ 0.0f, 0.5f, 0.0f },
	{ -0.5f, -0.5f, 0.5f },
	{ 0.5f, -0.5f, 0.5f },
	// Back face
	{ 0.0f, 0.5f, 0.0f },
	{ 0.5f, -0.5f, -0.5f },
	{ -0.5f, -0.5f, -0.5f },
	// Left face
	{ 0.0f, 0.5f, 0.0f },
	{ -0.5f, -0.5f, -0.5f },
	{ -0.5f, -0.5f, 0.5f },
	// Right face
	{ 0.0f, 0.5f, 0.0f },
	{ 0.5f, -0.5f, 0.5f },
	{ 0.5f, -0.5f, -0.5f },
};

Vec2f static_geometry::pyramid_texcoords[3] = {
	{ 0.5f, 1.0f },
	{ 0.0f, 0.0f },
	{ 1.0f, 0.0f },
};

Vec3f static_geometry::pyramid_face_colors[3] = {
	{ 1.0f, 1.0f, 0.0f },
	{ 0.25f, 0.0f, 0.5f },
	{ 0.0f, 1.0f, 0.0f },
};

// Render using triangle strip!
Vec3f static_geometry::plain_ground_vertices[4] = {
	{ -200.0f, 0.0f, -200.0f }, // Left-back point
	{ -200.0f, 0.0f, 200.0f }, // Left-front point
	{ 200.0f, 0.0f, -200.0f }, // Right-back point
	{ 200.0f, 0.0f, 200.0f }, // Right-front point
};

Vec2f static_geometry::plain_ground_texcoords[4] = {
	{ 0.0f, 20.0f },
	{ 0.0f, 0.0f },
	{ 20.0f, 20.0f },
	{ 20.0f, 0.0f },
};

Vec3f static_geometry::plain_ground_colors[4] = {
	{ 0.0f, 0.5f, 0.0f },
	{ 0.0f, 0.85f, 0.0f },
	{ 0.0f, 0.35f, 0.25f },
	{ 0.0f, 0.8f, 0.2f },
};

// Render using triangle strip!
Vec2f static_geometry::quad2D[4] = {
	{ 0, 1 }, // Top-left point
	{ 0, 0 }, // Bottom-left point
	{ 1, 1 }, // Top-right point
	{ 1, 0 }, // Bottom-right point
};