#pragma once
#include <iostream>

class Array {
    private:
        int m_size;
        int *m_arr;
        template <class T>
        void shift (int left , int right , bool (*cmp) (T , T));

    public:
        void input();
        void output();
        int getSize();
        void setSize (int new_size);
        int getElement (int idx);
        void setElement (int idx , int value);
        int find (int value); // look for an element and return its index, otherwise return -1;
        template <class T>
        int* HeapSort (bool (*cmp) (T , T)); // sort the array with criteria 

    ~Array() {
        free(m_arr);
        m_arr = nullptr;
    }
};