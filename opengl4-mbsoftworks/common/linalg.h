#ifndef _LINALG_H_
#define _LINALG_H_

template <typename T>
T lerp(T t, T a, T b)
{
	return a + t * (b - a);
}

template <typename T>
T unlerp(T t, T a, T b)
{
	return (t - a) / (b - a);
}

template <typename T>
T linear_remap(T x, T a, T b, T c, T d)
{
	return lerp(unlerp(x, a, b), c, d);
}

template <typename T>
T clamp(T x, T a, T b)
{
	if (x < a)
		x = a;
	else if (x > b)
		x = b;
	return x;
}

template <typename T>
T degrees(T rad)
{
	return rad * 180 / M_PI;
}

template <typename T>
T radians(T deg)
{
	return deg / 180 * M_PI;
}

template <typename T>
struct Vec2
{
	union
	{
		struct
		{
			T x, y;
		};
		struct
		{
			T s, t;
		};
	};

	Vec2()
		: x(0), y(0)
	{
	}

	Vec2(T v)
		: x(v), y(v)
	{
	}

	Vec2(T x, T y)
		: x(x), y(y)
	{
	}

	Vec2 operator+(Vec2 v)
	{
		return { x + v.x, y + v.y };
	}

	Vec2 operator-()
	{
		return { -x, -y };
	}

	Vec2 operator-(Vec2 v)
	{
		return { x - v.x, y - v.y };
	}

	Vec2 operator*(T s)
	{
		return { x * s, y * s };
	}

	Vec2 &operator*=(T s)
	{
		*this = { x * s, y * s };
		return *this;
	}

	static Vec2 perp(Vec2 v)
	{
		return { -v.y, v.x };
	}

	static T length(Vec2 v)
	{
		return sqrt(v.x * v.x + v.y * v.y);
	}

	static Vec2 normalize(Vec2 v)
	{
		auto l = length(v);
		return { v.x / l, v.y / l };
	}

	static T dot(Vec2 a, Vec2 b)
	{
		return a.x * b.x + a.y * b.y;
	}

	static T distance(Vec2 a, Vec2 b)
	{
		return length(a - b);
	}
};

template <typename T>
struct Vec3
{
	union
	{
		struct
		{
			T x, y, z;
		};
		struct
		{
			T r, g, b;
		};
	};

	Vec3()
		: x(0), y(0), z(0)
	{
	}

	Vec3(T v)
		: x(v), y(v), z(v)
	{
	}

	Vec3(T x, T y, T z)
		: x(x), y(y), z(z)
	{
	}

	Vec3 operator-()
	{
		return { -x, -y, -z };
	}

	Vec3 operator+(Vec3 v)
	{
		return { x + v.x, y + v.y, z + v.z };
	}

	Vec3 operator-(Vec3 v)
	{
		return { x - v.x, y - v.y, z - v.z };
	}

	Vec3 operator*(T s)
	{
		return { x * s, y * s, z * s };
	}

	Vec3 &operator+=(Vec3 v)
	{
		*this = { x + v.x, y + v.y, z + v.z };
		return *this;
	}

	Vec3 &operator-=(Vec3 v)
	{
		*this = { x - v.x, y - v.y, z - v.z };
		return *this;
	}

	Vec3 &operator*=(T s)
	{
		*this = { x * s, y * s, z * s };
		return *this;
	}

	static T length(Vec3 v)
	{
		return sqrt(v.x * v.x + v.y * v.y + v.z * v.z);
	}

	static Vec3 normalize(Vec3 v)
	{
		auto l = length(v);
		return { v.x / l, v.y / l, v.z / l };
	}

	static T dot(Vec3 a, Vec3 b)
	{
		return a.x * b.x + a.y * b.y + a.z * b.z;
	}

	static Vec3 cross(Vec3 a, Vec3 b)
	{
		return {
			a.y * b.z - a.z * b.y,
			a.z * b.x - a.x * b.z,
			a.x * b.y - a.y * b.x
		};
	}

