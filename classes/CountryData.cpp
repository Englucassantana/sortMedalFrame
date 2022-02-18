#include "CountryData.hpp"

CountryData::CountryData()
{
}
CountryData::CountryData(const CountryData &countryData)
{
  this->countryName = countryData.countryName;
  this->goldMedalAmount = countryData.goldMedalAmount;
  this->silverMedalAmount = countryData.silverMedalAmount;
  this->bronzeMedalAmount = countryData.bronzeMedalAmount;
}
CountryData::~CountryData()
{
}
