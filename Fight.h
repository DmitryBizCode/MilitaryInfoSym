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

    static map<string, int> Neutral;
    void Check_Parse(map<string, int>& myMap, map<string, int>& myBase);
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

    int Get_Shooter_My();
    int Get_Shooter_Op();

    void Push_To_Neutral_MyBase();
    void Push_To_Neutral_OpponentBase();

    bool Neutral_Check();

    void Neutral_Allocate();

    void printMaps();
};

