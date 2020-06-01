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

    void fillSensors (vector<Sensor> data);

    float avgQualityOverPeriod (string t1, string t2);

    Area  ( const Area  & unArea  );

    Area ();

    Area (float lat, float lon, float radius, vector <Sensor> sensors);

    virtual ~Area ();

protected:
    float latitude;
    float longitude;
    int radius;
    vector <Sensor> sensors;

};

#endif // Area _H
