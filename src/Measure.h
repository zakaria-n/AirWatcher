#if ! defined ( MEASURE_H )
#define MEASURE_H

#include <string>
#include <list>
#include <iostream>

using namespace std;

class Measure
{
    friend class Sensor;

public:
    string getSensor();
    float getValue();
    int getDay();
    int getMonth();
    int getYear();
    int getDateScore();
   // void detectFraud(list<Sensor> sdata, list<Measure> mdata);

   friend ostream & operator << ( ostream & out, const Measure & unMeasure );

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
    
     

};

#endif // MEASURES_H