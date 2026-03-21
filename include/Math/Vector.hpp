#pragma once
#include <cmath>

namespace phun
{

	class Vector
	{
	public:
		Vector(float x, float y, float z);
		Vector(Vector& other);

		Vector& operator=(const Vector& other);
		Vector operator+(const Vector& other)	const;
		Vector& operator+=(const Vector& other);
		Vector operator-(const Vector& other)	const;
		Vector& operator-=(const Vector& other);
		float operator*(const Vector& other)	const;
		Vector operator*(const float& scalar)	const;
		Vector& operator*=(const float& scalar);
		Vector operator/(const float& scalar)	const;
		Vector& operator/=(const float& scalar);
		Vector operator^(const Vector& other)	const;
		Vector& operator^=(const Vector& other);

		float Length()							const;

		Vector Normal()							const;
		void Normalize();

		float& x();
		float& y();
		float& z();


	private:
		float x_, y_, z_;
	};

	Vector operator*(const float& scalar, const Vector& vector);
}