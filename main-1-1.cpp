#include <iostream>
#include "Car.h"
#include "Bus.h"
#include "Motorbike.h"

int main() {
    const int SIZE = 3;
    Vehicle* vehicles[SIZE];

    vehicles[0] = new Car(1);
    vehicles[1] = new Bus(2);
    vehicles[2] = new Motorbike(3);

    std::cout << "Vehicle Parking Durations:\n";
    for (int i = 0; i < SIZE; ++i) {
        std::cout << "Vehicle ID " << vehicles[i]->getID() << " duration: " << vehicles[i]->getParkingDuration() << " seconds" << std::endl;
        delete vehicles[i];
    }

    return 0;
}
