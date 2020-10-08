/*
 * -----------------------------------------------------------------------------
 * 
 * Beispielprogramm: op_neues_objekt.cpp
 * 
 * Demonstration zur Ueberladung des ++-Operators einer Klasse
 * 
 * VL Programmierung 2, O. Henkel, HS Osnabrueck
 * -----------------------------------------------------------------------------
 */

#include <iostream>
#include <string>
using namespace std;

class K
{
public:
    // Praefix-Inkrement
    K &operator++()
    { /* Implementation */
        return *this;
    }

    // += und (ggf. auf ++ zurueckfuehren)
    K &operator+=(K param)
    { /*Implementation*/
        return *this;
    }
};

//!
//!ausserhalb der Klasse
// Postfix Inkrement
K operator++(K &k, int)
{
    K temp(k);
    ++k;
    return temp;
}

// Addition mit neuem Ergebnis
K operator+(const K &lhs, const K &rhs)
{
    K ergebnis(lhs);
    return ergebnis += rhs;
}

int main()
{
    K k;
    ++k;
    K ergebnis = k + k;
    return 0;
}