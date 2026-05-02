#pragma once
#include <cmath>

namespace rt {
	const float	EPSILON = 0.00001f;

	inline bool	equal(float a, float b) {
		return (std::abs(a - b) < EPSILON);
	}
}
