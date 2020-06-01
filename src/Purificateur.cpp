#include <iostream>

using namespace std;

#include "Purificateur.h"
#include "Catalogue.h"

Purificateur::Purificateur ( const Purificateur & unPurificateur )
{
#ifdef MAP
   cout << "Appel au constructeur de copie de <Purificateur>" << endl;
#endif
    latitude = unPurificateur.latitude;
    longitude = unPurificateur.longitude;
    timestampBegin = unPurificateur.timestampBegin;
    timestampEnd = unPurificateur.timestampEnd;
} 

Purificateur::Purificateur()
{
#ifdef MAP
    cout << "Appel au constructeur de <Purificateur>" << endl;
#endif
} 

Purificateur::Purificateur(string idInput, float latitudeInput, float longitudeInput, string begin, string end)
{
#ifdef MAP
    cout << "Appel au constructeur de <Purificateur>" << endl;
#endif
    id = idInput;
    latitude = latitudeInput;
    longitude = longitudeInput;
    timestampBegin = begin.substr(0,10);
    timestampEnd = end.substr(0,10);
}

Purificateur::~Purificateur ( )
{
#ifdef MAP
    cout << "Appel au destructeur de <Purificateur>" << endl;
#endif
} 

string Purificateur::GetId() const {
    return id;
}

float Purificateur::GetLatitude() const {
    return latitude;
}

float Purificateur::GetLongitude() const {
    return longitude;
}

string Purificateur::GetTimestampBegin() const {
    return timestampBegin;
}

string Purificateur::GetTimestampEnd() const {
    return timestampEnd;
}

// difference in air quality before vs after cleaner added
int Purificateur::calculateEfficiency(Catalogue* cat, float rayon) const {
    int before = cat->getAverageQuality(latitude, longitude, rayon, timestampBegin); 
    int after = cat->getAverageQuality(latitude, longitude, rayon, timestampEnd); 
    int result = after - before;
    return result;
}

// appeler la méthode getAverageQuality de 'Catalogue'
int Purificateur::calculateAirQuality(Catalogue* cat, float rayon) const {
    int quality = cat->getAverageQuality(latitude, longitude, rayon, timestampBegin, timestampEnd);
    return quality;
}

// area that has improved after cleaner added
float Purificateur::calculatePurifiedZone(Catalogue* cat) const {
    int minimalChange = 1;
    float purifiedRadius = 0;
    float currentRayon = 5;
    int efficiency = calculateEfficiency(cat, currentRayon);
    while ( efficiency > minimalChange) {
        purifiedRadius = currentRayon;
        currentRayon+=5;
        efficiency = calculateEfficiency(cat, currentRayon);
    }
    return purifiedRadius;
}

bool Purificateur::operator==(Purificateur const& a) const {
    bool place = ((latitude==a.GetLatitude()) && (longitude==a.GetLongitude()));
    bool time = ((timestampBegin==a.GetTimestampBegin()) && (timestampEnd==a.GetTimestampEnd()));
    return (place && time);    
}