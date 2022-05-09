#pragma once
#include <iostream>
#include <iomanip>
#include <stdlib.h>
#include <stdio.h> 
#include <time.h> 
#include <string>
#include <vector>  
#include <fstream>
#include <sstream>
#include <algorithm>
#include <chrono>
class studentas {
private:
    std::string vardas;
    std::string pavarde;
    double gal;
    std::vector<double> n;
    
public:
    studentas() : vardas(), pavarde(), gal(), n() { }
    studentas(const std::string& vardas, const std::string& pavarde, double gal, const std::vector<double>& n) : vardas(vardas), pavarde(pavarde), gal(gal), n(n) {}
    const std::string& vardai() const { return vardas; }
    const std::string& pavardes() const { return pavarde; }
    const std::vector<double>& pazym() const { return n; }
    double egzas() const { return gal; }
    studentas(const studentas& source);
    studentas& operator=(const studentas& source);
    ~studentas();
};


studentas skaitymas(std::ifstream& fd);
bool rusiavimas(const studentas& lhs, const studentas& rhs);
bool compare_5(const studentas& v);
void RemoveRezult(std::vector<studentas>& ab);
bool isNumber(const std::string& str);
int leftshift(unsigned char b);
int rightshift(unsigned char b);
