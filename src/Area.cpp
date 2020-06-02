#include <iostream>
using namespace std;
#include "Area.h"

bool Area::contains (float lon, float lat)
{
    /*int distance = (int)(6371 * acos(sin(latitude)*sin(lat)
		+ cos(latitude)*cos(lat)*cos(longitude - lon)));
    return  (distance < radius);*/
    double dLat = (lat - latitude) * M_PI / 180.0; 
    double dLon = (lon - longitude) *  M_PI / 180.0; 
    double latr = (latitude) * M_PI / 180.0; 
    double latr2 = (lat) * M_PI / 180.0; 
  
    // apply formulae 
    double a =  pow(sin(dLat / 2), 2) +  pow(sin(dLon / 2), 2) *  cos(latr) * cos(latr2); 
    double rad = 6371; 
    double c = 2 * asin(sqrt(a)); 
    double distance = rad * c;
    return (distance<=radius);
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
    //cout << "In are\n" << endl;
    int nbSensor =0;
    float quality=0.0;
    //cout << t1 << endl;
    //cout << t2 << endl;
    for (auto it=sensors.begin(); it!=sensors.end(); it++)
    {
        //cout << "fetching sensors\n" << endl;
        float elementary = it->airQualityOverPeriod(t1,t2);
        //cout << "elementary" << elementary << endl;
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

Area::Area(float lat, float lon, int rayon, vector<Sensor> sensorList)
{
#ifdef MAP
  cout << "Appel au constructeur de <Area>" << endl;
#endif
  latitude = lat;
  longitude = lon;
  radius = rayon;
  fillSensors(sensorList);
  //cout << sensors.size() << endl;
}

Area::~Area ( )
{
#ifdef MAP
  cout << "Appel au destructeur de <Area>" << endl;
#endif
}
