#pragma once
#include "Object.hpp"

namespace rt
{
	struct  Intersection
	{
		float			t;
		const Object*	obj;

		Intersection(float t, const Object* obj)
			: t(t), obj(obj) {}

		bool operator<(const Intersection& other) const {
			return (this->t < other.t);
		}
	};

	struct	Instersections
	{
		std::vector<Intersection>	t;

		Instersections() = default;
		Instersections(Intersection i1, Intersection i2)
			: t{i1, i2} {}

		Intersection	hit() const;
	};
}
