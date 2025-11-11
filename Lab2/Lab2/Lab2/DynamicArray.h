#pragma once
#include <iostream>

class DynamicArray {
private:
	int* m_arr;
	int m_len;
public:
	// Constructure
	DynamicArray() : m_arr(nullptr), m_len(0) {}

	// Destructure
	~DynamicArray() {
		free(m_arr);
		m_arr = nullptr;
		m_len = 0;
	}

public:
	// Methods
	int get_size() { return m_len; }
	void PushBack(int value);
	int getAt(int idx) { return m_arr[idx];  }
};