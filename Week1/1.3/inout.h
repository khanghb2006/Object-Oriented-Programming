#pragma once

//Input array
template <class T>
void Input (T *& arr , int &size) {

    std::cout << "Enter the size of array" << "\n";
    std::cin >> size;
    if(size <= 0) throw std::invalid_argument("The size must be greater than 0");

    arr = new T[size];

    // To use in Struct we need to add operator >> 
    for (int i = 0; i < size; i++) {
        std::cout << "Enter the " << i + 1 << " element" << "\n";
        std::cin >> arr[i];
    }
}

//Output array
template <class T>
void Output (T *arr , int size) {
    // To use in Struct wee need to add operator << 
    for (int i = 0; i < size; i++)
        std::cout << arr[i] << "\n";
}