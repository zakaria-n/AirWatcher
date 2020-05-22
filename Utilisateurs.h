
#if ! defined ( UTILISATEURS_H )
#define UTILISATEURS_H


class Utilisateurs 
{

public:

    Utilisateurs ( const Utilisateurs & unUtilisateurs );

    Utilisateurs();

    Utilisateurs(string id, string password);

    virtual ~Utilisateurs();

protected:

};

#endif // UTILISATEURS_H
