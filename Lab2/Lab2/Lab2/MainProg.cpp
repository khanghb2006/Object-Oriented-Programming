#include <iostream>
#include "CPoint.h"
#include "CCircle.h"
#include "CRectangle.h"
#include "CTriangle.h"
#include "DynamicArray.h"
#include <sstream>

int main() {
	CPoint A(0, 10);
	CPoint B(1, 3);
	CPoint C(10, 5);

	// Circle test
	CCircle c(&A, 5);
	std::cout << "Circle " << c.Perimeter() << " " << c.Area() << '\n';

	// Rectangle test
	CRectangle r(A, C);
	std::cout << "Rectangle " << r.Perimeter() << " " << r.Area() << '\n';

	//Triangle test
	CTriangle t(A, B, C);
	std::cout << "Triangle " << t.Perimeter() << " " << t.Area() << '\n';

	// DynamicArray test
	DynamicArray arr;
	std::cout << "Thua thay, chuong trinh co cac operation sau:" << "\n";
	std::cout << "Neu muon them so thi go add x" << "\n";
	std::cout << "Neu muon lay gia tri thi go get x" << "\n";
	std::cout << "Neu muon dung lai thi go exit" << "\n";

	int x;
	std::string req;
	std::stringstream ss;
	std::string buffer;
	while (true) {
		std::cout << "Moi thay nhap: ";
		std::getline(std::cin, buffer);
		ss.clear();
		ss.str(buffer);
		if (!(ss >> req >> x)) break;
		if (req == "add") {
			arr.PushBack(x);
			std::cout << "Da them " << x << " vao mang" << "\n";
		}
		else if (req == "get") 
			std::cout << "Gia tri tai vi tri " << x << " la " << arr.getAt(x) << "\n";
		else break;
	}
	return 0;
}