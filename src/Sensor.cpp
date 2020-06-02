#include <iostream>
#include <cmath> 
#include "Sensor.h"

using namespace std;

vector<float> Sensor::avgMeasures(list<Measure> mesures)
{
	list<Measure>::iterator it;
	vector<float> avg(4);
	float O3total = 0.0, NO2total = 0.0, SO2total = 0.0, PM10total = 0.0;
	float O3counter = 0.0, NO2counter = 0.0, SO2counter = 0.0, PM10counter = 0.0;
	for (it = mesures.begin(); it != mesures.end(); ++it)
	{
		if (it->attributeId.compare("O3") == 0)
		{
			O3total += it->value;
			O3counter++;
		}

		if (it->attributeId.compare("NO2") == 0)
		{
            NO2total += it->value;
			NO2counter++;
		}
		if (it->attributeId.compare("SO2") == 0)
		{
			SO2total += it->value;
			SO2counter++;

		}
		if (it->attributeId.compare("PM10") == 0)
		{
			PM10total += it->value;
			PM10counter++;
		}
	}
	if(O3counter>0){
		avg[0] = O3total / O3counter;
	}else{
		avg[0] = 0;
	}
	if(NO2counter>0){
		avg[1] = NO2total / NO2counter;
	}else{
		avg[1] = 0;
	}
	if(SO2counter>0){
		avg[2] = SO2total / SO2counter;
	}else{
		avg[2] = 0;
	}
	if(PM10counter>0){
		avg[3] = PM10total / PM10counter;
	}else{
		avg[3] = 0;
	}
	
	return avg;
}

float Sensor::airQuality(list<Measure> data)
{
   // cout << "Calculating air quality..." << endl;
    
    if(data.begin() == data.end()) //vibe check
    {
       // cout << "she's empty your honour" << endl;
        return 0;
    }
    
    vector<float> averages = avgMeasures(data);
    if (averages[0]==0 && averages[1]==0 && averages[2]==0 && averages[03]==0)
    {
       // cout << "null averages your honour" << endl;
        return 0;
    }

    float O3avg = averages[0];
	float NO2avg = averages[1];
	float SO2avg = averages[2];
	float PM10avg = averages[3];

	int O3index = 0, NO2index = 0, SO2index = 0, PM10index = 0;

	if (O3avg >= 0.0 && O3avg <= 104)
    { 
        O3index = 4;
    }
    
	else if (O3avg >= 105.0 && O3avg < 179.0) 
    { 
        O3index = 7; 
    }
	else if (O3avg >= 180.0) 
    { 
        O3index = 10; 
    }

    if (NO2avg >= 0.0 && NO2avg <= 159.0)
    { 
        NO2index = 4; 
    }
    if (NO2avg >= 160.0 && NO2avg <= 299.0)
    { 
        NO2index = 7;   
    }
    if (NO2avg >= 300.0)
    { 
        NO2index = 10; 
    }

    if (SO2avg >= 0.0 && SO2avg <= 109.0)
    { 
        SO2index = 4; 
    }
    if (SO2avg >= 110.0 && SO2avg <= 199.0)
    { 
        SO2index = 7;  
    }
    if (SO2avg >= 200.0)
    { 
        SO2index = 10;   
    }

    if (PM10avg >= 0.0 && PM10avg <= 27.0)
    { 
        PM10index = 4;   
    }
    if (PM10avg >= 28.0 && PM10avg <= 49.0)
    { 
        PM10index = 7;   
    }
    if (PM10avg >= 50)
    { 
        PM10index = 10;   
    }
    
    return ((PM10index+SO2index+NO2index+O3index)/4);
	
}

