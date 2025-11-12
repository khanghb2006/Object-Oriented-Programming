#include <iostream>
#include "CPoint.h"
#include "CCircle.h"
#include "CLine.h"
#include "CRectangle.h"
#include "DynamicArray.h"
#include "Fraction.h"

int main() {
	//// Circle
	std::cout << "Circle Input" << "\n";
	CCircle* cir = new CCircle();
	std::cin >> (*cir);
	std::cout << cir;
	if (cir) delete cir, cir = nullptr;

	////Line
	std::cout << "Line Input" << "\n";
	CLine* line = new CLine();
	std::cin >> (*line);
	std::cout << line;
	if (line) delete line, line = nullptr;

	//// Rectangle
	std::cout << "Rectangle Input" << "\n";
	CRectangle* rect = new CRectangle();
	std::cin >> (*rect);
	std::cout << rect;
	if (rect) delete rect, rect = nullptr;

	//// Dynamic Array
	std::cout << "Dynamic Array Input" << "\n";
	DynamicArray* arr = new DynamicArray();
	std::cin >> (*arr);
	std::cout << arr;
	if (arr) delete arr, arr = nullptr;

	//Fraction
	std::cout << "Fraction Input" << "\n";
	Fraction* f = new Fraction();
	std::cin >> (*f);
	std::cout << f;
	if (f) delete f, f = nullptr;
}