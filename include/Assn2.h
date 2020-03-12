#pragma once

#include <iostream>
#include <string>
#include <iomanip>
#include <vector>
#include <array>
#include <algorithm>
#include <memory>

#include "Point.h"
#include "Shape2D.h"
#include "Circle.h"
#include "Square.h"
#include "Rectangle.h"
#include "Cross.h"

// Driver Class Assn2
class Assn2
{
public:
	int record_count_ = 0;

	std::vector<std::unique_ptr<Shape2D>> Shapes_;

	int main();
	void input_Sensor_Data();

	void construct_Circle(const bool &warp_space);
	void construct_Square(const bool &warp_space);
	void construct_Rectangle(const bool &warp_space);
	void construct_Cross(const bool &warp_space);

	void compute_Area_For_All();
	void print_Shapes_Report();
	void sort_Shape_Data();
};
