#include <iostream>

using namespace std;

#include "Entreprise.h"

Entreprise::Entreprise ( const Entreprise & unEntreprise ) : Utilisateurs(unEntreprise)
{
#ifdef MAP
   cout << "Appel au constructeur de copie de <Entreprise>" << endl;
#endif
    cleaners = unEntreprise.cleaners;
} 

Entreprise::Entreprise()
{
#ifdef MAP
    cout << "Appel au constructeur de <Entreprise>" << endl;
#endif
} 

Entreprise::Entreprise(string id, string password, vector<Purificateur> cleanerInput) : Utilisateurs(id, password)
{
#ifdef MAP
    cout << "Appel au constructeur de <Entreprise>" << endl;
#endif
    cleaners = cleanerInput;
} 

vector<Purificateur> Entreprise::getCleaners() {
    return cleaners;
}

bool Entreprise::ajouterPurificateur(Purificateur cleaner) {
    bool success = false;
    cleaners.push_back(cleaner);
    return success;
}

Purificateur Entreprise::supprimerPurificateur(Purificateur cleaner) {
    Purificateur deleted;
    for(auto it=cleaners.begin(); it!= cleaners.end(); it++) {
        if (*it == cleaner) {
            deleted = *it;
            cleaners.erase(it);
        }
    }
    return deleted;
}
