#include <iostream>

using namespace std;

#include "Entreprise.h"

Entreprise::Entreprise ( const Entreprise & unEntreprise ) : Utilisateurs(unEntreprise)
{
#ifdef MAP
   cout << "Appel au constructeur de copie de <Entreprise>" << endl;
#endif
    cleaner = unEntreprise.cleaner;
    type = unEntreprise.type;
} 

Entreprise::Entreprise()
{
#ifdef MAP
    cout << "Appel au constructeur de <Entreprise>" << endl;
#endif
} 

Entreprise::Entreprise(string id, string password, Purificateur cleanerInput) : Utilisateurs(id, password)
{
#ifdef MAP
    cout << "Appel au constructeur de <Entreprise>" << endl;
#endif
    cleaner = cleanerInput;
    type = "Entreprise";
} 

Entreprise::~Entreprise ( )
{
#ifdef MAP
    cout << "Appel au destructeur de <Entreprise>" << endl;
#endif
} 

Purificateur Entreprise::getCleaner() {
    return cleaner;
}

string Entreprise::getType() {
    return type;
}
