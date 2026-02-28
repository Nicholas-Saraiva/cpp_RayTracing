#pragma once
#include "Tuple.hpp"
#include "Object.hpp"
#include "Matrix.hpp"
#include <vector>

namespace rt {
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
	};

	class Ray {
	public :
		Tuple	origin;
		Tuple	direction;

		Ray();
		Ray(const Tuple& origin, const Tuple& direction);

		static Tuple			position(const Ray& r, const float t);
		static Instersections	intersect(const Object& obj, const Ray& r);
		static Intersection		hit(const Instersections& inter);
		static Ray				transform(const Ray& r, const Matrix& transform);
	};
}
