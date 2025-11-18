#pragma once
#include <vector>
#include <string>

class Date {
	private:
		int m_day;
		int m_month;
		int m_year;

	public:
		static Date* Parse(std::string line, std::string seperator);

	public:
		// Constructor
		Date();
		Date(const Date& other);
		Date(int day, int month, int year);

	public:
		// Setters and Getters
		int get_day() { return m_day; }
		int get_month() { return m_month; }
		int get_year() { return m_year; }
		void set_day(int day);
		void set_month(int month);
		void set_year(int year);

	public:
		~Date();
};