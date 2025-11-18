#pragma once
#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

// include header files
#include "CPoint.h"

class CCircle {
    public:
        const double PI = 3.14;
        static int InstanceCount;
        static CCircle* Parse(std::string line, std::string seperator);

    private:
        CPoint* m_center;
        double m_radius;

    public:
        // Constructor
        CCircle();
        CCircle(const CCircle& other);
        CCircle(CPoint* center, double radius);

    public:
        // Getters and Setters
        CPoint get_center() { return *m_center; }
        double get_radius() { return m_radius; }
        void set_center(CPoint& new_center);
        void set_radius(double new_radius);

    public:
        // Destructor
        ~CCircle();
};