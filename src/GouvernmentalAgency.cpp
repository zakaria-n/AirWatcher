#include <iostream>

using namespace std;

#include "GouvernmentalAgency.h"

GouvernmentalAgency::GouvernmentalAgency ( const GouvernmentalAgency & unGouvernmentalAgency )
{
#ifdef MAP
   cout << "Appel au constructeur de copie de <GouvernmentalAgency>" << endl;
#endif
} 


GouvernmentalAgency::GouvernmentalAgency()
{
#ifdef MAP
    cout << "Appel au constructeur de <GouvernmentalAgency>" << endl;
#endif
} 

GouvernmentalAgency::GouvernmentalAgency(string id, string password) : Utilisateurs(id, password)
{
#ifdef MAP
    cout << "Appel au constructeur de <GouvernmentalAgency>" << endl;
#endif
}
