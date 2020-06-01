
#if ! defined ( PURIFICATEUR_H )
#define PURIFICATEUR_H

#include <ctime>
#include <string>

using namespace std;

class Catalogue;

class Purificateur 
{

public:

    Purificateur ( const Purificateur & unPurificateur );
    Purificateur();
    Purificateur (string id, float latitude, float longitude, string begin, string end);
    virtual ~Purificateur ( );

    string GetId() const;
    float GetLatitude() const;
    float GetLongitude() const;   
    string GetTimestampBegin() const;
    string GetTimestampEnd() const;

    int calculateEfficiency(Catalogue *cat, float rayon) const;
    int calculateAirQuality(Catalogue* cat, float rayon) const;
    float calculatePurifiedZone(Catalogue* cat) const;

    bool operator==(Purificateur const&) const;

protected:

    string id;
    float latitude;
    float longitude;
    string timestampBegin;
    string timestampEnd;

};

#endif // PURIFICATEUR_H
