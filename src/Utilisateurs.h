
#if ! defined ( UTILISATEURS_H )
#define UTILISATEURS_H

#include <string>

using namespace std;

class Utilisateurs 
{

public:
    // Constructors - Destructor
    Utilisateurs ( const Utilisateurs & unUtilisateurs );

    Utilisateurs();

    Utilisateurs(string id, string password);

    virtual ~Utilisateurs();
    
    // Getters
    string getId();
    string getPassword();

protected:
    string id;
    string password;

};

#endif // UTILISATEURS_H
