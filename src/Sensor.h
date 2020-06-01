/******** author Zakaria *********/
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
    void fillMeasures(list<Measure>);
    // Calculates the average measures for each measure type
    vector<float> avgMeasures(list<Measure>);
    int airQuality(list<Measure>);
    list<Measure> truncateMeasuresToPeriod(string, string);
    int airQualityOverPeriod(string, string);
    list<Measure> mostRecentMeasure();
    // Méthode pour calculter la distance sphérique entre deux capteurs
    int getDistance(const Sensor other);
    // Méthode pour attribuer à un capteur un score synthétisant ses propriétés
    float getScore(list<Measure> data);
    // Méthode pour trouver les capteurs similaires
    list<Sensor> getCluster(list<Sensor> sensorData, list<Measure> mesureData);

    void displayMeasures();
    // Getters
    string getId();
    double getLatitude();
    double getLongitude();
    string getDescripton();
    list<Measure> getMeasures();
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
