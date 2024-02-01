#pragma once
#include "Serealization.h"
using namespace std;
class Filtration
{
public:
	vector<string> PrintObjectsWithGreaterThan(int distance, int caliber);
	Filtration(string data_name) : data_name(data_name){}
private:
	string data_name;
	string ConvertToUkr(string englishWord);
};

