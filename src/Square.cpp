#include "Square.h"

Square::Square(const std::array<Point, 4> &vertices, const bool &warp_space)
	: Shape2D("Square", warp_space), vertices_(vertices)
{
	area_ = compute_Area();
	points_within_shape_ = get_All_Point_In_Shape();
	points_on_perimeter_ = get_All_Point_On_Shape();
}

Square::~Square()
{
}

std::string Square::to_String()
{
	std::stringstream ss;
	ss << get_Name() << ", ";
	if (get_Contain_Warp_Space())
		ss << "WS, ";
	else
		ss << "NS, ";
	ss << area_ << ", Vertices : ";
	for (int i = 0; i < 4; i++)
	{
		if (i == 3)
			ss << "(" << vertices_[i].get_X() << ", " << vertices_[i].get_Y() << ")";
		else
			ss << "(" << vertices_[i].get_X() << ", " << vertices_[i].get_Y() << "), ";
	}
	return ss.str();
}

double Square::compute_Area()
{
	int side = get_Vertex_0().get_X() - get_Vertex_2().get_X();

	return pow(abs(side), 2);
}

bool Square::is_Point_In_Shape(const int &x, const int &y) const
{
	bool within_x_range = (x > vertices_[0].get_X() && x < vertices_[2].get_X());
	bool within_y_range = (y > vertices_[1].get_Y() && y < vertices_[0].get_Y());

	if (within_x_range && within_y_range)
		return true;
}

bool Square::is_Point_On_Shape(const int &x, const int &y) const
{
	bool top_side = (x > vertices_[0].get_X() && x < vertices_[2].get_X() && y == vertices_[0].get_Y());
	bool bottom_side = (x > vertices_[0].get_X() && x < vertices_[2].get_X() && y == vertices_[1].get_Y());

	bool left_side = (x == vertices_[0].get_X() && y > vertices_[1].get_Y() && y < vertices_[0].get_Y());
	bool right_side = (x == vertices_[2].get_X() && y > vertices_[1].get_Y() && y < vertices_[0].get_Y());

	if (top_side || right_side || bottom_side || left_side)
		return true;
}

std::vector<Point> Square::get_All_Point_In_Shape()
{
	std::vector<Point> points_within_shape;
	for (int x = vertices_[0].get_X() + 1; x < vertices_[2].get_X(); x++)
	{
		for (int y = vertices_[1].get_Y() + 1; y < vertices_[0].get_Y(); y++)
		{
			if (is_Point_In_Shape(x, y))
				points_within_shape.push_back(Point(x, y));
		}
	}
	return points_within_shape;
}

std::vector<Point> Square::get_All_Point_On_Shape()
{
	std::vector<Point> points_on_perimeter;
	for (int x = vertices_[0].get_X(); x <= vertices_[2].get_X(); x++)
	{
		for (int y = vertices_[1].get_Y(); y <= vertices_[0].get_Y(); y++)
		{
			if (is_Point_On_Shape(x, y))
				points_on_perimeter.push_back(Point(x, y));
		}
	}
	return points_on_perimeter;
}

const Point &Square::get_Vertex_0() const { return this->vertices_[0]; }
const Point &Square::get_Vertex_1() const { return this->vertices_[1]; }
const Point &Square::get_Vertex_2() const { return this->vertices_[2]; }
const Point &Square::get_Vertex_3() const { return this->vertices_[3]; }
