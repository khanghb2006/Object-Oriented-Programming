#include <iostream>
#include <algorithm>
#include "DynamicArray.h"

DynamicArray::DynamicArray(const DynamicArray& other)
	: m_arr(nullptr), m_size(other.m_size)
{
	m_arr = (int*)calloc(other.m_size, sizeof(int));
	if (!m_arr) return;
	m_arr = std::copy(other.m_arr, other.m_arr + other.m_size , m_arr);
	m_size = other.m_size;
}

DynamicArray::DynamicArray(int size, int* arr)
	: m_arr(nullptr), m_size(size)
{
	m_arr = (int*)calloc(size, sizeof(int));
	if (!m_arr) return;
	std::copy(arr, arr + size, m_arr);
}

void DynamicArray::PushBack(int value) {
	if (!m_size) {
		m_arr = (int*)calloc(m_size + 1, sizeof(int));
		if (!m_arr) return;
		m_arr[m_size++] = value;
	}
	else {
		int* buffer = (int*)realloc(m_arr, (m_size + 1) * sizeof(int));
		if (!buffer) return;
		m_arr = buffer;
		m_arr[m_size++] = value;
	}
}

int DynamicArray::getAt(int idx) {
	return m_arr[idx];
}