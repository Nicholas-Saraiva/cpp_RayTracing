#include "Color.hpp"
#include "Math.hpp"

namespace rt {
	Color::Color()
		: r(0), g(0), b(0) {}

    Color::Color(float r, float g, float b)
        : r(r), g(g), b(b) {}

	Color&	Color::operator+=(const Color& other){
		r += other.r;
		g += other.g;
		b += other.b;
		return *this;
	}

	Color	Color::operator+(const Color& other) const{
		Color	result = *this;

		result += other;
		return result;
	}

	Color&	Color::operator-=(const Color& other){
		r -= other.r;
		g -= other.g;
		b -= other.b;
		return *this;
	}

	Color	Color::operator-(const Color& other) const{
		Color	result = *this;

		result -= other;
		return result;
	}

	Color&	Color::operator*=(const Color& other){
		r *= other.r;
		g *= other.g;
		b *= other.b;
		return *this;
	}

	Color	Color::operator*(const Color& other) const{
		Color	result = *this;

		result *= other;
		return result;
	}

	Color&	Color::operator*=(const float num){
		r *= num;
		g *= num;
		b *= num;
		return *this;
	}

	Color	Color::operator*(const float num) const{
		Color	result = *this;

		result *= num;
		return result;
	}

	Color&	Color::operator/=(const float num){
		float n = 1 / num;

		r *= n;
		g *= n;
		b *= n;
		return *this;
	}

	Color	Color::operator/(const float num) const{
		Color	result = *this;

		result /= num;
		return result;
	}


	Color	Color::operator-() const{
		return Color(-r, -g, -b);
	}

	bool	Color::operator==(const Color& other) const {
		return (equal(r, other.r) &&
				equal(g, other.g) &&
				equal(b, other.b)
		);
	}
}
