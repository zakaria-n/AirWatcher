#include <fstream>
#include <iostream>
#include <list>

using namespace std;

#include "Catalogue.h"

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

string* readMeasureLine (ifstream lect)
{

  string res [4];

  lect.getline(res[1];100; ';');
  lect.getline(res[2];100; ';');
  lect.getline(res[3];100; ';');
  lect.getline(res[4];100; ';');

  return res;
}

string* readSensorLine (ifstream lect)
{

  string res [4];

  lect.getline(res[1];100; ';');
  lect.getline(res[2];100; ';');
  lect.getline(res[3];100; ';');
  lect.getline(res[4];100; ';');

  return res;
}

// setMeasures

int setMeasures (string  &fileName)
{
 ifstream lect;

 string timeStamp;
 string sensorId;
 string sensorType;
 string sensorValue;

 lect.open(fileName.c_str());
 while (!lect.eof())
 {
   maMeasure = readMeasureLine(lect);
   Measure newM = new Measure (maMeasure[0],maMeasure[1],maMeasure[2],maMeasure[3],True);
   measureList.push_back(newM);
 }

 lect.close();
 return 0;
}

int setSensors(string &fileName)
{
  ifstream lect;

  string sensorID;
  string latitude;
  string longitude;
  string description;

  lect.open(fileName.c_str());
  while (!lect.eof())
  {
    monSensor = readSensorLine(lect);
    Sensor newS = new Sensor (monSensor[0],monSensor[1],monSensor[2],monSensor[3]);
    sensorList.push_back(newS);
  }
  lect.close();
  return 0;
}

int setMeasureTypes(string fileName)
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

}
