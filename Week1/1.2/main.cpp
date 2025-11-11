#include<iostream>
#include<algorithm>

#include "compare.h"
#include "def.h"
#include "inout.h"

// build : g++ *.cpp -o main.exe
// run : ./main.exe

//bouble sort
void sortFraction (Fraction *arr , int size , CompareFraction cmp) {
    for (int i = 0; i < size; i++)
        for (int j = 0; j < size; j++) 
            if(cmp(arr[i] , arr[j]))
                std::swap(arr[i] , arr[j]);
}

int main() {
    int size;
    Fraction *arr;
    try{
        std::cout << "Enter array of fraction" << "\n";
        InputFraction (arr , size);
        sortFraction (arr , size , isDecresing);
        OutputFraction (arr , size);
    }
    catch(std::invalid_argument &e) {
        std::cout << e.what() << "\n";
    }
}
