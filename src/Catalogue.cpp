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
  nbCleaner = 0;
}

Catalogue::Catalogue(string measureFile, string sensorFile, string cleanerFile)
{
#ifdef MAP
  cout << "Appel au constructeur de <Catalogue>" << endl;
#endif
  setSensors(sensorFile);
  setMeasures(measureFile);
  setCleaners(cleanerFile);
  nbMeasure = measureList.size();;
  nbSensor = sensorList.size();
  nbCleaner = cleanerList.size();
}

Catalogue::~Catalogue ( )
{
#ifdef MAP
  cout << "Appel au destructeur de <Catalogue>" << endl;
#endif
}

vector<Sensor> Catalogue::getSensorList() {
  return sensorList;
}
list<Measure> Catalogue::getMeasureList() {
  return measureList;
}

vector <Cleaner> Catalogue::getCleanerList() {
  return cleanerList;
}

Cleaner Catalogue::GetCleanerById(string id){
  Cleaner monCleaner;
  for (auto it=cleanerList.begin(); it!=cleanerList.end(); it++)
  {
    if (it->GetId()==id){
      monCleaner = *it;
    }
  }
  return monCleaner;
}

Sensor Catalogue::GetSensorById(string id)
{
    Sensor mySensor;
    for (auto it=sensorList.begin(); it!= sensorList.end(); it++)
    {
        if(it->getId()==id)
        {
          mySensor = *it;
        }
    }
    return mySensor;
}

void Catalogue::addMeasure(Measure uneMeasure){
  measureList.push_back(uneMeasure);
}

bool Catalogue::addIndivMeasure(Measure uneMeasure,string id){ 
    detectFraud(&uneMeasure);                       //Verification avant l'ajout dans la liste
    if(!uneMeasure.getIsFake()){                   
      measureList.push_back(uneMeasure);
    }
    return (!uneMeasure.getIsFake());                //fake data => false; good data => true
}


void Catalogue::addCleaner(Cleaner cleaner) {
  cleanerList.push_back(cleaner);
}

void Catalogue::addSensor(string id, float latitude, float longitude, string description) {
  list<Measure> measures;
  Sensor newSensor = Sensor(id,longitude,latitude,description, measures);
  sensorList.push_back(newSensor);
}

void Catalogue::addSensor(Sensor s) {
  sensorList.push_back(s);
}

Cleaner Catalogue::removeCleaner(string cleanerId) {
  Cleaner removed;
    for (auto it=cleanerList.begin(); it!=cleanerList.end(); it++)
    {
      if(it->GetId()==cleanerId) {
        removed = *it;
        cleanerList.erase(it);
        break;
      }
    }
  return removed;
}

vector<string> readLine (string line)
{
  vector<string> res;
  istringstream iss(line);

  string one;
  string two;
  string three;
  string four;

  getline(iss, one, ';');
  getline(iss, two, ';');
  getline(iss, three, ';');
  getline(iss, four, ';');

  res.push_back(one);
  res.push_back(two);
  res.push_back(three);
  res.push_back(four);

  return res;
}

vector<string> readCleanerLine (string line)
{
  vector<string> res;
  string ignore;
  istringstream iss(line);

  string one;
  string two;
  string three;
  string four;
  string five;

  getline(iss, one, ';');
  getline(iss, two, ';');
  getline(iss, three, ';');
  getline(iss, ignore, ';');
  getline(iss, four, ';');
  getline(iss, five, ';');

  res.push_back(one);
  res.push_back(two);
  res.push_back(three);
  res.push_back(four);
  res.push_back(five);

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
   Measure newM = Measure (maMeasure[0],maMeasure[1],maMeasure[2],stof(maMeasure[3]),false);
   int sensor = stoi(maMeasure[1].substr (6));
   sensorList.at(sensor).addMeasure(newM);
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
    list<Measure> measures; // need to do smth w this
    Sensor newSensor = Sensor(monSensor[0],stof(monSensor[1]),stof(monSensor[2]),monSensor[3], measures);
    sensorList.push_back(newSensor);
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
    Cleaner newCleaner = Cleaner(monCleaner[0],stof(monCleaner[1]),stof(monCleaner[2]),monCleaner[3], monCleaner[4]);
    //printf("Le cleaner : %s ajouté ",newCleaner.GetId());
    cleanerList.push_back(newCleaner);
  }
  lect.close();
}

float Catalogue::getAverageQuality
(float latitude, float longitude, int radius, string begin, string end) {
  Area curr = Area(latitude,longitude, radius, sensorList);
  float average = curr.avgQualityOverPeriod(begin, end);
  return average;
}


void Catalogue::detectFraud(Measure* m)
{
    Sensor s;
    vector<float> avgVec = s.avgMeasures(measureList); //prend toutes les donnees disponibles puis calcule les moyennes
    float avg;
    if (m->getAttributeID().compare("O3") == 0){
      avg = avgVec[0];
    }
    if (m->getAttributeID().compare("NO2") == 0){
          avg = avgVec[1];
    }
    if (m->getAttributeID().compare("SO2") == 0){
      avg = avgVec[2];
    }
    if (m->getAttributeID().compare("PM10") == 0){
      avg = avgVec[3];
    }
    
    if(abs(m->getValue()-avg)>10.0)
    {
        //cout << "avg: " << avg << endl;
        m->setIsFake(true);
    }
}