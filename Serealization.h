#pragma once
#include "nlohmann/json.hpp"
#include <fstream>
#include <iostream>

using json = nlohmann::json;

using namespace std;


class Serealization{
public:
    Serealization(string data_name) { Check(data_name); }
    json data;
private:
    void Check(string data_name);

};