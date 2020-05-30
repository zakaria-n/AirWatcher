#include <iostream>
#include <fstream>
#include <string>

using namespace std;

#include "Measure.h"
#include "Utilisateurs.h"
#include "Entreprise.h"
#include "GouvernmentalAgency.h"
#include "Individual.h"
#include "Area.h"
#include "Catalogue.h"
#include "Sensor.h"
#include "Purificateur.h"
#include "SimpleInterface.h"

int main() {
    string measureFile = "../dataset/measurements.csv";
    string sensorFile = "../dataset/sensors.csv";
    string cleanerFile = "../dataset/cleaners.csv";
    Catalogue cat = Catalogue(measureFile, sensorFile, cleanerFile);

    vector<Utilisateurs*> users;
    GouvernmentalAgency* government = new GouvernmentalAgency("one", "111");
    vector<Purificateur> cleaners;
    Entreprise* entre = new Entreprise("two", "222",  cleaners);
    Individual* indiv = new Individual("three", "333");
    users.push_back(government);
    users.push_back(entre);
    users.push_back(indiv);
    
    bool exit = false;
    int choice;
    while(!exit) {
        cout << "       Welcome to Sensor Inc." << endl << "What would you like to do?" << endl;
        cout << "================= MENU =================" << endl;
        cout << "1: Enter 1 to log in." << endl;
        cout << "2: Enter 2 to bla bla. " << endl;
        cout << "3: Enter 3 to bla bla." << endl;
        cout << "4: Enter 4 to bla bla." << endl;
        cout << "5: Enter 5 to exit." << endl;
        if(cin >> choice) {
            switch(choice) {
                case 1: {
                    string username;
                    string password;
                    printf("Enter your username:\n");
                    cin >> username;
                    printf("Enter your password:\n");
                    cin >> password;
                    break;
                }
                case 2: {
                    cin.ignore();
		            string a;
                    string b;
                    printf("Enter a:\n");
                    getline(cin, a);
                    printf("Enter b:\n");
                    getline(cin, b);
                    break;
                }
                case 3: {
                    break;
                }
                case 4: {
                    break;
                }
                case 5: {
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