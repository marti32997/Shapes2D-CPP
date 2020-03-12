#pragma once

#include <cmath>
#include <sstream>
#include <array>
#include <vector>

#include "Shape2D.h"
#include "Point.h"

class Cross : public Shape2D
{
private:
	std::array<Point, 12> vertices_;

public:
	Cross(const std::array<Point, 12> &vertices, const bool &warp_space);
	~Cross();

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
	const Point &get_Vertex_4() const;
	const Point &get_Vertex_5() const;
	const Point &get_Vertex_6() const;
	const Point &get_Vertex_7() const;
	const Point &get_Vertex_8() const;
	const Point &get_Vertex_9() const;
	const Point &get_Vertex_10() const;
	const Point &get_Vertex_11() const;
};
