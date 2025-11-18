#include <iostream>

// include header files
#include "Vehicle.h"

class Truck : public Vehicle {
    private:
        const double m_consume_for_run = 20; // per 100 km
        const double m_consume_for_goods = 1; // per 1000 kg of goods

    public: 
        // information of this vehicle
        static void Info() {
            std::cout << "Truck: " << "\n";
            std::cout << "Fuel consumtion for every 100 km: " << 20 << " liters" << "\n";
            std::cout << "Fuel consumption for every 1000 kg of goods: " << 1 << " liters" << "\n";
        }

    public: 
        // run the truck for a distance (per km)
        void run(double distance);

        // get current fuel left
        float GetCurrentFuel() const;
};