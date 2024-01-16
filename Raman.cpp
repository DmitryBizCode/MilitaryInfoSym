// Raman.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <Windows.h>
#include <random>

#include "nlohmann/json.hpp"
#include "Serealization.h"
#include "Fight.h"
#include "Filtration.h"
#include "Simulation.h"


using namespace std;
int main()
{
    Simulation S("Plain");
    Fight F;

    F.AddOP(10, 80, 4, 5);
    F.AddMY(0, 40, 10, 0);
    F.Parse();
    F.printMaps();
    S.Sim();
    F.printMaps();
    /*                                                                                                                                                                                                                                                                                                                                                           
    Serealization file("dataSimulation.json");
    string Name_Fight = "Drones";
    cout << file.data["Drones"]["Swamp"]["Drones"];
    */

    /*
    if (false)
    {
        cout << "1";
    }
    else if (false)
    {
        cout << "2";
    }
    else if (false)
    {
        cout << "3";
    }
    else if (false)
    {
        cout << "4";
    }
    else
    {
        cout << "5";
    }*/



    /*
    // Ініціалізація генератора випадкових чисел
    std::random_device rd;  // створення об'єкту для генерації випадкових чисел
    std::mt19937 gen(rd()); // використання Mersenne Twister для генерації випадкових чисел
    std::uniform_real_distribution<> distribution(0.01, 100.00); // випадкові цілі числа в діапазоні від 1 до 100
    // Генерація випадкових чисел
    for (int i = 0; i < 2; ++i) {
        float random_num = distribution(gen); // отримання наступного випадкового числа з заданого діапазону
        std::cout << "Випадкове число: " << random_num << std::endl;
        if (true)
        {
            random_num = distribution(gen);
            std::cout << "Випадкове число: " << random_num << std::endl;
        }
    }*/

    

    /*
    SetConsoleOutputCP(1251);
    SetConsoleCP(1251);

    Fight F;
    F.AddMY(5, 200, 10, 200);   
    F.AddOP(6, 150, 12, 15);

    F.Parse();
    //F.printMaps();

    Fight L;
    L.printMaps();
    */
    /*Serealization ser("datainformation.json");
    int num = 3;
    
    // Перевіряємо, чи існує вказаний номер у файлі
    if (ser.data.find(to_string(num)) != ser.data.end()) {
        json tanks = ser.data[to_string(num)];
        cout << tanks.dump(4) << endl; // Виводимо вміст вибраного танку у консоль (зі зміщенням 4 пробіли)
    }
    else
        cout << "Такого номеру не знайдено в файлі JSON." << endl;
        */
    //Filtration fil("data.json");
    //fil.PrintObjectsWithGreaterThan(60, 0);
    //
    // 
    // 
    // 
    //Fight::printMaps();
    //cout << "\nNumber of tanks in My Map: " << Fight::myMap["Tanks"] << endl;
    //cout << "Number of drones in Opponent's Map: " << Fight::opponentMap["Drones"] << endl;
    // 
    // 
    // 




    return 0;
}

// Запуск программы: CTRL+F5 или меню "Отладка" > "Запуск без отладки"
// Отладка программы: F5 или меню "Отладка" > "Запустить отладку"

// Советы по началу работы 
//   1. В окне обозревателя решений можно добавлять файлы и управлять ими.
//   2. В окне Team Explorer можно подключиться к системе управления версиями.
//   3. В окне "Выходные данные" можно просматривать выходные данные сборки и другие сообщения.
//   4. В окне "Список ошибок" можно просматривать ошибки.
//   5. Последовательно выберите пункты меню "Проект" > "Добавить новый элемент", чтобы создать файлы кода, или "Проект" > "Добавить существующий элемент", чтобы добавить в проект существующие файлы кода.
//   6. Чтобы снова открыть этот проект позже, выберите пункты меню "Файл" > "Открыть" > "Проект" и выберите SLN-файл.
