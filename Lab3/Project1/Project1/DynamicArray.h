#pragma once

class DynamicArray {
private:
	int* m_arr;
	int m_size;

public:
	// Constructor
	DynamicArray() : m_arr(nullptr), m_size(0) {}
	DynamicArray(const DynamicArray& other);
	DynamicArray(int size, int* arr);

public:
	// Methods
	void PushBack(int value);
	int getAt(int idx);

public:
	// Destructor
	~DynamicArray() {
		if (m_arr) {
			delete m_arr;
			m_arr = nullptr;
		}
		m_size = 0;
	}
};