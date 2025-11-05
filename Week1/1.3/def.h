template <class T1 , class T2 , class T3>
using Mixed = T3 (*) (T1 , T2);

struct Fraction {
    int num , den;
    
    bool operator < (const Fraction & a) {
        return num * a.den < den * a.num;
    }
};

//Input operator for struct Point
std::istream& operator >> (std::istream & inp , Fraction & f) {
    return inp >> f.num >> f.den;
}

//Output operator for struct Point
std::ostream& operator << (std::ostream & out , Fraction & f) {
    return out << f.num << " " << f.den;
}

// Bouble Sort
template <class T1 , class T2 , class T3>
void Sort (T1 *& arr , int size , Mixed<T1 , T2 , T3> cmp) {
    for (int i = 0; i < size; i++)
        for (int j = i + 1; j < size; j++)
            if (!cmp (arr[i] , arr[j]))
                std::swap (arr[i] , arr[j]);
}