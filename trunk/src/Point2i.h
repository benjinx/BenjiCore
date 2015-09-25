#ifndef POINT_2I_H
#define POINT_2I_H

#include <Trackable.h>
#include <ostream>

struct Vector2f;


// 2D integer vector.
struct Point2i : public Trackable
{
	int x, y;
	
	// Constants.
	static const Point2i ZERO;	// (0, 0)
	static const Point2i ONE;	// (1, 1)
	static const Point2i UNITX;	// +X
	static const Point2i UNITY;	// +Y

	// Constructors.
	Point2i();
	Point2i(int x, int y);
	explicit Point2i(const Vector2f& v);

	// Accessors.
	int			operator [](int index) const;
	int&		operator [](int index);
	bool		operator ==(const Point2i& other) const;
	bool		operator !=(const Point2i& other) const;

	// Mutators.
	Point2i&	setZero();
	Point2i&	set(int x, int y);
	Point2i&	negate();

	// Unary operators.
	Point2i		operator -() const;
	void		operator +=(const Point2i& v);
	void		operator -=(const Point2i& v);
	void		operator *=(const Point2i& v);
	void		operator /=(const Point2i& v);
	void		operator *=(int scalar);
	void		operator /=(int denominator);

	// Binary operators.
	Point2i		operator +(const Point2i& other) const;
	Point2i		operator -(const Point2i& other) const;
	Point2i		operator *(const Point2i& other) const;
	Point2i		operator /(const Point2i& other) const;
	Point2i		operator *(int scalar) const;
	Point2i		operator /(int denominator) const;
};


// Left-hand Operators.
Point2i			operator *(int scalar, const Point2i& v);
Point2i			operator /(int numerator, const Point2i& v);
std::ostream&	operator <<(std::ostream &out, const Point2i& v);


typedef Point2i Vector2i;


#endif // POINT_2I_H