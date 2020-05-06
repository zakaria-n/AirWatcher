#if ! defined ( INDIVIDUAL_H )
#define INDIVIDUAL_H

#include "Utilisateurs.h"

class Individual : public Utilisateurs
{

public:

    Individual ( const Individual & unIndividual );

    Individual();

protected:

};

#endif // INDIVIDUAL_H
