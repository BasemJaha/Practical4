#include "Vehicle.h"

Vehicle::Vehicle(int id) {
    ID = id;
    timeOfEntry = std::time(nullptr); // set to current time
}

int Vehicle::getID() const {
    return ID;
}
