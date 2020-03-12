#include "Shape2D.h"

Shape2D::Shape2D(const std::string& name, const bool& contain_Warp_Space)
	: name_(name), contain_warp_space_(contain_Warp_Space), area_(0) {}

Shape2D::~Shape2D() {}

std::string Shape2D::get_Name() const
{
	return this->name_;
}

double Shape2D::get_Area() const
{
	return this->area_;
}

bool Shape2D::get_Contain_Warp_Space() const
{
	return this->contain_warp_space_;
}

std::vector<Point> Shape2D::get_Points_Within_Shape()
{
	return this->points_within_shape_;
}

std::vector<Point> Shape2D::get_Points_On_Perimeter()
{
	return this->points_on_perimeter_;
}

void Shape2D::set_Name(const std::string& name)
{
	name_ = name;
}

void Shape2D::set_Contain_Warp_Space(const bool& contain_Warp_Space)
{
	contain_warp_space_ = contain_Warp_Space;
}

bool operator<(const std::unique_ptr<Shape2D>& s1, const std::unique_ptr<Shape2D>& s2)
{
	return s1->get_Area() < s2->get_Area();
}

bool operator>(const std::unique_ptr<Shape2D>& s1, const std::unique_ptr<Shape2D>& s2)
{
	return s1->get_Area() > s2->get_Area();
}