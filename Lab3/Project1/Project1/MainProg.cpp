#include <iostream>
#include <string>
#include <sstream>
#include "CPoint.h"
#include "CLine.h"
#include "CRectangle.h"
#include "DynamicArray.h"

int main() {
	CLine *line1 = new CLine(CPoint(3.0, 4.0), CPoint(7, 5));
	CLine line2(*line1); // copy line1 to line2
	std::cout << "Copy CLine " << line2.get_start().get_x() << " " << line2.get_start().get_y() << " "
		<< line2.get_end().get_x() << " " << line2.get_end().get_y() << "\n";
	std::cout << "CLine CountInstance " << CLine::InstanceCount << "\n";

	CRectangle *rect1 = new CRectangle(CPoint(2, 10), CPoint(10, 5));
	CRectangle rect2(*rect1); // copy rect1 to rect2
	std::cout << "Copy CRectangle " << rect2.get_topLeft().get_x() << " " << rect2.get_topLeft().get_y()
		<< " " << rect2.get_bottomRight().get_x() << " " << rect2.get_bottomRight().get_y() << "\n";
	std::cout << "CRectangle CountInstance " << CRectangle::InstanceCount << "\n";

	delete line1;
	line1 = nullptr;
	std::cout << "CLine CountInstance after delete line1 " << CLine::InstanceCount << "\n";

	delete rect1;
	rect1 = nullptr;
	std::cout << "CRectangle CountInstance after delete line2 " << CRectangle::InstanceCount << "\n";

	// DynamicArray
	int Size, * buffer;

	std::cout << "Moi thay nhap Dynamic Array" << "\n";
	std::cout << "Moi thay nhap so phan tu: ";
	std::cin >> Size;
	std::cout << "Moi thay nhap cac phan tu: " << "\n";
	buffer = (int*)calloc(Size, sizeof(int));
	for (int i = 0; i < Size; i++) {
		std::cout << "Moi thay nhap phan tu thu " << i + 1 << ": ";
		std::cin >> buffer[i];
		//std::cout << "\n";
	}
	DynamicArray arr(Size, buffer);

	std::cout << "Co 2 thao tac chinh cua Dynamic Array: " << "\n";
	std::cout << "add x : them phan tu x vao cuoi mang" << "\n";
	std::cout << "get x : lay phan tu tai vi tri x" << "\n";
	std::cout << "stop : ket thuc chuong trinh" << "\n";

	std::string command;
	std::stringstream ss;
	std::cout << "Moi thay nhap cac thao tac" << "\n";
	std::cin.ignore();
	while (true) {
		std::getline(std::cin, command);
		ss.clear();
		ss.str(command);
		std::string subcmd;
		int value;
		ss >> subcmd >> value;
		if (subcmd == "add") {
			arr.PushBack(value);
			std::cout << "Da them " << value << " vao cuoi mang" << "\n";
		}
		else if (subcmd == "get") {
			std::cout << "Phan tu tai vi tri " << value << " la: ";
			std::cout << arr.getAt(value) << "\n";
		}
		else break;
	}
}