#pragma once

namespace rt {
	class	Tuple{
	public:
		float x, y, z, w;
		Tuple(float x, float y, float z, float w);

		static Tuple	point(float x, float y, float z);
		static Tuple	vector(float x, float y, float z);

		bool	is_point() const;
		Tuple	operator+(const Tuple& other) const;
	};
}
