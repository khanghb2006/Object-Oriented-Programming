#pragma once
#include <iostream>
#include "Monomial.h"

class Polynomial {
    private:
        Monomial *m_poly;
        size_t m_degree;

    // Big Three Principle    
    public:
        // Constructor
        Polynomial() : m_poly(nullptr) , m_degree(0) {}
        Polynomial(size_t m_degree , double *array_coef);
        Polynomial(const Polynomial &other);

        // Assignment operator
        Polynomial operator = (Polynomial other) {
            std::swap(m_poly , other.m_poly);
            std::swap(m_degree , other.m_degree);
            return *this;
        }

        // Destructor
        ~Polynomial() {
            if (m_poly) 
                free(m_poly);
            m_degree = 0;
        }

    public:
        // Getters
        size_t getDegree() const {return m_degree;}
        double getCoefAt (size_t index) const {
            if (index > m_degree)
                throw std::out_of_range("Index out of range");
            return m_poly[index].isZero() ? 0 : m_poly[index].getCoef();
        }

        // Setters
        void setCoefAt (size_t degree , double new_coef);
        void setDegree (size_t new_degree);
    public:
        // Arithmetic operator
        Polynomial operator + (const Polynomial &other);
        Polynomial operator - (const Polynomial &other);
        Polynomial operator * (const Polynomial &other);

    public:
        // Comparision operator
        bool operator < (const Polynomial &other);
        bool operator > (const Polynomial &other);
        bool operator <= (const Polynomial &other);
        bool operator >= (const Polynomial &other);
        bool operator == (const Polynomial &other);
        bool operator != (const Polynomial &other);

    public:
        // Derivative and anti-derivative
        Polynomial operator ! ();
        Polynomial operator ~ ();

    public:
        // Input and output
        friend std::ostream& operator << (std::ostream &os , const Polynomial &p);
        friend std::istream& operator >> (std::istream &is , Polynomial &p);
};