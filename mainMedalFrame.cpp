#include <iostream>
#include <string>
#include "./classes/CountryData.hpp"
#include "./classes/MedalTable.hpp"

using namespace std;

int main()
{
  string path = "./assets/unorderedMedalFrame.txt";
  MedalTable currentMedalTable;

  currentMedalTable.setPathFile(path);
  currentMedalTable.showFile();
}