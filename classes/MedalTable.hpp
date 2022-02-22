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
  int getAmountLineFile();
  void buildingMedalFrameArray();
  void sortMedalFrameArray();

public:
  MedalTable();
  MedalTable(string path);
  ~MedalTable();
  void setPathFile(string path);
  void showFile();
  void showOrderedMedalFrame();
};

#endif