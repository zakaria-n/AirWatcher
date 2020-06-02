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

Entreprise::Entreprise(string id, string password, vector<Cleaner> cleanerInput) : Utilisateurs(id, password)
{
#ifdef MAP
    cout << "Appel au constructeur de <Entreprise>" << endl;
#endif
    cleaners = cleanerInput;
}

vector <Cleaner> Entreprise::getCleaners() {
    return cleaners;
}

bool Entreprise::ajouterCleaner(Cleaner cleaner) {
    bool success = false;
    cleaners.push_back(cleaner);
    return success;
}

Cleaner Entreprise::supprimerCleaner(Cleaner cleaner) {
    Cleaner deleted;
    for(auto it=cleaners.begin(); it!= cleaners.end(); it++) {
        if (*it == cleaner) {
            deleted = *it;
            cleaners.erase(it);
        }
    }
    return deleted;
}
