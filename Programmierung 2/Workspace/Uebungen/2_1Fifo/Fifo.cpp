#include "Fifo.h"

Fifo::~Fifo(){
    Fifo::element* next;
    while(this->top != nullptr){
        Fifo::element* _top_ptr = this->top;
        Fifo::element& _top = *_top_ptr;
        Fifo::element* _top_next = ++_top;
        next = ++*(this->top);
        delete (this->top);
        top = next;
    }
}

Fifo& Fifo::operator<<(const std::string& val){
    if(this->top == nullptr){
        this->top = new Fifo::element(val);
        return *this;
    } else {
        //finde das letzte Element
        Fifo::element* last = this->top;
        while(++*last != nullptr)
            Fifo::element* last = ++*last;

        // ++*last = new Fifo::element(val); //setze next des letzten Elements.
        return *this;
    }
}

Fifo& Fifo::operator>>(std::string& output){
    //haben wir etwas auszugeben??
    if(this->top == nullptr)
        throw std::string("Liste ist Leer!");

    //lese den ersten Eintrag in unserer Liste in den output:
    output = **this->top;//pointer auf top -> top-Element -> String eintrag.
    //lösche den ersten Eintrag in unserer Liste: (den gerade gelesenen Eintrag)
    Fifo:element* temp = this->top;
    this->top = ++*this->top;
    delete temp;

    return *this;
}

Fifo::operator int () const{
    int counter {0};

    Fifo::element* next = this->top;
    while(next != nullptr){
        ++counter;
        next = ++*next;
    }
    return counter;
}

Fifo::element::FifoElement(const std::string& value): value(value){};
std::string& Fifo::element::operator*(){
    return this->value;
}
Fifo::element* Fifo::element::operator++(){ //prefix
    FifoElement thi = *this;

    return this->next;
}