#include <catch2/catch.hpp>

#include "Rectangle.h"

TEST_CASE("Functions of a rectangle")
{
	std::array<Point, 4> vertices{Point(2, 17), Point(2, 15), Point(6, 15), Point(6, 17)};
	Rectangle a_Rectangle(vertices, true);

	SECTION("Rectangle is initialized properly")
	{
		REQUIRE(a_Rectangle.get_Vertex_0() == Point(2, 17));
		REQUIRE(a_Rectangle.get_Vertex_1() == Point(2, 15));
		REQUIRE(a_Rectangle.get_Vertex_2() == Point(6, 15));
		REQUIRE(a_Rectangle.get_Vertex_3() == Point(6, 17));
	}

	SECTION("Compute Area returns the correct output")
	{
		REQUIRE(a_Rectangle.compute_Area() == 8);
	}

	SECTION("to_String() Returns the correct output")
	{
		REQUIRE(a_Rectangle.to_String() == "Rectangle, WS, 8, Vertices : (2, 17), (2, 15), (6, 15), (6, 17)");
	}

	SECTION("Point in Shape is working properly")
	{
		REQUIRE(a_Rectangle.is_Point_In_Shape(3, 16) == true);
		REQUIRE(a_Rectangle.is_Point_In_Shape(4, 16) == true);
		REQUIRE(a_Rectangle.is_Point_In_Shape(5, 16) == true);
	}

	SECTION("Point on Shape is working properly")
	{
		REQUIRE(a_Rectangle.is_Point_On_Shape(2, 16) == true);
		REQUIRE(a_Rectangle.is_Point_On_Shape(3, 15) == true);
		REQUIRE(a_Rectangle.is_Point_On_Shape(4, 15) == true);
		REQUIRE(a_Rectangle.is_Point_On_Shape(5, 15) == true);
		REQUIRE(a_Rectangle.is_Point_On_Shape(6, 16) == true);
		REQUIRE(a_Rectangle.is_Point_On_Shape(5, 17) == true);
		REQUIRE(a_Rectangle.is_Point_On_Shape(4, 17) == true);
		REQUIRE(a_Rectangle.is_Point_On_Shape(3, 17) == true);
	}

	SECTION("Get all Point in shape is working properly")
	{
		std::vector<Point> Points{Point(3, 16), Point(4, 16), Point(5, 16)};
		REQUIRE(a_Rectangle.get_Points_Within_Shape().size() == Points.size());
	}
	SECTION("Get all Point on shape is working properly")
	{
		std::vector<Point> Points{Point(2, 16), Point(3, 15), Point(4, 15), Point(5, 15), Point(6, 16), Point(5, 17), Point(4, 17), Point(3, 17)};
		REQUIRE(a_Rectangle.get_Points_On_Perimeter().size() == Points.size());
	}
}