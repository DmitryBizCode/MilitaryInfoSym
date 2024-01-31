#include "Filtration.h"
#define Fi Filtration
#include "nlohmann/json.hpp"
#include <vector>
#include <sstream>

using json = nlohmann::json;

vector<string> Fi::PrintObjectsWithGreaterThan(int distance, int caliber) {

    try {
        vector<string> arr_filtr;

        Serealization ser(data_name);
        for (auto it = ser.data.begin(); it != ser.data.end(); ++it) {
            const auto& item = *it;
            const string& objectName = it.key();

            if ((item["distance"] >= distance) && (item["caliber"] >= caliber)) {
                // ������� �������� ������ � �����������
                stringstream ss;

                //ĳ�� ����� ��������� ��� ��� ���� �� ���������� �����
                //+ � �������� �������� ����� ����� ���� ����� ������� ��� ���� ����������� ����� �� ��� (� ��� ����)
                //+ �� ������ ������ ��� ������ � �� ���� (Qt)
                ss << objectName << "(��������� (" << item["distance"] << "), ����� (" << item["caliber"] << "))";

                arr_filtr.push_back(ss.str());
            }
        }
        return arr_filtr;
    }
    catch (const exception& e) {
        cerr << "Error: " << e.what() << endl;
    }
}