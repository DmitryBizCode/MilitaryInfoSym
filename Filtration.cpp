#include "Filtration.h"
#define Fi Filtration
#include "nlohmann/json.hpp"

using json = nlohmann::json;

void Fi::PrintObjectsWithGreaterThan(int distance, int caliber) {
    try {
        Serealization ser(data_name);
        for (auto it = ser.data.begin(); it != ser.data.end(); ++it) {
            const auto& item = *it;
            const string& objectName = it.key();

            if ((item["distance"] >= distance) && (item["caliber"] >= caliber))
                //тут фільтр 
                cout << objectName << endl;
        }
    }
    catch (const exception& e) {
        cerr << "Error: " << e.what() << endl;
    }
}