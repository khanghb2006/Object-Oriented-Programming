#include <iostream>
#include <ctype.h>
#include "CStudent.h"
#include<string>

bool CStudent::valid_name(std::string name) {
	for (char c : name)
		if (!isalpha(c)) return false;
	return true;
}

CStudent::CStudent() : 
	m_firstName("Khang"), m_middleName("Bao"), m_lastName("Huynh") {}

CStudent::CStudent(const CStudent& s) :
	m_firstName(s.m_firstName), m_middleName(s.m_middleName), m_lastName(s.m_lastName) {}

CStudent::CStudent(std::string firstName, std::string middleName, std::string lastName) {
	if (valid_name(firstName) && valid_name(middleName) && valid_name(lastName)) {
		m_firstName = firstName;
		m_middleName = middleName;
		m_lastName = lastName;
	}
	else {
		//set to default name
		m_firstName = "";
		m_middleName = "";
		m_lastName = "";
	}
}

void CStudent::set_firstName(std::string firstName) {
	if (valid_name(firstName))
		m_firstName = firstName;
}

void CStudent::set_middleName(std::string middleName) {
	if (valid_name(middleName))
		m_middleName = middleName;
}

void CStudent::set_lastName(std::string lastName) {
	if (valid_name(lastName))
		m_lastName = lastName;
}

CStudent::~CStudent() {}