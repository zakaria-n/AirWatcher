using namespace std;

#include "Entreprise.h"

Entreprise::Entreprise ( const Entreprise & unEntreprise )
{
#ifdef MAP
   cout << "Appel au constructeur de copie de <Entreprise>" << endl;
#endif
} 


Entreprise::Entreprise()
{
#ifdef MAP
    cout << "Appel au constructeur de <Entreprise>" << endl;
#endif
} 

Entreprise::~Entreprise ( )
{
#ifdef MAP
    cout << "Appel au destructeur de <Entreprise>" << endl;
#endif
} 
