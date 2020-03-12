#include <catch2/catch.hpp>

#include "Cross.h"

TEST_CASE("Functions of Cross")
{
	std::array<Point, 12> vertices{Point(3, 10), Point(1, 10), Point(1, 8), Point(3, 8), Point(3, 6), Point(5, 6), Point(5, 8), Point(7, 8), Point(7, 10), Point(5, 10), Point(5, 12), Point(3, 12)};
	Cross a_Cross(vertices, true);

	SECTION("Cross is initialized properly")
	{
		REQUIRE(a_Cross.get_Vertex_0() == Point(3, 10));
		REQUIRE(a_Cross.get_Vertex_1() == Point(1, 10));
		REQUIRE(a_Cross.get_Vertex_2() == Point(1, 8));
		REQUIRE(a_Cross.get_Vertex_3() == Point(3, 8));
		REQUIRE(a_Cross.get_Vertex_4() == Point(3, 6));
		REQUIRE(a_Cross.get_Vertex_5() == Point(5, 6));
		REQUIRE(a_Cross.get_Vertex_6() == Point(5, 8));
		REQUIRE(a_Cross.get_Vertex_7() == Point(7, 8));
		REQUIRE(a_Cross.get_Vertex_8() == Point(7, 10));
		REQUIRE(a_Cross.get_Vertex_9() == Point(5, 10));
		REQUIRE(a_Cross.get_Vertex_10() == Point(5, 12));
		REQUIRE(a_Cross.get_Vertex_11() == Point(3, 12));
	}

	SECTION("Compute Area returns the correct output")
	{
		REQUIRE(a_Cross.compute_Area() == 20);
	}

	SECTION("to_String() works properly")
	{
		REQUIRE(a_Cross.to_String() == "Cross, WS, 20, Vertices : (3, 10), (1, 10), (1, 8), (3, 8), (3, 6), (5, 6), (5, 8), (7, 8), (7, 10), (5, 10), (5, 12), (3, 12)");
	}

	SECTION("Point in Shape works properly")
	{
		REQUIRE(a_Cross.is_Point_In_Shape(2, 9) == true);
		REQUIRE(a_Cross.is_Point_In_Shape(3, 9) == true);
		REQUIRE(a_Cross.is_Point_In_Shape(4, 11) == true);
		REQUIRE(a_Cross.is_Point_In_Shape(4, 10) == true);
		REQUIRE(a_Cross.is_Point_In_Shape(4, 9) == true);
		REQUIRE(a_Cross.is_Point_In_Shape(4, 8) == true);
		REQUIRE(a_Cross.is_Point_In_Shape(4, 7) == true);
		REQUIRE(a_Cross.is_Point_In_Shape(5, 9) == true);
		REQUIRE(a_Cross.is_Point_In_Shape(6, 9) == true);
	}

	SECTION("Point on Shape works properly")
	{
		REQUIRE(a_Cross.is_Point_On_Shape(2, 10) == true);
		REQUIRE(a_Cross.is_Point_On_Shape(1, 9) == true);
		REQUIRE(a_Cross.is_Point_On_Shape(2, 8) == true);
		REQUIRE(a_Cross.is_Point_On_Shape(3, 7) == true);
		REQUIRE(a_Cross.is_Point_On_Shape(4, 6) == true);
		REQUIRE(a_Cross.is_Point_On_Shape(5, 7) == true);
		REQUIRE(a_Cross.is_Point_On_Shape(6, 8) == true);
		REQUIRE(a_Cross.is_Point_On_Shape(7, 9) == true);
		REQUIRE(a_Cross.is_Point_On_Shape(6, 10) == true);
		REQUIRE(a_Cross.is_Point_On_Shape(5, 11) == true);
		REQUIRE(a_Cross.is_Point_On_Shape(4, 12) == true);
		REQUIRE(a_Cross.is_Point_On_Shape(3, 11) == true);
	}

	SECTION("Get all Point in shape works properly")
	{
		std::vector<Point> Points{Point(2, 9), Point(3, 9), Point(4, 11), Point(4, 10), Point(4, 9), Point(4, 8), Point(4, 7), Point(5, 9), Point(6, 9)};
		REQUIRE(a_Cross.get_Points_Within_Shape().size() == Points.size());
	}

	SECTION("Get all Point on shape works properly")
	{
		std::vector<Point> Points{Point(2, 10), Point(1, 9), Point(2, 8), Point(3, 7), Point(4, 6), Point(5, 7), Point(6, 8), Point(7, 9), Point(6, 10), Point(5, 11), Point(4, 12), Point(3, 11)};
		REQUIRE(a_Cross.get_Points_On_Perimeter().size() == Points.size());
	}
}