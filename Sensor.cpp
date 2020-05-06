using namespace std;

#include <cmath> 
#include "Sensor.h"

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

list<Sensor> Sensor::getCluster(list<Sensor> data)
{
    
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
} 


Sensor::Sensor()
{
#ifdef MAP
    cout << "Appel au constructeur de <Sensor>" << endl;
#endif
} 

Sensor::Sensor(string id , int lat , int longi , string desc)
{
    sensorID=id;
    latitude=lat;
    longitude=longi;
    description=description;
}

Sensor::~Sensor ( )
{
#ifdef MAP
    cout << "Appel au destructeur de <Sensor>" << endl;  
#endif
}