
#if ! defined ( PURIFICATEUR_H )
#define PURIFICATEUR_H

#include <ctime>
#include <string>

using namespace std;

class Purificateur 
{

public:

    Purificateur ( const Purificateur & unPurificateur );
    Purificateur();
    Purificateur (string id, float latitude, float longitude, string begin, string end);
    virtual ~Purificateur ( );

    float GetLatitude() const;
    float GetLongitude() const;   
    time_t GetTimestampBegin() const;
    time_t GetTimestampEnd() const;

    int calculateEfficiency(float rayon) const;
    int calculateAirQuality(float rayon) const;
    float calculatePurifiedZone() const;

    bool operator==(Purificateur const&) const;

protected:

    string id;
    float latitude;
    float longitude;
    time_t timestampBegin;
    time_t timestampEnd;

    time_t processTimestampString(string time) const;

};

#endif // PURIFICATEUR_H
