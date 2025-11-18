#include <iostream>
#include <string>
#include <vector>

// include header files
#include "CPoint.h"
#include "Date.h"
#include "CCircle.h"
#include "CLine.h"
#include "CRectangle.h"
#include "CTriangle.h"
#include "DynamicArray.h"
#include "Fraction.h"

int main() {
	// CPoint test
	CPoint* point = CPoint::Parse("(3, 4)" , ", ");
	std::cout << "Point (" << point->get_x() << ", " << point->get_y() << ")" << "\n";
	delete point, point = nullptr;

	// CRectangle test
	CRectangle* rectangle = CRectangle::Parse("(0, 5), (5, 0)" , ", ");
	std::cout << "Rectangle [(" << rectangle->get_topLeft().get_x() << ", " << rectangle->get_topLeft().get_y() << "), ("
		<< rectangle->get_bottomRight().get_x() << ", " << rectangle->get_bottomRight().get_y() << ")]" << "\n";
	delete rectangle, rectangle = nullptr;

	// CTriangle test
	CTriangle* triangle = CTriangle::Parse("(0, 0), (5, 0), (0, 5)", ", ");
	std::cout << "Triangle [(" << triangle->get_A().get_x() << ", " << triangle->get_A().get_y() << "), ("
		<< triangle->get_B().get_x() << ", " << triangle->get_B().get_y() << "), ("
		<< triangle->get_C().get_x() << ", " << triangle->get_C().get_y() << ")]" << "\n";
	delete triangle, triangle = nullptr;
	
	//CCircle test
	CCircle* circle = CCircle::Parse("(2, 3), 5", ", ");
	std::cout << "Circle [Center: (" << circle->get_center().get_x() << ", " << circle->get_center().get_y() << "), Radius: "
		<< circle->get_radius() << "]" << "\n";
	delete circle, circle = nullptr;

	//Fraction test
	Fraction* fraction = Fraction::Parse("3/4", "/");
	std::cout << "Fraction: " << fraction->get_num() << "/" << fraction->get_den() << "\n";
	delete fraction, fraction = nullptr;

	//DynamicArray test
	DynamicArray* dynArr = DynamicArray::Parse("1, 2, 3, 4, 5", ", ");
	std::cout << "Dynamic Array: ";
	for (int i = 0; i < 5; i++) 
		std::cout << dynArr->getAt(i) << " ";
	std::cout << "\n";
	delete dynArr, dynArr = nullptr;

	// Date test
	Date* date = Date::Parse("25/12/2023", "/");
	std::cout << "Date: " << date->get_day() << "/" << date->get_month() << "/" << date->get_year() << "\n";
	delete date, date = nullptr;
	
	return 0;
}