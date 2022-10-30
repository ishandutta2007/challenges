#ifndef _HITTABLE_LIST_H_
#define _HITTABLE_LIST_H_

struct hittable_list : public hittable
{
	hittable_list()
	{
	}
	hittable_list(shared_ptr<hittable> object)
	{
		add(object);
	}

	void clear()
	{
		objects.clear();
	}

	void add(shared_ptr<hittable> object)
	{
		objects.push_back(object);
	}

	virtual bool hit(const ray &r, double t_min, double t_max, hit_record &rec) const override
	{
		hit_record temp_rec;
		bool hit_anything = false;
		auto closest_so_far = t_max;

		for (const auto &object : objects)
		{
			if (object->hit(r, t_min, closest_so_far, temp_rec))
			{
				hit_anything = true;
				closest_so_far = temp_rec.t;
				rec = temp_rec;
			}
		}

		return hit_anything;
	}

public:
	vector<shared_ptr<hittable> > objects;
};

#endif
