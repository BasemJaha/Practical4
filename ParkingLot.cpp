// ParkingLot.cpp
#include "ParkingLot.h"
#include <iostream>

ParkingLot::ParkingLot(int maxCapacity) : maxCapacity(maxCapacity), currentCount(0) {
    vehicles = new Vehicle*[maxCapacity];
    for (int i = 0; i < maxCapacity; ++i)
        vehicles[i] = nullptr;
}

ParkingLot::~ParkingLot() {
    for (int i = 0; i < maxCapacity; ++i)
        delete vehicles[i];
    delete[] vehicles;
}

bool ParkingLot::parkVehicle(Vehicle* v) {
    if (currentCount >= maxCapacity) {
        std::cout << "The lot is full" << std::endl;
        return false;
    }
    vehicles[currentCount++] = v;
    return true;
}

bool ParkingLot::unparkVehicle(int id) {
    for (int i = 0; i < currentCount; ++i) {
        if (vehicles[i] && vehicles[i]->getID() == id) {
            delete vehicles[i];
            for (int j = i; j < currentCount - 1; ++j)
                vehicles[j] = vehicles[j + 1];
            vehicles[--currentCount] = nullptr;
            return true;
        }
    }
    std::cout << "Vehicle not in the lot" << std::endl;
    return false;
}

int ParkingLot::getCount() const {
    return currentCount;
}

int ParkingLot::countOverstayingVehicles(int maxParkingDuration) const {
    int count = 0;
    for (int i = 0; i < currentCount; ++i) {
        if (vehicles[i]->getParkingDuration() > maxParkingDuration) {
            ++count;
        }
    }
    return count;
}