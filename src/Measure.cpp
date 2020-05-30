/******** author Zakaria *********/
#include <iostream>
#include <cmath>

using namespace std;

#include "Measure.h"


string Measure::getSensor()
{
    return sensorID;
}


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

int Measure::getDay ()
{
	int pos =  timestamp.find_first_of("T");
	return stoi(timestamp.substr(pos-3,2));
}

int Measure::getMonth ()
{
	int pos =  timestamp.find_first_of("T");
	return stoi(timestamp.substr(pos-5,2));
}


int Measure::getYear ()
{
	int pos =  timestamp.find_first_of("T");
	return stoi(timestamp.substr(pos-10,4));
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
