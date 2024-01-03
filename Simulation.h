#pragma once
using namespace std;
#include "Serealization.h"

class Simulation
{
public:
	Simulation() {
		this->tanks = 1;
		this->shooter = 1;
		this->drones = 1;
		this->vehicles = 1;
		this->tanks_Op = 1;
		this->shooter_Op = 1;
		this->drones_Op = 1;
		this->vehicles_Op = 1;
	}
	void Initialization(int tanks, int shooter, int drones, int vehicles, int tanks_Op, int shooter_Op, int drones_Op, int vehicles_Op);
	bool Sim(string str);
private:
	int tanks, shooter, drones, vehicles;
	int tanks_Op, shooter_Op, drones_Op, vehicles_Op;

};

