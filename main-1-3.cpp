#include <iostream>
#include <chrono>
#include <thread>
#include "Car.h"
#include "Bus.h"
#include "Motorbike.h"
#include "ParkingLot.h"

using namespace std;

int main() {
    ParkingLot lot(10);

    // Park 5 Cars
    for (int i = 0; i < 5; ++i) {
        lot.parkVehicle(new Car(i + 1));
    }

    // Park 3 Buses
    for (int i = 5; i < 8; ++i) {
        lot.parkVehicle(new Bus(i + 1));
    }

    // Park 2 Motorbikes
    for (int i = 8; i < 10; ++i) {
        lot.parkVehicle(new Motorbike(i + 1));
    }

    // Simulate waiting (e.g., 16 seconds)
    cout << "Waiting for 16 seconds...\n";
    std::this_thread::sleep_for(std::chrono::seconds(16));

    // Count overstaying vehicles (over 15 seconds)
    int overstayers = lot.countOverstayingVehicles(15);
    cout << "Number of overstaying vehicles: " << overstayers << endl;

    return 0;
}
