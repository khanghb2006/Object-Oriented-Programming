#pragma once
#include <algorithm>
#include <iostream>

template <class T>
class Array {
    private:
        T* m_arr;
        size_t m_size;
    public:
        // Constructor
        Array() : m_arr(NULL) , m_size(0) {}
        Array (const Array &arr);
        Array (T *arr , size_t size);

    public:
        // Comparision operator
        bool operator == (const Array &arr);
        // Assignment operator
        Array& operator = (const Array &arr);

    public:
        //Type cast
        operator T* ();
        //Array indexer operator
        const T& operator [] (size_t idx);

    public:
        // Input operator
        template <class T1>
        friend std::istream& operator >> (std::istream &in , Array<T1> &arr);

        // Output operator 
        template <class T1>
        friend std::ostream& operator << (std::ostream &os , const Array<T1> &arr);

        // Destructor
        ~Array();
};

// Constructor
template <class T>
Array<T>::Array (const Array &arr) {
    m_arr = (T*) calloc(arr.m_size , sizeof(T));
    if (m_arr) {
        m_size = arr.m_size;
        std::copy_n(arr.m_arr , m_size , m_arr);
    }
}

template <class T>
Array<T>::Array (T *arr , size_t size) {
    m_arr = (T*) calloc(size , sizeof(T));
    if (m_arr) {
        m_size = size;
        std::copy_n(arr , m_size , m_arr);
    }
}

// Comparision operator
template <class T>
bool Array<T>::operator == (const Array &arr) {
    if (m_size != arr.m_size) return false;
    for (size_t i = 0; i < m_size; i++)
        if (m_arr[i] != arr.m_arr[i]) return false;
    return true;
}

// Assignment operator
template <class T>
Array<T>& Array<T>::operator = (const Array &arr) {
    if (*this == arr) return *this;
    free(m_arr);
    m_arr = (T*) calloc(arr.m_size , sizeof(T));
    if (!m_arr) 
        throw std::bad_alloc();
    m_size = arr.m_size;
    std::copy_n(arr.m_arr , m_size , m_arr);
    return *this;
}

// Array indexer operator
template <class T>
const T& Array<T>::operator [] (size_t idx) {
    if (idx >= m_size)
        throw std::out_of_range("Array index out of range");
    return m_arr[idx];
}

// Type cast operator
template <class T>
Array<T>::operator T* () {
    return m_arr;
}

// Input operator
template <class T>
std::istream& operator >> (std::istream &is , Array<T> &arr) {
    is >> arr.m_size;
    arr.m_arr = (T*) calloc(arr.m_size , sizeof(T));
    for (size_t i = 0; i < arr.m_size; i++)
        is >> arr.m_arr[i];
    return is;
}

// Output operator
template <class T>
std::ostream& operator << (std::ostream &os , const Array<T> &arr) {
    for (size_t i = 0; i < arr.m_size; i++) 
        os << arr.m_arr[i] << " ";
    return os;
}

// Destructor
template <class T>
Array<T>::~Array() {
    free(m_arr);
    m_arr = NULL;
    m_size = 0;
}