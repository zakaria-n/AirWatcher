#if ! defined ( USER_BASE_H )
#define USER_BASE_H

#include <vector>
#include <string>
#include "Utilisateurs.h"

using namespace std;

class UserBase 
{

public:

    // Contructors - Destructor
    UserBase ( const UserBase & unUserBase );
    UserBase();
    UserBase(vector<Utilisateurs*> users);
    virtual ~UserBase();

    // Returns list of users
    vector<pair<Utilisateurs*,bool>> getUsers();
    // Adds user to collection.
    void addUser(Utilisateurs* user);
    // Removes user from collection.
    bool removeUser(Utilisateurs* user);
    // Authenticates user
    Utilisateurs* authenticate(string id, string password);
    // Ends user session
    void deconnexion(Utilisateurs* user);
    // Returns user type (individual or corporation)
    string getUserType(Utilisateurs* user);

protected:
    vector<pair<Utilisateurs*,bool>> userList;
};

#endif // USER_BASE_H
