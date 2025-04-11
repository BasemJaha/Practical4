#include "Motorbike.h"

Motorbike::Motorbike(int id) : Vehicle(id) {}

int Motorbike::getParkingDuration() const {
    int raw_duration = std::time(nullptr) - timeOfEntry;
    return raw_duration * 0.85; // 15% reduction
}
