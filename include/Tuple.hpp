#pragma once

namespace rt {
	class	Tuple{
	public:
		float	x, y, z, w;
		Tuple() = default;
		Tuple(float x, float y, float z, float w);
		Tuple(const float (&v)[4]);

		static	Tuple	point(float x, float y, float z);
		static	Tuple	vector(float x, float y, float z);
		static	Tuple	cross(const Tuple& a, const Tuple& b);
		static	float	dot(const Tuple& a, const Tuple& b);

		bool	is_point() const;
		float	magnitude() const;
		Tuple	normalize()	const;

		Tuple	operator+(const Tuple& other) const;
		Tuple	operator-(const Tuple& other) const;
		Tuple	operator*(const float num) const;
		Tuple	operator/(const float num) const;
		Tuple	operator-() const;
		Tuple&	operator+=(const Tuple& other);
		Tuple&	operator-=(const Tuple& other);
		Tuple&	operator*=(const float num);
		Tuple&	operator/=(const float num);
		bool	operator==(const Tuple& other) const;
	};
}
