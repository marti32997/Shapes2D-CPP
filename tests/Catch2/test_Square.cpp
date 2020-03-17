#include <catch2/catch.hpp>

#include "Square.h"

class Point_Matcher : public Catch::MatcherBase<Point>
{
private:
	Point p_;

public:
	explicit Point_Matcher(const Point &a_Point)
		: p_(a_Point) {}

	bool match(Point const &a_Point) const override
	{
		return a_Point == p_;
	}

	virtual std::string describe() const override
	{
		std::ostringstream oss;
		oss << "not the same as Point(" << p_.get_X() << ", " << p_.get_Y() << ")";
		return oss.str();
	}
};

std::ostream &operator<<(std::ostream &os, const Point &p)
{
	os << "Point(" << p.get_X() << ", " << p.get_Y() << ")";
	return os;
}

inline Point_Matcher is_Same(const Point &a_Point)
{
	return Point_Matcher(a_Point);
}

TEST_CASE("Functions of Square")
{
	std::array<Point, 4> a_Vertices{Point(2, 4), Point(2, 2), Point(4, 2), Point(4, 4)};
	Square a_Square(a_Vertices, true);

	SECTION("Square is initialized properly")
	{
		REQUIRE_THAT(a_Square.get_Vertex_0(), is_Same(Point(2, 4)));
		REQUIRE_THAT(a_Square.get_Vertex_1(), is_Same(Point(2, 2)));
		REQUIRE_THAT(a_Square.get_Vertex_2(), is_Same(Point(4, 2)));
		REQUIRE_THAT(a_Square.get_Vertex_3(), is_Same(Point(4, 4)));
	}

	SECTION("Compute Area returns the correct output")
	{
		REQUIRE(a_Square.compute_Area() == 4);
	}

	SECTION("to_String() returns the correct output")
	{
		REQUIRE(a_Square.to_String() == "Square, WS, 4, Vertices : (2, 4), (2, 2), (4, 2), (4, 4)");
	}

	SECTION("Point in Shape is working properly")
	{
		REQUIRE(a_Square.is_Point_In_Shape(3, 3) == true);
		REQUIRE(a_Square.is_Point_In_Shape(0, 0) == false);
	}

	SECTION("Point on Shape is working properly")
	{
		REQUIRE(a_Square.is_Point_On_Shape(2, 3) == true);
		REQUIRE(a_Square.is_Point_On_Shape(4, 3) == true);
		REQUIRE(a_Square.is_Point_On_Shape(3, 2) == true);
		REQUIRE(a_Square.is_Point_On_Shape(3, 4) == true);

		REQUIRE(a_Square.is_Point_On_Shape(0, 0) == false);
	}

	SECTION("Get all points in shape is working properly")
	{
		std::vector<Point> Points{Point(3, 3)};
		REQUIRE(a_Square.get_Points_Within_Shape().size() == Points.size());
	}

	SECTION("Get all points on shape is working properly")
	{
		std::vector<Point> Points{Point(2, 3), Point(4, 3), Point(3, 2), Point(3, 4)};
		REQUIRE(a_Square.get_Points_On_Perimeter().size() == Points.size());
	}
}