#pragma once

class Vehicle {
    protected:
        float m_fuel; // in liters
        float m_goods; // in kilograms

    public:
        // Constructor
        Vehicle() : m_fuel(0) , m_goods(0) {}
        Vehicle(float fuel , float goods);
        Vehicle(const Vehicle &other);
    
    public:
        // Assignment operator
        Vehicle& operator = (Vehicle other);
    
    public:
        // Methods
        float GetFuel() const;
        float GetGoods() const;
        void AddFuel(float amount);
        void AddGoods(float amount);
        void RemoveGoods(float amount);

    public:
        // Destructor
        ~Vehicle();
};