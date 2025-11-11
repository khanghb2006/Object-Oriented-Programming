#include <iostream>
#include <string>
#include <sstream>
#include "DynamicArray.h"

DynamicArray::DynamicArray() :
    m_arr(nullptr) , m_size(0) {}

DynamicArray::DynamicArray(const DynamicArray& other) {
    m_size = other.m_size;
    m_arr = (int*) calloc(m_size , sizeof(int));
    
    if (!m_arr) return;

    std::copy(other.m_arr , other.m_arr + m_size , m_arr);
}

DynamicArray::DynamicArray(int size , int *arr) {
    if (size <= 0) {
        m_size = 0;
        m_arr = nullptr;
        return;
    }

    m_size = size;
    m_arr = (int*) calloc(m_size , sizeof(int));
    if (!m_arr) return;

    std::copy(arr , arr + m_size , m_arr);
}

int DynamicArray::getAt(int idx) const {
    if (idx < 0 || idx >= m_size) return -1;
    return m_arr[idx];
}

void DynamicArray::PushBack(int value) {
    int *new_arr = (int*) calloc(m_size + 1 , sizeof(int));
    if (!new_arr) return;

    std::copy(m_arr , m_arr + m_size , new_arr);
    new_arr[m_size] = value;

    if (m_arr) free(m_arr) , m_arr = nullptr;

    m_arr = new_arr;
    m_size++;
}

std::string DynamicArray::ToString() const{
    std::stringstream ss;
    ss << "Dynamic Array: " << m_size << "\n"; 
    for (int i = 0; i < m_size; i++)
        ss << m_arr[i] << " ";
    ss << "\n";
    return ss.str();

}

std::istream& operator >> (std::istream &is , DynamicArray &da) {
    std::string buffer;
    std::stringstream ss;
    int sz , *arr;

    while(true) {
        std::cout << "Enter the size of array and the element" << "\n";
        std::getline(is , buffer);
        ss.clear();
        ss.str(buffer);
        if (ss >> sz) {
            arr = (int*) calloc(sz , sizeof(int));
            bool flag = true;
            for (int i = 0; i < sz; i++)
                if (!(ss >> arr[i])) {
                    flag = false;
                    break;
                }
            if (flag) {
                da.m_size = sz;
                if (da.m_arr) delete da.m_arr , da.m_arr = nullptr;
                da.m_arr = arr;
                break;
            }
            if (!flag) free(arr) , arr = nullptr;
        }
        std::cout << "Invalid input. Please enter again" << "\n";
    }
    return is;
}

std::ostream& operator << (std::ostream &os , DynamicArray *da) {
    os << da->ToString();
    return os;
}

DynamicArray::~DynamicArray() {
    if (m_arr) free(m_arr) , m_arr = 0;
    m_size = 0;
}