#pragma once

class Fraction {

    private:
        int m_num;
        int m_den;
    
    public: 
        void input ();
        void output ();
        int getNum ();
        void setNum (int new_num);
        int getDenom ();
        void setDenom (int new_num);
        Fraction reduce ();
        Fraction inverse ();
        Fraction add (Fraction p);
        int compare (Fraction p);
    
    ~Fraction() {} // Destructor
};