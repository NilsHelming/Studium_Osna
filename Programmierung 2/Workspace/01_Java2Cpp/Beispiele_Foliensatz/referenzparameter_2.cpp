/*
 * -----------------------------------------------------------------------------
 * 
 * Beispielprogramm: referenzparameter_2.cpp
 * 
 * Demonstration von call by value and call by reference
 * 
 * VL Programmierung 2, O. Henkel, HS Osnabrueck
 * -----------------------------------------------------------------------------
 */

#include <iostream>

using namespace std;

class Obj
{
public:
    void setze_i(int neuerWert)
    {
        i = neuerWert;
    }

    int erhalte_i()
    {
        return i;
    }

private:
    int i = 0;
};

void ausgabeObj(Obj obj)
{
    cout << "Wert i: " << obj.erhalte_i() << endl;
}

void setRef(Obj &obj, int neuerWert)
{
    obj.setze_i(neuerWert);
}

void setCopy(Obj obj, int neuerWert)
{
    obj.setze_i(neuerWert);
}

int main()
{
    Obj obj;
    setCopy(obj, 10);
    ausgabeObj(obj);
    setRef(obj, 10);
    ausgabeObj(obj);

    return 0;
}
