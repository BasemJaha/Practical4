#include <iostream>
#include <vector>
#include "Car.h"
#include "Bus.h"
#include "Motorbike.h"

using namespace std;

int main() {
    int num;
    cout << "How many vehicles do you want to park? ";
    cin >> num;

    vector<Vehicle*> parkingLot;

    for (int i = 0; i < num; ++i) {
        cout << "Enter vehicle type (1=Car, 2=Bus, 3=Motorbike): ";
        int type;
        cin >> type;
        int id;
        cout << "Enter vehicle ID: ";
        cin >> id;

        if (type == 1) parkingLot.push_back(new Car(id));
        else if (type == 2) parkingLot.push_back(new Bus(id));
        else if (type == 3) parkingLot.push_back(new Motorbike(id));
        else cout << "Invalid type. Skipping.\n";
    }

    cout << "\nParking durations:\n";
    for (Vehicle* v : parkingLot) {
        cout << "Vehicle ID " << v->getID() << ": " << v->getParkingDuration() << " seconds\n";
        delete v;
    }

    return 0;
}
