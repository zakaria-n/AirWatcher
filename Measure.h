/******** author Zakaria *********/
#if ! defined ( MEASURE_H )
#define MEASURE_H

#include <string>
#include <list>
#include <iostream>

#include "Catalogue.h"

using namespace std;

typedef struct{
    string id;
    string unit;
    string description;
} MeasureType; 

class Measure
{
    friend class Sensor;

public:
    string getSensor();
    float getValue();
    int getDay();
    int getMonth();
    int getYear();
    void detectFraud(list<Sensor> sdata, list<Measure> mdata);
    Measure ( const Measure & unMeasures );
    Measure( string ts, string sID, string attID, float val, bool isF);
    Measure();
    virtual ~Measure();

protected:

    string timestamp;
    string sensorID;
    string attributeId;
    float value;
    bool isFake;
    MeasureType type;
    
     

};

#endif // MEASURES_H