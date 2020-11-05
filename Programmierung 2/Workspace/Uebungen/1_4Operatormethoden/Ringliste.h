#pragma once
#include <vector>
#include <string>

class RingIter;
class RingCIter;

class Ringliste{
    std::vector<int> data;
    int capacity;
    int read{0};
    int write{0};
    int length{0};
public:
    Ringliste (int capacity = 10);
    Ringliste (const Ringliste&);
    Ringliste& operator= (const Ringliste&);//  Zuweisungsoperator

    int size() const;//currently occupied spaces
    int total() const;//available spaces
    bool empty() const;//is empty?
    bool full() const;//is full?

    int& operator[](const int&);
    const int& operator[](const int&) const;
    std::string toString() const;

    void push_front(const int&);
    int pop_front();
    void push_back(const int&);
    int pop_back();

    Ringliste& operator+ ();//unary plus
    Ringliste& operator+= (const int&);
    Ringliste operator- () const;//unary minus
    Ringliste& operator-= (const int&);
    Ringliste& operator*= (const int&);
    Ringliste& operator/= (const int&);
    Ringliste& operator%= (const int&);

    //for the iterator:
    friend class RingIter;
    friend class RingCIter;
    typedef RingIter iterator;
    typedef RingCIter const_iterator;
    typedef ptrdiff_t difference_type;
    typedef size_t size_type;
    typedef int value_type;
    typedef int * pointer;
    typedef int & reference;

    iterator begin();
    const_iterator begin() const;
    iterator end();
    const_iterator end() const;
};

Ringliste& operator+ (const Ringliste&, const int&);
Ringliste& operator+ (const int&, const Ringliste&);
Ringliste& operator++(Ringliste&); //prefix
Ringliste operator++(Ringliste&, int); //postfix

Ringliste& operator- (const Ringliste&, const int&);
Ringliste& operator- (const int&, const Ringliste&);
Ringliste& operator--(Ringliste&); //prefix
Ringliste operator--(Ringliste&, int); //postfix

Ringliste& operator* (const Ringliste&, const int&);
Ringliste& operator* (const int&, const Ringliste&);

Ringliste& operator/ (const Ringliste&, const int&);
Ringliste& operator/ (const int&, const Ringliste&);

Ringliste& operator% (const Ringliste&, const int&);
Ringliste& operator% (const int&, const Ringliste&);

Ringliste& operator<<(Ringliste&, const int&);
Ringliste& operator<<(Ringliste&, const Ringliste&);
Ringliste& operator>>(Ringliste&, int&);
Ringliste& operator>>(Ringliste&, Ringliste&);
bool operator==(const Ringliste&, const Ringliste&);
bool operator!=(const Ringliste&, const Ringliste&);

class RingIter {
private:
  Ringliste & liste;
  int position;
public:
  RingIter( Ringliste& ring, int position); //: liste(ring), position (position)
  bool operator==(const Ringliste::iterator&);
  bool operator!=(const Ringliste::iterator&);
  int& operator* ();
  Ringliste::iterator& operator++();
  Ringliste::iterator operator++(int);
};

class RingCIter {
private:
  const Ringliste& liste;
  int position;
public:
  RingCIter(const Ringliste& ring, int position); //: liste(ring), position (position)
  bool operator==(const Ringliste::const_iterator&);
  bool operator!=(const Ringliste::const_iterator&);
  const int& operator* ();
  const Ringliste::const_iterator& operator++();
  Ringliste::const_iterator operator++(int);
};

