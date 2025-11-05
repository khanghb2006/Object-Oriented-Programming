#include <iostream>
#include "Array.h"

Array::Array () :
    m_size(0) , m_arr(NULL) {}

Array::Array (int size) {
    if (size < 0)
        throw std::out_of_range ("size must be non-negative interger");

    if (size > 0) {
        m_arr = (int*) calloc (size , sizeof (int));
        if (!m_arr)
            throw std::bad_alloc();
        m_size = size;

        // for (int i = 0; i < m_size; i++)
        //     std::cout << m_arr[i] << " ";
        // std::cout << "\n";
    }
    else m_arr = NULL;
}

Array::Array (const int arr[] , int size) {
    if (size < 0)
        throw std::out_of_range ("size must be non-negative interger");
    m_size = size;

    if (m_size > 0) {
        if (!arr) throw std::invalid_argument ("arr is null");
        m_arr = (int*) calloc (m_size , sizeof (int));

        if (!m_arr)
            throw std::bad_alloc();
        //copy the value from arr to m_arr
        std::copy (arr , arr + m_size , m_arr);

        // for (int i = 0; i < m_size; i++)
        //     std::cout << m_arr[i] << " ";
        // std::cout << "\n";    
    }
    else m_arr = NULL;
}

Array::Array (const Array &arr) {
    if (m_size > 0) {   
        m_arr = (int*) calloc (arr.m_size , sizeof(int));
        if (!m_arr)
        throw std::bad_alloc();
        m_size = arr.m_size;
        m_arr = arr.m_arr;

        // for (int i = 0; i < m_size; i++)
        //     std::cout << m_arr[i] << " ";
        // std::cout << "\n";
    }
    else m_arr = NULL;
}

Array::~Array() {
    free(m_arr);
}