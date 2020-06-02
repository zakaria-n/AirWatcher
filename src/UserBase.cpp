#include <iostream>
#include "UserBase.h"
#include "GouvernmentalAgency.h"
#include "Individual.h"
#include "Entreprise.h"

using namespace std;

UserBase::UserBase ( const UserBase & unUserBase )
{
#ifdef MAP
   cout << "Appel au constructeur de copie de <UserBase>" << endl;
#endif
} 

UserBase::UserBase()
{
#ifdef MAP
    cout << "Appel au constructeur de <UserBase>" << endl;
#endif
} 

UserBase::UserBase(vector<Utilisateurs*> users)
{
#ifdef MAP
    cout << "Appel au constructeur 2 de <UserBase>" << endl;
#endif
    for(int i=0; i < users.size(); i++) {
        auto tmp = make_pair(users[i], false);
        userList.push_back(tmp);
    }
}

UserBase::~UserBase ( )
{
#ifdef MAP
    cout << "Appel au destructeur de <UserBase>" << endl;  
#endif
}

void UserBase::addUser(Utilisateurs* user) 
{
    userList.push_back( pair<Utilisateurs*,bool>(user,false) );
}

vector<pair<Utilisateurs*,bool>> UserBase::getUsers() 
{
    return userList;
}

bool UserBase::removeUser(Utilisateurs* user)
{
    bool deleted = false;
    vector<pair<Utilisateurs,bool>>::iterator it;
    for(auto it=userList.begin(); it!= userList.end() && !deleted; it++) {
        Utilisateurs currentUser = *it->first;
        if (currentUser.getId() == user->getId()) {
            userList.erase(it);
            deleted = true;
        }
    }
    return deleted;
}
    

Utilisateurs* UserBase::authenticate(string id, string password) 
{
    Utilisateurs* user = NULL;
    vector<pair<Utilisateurs*,bool>>::iterator it;
    for(auto it=userList.begin(); it!= userList.end(); it++) {
        Utilisateurs* currentUser = it->first;
        if (currentUser->getId() == id && currentUser->getPassword() == password ) {
            it->second = true;
            user = currentUser;
            break;
        }
    }
    return user;
}

void UserBase::deconnexion(Utilisateurs* user) 
{
  vector<pair<Utilisateurs*,bool>>::iterator it;
    for(auto it=userList.begin(); it!= userList.end(); it++) {
        Utilisateurs* currentUser = it->first;
        if (currentUser->getId() == user->getId() ) {
            it->second = false;
            break;
        }
    }
}

string UserBase::getUserType(Utilisateurs* user) {
    string userType = " ";
    if(typeid(*user) == typeid(GouvernmentalAgency)) {
        userType = "gouvernmentalAgency";
    }
    else if(typeid(*user) == typeid(Individual)) {
        userType = "individual";
    }
    else if(typeid(*user) == typeid(Entreprise)) {
        userType = "entreprise";
    }
    return userType;
}