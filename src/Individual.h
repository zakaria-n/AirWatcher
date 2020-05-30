#if ! defined ( INDIVIDUAL_H )
#define INDIVIDUAL_H

#include "Utilisateurs.h"

class Individual : public Utilisateurs
{

public:

    Individual ( const Individual & unIndividual );

    Individual();

    Individual(string id, string password, int numMeasure, int numValidatedMeasures);

    int getPoints();

protected:
    int totalMeasures;
    int validatedMeasures;

};

#endif // INDIVIDUAL_H
