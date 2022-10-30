#ifndef _LIB_H_
#define _LIB_H_

#define GL_GLEXT_PROTOTYPES

#include <cstdint>
#include <cinttypes>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <climits>
#include <vector>
#include <fstream>
#include <sstream>
#include <map>
#include <deque>
#include <string>
#include <functional>
#include <mutex>
#include <random>

#include <SDL.h>
#include <SDL_opengl.h>
#include <SDL_opengl_glext.h>

#include <assimp/Importer.hpp>
#include <assimp/scene.h>
#include <assimp/postprocess.h>

#include "stb_truetype.h"
#include "stb_image.h"

using namespace std;

#define nelem(x) (sizeof(x) / sizeof(x[0]))

#include "linalg.h"
#include "glwindow.h"
#include "shader.h"
#include "uniform.h"
#include "program.h"
#include "vbo.h"
#include "ubo.h"
#include "util.h"
#include "static_geometry.h"
#include "simple_walking_camera.h"
#include "flying_camera.h"
#include "orbit_camera.h"
#include "texture.h"
#include "sampler.h"
#include "shader_manager.h"
#include "texture_manager.h"
#include "sampler_manager.h"
#include "matrix_manager.h"
#include "transform_feedback_particle_system.h"

#include "shader_structs/shader_structs.h"
#include "shader_structs/ambient_light.h"
#include "shader_structs/diffuse_light.h"
#include "shader_structs/point_light.h"
#include "shader_structs/point_light_extended.h"
#include "shader_structs/material.h"
#include "shader_structs/fog_parameters.h"

#include "static_meshes_3d/static_mesh_3d.h"
#include "static_meshes_3d/static_mesh_indexed_3d.h"
#include "static_meshes_3d/primitives/cube.h"
#include "static_meshes_3d/primitives/pyramid.h"
#include "static_meshes_3d/primitives/torus.h"
#include "static_meshes_3d/primitives/cylinder.h"
#include "static_meshes_3d/primitives/cone.h"
#include "static_meshes_3d/primitives/sphere.h"
#include "static_meshes_3d/plain_ground.h"
#include "static_meshes_3d/snow_covered_ground.h"
#include "static_meshes_3d/house.h"
#include "static_meshes_3d/heightmap.h"
#include "static_meshes_3d/heightmap_with_fog.h"
#include "static_meshes_3d/skybox.h"
#include "static_meshes_3d/snow_covered_plain_ground.h"

#include "static_meshes_2d/static_mesh_2d.h"
#include "static_meshes_2d/primitives/quad.h"

#include "transform_feedback/fire_particle_system.h"
#include "transform_feedback/snow_particle_system.h"

#include "model.h"
#include "hud.h"
#include "font.h"
#include "font_manager.h"
#include "tga.h"
#include "string_utils.h"

#endif
