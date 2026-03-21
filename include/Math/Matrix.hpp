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

		float determinant() const;
		float det() const;
		static float determinant(const Matrix& matrix);
		static float det(const Matrix& matrix);

		Matrix inverse() const;
		void invert();
		static Matrix inverse(const Matrix& matrix);
		static void invert(Matrix& matrix);

	private:
		float at_(size_t index) const;
	private:
		std::array<float, 9> matrix_;
	};

	Matrix operator*(const float& scalar, const Matrix& matrix);
}