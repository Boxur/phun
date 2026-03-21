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
			at_(0) * other.at_(0) + at_(1) * other.at_(3) + at_(2) * other.at_(6),
			at_(0) * other.at_(1) + at_(1) * other.at_(4) + at_(2) * other.at_(7),
			at_(0) * other.at_(2) + at_(1) * other.at_(5) + at_(2) * other.at_(8),
			at_(3) * other.at_(0) + at_(4) * other.at_(3) + at_(5) * other.at_(6),
			at_(3) * other.at_(1) + at_(4) * other.at_(4) + at_(5) * other.at_(7),
			at_(3) * other.at_(2) + at_(4) * other.at_(5) + at_(5) * other.at_(8),
			at_(6) * other.at_(0) + at_(7) * other.at_(3) + at_(8) * other.at_(6),
			at_(6) * other.at_(1) + at_(7) * other.at_(4) + at_(8) * other.at_(7),
			at_(6) * other.at_(2) + at_(7) * other.at_(5) + at_(8) * other.at_(8)
			});
	}

	Matrix& Matrix::operator*=(const Matrix& other)
	{
		return *this = *this * other;
	}

	Vector Matrix::operator*(Vector& vector) const
	{
		return Vector(
			vector.x() * at_(0) + vector.y() * at_(1) + vector.z() * at_(2),
			vector.x() * at_(3) + vector.y() * at_(4) + vector.z() * at_(5),
			vector.x() * at_(6) + vector.y() * at_(7) + vector.z() * at_(8)
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

	float Matrix::determinant() const
	{
		return at_(0) * (at_(4) * at_(8) - at_(5) * at_(7))
			- at_(1) * (at_(3) * at_(8) - at_(5) * at_(6))
			+ at_(2) * (at_(3) * at_(7) - at_(4) * at_(6));
	}

	float Matrix::det() const
	{
		return determinant();
	}

	float Matrix::determinant(const Matrix& matrix)
	{
		return matrix.determinant();
	}

	float Matrix::det(const Matrix& matrix)
	{
		return matrix.determinant();
	}

	float phun::Matrix::at_(size_t index) const
	{
		if (index >= 9)
			index %= 9;
		return matrix_[index];
	}

	Matrix operator*(const float& scalar, const Matrix& matrix)
	{
		return matrix*scalar;
	}

}