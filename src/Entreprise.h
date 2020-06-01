#if ! defined ( ENTREPRISE_H )
#define ENTREPRISE_H

#include <string>
#include <list>

#include "Utilisateurs.h"
#include "Cleaner.h"

class Entreprise : public Utilisateurs
{

public:

    Entreprise ( const Entreprise & unEntreprise );
    Entreprise();
    Entreprise (string id, string password, list<Cleaner> cleaners);

    list<Cleaner> getCleaners();

    bool ajouterCleaner(Cleaner cleaner);
    Cleaner supprimerCleaner(Cleaner cleaner);

protected:
    list<Cleaner> cleaners;

};

#endif // ENTREPRISE_H
