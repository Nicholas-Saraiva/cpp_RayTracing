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

	Matrix	Matrix::Transpose() const{
		auto	T = Matrix(size);

		for (int row = 0; row < size; row++)
			for (int col = 0; col < size; col++)
				T.values[col * size + row] = values[row * size + col];
		return (T);
	}


	Matrix	Matrix::SubMatrix(int row, int col) const {
		auto	S = Matrix(size - 1);
		int		s_row = 0;
		int		s_col = 0;

		for (int m_row = 0; m_row < size; m_row++)
		{
			if (m_row == row) continue;
			for (int m_col = 0; m_col < size; m_col++)
			{
				if (m_col == col) continue;
				S.values[s_row * S.size + s_col] = values[m_row * size + m_col];
				s_col++;
			}
			s_row++;
			s_col = 0;
		}
		return (S);
	}

	float	Matrix::Determinant() const {
		float	det = 0.0f;
		if (size == 2)
			return (values[0] * values[3] - values[1] * values[2]);
		for (int col = 0; col < size; col++)
			det += values[col] * Cofactor(0, col);
		return (det);
	}

	float	Matrix::Minor(int row, int col) const {
		auto	S = SubMatrix(row, col);

		return (S.Determinant());
	}

	float	Matrix::Cofactor(int row, int col) const {
		float	minor = Minor(row, col);

		return ((row + col) % 2 == 0 ? minor : -minor);
	}
}
