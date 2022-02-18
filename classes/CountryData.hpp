#ifndef COUNTRYDATA_HPP
#define COUNTRYDATA_HPP
#include <string>
#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;

class CountryData
{
private:
  string countryName;
  int goldMedalAmount;
  int silverMedalAmount;
  int bronzeMedalAmount;

public:
  CountryData();
  CountryData(const CountryData &countryData);
  ~CountryData();
  string getCountryName()
  {
    return this->countryName;
  }
  void setCountryName(string countryName)
  {
    this->countryName = countryName;
  }

  int getGoldMedalAmount()
  {
    return this->goldMedalAmount;
  }
  void setGoldMedalAmount(int goldMedalAmount)
  {
    this->goldMedalAmount = goldMedalAmount;
  }

  int getSilverMedalAmount()
  {
    return this->silverMedalAmount;
  }
  void setSilverMedalAmount(int silverMedalAmount)
  {
    this->silverMedalAmount = silverMedalAmount;
  }

  int getBronzeMedalAmount()
  {
    return this->bronzeMedalAmount;
  }
  void setBronzeMedalAmount(int bronzeMedalAmount)
  {
    this->bronzeMedalAmount = bronzeMedalAmount;
  }
};

#endif