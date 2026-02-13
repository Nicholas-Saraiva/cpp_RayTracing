#include "Tuple.hpp"

namespace rt {
    Tuple::Tuple(float x, float y, float z, float w)
        : x(x), y(y), z(z), w(w) {}

    bool Tuple::is_point() const {
        return w == 1.0f;
    }
}
