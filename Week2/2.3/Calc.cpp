#include <iostream>
#include "Define.h"

double Student:: calculateGPA() {
    return 1.00 * (m_literature_point + m_math_point) / 2;
}

char Student:: grade() {
    double gpa = calculateGPA();
    return (gpa >= 9) ? 'A' : (gpa >= 7) ? 'B' : (gpa >= 5) ? 'C' : 'D';
}