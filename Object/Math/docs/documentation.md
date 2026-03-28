<a id="Math_library_"></a>
# Math library

All classes are defined within the `phun` namespace.

<a id="Vector"></a>
# Vector

Class for storing and working with 3D vectors.

<a id="Vector.public"></a>
## public:

<a id="Vector.Constructor"></a>
#### Constructor

```c++
Vector(float x, float y, float z)
```

Just the basic constructor.

Creates the vector and sets its values.

**Arguments**:

- `x` - the x value of the vector.
- `y` - the y value of the vector.
- `z` - the z value of the vector.

<a id="Vector.CopyConstructor"></a>
#### Copy Constructor

```c++
Vector(const Vector& other)
```

Constructor for instant assignment after creation.	

Reassigns the values by value to the other class.

<a id="Vector.operator="></a>
#### operator=

```c++
Vector& operator=(const Vector& other)
```

Reassignment operator overload.
Functionally the same as the [Copy Constructor](#Vector.CopyConstructor).

<a id="Vector.operator+"></a>
#### operator+

```c++
Vector operator+(const Vector& other) const
```

Vector addition operator overload.

Adds the values of the two vectors together 
and returns a new vector with the result.

<a id="Vector.operator+="></a>
#### operator+=

```c++
Vector& operator+=(const Vector& other)
```

Vector addition assignment operator overload.

Adds the values of the other vector to the current vector.

<a id="Vector.operator-"></a>
#### operator-

```c++
Vector operator-(const Vector& other) const
```

Vector subtraction operator overload.

Subtracts the values of the other vector from the current vector
and returns a new vector with the result.

<a id="Vector.operator-="></a>
#### operator-=
```c++
Vector& operator-=(const Vector& other)
```

Vector subtraction assignment operator overload.

Subtracts the values of the other vector from the current vector.

<a id="Vector.operator*"></a>
#### operator*

this operator has two overloads, one for multiplying by a scalar
and one for multiplying by another vector.

```c++
float operator*(const Vector& other)  const
Vector operator*(const float& scalar) const
```

The first overload is for multiplying by another vector
and returns the dot product of the two vectors.
The second overload is for multiplying by a scalar
and returns a new vector with the result.

<a id="Vector.operator*="></a>
#### operator*=

```c++
Vector& operator*=(const float& scalar)
```

Scalar multiplication assignment operator overload.

Multiplies the current vector by a scalar.

<a id="Vector.operator/"></a>
#### operator/

```c++
Vector operator/(const float& scalar) const
```

Scalar division operator overload.

Divides the current vector by a scalar
and returns a new vector with the result.

<a id="Vector.operator/="></a>
#### operator/=

```c++
Vector& operator/=(const float& scalar)
```

Scalar division assignment operator overload.

Divides the current vector by a scalar.

<a id="Vector.operator^"></a>
#### operator^

```c++
Vector operator^(const Vector& other) const
```

Vector cross product operator overload.

Calculates the cross product of the current vector and another vector
and returns a new vector with the result.

<a id="Vector.operator^="></a>
#### operator^=

```c++
Vector& operator^=(const Vector& other)
```

Vector cross product assignment operator overload.

Calculates the cross product of the current vector and another vector.

<a id="Vector.Length"></a>
#### Length

```c++
float Length() const
```

Calculates the length of the vector.

**Returns**:

The length of the vector.

<a id="Vector.Normal"></a>
#### Normal

```c++
Vector Normal() const
```

Calculates the normal version of the vector.

**Returns**:

A new vector with the normal version of the current vector.

<a id="Vector.Normalize"></a>
#### Normalize

```c++
void Normalize()
```

Normalizes the vector.

<a id="Vector.x"></a>
#### x

this function has two overloads, a constant version for getting the value
and a reference version for setting the value.

```c++
float& x()
float x() const
```

The first overload is for setting the value of x and returns a reference to it.
The second overload is for getting the value of x and returns it by value.

**Returns**:

- `float&` - a reference to the x value of the vector (for the first overload).
- `float` - the x value of the vector (for the second overload).

<a id="Vector.y"></a>
#### y

this function has two overloads, a constant version for getting the value
and a reference version for setting the value.

```c++
float& y()
float y() const
```
The first overload is for setting the value of y and returns a reference to it.
The second overload is for getting the value of y and returns it by value.

**Returns**:

- `float&` - a reference to the y value of the vector (for the first overload).
- `float` - the y value of the vector (for the second overload).

<a id="Vector.z"></a>
#### z

this function has two overloads, a constant version for getting the value
and a reference version for setting the value.

```c++
float& z()
float z() const
```

The first overload is for setting the value of z and returns a reference to it.
The second overload is for getting the value of z and returns it by value.

**Returns**:

- `float&` - a reference to the z value of the vector (for the first overload).
- `float` - the z value of the vector (for the second overload).

<a id="Vector.private"></a>
## private:

<a id="Vector.x_"></a>
#### x_

```c++
float x_
```

The x value of the vector.

<a id="Vector.y_"></a>
#### y_

```c++
float y_
```

The y value of the vector.

<a id="Vector.z_"></a>
#### z_

```c++
float z_
```

The z value of the vector.

<a id="Vector.outsideClass"></a>
## Outside of the class

<a id="Vector.outside.operator*"></a>
#### operator*

```c++
Vector operator*(const float& scalar, const Vector& vec)
```

Scalar multiplication operator overload for when the scalar is on the left side of the operator.

Multiplies the vector by a scalar and returns a new vector with the result.

<a id="Matrix"></a>
# Matrix

Class for storing and working with 3x3 matrices.

<a id="Matrix.public"></a>
## public:

<a id="Matrix.Constructor"></a>
#### Constructor

The constructor has two overloads, a default constructor that creates a matrix with all values set to 0
and a constructor that takes an std::array of 9 values to set the values of the matrix.

```c++
Matrix()
Matrix(const std::array<float, 9>& values)
```

Just the basic constructor.

The first overload creates a matrix with all values set to 0.
The second overload creates a matrix with the values set to the values in the array.

**Arguments**:

- `values` - an std::array of 9 values to set the values of the matrix.

<a id="Matrix.CopyConstructor"></a>
#### Copy Constructor

```c++
Matrix(const Matrix& other)
```

Constructor for instant assignment after creation.

Reassigns the values by value to the other class.

<a id="Matrix.operator()"></a>
#### operator()

```c++
float& operator()(const size_t& row, const size_t& col)
float operator()(const size_t& row, const size_t& col) const
```

This operator has two overloads, a constant version for getting the value
and a reference version for setting the value.

The first overload is for setting the value of the matrix at the specified row and column and returns a reference to it.
The second overload is for getting the value of the matrix at the specified row and column and returns it by value.

**Arguments**:

- `row` - the row of the matrix to access (0-2).
- `col` - the column of the matrix to access (0-2).

**Returns**:

- `float&` - a reference to the value of the matrix at the specified row and column (for the first overload).
- `float` - the value of the matrix at the specified row and column (for the second overload).

<a id="Matrix.operator="></a>
#### operator=

```c++
Matrix& operator=(const Matrix& other)
```

Reassignment operator overload.

Functionally the same as the [Copy Constructor](#Matrix.CopyConstructor).

<a id="Matrix.operator+"></a>
#### operator+

```c++
Matrix operator+(const Matrix& other) const
```

Matrix addition operator overload.

Adds the values of the two matrices together and returns a new matrix with the result.

<a id="Matrix.operator+="></a>
#### operator+=

```c++
Matrix& operator+=(const Matrix& other)
```

Matrix addition assignment operator overload.

Adds the values of the other matrix to the current matrix.

<a id="Matrix.operator-"></a>
#### operator-

```c++
Matrix operator-(const Matrix& other) const
```

Matrix subtraction operator overload.

Subtracts the values of the other matrix from the current matrix and returns a new matrix with the result.

<a id="Matrix.operator-="></a>
#### operator-=

```c++
Matrix& operator-=(const Matrix& other)
```

Matrix subtraction assignment operator overload.

Subtracts the values of the other matrix from the current matrix.

<a id="Matrix.operator*"></a>
#### operator*

```c++
Matrix operator*(const Matrix& other)	const
Vector operator*(const Vector& vector)	const
Matrix operator*(const float& scalar)	const
```

This operator has three overloads, one for multiplying by another matrix, one for multiplying by a vector, and one for multiplying by a scalar.

The first overload is for multiplying by another matrix and returns a new matrix with the result.
The second overload is for multiplying by a vector and returns a new vector with the result.
The third overload is for multiplying by a scalar and returns a new matrix with the result.

**Arguments**:

- `other` - the other matrix to multiply by (for the first overload).
- `vector` - the vector to multiply by (for the second overload).
- `scalar` - the scalar to multiply by (for the third overload).

**Returns**:

- `Matrix` - a new matrix with the result of the multiplication (for the first and third overloads).
- `Vector` - a new vector with the result of the multiplication (for the second overload).

<a id="Matrix.operator*="></a>
#### operator*=

```c++
Matrix& operator*=(const Matrix& other)
Matrix& operator*=(const float& scalar)
```

This operator has two overloads, one for multiplying by another matrix and one for multiplying by a scalar.

The first overload is for multiplying by another matrix and updates the current matrix with the result.
The second overload is for multiplying by a scalar and updates the current matrix with the result.

**Arguments**:

- `other` - the other matrix to multiply by (for the first overload).
- `scalar` - the scalar to multiply by (for the second overload).

<a id="Matrix.operator/"></a>
#### operator/

```c++
Matrix operator/(const float& scalar)	const
```

Scalar division operator overload.

Divides the current matrix by a scalar and returns a new matrix with the result.

**Arguments**:

- `scalar` - the scalar to divide by.

**Returns**:

- `Matrix` - a new matrix with the result of the division.

<a id="Matrix.operator/="></a>
#### operator/=

```c++
Matrix& operator/=(const float& scalar)
```

Scalar division assignment operator overload.

Divides the current matrix by a scalar and updates the current matrix with the result.

**Arguments**:

- `scalar` - the scalar to divide by.

<a id="Matrix.Determinant"></a>
#### Determinant

```c++
float Determinant() const
static float Determinant(const Matrix& matrix)
```

This function has two overloads, a non-static version that calculates the determinant of the current matrix
and a static version that calculates the determinant of a given matrix.

The first overload calculates the determinant of the current matrix and returns it.
The second overload calculates the determinant of the given matrix and returns it.

**Arguments**:

- `matrix` - the matrix to calculate the determinant of (for the second overload).

**Returns**:

- `float` - the determinant of the matrix.

<a id="Matrix.Det"></a>
#### Det

```c++
float Det() const
static float Det(const Matrix& matrix)
```

This function is an alias for the [Determinant](#Matrix.Determinant) function and has the same functionality.

<a id="Matrix.Transposition"></a>
#### Transposition

```c++
Matrix Transposition() const
static Matrix Transposition(const Matrix& matrix)
```

This function has two overloads, a non-static version that calculates the transposition of the current matrix
and a static version that calculates the transposition of a given matrix.

The first overload calculates the transposition of the current matrix and returns it.
The second overload calculates the transposition of the given matrix and returns it.

**Arguments**:

- `matrix` - the matrix to calculate the transposition of (for the second overload).

**Returns**:

- `Matrix` - a new matrix with the transposition of the matrix.

<a id="Matrix.Transpose"></a>
#### Transpose

```c++
void Transpose()
static void Transpose(Matrix& matrix)
```

This function has two overloads, a non-static version that transposes the current matrix 
and a static version that transposes a given matrix.

The first overload transposes the current matrix.
The second overload transposes the given matrix.

**Arguments**:

- `matrix` - the matrix to transpose (for the second overload).

<a id="Matrix.Inverse"></a>
#### Inverse

```c++
Matrix Inverse() const
static Matrix Inverse(const Matrix& matrix)
```

This function has two overloads, a non-static version that calculates the inverse of the current matrix
and a static version that calculates the inverse of a given matrix.

The first overload calculates the inverse of the current matrix and returns it.
The second overload calculates the inverse of the given matrix and returns it.

**Arguments**:

- `matrix` - the matrix to calculate the inverse of (for the second overload).

**Returns**:

- `Matrix` - a new matrix with the inverse of the matrix.

<a id="Matrix.Invert"></a>
#### Invert

```c++
void Invert()
static void Invert(Matrix& matrix)
```

This function has two overloads, a non-static version that inverts the current matrix
and a static version that inverts a given matrix.

The first overload inverts the current matrix.
The second overload inverts the given matrix.

**Arguments**:

- `matrix` - the matrix to invert (for the second overload).

<a id="Matrix.RotateX"></a>
#### RotateX

```c++
void RotateX(const float& teto)
```

Rotates the current matrix around the x-axis by the given angle in radians.

**Arguments**:

- `teto` - the angle to rotate by in radians.

The name teto sounds like the Greek letter theta and is a funny reference to the character [Kasane Teto](https://en.wikipedia.org/wiki/Kasane_Teto)

<a id="Matrix.RotateY"></a>
#### RotateY

```c++
void RotateY(const float& teto)
```
Rotates the current matrix around the y-axis by the given angle in radians.

**Arguments**:

- `teto` - the angle to rotate by in radians.

The name teto sounds like the Greek letter theta and is a funny reference to the character [Kasane Teto](https://en.wikipedia.org/wiki/Kasane_Teto)

<a id="Matrix.RotateZ"></a>
#### RotateZ

```c++
void RotateZ(const float& teto)
```

Rotates the current matrix around the z-axis by the given angle in radians.

**Arguments**:

- `teto` - the angle to rotate by in radians.

The name teto sounds like the Greek letter theta and is a funny reference to the character [Kasane Teto](https://en.wikipedia.org/wiki/Kasane_Teto)

<a id="Matrix.RotationX"></a>
#### RotationX

```c++
static Matrix RotationX(const float& teto)
```

Returns a new matrix that is a rotation around the x-axis by the given angle in radians.

**Arguments**:

- `teto` - the angle to rotate by in radians.

The name teto sounds like the Greek letter theta and is a funny reference to the character [Kasane Teto](https://en.wikipedia.org/wiki/Kasane_Teto)

<a id="Matrix.RotationY"></a>
#### RotationY

```c++
static Matrix RotationY(const float& teto)
```

Returns a new matrix that is a rotation around the y-axis by the given angle in radians.

**Arguments**:

- `teto` - the angle to rotate by in radians.

The name teto sounds like the Greek letter theta and is a funny reference to the character [Kasane Teto](https://en.wikipedia.org/wiki/Kasane_Teto)

<a id="Matrix.RotationZ"></a>
#### RotationZ

```c++
static Matrix RotationZ(const float& teto)
```

Returns a new matrix that is a rotation around the z-axis by the given angle in radians.

**Arguments**:

- `teto` - the angle to rotate by in radians.

The name teto sounds like the Greek letter theta and is a funny reference to the character [Kasane Teto](https://en.wikipedia.org/wiki/Kasane_Teto)

<a id="Matrix.private"></a>
## private:

<a id="Matrix.At_"></a>
#### At_

```c++
float& At_(const size_t& index)
float At_(const size_t& index) const
```

This function has two overloads, a constant version for getting the value
and a reference version for setting the value.

The first overload is for setting the value of the matrix at the specified index and returns a reference to it.
The second overload is for getting the value of the matrix at the specified index and returns it by value.

**Arguments**:

- `index` - the index of the matrix to access (0-8).

**Returns**:

- `float&` - a reference to the value of the matrix at the specified index (for the first overload).
- `float` - the value of the matrix at the specified index (for the second overload).

<a id="Matrix.matrix_"></a>
#### matrix_

```c++
std::array<float, 9> matrix_
```

The values of the matrix stored in a 1D array in row-major order.

<a id="Matrix.outsideClass"></a>
## Outside of the class

<a id="Matrix.outside.operator*"></a>
#### operator*

```c++
Matrix operator*(const float& scalar, const Matrix& matrix)
```

Scalar multiplication operator overload for when the scalar is on the left side of the operator.

Multiplies the matrix by a scalar and returns a new matrix with the result.