	static T distance(Vec3 a, Vec3 b)
	{
		return length(a - b);
	}
};

template <typename T>
struct Vec4
{
	union
	{
		struct
		{
			T x, y, z, w;
		};
		struct
		{
			T r, g, b, a;
		};
	};

	Vec4()
		: x(0), y(0), z(0), w(0)
	{
	}

	Vec4(T x, T y, T z, T w)
		: x(x), y(y), z(z), w(w)
	{
	}

	Vec4(Vec3<T> v, T w)
		: x(v.x), y(v.y), z(v.z), w(w)
	{
	}

	Vec4 operator+(Vec4 v)
	{
		return { x + v.x, y + v.y, z + v.z, w + v.w };
	}

	Vec4 operator-(Vec4 v)
	{
		return { x - v.x, y - v.y, z - v.z, w - v.w };
	}

	Vec4 operator-()
	{
		return { -x, -y, -z, -w };
	}

	Vec4 operator*(T s)
	{
		return { x * s, y * s, z * s, w * s };
	}

	Vec4 operator*(Vec4 v)
	{
		return { x * v.x, y * v.y, z * v.z, w * v.w };
	}

	Vec4 &operator*=(T s)
	{
		*this = { x * s, y * s, z * s, w * s };
		return *this;
	}

	Vec4 &operator*=(Vec4 v)
	{
		*this = { x * v.x, y * v.y, z * v.z, w * v.w };
		return *this;
	}

	Vec3<T> xyz()
	{
		return { x, y, z };
	}
};

template <typename T>
struct Mat3
{
	T m[3][3];

	T *operator[](int i)
	{
		return m[i];
	}

	Mat3 operator*(const Mat3 &mat) const
	{
		Mat3 p = {};
		for (auto i = 0; i < 3; i++)
			for (auto j = 0; j < 3; j++)
				for (auto k = 0; k < 3; k++)
					p[i][j] += m[i][k] * mat.m[k][j];
		return p;
	}

	Mat3 &operator*=(const Mat3 &mat)
	{
		*this = *this * mat;
		return *this;
	}

	Vec3<T> operator*(Vec3<T> vec)
	{
		return Vec3<T>{
			m[0][0] * vec.x + m[0][1] * vec.y + m[0][2] * vec.z,
			m[1][0] * vec.x + m[1][1] * vec.y + m[1][2] * vec.z,
			m[2][0] * vec.x + m[2][1] * vec.y + m[2][2] * vec.z,
		};
	}

	char *string(char *buf) const
	{
		auto l = 0;
		for (auto i = 0; i < 3; i++)
			l += sprintf(buf + l, "%.3f %.3f %.3f\n", m[i][0], m[i][1], m[i][2]);
		return buf;
	}

	static Mat3 transpose(const Mat3 &mat)
	{
		Mat3 p = {};
		for (auto i = 0; i < 3; i++)
			for (auto j = 0; j < 3; j++)
				p[j][i] = mat.m[i][j];
		return p;
	}

