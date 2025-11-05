#include <iostream>
#include "Define.h"

template <class T>
void Array:: shift (int left , int right , bool (*cmp) (T , T)) {
    int i = left , j = 2 * i + 1 , x = m_arr[i];
    while (j <= right) {
        if (j < right)
            if (cmp(m_arr[j] , m_arr[j + 1])) j++;
        if (x >= m_arr[j]) break;
        m_arr[i] = m_arr[j], i = j , j = 2 * i + 1;
    }
    m_arr[i] = x;
}

template <class T>
int* Array:: HeapSort(bool (*cmp) (T , T)) {
    int n = m_size - 1;
    int left = n / 2;
    while (left >= 0) 
        shift<T> (left-- , n , cmp);
    int right = n;
    while (right > 0) {
        std::swap (m_arr[0] , m_arr[right]);
        shift<T> (0 , --right , cmp);
    }
}