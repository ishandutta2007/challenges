#ifndef _STATIC_GEOMETRY_H_
#define _STATIC_GEOMETRY_H_

namespace static_geometry
{
// A simple cube with unit size
extern Vec3f cube_vertices[36];
extern Vec2f cube_texcoords[6];
extern Vec3f cube_face_colors[6];

// A simple pyramid with unit size
extern Vec3f pyramid_vertices[12];
extern Vec2f pyramid_texcoords[3];
extern Vec3f pyramid_face_colors[3];

// Ground, that has greenish color
extern Vec3f plain_ground_vertices[4];
extern Vec2f plain_ground_texcoords[4];
extern Vec3f plain_ground_colors[4];

// 2D quad of unit size, anchored in lower-left point (same as texture coordinates, render with triangle strip)
extern Vec2f quad2D[4];
}; // namespace static_geometry

#endif