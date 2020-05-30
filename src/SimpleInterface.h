#if ! defined ( SIMPLE_INTERFACE_H )
#define SIMPLE_INTERFACE_H

#include <vector>
#include <string>
#include "Utilisateurs.h"

using namespace std;

class SimpleInterface 
{

public:

    // Constructeur de copie
    SimpleInterface ( const SimpleInterface & unSimpleInterface );
    // Constructeur par défaut
    SimpleInterface();
    // Constructeur
    SimpleInterface(vector<pair<Utilisateurs,bool>> users);
    // Destructeur
    virtual ~SimpleInterface();

    vector<pair<Utilisateurs,bool>> getUsers();
    void addUser(Utilisateurs user);
    bool removeUser(Utilisateurs user);
    Utilisateurs authenticate(string id, string password);
    void deconnexion(Utilisateurs user);

protected:
    vector<pair<Utilisateurs,bool>> userList;
};

#endif // SIMPLE_INTERFACE_H