list<Measure> Sensor::truncateMeasuresToPeriod(string t1, string t2)
{
    list<Measure>::iterator it;
	list<Measure> overPeriod;
    int year1, month1, day1, year2, month2, day2;
    const char *time1 = t1.c_str();
    const char *time2 = t2.c_str();

    sscanf(time1, "%d-%d-%d", &year1, &month1, &day1);
    sscanf(time2, "%d-%d-%d", &year2, &month2, &day2);

	for (it = mesures.begin(); it != mesures.end(); it++)
	{
        bool match = false;
        if (it->getMonth()>month1 && it->getMonth()<month2)
        {
            match = true;
        }
        else if (it->getMonth()==month1 && it->getMonth()<=month2)
        {
            if(it->getDay()>=day1)
            {   
                match = true;
            }
        }
        else if (it->getMonth()>=month1 && it->getMonth()==month2)
        {
            if(it->getDay()<=day2)
            {   
                match = true;
            }
        }
		if (match)
		{
			overPeriod.push_back(*it);
		}
	}
	return overPeriod;
}

float Sensor::airQualityOverPeriod(string t1, string t2)
{
    list<Measure> period = truncateMeasuresToPeriod(t1,t2);
    return airQuality(period);
}

int Sensor::getDistance(const Sensor other)
{
    // distance between latitudes 
    // and longitudes 
    double dLat = (other.latitude - latitude) * 
                      M_PI / 180.0; 
    double dLon = (other.longitude - longitude) *  
                      M_PI / 180.0; 
  
    // convert to radians 
    double latr = (latitude) * M_PI / 180.0; 
    double latr2 = (other.latitude) * M_PI / 180.0; 
  
    // apply formulae 
    double a =  pow(sin(dLat / 2), 2) +  
                pow(sin(dLon / 2), 2) *  
                cos(latr) * cos(latr2); 
    double rad = 6371; 
    double c = 2 * asin(sqrt(a)); 
    return rad * c; 
}

float Sensor::getScore(list<Measure> data)
{
    int i=0;
    float s=0;
    list<Measure>::iterator iter;

    iter = mesures.begin();
    for (iter = mesures.begin(); iter!=mesures.end() && (i<4); iter++, i++)
    {
        s+=iter->getValue();
    }
    return s/4;
}

list<Sensor> Sensor::getCluster(list<Sensor> sensorData, list<Measure> mesureData)
{
    list<Sensor> cluster;
    float N=getScore(mesureData);
    for (auto it=sensorData.begin(); it!=sensorData.end(); it++)
    {
        if(getDistance(*it)<=10 && abs(N-it->getScore(mesureData))<10)
        {
            cluster.push_front(*it);
        }
    }
    return cluster;
}

string Sensor::getId()
{
    return sensorID;
}

double Sensor::getLatitude()
{
    return latitude;
}

double Sensor::getLongitude()
{
    return longitude;
}

string Sensor::getDescripton() {
    return description;
}

list<Measure> Sensor::getMeasures() {
    return mesures;
}

ostream & operator << ( ostream & out, const Sensor & unSensor )
{
    out<<unSensor.sensorID<<" (lat:"<<unSensor.latitude<<", long:"<<unSensor.longitude<<") ("<<unSensor.description<<")";
	return out;
}

void Sensor::addMeasure (Measure mes)
{
    mesures.push_back(mes);
}

void Sensor::displayMeasures()
{
    for (auto it=mesures.begin(); it!=mesures.end(); it++)
    {
        cout << *it << endl;
    }
}

Sensor & Sensor::operator = ( const Sensor & sens )
{
	sensorID = sens.sensorID;
	latitude = sens.latitude;
    longitude = sens.longitude;
	description = sens.description;
	mesures = sens.mesures;

	return *this;
}


Sensor::Sensor ( const Sensor & unSensor )
{
#ifdef MAP
   cout << "Appel au constructeur de copie de <Sensor>" << endl;
#endif
    sensorID=unSensor.sensorID;
    latitude=unSensor.latitude;
    longitude=unSensor.longitude;
    description=unSensor.description;
    mesures=unSensor.mesures;
} 


Sensor::Sensor()
{
#ifdef MAP
    cout << "Appel au constructeur de <Sensor>" << endl;
#endif
} 

Sensor::Sensor(string id , float lat , float longi , string desc, list<Measure> mes)
{
    sensorID=id;
    latitude=lat;
    longitude=longi;
    description=desc;
    mesures=mes;
}

Sensor::~Sensor ( )
{
#ifdef MAP
    cout << "Appel au destructeur de <Sensor>" << endl;  
#endif
}