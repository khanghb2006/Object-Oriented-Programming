#include <iostream>
#include "Array.h"

int main() {
    try {
        Array *arr1 = new Array(5);
        Array *arr2 = new Array(*arr1);

        int *arr = new int[4]{1 , 2 , 3 , 4};
        Array *arr3 = new Array(arr , 4);
        delete[] arr;
        delete arr1;
        delete arr2;
        delete arr3;
    }
    catch (const std::exception &e) {
        std::cerr << "Error: " << e.what() << std::endl;
    }
}