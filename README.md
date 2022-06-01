Vektorius
====

Aprašymas v3.0  
==
Sukurta vector klasė

Testavimas
==
 std::vector<int> v;

    v.push_back(3);
    std::cout << v.size();
    std::vector<int> p=v;
    cout<<p[0];
    p.push_back(4);
    p.insert(1,5);
    cout<<p[1]<<" "<<p[2];
    p.pop_back();
    cout<<p.size();
    p.erase(0);
    cout<<p[0];
          
          
--Mano vektorius
        
    vector<int> v;
    v.push_back(3);
    std::cout << v.size();
    vector<int> p=v;
    cout<<p[0];
    p.push_back(4);
    p.insert(1,5);
    cout<<p[1]<<" "<<p[2];
    p.pop_back();
    cout<<p.size();
    p.erase(0);
    cout<<p[0];
    
rezultatai gaunami tie patys;

Instrukcijos 
==
Programos naudojimo gidas: 
1. Pasirenkama ar generuoti naują failą
2. Pasirenkama iš kokio dydžio failo skaityti
3. Faila nuskaito, surušiuoja pagal vardą, išskirsto į neveykelius ir kietekus ir atspausdina į **"kietekai.txt"** ir **"nevykeliai.txt"** failus
4. Norint naudoti mano vector klasę: užkomentuoti #include <vector> ir using std::vector **struktura.h** faile ir nuimti komentarus nuo **#include "vektorius.h"**
