#include "lib.h"

MatrixManager &MatrixManager::get_instance()
{
	static MatrixManager matrix_manager;
	return matrix_manager;
}