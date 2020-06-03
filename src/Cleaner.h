
#if ! defined ( Cleaner_H )
#define Cleaner_H

#include <ctime>
#include <string>

using namespace std;

class Catalogue;

class Cleaner 
{

public:

    // Constructors - Destructor
    Cleaner ( const Cleaner & unCleaner );
    Cleaner();
    Cleaner (string id, float latitude, float longitude, string begin, string end);
    virtual ~Cleaner ( );
    
    // Getters
    string GetId() const;
    float GetLatitude() const;
    float GetLongitude() const;
    string GetTimestampBegin() const;
    string GetTimestampEnd() const;

    // Algorithm that outputs the difference in air quality before vs after cleaner added
    float calculateEfficiency(Catalogue *cat, int rayon) const;
    // Calls quality calculator from Catalogue to compute air quality around cleaner
    float calculateAirQuality(Catalogue* cat, int rayon) const;
    // Algorithm to compute area that has improved after cleaner added
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
