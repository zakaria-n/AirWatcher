/******** author Zakaria *********/
#include <iostream>
#include <cmath>

using namespace std;

#include "Measure.h"



/*void Measure::detectFraud(list<Sensor> sdata, list<Measure> mdata)
{
    Catalogue cat;
    Sensor s=getSensor(sdata);
    double avg= 1.0; // cat.getAverageQuality(s.getLatitude(), s.getLongitude(), 10);
    if(abs(value-avg)>10)
    {
        isFake=true;
    }
}*/


float Measure::getValue()
{
    return value;
}

Measure::Measure ( const Measure & unMeasure )
{
#ifdef MAP
   cout << "Appel au constructeur de copie de <Measure>" << endl;
#endif
    timestamp=unMeasure.timestamp;
    attributeId=unMeasure.attributeId;
    sensorID=unMeasure.sensorID;
    value=unMeasure.value;
    isFake=unMeasure.isFake;
} 

Measure::Measure( string ts, string sID, string attID, float val, bool isF)
{
    timestamp=ts;
    sensorID=sID;
    attributeId=attID;
    value=val;
    isFake=isF;
}

Measure::Measure()
{
#ifdef MAP
    cout << "Appel au constructeur de <Measure>" << endl;
#endif
} 

Measure::~Measure ( )
{
#ifdef MAP
    cout << "Appel au destructeur de <Measure>" << endl;
#endif
} 
