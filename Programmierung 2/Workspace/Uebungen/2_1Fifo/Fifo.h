#include <string>
#include <iostream>

class FifoElement{
    FifoElement *next = nullptr;
    std::string value;
public:
    FifoElement(const std::string& v):next(nullptr), value(v){};

    FifoElement* GetNext(){return next;};
    void SetNext(FifoElement* elem){next = elem;};
    operator std::string(){return value;};
};

class Fifo{
private:
    FifoElement *top = nullptr;

public:
    Fifo() = default;
    Fifo(Fifo&);
    ~Fifo();

    Fifo& operator<<(const std::string&);
    Fifo& operator>>(std::string&);
    Fifo& operator= (const Fifo&);

    operator int () const;

    bool empty();
    void clear();

    //für die Testfälle:
    std::string pop(){std::string x;*this >> x; return x;}
    void push(const std::string& val){ *this << val;}
    int size(){return *this;} //automatic conversion to int!
    void info();//defined at very end of file!
};


void Fifo::info(){
    // Fifo::element* next = this->top;
    // while (next != nullptr){
    //     std::cout << **next << std::endl;
    //     next = ++*next;
    // }
}
// Workspace/Uebungen/2_1Fifo/FifoClassTest.exe Workspace/Uebungen/2_1Fifo/zitat.txt