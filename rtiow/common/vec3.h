#ifndef _VEC3_H_
#define _VEC3_H_

static thread_local mt19937 rng;

inline void seed_rng()
{
	unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();
	rng.seed(seed);
}

inline double random_double(double min = 0.0, double max = 1.0)
{
	static thread_local uniform_real_distribution<double> distribution(min, max);
	return distribution(rng);
}

struct vec3
{
	double x, y, z;

	vec3()
		: x(0), y(0), z(0)
	{
	}

	vec3(double v)
		: x(v), y(v), z(v)
	{
	}

	vec3(double x, double y, double z)
		: x(x), y(y), z(z)
	{
	}

	vec3(const vec3 &v)
		: x(v.x), y(v.y), z(v.z)
	{
	}

	vec3 operator+(const vec3 &v) const
	{
		return vec3(x + v.x, y + v.y, z + v.z);
	}

	vec3 operator-(const vec3 &v) const
	{
		return vec3(x - v.x, y - v.y, z - v.z);
	}

	vec3 operator*(const vec3 &v) const
	{
		return vec3(x * v.x, y * v.y, z * v.z);
	}

	vec3 operator/(double s) const
	{
		return vec3(x / s, y / s, z / s);
	}

	vec3 &operator=(const vec3 &v)
	{
		x = v.x;
		y = v.y;
		z = v.z;
		return *this;
	}

	vec3 &operator+=(const vec3 &v)
	{
		x += v.x;
		y += v.y;
		z += v.z;
		return *this;
	}

	vec3 operator-() const
	{
		return vec3(-x, -y, -z);
	}

	bool near_zero() const
	{
		// Return true if the vector is close to zero in all dimensions.
		const auto s = 1e-8;
		return (fabs(x) < s) && (fabs(y) < s) && (fabs(z) < s);
	}
};

inline vec3 operator*(double t, const vec3 &v)
{
	return vec3(t * v.x, t * v.y, t * v.z);
}

inline vec3 operator*(const vec3 &v, double t)
{
	return t * v;
}

inline double clamp(double x, double a, double b)
{
	return min(max(x, a), b);
}

inline vec3 clamp(const vec3 &x, const vec3 &a, const vec3 &b)
{
	double cx = clamp(x.x, a.x, b.x);
	double cy = clamp(x.y, a.y, b.y);
	double cz = clamp(x.z, a.z, b.z);
	return vec3(cx, cy, cz);
}

inline double length(const vec3 &v)
{
	return sqrt(v.x * v.x + v.y * v.y + v.z * v.z);
}

inline vec3 normalize(const vec3 &v)
{
	auto l = length(v);
	if (l == 0)
		return vec3(0);
	return vec3(v.x / l, v.y / l, v.z / l);
}

inline double dot(const vec3 &a, const vec3 &b)
{
	return a.x * b.x + a.y * b.y + a.z * b.z;
}

inline vec3 cross(const vec3 &u, const vec3 &v)
{
	return vec3(u.y * v.z - u.z * v.y,
				u.z * v.x - u.x * v.z,
				u.x * v.y - u.y * v.x);
}

inline vec3 reflect(const vec3 &v, const vec3 &n)
{
	return v - 2 * dot(v, n) * n;
}

inline vec3 refract(const vec3 &uv, const vec3 &n, double etai_over_etat)
{
	auto cos_theta = fmin(dot(-uv, n), 1.0);
	vec3 r_out_perp = etai_over_etat * (uv + cos_theta * n);
	vec3 r_out_parallel = -sqrt(fabs(1.0 - dot(r_out_perp, r_out_perp))) * n;
	return r_out_perp + r_out_parallel;
}

typedef vec3 color;
typedef vec3 point3;

#endif