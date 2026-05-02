#pragma once

namespace rt {
	class Color {
	public:
		float	r,g,b;

		Color();
		Color(float r, float g, float b);


		Color	operator+(const Color& other) const;
		Color	operator-(const Color& other) const;
		Color	operator*(const Color& other) const;
		Color	operator*(const float num) const;
		Color	operator/(const float num) const;
		Color	operator-() const;
		Color&	operator+=(const Color& other);
		Color&	operator-=(const Color& other);
		Color&	operator*=(const Color& other);
		Color&	operator*=(const float num);
		Color&	operator/=(const float num);
		Color&	operator=(const Color& other) = default;
		bool	operator==(const Color& other) const;
	};
}
