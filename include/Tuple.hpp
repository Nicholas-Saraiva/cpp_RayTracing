#pragma once

namespace RT {
	class	Tuple{
	public:
		float x, y, z, w;

		Tuple(float x, float y, float z, float w);

		bool	is_point() const;
		Tuple	operator+(const Tuple& other) const;
	};
}
