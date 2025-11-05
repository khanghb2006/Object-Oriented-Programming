#pragma once
#include <string>

class CStudent {
private:
	std::string m_firstName;
	std::string m_middleName;
	std::string m_lastName;
	bool valid_name(std::string name);
public:
	CStudent();
	CStudent(const CStudent& s);
	CStudent(std::string firstName, std::string middleName, std::string lastName);
	std::string get_firstName() { return m_firstName; }	
	std::string get_middleName() { return m_middleName; }
	std::string get_lastName() { return m_lastName; }
	void set_firstName(std::string new_firstName);
	void set_middleName(std::string new_middleName);
	void set_lastName(std::string new_lastName);
	~CStudent();
};