#pragma once
#include <string>
#include <vector>
#include <memory>

#include "Point.h"

class Shape2D
{
protected:
	std::string name_;
	bool contain_warp_space_;
	double area_;

	std::vector<Point> points_within_shape_;
	std::vector<Point> points_on_perimeter_;

public:
	Shape2D(const std::string& name, const bool& contain_Warp_Space);
	virtual ~Shape2D();

	std::string get_Name() const;
	bool get_Contain_Warp_Space() const;
	double get_Area() const;
	std::vector<Point> get_Points_Within_Shape();
	std::vector<Point> get_Points_On_Perimeter();

	virtual std::string to_String() = 0;

	virtual double compute_Area() = 0;
	virtual bool is_Point_In_Shape(const int& x, const int& y) const = 0;
	virtual bool is_Point_On_Shape(const int& x, const int& y) const = 0;

	virtual std::vector<Point> get_All_Point_In_Shape() = 0;
	virtual std::vector<Point> get_All_Point_On_Shape() = 0;

	void set_Name(const std::string& name);
	void set_Contain_Warp_Space(const bool& contain_Warp_Space);

	friend bool operator<(const std::unique_ptr<Shape2D>& s1, const std::unique_ptr<Shape2D>& s2);
	friend bool operator>(const std::unique_ptr<Shape2D>& s1, const std::unique_ptr<Shape2D>& s2);
};
