/******** author Zakaria *********/
#include <iostream>
#include <cmath> 
#include "Sensor.h"
#include "Measure.h"

using namespace std;

int Sensor::getDistance(const Sensor other)
{
    // distance between latitudes 
    // and longitudes 
    double dLat = (other.latitude - latitude) * 
                      M_PI / 180.0; 
    double dLon = (other.longitude - longitude) *  
                      M_PI / 180.0; 
  
    // convert to radians 
    double latr = (latitude) * M_PI / 180.0; 
    double latr2 = (other.latitude) * M_PI / 180.0; 
  
    // apply formulae 
    double a =  pow(sin(dLat / 2), 2) +  
                pow(sin(dLon / 2), 2) *  
                cos(latr) * cos(latr2); 
    double rad = 6371; 
    double c = 2 * asin(sqrt(a)); 
    return rad * c; 
}

float Sensor::getScore()
{
    int i=0;
    float s=0;
    list<Measure*>::iterator iter;

    iter = mesures.begin();
    for (iter = mesures.begin(); iter!=mesures.end() && (i<4); iter++, i++)
    {
        Measure* temp = (*iter);
        s+=temp->getValue();
    }
    return s/4;
}

list<Sensor> Sensor::getCluster(list<Sensor> data)
{
    list<Sensor> cluster;
    float N=getScore();
    for (auto it=data.begin(); it!=data.end(); it++)
    {
        if(getDistance(*it)<=10 && abs(N-it->getScore())<10)
        {
            cluster.push_front(*it);
        }
    }
    return cluster;
}

string Sensor::getId()
{
    return sensorID;
}

double Sensor::getLatitude()
{
    return latitude;
}

double Sensor::getLongitude()
{
    return longitude;
}

Sensor::Sensor ( const Sensor & unSensor )
{
#ifdef MAP
   cout << "Appel au constructeur de copie de <Sensor>" << endl;
#endif
    sensorID=unSensor.sensorID;
    latitude=unSensor.latitude;
    longitude=unSensor.longitude;
    description=unSensor.description;
    mesures=unSensor.mesures;
} 


Sensor::Sensor()
{
#ifdef MAP
    cout << "Appel au constructeur de <Sensor>" << endl;
#endif
} 

Sensor::Sensor(string id , int lat , int longi , string desc, list<Measure*> mes)
{
    sensorID=id;
    latitude=lat;
    longitude=longi;
    description=desc;
    mesures=mes;
}

Sensor::~Sensor ( )
{
#ifdef MAP
    cout << "Appel au destructeur de <Sensor>" << endl;  
#endif
}