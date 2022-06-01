Vektorius
====

Aprašymas v3.0  
==
Sukurta vector klasė

Testavimas
==
    std::vector<int> v;
    v.push_back(3);
    cout <<"v.size() "<< v.size()<<endl;
    std::vector<int> p = v;
    cout<<"p[0] " << p[0]<<endl;
    p.push_back(4);
    p.insert(p.begin()+1, 5);
    cout <<"p[1] p[2] " << p[1] << " " << p[2] << endl;
    p.pop_back();
    cout<<"p.size() "<< p.size()<<endl;
    p.erase(p.begin());
    cout<<"p[0]" << p[0]<<endl;
    p.clear();
    cout<<"p.clear() size " << p.size()<<endl;
          
          
--Mano vektorius
        
    vector<int> v;
    v.push_back(3);
    cout <<"v.size() "<< v.size()<<endl;
    vector<int> p = v;
    cout<<"p[0] " << p[0]<<endl;
    p.push_back(4);
    p.insert(1, 5);
    cout <<"p[1] p[2] " << p[1] << " " << p[2] << endl;
    p.pop_back();
    cout<<"p.size() "<< p.size()<<endl;
    p.erase(0);
    cout<<"p[0]" << p[0]<<endl;
    p.clear();
    cout<<"p.clear() size " << p.size()<<endl;
    
rezultatai gaunami tie patys;

Instrukcijos 
==
Programos naudojimo gidas: 
1. Pasirenkama ar generuoti naują failą
2. Pasirenkama iš kokio dydžio failo skaityti
3. Faila nuskaito, surušiuoja pagal vardą, išskirsto į neveykelius ir kietekus ir atspausdina į **"kietekai.txt"** ir **"nevykeliai.txt"** failus
4. Norint naudoti mano vector klasę: užkomentuoti #include <vector> ir using std::vector **struktura.h** faile ir nuimti komentarus nuo **#include "vektorius.h"**
 //naudojau kaip pavyzdi https://www.youtube.com/watch?v=YpNCBw-cPWw&t=1300s
