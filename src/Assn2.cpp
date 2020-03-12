#include "Assn2.h"

// Driver class Assn2
int Assn2::main()
{
	int choice;
	do
	{
		std::cout << "Student ID            : 5281568" << std::endl;
		std::cout << "Student Name          : Yosua Martiansia" << std::endl;
		std::cout << std::setfill('-') << std::setw(50) << "-" << std::endl;

		std::cout << "Welcome to Assn2 Program!" << std::endl;
		std::cout << std::endl;

		std::cout << "1) Input Sensor Data" << std::endl;
		std::cout << "2) Compute Area (for all Records)" << std::endl;
		std::cout << "3) Print shapes report" << std::endl;
		std::cout << "4) Sort shape data" << std::endl;

		std::cout << std::endl;

		std::cout << "Please enter your choice:";
		std::cin >> choice;

		switch (choice)
		{
		case 1:
			input_Sensor_Data();
			break;
		case 2:
			compute_Area_For_All();
			break;
		case 3:
			print_Shapes_Report();
			break;
		case 4:
			sort_Shape_Data();
			break;
		}
	} while (choice != 9);

	return 0;
}

// Function to get user to input the sensor data
void Assn2::input_Sensor_Data()
{
	std::string shape_name;
	std::string warp_space;
	bool contain_warp_space;

	std::cout << std::endl;
	std::cout << "[Input Sensor Data]" << std::endl;
	std::cout << "Please enter name of shape: ";
	std::cin >> shape_name;

	std::cout << "Please enter special type: ";
	std::cin >> warp_space;
	for (auto i = warp_space.begin(); i != warp_space.end(); i++)
	{
		*i = tolower(*i);
	}

	for (auto i = shape_name.begin(); i != shape_name.end(); i++)
	{
		*i = tolower(*i);
	}

	std::cout << std::endl;

	// After the user key in the shape name, and the special type, a check will be done to determine which class should be constructed
	if (warp_space.compare("ns") == 0)
		contain_warp_space = false;
	else if (warp_space.compare("ws") == 0)
		contain_warp_space = true;
	if (shape_name.compare("circle") == 0)
		construct_Circle(contain_warp_space);
	else if (shape_name.compare("square") == 0)
		construct_Square(contain_warp_space);
	else if (shape_name.compare("rectangle") == 0)
		construct_Rectangle(contain_warp_space);
	else if (shape_name.compare("cross") == 0)
		construct_Cross(contain_warp_space);
}

/*
For each of the 4 construct function below, individual implementation will be done to get all the necessary data to construct that class
*/
void Assn2::construct_Circle(const bool &warp_space)
{
	int x, y, radius;

	std::cout << "Please enter x-ordinate of center : ";
	std::cin >> x;

	std::cout << "Please enter y-ordinate of center : ";
	std::cin >> y;

	std::cout << std::endl;

	std::cout << "Please enter radius (units) : ";
	std::cin >> radius;

	std::cout << std::endl;

	Shapes_.push_back(std::make_unique<Circle>(Point(x, y), radius, warp_space));
	record_count_++;

	std::cout << "Record successfully stored. Going back to main menu ... " << std::endl;
	std::cout << std::endl;
}

void Assn2::construct_Square(const bool &warp_space)
{
	int x, y;
	std::array<Point, 4> vertices;

	for (int i = 0; i < 4; i++)
	{
		x = 0;
		y = 0;

		std::cout << "Please enter x-ordinate of pt." << i + 1 << " : ";
		std::cin >> x;
		std::cout << "Please enter y-ordinate of pt." << i + 1 << " : ";
		std::cin >> y;
		std::cout << std::endl;

		vertices[i] = Point(x, y);
	}

	std::cout << std::endl;

	Shapes_.push_back(std::make_unique<Square>(vertices, warp_space));
	record_count_++;

	std::cout << "Record successfully stored. Going back to main menu ... " << std::endl;
	std::cout << std::endl;
}

void Assn2::construct_Rectangle(const bool &warp_space)
{
	int x, y;
	std::array<Point, 4> vertices;

	for (int i = 0; i < 4; i++)
	{
		x = 0;
		y = 0;

		std::cout << "Please enter x-ordinate of pt." << i + 1 << " : ";
		std::cin >> x;
		std::cout << "Please enter y-ordinate of pt." << i + 1 << " : ";
		std::cin >> y;
		std::cout << std::endl;

		vertices[i] = Point(x, y);
	}

	Shapes_.push_back(std::make_unique<Rectangle>(vertices, warp_space));
	std::cout << std::endl;

	record_count_++;

	std::cout << "Record successfully stored. Going back to main menu ... " << std::endl;
	std::cout << std::endl;
}

