#if ! defined ( AREA_H )
#define AREA_H

#include <string>
#include <cmath> 
#include "Sensor.h"

using namespace std;

class Area 
{

public:

    // Checks if two given coordinates belong (are within the range) of area.
    bool contains (float lon, float lat);
    // Check if a sensor is in area (calls contains(float, float) on its coordinates).
    bool contains (Sensor s);
    // Loops through a collection of sensors to fill the sensors list with those in area.
    void fillSensors (vector<Sensor> data);
    // Returns the average air quality in area over a given period. Calls quality method on each
    // of the sensors in area and averages the results.
    float avgQualityOverPeriod (string t1, string t2);
    // Getter
    vector<Sensor> getSensors();

    // Constructors - Destructor
    Area  ( const Area  & unArea  );

    Area ();

    Area (float lat, float lon, int radius, vector<Sensor> sensorList);

    virtual ~Area ();

protected:
    float latitude;
    float longitude;
    int radius;
    vector <Sensor> sensors;

};

#endif // Area _H
