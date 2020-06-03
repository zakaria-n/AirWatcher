
#if ! defined ( CATALOGUE_H )
#define CATALOGUE_H

#include <vector>
#include "Sensor.h"
#include "Cleaner.h"

class Catalogue
{

public:
    // Returns the average quality in a given area over a given timespan.
    float getAverageQuality(float latitude, float longitude, int radius, string begin, string end="2019-12-31");
    // Adds cleaner to the collection of cleaners that's embedded in Catalogue.
    void addCleaner(Cleaner cleaner);
    // Removes cleaner from Catalogue.
    Cleaner removeCleaner(string cleanerId);
    // Self explanatory (see above)
    void addSensor(string id, float latitude, float longitude, string description);
    void addSensor(Sensor s);
    void addMeasure(Measure uneMeasure);
    // Retrieves data from individual user input and only loads it in memory if it passes a fraud scan.
    bool addIndivMeasure(Measure uneMeasure,string id);
    // Scans input data against existing record of measures to determine the likeliness of input being compromised.
    void detectFraud(Measure* m);

    // Constructors - Destructor
    Catalogue();
    Catalogue(string measureFile, string sensorFile, string cleanerFile);
    Catalogue ( const Catalogue & unCatalogue );
    virtual ~Catalogue ();
    //getters
    vector<Sensor> getSensorList();
    list<Measure> getMeasureList();
    vector<Cleaner> getCleanerList();
    Cleaner GetCleanerById(string id);
    Sensor GetSensorById(string id);


protected:

//setter
    void setMeasures(string fileName);
    void setSensors (string fileName);
    void setCleaners (string fileName);
    list<Measure> setIndividualMeasures(string fileName);

    list<Measure> measureList;
    vector<Sensor> sensorList;
    vector<Cleaner> cleanerList;
    int nbMeasure;
    int nbSensor;
    int nbCleaner;

};

#endif // CATALOGUE_H
