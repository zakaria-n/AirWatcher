#if ! defined ( SENSOR_H )
#define SENSOR_H
#include <string>
#include <list>
using namespace std;

class Sensor 
{

public:

    // Méthode pour calculter la distance sphérique entre deux capteurs
    int getDistance(const Sensor other);
    // Méthode pour trouver les capteurs similaires
    list<Sensor> getCluster(list<Sensor> data);
    // Constructeur de copie
    Sensor ( const Sensor & unSensor );
    // Constructeur par défaut
    Sensor();
    // Constructeur
    Sensor(string id , int lat , int longi , string desc);
    // Destructeur
    virtual ~Sensor();

protected:

    string sensorID;
    double latitude;
    double longitude;
    string description;


};

#endif // SENSOR_H
