#include "Bus.h"

Bus::Bus(int id) : Vehicle(id) {}

int Bus::getParkingDuration() const {
    int raw_duration = std::time(nullptr) - timeOfEntry;
    return raw_duration * 0.75; // 25% reduction
}
