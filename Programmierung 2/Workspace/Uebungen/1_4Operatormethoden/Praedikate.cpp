#include <cmath>
#include <string>
#include <sstream>
#include <iostream>

class istTeilerVon_n;
class istNahe;
class istKuerzerAls;
class besitztMehrWorteAls;

class istTeilerVon_n{
    const int zahl;

public:
    istTeilerVon_n(const int& init): zahl(init){}
    bool operator()(const int& n){
        return n%zahl == 0;
    }
};

class istNahe{
    const double hinterlegt;
    const double tolerance;
public:
    istNahe(const double& hinterlegt, const double& tolerance = 0.0001):
        hinterlegt(hinterlegt), tolerance(tolerance){}

    bool operator()(double cmp){
        return std::abs(hinterlegt-cmp) <= tolerance;
    }
};

class istKuerzerAls{
public:
    bool operator()(const std::string& s1, const std::string& s2){
        return s1.size() < s2.size();
    }
};

class besitztMehrWorteAls{
    static int zaehleWorte(std::string src){
        std::stringstream ss{src};
        std::string temp;
        int counter {0};
        while(ss >> temp)
            if(temp.size() > 1)
                ++counter;

        return counter;
    }
public:
    bool operator()(std::string s1, std::string s2){
        return zaehleWorte(s1) > zaehleWorte(s2);
    }

};


int main(){
    // std::cout << istTeilerVon_n(17)(125) << std::endl;
    // std::cout << istNahe(0.1)(0.2) << std::endl;
    // std::cout << istKuerzerAls()("ASD ASD ASD", "AQWEDA WADSF WASDF") << std::endl;
    // std::cout << besitztMehrWorteAls()("ASD ASD ASD was", "AQWEDA WADSF WASDF") << std::endl;

    return 0;
}