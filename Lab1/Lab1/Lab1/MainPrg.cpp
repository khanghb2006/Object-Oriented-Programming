#include <iostream>
#include "CPoint.h"
#include "CCircle.h"

int main() {
	CCircle c(0, 0, 2);
	std::cout << (double) c.Area();
}