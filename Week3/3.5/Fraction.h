#pragma once

class Fraction {
    private:
        int m_num;
        int m_den;
        static int numFractions;
    public:
        Fraction();
        Fraction(const Fraction &f);
        Fraction(int num , int den);
        static int getNumFractions();
        ~Fraction();
};