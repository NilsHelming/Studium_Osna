//
// Created by Lukas on 23.10.2020.
//

#ifndef INC_2_FIFO_FIFOELEMENT_H
#define INC_2_FIFO_FIFOELEMENT_H

#include <iostream>

using namespace std;

class FifoElement {
private:

    FifoElement *next = nullptr;
    string text;

public:
    FifoElement(const string&);
    FifoElement(FifoElement&);
    ~FifoElement();
    string getString();
    bool hasnext();
    FifoElement* getnext();
    FifoElement& setnext(FifoElement*);

};


#endif //INC_2_FIFO_FIFOELEMENT_H
