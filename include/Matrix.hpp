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

		Matrix	Transpose(const Matrix& M) const;
		Matrix	SubMatrix(const Matrix& M, int row, int col) const;
		float	Determinant(const Matrix& M) const;
		float	Minor(const Matrix& M, int row, int col) const;
		float	Cofactor(const Matrix& M, int row, int col) const;

		bool	operator==(const Matrix& other) const;
	};
}
