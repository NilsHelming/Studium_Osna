#include "Ringliste.h"

#include <vector>
#include <sstream>

using namespace std;

Ringliste::Ringliste(int capacity) : data(capacity), capacity(capacity) {}
//Kopierkonstruktor
Ringliste::Ringliste(const Ringliste& ring) : data(ring.data), read(ring.read), write(ring.write), capacity(ring.capacity), length(ring.length){}
Ringliste& Ringliste::operator= (const Ringliste& cpy){ //Zuweisungs operator
    this->data = cpy.data;
    this->read = cpy.read;
    this->write = cpy.write;
    this->capacity = cpy.capacity;
    this->length = cpy.length;
    return *this;
}

int Ringliste::size() const {return this->length;}//currently occupied spaces
int Ringliste::total() const{return this->capacity;}//available spaces
bool Ringliste::empty() const{return this->length == 0;}//is empty?
bool Ringliste::full() const{return this->length == this->capacity;}//is full?


void Ringliste::push_back(const int& val){ //insert a new element at the write position.
    //insert at write
    this->data[this->write] = val;

    //move the write position to its next target.
    ++(this->write)%=this->capacity;

    if(this->length == this->capacity) //we were at capacity, when val was pushed in.
        this->read = this->write; //we have written over the element at the read position. carry it with us.
    else
        this->length+=1; //we lengthened our readable data.
}
void Ringliste::push_front(const int& val){ //insert a new element before the read position.
    //find the position at which we should insert:
    this->read = (this->read+this->capacity-1)%this->capacity;
    //write to the desired position:
    this->data[this->read] = val;

    if(this->length == this->capacity) //we have been at capacity before insertion.
        this->write = this->read; //we moved the front past 'write' - we have to carry it with us.
    else
        this->length+=1; //we lengthened our readable data.
}
int Ringliste::pop_front(){ //return the element at the read position.
    if(this->length < 1) throw std::out_of_range("List is empty");
    this->length-=1;//we will 'remove' a value
    int val {this->data[this->read]};

    ++(this->read)%=this->capacity;

    return val;
}
int Ringliste::pop_back(){ //return the element before the write position.
    if(this->length < 1) throw std::out_of_range("List is empty");
    this->length-=1;//we will 'remove' a value
    //find the position to be read from:
    this->write = (this->write+this->capacity-1)%this->capacity;
    return this->data[this->write];
}

int& Ringliste::operator[](const int& index){
    if(index < 0 || index >= this->length) throw std::out_of_range("No Such Entry exists!");
    int i = (index+this->read)%this->capacity; //transform the index from 'in relation to read' to position of the data-vector.

    return this->data[i];
}
const int& Ringliste::operator[](const int& index) const{
    if(index < 0 || index >= this->length) throw std::out_of_range("No Such Entry exists!");
    int i = (index+this->read)%this->capacity; //transform the index from 'in relation to read' to position of the data-vector.

    return this->data[i];
}
string Ringliste::toString() const{     //Beispielausgabe: 5/5 | 2 3 4 5 6\n
    stringstream stream;
    stream << this->size() << "/" << this->total() << " |";

    for(int entry: *this){
        stream << " " << entry;
    }
    return stream.str();
}

Ringliste& Ringliste::operator+ (){//unary plus
    return *this;
}
Ringliste& Ringliste::operator+= (const int& val){
    for(int& entry: *this)
        entry += val;
    return *this;
}
Ringliste Ringliste::operator- () const{//unary minus
    Ringliste liste {*this};
    for(int& entry: liste)
        entry = -entry;
    return liste;
}
Ringliste& Ringliste::operator-= (const int& val){
    for(int& entry: *this)
        entry -= val;
    return *this;
}
Ringliste& Ringliste::operator*= (const int& val){
    for(int& entry: *this)
        entry *= val;
    return *this;
}
Ringliste& Ringliste::operator/= (const int& val){
    for(int& entry: *this)
        entry /= val;
    return *this;
}
Ringliste& Ringliste::operator%= (const int& val){
    for(int& entry: *this)
        entry %= val;
    return *this;
}


Ringliste& operator+ (const Ringliste& ring, const int& val){
    Ringliste liste {ring};
    return liste+=val;
}
Ringliste& operator+ (const int& val, const Ringliste& ring){
    Ringliste liste {ring};
    return liste+=val;
}
Ringliste& operator++ (Ringliste& ring){//prefix: ++ring
    return ring+=1;
}
Ringliste operator++ (Ringliste& ring, int){//postfix: ring++
    Ringliste temp{ring};
    ring+=1;
    return temp;
}

