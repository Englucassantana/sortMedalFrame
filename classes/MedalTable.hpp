#ifndef MEDALTABLE_HPP
#define MEDALTABLE_HPP

#include <string>
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include "CountryData.hpp"

using namespace std;

class MedalTable
{
private:
  string path = "";
  vector<CountryData> countriesData;
  void buildingMedalTableArray();
  void sortMedalTableArray();

public:
  MedalTable();
  MedalTable(string path);
  void setPathFile(string path);
  void show();
};

#endif