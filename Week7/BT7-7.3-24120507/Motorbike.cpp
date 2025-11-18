#include <iostream>

// include header files
#include "Motorbike.h"

// run the motorbike for a distance (per km)
void Motorbike::run(double distance) {
    if (distance < 0) 
        throw std::invalid_argument("Distance must be non-negative");
    
    // calculate fuel consumption
    double fuel_for_run = (m_consume_for_run * distance) / 100.0;
    double fuel_for_goods = (m_consume_for_goods * m_goods) / 10.0;
    double fuel_needed = fuel_for_run + fuel_for_goods;

    if (fuel_needed > m_fuel) 
        throw std::out_of_range("Not enough fuel to run the specified distance");
    m_fuel -= fuel_needed;
}

// get current fuel left
float Motorbike::GetCurrentFuel() const {
    return m_fuel;
}