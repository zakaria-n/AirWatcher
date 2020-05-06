/******** author Zakaria *********/
using namespace std;

#include "Measure.h"


Sensor Measure::getSensor(list<Sensor> data)
{
    Sensor s=Sensor();
    for(auto it=data.begin(); it!=data.end(); it++)
    {
        if(sensorID==it->getId())
        {
            s=*it;
        }
    }
    return s;
}
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
    attributeID=unMeasure.attributeID;
    sensorID=unMeasure.sensorID;
    value=unMeasure.value;
    isFake=unMeasure.isFake;
} 

Measure::Measure( string ts, string sID, string attID, float val, bool isF)
{
    timestamp=ts;
    sensorID=sID;
    attributeID=attID;
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
