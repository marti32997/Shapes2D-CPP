#include "Cross.h"

Cross::Cross(const std::array<Point, 12> &vertices, const bool &warp_space)
	: Shape2D("Cross", warp_space), vertices_(vertices)
{
	area_ = compute_Area();
	points_within_shape_ = get_All_Point_In_Shape();
	points_on_perimeter_ = get_All_Point_On_Shape();
}

Cross::~Cross() {}

std::string Cross::to_String()
{
	std::stringstream ss;
	ss << get_Name() << ", ";
	if (get_Contain_Warp_Space())
		ss << "WS, ";
	else
		ss << "NS, ";
	ss << area_ << ", Vertices : ";
	for (int i = 0; i < 12; i++)
	{
		if (i == 11)
			ss << "(" << vertices_[i].get_X() << ", " << vertices_[i].get_Y() << ")";
		else
			ss << "(" << vertices_[i].get_X() << ", " << vertices_[i].get_Y() << "), ";
	}
	return ss.str();
}

double Cross::compute_Area()
{
	int left_rectangle_length = vertices_[0].get_X() - vertices_[1].get_X();
	int left_rectangle_width = vertices_[1].get_Y() - vertices_[2].get_Y();
	int left_rectangle_area = left_rectangle_length * left_rectangle_width;

	int bottom_rectangle_length = vertices_[5].get_X() - vertices_[4].get_X();
	int bottom_rectangle_width = vertices_[3].get_Y() - vertices_[4].get_Y();
	int bottom_rectangle_area = bottom_rectangle_length * bottom_rectangle_width;

	int right_rectangle_length = vertices_[7].get_X() - vertices_[6].get_X();
	int right_rectangle_width = vertices_[8].get_Y() - vertices_[7].get_Y();
	int right_rectangle_area = right_rectangle_length * right_rectangle_width;

	int top_rectangle_length = vertices_[10].get_X() - vertices_[11].get_X();
	int top_rectangle_width = vertices_[10].get_Y() - vertices_[9].get_Y();
	int top_rectangle_area = top_rectangle_length * top_rectangle_width;

	int middle_rectangle_length = vertices_[9].get_X() - vertices_[0].get_X();
	int middle_rectangle_width = vertices_[0].get_Y() - vertices_[3].get_Y();
	int middle_rectangle_area = middle_rectangle_length * middle_rectangle_width;

	double sum_of_area = left_rectangle_area + bottom_rectangle_area + right_rectangle_area + top_rectangle_area + middle_rectangle_area;
	return sum_of_area;
}

bool Cross::is_Point_In_Shape(const int &x, const int &y) const
{
	bool within_horizontal_rectangle = (x > vertices_[1].get_X() && x < vertices_[8].get_X() && y > vertices_[2].get_Y() && y < vertices_[8].get_Y());
	bool within_vertical_rectangle = (x > vertices_[0].get_X() && x < vertices_[9].get_X() && y > vertices_[4].get_Y() && y < vertices_[11].get_Y());

	if (within_horizontal_rectangle || within_vertical_rectangle)
		return true;
}

bool Cross::is_Point_On_Shape(const int &x, const int &y) const
{
	bool between_v0_v1 = (x > vertices_[1].get_X() && x < vertices_[0].get_X() && y == vertices_[0].get_Y());
	bool between_v1_v2 = (y > vertices_[2].get_Y() && y < vertices_[1].get_Y() && x == vertices_[1].get_X());
	bool between_v2_v3 = (x > vertices_[2].get_X() && x < vertices_[3].get_X() && y == vertices_[2].get_Y());
	bool between_v3_v4 = (y > vertices_[4].get_Y() && y < vertices_[3].get_Y() && x == vertices_[3].get_X());
	bool between_v4_v5 = (x > vertices_[4].get_X() && x < vertices_[5].get_X() && y == vertices_[4].get_Y());
	bool between_v5_v6 = (y > vertices_[5].get_Y() && y < vertices_[6].get_Y() && x == vertices_[5].get_X());
	bool between_v6_v7 = (x > vertices_[6].get_X() && x < vertices_[7].get_X() && y == vertices_[6].get_Y());
	bool between_v7_v8 = (y > vertices_[7].get_Y() && y < vertices_[8].get_Y() && x == vertices_[7].get_X());
	bool between_v8_v9 = (x > vertices_[9].get_X() && x < vertices_[8].get_X() && y == vertices_[8].get_Y());
	bool between_v9_v10 = (y > vertices_[9].get_Y() && y < vertices_[10].get_Y() && x == vertices_[9].get_X());
	bool between_v10_v11 = (x > vertices_[11].get_X() && x < vertices_[10].get_X() && y == vertices_[10].get_Y());
	bool between_v11_v0 = (y > vertices_[0].get_Y() && y < vertices_[11].get_Y() && x == vertices_[11].get_X());

	bool within_any_of_line = (between_v0_v1 || between_v1_v2 || between_v2_v3 || between_v3_v4 || between_v4_v5 || between_v5_v6 || between_v6_v7 || between_v7_v8 || between_v8_v9 || between_v9_v10 || between_v10_v11 || between_v11_v0);
	if (within_any_of_line)
		return true;
}

std::vector<Point> Cross::get_All_Point_In_Shape()
{
	std::vector<Point> points_within_shape;
	for (int x = vertices_[1].get_X() + 1; x < vertices_[8].get_X(); x++)
	{
		for (int y = vertices_[4].get_Y() + 1; y < vertices_[11].get_Y(); y++)
		{
			if (is_Point_In_Shape(x, y))
				points_within_shape.push_back(Point(x, y));
		}
	}
	return points_within_shape;
}

std::vector<Point> Cross::get_All_Point_On_Shape()
{
	std::vector<Point> points_on_perimeter;
	for (int x = vertices_[1].get_X(); x <= vertices_[8].get_X(); x++)
	{
		for (int y = vertices_[4].get_Y(); y <= vertices_[11].get_Y(); y++)
		{
			if (is_Point_On_Shape(x, y))
				points_on_perimeter.push_back(Point(x, y));
		}
	}
	return points_on_perimeter;
}

const Point &Cross::get_Vertex_0() const { return this->vertices_[0]; }
const Point &Cross::get_Vertex_1() const { return this->vertices_[1]; }
const Point &Cross::get_Vertex_2() const { return this->vertices_[2]; }
const Point &Cross::get_Vertex_3() const { return this->vertices_[3]; }
const Point &Cross::get_Vertex_4() const { return this->vertices_[4]; }
const Point &Cross::get_Vertex_5() const { return this->vertices_[5]; }
const Point &Cross::get_Vertex_6() const { return this->vertices_[6]; }
const Point &Cross::get_Vertex_7() const { return this->vertices_[7]; }
const Point &Cross::get_Vertex_8() const { return this->vertices_[8]; }
const Point &Cross::get_Vertex_9() const { return this->vertices_[9]; }
const Point &Cross::get_Vertex_10() const { return this->vertices_[10]; }
const Point &Cross::get_Vertex_11() const { return this->vertices_[11]; }