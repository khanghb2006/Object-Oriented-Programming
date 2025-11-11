#pragma once
class Fraction {
    private:
        int m_num;
        int m_den;
    public:
        Fraction ();
        Fraction (int value);
        Fraction (const Fraction & f);
        Fraction (int num , int den);
};