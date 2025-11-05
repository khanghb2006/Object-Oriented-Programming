#pragma once
class CFraction {
private:
	int m_num;
	int m_den;
public:
	CFraction();
	CFraction(const CFraction& f);
	CFraction(int num, int den);
	int get_num() { return m_num; }
	int get_den() { return m_den; }
	void set_num(int new_num);
	void set_den(int new_den);
	~CFraction();
};