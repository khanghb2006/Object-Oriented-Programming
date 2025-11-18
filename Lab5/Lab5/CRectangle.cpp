#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <sstream>

// include header files
#include "CPoint.h"
#include "CRectangle.h"

int CRectangle::InstanceCount = 0;

CRectangle* CRectangle::Parse(std::string line, std::string seperator) {
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
    return new CRectangle(CPoint(tokens[0] , tokens[1]) , CPoint(tokens[2] , tokens[3]));
}

CRectangle::CRectangle() :
    m_topLeft(new CPoint(0, 1)), m_bottomRight(new CPoint(1, 0)) {
    InstanceCount++;
}

CRectangle::CRectangle(const CRectangle& other) :
    m_topLeft(new CPoint(*other.m_topLeft)), m_bottomRight(new CPoint(*other.m_bottomRight)) {
    InstanceCount++;
}

CRectangle::CRectangle(CPoint topLeft, CPoint bottomRight) {
    if (topLeft.is_overlap(bottomRight)) {
        // set to default value
        m_topLeft = new CPoint(0, 1);
        m_bottomRight = new CPoint(1, 0);
    }
    else {
        m_topLeft = new CPoint(topLeft);
        m_bottomRight = new CPoint(bottomRight);
    }
    InstanceCount++;
}

void CRectangle::set_topLeft(CPoint& topLeft) {
    if (topLeft.is_overlap(*m_bottomRight)) return;
    *m_topLeft = topLeft;
}

void CRectangle::set_bottomRight(CPoint& bottomRight) {
    if (bottomRight.is_overlap(*m_topLeft)) return;
    *m_bottomRight = bottomRight;
}

CRectangle::~CRectangle() {
    if (m_topLeft) delete m_topLeft, m_topLeft = nullptr;
    if (m_bottomRight) delete m_bottomRight, m_bottomRight = nullptr;
    --InstanceCount;
}