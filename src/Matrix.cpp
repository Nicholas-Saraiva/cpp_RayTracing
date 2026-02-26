#include "Matrix.hpp"
#include "Math.hpp"
#include <vector>

namespace rt {

	Matrix::Matrix(int size)
			: size{size}, values(size * size, 0.0f) {};
	Matrix::Matrix(int size, std::vector<float> vec)
		: size(size), values(vec.size() == size * size ? vec : Matrix::Identity(size).values){};

	bool	Matrix::operator==(const Matrix& other) const {
		if (size != other.size) return false;
		for (int i = 0; i < size * size; i++)
			if (!equal(values[i], other.values[i]))
				return (false);
		return (true);
	}

	Matrix	Matrix::multiply_matrix(const Matrix& A, const Matrix& B) {
		auto M = Matrix(4);

		if (A.size != 4 || B.size != 4)
			return (M);
		for (int row = 0; row < 4; row++)
		{
			for (int col = 0; col < 4; col++)
			{
				M.values[row * 4 + col] = A.values[row * 4 + 0] * B.values[0 * 4 + col] +
									  A.values[row * 4 + 1] * B.values[1 * 4 + col] +
									  A.values[row * 4 + 2] * B.values[2 * 4 + col] +
									  A.values[row * 4 + 3] * B.values[3 * 4 + col];
			}
		}
		return (M);
	}

	Tuple	Matrix::multiply_tuple(const Matrix& A, const Tuple& B) {
		float	v[4] = {0, 0, 0, 0};
		float	b_val[4] = {B.x, B.y, B.z, B.w};

		if (A.size != 4) return (Tuple());
		for (int row = 0; row < A.size; row++)
			for (int col = 0; col < A.size; col++)
				v[row] += A.values[row * A.size + col] * b_val[col];
		return (Tuple(v));
	}

	Matrix	Matrix::Identity(int size) {
		auto	M = Matrix(size);

		for (int i = 0; i < size; i++)
			M.values[i * size + i] = 1.0f;
		return (M);
	}

	Matrix	Matrix::Transpose(const Matrix& M) {
		auto	T = Matrix(M.size);

		for (int row = 0; row < M.size; row++)
			for (int col = 0; col < M.size; col++)
				T.values[col * M.size + row] = M.values[row * M.size + col];
		return (T);
	}


	Matrix	Matrix::SubMatrix(const Matrix& M, int row, int col) {
		auto	S = Matrix(M.size - 1);
		int		s_row = 0;
		int		s_col = 0;

		for (int m_row = 0; m_row < M.size; m_row++)
		{
			if (m_row == row) continue;
			for (int m_col = 0; m_col < M.size; m_col++)
			{
				if (m_col == col) continue;
				S.values[s_row * S.size + s_col] = M.values[m_row * M.size + m_col];
				s_col++;
			}
			s_row++;
			s_col = 0;
		}
		return (S);
	}

	float	Matrix::Determinant(const Matrix& M) {
		float	det = 0.0f;
		if (M.size == 2)
			return (M.values[0] * M.values[3] - M.values[1] * M.values[2]);
		for (int col = 0; col < M.size; col++)
			det += M.values[col] * Cofactor(M, 0, col);
		return (det);
	}

	float	Matrix::Minor(const Matrix& M, int row, int col) {
		auto	S = SubMatrix(M, row, col);

		return (Determinant(S));
	}

	float	Matrix::Cofactor(const Matrix& M, int row, int col) {
		float	minor = Minor(M, row, col);

		return ((row + col) % 2 == 0 ? minor : -minor);
	}
}
