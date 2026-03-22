#include "Matrix.hpp"
namespace phun
{
	Matrix::Matrix() : matrix_{} {}
	Matrix::Matrix(const std::array<float, 9>& matrix) : matrix_(matrix) {}

	Matrix::Matrix(const Matrix& other) : matrix_(other.matrix_) {}

	float& Matrix::operator()(const size_t& row, const size_t& col)
	{
		size_t index = 3 * row + col;
		if (index >= 9)
			index %= 9;
		return matrix_[index];
	}

	float Matrix::operator()(const size_t& row, const size_t& col) const
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
		Matrix ret;
		ret.matrix_ = matrix_;
		for (int i = 0; i < 9; i++)
			ret.matrix_[i] += other.matrix_[i];
		return ret;
	}

	Matrix& Matrix::operator+=(const Matrix& other)
	{
		for (int i = 0; i < 9; i++)
			At_(i) += other.matrix_[i];
		return *this;
	}

	Matrix Matrix::operator-(const Matrix& other) const
	{
		Matrix ret;
		ret.matrix_ = matrix_;
		for (int i = 0; i < 9; i++)
			ret.matrix_[i] -= other.matrix_[i];
		return ret;
	}

	Matrix& Matrix::operator-=(const Matrix& other)
	{
		for (int i = 0; i < 9; i++)
			At_(i) -= other.matrix_[i];
		return *this;
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

	Vector Matrix::operator*(const Vector& vector) const
	{
		return Vector(
			vector.x() * At_(0) + vector.y() * At_(1) + vector.z() * At_(2),
			vector.x() * At_(3) + vector.y() * At_(4) + vector.z() * At_(5),
			vector.x() * At_(6) + vector.y() * At_(7) + vector.z() * At_(8)
			);
	}

	Matrix Matrix::operator*(const float& scalar) const
	{
		Matrix ret;
		ret.matrix_ = matrix_;
		for (int i = 0; i < 9; i++)
			ret.matrix_[i] *= scalar;
		return ret;
	}

	Matrix& Matrix::operator*=(const Matrix& other)
	{
		return *this = *this * other;
	}

	Matrix& Matrix::operator*=(const float& scalar)
	{
		for (int i = 0; i < 9; i++)
			At_(i) *= scalar;
		return *this;
	}

	Matrix Matrix::operator/(const float& scalar) const
	{
		Matrix ret;
		ret.matrix_ = matrix_;
		for (int i = 0; i < 9; i++)
			ret.matrix_[i] /= scalar;
		return ret;
	}

	Matrix& Matrix::operator/=(const float& scalar)
	{
		for (int i = 0; i < 9; i++)
			At_(i) /= scalar;
		return *this;
	}

	float Matrix::Determinant() const
	{
		return At_(0) * (At_(4) * At_(8) - At_(5) * At_(7))
			- At_(1) * (At_(3) * At_(8) - At_(5) * At_(6))
			+ At_(2) * (At_(3) * At_(7) - At_(4) * At_(6));
	}

	float Matrix::Determinant(const Matrix& matrix)
	{
		return matrix.Determinant();
	}

	float Matrix::Det() const
	{
		return Determinant();
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

	Matrix phun::Matrix::Transposition(const Matrix& matrix)
	{
		return matrix.Transposition();
	}

	void phun::Matrix::Transpose()
	{
		matrix_ = Transposition().matrix_;
	}

	void phun::Matrix::Transpose(Matrix& matrix)
	{
		matrix.matrix_ = matrix.Transposition().matrix_;
	}

	Matrix Matrix::Inverse() const
	{
		float d = Determinant();
		if (d == 0)
			return Matrix();
		return Matrix({
			At_(4) * At_(8) - At_(5) * At_(7),At_(2) * At_(7) - At_(1) * At_(8) , At_(1) * At_(5) - At_(2) * At_(4),
			At_(5) * At_(6) - At_(3) * At_(8), At_(0) * At_(8) - At_(2) * At_(6), At_(2) * At_(3) - At_(0) * At_(5),
			At_(3) * At_(7) - At_(4) * At_(6), At_(1) * At_(6) - At_(0) * At_(7), At_(0) * At_(4) - At_(1) * At_(3)
			}) / d;
	}

	Matrix phun::Matrix::Inverse(const Matrix& matrix)
	{
		return matrix.Inverse();
	}

	void phun::Matrix::Invert()
	{
		matrix_ = Inverse().matrix_;
	}

	void phun::Matrix::Invert(Matrix& matrix)
	{
		matrix.matrix_ = matrix.Inverse().matrix_;
	}

	void phun::Matrix::RotateX(const float& teto)
	{
		*this *= RotationX(teto);
	}

	void phun::Matrix::RotateY(const float& teto)
	{
		*this *= RotationY(teto);
	}

	void phun::Matrix::RotateZ(const float& teto)
	{
		*this *= RotationZ(teto);
	}

	Matrix phun::Matrix::RotationX(const float& teto)
	{
		return Matrix({
			1, 0, 0,
			0, cosf(teto), -sinf(teto),
			0, sinf(teto), cosf(teto)
			});
	}

	Matrix phun::Matrix::RotationY(const float& teto)
	{
		return Matrix({
			cosf(teto), 0, sinf(teto),
			0, 1, 0,
			-sinf(teto), 0, cosf(teto)
			});
	}

	Matrix phun::Matrix::RotationZ(const float& teto)
	{
		return Matrix({
			cosf(teto), -sinf(teto), 0,
			sinf(teto), cosf(teto), 0,
			0, 0, 1
			});
	}

	float& phun::Matrix::At_(const size_t& index)
	{
		if (index >= 9)
			return matrix_[index%9];
		return matrix_[index];
	}

	float phun::Matrix::At_(const size_t& index) const
	{
		if (index >= 9)
			return matrix_[index%9];
		return matrix_[index];
	}

	Matrix operator*(const float& scalar, const Matrix& matrix)
	{
		return matrix*scalar;
	}

}