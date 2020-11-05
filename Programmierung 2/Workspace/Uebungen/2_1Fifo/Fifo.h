#include <string>
#include <iostream>

class Fifo;
class FifoElement;


class Fifo{
public: typedef FifoElement element;

private:
    Fifo::element *top;

public:
    Fifo() = default;
    ~Fifo();

    Fifo& operator<<(const std::string&);
    Fifo& operator>>(std::string&);

    operator int () const;

    //für die Testfälle:
    std::string pop(){std::string x;*this >> x; return x;}
    void push(const std::string& val){ *this << val;}
    int size(){return *this;} //automatic conversion to int!
    void info();//defined at very end of file!
};

class FifoElement{
    Fifo::element *next = nullptr;
    std::string value;
public:
    FifoElement(const std::string&);
    FifoElement(const FifoElement& o):next(o.next), value(o.value){};

    std::string& operator*();
    Fifo::element* operator++(); //prefix

    // void SetNext(Fifo::element *next);
    // Fifo::element *GetNext();
};

void Fifo::info(){
    Fifo::element* next = this->top;
    while (next != nullptr){
        std::cout << **next << std::endl;
        next = ++*next;
    }
}