Ringliste& operator- (const Ringliste& ring, const int& val){
    Ringliste liste {ring};
    return liste-=val;
}
Ringliste& operator- (const int& val, const Ringliste& ring){
    Ringliste liste {ring};
    return liste-=val;
}
Ringliste& operator-- (Ringliste& ring){//prefix: --ring
    return ring-=1;
}
Ringliste operator-- (Ringliste& ring, int){//postfix: ring--
    Ringliste temp{ring};
    ring-=1;
    return temp;
}

Ringliste& operator* (const Ringliste& ring, const int& val){
    Ringliste liste {ring};
    return liste*=val;
}
Ringliste& operator* (const int& val, const Ringliste& ring){
    Ringliste liste {ring};
    return liste*=val;
}

Ringliste& operator/ (const Ringliste& ring, const int& val){
    Ringliste liste {ring};
    return liste/=val;
}
Ringliste& operator/ (const int& val, const Ringliste& ring){
    Ringliste liste {ring};
    return liste/=val;
}

Ringliste& operator% (const Ringliste& ring, const int& val){
    Ringliste liste {ring};
    return liste%=val;
}
Ringliste& operator% (const int& val, const Ringliste& ring){
    Ringliste liste {ring};
    return liste%=val;
}

Ringliste& operator<<(Ringliste& liste, const int& newVal){
    liste.push_back(newVal);
    return liste;
}
Ringliste& operator<<(Ringliste& liste, const Ringliste& src){
    for(int val: src)
        liste << val;
    return liste;
}

Ringliste& operator>>(Ringliste& liste, int& output){
    output = liste.pop_front();
    return liste;
}
Ringliste& operator>>(Ringliste& liste, Ringliste& output){
    while(!liste.empty() && !output.full())
        output << liste.pop_front();
    return liste;
}

bool operator==(const Ringliste& lhs, const Ringliste& rhs){
    if (lhs.size() != rhs.size()) return false;
    for(int index = 0; index < lhs.size(); ++index)
        if (lhs[index] != rhs[index]) return false;
    return true;
}
bool operator!=(const Ringliste& lhs, const Ringliste& rhs){
    return !(lhs==rhs);
}

//Mutable Iterator:
Ringliste::iterator Ringliste::begin(){
    return Ringliste::iterator( *this, 0 );
}
Ringliste::iterator Ringliste::end(){
    return Ringliste::iterator( *this, this->length );
}
Ringliste::iterator::RingIter(Ringliste & ring, int position): liste(ring), position (position){}
bool Ringliste::iterator::operator==(const Ringliste::iterator& cmp){
    return (this->liste == cmp.liste && this->position == cmp.position);
}
bool Ringliste::iterator::operator!=(const Ringliste::iterator& cmp){
    return !(*this==cmp);
}
int& Ringliste::iterator::operator*(){
    return this->liste[this->position];
}
Ringliste::iterator& Ringliste::iterator::operator++(){
    ++(this->position);
    return *this;
}
Ringliste::iterator Ringliste::iterator::operator++(int){
    Ringliste::iterator temp{*this};
    ++(this->position);
    return temp;
}


//Const Iterator:
Ringliste::const_iterator Ringliste::begin() const{
    return Ringliste::const_iterator( *this, 0 );
}
Ringliste::const_iterator Ringliste::end() const{
    return Ringliste::const_iterator( *this, this->length );
}
Ringliste::const_iterator::RingCIter(const Ringliste & ring, int position): liste(ring), position (position){}
bool Ringliste::const_iterator::operator==(const Ringliste::const_iterator& cmp){
    return (this->liste == cmp.liste && this->position == cmp.position);
}
bool Ringliste::const_iterator::operator!=(const Ringliste::const_iterator& cmp){
    return !(*this==cmp);
}
const int& Ringliste::const_iterator::operator*(){
    return this->liste[this->position];
}
const Ringliste::const_iterator& Ringliste::const_iterator::operator++(){
    ++(this->position);
    return *this;
}
Ringliste::const_iterator Ringliste::const_iterator::operator++(int){
    Ringliste::const_iterator temp{*this};
    ++(this->position);
    return temp;
}