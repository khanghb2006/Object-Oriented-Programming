#include <iostream>
#include "Student.h"

int main () {
    try {
        Student *s0 = new Student ("Khang");
        Student *s1 = new Student ("Khang", 8.5, 9.0);
        Student *s2 = new Student (*s1);

        delete s0;
        delete s1;
        delete s2;
    }
    catch (const std::out_of_range &e) {
        std::cout << e.what() << "\n";
    }
}