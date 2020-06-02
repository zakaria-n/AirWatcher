#if ! defined ( USER_BASE_H )
#define USER_BASE_H

#include <vector>
#include <string>
#include "Utilisateurs.h"

using namespace std;

class UserBase 
{

public:

    // Constructeur de copie
    UserBase ( const UserBase & unUserBase );
    // Constructeur par défaut
    UserBase();
    // Constructeur
    UserBase(vector<Utilisateurs*> users);
    // Destructeur
    virtual ~UserBase();

    vector<pair<Utilisateurs*,bool>> getUsers();
    void addUser(Utilisateurs* user);
    bool removeUser(Utilisateurs* user);
    Utilisateurs* authenticate(string id, string password);
    void deconnexion(Utilisateurs* user);
    string getUserType(Utilisateurs* user);

protected:
    vector<pair<Utilisateurs*,bool>> userList;
};

#endif // USER_BASE_H
