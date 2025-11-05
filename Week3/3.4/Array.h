#pragma once

template <class T>
class Array {
    private:
        T* m_arr;
        int m_size;
    public:
        Array();
        Array (int size);
        Array (const T arr[] , int size);
        Array (const Array<T>& arr);
        ~Array();
};

template<class T>
Array<T>::Array(): 
    m_size(0) , m_arr(NULL) {}

template <class T>
Array<T>::Array(int size) {
    if (size < 0) 
        throw std::invalid_argument("Size must be non-negative integer");
    m_size = size;
    m_arr = (T*) calloc (m_size , sizeof(T));

    // for (int i = 0; i < m_size; i++)
    //     std::cout << m_arr[i] << " ";
    // std::cout << std::endl;

    if (!m_arr)
        throw std::bad_alloc();
}

template <class T>
Array<T>::Array (const T arr[] , int size) {
    if (size < 0) 
        throw std::invalid_argument("Size must be non-negative integer");
    if (!arr)
        throw std::invalid_argument("arr is null");

    
    m_arr = (T*) calloc (size , sizeof(T));
    if (!m_arr)
        throw std::bad_alloc();
    m_size = size;
    std::copy (arr , arr + m_size , m_arr);

    // for (int i = 0; i < m_size; i++)
    //     std::cout << m_arr[i] << " ";
    // std::cout << std::endl;
}

template <class T>
Array<T>::Array (const Array<T> &arr) {
    if (m_size > 0) {   
        m_arr = (T*) calloc (arr.m_size , sizeof(T));
        if (!m_arr)
            throw std::bad_alloc();
        m_size = arr.m_size;
        std::copy (arr.m_arr , arr.m_arr + m_size , m_arr);

        // for (int i = 0; i < m_size; i++)
        //     std::cout << m_arr[i] << " ";
        // std::cout << std::endl;
    }
    else m_arr = NULL , m_size = 0;
}

template <class T>
Array<T>::~Array() {
    free(m_arr);
}