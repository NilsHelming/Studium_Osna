/*
 * -----------------------------------------------------------------------------
 * 
 * Beispielprogramm: op_aktuelles_objekt.cpp
 * 
 * Demonstration zur Verwendung verschiedener Operatoren
 * 
 * VL Programmierung 2, O. Henkel, HS Osnabrueck
 * -----------------------------------------------------------------------------
 */

#include <iostream>
using namespace std;

class K
{
public:
    // Praefix-Operatoren
    K &operator++()
    { /* Implementation */
        return *this;
    }
    K &operator--()
    { /* Implementation */
        return *this;
    }

    // += und -= (ggf. auf ++/-- zurueckfuehren)
    K &operator+=(K param)
    { /*Implementation*/
        return *this;
    }
    K &operator-=(K param)
    { /*Implementation*/
        return *this;
    }

    // Weitere, z.B. *= und /= (ggf. auf +=/-= zurueckfueren)...
};

int main()
{
    K k;
}
