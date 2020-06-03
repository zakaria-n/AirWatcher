#include <iostream>
#include <fstream>
#include <string>
#include <chrono> 
#include <assert.h>

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

int main(int argc, char** argv) {
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
    Individual* indiv = new Individual("three", "333",3,2, "Sensor70");
    Individual* indiv2 = new Individual("four", "444",3,3, "Sensor36");
    users.addUser(government);
    users.addUser(entre);
    users.addUser(indiv);
    users.addUser(indiv2);
    
    // Tests from CLI arguments
    
    if (argc >1)
    {
        switch(stoi(argv[1]))
        {
            case 1: // displaying sensors
            {
                cout << "Sensors:" << endl;
                vector<Sensor> sensors = cat.getSensorList();
                for(int i=0; i < sensors.size(); i++) {
                    cout << sensors.at(i) << endl;
                } 
            }
            break;

            case 2: // testing air quality
            {
                Area ar = Area(stoi(argv[2]), stoi(argv[3]), stoi(argv[4]), cat.getSensorList());
                cout << "Average air quality in this area: " << endl;
                cout << ar.avgQualityOverPeriod(argv[5],argv[6]) << endl;
            }
            break;

            case 3: // testing sensor cluster
            {
                cout << "Cluster of " << argv[2] << endl;
                Sensor s = cat.GetSensorById(argv[2]);
                s.displayCluster(cat.getSensorList());
            }
            break;

            case 4: // testing cleaner impact
            {
                Cleaner unCleaner;
                float efficiency;
                unCleaner = cat.GetCleanerById(argv[2]);
                efficiency = unCleaner.calculateEfficiency(&cat,stoi(argv[3]));
                cout<<"Here is the efficiency of the cleaner ... : "<<efficiency<<endl;
            }
            break;

            case 5: // testing purified radius
            {
                string CleanerId;
                Cleaner unCleaner;
                int purifiedRadius, purifiedZone;
                unCleaner = cat.GetCleanerById(argv[2]);
                purifiedRadius = unCleaner.calculatePurifiedZone(&cat);
                purifiedZone = PI*pow(purifiedRadius,2);
                cout<< "Radius of the purified zone : " << purifiedRadius << endl;
            }
            break;
            
            
        }
    }
   
    // If no argument, display UI to let user interact more intuitively with app

    bool exit = true;
    if(argc==1)
    {
        exit = false;
    }

    int choice;
    while(!exit) {
        cout << "       Welcome to Sensor Inc." << endl << "What would you like to do?" << endl;
        cout << "================= MENU =================" << endl;
        cout << "1: Enter 1 to log in." << endl;
        cout << "2: Enter 2 to sign up. " << endl;
        cout << "3: Enter 3 to exit." << endl;
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
                                    cout << "3: Enter 3 to display sensors. " << endl;
                                    cout << "4: Enter 4 to display cluster of a sensor. " << endl;
                                    cout << "5: Enter 5 to log out." << endl;
                                    if(cin >> choice) {
                                        switch(choice) {
                                            case 1: {
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
                                                auto start = chrono::high_resolution_clock::now();
                                                float avgQua = cat.getAverageQuality(lat,longi,radius,dateBegin, dateEnd);
                                                auto stop = chrono::high_resolution_clock::now(); 
                                                auto duration = std::chrono::duration_cast<chrono::milliseconds>(stop - start);
                                                printf("The average air quality in your area : %f\n",avgQua );
                                                cout << "Elapsed time: " << duration.count() << " milliseconds" << endl;
                                                break;
                                            }
                                            case 2: {
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
                                                cout << "Sensors:" << endl;
                                                vector<Sensor> sensors = cat.getSensorList();
                                                for(int i=0; i < sensors.size(); i++) {
                                                    cout << sensors.at(i) << endl;
                                                }
                                                break;
                                            }
                                            case 4: {
                                                cout << "Enter sensor ID..." << endl;
                                                string id;
                                                cin >> id;
                                                Sensor s = cat.GetSensorById(id);
                                                s.displayCluster(cat.getSensorList());
                                            }
                                            case 5: {
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
                                                    cout <<"Cleaner ID: "<< id << endl; //NE S'AFFICHE PAS
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
                                              cout<<"Here is the efficiency of the cleaner: "<<efficiency<<endl;
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

                                                cout<<"Here is the air quality of the cleaner: "<<qua<<endl;

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
                                                auto start = chrono::high_resolution_clock::now();
                                                purifiedRadius = unCleaner.calculatePurifiedZone(&cat);
                                                auto stop = chrono::high_resolution_clock::now(); 
                                                auto duration = std::chrono::duration_cast<chrono::milliseconds>(stop - start);
                                                purifiedZone = PI*pow(purifiedRadius,2);
                                                cout<< "Radius of the purified zone : " << purifiedRadius << endl;
                                                cout<< "Srface of the purified zone : " << purifiedZone << endl;
                                                cout << "Elapsed time: " << duration.count() << " milliseconds" << endl;

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
                                                string value;
                                                cout << "What is your measure type ? O3,SO2,NO2,PM10 ?" << endl;
                                                cin>>attributeId;
                                                cout << "What is the date today? (YYYY-MM-DD)" << endl;
                                                cin>>ts;
                                                cout << "The value?" << endl;
                                                cin>>value;
                                                if(value.find_first_not_of("1234567890.-") != string::npos)
                                                {
                                                    cout << "Invalid input. " << endl;
                                                    break;
                                                }
                                                Measure maMeasure =  Measure (ts,indiv->getId(), attributeId, stof(value), false);
                                                if(cat.addIndivMeasure(maMeasure,indiv->getId())){
                                                    indiv->addPoint();
                                                    cout << "good data! ";
                                                    cout << "Measure has been added and you have gained a point!" << endl;
                                                } else {
                                                    indiv->addTotalMeasures();
                                                    cout << "bad data!" << endl;
                                                }
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
                        string sensorId = "Sensor";
                        float latitude, longitude;
                        string desc;
                        int nbSensors = cat.getSensorList().size();
                        cout << "Enter latitude" << endl;
                        cin >> latitude;
                        cout << "Enter longitude" << endl;
                        cin >> longitude;
                        cout << "Enter description" << endl;
                        cin >> desc;
                        sensorId += nbSensors;
                        list<Measure> measures;
                        Sensor newIndivSensor = Sensor(sensorId, latitude, longitude, desc, measures);
                        cat.addSensor(newIndivSensor);
                        Individual* newUser = new Individual(id, password, 0, 0, sensorId);
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
