#pragma once
using namespace std;

#include "Serealization.h"
#include "Fight.h"
#include <random>


class Simulation
{
public:
	Simulation(string str): Weather_conditions(str){}
	bool Sim(string str);
	static int Time;
private:
	void Random_Choose_and_Fight(float Tanks, float Shooters, float Drones, float Vehicle, string Name_Fight, string Team);
	string Weather_conditions;
};

