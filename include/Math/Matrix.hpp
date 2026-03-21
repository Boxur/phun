#pragma once
#include "Vector.hpp"
#include <array>

namespace phun
{
	class Matrix
	{
	public:
		Matrix(std::array<float, 9> matrix);
		Matrix(const Matrix& other);

		float& operator()(size_t row, size_t col);
		Matrix& operator=(const Matrix& other);
		Matrix operator+(const Matrix& other)	const;
		Matrix& operator+=(const Matrix& other);
		Matrix operator-(const Matrix& other)	const;
		Matrix& operator-=(const Matrix& other);
		Matrix operator*(const Matrix& other)	const;
		Matrix& operator*=(const Matrix& other);
		Vector operator*(Vector& vector)		const;
		Matrix operator*(const float& scalar)	const;
		Matrix& operator*=(const float& scalar);
		Matrix operator/(const float& scalar)	const;
		Matrix& operator/=(const float& scalar);
	private:
		std::array<float, 9> matrix_;
	};

	Matrix operator*(const float& scalar, const Matrix& matrix);
}