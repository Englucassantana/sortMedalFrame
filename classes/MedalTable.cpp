#include "MedalTable.hpp"

using namespace std;

MedalTable::MedalTable()
{
  cout << "Objeto criado! Use o metodo setPathFile para entrar com o caminho do arquivo!" << endl;
}
MedalTable::MedalTable(string path)
{
  this->path = path;
}

void MedalTable::show()
{
  buildingMedalTableArray();
  sortMedalTableArray();
}
void MedalTable::setPathFile(string path)
{
  this->path = path;
}
void MedalTable::buildingMedalTableArray()
{
  ifstream medalTableFile(this->path);

  cout << "Carregando tabela........" << endl;
  if (medalTableFile.is_open())
  {
    string tuple;
    
    while (getline(medalTableFile,tuple))
    {    
      CountryData countryData;

      countryData.setCountryName(tuple.substr(0,tuple.find(' ')));
      tuple = tuple.erase(0,tuple.find(' ') + 1);
      countryData.setGoldMedalAmount(stoi(tuple.substr(0,tuple.find(' '))));
      tuple = tuple.erase(0,tuple.find(' ') + 1);
      countryData.setSilverMedalAmount(stoi(tuple.substr(0,tuple.find(' '))));
      tuple = tuple.erase(0,tuple.find(' ') + 1);
      countryData.setBronzeMedalAmount(stoi(tuple));

      cout
      << "País: " << countryData.getCountryName()
      << " Ouro: " << countryData.getGoldMedalAmount()
      << " Prata: " << countryData.getSilverMedalAmount()
      << " Bronze: " << countryData.getBronzeMedalAmount()
      << endl;

      countriesData.push_back(countryData);    
    }
    
    medalTableFile.close();
    
  }
  

  else
  {
    cout << "Arquivo não pôde ser aberto" << endl;
  }
}
void MedalTable::sortMedalTableArray()
{

  cout << "Ordenando o quadro de medalhas... " << endl;

  for (size_t i = 0; i < this->countriesData.size(); i++)
  {
    for (size_t j = i + 1; j < this->countriesData.size(); j++)
    {
      if (this->countriesData[i].getBronzeMedalAmount() < this->countriesData[j].getBronzeMedalAmount())
      {
        CountryData elementToSwap = countriesData[j];
        this->countriesData.erase(this->countriesData.begin() + j);
        this->countriesData.insert(this->countriesData.begin() + i, elementToSwap);
      }
    }     
  }

  for (size_t i = 0; i < this->countriesData.size(); i++)
  {
    for (size_t j = i + 1; j < this->countriesData.size(); j++)
    {
      if (this->countriesData[i].getSilverMedalAmount() < this->countriesData[j].getSilverMedalAmount())
      {
        CountryData elementToSwap = countriesData[j];
        this->countriesData.erase(this->countriesData.begin() + j);
        this->countriesData.insert(this->countriesData.begin() + i, elementToSwap);
      }
    }     
  }

  for (size_t i = 0; i < this->countriesData.size(); i++)
  {
    for (size_t j = i + 1; j < this->countriesData.size(); j++)
    {
      if (this->countriesData[i].getGoldMedalAmount() < this->countriesData[j].getGoldMedalAmount())
      {
        CountryData elementToSwap = countriesData[j];
        this->countriesData.erase(this->countriesData.begin() + j);
        this->countriesData.insert(this->countriesData.begin() + i, elementToSwap);
      }
    }     
  }

  for (size_t i = 0; i < this->countriesData.size(); i++)
  {
    cout
      << "Pais: " << this->countriesData[i].getCountryName() << " "
      << "Ouro: " << this->countriesData[i].getGoldMedalAmount() << " "
      << "Prata: " << this->countriesData[i].getSilverMedalAmount() << " "
      << "Bronze: " << this->countriesData[i].getBronzeMedalAmount()
      << endl;
  }
  
}
