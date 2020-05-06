using namespace std;

#include "Sensor.h"

Sensor::Sensor ( const Sensor & unSensor )
{
#ifdef MAP
   cout << "Appel au constructeur de copie de <Sensor>" << endl;
#endif
} 


Sensor::Sensor()
{
#ifdef MAP
    cout << "Appel au constructeur de <Sensor>" << endl;
#endif
} 

Sensor::~Sensor ( )
{
#ifdef MAP
    cout << "Appel au destructeur de <Sensor>" << endl;
#endif
} 
