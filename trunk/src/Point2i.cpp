#include "point2i.h"
#include "vector2f.h"
#include <assert.h>


//-----------------------------------------------------------------------------
// 2D Point Constants.
//-----------------------------------------------------------------------------

const Point2i Point2i::ZERO  = Point2i(0, 0);
const Point2i Point2i::ONE   = Point2i(1, 1);
const Point2i Point2i::UNITX = Point2i(1, 0);
const Point2i Point2i::UNITY = Point2i(0, 1);



//-----------------------------------------------------------------------------
// Constructors.
//-----------------------------------------------------------------------------

// Construct a vector with unitialized components.
Point2i::Point2i()
{
}

// Construct a vector with the given components.
Point2i::Point2i(int x, int y) :
	x(x), y(y)
{
}

// Construct a vector with the given components.
Point2i::Point2i(const Vector2f& v) :
	x((int) v.x), y((int) v.y)
{
}



//-----------------------------------------------------------------------------
// Accessors.
//-----------------------------------------------------------------------------

// Access a component of this vector.
int Point2i::operator [](int index) const
{
	assert(index >= 0 && index < 2);
	return (&x)[index];
}

// Modify a component of this vector.
int& Point2i::operator [](int index)
{
	assert(index >= 0 && index < 2);
	return (&x)[index];
}

// Are the point's coordinates equal to anothers'?
bool Point2i::operator ==(const Point2i& other) const
{
	return (other.x == x && other.y == y);
}

// Are the point's coordinates unequal to anothers'?
bool Point2i::operator !=(const Point2i& other) const
{
	return (other.x != x || other.y != y);
}



//-----------------------------------------------------------------------------
// Mutators.
//-----------------------------------------------------------------------------

// Set the components of this vector to zero.
Point2i& Point2i::setZero()
{
	x = 0;
	y = 0;
	return *this;
}

// Set the components of this vector.
Point2i& Point2i::set(int x, int y)
{
	this->x = x;
	this->y = y;
	return *this;
}

// Negate this vector.
Point2i& Point2i::negate()
{
	x = -x;
	y = -y;
	return *this;
}



//-----------------------------------------------------------------------------
// Unary operators.
//-----------------------------------------------------------------------------

// Return the inverse of this vector.
Point2i Point2i::operator -() const
{
	return Point2i(-x, -y);
}

// Add another vector.
void Point2i::operator +=(const Point2i& v)
{
	x += v.x;
	y += v.y;
}

// Subtract another vector.
void Point2i::operator -=(const Point2i& v)
{
	x -= v.x;
	y -= v.y;
}

// Multiply by another vector.
void Point2i::operator *=(const Point2i& v)
{
	x *= v.x;
	y *= v.y;
}

// Divide by another vector.
void Point2i::operator /=(const Point2i& v)
{
	x /= v.x;
	y /= v.y;
}

// Multiply by scalar.
void Point2i::operator *=(int scalar)
{
	x *= scalar;
	y *= scalar;
}

// Divide by a denominator.
void Point2i::operator /=(int denominator)
{
	x /= denominator;
	y /= denominator;
}



//-----------------------------------------------------------------------------
// Binary operators.
//-----------------------------------------------------------------------------

Point2i Point2i::operator +(const Point2i& other) const
{
	return Point2i(x + other.x, y + other.y);
}

Point2i Point2i::operator -(const Point2i& other) const
{
	return Point2i(x - other.x, y - other.y);
}

Point2i Point2i::operator *(const Point2i& other) const
{
	return Point2i(x * other.x, y * other.y);
}

Point2i Point2i::operator /(const Point2i& other) const
{
	return Point2i(x / other.x, y / other.y);
}

Point2i Point2i::operator *(int scalar) const
{
	return Point2i(x * scalar, y * scalar);
}

Point2i Point2i::operator /(int denominator) const
{
	return Point2i(x / denominator, y / denominator);
}

Point2i operator *(int scalar, const Point2i& v)
{
	return Point2i(scalar * v.x, scalar * v.y);
}

Point2i operator /(int numerator, const Point2i& v)
{
	return Point2i(numerator / v.x, numerator / v.y);
}

// Create a string representation.
std::ostream& operator <<(std::ostream &out, const Point2i& v)
{
	out << "(" << v.x << ", " << v.y << ")";
    return out;
}

