#pragma once
#include "CPoint.h"

class CCircle {
    public:
        const double PI = 3.14;
        static int InstanceCount;

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
        double get_radius() { return m_radius;  }
        void set_center(CPoint &new_center);
        void set_radius(double new_radius);

    public: 
        std::string ToString() const;
        friend std::ostream& operator << (std::ostream& os, const CCircle *c);
        friend std::istream& operator >> (std::istream &is , CCircle &c);

    public:
        // Destructor
        ~CCircle();  
};