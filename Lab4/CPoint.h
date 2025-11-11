#pragma once
#include <iostream>
#include <string>

class CPoint {
    private:
        double m_x;
        double m_y;
    public:
        static int InstanceCount;

    public:
        //Constructor
        CPoint();
        CPoint(const CPoint &other);
        CPoint(double x , double y);

    public:
        // Getters and Setter
        double get_x() {return m_x;}
        double get_y() {return m_y;}
        void set_x(double new_x) {m_x = new_x;}
        void set_y(double new_y) {m_y = new_y;}

    public:
        // Methods
        double CalcDist(const CPoint &other);
        bool is_overlap(const CPoint &other) {
            return (m_x == other.m_x && m_y == other.m_y);
        }
        std::string ToString() const;

    public:
        friend std::ostream &operator << (std::ostream &os, const CPoint *p);
        friend std::istream &operator >> (std::istream &is , CPoint &p);
    
    public:
        // Destructor
        ~CPoint() {
            m_x = 0;
            m_y = 0;
        }
    
};