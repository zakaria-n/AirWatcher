using namespace std;

#include "Measures.h"

Measures::Measures ( const Measures & unMeasures )
{
#ifdef MAP
   cout << "Appel au constructeur de copie de <Measures>" << endl;
#endif
} 


Measures::Measures()
{
#ifdef MAP
    cout << "Appel au constructeur de <Measures>" << endl;
#endif
} 

Measures::~Measures ( )
{
#ifdef MAP
    cout << "Appel au destructeur de <Measures>" << endl;
#endif
} 
