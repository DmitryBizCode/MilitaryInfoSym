#include "Filtration.h"
#define Fi Filtration
#include "nlohmann/json.hpp"
#include <vector>
#include <sstream>
#include <string>

using json = nlohmann::json;

vector<string> Fi::PrintObjectsWithGreaterThan(int distance, int caliber) {

    try {
        vector<string> arr_filtr;

        Serealization ser(data_name);
        for (auto it = ser.data.begin(); it != ser.data.end(); ++it) {

            const auto& item = *it;
            const string& objectName = it.key();

            if ((item["distance"] >= distance) && (item["caliber"] >= caliber)) {
                // Формуємо текстову строку з інформацією
                stringstream ss;

                //Діма добав розрешенія для укр мови бо получається хуйня
                //+ є вопросіки сприводу назви обєкта може зроби функцію яка буде співставляти назву до укр (а так секс)
                //+ не забуль змінити тип ункції в аш файлі (Qt)
            
                ss << ConvertToUkr(objectName) << "(дистанція (" << item["distance"] << "), калібр (" << item["caliber"] << "))";

                arr_filtr.push_back(ss.str());
            }
        }
        return arr_filtr;
    }
    catch (const exception& e) {
        cerr << "Error: " << e.what() << endl;
    }
}
string Fi::ConvertToUkr(string englishWord) {
    if (englishWord == "Mines")
        return "Міни";
    else if (englishWord == "MLRS")
        return "РСЗО";
    else if (englishWord == "Tanks")
        return "Танк";
    else if (englishWord == "Artillery")
        return "Артилерія";
    else if (englishWord == "Shooter")
        return "Стрілкове";
    else if (englishWord == "Aviation")
        return "Авіація";
    else if (englishWord == "Mortars")
        return "Міномет";
    else if (englishWord == "Armored vehicles")
        return "Броньовані машини/БМП";
    else if (englishWord == "Anti-tank missile")
        return "ПТО";
    else
        return "Дрони";

}
