#pragma once
#include <cmath>

namespace rt {
	const float	EPSILON = 0.000001f;

	inline bool	equal(float a, float b) {
		return (std::abs(a - b) < EPSILON);
	}
}
