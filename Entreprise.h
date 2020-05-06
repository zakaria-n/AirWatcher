#if ! defined ( ENTREPRISE_H )
#define ENTREPRISE_H

#include "Utilisateurs.h"

class Entreprise : public Utilisateurs
{

public:

    Entreprise ( const Entreprise & unEntreprise );

    Entreprise();

protected:

};

#endif // ENTREPRISE_H
