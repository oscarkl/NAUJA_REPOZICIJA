#include "struktura.h"

bool isNumber(const std::string& str)
{
    for (char const& c : str) {
        if (std::isdigit(c) == 0) return false;
    }
    return true;
}

double vidurkis(const std::vector<double>&h) {
    double sum = 0;
    for (auto pazymys : h)
    {
        sum += pazymys;
    }
    return sum / h.size();
}

double egz(double vid, const std::vector<double>&h) {
    double egzas = 0.6 * h.back() + 0.4 * vidurkis(h);
    return egzas;
}

studentas skaitymas(std::ifstream& fd)
{
    std::string data, vard, pav;
    int sk;
    std::vector<double> h;
    double gal;
    fd >> vard;
    fd >> pav;
    for (int i = 0; i < 5; i++)
    {
        fd >> data;
        //std::cout << data << " ";
        sk = std::stoi(data);
        h.push_back(sk);
        
    }
    gal = egz(vidurkis(h), h);
    return studentas(vard, pav, gal, h);
}

bool rusiavimas(const studentas&lhs, const studentas&rhs) {
    if (lhs.vardai() != rhs.vardai()) return lhs.vardai() < rhs.vardai();
    else return lhs.vardai() < rhs.vardai();
}

bool compare_5(const studentas& v) { return v.egzas() < 5; }

void RemoveRezult(std::vector<studentas>& ab) {
    ab.erase(
        std::remove_if(ab.begin(), ab.end(), [&](studentas const& ab) {
            return compare_5(ab);
            }),
        ab.end());
}
