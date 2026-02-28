#include <iostream>
#include "Tuple.hpp"
#include "Terminal.hpp"
#include "Math.hpp"
#include "Color.hpp"
#include "Canvas.hpp"
#include "Matrix.hpp"
#include "Ray.hpp"
#include "Object.hpp"
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
			rt::term::RESET << "Color cross is assigned correctly." << std::endl;
	} else {
		std::cout << "Status: " << rt::term::RED << "Error " <<
		rt::term::RESET << "in Color assigned logic." << std::endl;
	}

	auto c1_add = rt::Color(0.9, 0.6, 0.75);
    auto c2_add = rt::Color(0.7, 0.1, 0.25);
    auto res_add = rt::Color(1.6, 0.7, 1.0);

    if ((c1_add + c2_add) == res_add) {
        std::cout << "Status: " << rt::term::GREEN << "Success! " <<
            rt::term::RESET << "Color addition is handled correctly." << std::endl;
    } else {
        std::cout << "Status: " << rt::term::RED << "Error " <<
            rt::term::RESET << "in Color addition logic." << std::endl;
    }

    auto c1_sub = rt::Color(0.9, 0.6, 0.75);
    auto c2_sub = rt::Color(0.7, 0.1, 0.25);
    auto res_sub = rt::Color(0.2, 0.5, 0.5);

    if ((c1_sub - c2_sub) == res_sub) {
        std::cout << "Status: " << rt::term::GREEN << "Success! " <<
            rt::term::RESET << "Color subtraction is handled correctly." << std::endl;
    } else {
        std::cout << "Status: " << rt::term::RED << "Error " <<
            rt::term::RESET << "in Color subtraction logic." << std::endl;
    }

    auto c_scalar = rt::Color(0.2, 0.3, 0.4);
    auto res_scalar = rt::Color(0.4, 0.6, 0.8);

    if ((c_scalar * 2) == res_scalar) {
        std::cout << "Status: " << rt::term::GREEN << "Success! " <<
            rt::term::RESET << "Color scalar multiplication is handled correctly." << std::endl;
    } else {
        std::cout << "Status: " << rt::term::RED << "Error " <<
            rt::term::RESET << "in Color scalar multiplication logic." << std::endl;
    }

    auto c1_prod = rt::Color(1.0, 0.2, 0.4);
    auto c2_prod = rt::Color(0.9, 1.0, 0.1);
    auto res_prod = rt::Color(0.9, 0.2, 0.04);

    if ((c1_prod * c2_prod) == res_prod) {
        std::cout << "Status: " << rt::term::GREEN << "Success! " <<
            rt::term::RESET << "Color Hadamard product is handled correctly." << std::endl;
    } else {
        std::cout << "Status: " << rt::term::RED << "Error " <<
            rt::term::RESET << "in Color multiplication logic." << std::endl;
    }

	std::cout << "\n--- Canvas Operations ---" << std::endl;


	auto canvas = rt::Canvas(10 ,20);
	c1 = rt::Color(1, 0, 0);
	canvas.write_pixel(2, 3, c1);

	if ((canvas.pixel_at(2, 3)) == c1) {
        std::cout << "Status: " << rt::term::GREEN << "Success! " <<
            rt::term::RESET << "Cavas write_pixel/pixel_at is handled correctly." << std::endl;
    } else {
        std::cout << "Status: " << rt::term::RED << "Error " <<
            rt::term::RESET << "in Cavas write_pixel/pixel_at logic." << std::endl;
    }

	canvas = rt::Canvas(5, 3);
	try
	{
		canvas.canvas_to_ppm();
		std::cout << "Status: " << rt::term::GREEN << "Success! " <<
		rt::term::RESET << "Cavas canvas_to_ppm is handled correctly." << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}

	std::cout << "\n--- Matrix Operations ---" << std::endl;

    // Test 1: Matrix Multiplication
    auto m1 = rt::Matrix(4, {
        1, 2, 3, 4,
        5, 6, 7, 8,
        9, 8, 7, 6,
        5, 4, 3, 2
    });
    auto m2 = rt::Matrix(4, {
        -2, 1, 2,  3,
         3, 2, 1, -1,
         4, 3, 6,  5,
         1, 2, 7,  8
    });
    auto res_m = rt::Matrix(4, {
        20, 22, 50,  48,
        44, 54, 114, 108,
        40, 58, 110, 102,
        16, 26, 46,  42
    });

    if (rt::Matrix::multiply_matrix(m1, m2) == res_m) {
        std::cout << "Status: " << rt::term::GREEN << "Success! " <<
            rt::term::RESET << "Matrix multiplication is handled correctly." << std::endl;
    } else {
        std::cout << "Status: " << rt::term::RED << "Error " <<
            rt::term::RESET << "in Matrix multiplication logic." << std::endl;
    }

    // Test 2: Matrix * Tuple
    auto m3 = rt::Matrix(4, {
        1, 2, 3, 4,
        2, 4, 4, 2,
        8, 6, 4, 1,
        0, 0, 0, 1
    });
    auto tup_in = rt::Tuple(1, 2, 3, 1);
    auto res_tup = rt::Tuple(18, 24, 33, 1);

    if (rt::Matrix::multiply_tuple(m3, tup_in) == res_tup) {
        std::cout << "Status: " << rt::term::GREEN << "Success! " <<
            rt::term::RESET << "Matrix * Tuple is handled correctly." << std::endl;
    } else {
        std::cout << "Status: " << rt::term::RED << "Error " <<
            rt::term::RESET << "in Matrix * Tuple logic." << std::endl;
    }

    // Test 3: Identity Matrix
    auto ident = rt::Matrix::Identity(4);
    if (rt::Matrix::multiply_tuple(ident, tup_in) == tup_in) {
        std::cout << "Status: " << rt::term::GREEN << "Success! " <<
            rt::term::RESET << "Identity Matrix multiplication works." << std::endl;
    } else {
        std::cout << "Status: " << rt::term::RED << "Error " <<
            rt::term::RESET << "in Identity Matrix logic." << std::endl;
    }

	std::cout << "\n--- Matrix Complexity (Submatrices & Determinants) ---" << std::endl;

    // --- 2x2 Determinant ---
    auto m2x2 = rt::Matrix(2, {
         1, 5,
        -3, 2
    });

    if (rt::equal(m2x2.Determinant(), 17.0f)) {
        std::cout << "Status: " << rt::term::GREEN << "Success! " <<
            rt::term::RESET << "2x2 Determinant is 17." << std::endl;
    } else {
        std::cout << "Status: " << rt::term::RED << "Error " <<
            rt::term::RESET << "in 2x2 Determinant logic." << std::endl;
    }

    // --- Submatrix Test ---
    auto m3x3 = rt::Matrix(3, {
         1, 5,  0,
        -3, 2,  7,
         0, 6, -3
    });
    auto sub_expected = rt::Matrix(2, {
        -3, 2,
         0, 6
    });

    // Removing row 0, col 2 from m3x3
    if (m3x3.SubMatrix(0, 2) == sub_expected) {
        std::cout << "Status: " << rt::term::GREEN << "Success! " <<
            rt::term::RESET << "Submatrix (3x3 -> 2x2) correctly identified." << std::endl;
    } else {
        std::cout << "Status: " << rt::term::RED << "Error " <<
            rt::term::RESET << "in Submatrix logic." << std::endl;
    }

    // --- Cofactor Test ---
    // Checking the "checkerboard" sign flipping logic
    if (rt::equal(m3x3.Cofactor(0, 0), -48.0f) && rt::equal(m3x3.Cofactor(0, 1), -9.0f)) {
        std::cout << "Status: " << rt::term::GREEN << "Success! " <<
            rt::term::RESET << "Cofactors (sign flipping) handled correctly." << std::endl;
    } else {
        std::cout << "Status: " << rt::term::RED << "Error " <<
            rt::term::RESET << "in Cofactor logic." << std::endl;
    }

    // --- 4x4 Determinant (The "Big Boss") ---
    auto m4x4 = rt::Matrix(4, {
        -2, -8,  3,  5,
        -3,  1,  7,  3,
         1,  2, -9,  6,
        -6,  7,  7, -9
    });

    if (rt::equal(m4x4.Determinant(), -4071.0f)) {
        std::cout << "Status: " << rt::term::GREEN << "Success! " <<
            rt::term::RESET << "4x4 Determinant (-4071) is correct." << std::endl;
    } else {
        std::cout << "Status: " << rt::term::RED << "Error " <<
            rt::term::RESET << "in 4x4 Determinant logic." << std::endl;
    }

