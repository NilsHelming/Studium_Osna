#include "Fifo.h"
#include "sstream"

void Fifo::info(){
    std::cout << "Test"<<std::endl;
    // Fifo::element* next = this->top;
    // while (next != nullptr){
    //     std::cout << **next << std::endl;
    //     next = ++*next;
    // }
}

Fifo::Fifo(const Fifo& cpy){
    *this = cpy; //Verweis auf Zuweisungsoperator.
}

Fifo& Fifo::operator= (const Fifo& cpy){
    if(this == &cpy) return *this; //Selbstzuweisung verhindern.

    this->clear();

    FifoElement* obj = cpy.top;
    do{
        //FifoElement* -> FifoElement -> string
        *this << *obj; //cast from FifoElement to string
        obj = obj->GetNext();
    } while(obj != nullptr);

    return *this;
};

Fifo::~Fifo(){
    clear();
}

Fifo& Fifo::operator<<(const std::string& val){
    if(empty()){
        this->top = new FifoElement(val);
    } else {
        FifoElement* last = this->top;
        while(last->GetNext() != nullptr)
            last = last->GetNext();

        last->SetNext(new FifoElement(val));
    }
    return *this;
}

Fifo& Fifo::operator<<(Fifo& src){
    std::string temp;

    while(!src.empty()){
        src >> temp;
        *this << temp;
    }

    return *this;
}

Fifo& Fifo::operator>>(std::string& output){
    if (empty())
        throw new std::string("Fifo ist leer!");

    FifoElement* first = this->top;
    output = *first;

    this->top = this->top->GetNext();
    delete first;

    return *this;
}

Fifo::operator int () const{
    if(empty()){
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

bool Fifo::empty() const{
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

std::string Fifo::concat(const std::string& sep){
    std::stringstream ss;

    FifoElement* curr = this->top;
    if (curr != nullptr) {
        ss << static_cast<std::string>(*curr);
        curr = curr->GetNext();
    }

    while(curr != nullptr){
        //top: FifoElement* -> FifoElement -> std::string
        ss << sep << static_cast<std::string>(*curr);
        curr = curr->GetNext();
    }

    return ss.str();
}
