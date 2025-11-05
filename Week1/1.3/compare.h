#pragma once
#include<iostream>

template <class T1 , class T2 , class T3>
T3 Increasing (T1 a , T2 b) {
    return a < b;
}

template <class T1 , class T2 , class T3> 
T3 Decreasing (T1 a , T2 b) {
    return a > b;
}