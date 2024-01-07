#pragma once

#include <map>
#include <iostream>

using namespace std;

class Fight
{
private:
    static map<string, int> myMap;
    static map<string, int> opponentMap;

    static map<string, int> myBase;
    static map<string, int> opponentBase;

    void Check_Parse(map<string, int>& myMap, map<string, int>& myBase);
    //void Check_ParseOp();
public:
    void Parse();


    void AddMY(int Tanks, int Shooter, int Drones, int vehicles);
    void AddOP(int Tanks, int Shooter, int Drones, int vehicles);

    void SubstractionMyTanks1();
    void SubstractionMyShooter1();
    void SubstractionMyDrones1();
    void SubstractionMyVehicles1();
    void SubstractionOpponentTanks1();
    void SubstractionOpponentShooter1();
    void SubstractionOpponentDrones1();
    void SubstractionOpponentVehicles1();

    void printMaps();
};

