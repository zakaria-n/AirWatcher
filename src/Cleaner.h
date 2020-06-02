
#if ! defined ( Cleaner_H )
#define Cleaner_H

#include <ctime>
#include <string>

using namespace std;

class Catalogue;

class Cleaner 
{

public:

    Cleaner ( const Cleaner & unCleaner );
    Cleaner();
    Cleaner (string id, float latitude, float longitude, string begin, string end);
    virtual ~Cleaner ( );

    string GetId() const;
    float GetLatitude() const;
    float GetLongitude() const;
    string GetTimestampBegin() const;
    string GetTimestampEnd() const;

    float calculateEfficiency(Catalogue *cat, int rayon) const;
    float calculateAirQuality(Catalogue* cat, int rayon) const;
    float calculatePurifiedZone(Catalogue* cat) const;

    bool operator==(Cleaner const&) const;

protected:

    string id;
    float latitude;
    float longitude;
    string timestampBegin;
    string timestampEnd;

};

#endif // Cleaner_H
