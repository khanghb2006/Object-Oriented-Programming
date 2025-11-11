#include<iostream>
#include"CFraction.h"

CFraction::CFraction() : m_num(0), m_den(1) {}

CFraction::CFraction(const CFraction& f) :
	m_num(f.m_num), m_den(f.m_den) {}

CFraction::CFraction(int num, int den) {
	if (!den) {
		//set to default fraction
		m_num = 0;
		m_den = 1;
	}
	else {
		m_num = num;
		m_den = den;
	}
}

void CFraction::set_num(int new_num) {
	m_num = new_num;
}

void CFraction::set_den(int new_den) {
	if (new_den == 0) return;
	m_den = new_den;
}

CFraction::~CFraction() {}
