
#if ! defined ( CATALOGUE_H )
#define CATALOGUE_H

#include <vector>
#include "Sensor.h"
#include "Purificateur.h"

class Catalogue
{

public:
    float getAverageQuality(float latitude, float longitude, float radius, string begin, string end);
    list<Sensor> parseSensors();
    list<Measure> parseMeasures();
    int identifySimilarities(list <Sensor> mySensorList);
    void addCleaner(Purificateur cleaner);
    Purificateur removeCleaner(string cleanerId);

// constructeur - déstructeur
    Catalogue();
    Catalogue(string measureFile, string sensorFile, string cleanerFile);
    Catalogue ( const Catalogue & unCatalogue );
    virtual ~Catalogue ();
//getter
    list<Sensor> getSensorList();
    list<Measure> getMeasureList();
    list<Purificateur> getCleanerList();


protected:

//setter
    void setMeasures(string fileName);
    void setSensors (string fileName);
    void setCleaners (string fileName);
    list<Measure> setIndividualMeasures(string fileName);
   // void setMeasureTypes(string fileName);

    list<Measure> measureList;
    list<Sensor> sensorList;
    list<Purificateur> cleanerList;
    int nbMeasure;
    int nbSensor;
    int nbCleaner;

};

#endif // CATALOGUE_H
