#include <iostream>
using namespace std;
#include "Area.h"

bool Area::contains (float lon, float lat)
{
    double dLat = (lon - latitude) * 
                      M_PI / 180.0; 
    double dLon = (lat - longitude) *  
                      M_PI / 180.0; 
    
    double latr = (latitude) * M_PI / 180.0; 
    double latr2 = (lat) * M_PI / 180.0; 

    double a =  pow(sin(dLat / 2), 2) +  
                pow(sin(dLon / 2), 2) *  
                cos(latr) * cos(latr2); 
    double earth_radius = 6371; 
    double distance = 2 * asin(sqrt(a)); 

    distance = distance * earth_radius;

    return (radius-distance >=0);

}

void Area::fillSensors(list<Sensor> data)
{
    for (auto it=data.begin(); it!=data.end(); it++)
    {
        if (contains(it->getLongitude(),it->getLatitude()))
        {
            sensors.push_back(*it);
        }
    }
}

float Area::avgQualityOverPeriod (string t1, string t2){
    int nbSensor =0;
    float quality=0.0;
    for (auto it=sensors.begin(); it!=sensors.end(); it++)
    {
        int elementary = it->airQualityOverPeriod(t1,t2);
        if (elementary>=1)
        {
            quality+=elementary;
            nbSensor++;
        }
    }
    return (quality/nbSensor);
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

Area::Area(float lat, float lon, float rayon, list <Sensor> sensorsInput)
{
#ifdef MAP
  cout << "Appel au constructeur de <Area>" << endl;
#endif
  latitude = lat;
  longitude = lon;
  radius = rayon;
  sensors = sensorsInput;
}

Area::~Area ( )
{
#ifdef MAP
  cout << "Appel au destructeur de <Area>" << endl;
#endif
}