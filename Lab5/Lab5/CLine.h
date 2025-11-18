#pragma once
#include <string>
#include <vector>
#include "CPoint.h"

class CLine {
    private:
        CPoint* m_start;
        CPoint* m_end;

    public:
        static int InstanceCount;
        static CLine* Parse(std::string line, std::string seperator);

    public:
        // Constructors
        CLine();
        CLine(const CLine& other);
        CLine(CPoint start, CPoint end);

    public:
        // Getters and Setters
        CPoint get_start() { return *m_start; }
        CPoint get_end() { return *m_end; }
        void set_start(CPoint& start);
        void set_end(CPoint& end);

    public:
        // Destructure
        ~CLine();
};