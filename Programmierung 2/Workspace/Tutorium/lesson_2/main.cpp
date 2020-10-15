#include <iostream>
#include <sstream>
#include <string>

using namespace std;

void exceptionUngerade(int& divident){
    if (divident % 2 == 1)
        throw string("Nicht gerade");
}

void neu(int& neu){
    neu = 8;
}

int main(){
    int divident = 5;
    try{
        neu(divident);
        exceptionUngerade(divident);
    } catch (string fehler){
        cout << fehler << endl;
    }
    stringstream stream;
    stream << "Hello" << "World";
    cout << stream.str() << endl;

    return 0;
}