#include "Simulation.h"
bool Simulation::Sim(string str) {
	Fight F; 

	Time = 0;
	while (F.MyTeam_Check() && F.OpponentTeam_Check())
	{
		Time++;
		//shooter
		for (int i = 0; (i <= F.Get_Shooter_My() || i <= F.Get_Shooter_Op()); i++)
		{
			if (i <= F.Get_Drones_My())
			{
				//Random_Choose_and_Fight(float Tanks, float Shooters, float Drones, float Vehicle, "Shooter", "My");
			}
			if (i <= F.Get_Drones_Op())
			{
				//Random_Choose_and_Fight(float Tanks, float Shooters, float Drones, float Vehicle, "Shooter", "Op");
			}
		}
		//Drones
		if (Time % 4 == 0)
		{
			//for (int i = 1; (i <= F.Get_Drones_My() || i <= F.Get_Drones_Op()); i++)
			while (F.Get_Drones_My() > 0 || F.Get_Drones_Op() > 0)
			{
				if (F.Get_Drones_My() > 0)
				{
					//Random_Choose_and_Fight(float Tanks, float Shooters, float Drones, float Vehicle, "Drones", "My");
					F.SubstractionMyDrones1();
				}
				if (F.Get_Drones_Op() > 0)
				{
					//Random_Choose_and_Fight(float Tanks, float Shooters, float Drones, float Vehicle, "Drones", "Op");
					F.SubstractionOpponentDrones1();
				}
			}
		}
		//Tanks
		for (int i = 0; (i <= F.Get_Shooter_My() || i <= F.Get_Shooter_Op()); i++)
		{
			if (i <= F.Get_Drones_My())
			{
				//Random_Choose_and_Fight(float Tanks, float Shooters, float Drones, float Vehicle, "Tanks", "My");
			}
			if (i <= F.Get_Drones_Op())
			{
				//Random_Choose_and_Fight(float Tanks, float Shooters, float Drones, float Vehicle, "Tanks", "Op");
			}
		}
		//Vehicle
		for (int i = 0; (i <= F.Get_Shooter_My() || i <= F.Get_Shooter_Op()); i++)
		{
			if (i <= F.Get_Drones_My())
			{
				//Random_Choose_and_Fight(float Tanks, float Shooters, float Drones, float Vehicle, "Shooter", "My");
			}
			if (i <= F.Get_Drones_Op())
			{
				//Random_Choose_and_Fight(float Tanks, float Shooters, float Drones, float Vehicle, "Armored vehicles", "Op");
			}
		}
		if (Time % 15 == 0)		
			F.Neutral_Allocate();		
	}
	return F.MyTeam_Check();
}

void Simulation::Random_Choose_and_Fight(float Tanks,float Shooters, float Drones, float Vehicle,string Name_Fight, string Team) {
	Serealization file("dataSimulation.json");
	Fight F;

	random_device rd;  // створення об'єкту для генерації випадкових чисел
	mt19937 gen(rd()); // використання Mersenne Twister для генерації випадкових чисел
	uniform_real_distribution<> range(0.001, 100.000); // випадкові цілі числа в діапазоні від 0.001 до 100.000

	for (int ttl = 0; ttl < 1 && F.MyTeam_Check() && F.OpponentTeam_Check(); ttl++)
	{
		double random_num = range(gen);
		if (random_num <= Tanks)	
		{
			random_num = range(gen);
			if (file.data[Name_Fight][Weather_conditions]["Tanks"] <= random_num)
			{
				if (Team == "My") 
					F.SubstractionOpponentTanks1();
				else 
					F.SubstractionMyTanks1();
			}
		}
		else if (random_num <= Shooters)
		{
			random_num = range(gen);
			if (file.data[Name_Fight][Weather_conditions]["Shooter"] <= random_num)
			{
				if (Team == "My")
					F.SubstractionOpponentShooter1();
				else
					F.SubstractionMyShooter1();
			}
		}
		else if (random_num <= Drones)
		{
			random_num = range(gen);
			if (file.data[Name_Fight][Weather_conditions]["Drones"] <= random_num)
			{
				if (Team == "My")
					F.SubstractionOpponentDrones1();
				else
					F.SubstractionMyDrones1();
			}
		}
		else if (random_num <= Vehicle)
		{
			random_num = range(gen);
			if (file.data[Name_Fight][Weather_conditions]["Armored vehicles"] <= random_num)
			{
				if (Team == "My")
					F.SubstractionOpponentVehicles1();
				else
					F.SubstractionMyVehicles1();
			}
		}
	}
}