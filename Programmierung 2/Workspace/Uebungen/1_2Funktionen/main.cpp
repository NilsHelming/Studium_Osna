#include <iostream>
#include <sstream>
#include <iomanip>

using namespace std;

void abschneiden(float&, int);
void ggT(int& a, const int& b);

int main(){
    float val {23.14159};
    abschneiden(val, 5);

    int test = 27;
    ggT(test,15);
    cout << test << endl;

    return 0;
}


void abschneiden(float& x, int n){
    stringstream ss;
    ss << fixed << setprecision(n) << x << endl;
    ss >> x;
}

void ggT(int& a, const int& b){
    if (a == b) //a ist der größte gmeinsame Teiler von a und b
        return;
    else if (a > b)
        return ggT(a-=b,b);
    else //if (a < b)
        return ggT(a, b-a);
}