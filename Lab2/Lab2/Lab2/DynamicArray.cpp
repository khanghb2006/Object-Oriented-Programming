#include <iostream>
#include "DynamicArray.h"

void DynamicArray::PushBack(int x) {
	if (!m_len) {
		m_arr = (int*)calloc(m_len + 1, sizeof(int));
		if (m_arr) m_arr[m_len++] = x;
	}
	else {
		int* buffer = (int*)realloc(m_arr, (m_len + 1) * sizeof(int));
		if (buffer) {
			m_arr = buffer;
			m_arr[m_len++] = x;
		}
	}
}