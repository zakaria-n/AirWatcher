
#if ! defined ( PURIFICATEUR_H )
#define PURIFICATEUR_H

#include <ctime>


class Purificateur 
{

public:

    Purificateur ( const Purificateur & unPurificateur );
    Purificateur();
    ~Purificateur ( );

    float GetLatitude() const;
    float GetLongitude() const;   
    time_t GetTimestampBegin() const;
    time_t GetTimestampEnd() const;

    int calculateEfficiency() const;
    int* calculateAirQuality() const;
    int* calculatePurifiedZone() const;

protected:

    float latitude;
    float longitude;
    time_t timestampBegin;
    time_t timestampEnd;

};

#endif // PURIFICATEUR_H
