#include "Fight.h"
#define F Fight

//base
map<string, int> F::myMap = {
    {"Tanks", 0},
    {"Shooter", 0},
    {"Drones", 0},
    {"Armored vehicles", 0}
};

map<string, int> F::opponentMap = {
    {"Tanks", 0},
    {"Shooter", 0},
    {"Drones", 0},
    {"Armored vehicles", 0}
};

map<string, int> F::myBase = {
    {"Tanks", 0},
    {"Drones", 0},
    {"Armored vehicles", 0}
};

map<string, int> F::opponentBase = {
    {"Tanks", 0},
    {"Drones", 0},
    {"Armored vehicles", 0}
};

map<string, int> F::Neutral = {
    {"Tanks", 0},
    {"Drones", 0},
    {"Armored vehicles", 0}
};

//add
void F::AddMY(int Tanks, int Shooter, int Drones, int vehicles) {
    myBase["Tanks"] = Tanks;
    myMap["Shooter"] = Shooter;
    myBase["Drones"] = Drones;
    myBase["Armored vehicles"] = vehicles;
}
void F::AddOP(int Tanks, int Shooter, int Drones, int vehicles) {
    opponentBase["Tanks"] = Tanks;
    opponentMap["Shooter"] = Shooter;
    opponentBase["Drones"] = Drones;
    opponentBase["Armored vehicles"] = vehicles;
}

//sub
void F::SubstractionMyTanks1() {
    myMap["Tanks"] -= 1;
}
void F::SubstractionMyShooter1() {
    myMap["Shooter"] -= 1;
}
void F::SubstractionMyDrones1() {
    myMap["Shooter"] += 1;
    myMap["Drones"] -= 1;
}
void F::SubstractionMyVehicles1() {
    myMap["Armored vehicles"] -= 1;
}
void F::SubstractionOpponentTanks1() {
    opponentMap["Tanks"] -= 1;
}
void F::SubstractionOpponentShooter1() {
    opponentMap["Shooter"] -= 1;
}
void F::SubstractionOpponentDrones1() {
    opponentMap["Shooter"] += 1;
    opponentMap["Drones"] -= 1;
}
void F::SubstractionOpponentVehicles1() {
    opponentMap["Armored vehicles"] -= 1;
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


//перевооружения
void F::Parse() {
    if (myMap["Shooter"] >= (myBase["Tanks"] * 4 + myBase["Drones"] + myBase["Armored vehicles"] * 3))
    {
        myMap["Shooter"] -= (myBase["Tanks"] * 4 + myBase["Drones"] + myBase["Armored vehicles"] * 3);
        myMap["Tanks"] = myBase["Tanks"];
        myBase["Tanks"] = 0;
        myMap["Drones"] = myBase["Drones"];
        myBase["Drones"] = 0;
        myMap["Armored vehicles"] = myBase["Armored vehicles"];
        myBase["Armored vehicles"] = 0;
    }
    else
        Check_Parse(myMap, myBase);

    if (opponentMap["Shooter"] >= (opponentBase["Tanks"] * 4 + opponentBase["Drones"] + opponentBase["Armored vehicles"] * 3))
    {
        opponentMap["Shooter"] -= (opponentBase["Tanks"] * 4 + opponentBase["Drones"] + opponentBase["Armored vehicles"] * 3);
        opponentMap["Tanks"] = opponentBase["Tanks"];
        opponentBase["Tanks"] = 0;
        opponentMap["Drones"] = opponentBase["Drones"];
        opponentBase["Drones"] = 0;
        opponentMap["Armored vehicles"] = opponentBase["Armored vehicles"];
        opponentBase["Armored vehicles"] = 0;
    }
    else
        Check_Parse(opponentMap, opponentBase);
}

void  F::Check_Parse(map<string, int>& Map, map<string, int>& Base) {
    if ((Map["Shooter"] >= Base["Drones"]) && (Base["Drones"] > 0))
    {
        Map["Shooter"] -= Base["Drones"];
        Map["Drones"] += Base["Drones"];
        Base["Drones"] = 0;
    }
    else if ((Base["Drones"] > 0) && (Map["Shooter"] > 0))
    {
        Map["Drones"] += Map["Shooter"];
        int ttl = Map["Shooter"];
        Map["Shooter"] = 0;
        Base["Drones"] -= ttl;
        return;
    }
    if ((Map["Shooter"] >= (Base["Tanks"] * 4)) && (Base["Tanks"] > 0))
    {
        Map["Shooter"] -= (Base["Tanks"] * 4);
        Map["Tanks"] += Base["Tanks"];
        Base["Tanks"] = 0;
    }
    else if ((Base["Tanks"] > 0) && (Map["Shooter"] > 4))
    {
        int possible = Map["Shooter"] / 4;
        Map["Tanks"] += possible;
        Map["Shooter"] -= possible * 4;
        Base["Tanks"] -= possible;
        return;
    }
    if ((Map["Shooter"] >= (Base["Armored vehicles"] * 3)) && (Base["Armored vehicles"] > 0))
    {
        Map["Shooter"] -= (Base["Armored vehicles"] * 3);
        Map["Armored vehicles"] += Base["Armored vehicles"];
        Base["Armored vehicles"] = 0;
        return;
    }
    else if ((Base["Armored vehicles"] > 0) && (Map["Shooter"] > 3))
    {
        int possible = Map["Shooter"] / 3;
        Map["Armored vehicles"] += possible;
        Map["Shooter"] -= possible * 3;
        Base["Armored vehicles"] -= possible;
        return;
    }
}


//Neutral
void F::Push_To_Neutral_MyBase() {
    Neutral["Tanks"] += myBase["Tanks"];
    Neutral["Drones"] += myBase["Drones"];
    Neutral["Armored vehicles"] += myBase["Armored vehicles"];
    myBase["Tanks"] = 0;
    myBase["Drones"] = 0;
    myBase["Armored vehicles"] = 0;
}
void F::Push_To_Neutral_OpponentBase() {
    Neutral["Tanks"] += opponentBase["Tanks"];
    Neutral["Drones"] += opponentBase["Drones"];
    Neutral["Armored vehicles"] += opponentBase["Armored vehicles"];
    opponentBase["Tanks"] = 0;
    opponentBase["Drones"] = 0;
    opponentBase["Armored vehicles"] = 0;
}

//перегрупування
bool F::Neutral_Check() {
    return ((Neutral["Tanks"] + Neutral["Drones"] + Neutral["Armored vehicles"]) > 0) ? true : false;
}

//Get
int F::Get_Shooter_My() {
    return myMap["Shooter"];
}
int F::Get_Shooter_Op() {
    return opponentMap["Shooter"];
}

//Allocate
void F::Neutral_Allocate() {
    if (myMap["Shooter"] > 0)    
        Check_Parse(myMap, Neutral);
    
    if (opponentMap["Shooter"] > 0)    
        Check_Parse(opponentMap, Neutral);
    
    Neutral["Tanks"] = 0;
    Neutral["Drones"] = 0;
    Neutral["Armored vehicles"] = 0;
}