#include <iostream>
#include "Tuple.hpp"
#include "Terminal.hpp"
#include "Math.hpp"
#include "Color.hpp"
#include <cmath>

int main() {
	auto my_point = rt::Tuple::point(4.3f, -4.2f, 3.1f);
	auto my_vector = rt::Tuple::vector(4.3f, -4.2f, 3.1f);

	std::cout << "--- Ray Tracer Initial Test ---" << std::endl;

	std::cout << "Point coordinates: (" << my_point.x << ", "
			  << my_point.y << ", " << my_point.z << ")" << std::endl;
	std::cout << "Vector coordinates: (" << my_vector.x << ", "
			  << my_vector.y << ", " << my_vector.z << ")" << std::endl;

	if (my_point.is_point()) {
		std::cout << "Status: " << rt::term::GREEN << "Success! " <<
			rt::term::RESET << "The Tuple is correctly identified as a Point." << std::endl;
	} else {
		std::cout << "Status: " << rt::term::RED << "Error " <<
		rt::term::RESET << "in Tuple logic." << std::endl;
	}

	if (!my_vector.is_point()) {
		std::cout << "Status: " << rt::term::GREEN << "Success! " <<
			rt::term::RESET << "The Tuple is correctly identified as a Vector." << std::endl;
	} else {
		std::cout << "Status: " << rt::term::RED << "Error " <<
		rt::term::RESET << "in Tuple logic." << std::endl;
	}

	std::cout << "\n--- Tuples Operations ---" << std::endl;

	auto	tup1 = rt::Tuple(3, -2, 5, 1);
	auto	tup2 = rt::Tuple(-2, 3, 1, 0);
	auto	res  = rt::Tuple(1, 1, 6, 1);

	if ((tup1 + tup2) == res) {
		std::cout << "Status: " << rt::term::GREEN << "Success! " <<
			rt::term::RESET << "The Tuple sum correctly." << std::endl;
	} else {
		std::cout << "Status: " << rt::term::RED << "Error " <<
		rt::term::RESET << "in Tuple sum logic." << std::endl;
	}


	tup1 = rt::Tuple::point(3, 2, 1);
	tup2 = rt::Tuple::point(5, 6, 7);
	res  = rt::Tuple::vector(-2, -4, -6);

	if ((tup1 - tup2) == rt::Tuple(-2, -4, -6, 0)) {
		std::cout << "Status: " << rt::term::GREEN << "Success! " <<
			rt::term::RESET << "The Tuple subtract correctly." << std::endl;
	} else {
		std::cout << "Status: " << rt::term::RED << "Error " <<
		rt::term::RESET << "in Tuple subtract logic." << std::endl;
	}

	tup1 = rt::Tuple::vector(3, 2, 1);
	tup2 = rt::Tuple::vector(5, 6, 7);
	res  = rt::Tuple::vector(-2, -4, -6);

	if ((tup1 - tup2) == rt::Tuple(-2, -4, -6, 0)) {
		std::cout << "Status: " << rt::term::GREEN << "Success! " <<
			rt::term::RESET << "The Tuple subtract correctly." << std::endl;
	} else {
		std::cout << "Status: " << rt::term::RED << "Error " <<
		rt::term::RESET << "in Tuple subtract logic." << std::endl;
	}

	tup1 = rt::Tuple(1, -2, 3, -4);
	res  = rt::Tuple(-1, 2, -3, 4);

	if (-tup1 == res) {
		std::cout << "Status: " << rt::term::GREEN << "Success! " <<
			rt::term::RESET << "The Tuple negation work correctly." << std::endl;
	} else {
		std::cout << "Status: " << rt::term::RED << "Error " <<
		rt::term::RESET << "in Tuple negation logic." << std::endl;
	}

	tup1 = rt::Tuple(1, -2, 3, -4);
	res  = rt::Tuple(3.5, -7, 10.5, -14);

	if (tup1 * 3.5 == res) {
		std::cout << "Status: " << rt::term::GREEN << "Success! " <<
			rt::term::RESET << "The Tuple multply correctly." << std::endl;
	} else {
		std::cout << "Status: " << rt::term::RED << "Error " <<
		rt::term::RESET << "in Tuple multply logic." << std::endl;
	}

	res  = rt::Tuple(0.5, -1, 1.5, -2);

	if (tup1 * 0.5 == res) {
		std::cout << "Status: " << rt::term::GREEN << "Success! " <<
			rt::term::RESET << "The Tuple multply correctly." << std::endl;
	} else {
		std::cout << "Status: " << rt::term::RED << "Error " <<
		rt::term::RESET << "in Tuple multply logic." << std::endl;
	}

	tup1 = rt::Tuple(1, -2, 3, -4);
	res  = rt::Tuple(0.5, -1, 1.5, -2);

	if (tup1 / 2 == res) {
		std::cout << "Status: " << rt::term::GREEN << "Success! " <<
			rt::term::RESET << "The Tuple divided correctly." << std::endl;
	} else {
		std::cout << "Status: " << rt::term::RED << "Error " <<
		rt::term::RESET << "in Tuple divided logic." << std::endl;
	}

	std::cout << "\n--- Vector Operations ---" << std::endl;

	tup1 = rt::Tuple::vector(1, 0, 0);
	float	mag = 1;

	if (tup1.magnitude() == mag) {
		std::cout << "Status: " << rt::term::GREEN << "Success! " <<
			rt::term::RESET << "The Vector magnitude is handled correctly." << std::endl;
	} else {
		std::cout << "Status: " << rt::term::RED << "Error " <<
		rt::term::RESET << "in Vector magnitude logic." << std::endl;
	}


	tup1 = rt::Tuple::vector(0, 1, 0);

	if (tup1.magnitude() == mag) {
		std::cout << "Status: " << rt::term::GREEN << "Success! " <<
			rt::term::RESET << "The Vector magnitude is handled correctly." << std::endl;
	} else {
		std::cout << "Status: " << rt::term::RED << "Error " <<
		rt::term::RESET << "in Vector magnitude logic." << std::endl;
	}

	tup1 = rt::Tuple::vector(0, 0, 1);

	if (tup1.magnitude() == mag) {
		std::cout << "Status: " << rt::term::GREEN << "Success! " <<
			rt::term::RESET << "The Vector magnitude is handled correctly." << std::endl;
	} else {
		std::cout << "Status: " << rt::term::RED << "Error " <<
		rt::term::RESET << "in Vector magnitude logic." << std::endl;
	}

	tup1 = rt::Tuple::vector(1, -2, -3);
	mag = std::sqrt(14);

	if (tup1.magnitude() == mag) {
		std::cout << "Status: " << rt::term::GREEN << "Success! " <<
			rt::term::RESET << "The Vector magnitude is handled correctly." << std::endl;
	} else {
		std::cout << "Status: " << rt::term::RED << "Error " <<
		rt::term::RESET << "in Vector magnitude logic." << std::endl;
	}


	tup1 = rt::Tuple::vector(4, 0, 0);
	res = rt::Tuple::vector(1, 0, 0);

	if (tup1.normalize() == res) {
		std::cout << "Status: " << rt::term::GREEN << "Success! " <<
			rt::term::RESET << "The Vector normalize is handled correctly." << std::endl;
	} else {
		std::cout << "Status: " << rt::term::RED << "Error " <<
		rt::term::RESET << "in Vector normalize logic." << std::endl;
	}

	tup1 = rt::Tuple::vector(4, 0, 0);
	res = rt::Tuple::vector(1, 0, 0);

	if (tup1.normalize() == res) {
		std::cout << "Status: " << rt::term::GREEN << "Success! " <<
			rt::term::RESET << "The Vector normalize is handled correctly." << std::endl;
	} else {
		std::cout << "Status: " << rt::term::RED << "Error " <<
		rt::term::RESET << "in Vector normalize logic." << std::endl;
	}

	tup1 = rt::Tuple::vector(1, 2, 3);
	res = rt::Tuple::vector(0.26726, 0.53452, 0.80178);

	if (tup1.normalize() == res) {
		std::cout << "Status: " << rt::term::GREEN << "Success! " <<
			rt::term::RESET << "The Vector normalize is handled correctly." << std::endl;
	} else {
		std::cout << "Status: " << rt::term::RED << "Error " <<
		rt::term::RESET << "in Vector normalize logic." << std::endl;
	}

	mag = tup1.normalize().magnitude();

	if (rt::equal(mag, 1)) {
		std::cout << "Status: " << rt::term::GREEN << "Success! " <<
			rt::term::RESET << "The magnitude of a normalized vector is 1" << std::endl;
	} else {
		std::cout << "Status: " << rt::term::RED << "Error " <<
		rt::term::RESET << "The magnitude of a normalized vector is not 1" << std::endl;
	}


	tup1 = rt::Tuple::vector(1, 2, 3);
	tup2 = rt::Tuple::vector(2, 3, 4);

	if (rt::equal(rt::Tuple::dot(tup1, tup2), 20)) {
		std::cout << "Status: " << rt::term::GREEN << "Success! " <<
			rt::term::RESET << "The Vector dot is handled correctly." << std::endl;
	} else {
		std::cout << "Status: " << rt::term::RED << "Error " <<
		rt::term::RESET << "in Vector dot logic." << std::endl;
	}

	res = rt::Tuple::vector(-1, 2, -1);

	if (rt::Tuple::cross(tup1, tup2) == res) {
		std::cout << "Status: " << rt::term::GREEN << "Success! " <<
			rt::term::RESET << "The Vector cross is handled correctly." << std::endl;
	} else {
		std::cout << "Status: " << rt::term::RED << "Error " <<
		rt::term::RESET << "in Vector cross logic." << std::endl;
	}

	res = rt::Tuple::vector(1, -2, 1);

	if (rt::Tuple::cross(tup2, tup1) == res) {
		std::cout << "Status: " << rt::term::GREEN << "Success! " <<
			rt::term::RESET << "The Vector cross is handled correctly." << std::endl;
	} else {
		std::cout << "Status: " << rt::term::RED << "Error " <<
		rt::term::RESET << "in Vector cross logic." << std::endl;
	}

	std::cout << "\n--- Color Operations ---" << std::endl;

	auto c1 = rt::Color(-0.5, 0.4, 1.7);

	if (rt::equal(c1.r, -0.5) && rt::equal(c1.g, 0.4) && rt::equal(c1.b, 1.7)) {
		std::cout << "Status: " << rt::term::GREEN << "Success! " <<
			rt::term::RESET << "The Color cross is assigned correctly." << std::endl;
	} else {
		std::cout << "Status: " << rt::term::RED << "Error " <<
		rt::term::RESET << "in Color assigned logic." << std::endl;
	}

	return 0;
}
