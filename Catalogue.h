
#if ! defined ( CATALOGUE_H )
#define CATALOGUE_H

#include <list>

class Catalogue
{

public:
    double getAverageQuality(double lat, double long, double radius);
    list<Sensor> parseSensors();
    list<Measure> parseMeasures();
    int identifySimilarities(list <Sensor> mySensorList);

// constructeur - déstructeur
    Catalogue();
    Catalogue ( const Catalogue & unCatalogue );
    virtual ~Catalogue ();
//getter
    list <Sensor> getSensorList();
    list <Measure> getMeasureList();

//setter
    list<Measure> setMeasures(string fileName);
    list<Sensor> setSensors (string fileName);
    list<Measure> setIndividualMeasures(string fileName);
    int setMeasureTypes(string fileName);

protected:

  list <Measure> measureList;
  list <Sensor> sensorList;
  list <Cleaner> cleanerList;
  int nbMeasure;
  int nbSensor;


};

#endif // CATALOGUE_H
