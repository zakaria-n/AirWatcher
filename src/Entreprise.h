#if ! defined ( ENTREPRISE_H )
#define ENTREPRISE_H

#include <string>
#include <list>
#include <vector>

#include "Utilisateurs.h"
#include "Cleaner.h"

class Entreprise : public Utilisateurs
{

public:

    Entreprise ( const Entreprise & unEntreprise );
    Entreprise();
    Entreprise (string id, string password, vector <Cleaner> cleaners);

    vector <Cleaner> getCleaners();
    // Self explanatory
    bool ajouterCleaner(Cleaner cleaner);
    Cleaner supprimerCleaner(Cleaner cleaner);

protected:
    vector <Cleaner> cleaners;

};

#endif // ENTREPRISE_H
