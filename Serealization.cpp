#include "Serealization.h"
#define Ser Serealization
#include "nlohmann/json.hpp"

using json = nlohmann::json;

void Ser::PrintObjectsWithGreaterThan(int distance, int caliber) {
    try {
        for (auto it = data.begin(); it != data.end(); ++it) {
            const auto& item = *it;
            const string& objectName = it.key();

            if ((item["distance"] >= distance) && (item["caliber"] >= caliber))
                //тут фільтр 
                cout << objectName << endl;            
        }
    }
    catch (const exception& e) {
        cerr << "Error 123: " << e.what() << endl;
    }
}

void Ser::Check() {
    try {
        ifstream file("data.json");

        if (!file.is_open())
            cerr << "Unable to open file." << endl;
        
        file >> data;
        file.close();

        // Додаткова перевірка на коректність даних
        if (!data.is_object())
             cerr << "Invalid JSON data format." << endl;
    }
    catch (const std::exception& ex) {
        cerr << "Error: " << ex.what() << endl;
    }
}
