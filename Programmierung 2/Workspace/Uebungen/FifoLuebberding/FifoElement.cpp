//
// Created by Lukas on 23.10.2020.
//

#include "FifoElement.h"

FifoElement::FifoElement(const string& t){
    text = t;
}
FifoElement::FifoElement(FifoElement &copy) {
    text = copy.text;
}

FifoElement::~FifoElement(){
}

string FifoElement::getString() {
    return this->text;
}

bool FifoElement::hasnext() {
    if (this == nullptr) return false;

    FifoElement* yasd = this->next;
    bool x = this->next == nullptr;

    if (this->next == nullptr){
        return false;
    }else{
        return true;
    }
}

FifoElement* FifoElement::getnext() {
    return next;
}

FifoElement& FifoElement::setnext(FifoElement *ding){
    this->next = ding;
    return *this;
}

