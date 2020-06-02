#if ! defined ( AREA_H )
#define AREA_H

#include <string>
#include <cmath> 
#include "Sensor.h"

using namespace std;

class Area 
{

public:

    bool contains (float lon, float lat);

    bool contains (Sensor s);

    void fillSensors (vector<Sensor> data, list<Measure> mdata);

    void displaySensors();

    void fillSensorData(list <Measure>);

    void displayAreaMeasures();

    float avgQualityOverPeriod (string t1, string t2);
    
    vector<Sensor> getSensors();

    Area  ( const Area  & unArea  );

    Area ();

    Area (float lat, float lon, float radius, vector<Sensor> sensorList, list<Measure> mdata);

    virtual ~Area ();

protected:
    float latitude;
    float longitude;
    int radius;
    vector <Sensor> sensors;

};

#endif // Area _H
