#include "Circle.h"

Circle::Circle(const Point& center, const double& r, const bool& warp_space)
	: Shape2D("Circle", warp_space), center_(center), r_(r)
{
	area_ = compute_Area();
	points_within_shape_ = get_All_Point_In_Shape();
	points_on_perimeter_ = get_All_Point_On_Shape();
}

Circle::~Circle() {}

std::string Circle::to_String()
{
	std::stringstream ss;
	ss << get_Name() << ", ";
	if (get_Contain_Warp_Space())
		ss << "WS, ";
	else
		ss << "NS, ";
	ss << area_ << ", ";
	ss << "Center : (" << center_.get_X() << ", " << center_.get_Y() << "), Radius : " << r_;
	return ss.str();
}

double Circle::compute_Area()
{
	return 3.14 * pow(r_, 2);
}

bool Circle::is_Point_In_Shape(const int& x, const int& y) const
{
	bool within_x_range = (x > center_.get_X() - r_ && x < center_.get_X() + r_);
	bool within_y_range = (y > center_.get_Y() - r_ && y < center_.get_Y() + r_);
	if (within_x_range && within_y_range)
		return true;
}

bool Circle::is_Point_On_Shape(const int& x, const int& y) const
{
	bool north = (x == center_.get_X() && y == center_.get_Y() + r_);
	bool east = (x == center_.get_X() + r_ && y == center_.get_Y());
	bool south = (x == center_.get_X() && y == center_.get_Y() - r_);
	bool west = (x == center_.get_X() - r_ && y == center_.get_Y());

	if (north || east || south || west)
		return true;
}

std::vector<Point> Circle::get_All_Point_In_Shape()
{
	std::vector<Point> points_within_shape;
	for (int x = center_.get_X() - r_ + 1; x < center_.get_X() + r_; x++)
	{
		for (int y = center_.get_Y() - r_ + 1; y < center_.get_Y() + r_; y++)
		{
			if (is_Point_In_Shape(x, y))
				points_within_shape.push_back(Point(x, y));
		}
	}
	return points_within_shape;
}

std::vector<Point> Circle::get_All_Point_On_Shape()
{
	std::vector<Point> points_on_perimeter;
	for (int x = center_.get_X() - r_; x <= center_.get_X() + r_; x++)
	{
		for (int y = center_.get_Y() - r_; y <= center_.get_Y() + r_; y++)
		{
			if (is_Point_On_Shape(x, y))
				points_on_perimeter.push_back(Point(x, y));
		}
	}
	return points_on_perimeter;
}

const Point& Circle::get_Center() const { return this->center_; }
const double& Circle::get_Radius() const { return this->r_; }
