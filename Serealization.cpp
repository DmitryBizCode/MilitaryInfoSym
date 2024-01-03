#include "Serealization.h"
#define Ser Serealization
#include "nlohmann/json.hpp"

using json = nlohmann::json;

void Ser::Check(string str) {
    try {
        ifstream file(str);

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
