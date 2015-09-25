#ifndef VECTOR_2F_H
#define VECTOR_2F_H

#include <Trackable.h>
#include <ostream>

struct Point2i;


// 2D floating-point vector.
struct Vector2f : public Trackable
{
	float x, y;

	// Constants.
	static const Vector2f ZERO;
	static const Vector2f ONE;
	static const Vector2f UNITX;
	static const Vector2f UNITY;

	// Constructors.
	Vector2f();
	Vector2f(float x, float y);
	Vector2f(const Point2i& point);

	// Accessors.
	bool		operator ==(const Vector2f& other) const;
	bool		operator !=(const Vector2f& other) const;
	float		operator [](int index) const;
	float&		operator [](int index);
	float		length() const;
	float		lengthSquared() const;
	float		getX() { return x; }
	float		getY() { return y; }

	// Mutators.
	Vector2f&	setZero();
	Vector2f&	set(float x, float y);
	Vector2f&	negate();
	Vector2f&	normalize();

	// Unary operators.
	Vector2f	operator -() const;
	void		operator +=(const Vector2f& v);
	void		operator -=(const Vector2f& v);
	void		operator *=(const Vector2f& v);
	void		operator /=(const Vector2f& v);
	void		operator *=(float scalar);
	void		operator /=(float invScalar);

	// Binary operators.
	Vector2f	operator +(const Vector2f& other) const;
	Vector2f	operator -(const Vector2f& other) const;
	Vector2f	operator *(const Vector2f& other) const;
	Vector2f	operator /(const Vector2f& other) const;
	Vector2f	operator *(float scalar) const;
	Vector2f	operator /(float invScalar) const;

	// Static Methods.
	static Vector2f	normalize(const Vector2f& v);
	static float	distance(const Vector2f& a, const Vector2f& b);
	static float	distanceSqr(const Vector2f& a, const Vector2f& b);
	static float	dot(const Vector2f& a, const Vector2f& b);
	static float	cross(const Vector2f& a, const Vector2f& b);
	static Vector2f	lerp(const Vector2f& a, const Vector2f& b, float lerpFactor);
};


// Left-hand operators.
Vector2f		operator *(float scalar, const Vector2f& v);
std::ostream&	operator <<(std::ostream &out, const Vector2f& v);


#endif // VECTOR_2F_H
