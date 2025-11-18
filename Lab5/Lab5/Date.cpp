#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

// include header files
#include "Date.h"

Date* Date::Parse(std::string line, std::string seperator) {
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
    return new Date(tokens[0] , tokens[1] , tokens[2]);
}

// Constructor
Date::Date() : m_day(18), m_month(4), m_year(2006) {}
Date::Date(const Date& other) :
	m_day(other.m_day), m_month(other.m_month), m_year(other.m_year) {}
Date::Date(int day, int month, int year): Date() {
    if (day < 0 || day > 31) return;
    if (day > 29 && month == 2) return;
    if ((month == 4 || month == 6 || month == 9 || month == 11) && day > 30) return;
	m_day = day;
    m_month = month;
    m_year = year;
}

// Setters
void Date::set_day(int day) {
    if (day < 0 || day > 31) return;
    if (day > 29 && m_month == 2) return;
	if (day > 30 && (m_month == 4 || m_month == 6 || m_month == 9 || m_month == 11)) return;
    m_day = day;
}

void Date::set_month(int month) {
    if (month < 1 || month > 12) return;
	if (m_day > 29 && month == 2) return;
	if (m_day > 30 && (month == 4 || month == 6 || month == 9 || month == 11)) return;
	m_month = month;
}

void Date::set_year(int year) {
    if (year < 0) return;
    m_year = year;
}

Date::~Date() {
    m_day = 0;
    m_month = 0;
    m_year = 0;
}