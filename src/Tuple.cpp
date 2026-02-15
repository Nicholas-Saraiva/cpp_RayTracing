#include "Tuple.hpp"
#include "Math.hpp"

namespace rt {
    Tuple::Tuple(float x, float y, float z, float w)
        : x(x), y(y), z(z), w(w) {}

	Tuple	Tuple::point(float x, float y, float z) {
		return (Tuple(x, y, z, 1.0f));
	}

	Tuple	Tuple::vector(float x, float y, float z) {
		return (Tuple(x, y, z, 0.0f));
	}

    bool Tuple::is_point() const {
        return equal(w, 1.0f);
    }

	Tuple&	Tuple::operator+=(const Tuple& other){
		x += other.x;
		y += other.y;
		z += other.z;
		w += other.w;
		return *this;
	}

	Tuple	Tuple::operator+(const Tuple& other) const{
		Tuple	result = *this;

		result += other;
		return result;
	}

	Tuple&	Tuple::operator-=(const Tuple& other){
		x -= other.x;
		y -= other.y;
		z -= other.z;
		w -= other.w;
		return *this;
	}

	Tuple	Tuple::operator-(const Tuple& other) const{
		Tuple	result = *this;

		result -= other;
		return result;
	}

	bool	Tuple::operator==(const Tuple& other) const {
		return (x == other.x &&
				y == other.y &&
				z == other.z &&
				w == other.w
		);
	}

}
