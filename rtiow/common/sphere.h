#ifndef _SPHERE_H_
#define _SPHERE_H_

struct sphere : public hittable
{
	sphere()
		: center(point3(0)), radius(0), mat_ptr(nullptr)
	{
	}

	sphere(point3 cen, double r, shared_ptr<material> m)
		: center(cen), radius(r), mat_ptr(m)
	{
	}

	bool hit(const ray &r, double t_min, double t_max, hit_record &rec) const
	{
		vec3 oc = r.origin - center;
		auto a = dot(r.direction, r.direction);
		auto half_b = dot(oc, r.direction);
		auto c = dot(oc, oc) - radius * radius;

		auto discriminant = half_b * half_b - a * c;
		if (discriminant < 0)
			return false;
		auto sqrtd = sqrt(discriminant);

		// Find the nearest root that lies in the acceptable range.
		auto root = (-half_b - sqrtd) / a;
		if (root < t_min || t_max < root)
		{
			root = (-half_b + sqrtd) / a;
			if (root < t_min || t_max < root)
				return false;
		}

		rec.t = root;
		rec.p = r.at(rec.t);
		vec3 outward_normal = (rec.p - center) / radius;
		rec.set_face_normal(r, outward_normal);
		rec.mat_ptr = mat_ptr;

		return true;
	}

	point3 center;
	double radius;
	shared_ptr<material> mat_ptr;
};

#endif