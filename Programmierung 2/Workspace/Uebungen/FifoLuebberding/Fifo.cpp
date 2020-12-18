//
// Created by Lukas on 23.10.2020.
//

#include "Fifo.h"
#include "sstream"

Fifo::Fifo() {
    top = nullptr;
}
Fifo::Fifo(const Fifo &a): top(nullptr) {
    if (a.top == nullptr) return;
    FifoElement *temp = a.top;
    do {
        this->push(temp->getString());
    }while ((temp = temp->getnext())!= nullptr);
}

Fifo::~Fifo() {
    FifoElement *temp;
    if (top != nullptr) {
        while (top->hasnext()) {
            temp = top->getnext();
            delete top;
            this->top = temp;
        }
    }
};

Fifo& Fifo::push(const string &s) {
    if (this->top == nullptr) {
        this->top = new FifoElement(s);
        return *this;
    }
    FifoElement *temp = this->top;
cout << "a" << endl;
    while (temp->hasnext()){
cout << "b" << endl;
        temp = temp->getnext();
    }
    temp->setnext(new FifoElement(s));

    return *this;
}

string Fifo::pop() {
    if (this->top==nullptr) throw new string("fehler leere fifo");

    string x = this->top->getString();   // text zwischenspeichern
    FifoElement *temp = this->top;
    this->top = this->top->getnext();    // top weiter schieben
    delete temp;
    return x;                             // ehemaligen top ausgeben
}

Fifo& Fifo::operator<<(const string& s) {
    return push(s);
}

Fifo& Fifo::operator>>(string& s) {
    stringstream ss;

    while (this->top->hasnext()){

        ss << this->pop();

    }
    s=ss.str();
    return *this;
}

Fifo::operator int() const {
    return this->size();
}

int Fifo::size() const {
    if (top == nullptr) return 0;
    FifoElement *temp = this->top;
    int counter = 1;

    while (temp->hasnext()){
        temp = temp->getnext();
        counter++;
    }
    return counter;
}


