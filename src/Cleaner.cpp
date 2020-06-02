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
float Cleaner::calculateEfficiency(Catalogue* cat, int rayon) const {
    float before = cat->getAverageQuality(latitude, longitude, rayon, "2019-01-01", timestampBegin);
    float after = cat->getAverageQuality(latitude, longitude, rayon, timestampBegin, timestampEnd);
    float result = after - before;
    return result;
}

// appeler la méthode getAverageQuality de 'Catalogue'
float Cleaner::calculateAirQuality(Catalogue* cat, int rayon) const {
    float quality = cat->getAverageQuality(latitude, longitude, rayon, timestampBegin, timestampEnd);
    return quality;
}

// area that has improved after cleaner added
float Cleaner::calculatePurifiedZone(Catalogue* cat) const {
    float minimalChange = -0.5;
    int purifiedRadius = 0;
    int currentRayon = 110;
    float efficiency = calculateEfficiency(cat, currentRayon);
    while ( efficiency <= minimalChange && currentRayon < 400) {
        cout << efficiency << endl;
        purifiedRadius = currentRayon;
        currentRayon+=10;
        efficiency = calculateEfficiency(cat, currentRayon);
    }
    return purifiedRadius;
}

bool Cleaner::operator==(Cleaner const& a) const {
    bool place = ((latitude==a.GetLatitude()) && (longitude==a.GetLongitude()));
    bool time = ((timestampBegin==a.GetTimestampBegin()) && (timestampEnd==a.GetTimestampEnd()));
    return (place && time);
}
