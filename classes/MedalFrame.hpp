#ifndef MEDALFRAME_HPP
#define MEDALFRAME_HPP

#include <string>
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include "CountryData.hpp"

using namespace std;

class MedalFrame
{
private:
  string path = "";
  vector<CountryData> countriesData;
  int getAmountLineFile();
  void buildingMedalFrameArray();
  void sortMedalFrameArray();

public:
  MedalFrame();
  MedalFrame(string path);
  ~MedalFrame();
  void setPathFile(string path);
  void showFile();
  void showOrderedMedalFrame();
};

#endif