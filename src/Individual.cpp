#include <iostream>

using namespace std;

#include "Individual.h"

Individual::Individual ( const Individual & unIndividual )
{
#ifdef MAP
   cout << "Appel au constructeur de copie de <Individual>" << endl;
#endif
} 


Individual::Individual()
{
#ifdef MAP
    cout << "Appel au constructeur de <Individual>" << endl;
#endif
} 

Individual::Individual(string id, string password, int numMeasures, int numValidatedMeasures, string sensor) : Utilisateurs(id, password)
{
#ifdef MAP
    cout << "Appel au constructeur de <Individual>" << endl;
#endif
    sensorId = sensor;
    totalMeasures = numMeasures;
    validatedMeasures = numValidatedMeasures;
} 

int Individual::getPoints() {
    return validatedMeasures;
}

void Individual::addPoint() {
    totalMeasures++;
    validatedMeasures++;
}

void Individual::addTotalMeasures(){
    totalMeasures++;
}

