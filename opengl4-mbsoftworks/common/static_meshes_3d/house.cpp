#include "lib.h"

House::~House()
{
	cube.release();
	pyramid.release();
	release();
}

void House::init(bool has_positions, bool has_texcoords, bool has_normals)
{
	StaticMesh3D::init(has_positions, has_texcoords, has_normals);
	cube.init(has_positions, has_texcoords, has_normals);
	pyramid.init(has_positions, has_texcoords, has_normals);

	static once_flag once;
	call_once(once, [&]() {
		auto &tm = TextureManager::get_instance();
		tm.add_texture("house_walls", "data/textures/brick.png");
		tm.add_texture("house_door_wall", "data/textures/tut008/house_texture_front.png");
		tm.add_texture("house_windows_wall", "data/textures/tut008/house_texture_side.png");
		tm.add_texture("house_roof", "data/textures/prismarine_dark.png");
	});
}

void House::render()
{
	render({ 0.0f, 0.0f, 0.0f }, 0.0f);
}

void House::render(Vec3f position, float rotation_angle)
{
	auto &sm = ShaderManager::get_instance();
	auto &tm = TextureManager::get_instance();

	auto &main_program = sm.programs["main"];
	auto &walls_texture = tm.textures["house_walls"];
	auto &door_wall_texture = tm.textures["house_door_wall"];
	auto &windows_wall_texture = tm.textures["house_windows_wall"];
	auto &roof_texture = tm.textures["house_roof"];

	auto house_bottom_size = 10.0f;
	auto rooftop_size = 12.0f;
	// First, calculate the basic position of house
	auto model_matrix_house = Mat4f::eye(1.0);
	model_matrix_house = Mat4f::translate(model_matrix_house, position);

	// Render bottom cube of the house
	auto model_matrix_bottom = Mat4f::translate(model_matrix_house, { 0.0f, house_bottom_size / 2.0f, 0.0f });
	model_matrix_bottom = Mat4f::rotate(model_matrix_bottom, rotation_angle, { 0.0f, 1.0f, 0.0f });
	model_matrix_bottom = Mat4f::scale(model_matrix_bottom, { house_bottom_size, house_bottom_size, house_bottom_size });
	main_program["matrices.modelMatrix"] = model_matrix_bottom;

	// Render just plain house walls made of bricks
	walls_texture.bind();
	cube.render_faces(Cube::BACK_FACE | Cube::TOP_FACE);
	// Render house wall with a door and windows
	door_wall_texture.bind();
	cube.render_faces(Cube::FRONT_FACE);
	// Render house wall with a window
	windows_wall_texture.bind();
	cube.render_faces(Cube::LEFT_FACE | Cube::RIGHT_FACE);

	roof_texture.bind();
	auto translate_top_y = house_bottom_size + rooftop_size / 2.0f - 0.25f;
	auto model_matrix_top = Mat4f::translate(model_matrix_house, { 0.0f, translate_top_y, 0.0f });
	model_matrix_top = Mat4f::rotate(model_matrix_top, rotation_angle, { 0.0f, 1.0f, 0.0f });
	model_matrix_top = Mat4f::scale(model_matrix_top, { rooftop_size, rooftop_size, rooftop_size });
	main_program["matrices.modelMatrix"] = model_matrix_top;
	pyramid.render();
}