#include "Simulation.h"
tuple<bool, int> Simulation::Sim() {
	Time = 0;
	random_device rd;  // створення об'єкту для генерації випадкових чисел
	mt19937 gen(rd()); // використання Mersenne Twister для генерації випадкових чисел
	uniform_int_distribution<> range(1, 2); // випадкові цілі числа в діапазоні від 1 до 2
	int random_num = range(gen);

	while (MyTeam_Check() && OpponentTeam_Check())
	{
		Time++;
		cout << Time<<endl;
		//shooter
		for (int i = 0; (i <= Get_Shooter_My() || i <= Get_Shooter_Op()); i++)
		{
			random_num = range(gen);
			if (random_num == 1)
			{
				if (i <= Get_Shooter_My())
					Random_Choose_and_Fight(15, 50, 5, 30, "Shooter", "My");
				if (i <= Get_Shooter_Op())
					Random_Choose_and_Fight(15, 50, 5, 30, "Shooter", "Op");
			}
			else {
				if (i <= Get_Shooter_Op())
					Random_Choose_and_Fight(15, 50, 5, 30, "Shooter", "Op");
				if (i <= Get_Shooter_My())
					Random_Choose_and_Fight(15, 50, 5, 30, "Shooter", "My");
			}
		}
		//Drones
		if (Time % 4 == 0)
		{
			while (Get_Drones_My() > 0 || Get_Drones_Op() > 0)
			{
				random_num = range(gen);
				if (random_num == 1)
				{
					if (Get_Drones_My() > 0)
					{
						Random_Choose_and_Fight(55, 9.5, 0.5, 25, "Drones", "My");
						SubstractionMyDrones1();
					}
					if (Get_Drones_Op() > 0)
					{
						Random_Choose_and_Fight(55, 9.5, 0.5, 25, "Drones", "Op");
						SubstractionOpponentDrones1();
					}
				}
				else {
					if (Get_Drones_Op() > 0)
					{
						Random_Choose_and_Fight(55, 9.5, 0.5, 25, "Drones", "Op");
						SubstractionOpponentDrones1();
					}
					if (Get_Drones_My() > 0)
					{
						Random_Choose_and_Fight(55, 9.5, 0.5, 25, "Drones", "My");
						SubstractionMyDrones1();
					}					
				}
			}
			Parse();
		}
		//Tanks
		for (int i = 0; (i <= Get_Tanks_My() || i <= Get_Tanks_Op()); i++)
		{
			random_num = range(gen);
			if (random_num == 1)
			{
				if (i <= Get_Tanks_My())
					Random_Choose_and_Fight(55, 15, 0, 30, "Tanks", "My");
				if (i <= Get_Tanks_Op())
					Random_Choose_and_Fight(55, 15, 0, 30, "Tanks", "Op");
			}
			else {
				if (i <= Get_Tanks_Op())
					Random_Choose_and_Fight(55, 15, 0, 30, "Tanks", "Op");
				if (i <= Get_Tanks_My())
					Random_Choose_and_Fight(55, 15, 0, 30, "Tanks", "My");
			}
		}
		//Vehicle
		for (int i = 0; (i <= Get_Vehicles_My() || i <= Get_Vehicles_Op()); i++)
		{
			random_num = range(gen);
			if (random_num == 1)
			{
				if (i <= Get_Vehicles_My())
					Random_Choose_and_Fight(10, 50, 1, 39, "Armored vehicles", "My");
				if (i <= Get_Vehicles_Op())
					Random_Choose_and_Fight(10, 50, 1, 39, "Armored vehicles", "Op");
			}
			else {
				if (i <= Get_Vehicles_Op())
					Random_Choose_and_Fight(10, 50, 1, 39, "Armored vehicles", "Op");
				if (i <= Get_Vehicles_My())
					Random_Choose_and_Fight(10, 50, 1, 39, "Armored vehicles", "My");
			}						
		}
		if ((Time % 15 == 0) && (MyBaseTeam_Check() || OpponentBaseTeam_Check())) 
			Neutral_Allocate();		
		if (Time % 5 == 0) {
			cout << endl;
			printMaps();
			//std::this_thread::sleep_for(std::chrono::seconds(5));
		}
	}
	return make_tuple(MyTeam_Check(), Time);
}

void Simulation::Random_Choose_and_Fight(float Tanks,float Shooters, float Drones, float Vehicle,string Name_Fight, string Team) {
	Serealization file("dataSimulation.json");

	random_device rd;  // створення об'єкту для генерації випадкових чисел
	mt19937 gen(rd()); // використання Mersenne Twister для генерації випадкових чисел
	uniform_real_distribution<> range(0.001, 100.000); // випадкові цілі числа в діапазоні від 0.001 до 100.000

	for (int ttl = 0; ttl < 1 && MyTeam_Check() && OpponentTeam_Check(); ttl++)
	{
		double random_num = range(gen);
		if (random_num <= Tanks)	
		{
			if (Team == "My") {
				if (Get_Tanks_Op() > 0) {
					random_num = range(gen);
					if (file.data[Name_Fight][Weather_conditions]["Tanks"] >= random_num)
						SubstractionOpponentTanks1();
				}
				else
					ttl = 0;
			}
			else
			{
				if (Get_Tanks_My() > 0) {
					random_num = range(gen);
					if (file.data[Name_Fight][Weather_conditions]["Tanks"] >= random_num)
						SubstractionMyTanks1();
				}
				else
					ttl = 0;
			}			
		}
		else if (random_num <= Shooters + Tanks)
		{
			if (Team == "My") {
				if (Get_Shooter_Op() > 0) {
					random_num = range(gen);
					if (file.data[Name_Fight][Weather_conditions]["Shooter"] >= random_num)
						SubstractionOpponentShooter1();
				}
				else
					ttl = 0;
			}
			else
			{
				if (Get_Shooter_My() > 0) {
					random_num = range(gen);
					if (file.data[Name_Fight][Weather_conditions]["Shooter"] >= random_num)
						SubstractionMyShooter1();
				}
				else
					ttl = 0;
			}
		}
		else if (random_num <= Drones + Shooters + Tanks)
		{
			if (Team == "My") {
				if (Get_Drones_Op() > 0) {
					random_num = range(gen);
					if (file.data[Name_Fight][Weather_conditions]["Drones"] >= random_num)					
						SubstractionOpponentDrones1();					
				}
				else
					ttl = 0;
			}
			else
			{
				if (Get_Drones_My() > 0) {
					random_num = range(gen);
					if (file.data[Name_Fight][Weather_conditions]["Drones"] >= random_num)
						SubstractionMyDrones1();
				}
				else
					ttl = 0;
			}					
		}
		else if (random_num <= Vehicle + Drones + Shooters + Tanks)
		{
			if (Team == "My") {
				if (Get_Vehicles_Op() > 0) {
					random_num = range(gen);
					if (file.data[Name_Fight][Weather_conditions]["Armored vehicles"] >= random_num)
						SubstractionOpponentVehicles1();
				}
				else
					ttl = 0;
			}
			else
			{
				if (Get_Vehicles_My() > 0) {
					random_num = range(gen);
					if (file.data[Name_Fight][Weather_conditions]["Armored vehicles"] >= random_num)
						SubstractionMyVehicles1();
				}
				else
					ttl = 0;
			}
		}
	}
}