std::cout << "\n--- Matrix Inversion (The Final Boss) ---" << std::endl;

    // --- Test 1: Invertibility Check ---
    auto m_invertible = rt::Matrix(4, {
        6,  4,  4,  4,
        5,  5,  7,  6,
        4, -9,  3, -7,
        9,  1,  7, -6
    });

    if (m_invertible.Determinant() != 0) {
        std::cout << "Status: " << rt::term::GREEN << "Success! " <<
            rt::term::RESET << "Matrix is correctly identified as invertible." << std::endl;
    }

    // --- Test 2: Actual Inversion ---
    auto m_to_invert = rt::Matrix(4, {
        -5,  2,  6, -8,
         1, -5,  1,  8,
         7,  7, -6, -7,
         1, -3,  7,  4
    });

    auto m_expected_inv = rt::Matrix(4, {
         0.21805f,  0.45113f,  0.24060f, -0.04511f,
        -0.80827f, -1.45677f, -0.44361f,  0.52068f,
        -0.07895f, -0.22368f, -0.05263f,  0.19737f,
        -0.52256f, -0.81391f, -0.30075f,  0.30639f
    });
    auto m_result_inv = m_to_invert.Inverse();

    if (m_result_inv == m_expected_inv) {
        std::cout << "Status: " << rt::term::GREEN << "Success! " <<
            rt::term::RESET << "Matrix inversion produced correct values." << std::endl;
    } else {
        std::cout << "Status: " << rt::term::RED << "Error " <<
            rt::term::RESET << "in Inverse logic. Check your cofactor/transpose steps." << std::endl;
    }

    // --- Test 3: The Ultimate Proof (A * A^-1 = Identity) ---
    // If you multiply a matrix by its inverse, you MUST get the Identity matrix.
    auto identity_check = rt::Matrix::multiply_matrix(m_to_invert, m_result_inv);

    if (identity_check == rt::Matrix::Identity(4)) {
        std::cout << "Status: " << rt::term::GREEN << "Success! " <<
            rt::term::RESET << "A * Inverse(A) = Identity Matrix." << std::endl;
    } else {
        std::cout << "Status: " << rt::term::RED << "Error " <<
            rt::term::RESET << "The result of A * A^-1 is not Identity." << std::endl;
    }

