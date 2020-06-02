#if ! defined ( INDIVIDUAL_H )
#define INDIVIDUAL_H

#include "Utilisateurs.h"

class Individual : public Utilisateurs
{

public:


    Individual ( const Individual & unIndividual );

    Individual();

    Individual(string id, string password, int numMeasure, int numValidatedMeasures, string sensor);

    int getPoints();

    void addPoint();

    void addTotalMeasures();

protected:
    int totalMeasures;
    int validatedMeasures;
    string sensorId;

};

#endif // INDIVIDUAL_H
