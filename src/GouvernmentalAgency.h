#if ! defined ( GOUVERNMENTAL_AGENCY_H )
#define GOUVERNMENTAL_AGENCY_H

#include "Utilisateurs.h"

class GouvernmentalAgency : public Utilisateurs
{

public:

    GouvernmentalAgency ( const GouvernmentalAgency & unGouvernmentalAgency );

    GouvernmentalAgency();

    GouvernmentalAgency(string id, string password);

protected:

};

#endif // GOUVERNMENTAL_AGENCY_H
