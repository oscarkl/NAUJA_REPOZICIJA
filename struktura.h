#pragma once
#include <iostream>
#include <iomanip>
#include <stdlib.h>
#include <stdio.h> 
#include <time.h> 
#include <string>
#include <fstream>
#include <sstream>
#include <algorithm>
#include <chrono>

#include "vektorius.h"
//#include <vector>  
//using std::vector;

class zmogus {
public:
    virtual const std::string& vardai() const = 0;
    virtual const std::string& pavardes() const = 0;
};

class studentas : public zmogus {
private:
    std::string vardas;
    std::string pavarde;
    double gal;
    vector<double> n;

public:
    studentas() : vardas(), pavarde(), gal(), n() { }
    studentas(const std::string& vardas, const std::string& pavarde, double gal, const vector<double>& n) : vardas(vardas), pavarde(pavarde), gal(gal), n(n) {}
    const std::string& vardai() const { return vardas; }
    const std::string& pavardes() const { return pavarde; }
    const vector<double>& pazym() const { return n; }
    double egzas() const { return gal; }
    studentas(const studentas& source);
    studentas& operator=(const studentas& source);
    ~studentas();
};


void skaitymas(std::ifstream& fd, studentas& temp);
bool rusiavimas(const studentas& lhs, const studentas& rhs);
bool compare_5(const studentas& v);
void RemoveRezult(vector<studentas>& ab);
bool isNumber(const std::string& str);
