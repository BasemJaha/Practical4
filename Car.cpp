#include "Car.h"

Car::Car(int id) : Vehicle(id) {}

int Car::getParkingDuration() const {
    int raw_duration = std::time(nullptr) - timeOfEntry;
    return raw_duration * 0.9; // 10% reduction
}
