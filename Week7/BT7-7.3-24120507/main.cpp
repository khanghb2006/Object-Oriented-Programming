#include <iostream>

// include header files
#include "Motorbike.h"
#include "Truck.h"

int main() {
    try {
        Motorbike :: Info();
        Truck :: Info();

        Motorbike bike;
        bike.AddFuel(10); // add 10 liters of fuel
        bike.AddGoods(50); // add 50 kg of goods
        std::cout << "Motorbike current fuel: " << bike.GetCurrentFuel() << " liters\n";
        bike.run(100); // run 100 km
        std::cout << "Motorbike current fuel after running 100 km: " << bike.GetCurrentFuel() << " liters\n";

        Truck truck;
        truck.AddFuel(50); // add 50 liters of fuel
        truck.AddGoods(2000); // add 2000 kg of goods
        std::cout << "Truck current fuel: " << truck.GetCurrentFuel() << " liters\n";
        truck.run(100); // run 100 km
        std::cout << "Truck current fuel after running 100 km: " << truck.GetCurrentFuel() << " liters\n";
    }
    catch (const std::exception &e) {
        std::cout << e.what() << "\n";
    }
}