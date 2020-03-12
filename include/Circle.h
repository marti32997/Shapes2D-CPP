#pragma once
#include <cmath>
#include <sstream>
#include <vector>

#include "Shape2D.h"
#include "Point.h"

/**
 * @brief A class which represents a circle, containing the radius, and a center Point
 *
 */
class Circle : public Shape2D
{
private:
	Point center_;
	double r_;

public:
	/**
	 * @brief Construct a new Circle:: Circle object
	 *
	 * @param center A Point(x, y) which is the center of the circle
	 * @param r The radius of the circle in units
	 * @param warp_space A boolean value to indicate whether this shape is a special type or not
	 * @details For this constructor to be called, the user must type in Circle as the Shape Name
	 */
	Circle(const Point& center, const double& r, const bool& warp_space);
	~Circle();

	/**
	 * @brief A function that returns all the attribute of the Circle as a string
	 *
	 * @return std::string
	 */
	std::string to_String() override;

	/**
	 * @brief Calculates the area of the circle
	 *
	 * @return double
	 */
	double compute_Area() override;

	/**
	 * @brief Given a coordinate (x, y), functions return true if point is within shape (not on the perimeter)
	 *
	 * @param x X coordinate
	 * @param y Y coordinate
	 * @return true
	 * @return false
	 */
	bool is_Point_In_Shape(const int& x, const int& y) const override;

	/**
	 * @brief Given a coordinate (x, y), functions return ture if point is on the perimeter and not the vertices
	 *
	 * @param x X coordinate
	 * @param y Y coordinate
	 * @return true
	 * @return false
	 */
	bool is_Point_On_Shape(const int &x, const int &y) const override;

	/**
	 * @brief Get the All Point In Circle object using is_Point_In_Shape method
	 *
	 * @return std::vector<Point> that contains all the points within Shape
	 */
	std::vector<Point> get_All_Point_In_Shape() override;

	/**
	 * @brief Get the All Point On the circle perimeter, in this case, the North, West, South, East Point from the center
	 *
	 * @return std::vector<Point> that contains all point on the perimeter
	 */
	std::vector<Point> get_All_Point_On_Shape() override;

	/**
	 * @brief Get the Radius of the circle
	 *
	 * @return radius of circle
	 */
	const double &get_Radius() const;

	/**
	 * @brief Get the Center of the circle in coordinate (x, y)
	 *
	 * @return Point object (x, y) with the coordinate of the circle Center
	 */
	const Point &get_Center() const;
};