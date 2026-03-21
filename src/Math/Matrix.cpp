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
			At_(0) * other.At_(0) + At_(1) * other.At_(3) + At_(2) * other.At_(6),
			At_(0) * other.At_(1) + At_(1) * other.At_(4) + At_(2) * other.At_(7),
			At_(0) * other.At_(2) + At_(1) * other.At_(5) + At_(2) * other.At_(8),
			At_(3) * other.At_(0) + At_(4) * other.At_(3) + At_(5) * other.At_(6),
			At_(3) * other.At_(1) + At_(4) * other.At_(4) + At_(5) * other.At_(7),
			At_(3) * other.At_(2) + At_(4) * other.At_(5) + At_(5) * other.At_(8),
			At_(6) * other.At_(0) + At_(7) * other.At_(3) + At_(8) * other.At_(6),
			At_(6) * other.At_(1) + At_(7) * other.At_(4) + At_(8) * other.At_(7),
			At_(6) * other.At_(2) + At_(7) * other.At_(5) + At_(8) * other.At_(8)
			});
	}

	Matrix& Matrix::operator*=(const Matrix& other)
	{
		return *this = *this * other;
	}

	Vector Matrix::operator*(Vector& vector) const
	{
		return Vector(
			vector.x() * At_(0) + vector.y() * At_(1) + vector.z() * At_(2),
			vector.x() * At_(3) + vector.y() * At_(4) + vector.z() * At_(5),
			vector.x() * At_(6) + vector.y() * At_(7) + vector.z() * At_(8)
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

	float Matrix::Determinant() const
	{
		return At_(0) * (At_(4) * At_(8) - At_(5) * At_(7))
			- At_(1) * (At_(3) * At_(8) - At_(5) * At_(6))
			+ At_(2) * (At_(3) * At_(7) - At_(4) * At_(6));
	}

	float Matrix::Det() const
	{
		return Determinant();
	}

	float Matrix::Determinant(const Matrix& matrix)
	{
		return matrix.Determinant();
	}

	float Matrix::Det(const Matrix& matrix)
	{
		return matrix.Determinant();
	}

	Matrix phun::Matrix::Transposition() const
	{
		return Matrix({
			At_(0), At_(3), At_(6),
			At_(1), At_(4), At_(7),
			At_(2), At_(5), At_(8)
			});
	}

	void phun::Matrix::Transpose()
	{
		matrix_ = Transposition().matrix_;
	}

	Matrix phun::Matrix::Transposition(const Matrix& matrix)
	{
		return matrix.Transposition();
	}

	void phun::Matrix::Transpose(Matrix& matrix)
	{
		matrix.matrix_ = matrix.Transposition().matrix_;
	}

	Matrix Matrix::Inverse() const
	{
		float d = Determinant();
		if (d == 0)
			return Matrix({});
		return Matrix({
			At_(4) * At_(8) - At_(5) * At_(7),At_(2) * At_(7) - At_(1) * At_(8) , At_(1) * At_(5) - At_(2) * At_(4),
			At_(5) * At_(6) - At_(3) * At_(8), At_(0) * At_(8) - At_(2) * At_(6), At_(2) * At_(3) - At_(0) * At_(5),
			At_(3) * At_(7) - At_(4) * At_(6), At_(1) * At_(6) - At_(0) * At_(7), At_(0) * At_(4) - At_(1) * At_(3)
			}) / d;
	}

	void phun::Matrix::Invert()
	{
		matrix_ = Inverse().matrix_;
	}

	Matrix phun::Matrix::Inverse(const Matrix& matrix)
	{
		return matrix.Inverse();
	}

	void phun::Matrix::Invert(Matrix& matrix)
	{
		matrix.matrix_ = matrix.Inverse().matrix_;
	}

	float phun::Matrix::At_(size_t index) const
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