	static Mat3 inverse(const Mat3 &mat)
	{
		auto det = mat.m[0][0] * (mat.m[1][1] * mat.m[2][2] - mat.m[2][1] * mat.m[1][2]) -
				   mat.m[0][1] * (mat.m[1][0] * mat.m[2][2] - mat.m[1][2] * mat.m[2][0]) +
				   mat.m[0][2] * (mat.m[1][0] * mat.m[2][1] - mat.m[1][1] * mat.m[2][0]);
		auto invdet = 0.0;
		if (det != 0)
			invdet = 1.0 / det;

		Mat3 minv;
		minv[0][0] = (mat.m[1][1] * mat.m[2][2] - mat.m[2][1] * mat.m[1][2]) * invdet;
		minv[0][1] = (mat.m[0][2] * mat.m[2][1] - mat.m[0][1] * mat.m[2][2]) * invdet;
		minv[0][2] = (mat.m[0][1] * mat.m[1][2] - mat.m[0][2] * mat.m[1][1]) * invdet;
		minv[1][0] = (mat.m[1][2] * mat.m[2][0] - mat.m[1][0] * mat.m[2][2]) * invdet;
		minv[1][1] = (mat.m[0][0] * mat.m[2][2] - mat.m[0][2] * mat.m[2][0]) * invdet;
		minv[1][2] = (mat.m[1][0] * mat.m[0][2] - mat.m[0][0] * mat.m[1][2]) * invdet;
		minv[2][0] = (mat.m[1][0] * mat.m[2][1] - mat.m[2][0] * mat.m[1][1]) * invdet;
		minv[2][1] = (mat.m[2][0] * mat.m[0][1] - mat.m[0][0] * mat.m[2][1]) * invdet;
		minv[2][2] = (mat.m[0][0] * mat.m[1][1] - mat.m[1][0] * mat.m[0][1]) * invdet;
		return minv;
	}
};

template <typename T>
struct Mat4
{
	T m[4][4];

	T *operator[](int i)
	{
		return m[i];
	}

	Mat4 operator*(const Mat4 &mat) const
	{
		Mat4 p = {};
		for (auto i = 0; i < 4; i++)
			for (auto j = 0; j < 4; j++)
				for (auto k = 0; k < 4; k++)
					p[i][j] += m[i][k] * mat.m[k][j];
		return p;
	}

	Mat4 &operator*=(const Mat4 &mat)
	{
		*this = *this * mat;
		return *this;
	}

	Vec3<T> operator*(Vec3<T> vec) const
	{
		return Vec3<T>{
			m[0][0] * vec.x + m[0][1] * vec.y + m[0][2] * vec.z + m[0][3],
			m[1][0] * vec.x + m[1][1] * vec.y + m[1][2] * vec.z + m[1][3],
			m[2][0] * vec.x + m[2][1] * vec.y + m[2][2] * vec.z + m[2][3],
		};
	}

	Vec4<T> operator*(Vec4<T> vec) const
	{
		return Vec4<T>{
			m[0][0] * vec.x + m[0][1] * vec.y + m[0][2] * vec.z + m[0][3] * vec.w,
			m[1][0] * vec.x + m[1][1] * vec.y + m[1][2] * vec.z + m[1][3] * vec.w,
			m[2][0] * vec.x + m[2][1] * vec.y + m[2][2] * vec.z + m[2][3] * vec.w,
			m[3][0] * vec.x + m[3][1] * vec.y + m[3][2] * vec.z + m[3][3] * vec.w,
		};
	}

	char *string(char *buf) const
	{
		auto l = 0;
		for (auto i = 0; i < 4; i++)
			l += sprintf(buf + l, "%.3f %.3f %.3f %.3f\n", m[i][0], m[i][1], m[i][2], m[i][3]);
		return buf;
	}

	static Mat3<T> mat3(const Mat4 &mat)
	{
		return Mat3<T>{ {
			{ mat.m[0][0], mat.m[0][1], mat.m[0][2] },
			{ mat.m[1][0], mat.m[1][1], mat.m[1][2] },
			{ mat.m[2][0], mat.m[2][1], mat.m[2][2] },
		} };
	}

	static Mat4 transpose(const Mat4 &mat)
	{
		Mat4 p = {};
		for (auto i = 0; i < 4; i++)
			for (auto j = 0; j < 4; j++)
				p[j][i] = mat.m[i][j];
		return p;
	}

	static Mat4 eye(T val)
	{
		return Mat4{ {
			{ val, 0, 0, 0 },
			{ 0, val, 0, 0 },
			{ 0, 0, val, 0 },
			{ 0, 0, 0, val },
		} };
	}

	static Mat4 translate(const Mat4 &mat, Vec3<T> off)
	{
		auto xfm = Mat4{ {
			{ 1, 0, 0, off.x },
			{ 0, 1, 0, off.y },
			{ 0, 0, 1, off.z },
			{ 0, 0, 0, 1 },
		} };
		return mat * xfm;
	}

