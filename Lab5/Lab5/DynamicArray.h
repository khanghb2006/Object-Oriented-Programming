#pragma once
#include <string>
#include <vector>

class DynamicArray {
    private:
        int* m_arr;
        int m_size;

    public:
        static DynamicArray* Parse(std::string line, std::string seperator);

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
        // Destructor
        ~DynamicArray();
};