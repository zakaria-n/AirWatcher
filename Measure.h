/******** author Zakaria *********/
#if ! defined ( MEASURE_H )
#define MEASURE_H
#include <string>
#include <list>
#include "Sensor.h"
using namespace std;

class Measure
{

public:
    Sensor getSensor(list<Sensor> data);
    float getValue();
    Measure ( const Measure & unMeasures );
    Measure( string ts, string sID, string attID, float val, bool isF);
    Measure();

protected:

    string timestamp;
    string sensorID;
    string attributeID;
    float value;
    bool isFake;

};

#endif // MEASURES_H