	static Mat4 scale(const Mat4 &mat, Vec3<T> scale)
	{
		auto xfm = Mat4{ {
			{ scale.x, 0, 0, 0 },
			{ 0, scale.y, 0, 0 },
			{ 0, 0, scale.z, 0 },
			{ 0, 0, 0, 1 },
		} };
		return mat * xfm;
	}

	// https://mathworld.wolfram.com/RodriguesRotationFormula.html
	static Mat4 rotate(const Mat4 &mat, T rad, Vec3<T> axis)
	{
		auto c = cos(rad);
		auto s = sin(rad);
		auto w = Vec3<T>::normalize(axis);
		auto xfm = Mat4{};
		xfm[0][0] = c + w.x * w.x * (1 - c);
		xfm[0][1] = w.x * w.y * (1 - c) - w.z * s;
		xfm[0][2] = w.y * s + w.x * w.z * (1 - c);
		xfm[1][0] = w.z * s + w.x * w.y * (1 - c);
		xfm[1][1] = c + w.y * w.y * (1 - c);
		xfm[1][2] = -w.x * s + w.y * w.z * (1 - c);
		xfm[2][0] = -w.y * s + w.x * w.z * (1 - c);
		xfm[2][1] = w.x * s + w.y * w.z * (1 - c);
		xfm[2][2] = c + w.z * w.z * (1 - c);
		xfm[3][3] = 1;
		return mat * xfm;
	}

	static Mat4 shear(const Mat4 &mat, Vec3<T> axis)
	{
		auto xfm = Mat4{ {
			{ 1, 0, 0, 0 },
			{ axis.x, 1, 0, 0 },
			{ axis.y, axis.z, 1, 0 },
			{ 0, 0, 0, 1 },
		} };
		return mat * xfm;
	}

	static Mat4 ortho(T left, T right, T bottom, T top, T near, T far)
	{
		auto sx = 2 / (right - left);
		auto sy = 2 / (top - bottom);
		auto sz = -2 / (far - near);
		auto tx = -(right + left) / (right - left);
		auto ty = -(top + bottom) / (top - bottom);
		auto tz = -(far + near) / (far - near);
		auto mat = Mat4{ {
			{ sx, 0, 0, tx },
			{ 0, sy, 0, ty },
			{ 0, 0, sz, tz },
			{ 0, 0, 0, 1 },
		} };
		return mat;
	}

	static Mat4 perspective(T fovy, T aspect, T znear, T zfar)
	{
		float f = 1 / tan(fovy / 2);
		auto sx = f / aspect;
		auto sy = f;
		auto sz = (zfar + znear) / (znear - zfar);
		auto tz = 2 * zfar * znear / (znear - zfar);
		auto mat = Mat4{ {
			{ sx, 0, 0, 0 },
			{ 0, sy, 0, 0 },
			{ 0, 0, sz, tz },
			{ 0, 0, -1, 0 },
		} };
		return mat;
	}

	static Mat4 lookAt(Vec3<T> eye, Vec3<T> center, Vec3<T> up)
	{
		auto f = Vec3<T>::normalize(center - eye);
		auto u = Vec3<T>::normalize(up);
		auto s = Vec3<T>::cross(f, u);
		s = Vec3<T>::normalize(s);
		u = Vec3<T>::cross(s, f);
		auto mat = Mat4{ {
			{ s.x, s.y, s.z, 0 },
			{ u.x, u.y, u.z, 0 },
			{ -f.x, -f.y, -f.z, 0 },
			{ 0, 0, 0, 1 },
		} };
		return translate(mat, -eye);
	}
};

typedef Vec2<int> Vec2i;
typedef Vec2<float> Vec2f;
typedef Vec3<float> Vec3f;
typedef Vec4<float> Vec4f;
typedef Mat3<float> Mat3f;
typedef Mat4<float> Mat4f;

#endif
