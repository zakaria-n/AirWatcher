#if ! defined ( ENTREPRISE_H )
#define ENTREPRISE_H

#include <string>
#include <vector>

#include "Utilisateurs.h"
#include "Purificateur.h"

class Entreprise : public Utilisateurs
{

public:

    Entreprise ( const Entreprise & unEntreprise );
    Entreprise();
    Entreprise (string id, string password, vector<Purificateur> cleaners);

    vector<Purificateur> getCleaners();
    string getType();

    bool ajouterPurificateur(Purificateur cleaner);
    Purificateur supprimerPurificateur(Purificateur cleaner);

protected:
    vector<Purificateur> cleaners;
    string type;

};

#endif // ENTREPRISE_H