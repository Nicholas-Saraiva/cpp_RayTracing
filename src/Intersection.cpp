#include "Intersection.hpp"

namespace rt
{
	Intersection Instersections::hit() const
	{
		auto	hit = Intersection(0, nullptr);

		for (const auto& i : this->t) {
			if (i.t > 0 && (hit.obj == nullptr || i.t < hit.t)) {
				hit = i;
			}
		}
		return hit;
	}
}
