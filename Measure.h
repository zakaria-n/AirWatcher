/******** author Zakaria *********/
#if ! defined ( MEASURE_H )
#define MEASURE_H

#include <string>
#include <list>

#include "Sensor.h"
#include "Catalogue.h"

using namespace std;

class Measure
{

public:
    Sensor getSensor(list<Sensor> data);
    void detectFraud(list<Sensor> sdata, list<Measure> mdata);
    float getValue();
    Measure ( const Measure & unMeasures );
    Measure( string ts, string sID, string type, float val, bool isF);
    Measure();
    virtual ~Measure();

protected:

    string timestamp;
    string sensorID;
    string measureType; // 'SensorType' in the class diagram currently, which attribute is being measured
    float value;
    bool isFake;

};

#endif // MEASURES_H