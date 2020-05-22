#include <iostream>

using namespace std;

#include "Utilisateurs.h"

Utilisateurs::Utilisateurs ( const Utilisateurs & unUtilisateurs )
{
#ifdef MAP
   cout << "Appel au constructeur de copie de <Utilisateurs>" << endl;
#endif
} 


Utilisateurs::Utilisateurs()
{
#ifdef MAP
    cout << "Appel au constructeur de <Utilisateurs>" << endl;
#endif
} 

Utilisateurs::Utilisateurs(string id, string password)
{
#ifdef MAP
    cout << "Appel au constructeur de <Utilisateurs>" << endl;
#endif
} 

Utilisateurs::~Utilisateurs ( )
{
#ifdef MAP
    cout << "Appel au destructeur de <Utilisateurs>" << endl;
#endif
} 
