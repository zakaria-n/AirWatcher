#include <iostream>
using namespace std;
#include "Area.h"

bool Area::contains (float lon, float lat)
{
    int distance = (int)(6371 * acos(sin(latitude)*sin(lat)
		+ cos(latitude)*cos(lat)*cos(longitude - lon)));
    return  (distance < radius);
}

bool Area::contains (Sensor s)
{
  return contains(s.getLongitude(), s.getLatitude() );
}

void Area::fillSensors(vector<Sensor> data)
{
    for (auto it=data.begin(); it!=data.end(); it++)
    {
        if (contains(*it))
        {
            sensors.push_back(*it);
        }
    }
}

void Area::fillSensorData(list <Measure> data)
{
  for (auto it=sensors.begin(); it!=sensors.end(); it++)
  {
      it->fillMeasures(data);
  }
}

void Area::displaySensors()
{
  vector<Sensor> sl = sensors;
  if (sl.size()==0)
  {
    cout << "This area contains no sensors." << endl;
  }
  for (auto it=sl.begin(); it!=sl.end(); it++)
  {
    cout << *it << endl;
  }
}


void Area::displayAreaMeasures()
{
  for (auto it=sensors.begin(); it!=sensors.end(); it++)
  {
    it->displayMeasures();
  }
}


float Area::avgQualityOverPeriod (string t1, string t2){
    cout << "In area rn" << endl;
    int nbSensor =0;
    float quality=0.0;
    for (auto it=sensors.begin(); it!=sensors.end(); it++)
    {
        cout << "fetching sensors" << endl;
        int elementary = it->airQualityOverPeriod(t1,t2);
        if (elementary>=1)
        {
            quality+=elementary;
            nbSensor++;
        }
    }
    return (quality/nbSensor);
}

vector <Sensor> Area::getSensors()
{
  return sensors;
}

Area::Area ( const Area & unArea )
{
#ifdef MAP
   cout << "Appel au constructeur de copie de <Area>" << endl;
#endif
}

Area::Area()
{
#ifdef MAP
  cout << "Appel au constructeur de <Area>" << endl;
#endif
}

Area::Area(float lat, float lon, float rayon, vector<Sensor> sensorList)
{
#ifdef MAP
  cout << "Appel au constructeur de <Area>" << endl;
#endif
  latitude = lat;
  longitude = lon;
  radius = rayon;
  fillSensors(sensorList);
}

Area::~Area ( )
{
#ifdef MAP
  cout << "Appel au destructeur de <Area>" << endl;
#endif
}