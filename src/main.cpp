#include <iostream>
#include <fstream>
#include <string>

#define PI 3.141592

using namespace std;

#include "Measure.h"
#include "Utilisateurs.h"
#include "Entreprise.h"
#include "GouvernmentalAgency.h"
#include "Individual.h"
#include "Area.h"
#include "Catalogue.h"
#include "Sensor.h"
#include "Cleaner.h"
#include "UserBase.h"

int main() {
    string measureFile = "../dataset/measurements.csv";
    string sensorFile = "../dataset/sensors.csv";
    string cleanerFile = "../dataset/cleaners.csv";
    Catalogue cat = Catalogue(measureFile, sensorFile, cleanerFile);
    
    list<Measure> measureList = cat.getMeasureList();
    Area ar = Area();
    UserBase users = UserBase();
    GouvernmentalAgency* government = new GouvernmentalAgency("one", "111");
    vector <Cleaner> cleaners = cat.getCleanerList();
    Entreprise* entre = new Entreprise("two", "222",  cleaners);
    Individual* indiv = new Individual("three", "333",3,2);
    users.addUser(government);
    users.addUser(entre);
    users.addUser(indiv);

    bool exit = false;
    int choice;
    while(!exit) {
        cout << "       Welcome to Sensor Inc." << endl << "What would you like to do?" << endl;
        cout << "================= MENU =================" << endl;
        cout << "1: Enter 1 to log in." << endl;
        cout << "2: Enter 2 to sign up. " << endl;
        cout << "5: Enter 3 to exit." << endl;
        if(cin >> choice) {
            switch(choice) {
                case 1: {
                    string username;
                    string password;
                    cout << "Enter your username:" << endl;
                    cin >> username;
                    cout << "Enter your password:" << endl;
                    cin >> password;
                    Utilisateurs* user = users.authenticate(username, password);
                    if(user==NULL) {
                    cout << "Authentication failed" << endl;
                    }
                    else {
                        cout << "Welcome, you have logged in!" << endl;
                        bool loggedIn = true;
                        string userType = users.getUserType(user);
                            while(loggedIn) {
                                if(userType=="gouvernmentalAgency") {
                                    cout << "================= AGENCY MENU =================" << endl;
                                    cout << "1: Enter 1 to get average quality for an area." << endl;
                                    cout << "2: Enter 2 to add new sensor. " << endl;
                                    cout << "3: Enter 3 to log out." << endl;
                                    if(cin >> choice) {
                                        switch(choice) {
                                            case 1: { //  NE FONCTIONNE PAS
                                                float lat,longi;
                                                int radius;
                                                string dateBegin;
                                                string dateEnd;
                                                cout << "Enter latitude:" << endl;
                                                cin >> lat;
                                                cout << "Enter longitude:" << endl;
                                                cin >> longi;
                                                cout << "Enter radius" << endl;
                                                cin >> radius;
                                                cout << "Enter Begin date: (YYYY-MM-DD):" << endl;
                                                cin >> dateBegin;
                                                cout << "Enter End date: (YYYY-MM-DD):" << endl;
                                                cin >> dateEnd;
                                                float avgQua = cat.getAverageQuality(lat,longi,radius,dateBegin, dateEnd);
                                                printf("The average air quality in your area : %f\n",avgQua );
                                                break;
                                            }
                                            case 2: {  //TESTER L'AFFICHAGE
                                                float lat,longi;
                                                string id, description;
                                                cout << "Enter id" << endl;
                                                cin >> id;
                                                cout << "Enter latitude" << endl;
                                                cin >> lat;
                                                cout << "Enter longitude" << endl;
                                                cin >> longi;
                                                cout << "Enter description" << endl;
                                                cin >> description;
                                                cat.addSensor(id,lat,longi, description);
                                                cout << "Sensor has been added" << endl;
                                                break;
                                            }
                                            case 3: {
                                                users.deconnexion(user);
                                                loggedIn = false;
                                                break;
                                            }
                                            default: {
                                                cout << "Invalid input" << endl;
                                                break;
                                            }
                                        }
                                    }
                                }
                                else if(userType=="entreprise") {
                                    cout << "================= ENTREPRISE MENU =================" << endl;
                                    cout << "1: Enter 1 to get list of cleaners." << endl;
                                    cout << "2: Enter 2 to add cleaner. " << endl;
                                    cout << "3: Enter 3 to get impact on air quality index of cleaner. " << endl;
                                    cout << "4: Enter 4 to get air quality of cleaner area. " << endl;
                                    cout << "5: Enter 5 to get calculate purified zone of cleaner. " << endl;
                                    cout << "6: Enter 6 to log out." << endl;
                                    if(cin >> choice) {
                                        switch(choice) {
                                            case 1: {
                                                vector<Cleaner> cleaners = cat.getCleanerList();
                                                for (auto it=cleaners.begin(); it!=cleaners.end(); it++)
                                                {
                                                  string id = it->GetId();
                                                    cout <<"Cleaner ID :"<< id << endl; //NE S'AFFICHE PAS
                                                }
                                                break;
                                            }
                                            case 2: {
                                                float lat,longi;
                                                string id, begin, end;
                                                cout << "Enter id" << endl;
                                                cin >> id;
                                                cout << "Enter latitude" << endl;
                                                cin >> lat;
                                                cout << "Enter longitude" << endl;
                                                cin >> longi;
                                                cout << "Enter begin timestamp" << endl;
                                                cin>>begin;
                                                cout << "Enter end timestamp" << endl;
                                                cin >> end;
                                                Cleaner newCleaner = Cleaner(id, lat, longi, begin, end);
                                                cat.addCleaner(newCleaner);
                                                cout << "Cleaner has been added" << endl;
                                                break;
                                            }
                                            case 3: {
                                              string CleanerId;
                                              Cleaner unCleaner;
                                              float efficiency;
                                              int rad;
                                              cout << "Enter cleaner ID" << endl;
                                              cin >> CleanerId;
                                              cout << "Enter radius " << endl;
                                              cin >> rad;
                                              unCleaner = cat.GetCleanerById(CleanerId);
                                              efficiency = unCleaner.calculateEfficiency(&cat,rad);
                                              cout<<"Here is the efficiency of the cleaner ... : "<<efficiency<<endl;
                                              break;
                                            }
                                            case 4: {
                                              string CleanerId;
                                              int qua;
                                              int rad;
                                              cout << "Enter cleaner ID" << endl;
                                              cin >> CleanerId;
                                              cout << "Enter radius " << endl;
                                              cin >> rad;
                                              Cleaner unCleaner = cat.GetCleanerById(CleanerId);
                                              qua = unCleaner.calculateAirQuality(&cat,rad);

                                              cout<<"Here is the air quality of the cleaner ... area  : "<<qua<<endl;

                                                break;
                                            }
                                            case 5: {
                                              string CleanerId;
                                              Cleaner unCleaner;
                                              int purifiedRadius, purifiedZone;
                                              cout << "Enter cleaner id" << endl;
                                              cin >> CleanerId;
                                              //unCleaner = cat.GetCleanerById(CleanerId);
                                              //purifiedRadius = unCleaner.calculatePurifiedZone(&cat);
                                              unCleaner = cat.GetCleanerById(CleanerId);
                                              purifiedRadius = unCleaner.calculatePurifiedZone(&cat);
                                              purifiedZone = PI*pow(purifiedRadius,2);
                                              cout<< "Radius of the purified zone : " << purifiedRadius << endl;
                                              cout<< "Srface of the purified zone : " << purifiedZone << endl;

                                                break;
                                            }
                                            case 6: {
                                                users.deconnexion(user);
                                                loggedIn = false;
                                                break;
                                            }
                                            default: {
                                                cout << "Invalid input" << endl;
                                                break;
                                            }
                                        }
                                    }
                                }
                                else {//AJOUTER DES POINTS A CHAQUE NOUVELLE MEASURE
                                    cout << "================= INDIVIDUAL MENU =================" << endl;
                                    cout << "1: Enter 1 to submit new measure." << endl;
                                    cout << "2: Enter 2 to get your current points. " << endl;
                                    cout << "3: Enter 3 to log out." << endl;
                                    Individual* indiv = (Individual*) user;
                                    if(cin >> choice) {
                                        switch(choice) {
                                            case 1: {
                                                string attributeId, ts;
                                                float value;
                                                cout << "What is your measure type ? O3,SO2,NO2,PM10 ?" << endl;
                                                cin>>attributeId;
                                                cout << "What is the date today? (YYYY-MM-DD)" << endl;
                                                cin>>ts;
                                                cout << "The value?" << endl;
                                                cin>>value;
                                                Measure maMeasure =  Measure (ts,indiv->getId(), attributeId, value, false);
                                                cat.addMeasure(maMeasure);
                                                break;
                                            }
                                            case 2: {
                                                cout << "Points: " << indiv->getPoints()<<"\n";
                                                break;
                                            }
                                            case 3: {
                                                users.deconnexion(user);
                                                loggedIn = false;
                                                break;
                                            }
                                            default: {
                                                cout << "Invalid input" << endl;
                                                break;
                                            }
                                        }
                                    }
                                }
                            }
                    }
                    break;
                }
                case 2: {
                    cin.ignore();
		            string userType;
                    cout << "Are you an 'individual' or 'entreprise'?:" << endl;
                    getline(cin, userType);
                    if(userType=="individual") {
                        string id, password;
                        cout << "Enter your username" << endl;
                        getline(cin, id);
                        cout << "Enter your password" << endl;
                        getline(cin, password);
                        Individual* newUser = new Individual(id, password, 0, 0);
                        users.addUser(newUser);
                        cout << "You have successfully signed up as an individual!" << endl;
                    }
                    else if(userType=="entreprise") {
                        string id, password;
                        cout << "Enter your username" << endl;
                        getline(cin, id);
                        cout << "Enter your password" << endl;
                        getline(cin, password);
                        vector<Cleaner> cleaners;
                        Entreprise* newUser = new Entreprise(id, password, cleaners);
                        users.addUser(newUser);
                        cout << "You have successfully signed up as an entreprise!" << endl;
                    }
                    else {
                        cout << "Sorry, that is not a valid user type" << endl;
                    }
                    break;
                }
                case 3: {
                    exit = true;
                    break;
                }
                default: {
                    cout << "Invalid input" << endl;
                    break;
                }
            }
        }
        else {
            cout << "Invalid input" << endl;
            cin.clear();
            cin.ignore(80,'\n');
        }
    }
}
