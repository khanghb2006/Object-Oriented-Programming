#include <iostream>
#include <sstream>
#include <string.h>
#include "Polynomial.h"
#include "Monomial.h"
#include "Calculate.h"

// a0 + a1*x + a2*x^2 + ... + an*x^n
// n is non-negative integer

//Constructor
Polynomial::Polynomial(size_t degree , double *array_coef) {
    m_poly = (Monomial*) calloc(degree + 1 , sizeof(Monomial));
    if (!m_poly)
        throw std::bad_alloc();
    m_degree = degree;
    for (size_t i = 0; i <= degree; i++)
        m_poly[i] = Monomial(array_coef[i] , i);
}

Polynomial::Polynomial(const Polynomial &other) {
    // Allocate memory for the polynomial
    m_poly = (Monomial*) calloc(other.m_degree + 1 , sizeof(Monomial));
    if (!m_poly) 
        throw std::bad_alloc();

    m_degree = other.m_degree;
    for (size_t i = 0; i <= m_degree; i++)
        m_poly[i] = other.m_poly[i];
}

// Comparision operator
// to compare the max exponnent of two polynomials
bool Polynomial::operator < (const Polynomial &other) {
    // compare by the max exponent of each polynomial
    return m_poly[m_degree] < other.m_poly[other.m_degree];
}

bool Polynomial::operator > (const Polynomial &other) {
    // compare by the max exponent of each polynomial
    return m_poly[m_degree] > other.m_poly[other.m_degree];
}

bool Polynomial::operator <= (const Polynomial &other) {
    return (! (*this > other));
}

bool Polynomial::operator >= (const Polynomial &other) {
    return (! (*this < other));
}

bool Polynomial::operator != (const Polynomial &other) {
    if (m_degree != other.m_degree) return true;
    for (size_t i = 0; i <= m_degree; i++)
        if (m_poly[i] != other.m_poly[i]) return true;
    return false;
}

bool Polynomial::operator == (const Polynomial &other) {
    return (! (*this != other));
}

// Set the coef at specific degree
void Polynomial::setCoefAt(size_t degree , double new_coef) {
    if (degree > m_degree) 
        throw std::out_of_range("the degree is out of range");
    m_poly[degree] = Monomial(new_coef , degree);
}

void Polynomial::setDegree(size_t new_degree) {
    Monomial *new_poly = (Monomial*) calloc(new_degree + 1 , sizeof(Monomial));
    if (!new_poly) 
        throw std::bad_alloc();
    
    size_t min_degree = (new_degree < m_degree) ? new_degree : m_degree;
    for (size_t i = 0; i <= min_degree; i++)
        new_poly[i] = m_poly[i];

    for (size_t i = m_degree + 1; i <= new_degree; i++)
        new_poly[i] = Monomial(0 , i);
    
    // assign new polynomial to this polynomial
    free(m_poly);
    m_poly = new_poly;
    m_degree = new_degree;
    free(new_poly);
    new_poly = nullptr;
}

void swap(Polynomial &p1 , Polynomial &p2) {
    Polynomial temp = p1;
    p1 = p2;
    p2 = temp;
}

//Arithmetics operator
Polynomial Polynomial::operator + (const Polynomial &other) {
    Polynomial p1(*this) , p2(other);
    // ensure that p1 has smaller than p2
    if (p1.m_degree > p2.m_degree) 
        swap(p1 , p2);

    // new p1 for that new p1 have the same degree as p2 so we easy to add
    Polynomial new_p1 = Polynomial(p2);
    new_p1.m_degree = p2.m_degree;
    new_p1.m_poly = (Monomial*) calloc(new_p1.m_degree + 1 , sizeof(Monomial));
    if (!new_p1.m_poly)
        throw std::bad_alloc();

    // copy p1 to new p1
    size_t diff = p2.m_degree - p1.m_degree;
    for (size_t i = 0; i <= p2.m_degree - diff; i++)
        new_p1.m_poly[i] = p1.m_poly[i];
    for (size_t i = p2.m_degree - diff + 1; i <= p2.m_degree; i++)
        new_p1.m_poly[i] = Monomial(0 , i);
    
    // add twp polynomials
    Polynomial result = Polynomial(p2);
    result.m_degree = p2.m_degree;
    result.m_poly = (Monomial*) calloc(result.m_degree + 1 , sizeof(Monomial));
    if (!result.m_poly)
        throw std::bad_alloc();
    for (size_t i = 0; i <= result.m_degree; i++)
        result.m_poly[i] = new_p1.m_poly[i] + p2.m_poly[i];
   
    // free memory
    free(new_p1.m_poly);
    new_p1.m_poly = nullptr;

    return result;
}