std::cout << "\n--- Matrix Transformations ---" << std::endl;

    // --- Translation Test ---
    auto transform = rt::Matrix::Translation(rt::Tuple::vector(5, -3, 2));
    auto p = rt::Tuple::point(-3, 4, 5);
    auto p_expected = rt::Tuple::point(2, 1, 7);

    if (rt::Matrix::multiply_tuple(transform, p) == p_expected) {
        std::cout << "Status: " << rt::term::GREEN << "Success! " <<
            rt::term::RESET << "Point translation works correctly." << std::endl;
    } else {
        std::cout << "Status: " << rt::term::RED << "Error " <<
            rt::term::RESET << "in translation logic." << std::endl;
    }

    // --- Translation should not affect Vectors ---
    auto v = rt::Tuple::vector(-3, 4, 5);
    if (rt::Matrix::multiply_tuple(transform, v) == v) {
        std::cout << "Status: " << rt::term::GREEN << "Success! " <<
            rt::term::RESET << "Translation ignored the vector (as it should)." << std::endl;
    } else {
        std::cout << "Status: " << rt::term::RED << "Error " <<
            rt::term::RESET << "Translation incorrectly moved a vector." << std::endl;
    }

    // --- Scaling Test ---
    transform = rt::Matrix::Scaling(rt::Tuple::vector(2, 3, 4));
    p = rt::Tuple::point(-4, 6, 8);
    p_expected = rt::Tuple::point(-8, 18, 32);

    if (rt::Matrix::multiply_tuple(transform, p) == p_expected) {
        std::cout << "Status: " << rt::term::GREEN << "Success! " <<
            rt::term::RESET << "Scaling works correctly." << std::endl;
    } else {
        std::cout << "Status: " << rt::term::RED << "Error " <<
            rt::term::RESET << "in scaling logic." << std::endl;
    }

    // --- Rotation X Test ---
    auto half_quarter = rt::Matrix::Rotation_x(45);
    auto full_quarter = rt::Matrix::Rotation_x(90);
    p = rt::Tuple::point(0, 1, 0);

    auto expected_hq = rt::Tuple::point(0, std::sqrt(2)/2, std::sqrt(2)/2);
    auto expected_fq = rt::Tuple::point(0, 0, 1);

    if (rt::Matrix::multiply_tuple(half_quarter, p) == expected_hq && rt::Matrix::multiply_tuple(full_quarter, p) == expected_fq) {
        std::cout << "Status: " << rt::term::GREEN << "Success! " <<
            rt::term::RESET << "Rotation X works correctly." << std::endl;
    } else {
        std::cout << "Status: " << rt::term::RED << "Error " <<
            rt::term::RESET << "in Rotation X logic." << std::endl;
    }

    // --- Chaining Transformations (The Ultimate Test) ---
    // In Ray Tracing, order matters! Multiply in REVERSE order of application.
    auto A = rt::Matrix::Rotation_x(90);
    auto B = rt::Matrix::Scaling(rt::Tuple::vector(5, 5, 5));
    auto C = rt::Matrix::Translation(rt::Tuple::vector(10, 5, 7));

    // Apply: Rotate, then Scale, then Translate
    auto T_chained = rt::Matrix::multiply_matrix(C, rt::Matrix::multiply_matrix(B, A));
    p = rt::Tuple::point(1, 0, 1);
    auto res_chained = rt::Tuple::point(15, 0, 7);

    if (rt::Matrix::multiply_tuple(T_chained, p) == res_chained) {
        std::cout << "Status: " << rt::term::GREEN << "Success! " <<
            rt::term::RESET << "Chained transformations (T*S*R) work!" << std::endl;
    } else {
        std::cout << "Status: " << rt::term::RED << "Error " <<
            rt::term::RESET << "in chained transformation order." << std::endl;
    }

    std::cout << "\n--- Ray-Sphere Intersections ---" << std::endl;

    // --- Test 1: A ray intersects a sphere at two points ---
    rt::Ray r1(rt::Tuple::point(0, 0, -5), rt::Tuple::vector(0, 0, 1));
    rt::Sphere s1;
    auto xs1 = rt::Ray::intersect(s1, r1);

    if (xs1.t.size() == 2 && xs1.t[0].t == 4.0f && xs1.t[1].t == 6.0f) {
        std::cout << "Status: " << rt::term::GREEN << "Success! " <<
            rt::term::RESET << "Ray intersects sphere at t=4 and t=6." << std::endl;
    } else {
        std::cout << "Status: " << rt::term::RED << "Error " <<
            rt::term::RESET << "in basic intersection math." << std::endl;
    }

    // --- Test 2: Identifying the 'Hit' ---
    // Scenario: One intersection is negative, one is positive.
    rt::Intersection i1(-1.0f, &s1);
    rt::Intersection i2(1.0f, &s1);
    rt::Instersections xs2(i1, i2);
    auto h = rt::Ray::hit(xs2);

    if (h.obj != nullptr && h.t == 1.0f) {
        std::cout << "Status: " << rt::term::GREEN << "Success! " <<
            rt::term::RESET << "Hit correctly identified as the lowest non-negative t." << std::endl;
    } else {
        std::cout << "Status: " << rt::term::RED << "Error " <<
            rt::term::RESET << "in Hit logic (negative t handling)." << std::endl;
    }

    // --- Test 3: Intersecting a Scaled Sphere ---
    // This tests if your Ray::intersect correctly uses the Inverse Matrix
    rt::Sphere s2;
    s2.inv_transform = (rt::Matrix::Scaling(rt::Tuple::vector(2, 2, 2))).Inverse();
    rt::Ray r2(rt::Tuple::point(0, 0, -5), rt::Tuple::vector(0, 0, 1));
    auto xs3 = rt::Ray::intersect(s2, r2);

    if (xs3.t.size() == 2 && xs3.t[0].t == 3.0f && xs3.t[1].t == 7.0f) {
        std::cout << "Status: " << rt::term::GREEN << "Success! " <<
            rt::term::RESET << "Intersection with scaled sphere is correct (t=3, t=7)." << std::endl;
    } else {
        std::cout << "Status: " << rt::term::RED << "Error " <<
            rt::term::RESET << "in transformed intersection. Check your Inverse Matrix usage!" << std::endl;
    }

    // --- Test 4: Intersecting a Translated Sphere ---
    rt::Sphere s3;
    s3.inv_transform = (rt::Matrix::Translation(rt::Tuple::vector(5, 0, 0))).Inverse();
    auto xs4 = rt::Ray::intersect(s3, r2); // Same ray as Test 3

    if (xs4.t.size() == 0) {
        std::cout << "Status: " << rt::term::GREEN << "Success! " <<
            rt::term::RESET << "Ray correctly misses a translated sphere." << std::endl;
    } else {
        std::cout << "Status: " << rt::term::RED << "Error " <<
            rt::term::RESET << "Ray should have missed the translated sphere." << std::endl;
    }

	return 0;
}
