#include "Vector.hpp"

namespace phun
{
	Vector::Vector(float x, float y, float z) : x_(x), y_(y), z_(z) {}

	Vector::Vector(Vector& other) : x_(other.x_), y_(other.y_), z_(other.z_) {}

	Vector Vector::operator+(const Vector& other) const
	{
		return Vector(x_+other.x_,y_+other.y_,z_+other.z_);
	}

	Vector Vector::operator-(const Vector& other) const
	{
		return Vector(x_ - other.x_, y_ - other.y_, z_ - other.z_);
	}

	float Vector::operator*(const Vector& other) const
	{
		return x_*other.x_+ y_ * other.y_ + z_ * other.z_;
	}

	Vector Vector::operator*(const float& scalar) const
	{
		return Vector(x_*scalar,y_*scalar,z_*scalar);
	}

	Vector Vector::operator/(const float& scalar) const
	{
		return Vector(x_/scalar,y_/scalar,z_/scalar);
	}

	Vector Vector::operator^(const Vector& other) const
	{
		return Vector(y_ * other.z_ - z_ * other.y_, z_ * other.x_ - x_ * other.z_, x_ * other.y_ - y_ * other.x_);
	}

	float Vector::Length() const
	{
		return sqrtf(x_ * x_ + y_ * y_ + z_ * z_);
	}
	
	Vector Vector::Normal() const
	{
		return (*this) / Length();
	}

	void Vector::Normalize()
	{
		*this = Normal();
	}

	float& Vector::x() { return x_; }
	float& Vector::y() { return y_; }
	float& Vector::z() { return z_; }

	Vector operator*(const float& scalar, const Vector& vector)
	{
		return vector * scalar;
	}

}

