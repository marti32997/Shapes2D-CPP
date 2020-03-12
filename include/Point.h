#pragma once
#include <iostream>

class Point
{
private:
	int x_, y_;

public:
	Point();
	Point(const int &x, const int &y);
	Point(const Point &p);
	~Point();
	const int &get_X() const;
	const int &get_Y() const;

	friend bool operator==(const Point &p1, const Point &p2);
};