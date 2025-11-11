#pragma once

class Array {
    private:
        int *m_arr;
        int m_size;
    public:
        Array();
        Array (int size);
        Array (const int arr[] , int size);
        Array (const Array &other);
        ~Array();
};