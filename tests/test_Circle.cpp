#include <catch2/catch.hpp>

#include "Circle.h"

TEST_CASE("Functions of Circle")
{
	Circle a_Circle(Point(4, 5), 3, true);

	SECTION("Get X Returns the correct output")
	{
		REQUIRE(a_Circle.get_Center().get_X() == 4);
	}

	SECTION("Get Y Returns the correct output")
	{
		REQUIRE(a_Circle.get_Center().get_Y() == 4);
	}

	SECTION("Get Radius Returns the correct output")
	{
		REQUIRE(a_Circle.get_Radius() == 3);
	}

	SECTION("Point In Shape Working Properly")
	{
		REQUIRE(a_Circle.is_Point_In_Shape(2, 3) == true);
		REQUIRE(a_Circle.is_Point_In_Shape(2, 4) == true);
		REQUIRE(a_Circle.is_Point_In_Shape(2, 5) == true);
		REQUIRE(a_Circle.is_Point_In_Shape(2, 6) == true);
		REQUIRE(a_Circle.is_Point_In_Shape(2, 7) == true);

		REQUIRE(a_Circle.is_Point_In_Shape(3, 3) == true);
		REQUIRE(a_Circle.is_Point_In_Shape(3, 4) == true);
		REQUIRE(a_Circle.is_Point_In_Shape(3, 5) == true);
		REQUIRE(a_Circle.is_Point_In_Shape(3, 6) == true);
		REQUIRE(a_Circle.is_Point_In_Shape(3, 7) == true);

		REQUIRE(a_Circle.is_Point_In_Shape(4, 3) == true);
		REQUIRE(a_Circle.is_Point_In_Shape(4, 4) == true);
		REQUIRE(a_Circle.is_Point_In_Shape(4, 5) == true);
		REQUIRE(a_Circle.is_Point_In_Shape(4, 6) == true);
		REQUIRE(a_Circle.is_Point_In_Shape(4, 7) == true);

		REQUIRE(a_Circle.is_Point_In_Shape(5, 3) == true);
		REQUIRE(a_Circle.is_Point_In_Shape(5, 4) == true);
		REQUIRE(a_Circle.is_Point_In_Shape(5, 5) == true);
		REQUIRE(a_Circle.is_Point_In_Shape(5, 6) == true);
		REQUIRE(a_Circle.is_Point_In_Shape(5, 7) == true);

		REQUIRE(a_Circle.is_Point_In_Shape(6, 3) == true);
		REQUIRE(a_Circle.is_Point_In_Shape(6, 4) == true);
		REQUIRE(a_Circle.is_Point_In_Shape(6, 5) == true);
		REQUIRE(a_Circle.is_Point_In_Shape(6, 6) == true);
		REQUIRE(a_Circle.is_Point_In_Shape(6, 7) == true);

		REQUIRE(a_Circle.is_Point_In_Shape(6, 8) == false);
	}

	SECTION("Point on Shape Working Properly")
	{
		REQUIRE(a_Circle.is_Point_On_Shape(0, 0) == false);

		REQUIRE(a_Circle.is_Point_On_Shape(4, 8) == true);
		REQUIRE(a_Circle.is_Point_On_Shape(7, 5) == true);
		REQUIRE(a_Circle.is_Point_On_Shape(4, 2) == true);
		REQUIRE(a_Circle.is_Point_On_Shape(1, 5) == true);
	}

	SECTION("Compute Area returns the correct output")
	{
		REQUIRE(a_Circle.compute_Area() == 28.26);
	}

	SECTION("toString() returns the correct output")
	{
		REQUIRE(a_Circle.to_String() == "Circle, WS, 28.26, Center : (4, 5), Radius : 3");
	}

	SECTION("Get all Points in shape is working properly")
	{
		std::vector<Point> Points{Point(2, 3), Point(2, 4), Point(2, 5), Point(2, 6), Point(2, 7), Point(3, 3), Point(3, 4), Point(3, 5), Point(3, 6), Point(3, 7), Point(4, 3), Point(4, 4), Point(4, 5), Point(4, 6), Point(4, 7), Point(5, 3), Point(5, 4), Point(5, 5), Point(5, 6), Point(5, 7), Point(6, 3), Point(6, 4), Point(6, 5), Point(6, 6), Point(6, 7)};
		REQUIRE(a_Circle.get_Points_Within_Shape() == Points);
	}

	SECTION("Get all Points on shape is working properly")
	{
		std::vector<Point> Points{Point(4, 8), Point(7, 5), Point(7, 5), Point(1, 5)};
		REQUIRE(a_Circle.get_Points_On_Perimeter().size() == Points.size());
	}
}