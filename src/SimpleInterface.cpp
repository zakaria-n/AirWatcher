#include <iostream>
#include "SimpleInterface.h"

using namespace std;

SimpleInterface::SimpleInterface ( const SimpleInterface & unSimpleInterface )
{
#ifdef MAP
   cout << "Appel au constructeur de copie de <SimpleInterface>" << endl;
#endif
} 

SimpleInterface::SimpleInterface()
{
#ifdef MAP
    cout << "Appel au constructeur de <SimpleInterface>" << endl;
#endif
} 

SimpleInterface::SimpleInterface(vector<pair<Utilisateurs,bool>> users)
{
#ifdef MAP
    cout << "Appel au constructeur 2 de <SimpleInterface>" << endl;
#endif
    userList = users;
}

SimpleInterface::~SimpleInterface ( )
{
#ifdef MAP
    cout << "Appel au destructeur de <SimpleInterface>" << endl;  
#endif
}

void SimpleInterface::addUser(Utilisateurs user) 
{
    userList.push_back( pair<Utilisateurs,bool>(user,false) );
}

vector<pair<Utilisateurs,bool>> SimpleInterface::getUsers() 
{
    return userList;
}

bool SimpleInterface::removeUser(Utilisateurs user)
{
    bool deleted = false;
    vector<pair<Utilisateurs,bool>>::iterator it;
    for(auto it=userList.begin(); it!= userList.end() && !deleted; it++) {
        Utilisateurs currentUser = it->first;
        if (currentUser.getId() == user.getId()) {
            userList.erase(it);
            deleted = true;
        }
    }
    return deleted;
}
    

Utilisateurs SimpleInterface::authenticate(string id, string password) 
{
    Utilisateurs user;
    vector<pair<Utilisateurs,bool>>::iterator it;
    for(auto it=userList.begin(); it!= userList.end(); it++) {
        Utilisateurs currentUser = it->first;
        if (currentUser.getId() == id && currentUser.getPassword() == password ) {
            it->second = true;
            user = currentUser;
            break;
        }
    }
    return user;
}

void SimpleInterface::deconnexion(Utilisateurs user) 
{
  vector<pair<Utilisateurs,bool>>::iterator it;
    for(auto it=userList.begin(); it!= userList.end(); it++) {
        Utilisateurs currentUser = it->first;
        if (currentUser.getId() == user.getId() ) {
            it->second = false;
            break;
        }
    }
}