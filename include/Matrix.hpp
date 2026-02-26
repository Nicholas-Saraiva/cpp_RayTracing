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

		static Matrix	multiply_matrix(const Matrix& A, const Matrix& B);
		static Matrix	Identity(int size);
		static Matrix	Transpose(const Matrix& M);
		static Matrix	SubMatrix(const Matrix& M, int row, int col);
		static Tuple	multiply_tuple(const Matrix& A, const Tuple& B);
		static float	Determinant(const Matrix& M);
		static float	Minor(const Matrix& M, int row, int col);
		static float	Cofactor(const Matrix& M, int row, int col);

		Matrix	operator+(const Matrix& other) const;
		Matrix	operator-(const Matrix& other) const;
		Matrix	operator/(const float num) const;
		Matrix	operator-() const;
		Matrix&	operator+=(const Matrix& other);
		Matrix&	operator-=(const Matrix& other);
		Matrix&	operator/=(const float num);
		bool	operator==(const Matrix& other) const;
	};
}
