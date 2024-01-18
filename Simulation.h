#pragma once
using namespace std;

#include "Serealization.h"
#include "Fight.h"
#include <random>

#include <thread>
#include <chrono>

class Simulation : protected Fight
{
public:
	Simulation(string str): Weather_conditions(str){}
	bool Sim();
	int Time = 0;
private:
	void Random_Choose_and_Fight(float Tanks, float Shooters, float Drones, float Vehicle, string Name_Fight, string Team);
	string Weather_conditions;
};