void Assn2::construct_Cross(const bool &warp_space)
{
	int x, y;
	std::array<Point, 12> vertices;

	for (int i = 0; i < 12; i++)
	{
		x = 0;
		y = 0;

		std::cout << "Please enter x-ordinate of pt." << i + 1 << " : ";
		std::cin >> x;
		std::cout << "Please enter y-ordinate of pt." << i + 1 << " : ";
		std::cin >> y;
		std::cout << std::endl;

		vertices[i] = Point(x, y);
	}

	std::cout << std::endl;

	Shapes_.push_back(std::make_unique<Cross>(vertices, warp_space));
	record_count_++;

	std::cout << "Record successfully stored. Going back to main menu ... " << std::endl;
	std::cout << std::endl;
}

// As area is already computed in the initialization of the class, compute_Area() only outputs the current number of record
void Assn2::compute_Area_For_All()
{
	std::cout << std::endl;
	std::cout << "Computation completed! (" << record_count_ << " records were updated)" << std::endl;
	std::cout << std::endl;
}

/*
Function to print the shape report
Format as follows
Shape [i] = Shape_Name, WS/NS, Area, vertices
Points in shape
Points on perimeter
*/

void Assn2::print_Shapes_Report()
{
	std::cout << std::endl;
	std::cout << "Total no. of records available = " << record_count_ << std::endl;
	std::cout << std::endl;

	for (int i = 0; i < Shapes_.size(); i++)
	{
		std::cout << "Shapes[" << i << "] = " << Shapes_[i]->to_String() << std::endl;
		if (Shapes_[i]->get_Points_Within_Shape().empty())
		{
			std::cout << "No Points within shape" << std::endl;
		}
		else
		{
			std::cout << "Points within Shape : ";
			for (auto it : Shapes_[i]->get_Points_Within_Shape())
			{
				if (it == Shapes_[i]->get_Points_Within_Shape().back())
					std::cout << "(" << it.get_X() << ", " << it.get_Y() << ")";
				else
					std::cout << "(" << it.get_X() << ", " << it.get_Y() << "), ";
			}
			std::cout << std::endl;
		}

		if (Shapes_[i]->get_Points_On_Perimeter().empty())
		{
			std::cout << "No Points on shape" << std::endl;
		}
		else
		{
			std::cout << "Points on Shape: ";
			for (auto it : Shapes_[i]->get_Points_On_Perimeter())
			{
				if (it == Shapes_[i]->get_Points_On_Perimeter().back())
					std::cout << "(" << it.get_X() << ", " << it.get_Y() << ")";
				else
					std::cout << "(" << it.get_X() << ", " << it.get_Y() << "), ";
			}
			std::cout << std::endl;
		}
		std::cout << std::endl;
	}

	std::cout << std::endl;
}

// Sort the shape data according to the criteria given by the user
void Assn2::sort_Shape_Data()
{
	std::cout << std::endl;
	std::cout << "[Sorting Shape Data]" << std::endl;
	std::cout << std::endl;

	std::cout << "a) Sort by Area(Ascending)" << std::endl;
	std::cout << "b) Sort by Area(Descending)" << std::endl;
	std::cout << "c) Sort by special type and area" << std::endl;

	char option;
	std::cout << std::endl;
	std::cout << "Please select sort option : ";
	std::cin >> option;

	std::cout << std::endl;

	switch (option)
	{
	case 'a':
		std::cout << "Sort by area (smallest to largest)" << std::endl;
		std::cout << std::endl;
		std::sort(Shapes_.begin(), Shapes_.end());
		print_Shapes_Report();
		break;
	case 'b':
		std::cout << "Sort by area (largest to smallest)" << std::endl;
		std::cout << std::endl;
		std::sort(Shapes_.rbegin(), Shapes_.rend());
		print_Shapes_Report();
		break;
	case 'c':
		std::cout << "Sort by special type and area (largest to smallest)" << std::endl;
		std::sort(Shapes_.rbegin(), Shapes_.rend());
		std::stable_partition(Shapes_.begin(), Shapes_.end(), [](const std::unique_ptr<Shape2D> &s) { return s->get_Contain_Warp_Space(); });
		print_Shapes_Report();
		break;
	}
}