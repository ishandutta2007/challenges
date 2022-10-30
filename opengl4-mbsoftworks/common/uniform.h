#ifndef _UNIFORM_H_
#define _UNIFORM_H_

class Program;

class Uniform
{
public:
	Uniform();
	Uniform(const string &name, Program *program);

	Uniform &operator=(bool val);
	void set(bool val);

	Uniform &operator=(float val);
	void set(float val);

	Uniform &operator=(int val);
	void set(int val);

	Uniform &operator=(const vector<float> &vals);
	void set(const float *vals, int count);

	Uniform &operator=(const Vec3f &vect);
	void set(const Vec3f &vect);

	Uniform &operator=(const Vec4f &vect);
	void set(const Vec4f &vect);

	Uniform &operator=(const Mat3f &matrix);
	void set(const Mat3f &matrix);

	Uniform &operator=(const Mat4f &matrix);
	void set(const Mat4f &matrix);

	string name;
	Program *program;
	int location;
};

#endif