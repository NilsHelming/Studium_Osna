#include <iostream>
#include <vector>

using namespace std;

class Ringliste{
    vector<int> data;
    int read{0};
    int write{0};
    int capacity;
    int size{0};

    Ringliste() : data(10), capacity(10){} //default: capacity = 10
    Ringliste(const int& capacity) : data(capacity), capacity(capacity){}
    Ringliste(const Ringliste& cpy) : data(cpy.data), capacity(cpy.capacity), read(cpy.read), write(cpy.write), size(cpy.size) {}

    Ringliste operator<<(const int& x){
        data[write] = x;
        write = (write+1)%capacity;

        size++;
        if (size > capacity){
            size = capacity;
            read++;
        }
        return *this;
    }
    Ringliste operator>>(int& x){
        if(size < 1)
            throw "This List is empty!";
        x = data[read++];
        size--;
        return *this;
    }

};

int main(){
    return 0;
}