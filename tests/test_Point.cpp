#include <catch2/catch.hpp>

#include "Point.h"

TEST_CASE("Functions of Point")
{
	Point a_Point(3, 5);

	SECTION("Point is initialized properly")
	{
		REQUIRE(a_Point.get_X() == 3);
		REQUIRE(a_Point.get_Y() == 5);
	}
}