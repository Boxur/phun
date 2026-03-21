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

		float Determinant() const;
		float Det() const;
		static float Determinant(const Matrix& matrix);
		static float Det(const Matrix& matrix);

		Matrix Transposition() const;
		void Transpose();
		static Matrix Transposition(const Matrix& matrix);
		static void Transpose(Matrix& matrix);

		Matrix Inverse() const;
		void Invert();
		static Matrix Inverse(const Matrix& matrix);
		static void Invert(Matrix& matrix);

		//Teto reference because it sounds similar to "theta" as an angle
		void RotateX(float teto);
		void RotateY(float teto);
		void RotateZ(float teto);
		static Matrix RotationX(float teto);
		static Matrix RotationY(float teto);
		static Matrix RotationZ(float teto);

	private:
		float At_(size_t index) const;
	private:
		std::array<float, 9> matrix_;
	};

	Matrix operator*(const float& scalar, const Matrix& matrix);
}