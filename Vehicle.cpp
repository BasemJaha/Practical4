#include "Vehicle.h"
#include <ctime>

Vehicle::Vehicle(int id) {
    ID = id;
    timeOfEntry = std::time(nullptr); // current time
}

int Vehicle::getID() const {
    return ID;
}

// Each subclass applies a different reduction

Car::Car(int id) : Vehicle(id) {}

int Car::getParkingDuration() const {
    int duration = static_cast<int>(std::time(nullptr) - timeOfEntry);
    return duration - (duration * 10 / 100); // 10% reduction
}

Bus::Bus(int id) : Vehicle(id) {}

int Bus::getParkingDuration() const {
    int duration = static_cast<int>(std::time(nullptr) - timeOfEntry);
    return duration - (duration * 25 / 100); // 25% reduction
}

Motorbike::Motorbike(int id) : Vehicle(id) {}

int Motorbike::getParkingDuration() const {
    int duration = static_cast<int>(std::time(nullptr) - timeOfEntry);
    return duration - (duration * 15 / 100); // 15% reduction
}
