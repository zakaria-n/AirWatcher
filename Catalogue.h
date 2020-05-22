
#if ! defined ( CATALOGUE_H )
#define CATALOGUE_H

#include <list>

#include "Measure.h"

class Catalogue 
{

public:
    double getAverageQuality(double lat, double long, double radius);
    list<Sensor> parseSensors();
    list<Measure> parseMeasures();
    Catalogue ( const Catalogue & unCatalogue );
    Catalogue();
    virtual ~Catalogue();

protected:

};

#endif // CATALOGUE_H
