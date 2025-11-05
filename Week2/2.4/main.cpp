#include <iostream>
#include "Define.h"
#include "sort.h"

bool ascending (int a , int b) {
    return a < b;
}   

int main() {
    Array arr;
    try {
        // arr.input();
        // arr.output();

        // // Get element at index 2
        // arr.getElement(2);
        // int *sorted_arr = arr.HeapSort(ascending);
        // std::cout << "Sorted array (ascending): ";
        // arr.output();

        // // set size
        // arr.setSize(4);
        // arr.output();

        // // set element at index 3
        // arr.setElement(3, 5);
        // arr.output();

        // // set size
        // arr.setSize(3);
        // arr.output();
    } 
    catch (const std::exception &e) {
        std::cerr << "Error: " << e.what() << std::endl;
    }
}