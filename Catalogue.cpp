#include <fstream>
#include <iostream>
#include <list>
#include <sstream>
#include <vector>

using namespace std;

#include "Catalogue.h"
#include "Area.h"

// constructeur, destructeur

Catalogue::Catalogue ( const Catalogue & unCatalogue )
{
#ifdef MAP
   cout << "Appel au constructeur de copie de <Catalogue>" << endl;
#endif
}

Catalogue::Catalogue()
{
#ifdef MAP
  cout << "Appel au constructeur de <Catalogue>" << endl;
#endif
  nbMeasure = 0;
  nbSensor = 0;
}

Catalogue::~Catalogue ( )
{
#ifdef MAP
  cout << "Appel au destructeur de <Catalogue>" << endl;
#endif
}

vector<string> readLine (string line)
{
  vector<string> res;
  string token;
  istringstream iss(line);
  getline(iss, res[0], ';');
  getline(iss, res[1], ';');
  getline(iss, res[2], ';');
  getline(iss, res[3], ';');

  return res;
}

vector<string> readCleanerLine (string line)
{
  vector<string> res;
  string ignore;
  string token;
  istringstream iss(line);
  getline(iss, res[0], ';');
  getline(iss, res[1], ';');
  getline(iss, res[2], ';');
  getline(iss, ignore, ';');
  getline(iss, res[3], ';');
  getline(iss, res[4], ';');

  return res;
}

// setMeasures

void Catalogue::setMeasures (string fileName)
{

 ifstream lect;
 lect.open(fileName.c_str());
 string line;
 while (getline(lect, line))
 {
   vector<string> maMeasure = readLine(line);
   Measure newM = Measure (maMeasure[0],maMeasure[1],maMeasure[2],stof(maMeasure[3]),true);
   measureList.push_back(newM);
 }

 lect.close();
}

void Catalogue::setSensors(string fileName)
{
  ifstream lect;
  lect.open(fileName.c_str());
  string line;
  while (getline(lect, line))
  {
    vector<string> monSensor = readLine(line);
    list<Measure*> measures; // need to do smth w this
    Sensor newS = Sensor(monSensor[0],stoi(monSensor[1]),stoi(monSensor[2]),monSensor[3], measures);
    sensorList.push_back(newS);
  }
  lect.close();
}

void Catalogue::setCleaners(string fileName)
{
  ifstream lect;
  lect.open(fileName.c_str());
  string line;
  while (getline(lect, line))
  {
    vector<string> monCleaner = readCleanerLine(line);
    Purificateur newCleaner = Purificateur(monCleaner[0],stof(monCleaner[1]),stof(monCleaner[2]),monCleaner[3], monCleaner[4]);
    cleanerList.push_back(newCleaner);
  }
  lect.close();
}

/*void Catalogue::setMeasureTypes(string fileName)
{
  ifstream lect;

  string attributeID;
  string unit;
  string description;

  lect.open(fileName);
  lect.getline(a;100; ';');
  lect.getline(latitude;100; ':');
  lect.getline(longitude;100; ';');
  lect.getline();

  return 0;

}*/

vector<float> Catalogue::getAverageQuality
(float latitude, float longitude, float radius, time_t begin, time_t end) {
  Area curr = Area(latitude,longitude,radius);
  vector<float> averages = curr.getAverageQuality(begin, end);
}
