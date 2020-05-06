/******** author Zakaria *********/
#if ! defined ( SENSOR_H )
#define SENSOR_H
#include <string>
#include <list>
#include "Measure.h"
using namespace std;

class Sensor 
{

public:

    // Méthode pour calculter la distance sphérique entre deux capteurs
    int getDistance(const Sensor other);
    // Méthode pour attribuer à un capteur un scor synthétisant ses propriétés
    float getScore();
    // Méthode pour trouver les capteurs similaires
    list<Sensor> getCluster(list<Sensor> data);
    // Getter de l'identifiant
    string getId();
    // Constructeur de copie
    Sensor ( const Sensor & unSensor );
    // Constructeur par défaut
    Sensor();
    // Constructeur
    Sensor(string id , int lat , int longi , string desc, list<Measure> mes);
    // Destructeur
    virtual ~Sensor();

protected:

    string sensorID;
    double latitude;
    double longitude;
    string description;
    list<Measure> mesures;


};

#endif // SENSOR_H
