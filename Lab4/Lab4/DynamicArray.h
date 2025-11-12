#pragma once
#include <string>

class DynamicArray {
private:
    int* m_arr;
    int m_size;

public:
    // Constructors
    DynamicArray();
    DynamicArray(const DynamicArray& other);
    DynamicArray(int size, int* arr);

public:
    // Methods
    int getAt(int idx) const;
    void PushBack(int value);

public:
    std::string ToString() const;
    friend std::ostream& operator << (std::ostream& os, const DynamicArray* da);
    friend std::istream& operator >> (std::istream& is, DynamicArray& da);

public:
    // Destructor
    ~DynamicArray();
};