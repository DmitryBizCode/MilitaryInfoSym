#pragma once
#include "nlohmann/json.hpp"
#include <fstream>
#include <iostream>

using json = nlohmann::json;

using namespace std;


class Serealization{
public:
    Serealization() { Check(); }

    void PrintObjectsWithGreaterThan(int distance, int caliber);

private:
    json data;
    void Check();
};