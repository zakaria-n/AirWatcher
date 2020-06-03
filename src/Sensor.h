#if ! defined ( SENSOR_H )
#define SENSOR_H
#include <ctime>
#include <string>
#include <list>
#include <vector>
#include "Measure.h"
using namespace std;



class Sensor 
{

    friend class Area;

public:
    // Adds measure to measure list of sensor
    void addMeasure (Measure);
    // Calculates the average measures for each measure type
    vector<float> avgMeasures(list<Measure>);
    // Calculates air quality based on the different measures.
    float airQuality(list<Measure>);
    // Restricts measures to a given period.
    list<Measure> truncateMeasuresToPeriod(string, string);
    // Outputs air quality for a given period.
    float airQualityOverPeriod(string, string);
    // Returns most recent measures recorded by Sensor
    list<Measure> mostRecentMeasure();
    // Calculates distances between two sensors based on their coordinates
    int getDistance(const Sensor other);
    // Assigns a score to a sensor based on its properties. Method discarded.
    float getScore(list<Measure> data);
    // Returns cluster of sensor, i.e other sensors with similar properties (geographical setting and recorded data).
    list<Sensor> getCluster(vector<Sensor> sensorData);
    // Displays cluster of sensor.
    void displayCluster(vector<Sensor> sensorData);
    // Displays measures embedded in sensor.
    void displayMeasures();
    // Getters
    string getId();
    double getLatitude();
    double getLongitude();
    string getDescripton();
    list<Measure> getMeasures();
    //void detectFraud(Measure m);
    //------------------------------------------------- Overloading

	friend ostream & operator << ( ostream & out, const Sensor & unSensor );

    Sensor& operator = ( const Sensor & sens );
    
    
    // Constructeur de copie
    Sensor ( const Sensor & unSensor );
    // Constructeur par défaut
    Sensor();
    // Constructeur
    Sensor(string id , float lat , float longi , string desc, list<Measure> mes);
    // Destructeur
    virtual ~Sensor();

protected:

    string sensorID;
    float latitude;
    float longitude;
    string description;
    list<Measure> mesures;


};

#endif // SENSOR_H
