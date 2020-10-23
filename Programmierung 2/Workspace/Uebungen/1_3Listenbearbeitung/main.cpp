#include <iostream>
#include <sstream>
#include <list>

using namespace std;

list<int> intersection(list<int>, const list<int>&);
bool unique(const list<int>&, const list<int>&);
bool equals(list<int>, list<int>);
void joinUnique(list<int>& A, list<int> B);


class IsEntry{
    private:
        list<int> List;
    public:
        IsEntry(const list<int>& Reference) : List(Reference) {List.sort(); List.unique();}
        bool operator() (const int& i) {
            for (list<int>::iterator it = List.begin(); it != List.end(); it++)
                if (*it == i)
                    return true;
            return false;
        }
};
class NotEntry{
    private:
        IsEntry isEntry;
    public:
        NotEntry(const list<int>& Reference) : isEntry(Reference) {}
        bool operator() (const int& i) {return !isEntry(i);}
};

string toString(const list<int>& A){
    stringstream s;
    s << A.size() << "| ";
    for (list<int>::const_iterator it = A.begin(); it!=A.end(); it++)
        s << *it << " ";
    s << "|";
    return s.str();
}

int main(){
    list<int> A {1, 3, 5, 7, 9};
    list<int> B {3, 6, 9};
    list<int> C {1, 2, 4, 8};
    list<int> L {};

    cout << "A: " << toString(A) << endl;
    cout << "B: " << toString(B) << endl;
    cout << "C: " << toString(C) << endl;
    cout << "L: " << toString(L) << endl;

    cout << "Intersections:" << endl;
    cout << "A,A: " << toString(intersection(A,A)) << endl;
    cout << "A,B: " << toString(intersection(A,B)) << endl;
    cout << "A,C: " << toString(intersection(A,C)) << endl;
    cout << "B,C: " << toString(intersection(B,C)) << endl;
    cout << "A,L: " << toString(intersection(A,L)) << endl;

    cout << "No Common Entries:" << endl;
    cout << "A,A: " << unique(A,A) << endl;
    cout << "A,B: " << unique(A,B) << endl;
    cout << "A,C: " << unique(A,C) << endl;
    cout << "B,C: " << unique(B,C) << endl;
    cout << "A,L: " << unique(A,L) << endl;

    cout << "Equals:" << endl;
    cout << "A,A: " << equals(A,A) << endl;
    cout << "A,B: " << equals(A,B) << endl;
    cout << "A,C: " << equals(A,C) << endl;
    cout << "B,C: " << equals(B,C) << endl;
    cout << "A,L: " << equals(A,L) << endl;

    cout << "Join:" << endl;
    list<int> temp{A};
    joinUnique(temp,A);
    cout << "A,A: " << toString(temp) << endl;
    joinUnique(temp=A, B);
    cout << "A,B: " << toString(temp) << endl;
    joinUnique(temp=A, C);
    cout << "A,C: " << toString(temp) << endl;
    joinUnique(temp=B, C);
    cout << "B,C: " << toString(temp) << endl;
    joinUnique(temp=A, L);
    cout << "A,L: " << toString(temp) << endl;

    return 0;
}

list<int> intersection(list<int> A, const list<int>& B){
    A.sort(); //sortiere, damit alle identischen Werte nebeneinander liegen.
    A.unique(); //entferne alle doppelten einträge (da diese nun nebeneinander liegen)
    A.remove_if(NotEntry(B)); //entferne alle, die nicht in B vorkommen
    return A;
}

bool unique(const list<int>& A, const list<int>& B){
    return intersection(A, B).empty(); //prüft, ob die Liste aller gemeinsamen Werte leer ist.
}

bool equals(list<int> A, list<int> B){
    A.sort(); B.sort();
    return (A == B);
}

void joinUnique(list<int>& A, list<int> B){
    B.sort(); //sortiere, damit alle identischen Werte nebeneinander liegen.
    B.unique(); //entferne alle doppelten einträge (da diese nun nebeneinander liegen)
    B.remove_if(IsEntry(A)); //entferne alle, die in A vorkommen
    A.merge(B); //füge diese Elemente in A ein. (B ist danach leer!)
}

