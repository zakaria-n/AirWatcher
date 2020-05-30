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
    timestampBegin = processTimestampString(begin);
    timestampEnd = processTimestampString(end);   
}

time_t Purificateur::processTimestampString(string time) const {
    int year, month, day, hour, minute, second;
    const char *zStart = time.c_str();
    sscanf(zStart, "%d-%d-%d %d:%d:%d", &year, &month, &day, &hour, &minute, &second);
    struct tm timeStruct;
    timeStruct.tm_year = year - 1900;
    timeStruct.tm_mon = month - 1;
    timeStruct.tm_mday = day;
    timeStruct.tm_hour = hour;
    timeStruct.tm_min = minute;
    timeStruct.tm_sec = second;
    timeStruct.tm_isdst = -1;
    time_t result = mktime(&timeStruct);
    return result;

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

time_t Purificateur::GetTimestampBegin() const {
    return timestampBegin;
}

time_t Purificateur::GetTimestampEnd() const {
    return timestampEnd;
}

// difference in air quality before vs after cleaner added
int Purificateur::calculateEfficiency(Catalogue* cat, float rayon) const {
    int before = cat->getAverageQuality(latitude, longitude, rayon, "begin", "default-end"); // timestampBegin
    int after = cat->getAverageQuality(latitude, longitude, rayon, "begin", "default-end"); // timestampEnd
    int result = after - before;
    return result;
}

// appeler la méthode getAverageQuality de 'Catalogue'
int Purificateur::calculateAirQuality(Catalogue* cat, float rayon) const {
    int quality = cat->getAverageQuality(latitude, longitude, rayon, "timestampBegin", "timestampEnd");
    return quality;
}

// area that has improved after cleaner added
float Purificateur::calculatePurifiedZone(Catalogue* cat) const {
    int minimalChange = 1;
    float currentRayon = 1.0;
    int efficiency = calculateEfficiency(cat, currentRayon);
    while ( efficiency > minimalChange) {
        currentRayon+=0.5;
        efficiency = calculateEfficiency(cat, currentRayon);
    }
    return currentRayon;
}

bool Purificateur::operator==(Purificateur const& a) const {
    bool place = ((latitude==a.GetLatitude()) && (longitude==a.GetLongitude()));
    bool time = ((timestampBegin==a.GetTimestampBegin()) && (timestampEnd==a.GetTimestampEnd()));
    return (place && time);    
}