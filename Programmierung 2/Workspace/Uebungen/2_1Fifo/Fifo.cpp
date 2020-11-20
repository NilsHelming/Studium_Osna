#include "Fifo.h"

Fifo::Fifo(Fifo& cpy){

}


Fifo::~Fifo(){
    clear();
}

Fifo& Fifo::operator<<(const std::string& val){
    if(this->top == nullptr){
        this->top = new FifoElement(val);
    } else {
        FifoElement* last = this->top;
        while(last->GetNext() != nullptr)
            last = last->GetNext();

        last->SetNext(new FifoElement(val));
    }
    return *this;
}

Fifo& Fifo::operator>>(std::string& output){
    if (this->top == nullptr)
        throw new std::string("Fifo ist leer!");

    FifoElement* first = this->top;
    output = *first;

    this->top = this->top->GetNext();
    delete first;

    return *this;
}

Fifo::operator int () const{
    if(this->top == nullptr){
        return 0;
    } else {
        int counter {1};
        FifoElement* last = this->top;
        while(last->GetNext() != nullptr){
            last = last->GetNext();
            ++counter;
        }
        return counter;
    }
}

bool Fifo::empty(){
    return this->top == nullptr;
}
void Fifo::clear(){
    FifoElement* first;
    while(!empty()){
        first = this->top;
        this->top = first->GetNext();
        delete first;
    }
}