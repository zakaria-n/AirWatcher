#include <iostream>

using namespace std;

#include "Cleaner.h"
#include "Catalogue.h"

Cleaner::Cleaner ( const Cleaner & unCleaner )
{
#ifdef MAP
   cout << "Appel au constructeur de copie de <Cleaner>" << endl;
#endif
    id = unCleaner.id;
    latitude = unCleaner.latitude;
    longitude = unCleaner.longitude;
    timestampBegin = unCleaner.timestampBegin;
    timestampEnd = unCleaner.timestampEnd;
}

Cleaner::Cleaner()
{
#ifdef MAP
    cout << "Appel au constructeur de <Cleaner>" << endl;
#endif
}

Cleaner::Cleaner(string idInput, float latitudeInput, float longitudeInput, string begin, string end)
{
#ifdef MAP
    cout << "Appel au constructeur de <Cleaner>" << endl;
#endif
    id = idInput;
    latitude = latitudeInput;
    longitude = longitudeInput;
    timestampBegin = begin.substr(0,10);
    timestampEnd = end.substr(0,10);
}

Cleaner::~Cleaner ( )
{
#ifdef MAP
    cout << "Appel au destructeur de <Cleaner>" << endl;
#endif
}



string Cleaner::GetId() const {
    return id;
}

float Cleaner::GetLatitude() const {
    return latitude;
}

float Cleaner::GetLongitude() const {
    return longitude;
}

string Cleaner::GetTimestampBegin() const {
    return timestampBegin;
}

string Cleaner::GetTimestampEnd() const {
    return timestampEnd;
}

// difference in air quality before vs after cleaner added
int Cleaner::calculateEfficiency(Catalogue* cat, float rayon) const {
    int before = cat->getAverageQuality(latitude, longitude, rayon, timestampBegin);
    int after = cat->getAverageQuality(latitude, longitude, rayon, timestampEnd);
    int result = after - before;
    return result;
}

// appeler la méthode getAverageQuality de 'Catalogue'
int Cleaner::calculateAirQuality(Catalogue* cat, float rayon) const {
    int quality = cat->getAverageQuality(latitude, longitude, rayon, timestampBegin, timestampEnd);
    return quality;
}

// area that has improved after cleaner added
float Cleaner::calculatePurifiedZone(Catalogue* cat) const {
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

bool Cleaner::operator==(Cleaner const& a) const {
    bool place = ((latitude==a.GetLatitude()) && (longitude==a.GetLongitude()));
    bool time = ((timestampBegin==a.GetTimestampBegin()) && (timestampEnd==a.GetTimestampEnd()));
    return (place && time);
}
