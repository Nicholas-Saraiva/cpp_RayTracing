#include <iostream>
#include "Tuple.hpp"
#include "Terminal.hpp"

int main() {
	auto my_point = rt::Tuple::point(4.3f, -4.2f, 3.1f);
	auto my_vector = rt::Tuple::vector(4.3f, -4.2f, 3.1f);

	std::cout << "--- Ray Tracer Initial Test ---" << std::endl;

	std::cout << "Point coordinates: (" << my_point.x << ", "
			  << my_point.y << ", " << my_point.z << ")" << std::endl;
	std::cout << "Vector coordinates: (" << my_vector.x << ", "
			  << my_vector.y << ", " << my_vector.z << ")" << std::endl;

	if (my_point.is_point()) {
		std::cout << "Status: " << rt::color::GREEN << "Success! " <<
			rt::color::RESET << "The Tuple is correctly identified as a Point." << std::endl;
	} else {
		std::cout << "Status: " << rt::color::RED << "Error " <<
		rt::color::RESET << "in Tuple logic." << std::endl;
	}

	if (!my_vector.is_point()) {
		std::cout << "Status: " << rt::color::GREEN << "Success! " <<
			rt::color::RESET << "The Tuple is correctly identified as a Vector." << std::endl;
	} else {
		std::cout << "Status: " << rt::color::RED << "Error " <<
		rt::color::RESET << "in Tuple logic." << std::endl;
	}

	std::cout << "--- Tuples Operations ---" << std::endl;

	auto	tup1 = rt::Tuple(3, -2, 5, 1);
	auto	tup2 = rt::Tuple(-2, 3, 1, 0);
	auto	res  = rt::Tuple(1, 1, 6, 1);

	if ((tup1 + tup2) == res) {
		std::cout << "Status: " << rt::color::GREEN << "Success! " <<
			rt::color::RESET << "The Tuple sum correctly." << std::endl;
	} else {
		std::cout << "Status: " << rt::color::RED << "Error " <<
		rt::color::RESET << "in Tuple logic." << std::endl;
	}


	return 0;
}
