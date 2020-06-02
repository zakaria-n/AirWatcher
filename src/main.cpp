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
#include "SimpleInterface.h"

int main() {
    string measureFile = "../dataset/measurements.csv";
    string sensorFile = "../dataset/sensors.csv";
    string cleanerFile = "../dataset/cleaners.csv";
    Catalogue cat = Catalogue(measureFile, sensorFile, cleanerFile);
    
    
    //vector<Sensor> sensorLz = cat.getSensorList();
    /*for (auto it=sensorLz.begin(); it!= sensorLz.end(); it++)
    {
        cout << *it << endl;
    }*/
    /*
    list<Measure> measureL = cat.getMeasureList();
    Area arz = Area(44.0,0.3, 170,sensorLz,measureL);
    //arz.fillSensors(sensorLz, measureL);
    cout << "Sensors in this area:" << endl;
    arz.displaySensors();
    cout << "Measures for this area: " << endl;
    arz.displayAreaMeasures();
    cout << "Average air quality in this area: " << endl;
    cout << arz.avgQualityOverPeriod("2019-02-09","2019-03-09");


    Sensor s = sensorLz.back();

    s.fillMeasures(measureL);
    cout << "The measures recorded by this sensor are: " << endl;
    s.displayMeasures();

    cout << "For this sensor: " << s << " the average quality is: " << endl;
    cout << s.airQuality(measureL) << endl;
    cout << "-----------------sopi-----------" << endl;

    */ 
    /*vector<Sensor> sensorL = cat.getSensorList();
    for (auto it=sensorL.begin(); it!= sensorL.end(); it++)
    {
        cout << *it << endl;
    }*/
    list<Measure> measureList = cat.getMeasureList();
    Area ar = Area();
    SimpleInterface users = SimpleInterface();
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
                    printf("Enter your username:\n");
                    cin >> username;
                    printf("Enter your password:\n");
                    cin >> password;
                    Utilisateurs* user = users.authenticate(username, password);
                    if(user==NULL) {
                        printf("Authentication failed:\n");
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
                                                float lat,longi,radius;
                                                string dateBegin;
                                                string dateEnd;
                                                printf("Enter latitude:\n");
                                                cin >> lat;
                                                printf("Enter longitude:\n");
                                                cin >> longi;
                                                printf("Enter radius:\n");
                                                cin >> radius;
                                                printf("Enter Begin date: (YYYY-MM-DD)\n");
                                                cin >> dateBegin;
                                                printf("Enter End date: (YYYY-MM-DD)\n");
                                                cin >> dateEnd;
                                                float avgQua = cat.getAverageQuality(lat,longi,radius,dateBegin, dateEnd);
                                                printf("The average air quality in your area : %f\n",avgQua );
                                                break;
                                            }
                                            case 2: {  //TESTER L'AFFICHAGE
                                                float lat,longi;
                                                string id, description;
                                                printf("Enter id:\n");
                                                cin >> id;
                                                printf("Enter latitude:\n");
                                                cin >> lat;
                                                printf("Enter longitude:\n");
                                                cin >> longi;
                                                printf("Enter description:\n");
                                                cin >> description;
                                                cat.addSensor(id,lat,longi, description);
                                                printf("Sensor has been added.\n");
                                                break;
                                            }
                                            case 3: {
                                                users.deconnexion(user);
                                                loggedIn = false;
                                                break;
                                            }
                                            default: {
                                                printf("Invalid input\n");
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
                                                printf("Enter id:\n");
                                                cin >> id;
                                                printf("Enter latitude:\n");
                                                cin >> lat;
                                                printf("Enter longitude:\n");
                                                cin >> longi;
                                                printf("Enter begin timestamp:\n");
                                                cin>>begin;
                                                printf("Enter end timestamp:\n");
                                                cin >> end;
                                                cat.addCleaner(id,lat,longi, begin, end);
                                                printf("Cleaner has been added.\n");
                                                break;
                                            }
                                            case 3: {
                                              Cleaner unCleaner;
                                              string CleanerId;
                                              float purifiedRadius, purifiedZone;
                                              printf("Enter cleaner iD:\n");
                                              cin >> CleanerId;
                                              unCleaner = cat.GetCleanerById(CleanerId);
                                              purifiedRadius = unCleaner.calculatePurifiedZone(&cat);
                                              purifiedZone = PI*pow(purifiedRadius,2);
                                              //purifiedZone = purifiedRadius;
                                              printf("Here is the surface of the purified zone : %f\n",purifiedZone);

                                                break;
                                            }
                                            case 4: {

                                                break;
                                            }
                                            case 5: {
                                                break;
                                            }
                                            case 6: {
                                                users.deconnexion(user);
                                                loggedIn = false;
                                                break;
                                            }
                                            default: {
                                                printf("Invalid input\n");
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
                                                printf("What is your measure type ? O3,SO2,NO2,PM10 ? \n" );
                                                cin>>attributeId;
                                                printf("What is the date today? (YYYY-MM-DD) \n" );
                                                cin>>ts;
                                                printf("The value ? \n");
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
                                                printf("Invalid input\n");
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
                    printf("Are you an 'individual' or 'entreprise'?:\n");
                    getline(cin, userType);
                    if(userType=="individual") {
                        string id, password;
                        printf("Enter your username:\n");
                        getline(cin, id);
                        printf("Enter your password:\n");
                        getline(cin, password);
                        Individual* newUser = new Individual(id, password, 0, 0);
                        users.addUser(newUser);
                        printf("You have successfully signed up as an individual!:\n");
                    }
                    else if(userType=="entreprise") {
                        string id, password;
                        printf("Enter your username:\n");
                        getline(cin, id);
                        printf("Enter your password:\n");
                        getline(cin, password);
                        vector<Cleaner> cleaners;
                        Entreprise* newUser = new Entreprise(id, password, cleaners);
                        users.addUser(newUser);
                        printf("You have successfully signed up as an entreprise!:\n");
                    }
                    else {
                        printf("Sorry, that is not a valid user type:\n");
                    }
                    break;
                }
                case 3: {
                    exit = true;
                    break;
                }
                default: {
                    printf("Invalid input\n");
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
