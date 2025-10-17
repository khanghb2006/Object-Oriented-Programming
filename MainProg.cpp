#include <iostream>
#include "CPoint.h"

int main() {
	CPoint* p = new CPoint(7, 5);
	std::cout << "Point" <<  p->GetX() << " " << p->GetY() << "\n";
	delete p;
}