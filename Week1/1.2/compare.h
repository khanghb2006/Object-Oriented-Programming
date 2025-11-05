#pragma once
#include<iostream>
#include "def.h"

typedef bool (*CompareFraction) (Fraction , Fraction);

bool CompareTwoFraction (Fraction frac1 , Fraction frac2);

bool isIncresing (Fraction frac1 , Fraction frac2);

bool isDecresing (Fraction frac1 , Fraction frac2);