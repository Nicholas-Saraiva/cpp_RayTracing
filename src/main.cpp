#include <iostream>
#include "Tuple.hpp"
#include "Terminal.hpp"

int main() {
    rt::Tuple my_point{4.3f, -4.2f, 3.1f, 1.0f};

    std::cout << "--- Ray Tracer Initial Test ---" << std::endl;
    std::cout << "Point coordinates: (" << my_point.x << ", "
              << my_point.y << ", " << my_point.z << ")" << std::endl;

    if (my_point.is_point()) {
        std::cout << "Status: " << rt::color::GREEN << "Success! " <<
			rt::color::RESET << "The Tuple is correctly identified as a Point." << std::endl;
    } else {
        std::cout << "Status: " << rt::color::RED << "Error " <<
		rt::color::RESET << "in Tuple logic." << std::endl;
    }

    return 0;
}
