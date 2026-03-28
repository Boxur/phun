#pragma once
#include "Vector.hpp"
#include <array>

namespace phun
{
	class Matrix
	{
	public:
		Matrix();
		Matrix(const std::array<float, 9>& matrix);
		Matrix(const Matrix& other);

		float& operator()(const size_t& row, const size_t& col);
		float operator()(const size_t& row, const size_t& col) const;
		Matrix& operator=(const Matrix& other);
		Matrix operator+(const Matrix& other)	const;
		Matrix& operator+=(const Matrix& other);
		Matrix operator-(const Matrix& other)	const;
		Matrix& operator-=(const Matrix& other);
		Matrix operator*(const Matrix& other)	const;
		Vector operator*(const Vector& vector)	const;
		Matrix operator*(const float& scalar)	const;
		Matrix& operator*=(const Matrix& other);
		Matrix& operator*=(const float& scalar);
		Matrix operator/(const float& scalar)	const;
		Matrix& operator/=(const float& scalar);

		float Determinant() const;
		static float Determinant(const Matrix& matrix);
		float Det() const;
		static float Det(const Matrix& matrix);

		Matrix Transposition() const;
		static Matrix Transposition(const Matrix& matrix);
		void Transpose();
		static void Transpose(Matrix& matrix);

		Matrix Inverse() const;
		static Matrix Inverse(const Matrix& matrix);
		void Invert();
		static void Invert(Matrix& matrix);

		//Teto reference because it sounds similar to "theta" as an angle
		void RotateX(const float& teto);
		void RotateY(const float& teto);
		void RotateZ(const float& teto);
		static Matrix RotationX(const float& teto);
		static Matrix RotationY(const float& teto);
		static Matrix RotationZ(const float& teto);

	private:
		float& At_(const size_t& index);
		float At_(const size_t& index) const;
	private:
		std::array<float, 9> matrix_;
	};

	Matrix operator*(const float& scalar, const Matrix& matrix);
}