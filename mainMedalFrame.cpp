#include <iostream>
#include <string>
#include "./Classes/CountryData.hpp"
#include "./Classes/MedalFrame.hpp"

using namespace std;

int main()
{
  string path = "./assets/unorderedMedalFrame.txt";
  MedalFrame currentMedalFrame;

  currentMedalFrame.setPathFile(path);
  currentMedalFrame.showFile();
}