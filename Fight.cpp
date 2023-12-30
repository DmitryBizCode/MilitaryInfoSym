#include "Fight.h"
#define F Fight

//base
map<string, int> F::myMap = {
    {"Tanks", 1},
    {"Shooter", 1},
    {"Drones", 1},
    {"Armored vehicles", 1}
};

map<string, int> F::opponentMap = {
    {"Tanks", 1},
    {"Shooter", 1},
    {"Drones", 1},
    {"Armored vehicles", 1}
};

//add
void F::AddMY(int Tanks, int Shooter, int Drones, int vehicles) {
    myMap["Tanks"] = Tanks;
    myMap["Shooter"] = Shooter;
    myMap["Drones"] = Drones;
    myMap["Armored vehicles"] = vehicles;
}
void F::AddOP(int Tanks, int Shooter, int Drones, int vehicles) {
    opponentMap["Tanks"] = Tanks;
    opponentMap["Shooter"] = Shooter;
    opponentMap["Drones"] = Drones;
    opponentMap["Armored vehicles"] = vehicles;
}

//sub
void F::SubstractionMyTanks1() {
    myMap["Tanks"] -= 1;
}
void F::SubstractionMyShooter1() {
    myMap["Shooter"] -= 1;
}
void F::SubstractionMyDrones1() {
    myMap["Drones"] -= 1;
}
void F::SubstractionMyVehicles1() {
    myMap["Armored vehicles"] -= 1;
}
void F::SubstractionOpponentTanks1() {
    myMap["Tanks"] -= 1;
}
void F::SubstractionOpponentShooter1() {
    myMap["Shooter"] -= 1;
}
void F::SubstractionOpponentDrones1() {
    myMap["Drones"] -= 1;
}
void F::SubstractionOpponentVehicles1() {
    myMap["Armored vehicles"] -= 1;
}


//print
void F::printMaps() {
    cout << "My Map:" << endl;
    for (const auto& pair : myMap) {
        cout << pair.first << ": " << pair.second << endl;
    }

    cout << "\nOpponent's Map:" << endl;
    for (const auto& pair : opponentMap) {
        cout << pair.first << ": " << pair.second << endl;
    }
}