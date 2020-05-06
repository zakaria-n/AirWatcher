#if ! defined ( ENTREPRISE_H )
#define ENTREPRISE_H

#include "Utilisateurs.h"
#include "Purificateur.h"
#include <string>

class Entreprise : public Utilisateurs
{

public:

    Entreprise ( const Entreprise & unEntreprise );
    Entreprise();
    Entreprise (string id, string password, Purificateur cleaner);
    ~Entreprise ( );

    Purificateur getCleaner();
    string getType();

protected:
    Purificateur cleaner;
    string type;

};

#endif // ENTREPRISE_H
