#include <iostream>
#include <utility>

// include header files
#include "Vehicle.h"

// Constructor
Vehicle::Vehicle(float fuel , float goods) {
    if (fuel < 0 || goods < 0) 
        throw std::invalid_argument("Fuel and goods must be non-negative");
    m_fuel = fuel;
    m_goods = goods;
}

Vehicle::Vehicle(const Vehicle &other) :
    m_fuel(other.m_fuel) , m_goods(other.m_goods) {}

// Assigment opetor
Vehicle& Vehicle::operator = (Vehicle other) {
    std::swap(m_fuel , other.m_fuel);
    std::swap(m_goods , other.m_goods);
    return *this;
}

// Methods
float Vehicle::GetFuel() const { return m_fuel; }

float Vehicle::GetGoods() const { return m_goods; }

void Vehicle::AddFuel(float amount) {
    if (amount < 0) 
        throw std::invalid_argument("Amount of fuel to add must be non-negative");
    m_fuel += amount;
}

void Vehicle::AddGoods(float amount) {
    if (amount < 0)
        throw std::invalid_argument("Amount of goods to add must be non-negative");
    m_goods += amount;
}

void Vehicle::RemoveGoods(float amount) {
    if (amount < 0) 
        throw std::invalid_argument("Amount of goods to remove must be non-negative");
    if (amount > m_goods) 
        throw std::out_of_range("Not enough goods to remove the specified amount");
    m_goods -= amount;
}

// Destructor 
Vehicle::~Vehicle() {
    m_fuel = 0;
    m_goods = 0;
}