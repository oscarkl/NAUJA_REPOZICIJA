#include "struktura.h"
int sk;
int counter = 0;
double durs;
double duro;
double durg;
#define MAXBUFLEN 1000000

using namespace std;

vector<studentas> rezult;

double dur[5];

void input(int& o) {
    char skait;
    if (o == 0) {
        //cout << "ar norite naudoti jau sugeneruotus studenus? T/N:" << endl;
        skait = 'T';
        if (skait == 'T' || skait == 't')
        {
            cout << "pasirinkite faila kuri skaityti" << endl;
            cout << "(1) 1000" << endl;
            cout << "(2) 10000" << endl;
            cout << "(3) 100000" << endl;
            cout << "(4) 1000000" << endl;
            cout << "(5) 10000000" << endl;
            cin >> o;
        }
    }
    auto in = chrono::high_resolution_clock::now();
    string name = "Kurstiokai.txt";
    if (o > 0) {
        name = to_string(int(1000 * pow(10, o - 1))) + "_studentu.txt";
    }
    cout << name;
    ifstream fd(name);
    studentas temp;
    if (fd) {
        if (fd.eof()) {
            cout << "failas yra tuscias" << endl;
        }
        else {
            string data;
            getline(fd, data);
            for (int i = 0; i< int(1000 * pow(10, o - 1)); i++) {
                //cout << rezult.size();
                skaitymas(fd, temp);
                //cout << temp.vardai();
                rezult.push_back(temp);
                
            }
            fd.close();
        }
    }
    auto out = chrono::high_resolution_clock::now();
    auto dura = chrono::duration_cast<chrono::microseconds>(out - in);
    durg = dura.count();
}

void output(int o) {
    auto is = chrono::high_resolution_clock::now();
    //vector<studentas> kietiakai;
    vector<studentas> nevyk;

    sort(rezult.begin(), rezult.end(), rusiavimas);
    for (auto& stud : rezult) {
        if (compare_5(stud)) {
            nevyk.push_back(stud);
        }
    }
    //cout << leftshift(rezult[1].egzas());
    RemoveRezult(rezult);
    auto out = chrono::high_resolution_clock::now();
    auto durt = chrono::duration_cast<chrono::microseconds>(out - is);
    durs = durt.count();
    if (o > 0) {
        ofstream fr("nevykeliai.txt");
        fr << left << setw(16) << "Vardas" << left << setw(16) << "Pavarde" << left << setw(16) << "Galutinis vid." << endl;
        fr << "-----------------------------" << endl;
        for (int i = 0; i < nevyk.size(); i++) {
            fr << left << setw(16) << nevyk[i].vardai() << left << setw(16) << nevyk[i].pavardes() << left << setw(16) << fixed << setprecision(2) << nevyk[i].egzas() << endl;
        }
        nevyk.clear();
        fr.close();
        ofstream fp("kietiakai.txt");
        fp << left << setw(16) << "Vardas" << left << setw(16) << "Pavarde" << left << setw(16) << "Galutinis(vid.)" << endl;
        fp << "-----------------------------" << endl;
        for (int i = 0; i < rezult.size(); i++) {
            fp << left << setw(16) << rezult[i].vardai() << left << setw(16) << rezult[i].pavardes() << left << setw(16) << fixed << setprecision(2) << rezult[i].egzas() << endl;
        }
        rezult.clear();
        fp.close();
    }
    auto end = chrono::high_resolution_clock::now();
    auto durb = chrono::duration_cast<chrono::microseconds>(end - out);
    duro = durb.count();
}

void filegen() {
    string vardas, pavarde;
    int n[5];
    string name;
    int skai;
    for (int i = 0; i < 5; i++) {
        auto start = chrono::high_resolution_clock::now();
        name = to_string(int(1000 * pow(10, i))) + "_studentu.txt";
        cout << name << endl;
        ofstream fr(name);
        fr << left << setw(16) << "Vardas" << left << setw(16) << "Pavarde" << left << setw(8) << "ND1" << left << setw(8) << "ND2" << left << setw(8) << "ND3" << left << setw(8) << "ND4" << left << setw(8) << "Egz." << endl;
        skai = 1000 * pow(10, i);
        for (int j = 1; j <= skai; j++) {
            vardas = "Vardas" + to_string(j);
            pavarde = "Pavarde" + to_string(j);
            for (int k = 0; k < 5; k++) {
                n[k] = rand() % 10 + 1;
            }
            fr << left << setw(16) << vardas << left << setw(16) << pavarde << left << setw(8) << n[0] << left << setw(8) << n[1] << left << setw(8) << n[2] << left << setw(8) << n[3] << left << setw(8) << n[4] << "\n";
        }
        auto stop = chrono::high_resolution_clock::now();
        auto duration = chrono::duration_cast<chrono::milliseconds>(stop - start);
        dur[i] = duration.count() / double(1000);

        fr.close();
    }
}



int main() {
    /** <summary>
    * @brief this ahaha
    * this bbb
    * @param vara
    **/
    srand(time(NULL));
    int studentSk;
    char type;
    char skait;

    int o;
    cout << "ar generuoti failus? T/N" << endl;
    cin >> skait;
    if (skait == 'N' || skait == 'n') {
        o = 0;
        //input(o);
        //sort(rezult.begin(), rezult.end(), [](const studentas& a, const studentas& b)
            //{
                //return a.vardas < b.vardas;
            //});
        //output(o);
    }
    if (skait == 'T' || skait == 't') {
        filegen();
        cout << "pasirinkite faila kuri skirstyti" << endl;
        cout << "(1) 1000" << endl;
        cout << "(2) 10000" << endl;
        cout << "(3) 100000" << endl;
        cout << "(4) 1000000" << endl;
        cout << "(5) 10000000" << endl;
        cin >> o;
    }
    
    input(o);
    //auto out = chrono::high_resolution_clock::now();
    auto pradz = chrono::high_resolution_clock::now();


    auto pr = chrono::high_resolution_clock::now();
    output(o);
    auto pa = chrono::high_resolution_clock::now();
    auto ilg = chrono::duration_cast<chrono::microseconds>(pa - pr);

    cout << endl;
    for (int i = 0; i < 5; i++) {
        //cout << "failo is " << fixed << int(1000 * pow(10, i)) << " skaiciu generavimas: " << dur[i] << endl;
        if (o == i + 1) {
            cout << "skaitymas is " << fixed << int(1000 * pow(10, i)) << " skaiciu failo: " << durg / double(1000000) << endl;
            cout << "rusiavimas " << fixed << int(1000 * pow(10, i)) << " skaiciu failo: " << durs / double(1000000) << endl;
            cout << "surusiuotu studentu is " << fixed << int(1000 * pow(10, i)) << " skaiciu failo spausdinimas: " << duro / double(1000000) << endl;
        }
    }
    auto pab = chrono::high_resolution_clock::now();
    auto truk = chrono::duration_cast<chrono::microseconds>(pab - pradz);
    cout << "visos programos laikas " << (truk.count()+durg) / double(1000000) << endl;
    system("pause");
}
