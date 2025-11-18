#include <iostream>
#include <sstream>
#include <vector>
#include <string>
#include <algorithm>
#include "CLine.h"
#include "CPoint.h"

int CLine::InstanceCount = 0;

CLine* CLine::Parse(std::string line, std::string seperator) {
    // lamda to check valid characters
    auto valid = [](char x) {
        return (isdigit(x) || x == '-' || x == '.');
        };

    std::vector<double> tokens;
    std::string valid_sub;

    while (line.find(seperator) != std::string::npos) {
        // get substring before seperator
        std::string sub = line.substr(0, line.find(seperator));

        // get valid characters only
        valid_sub = "";
        std::copy_if(sub.begin(), sub.end(), std::back_inserter(valid_sub), valid);

		double x = std::stod(valid_sub);
        tokens.push_back(x);
        line = line.substr(line.find(seperator) + seperator.size(), std::string::npos);
    }

    // get the last token
    valid_sub = "";
    std::copy_if(line.begin(), line.end(), std::back_inserter(valid_sub), valid);
	double x = std::stod(valid_sub);
    tokens.push_back(x);
    return new CLine(CPoint(tokens[0], tokens[1]), CPoint(tokens[2], tokens[3]));
}

CLine::CLine() :
    m_start(new CPoint(0, 0)), m_end(new CPoint(0, 1)) {
    InstanceCount++;
}

CLine::CLine(const CLine& other) :
    m_start(new CPoint(*other.m_start)), m_end(new CPoint(*other.m_end)) {
    InstanceCount++;
}

CLine::CLine(CPoint start, CPoint end) {
    if (start.is_overlap(end)) {
        //set to default value
        m_start = new CPoint(0, 0);
        m_end = new CPoint(0, 1);
    }
    else {
        m_start = new CPoint(start);
        m_end = new CPoint(end);
    }
    InstanceCount++;
}

void CLine::set_start(CPoint& start) {
    if (start.is_overlap(*m_end)) return;
    *m_start = start;
}

void CLine::set_end(CPoint& end) {
    if (m_start->is_overlap(end)) return;
    *m_end = end;
}

CLine::~CLine() {
    if (m_start) delete m_start, m_start = nullptr;
    if (m_end) delete m_end, m_end = nullptr;
    --InstanceCount;
}