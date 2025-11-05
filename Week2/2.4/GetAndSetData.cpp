#include <iostream>
#include <cstdlib>
#include "Define.h"

// get the size of array
int Array:: getSize() {
    return m_size;
}

// set the size of array
void Array:: setSize (int new_size) {
    if (new_size <= 0) throw std::invalid_argument("Size must be greater than 0");

    // allocate memory
    int *new_arr = (int*) realloc(m_arr , new_size * sizeof(int));
    if (!new_arr) throw std::bad_alloc();
    m_arr = new_arr;
    
    // set the value of new elements to 0
    if (new_size > m_size) 
        for (int i = m_size; i < new_size; i++)
            m_arr[i] = 0;
    m_size = new_size;
}

// get the element at specified index
int Array:: getElement (int idx) {
    if (idx < 0 || idx >= m_size) throw std::out_of_range("Index out of range");
    return m_arr[idx];
}

void Array:: setElement (int idx , int value) {
    if (idx < 0 || idx >= m_size) throw std::out_of_range("Index out of range");
    m_arr[idx] = value;
}