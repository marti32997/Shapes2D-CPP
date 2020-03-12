#pragma once
#include <cmath>
#include <sstream>
#include <array>
#include <vector>

#include "Point.h"
#include "Shape2D.h"

class Square : public Shape2D
{
private:
	std::array<Point, 4> vertices_;

public:
	Square(const std::array<Point, 4> &vertices, const bool &contain_warp_space);
	~Square();

	std::string to_String() override;

	double compute_Area() override;
	bool is_Point_In_Shape(const int &x, const int &y) const override;
	bool is_Point_On_Shape(const int &x, const int &y) const override;

	std::vector<Point> get_All_Point_In_Shape() override;
	std::vector<Point> get_All_Point_On_Shape() override;

	const Point &get_Vertex_0() const;
	const Point &get_Vertex_1() const;
	const Point &get_Vertex_2() const;
	const Point &get_Vertex_3() const;
};
