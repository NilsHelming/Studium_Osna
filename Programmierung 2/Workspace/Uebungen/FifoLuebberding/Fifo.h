//
// Created by Lukas on 23.10.2020.
//

#ifndef INC_2_FIFO_FIFO_H
#define INC_2_FIFO_FIFO_H

#include "FifoElement.h"

class Fifo {

private:
    FifoElement *top;

public:
    Fifo();
    ~Fifo();
    Fifo(const Fifo&);
    Fifo& push(const string&);
    string pop();
    Fifo& operator<<(const string&);
    Fifo& operator>>(string&);
    operator int () const;

    int size() const;
};


#endif //INC_2_FIFO_FIFO_H
