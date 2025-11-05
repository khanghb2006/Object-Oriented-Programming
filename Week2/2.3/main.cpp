#include <iostream>
#include "Define.h"

int main() {
    Student s;
    try {
        // s.input();
        // s.output();
    }
    catch (std::invalid_argument &e) {
        std::cout << e.what() << "\n";
    }
}