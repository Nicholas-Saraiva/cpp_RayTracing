#pragma once
#include "Tuple.hpp"
#include <vector>

namespace rt {
	class	Matrix{
	public:
		int	size;
		std::vector<float>	values;

		Matrix(int size);
		Matrix(int size, std::vector<float> vec);

		static Matrix	Identity(int size);
		static Matrix	multiply_matrix(const Matrix& A, const Matrix& B);
		static Tuple	multiply_tuple(const Matrix& A, const Tuple& B);
		static Matrix	Scaling(const Tuple& T);
		static Matrix	Translation(const Tuple& T);
		static Matrix	Shearing(float xy, float xz, float yx, float yz, float zx, float zy);
		static Matrix	Rotation_x(const float angle);
		static Matrix	Rotation_y(const float angle);
		static Matrix	Rotation_z(const float angle);

		Matrix	Transpose() const;
		Matrix	SubMatrix(int row, int col) const;
		Matrix	Inverse() const;
		float	Determinant() const;
		float	Minor(int row, int col) const;
		float	Cofactor(int row, int col) const;

		bool	operator==(const Matrix& other) const;
	};
}
