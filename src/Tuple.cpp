#include "Tuple.hpp"

namespace RT {
    Tuple::Tuple(float x, float y, float z, float w)
        : x(x), y(y), z(z), w(w) {}

    bool Tuple::is_point() const {
        return w == 1.0f;
    }

    Tuple Tuple::operator+(const Tuple& other) const {
        return Tuple(x + other.x, y + other.y, z + other.z, w + other.w);
    }
}
