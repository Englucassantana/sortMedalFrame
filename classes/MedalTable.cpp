#include "MedalTable.hpp"

using namespace std;

MedalTable::MedalTable()
{
  cout << "Objeto criado use o metodo setPathFile para entrar com o caminho do arquivo" << endl;
}
MedalTable::MedalTable(string path)
{
  this->path = path;
}
MedalTable::~MedalTable()
{
}

void MedalTable::showFile()
{
  buildingMedalFrameArray();
  sortMedalFrameArray();
}
void MedalTable::setPathFile(string path)
{
  this->path = path;
}
int MedalTable::getAmountLineFile()
{
  int lineAmount = 0;
  ifstream medalFrameFile(this->path);
  if (medalFrameFile.is_open())
  {

    medalFrameFile.close();
    return lineAmount;
  }
  return 0;
}
void MedalTable::buildingMedalFrameArray()
{
  ifstream medalFrameFile(this->path);
  
  char c;

  cout << "Carregando tabela........" << endl;
  
  if (medalFrameFile.is_open())
  {
    while (medalFrameFile.get(c))
    {
      string countryName;
      string medalAmount;
      CountryData countryData;

      do
      {
        countryName += c;
        medalFrameFile.get(c);
      } while (c != ' ');
      countryData.setCountryName(countryName);
      medalFrameFile.get(c);

      do
      {
        medalAmount += c;
        medalFrameFile.get(c);
      } while (c != ' ');
      countryData.setGoldMedalAmount(stoi(medalAmount));
      medalAmount = "";
      medalFrameFile.get(c);

      do
      {
        medalAmount += c;
        medalFrameFile.get(c);
      } while (c != ' ');
      countryData.setSilverMedalAmount(stoi(medalAmount));
      medalAmount = "";
      medalFrameFile.get(c);

      do
      {
        medalAmount += c;
      } while (c != '\n' && medalFrameFile.get(c));
      countryData.setBronzeMedalAmount(stoi(medalAmount));
      medalAmount = "";

      countriesData.push_back(countryData);

      cout
        << "País: " << countryData.getCountryName()
        << " Ouro: " << countryData.getGoldMedalAmount()
        << " Prata: " << countryData.getSilverMedalAmount()
        << " Bronze: " << countryData.getBronzeMedalAmount()
        << endl;
    }

    medalFrameFile.close();
  }
  else
  {
    cout << "Arquivo não pôde ser aberto" << endl;
  }
}
void MedalTable::sortMedalFrameArray()
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