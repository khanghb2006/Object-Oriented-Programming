#include <iostream>
#include "Define.h"

int Array:: find (int value) {
    for (int i = 0; i < m_size; i++) 
        if (m_arr[i] == value) 
            return i;
    return -1;
}