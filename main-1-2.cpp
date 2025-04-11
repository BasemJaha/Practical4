// main-1-2.cpp
#include <iostream>
#include "Car.h"
#include "Bus.h"
#include "Motorbike.h"
#include "ParkingLot.h"

int main() {
    ParkingLot lot(10);

    while (lot.getCount() < 10) {
        std::cout << "Enter type (car, bus, bike) and ID: ";
        std::string type;
        int id;
        std::cin >> type >> id;

        Vehicle* v = nullptr;
        if (type == "car") v = new Car(id);
        else if (type == "bus") v = new Bus(id);
        else if (type == "bike") v = new Motorbike(id);

        if (v && lot.parkVehicle(v)) {
            std::cout << "Vehicle parked." << std::endl;
        }
    }

    std::cout << "Enter ID to unpark: ";
    int removeId;
    std::cin >> removeId;
    lot.unparkVehicle(removeId);

    return 0;
}
