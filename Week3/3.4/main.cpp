#include <iostream>
#include "Array.h"

int main() {
    try {
        Array<int> *arr1 = new Array<int>(5);
        Array<int> *arr2 = new Array<int>(*arr1);

        double *arr = new double [4] {1.1, 2.2, 3.3, 4.4};
        Array<double> *arr3 = new Array<double>(arr, 4);

        delete arr1;
        delete arr2;
        delete[] arr;
        delete arr3;
    }
    catch (const std::invalid_argument &e) {
        std::cout << e.what() << '\n';
    }
}