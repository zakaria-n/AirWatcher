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

Utilisateurs::Utilisateurs(string idInput, string passwordInput)
{
#ifdef MAP
    cout << "Appel au constructeur de <Utilisateurs>" << endl;
#endif
    id = idInput;
    password = passwordInput;
} 

Utilisateurs::~Utilisateurs ( )
{
#ifdef MAP
    cout << "Appel au destructeur de <Utilisateurs>" << endl;
#endif
} 

string Utilisateurs::getId() {
    return id;
}

string Utilisateurs::getPassword() {
    return password;
}
