#include "Matrix.hpp"

namespace phun
{
	Matrix::Matrix(std::array<float, 9> matrix) : matrix_(matrix) {}

	Matrix::Matrix(const Matrix& other) : matrix_(other.matrix_) {}

	float& Matrix::operator()(size_t row, size_t col)
	{
		size_t index = 3 * row + col;
		if (index >= 9)
			index %= 9;
		return matrix_[index];
	}

	Matrix& Matrix::operator=(const Matrix& other)
	{
		matrix_ = other.matrix_;
		return *this;
	}

	Matrix Matrix::operator+(const Matrix& other) const
	{
		Matrix ret = *this;
		for (int i = 0; i < 9; i++)
			ret.matrix_[i] += other.matrix_[i];
		return ret;
	}

	Matrix& Matrix::operator+=(const Matrix& other)
	{
		return *this = *this + other;
	}

	Matrix Matrix::operator-(const Matrix& other) const
	{
		Matrix ret = *this;
		for (int i = 0; i < 9; i++)
			ret.matrix_[i] -= other.matrix_[i];
		return ret;
	}

	Matrix& Matrix::operator-=(const Matrix& other)
	{
		return *this = *this - other;
	}

	Matrix Matrix::operator*(const Matrix& other) const
	{
		return Matrix({
			matrix_[0] * other.matrix_[0] + matrix_[1] * other.matrix_[3] + matrix_[2] * other.matrix_[6],
			matrix_[0] * other.matrix_[1] + matrix_[1] * other.matrix_[4] + matrix_[2] * other.matrix_[7],
			matrix_[0] * other.matrix_[2] + matrix_[1] * other.matrix_[5] + matrix_[2] * other.matrix_[8],
			matrix_[3] * other.matrix_[0] + matrix_[4] * other.matrix_[3] + matrix_[5] * other.matrix_[6],
			matrix_[3] * other.matrix_[1] + matrix_[4] * other.matrix_[4] + matrix_[5] * other.matrix_[7],
			matrix_[3] * other.matrix_[2] + matrix_[4] * other.matrix_[5] + matrix_[5] * other.matrix_[8],
			matrix_[6] * other.matrix_[0] + matrix_[7] * other.matrix_[3] + matrix_[8] * other.matrix_[6],
			matrix_[6] * other.matrix_[1] + matrix_[7] * other.matrix_[4] + matrix_[8] * other.matrix_[7],
			matrix_[6] * other.matrix_[2] + matrix_[7] * other.matrix_[5] + matrix_[8] * other.matrix_[8]
			});
	}

	Matrix& Matrix::operator*=(const Matrix& other)
	{
		return *this = *this * other;
	}

	Vector Matrix::operator*(Vector& vector) const
	{
		return Vector(
			vector.x() * matrix_[0] + vector.y() * matrix_[1] + vector.z() * matrix_[2],
			vector.x() * matrix_[3] + vector.y() * matrix_[4] + vector.z() * matrix_[5],
			vector.x() * matrix_[6] + vector.y() * matrix_[7] + vector.z() * matrix_[8]
			);
	}

	Matrix Matrix::operator*(const float& scalar) const
	{
		Matrix ret = *this;
		for (int i = 0; i < 9; i++)
			ret.matrix_[i] *= scalar;
		return ret;
	}

	Matrix Matrix::operator/(const float& scalar) const
	{
		Matrix ret = *this;
		for (int i = 0; i < 9; i++)
			ret.matrix_[i] /= scalar;
		return ret;
	}

	Matrix operator*(const float& scalar, const Matrix& matrix)
	{
		return matrix*scalar;
	}

}