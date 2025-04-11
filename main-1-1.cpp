#include <iostream>
#include "Vehicle.h"

using namespace std;

int main() {
    int numVehicles;
    cout << "Enter the number of vehicles to park: ";
    cin >> numVehicles;

    Vehicle** parkingLot = new Vehicle*[numVehicles];

    for (int i = 0; i < numVehicles; i++) {
        int id;
        string type;
        cout << "Enter vehicle type (Car, Bus, Motorbike): ";
        cin >> type;
        cout << "Enter vehicle ID: ";
        cin >> id;

        if (type == "Car")
            parkingLot[i] = new Car(id);
        else if (type == "Bus")
            parkingLot[i] = new Bus(id);
        else if (type == "Motorbike")
            parkingLot[i] = new Motorbike(id);
        else {
            cout << "Invalid type. Skipping this vehicle.\n";
            parkingLot[i] = nullptr;
        }
    }

    cout << "\n--- Parking Durations ---\n";
    for (int i = 0; i < numVehicles; i++) {
        if (parkingLot[i] != nullptr) {
            cout << "Vehicle ID " << parkingLot[i]->getID()
                 << " parked for " << parkingLot[i]->getParkingDuration()
                 << " seconds.\n";
        }
    }

    // Cleanup
    for (int i = 0; i < numVehicles; i++) {
        delete parkingLot[i];
    }
    delete[] parkingLot;

    return 0;
}
