#include <iostream>

using namespace std;

#include "Individual.h"

Individual::Individual ( const Individual & unIndividual )
{
#ifdef MAP
   cout << "Appel au constructeur de copie de <Individual>" << endl;
#endif
} 


Individual::Individual()
{
#ifdef MAP
    cout << "Appel au constructeur de <Individual>" << endl;
#endif
} 

