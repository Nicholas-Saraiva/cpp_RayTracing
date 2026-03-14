#pragma once
#include "Tuple.hpp"
#include "Object.hpp"
#include "Matrix.hpp"
#include "Intersection.hpp"
#include <vector>

namespace rt {

	class Ray {
	public :
		Tuple	origin;
		Tuple	direction;

		Ray();
		Ray(const Tuple& origin, const Tuple& direction);

		static Tuple			position(const Ray& r, const float t);
		static Instersections	intersect(const Object& obj, const Ray& r);
		static Ray				transform(const Ray& r, const Matrix& transform);
	};
}
