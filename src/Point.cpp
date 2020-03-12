#include "Point.h"

Point::Point()
	: x_(0), y_(0) {}

Point::Point(const int &x, const int &y)
	: x_(x), y_(y) {}

Point::Point(const Point &p)
	: x_(p.x_), y_(p.y_) {}

Point::~Point() {}

const int &Point::get_X() const
{
	return this->x_;
}

const int &Point::get_Y() const
{
	return y_;
}

bool operator==(const Point &p1, const Point &p2)
{
	return p1.x_ == p2.x_ && p1.y_ == p2.y_;
}