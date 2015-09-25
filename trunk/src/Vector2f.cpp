#include "vector2f.h"
#include "Point2i.h"
#include <assert.h>


//-----------------------------------------------------------------------------
// Constants.
//-----------------------------------------------------------------------------

const Vector2f Vector2f::ZERO = Vector2f(0.0f, 0.0f);
const Vector2f Vector2f::ONE = Vector2f(1.0f, 1.0f);
const Vector2f Vector2f::UNITX = Vector2f(1.0f, 0.0f);
const Vector2f Vector2f::UNITY = Vector2f(0.0f, 1.0f);



//-----------------------------------------------------------------------------
// Constructors.
//-----------------------------------------------------------------------------

// Construct a vector with x = 0 and y = 0.
Vector2f::Vector2f() :
x(0.0f),
y(0.0f)
{
}

// Construct a vector with the given components.
Vector2f::Vector2f(float x, float y) :
x(x),
y(y)
{
}

// Create a vector from a point.
Vector2f::Vector2f(const Point2i& point) :
x((float)point.x),
y((float)point.y)
{
}



//-----------------------------------------------------------------------------
// Accessors.
//-----------------------------------------------------------------------------

bool Vector2f::operator ==(const Vector2f& other) const
{
	return (x == other.x && y == other.y);
}

bool Vector2f::operator !=(const Vector2f& other) const
{
	return (x != other.x || y != other.y);
}

// Get a component of this vector.
float Vector2f::operator [](int index) const
{
	assert(index >= 0 && index < 2);
	return (&x)[index];
}

// Modify a component of this vector.
float& Vector2f::operator [](int index)
{
	assert(index >= 0 && index < 2);
	return (&x)[index];
}

// Return the length of this vector.
float Vector2f::length() const
{
	return sqrtf((x * x) + (y * y));
}

// Return the squared-length of this vector.
float Vector2f::lengthSquared() const
{
	return ((x * x) + (y * y));
}



//-----------------------------------------------------------------------------
// Mutators.
//-----------------------------------------------------------------------------

// Set the components of this vector to zero.
Vector2f& Vector2f::setZero()
{
	x = 0.0f;
	y = 0.0f;
	return *this;
}

// Set the components of this vector.
Vector2f& Vector2f::set(float x, float y)
{
	this->x = x;
	this->y = y;
	return *this;
}

// Negate this vector.
Vector2f& Vector2f::negate()
{
	x = -x;
	y = -y;
	return *this;
}

// Normalize the vector, returning a reference to it.
Vector2f& Vector2f::normalize()
{
	float len = length();

	// Don't divide by zero.
	if (len < FLT_EPSILON)
	{
		x = 1.0f;
		y = 0.0f;
	}
	else
	{
		float invLength = 1.0f / len;
		x *= invLength;
		y *= invLength;
	}
	return *this;
}



//-----------------------------------------------------------------------------
// Unary operators.
//-----------------------------------------------------------------------------

// Return the negation of this vector.
Vector2f Vector2f::operator -() const
{
	return Vector2f(-x, -y);
}

// Add another vector.
void Vector2f::operator +=(const Vector2f& v)
{
	x += v.x; y += v.y;
}

// Subtract another vector.
void Vector2f::operator -=(const Vector2f& v)
{
	x -= v.x;
	y -= v.y;
}

// Multiply another vector.
void Vector2f::operator *=(const Vector2f& v)
{
	x *= v.x;
	y *= v.y;
}

// Divide by another vector.
void Vector2f::operator /=(const Vector2f& v)
{
	x /= v.x;
	y /= v.y;
}

// Multiply by a scalar.
void Vector2f::operator *=(float scalar)
{
	x *= scalar;
	y *= scalar;
}

// Divide by the inverse of a scalar.
void Vector2f::operator /=(float invScalar)
{
	float scalar = 1.0f / invScalar;
	x *= scalar;
	y *= scalar;
}



//-----------------------------------------------------------------------------
// Binary operators.
//-----------------------------------------------------------------------------

// Return the vector sum.
Vector2f Vector2f::operator +(const Vector2f& other) const
{
	return Vector2f(x + other.x, y + other.y);
}

// Return the vector difference.
Vector2f Vector2f::operator -(const Vector2f& other) const
{
	return Vector2f(x - other.x, y - other.y);
}

// Return the vector product.
Vector2f Vector2f::operator *(const Vector2f& other) const
{
	return Vector2f(x * other.x, y * other.y);
}

// Return the vector quotient.
Vector2f Vector2f::operator /(const Vector2f& other) const
{
	return Vector2f(x / other.x, y / other.y);
}

// Return the vector scaled by a value.
Vector2f Vector2f::operator *(float scalar) const
{
	return Vector2f(x * scalar, y * scalar);
}

// Return the vector with components divided by some value.
Vector2f Vector2f::operator /(float invScalar) const
{
	float scalar = 1.0f / invScalar;
	return Vector2f(x * scalar, y * scalar);
}

// Return a vector scaled by a value.
Vector2f operator *(float scalar, const Vector2f& v)
{
	return Vector2f(v.x * scalar, v.y * scalar);
}

// Output a string representation of a vector.
std::ostream& operator <<(std::ostream &out, const Vector2f& v)
{
	out << "(" << v.x << ", " << v.y << ")";
	return out;
}



//-----------------------------------------------------------------------------
// Static methods.
//-----------------------------------------------------------------------------

// Returns a normalized vector.
Vector2f Vector2f::normalize(const Vector2f& v)
{
	Vector2f result = v;
	return result.normalize();
}

// Returns the distance between two vectors.
float Vector2f::distance(const Vector2f& a, const Vector2f& b)
{
	return sqrtf((b.x - a.x) * (b.x - a.x) +
		(b.y - a.y) * (b.y - a.y));
}

// Returns the sqaured distance between two vectors.
float Vector2f::distanceSqr(const Vector2f& a, const Vector2f& b)
{
	return ((b.x - a.x) * (b.x - a.x) +
		(b.y - a.y) * (b.y - a.y));
}

// Returns the dot product of two vectors.
float Vector2f::dot(const Vector2f& a, const Vector2f& b)
{
	return (a.x * b.x) + (a.y * b.y);
}

// Returns 2D cross product of two vectors.
float Vector2f::cross(const Vector2f& a, const Vector2f& b)
{
	return (a.x * b.y) - (a.y * b.x);
}

// Performs a linear interpolation between two vectors.
Vector2f Vector2f::lerp(const Vector2f& a, const Vector2f& b, float lerpFactor)
{
	return (a * (1.0f - lerpFactor)) + (b * lerpFactor);
}

