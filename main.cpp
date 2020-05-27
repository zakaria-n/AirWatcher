#include <iostream>
#include <fstream>
#include <string>

using namespace std;

#include "Measure.h"
#include "Utilisateurs.h"
#include "Entreprise.h"
#include "GouvernmentalAgency.h"
#include "Individual.h"
#include "Sensor.h"
#include "Purificateur.h"
#include "SimpleInterface.h"
#include "Catalogue.h"

int main() {
    string measureFile = "dataset/measurements.csv";
    string sensorFile = "dataset/sensors.csv";
    string cleanerFile = "dataset/cleaners.csv";
    Catalogue cat = Catalogue(measureFile, sensorFile, cleanerFile);
    list<Sensor> sensors = cat.getSensorList();
    for (list<Sensor>::iterator it = sensors.begin(); it != sensors.end(); ++it){
        cout << it->getId() << endl;;
    }

}