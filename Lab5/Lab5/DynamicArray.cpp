#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <sstream>

// include header files
#include "DynamicArray.h"

DynamicArray* DynamicArray::Parse(std::string line, std::string seperator) {
    // lamda to check valid characters
    auto valid = [](char x) {
        return (isdigit(x) || x == '-' || x == '.');
        };

    std::vector<int> tokens;
    std::string valid_sub;

    while (line.find(seperator) != std::string::npos) {
        // get substring before seperator
        std::string sub = line.substr(0, line.find(seperator));

        // get valid characters only
        valid_sub = "";
        std::copy_if(sub.begin(), sub.end(), std::back_inserter(valid_sub), valid);
		int x = std::stoi(valid_sub);
        tokens.push_back(x);
        line = line.substr(line.find(seperator) + seperator.size(), std::string::npos);
    }

    // get the last token
    valid_sub = "";
    std::copy_if(line.begin(), line.end(), std::back_inserter(valid_sub), valid);
	int x = std::stoi(valid_sub);
    tokens.push_back(x);
    return new DynamicArray((int) tokens.size(), tokens.data());
}

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

DynamicArray::~DynamicArray() {
    if (m_arr) free(m_arr), m_arr = 0;
    m_size = 0;
}