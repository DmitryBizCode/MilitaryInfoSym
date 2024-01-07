// Raman.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include "nlohmann/json.hpp"
#include "Serealization.h"
#include "Fight.h"
#include "Filtration.h"
#include <Windows.h>
using namespace std;
int main()
{
    SetConsoleOutputCP(1251);
    SetConsoleCP(1251);

    Fight F;
    F.AddMY(5, 200, 10, 200);   
    F.AddOP(6, 150, 12, 15);

    F.Parse();
    F.printMaps();

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
