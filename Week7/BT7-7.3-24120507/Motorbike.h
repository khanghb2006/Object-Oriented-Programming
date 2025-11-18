#include <iostream>

// include header files
#include "Vehicle.h"

class Motorbike : public Vehicle  {
    private:
        const double m_consume_for_run = 2; // per 100 km
        const double m_consume_for_goods = 0.1; // per 10kg of goods

    public:
        // information of this vehicle
        static void Info() {
            std::cout << "Motorbike: " << "\n";
            std::cout << "Fuel consumtion for every 100 km: " << 2 << " liters" << "\n";
            std::cout << "Fuel consumption for every 10 kg of goods: " << 0.1 << " liters" << "\n";
        }

    public:
        // run the motorbike for a distance (per km) 
        void run(double distance);

        // get current fuel left
        float GetCurrentFuel() const;
};