#include <iostream>
#include <string>
#include <sstream>
#include "DynamicArray.h"

DynamicArray::DynamicArray() :
    m_arr(nullptr), m_size(0) {
}

DynamicArray::DynamicArray(const DynamicArray& other) {
    m_size = other.m_size;
    m_arr = (int*)calloc(m_size, sizeof(int));

    if (!m_arr) return;

    std::copy(other.m_arr, other.m_arr + m_size, m_arr);
}

DynamicArray::DynamicArray(int size, int* arr) {
    if (size <= 0) {
        m_size = 0;
        m_arr = nullptr;
        return;
    }

    m_size = size;
    m_arr = (int*)calloc(m_size, sizeof(int));
    if (!m_arr) return;

    std::copy(arr, arr + m_size, m_arr);
}

int DynamicArray::getAt(int idx) const {
    if (idx < 0 || idx >= m_size) return -1;
    return m_arr[idx];
}

void DynamicArray::PushBack(int value) {
    int* new_arr = (int*)calloc(m_size + 1, sizeof(int));
    if (!new_arr) return;

    std::copy(m_arr, m_arr + m_size, new_arr);
    new_arr[m_size] = value;

    if (m_arr) free(m_arr), m_arr = nullptr;

    m_arr = new_arr;
    m_size++;
}

std::string DynamicArray::ToString() const {
    std::stringstream ss;
    //std::cout << 1;
    ss << "Dynamic Array: Size = " << m_size << "\n";
    ss << "Element ";
    for (int i = 0; i < m_size; i++)
        ss << m_arr[i] << " ";
    ss << "\n";
    
    return ss.str();

}

std::istream& operator >> (std::istream& is, DynamicArray& da) {
    std::string buffer;
    int sz, * arr = nullptr;

    bool ok = false;

    while (!ok) {
        std::cout << "Enter the size of array and the element" << "\n";
        std::getline(is, buffer);
		std::stringstream ss(buffer);
        if (ss >> sz) {
            if (sz < 0) continue;
            arr = (int*)calloc(sz, sizeof(int));
            if (!arr) continue;
            bool flag = true;
            for (int i = 0; i < sz; i++) 
                if (!(ss >> arr[i])) {
                    flag = false;
                    break;
                }
            if (flag) ok = true;
            else 
                if (arr) free(arr), arr = nullptr;
        }
        if (!ok) std::cout << "Invalid input. Please enter again" << "\n";
    }
    if (da.m_arr) free(da.m_arr), da.m_arr = nullptr;
    da.m_size = sz;
    if (arr) da.m_arr = arr;
  /*  for (int i = 0; i < sz; i++)
        std::cout << da.m_arr[i] << " ";*/
    return is;
}

std::ostream& operator << (std::ostream& os,const DynamicArray* da) {
    os << da -> ToString();
    return os;
}

DynamicArray::~DynamicArray() {
    if (m_arr) free(m_arr), m_arr = 0;
    m_size = 0;
}