Polynomial Polynomial::operator - (const Polynomial &other) {
    Polynomial p1(*this) , p2(other);

    // ensure that p1 has the degree smaller than p2
    bool swapped = false; // check if swapped than later we need to negate the result
    if (p1.m_degree > p2.m_degree)
        swap(p1 , p2);
    
    // new p1 for that new p1 have the same degree as p2 so we easy to minus
    Polynomial new_p1 = Polynomial(p2);
    new_p1.m_degree = p2.m_degree;
    new_p1.m_poly = (Monomial*) calloc(new_p1.m_degree + 1 , sizeof(Monomial));
    if (!new_p1.m_poly)
        throw std::bad_alloc();

    // copy p1 to new p1
    size_t diff = p2.m_degree - p1.m_degree;
    for (size_t i = 0; i <= p2.m_degree - diff; i++)
        new_p1.m_poly[i] = p1.m_poly[i];
    for (size_t i = p2.m_degree - diff + 1; i <= p2.m_degree; i++)
        new_p1.m_poly[i] = Monomial(0 , i);
    
    // minus two polynomials
    Polynomial result = Polynomial(p2);
    for (size_t i = 0; i <= result.m_degree; i++)
        result.m_poly[i] = new_p1.m_poly[i] - p2.m_poly[i];
    
    // if swapped then negative the result
    if (swapped) {
        for (size_t i = 0; i <= result.m_degree; i++)
            result.m_poly[i].negative();
    }

    // free memory
    free(new_p1.m_poly);
    new_p1.m_poly = nullptr;

    return result;
}

Polynomial Polynomial::operator * (const Polynomial &other) {
    // array to store mul coeficients
    double *mul = (double*) calloc(m_degree + other.m_degree + 1 , sizeof(double));
    if (!mul) 
        throw std::bad_alloc();
    
    // multiply two polynomials
    for (size_t i = 0; i <= m_degree; i++)
        for (size_t j = 0; j <= other.m_degree; j++)
            mul[i + j] += m_poly[i].mul_coef(other.m_poly[j]);
    
    // create result polynomial 
    Polynomial result = Polynomial(m_degree + other.m_degree , mul);
    
    // free memory
    free(mul);
    mul = nullptr;

    return result;
}

// Dirivative
Polynomial Polynomial::operator ! () {
    Polynomial res;
    res.m_degree = m_degree - 1;
    res.m_poly = (Monomial*) calloc(res.m_degree + 1 , sizeof(Monomial));
    if (!res.m_poly)
        throw std::bad_alloc();

    // derivative each monomial
    for (size_t i = 1; i <= m_degree; i++)
        res.m_poly[i - 1] = !m_poly[i];
    return res;
}

// Anti-dirivative
Polynomial Polynomial::operator ~() {
    Polynomial res;
    res.m_degree = m_degree + 1;
    res.m_poly = (Monomial*) calloc(res.m_degree + 1 , sizeof(Monomial));
    if (!res.m_poly)
        throw std::bad_alloc();
    
    res.m_poly[0] = Monomial(0 , 0); // the constant term is 0
    // anti-derivative each monomial
    for (size_t i = 0; i <= m_degree; i++)
        res.m_poly[i + 1] = ~m_poly[i];
    return res;
}

// Input and output
std::ostream& operator << (std::ostream &os , const Polynomial &p) {
    // if the polynomial is zero
    if (p.m_poly[p.m_degree].isZero()) {
        os << 0 << "\n";
        return os;
    }

    for (size_t i = 0; i <= p.m_degree; i++) {
        if (!p.m_poly[i].isZero()) {
            os << p.m_poly[i];
            os << (i == p.m_degree ? "" : "+ ");
        }
    }
    os << "\n";
    return os;
}

std::istream& operator >> (std::istream &is , Polynomial &m) {
    std::stringstream ss;
    std::string buffer;

    std::cout << "Enter the polynomial: " << "\n";

    std::getline(is , buffer);
    ss.clear();
    ss.str(buffer);

    int max_exp = 0;
    double *coef_arr = (double*) calloc(1 , sizeof(double));

    while (!ss.eof()) {
        std::string str_coef , str_exp;
        if (!(ss >> str_coef >> str_exp))
            throw std::invalid_argument("Invalid input format");
        
        double coef = calc<double>(str_coef , 0);
        int exp = calc<int>(str_exp , 1);

        if (exp < 0) 
            throw std::invalid_argument("Negative exponent");

        // resize coef_arr if exp > max_exp
        if (exp > max_exp) {
            double *tmp = (double*) realloc(coef_arr , (exp + 1) * sizeof(double));
            if (!tmp) {
                free(coef_arr);
                coef_arr = nullptr;
                throw std::bad_alloc();
            }
            coef_arr = tmp;
            for (size_t i = max_exp + 1; i <= exp; i++)
                coef_arr[i] = 0;
            max_exp = exp;
        }
        coef_arr[exp] += coef;
    }
    m = Polynomial(max_exp , coef_arr);
    return is;
}

