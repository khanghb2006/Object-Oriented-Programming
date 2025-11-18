#pragma once
#include <iostream>
#include <string>
#include <vector>

class CPoint {
    private:
        double m_x;
        double m_y;
    public:
        static int InstanceCount;
        static CPoint* Parse(std::string line, std::string seperator);

    public:
        //Constructor
        CPoint();
        CPoint(const CPoint& other);
        CPoint(double x, double y);

    public:
        // Getters and Setter
        double get_x() { return m_x; }
        double get_y() { return m_y; }
        void set_x(double new_x) { m_x = new_x; }
        void set_y(double new_y) { m_y = new_y; }

    public:
        bool is_overlap(const CPoint& other) const {
                return (m_x == m_x && m_y == m_y);
	    }

    public:
        // Destructor
        ~CPoint();

};