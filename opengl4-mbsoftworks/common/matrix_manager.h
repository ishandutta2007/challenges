#ifndef _MATRIX_MANAGER_H_
#define _MATRIX_MANAGER_H_

class MatrixManager
{
public:
	static MatrixManager &get_instance();

	Mat4f ortho, proj, view, orthoyn;
};

#endif