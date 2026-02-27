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

		Matrix	Transpose() const;
		Matrix	SubMatrix(int row, int col) const;
		Matrix	Inverse() const;
		float	Determinant() const;
		float	Minor(int row, int col) const;
		float	Cofactor(int row, int col) const;

		bool	operator==(const Matrix& other) const;
	};
}
