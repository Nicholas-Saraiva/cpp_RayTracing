#include "Ray.hpp"
#include <math.h>

namespace rt
{
	Ray::Ray()
		: origin(Tuple()), direction(Tuple()) {}

	Ray::Ray(const Tuple& origin, const Tuple& direction)
		: origin(origin), direction(direction) {}

	Tuple	Ray::position(const Ray& r, const float t) {
		return (r.origin + r.direction * t);
	}

	Instersections	Ray::intersect(const Object &obj, const Ray &r) {
		Ray		new_ray = transform(r, obj.inv_transform);
		Tuple	sphere_to_ray = new_ray.origin - Tuple::point(0, 0 ,0);
		float	a = Tuple::dot(new_ray.direction, new_ray.direction);
		float	b = 2 * Tuple::dot(new_ray.direction, sphere_to_ray);
		float	c = Tuple::dot(sphere_to_ray, sphere_to_ray) - 1;
		float	discriminant = (b * b) - (4 * a * c);

		if (discriminant < 0) return (Instersections());
		float t1 = (-b - std::sqrtf(discriminant)) / (2 * a);
		float t2 = (-b + std::sqrtf(discriminant)) / (2 * a);

		auto inter1 = Intersection(t1, &obj);
		auto inter2 = Intersection(t2, &obj);

		return (Instersections(inter1, inter2));
	}

	Intersection	Ray::hit(const Instersections& inter) {
		auto	hit = Intersection(0, nullptr);

		for (const auto& i : inter.t) {
			if (i.t > 0 && (hit.obj == nullptr || i.t < hit.t)) {
				hit = i;
			}
		}
		return hit;
	}

	Ray	Ray::transform(const Ray& r, const Matrix& transform) {
		Tuple new_origin = Matrix::multiply_tuple(transform, r.origin);
		Tuple new_direction = Matrix::multiply_tuple(transform, r.direction);
		return Ray(new_origin, new_direction);
	}
}
