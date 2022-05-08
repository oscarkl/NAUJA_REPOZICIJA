Pirmoji Užduotis - v1.0  
====

Aprašymas v1.0  
==
Ši programa paėma studento vardą, pavardę, namų darbų rezultatus ir egzamino rezultatą iš teksto failo ir apskaičiuoją vidurkį pagal šią formulę  
GalutinisVid = 0.4 * vidurkis + 0.6 egzaminas  
Taip pat galutinis vidurkis yra skaičiuojamas pagal medianą;  
GalutinisVid = 0.4 * mediana + 0.6 * egzaminas   
Teksto failą gailma naujai sugeneruoti ir tai sukurs 5 failus su dydžiais nuo 1000 iki 10000000  
Programa gavus visus duomenis išrūšiuoja studentus į dvi grupes: kietiakai ir nevykeliai ir tada juos išspausdina i 2 atskirus failus su studento vardu, pavardę ir abiejais galutinio vidurkio variantais  
Vietoj to, kad sukurt 2 naujus vektorius (ar list, ar deque) sukuriamas tik naujas 1 kuris laiko nevykelius ir iš pagrindinio jie ištrinami, paliekant tik kietekus
Taip pat ekrane spausdina programos veikimo laiką bei išskirsto jį į generavimą failų, skaitymą iš failo, rusiavima vektoriaus į dvi grupes, spausdinimą failo, visos programos veikimo laika  

Failai 
==
Užduotį sudaro **main.cpp** failas  
Kuriame viskas saugoma yra vektoriuose.   
**kursiokai.txt** failas iš kurio traukemi visi v0.2 uzduotyje duoti duomenys  
**ats.txt** failas kuriame spausdinami visi studentų duomenys  
**kietekai.txt** failas kuriame spausdinami visū studentų duomenys kurių vidurkis bent 5  
**nevykeliai.txt** failas kuriame spausdinami visū studentų duomenys kurių vidurkis mažiau nei 5  
**struktura.h** failas kuriame laikoma klases aprašymas  
**studentai.cpp** failas kuriame laikomos visos klases funkciju aprasymai
**1000.txt** 1000 studentų dydžio sugeneruotas failas  
**10000.txt** 10000 studentų dydžio sugeneruotas failas  
**100000.txt** 100000 studentų dydžio sugeneruotas failas  
**1000000.txt** 1000000 studentų dydžio sugeneruotas failas  
**10000000.txt**10000000 studentų dydžio sugeneruotas failas  
**vector.cpp** - main.cpp bet išimta įvesčių prašymas vykdymo laikui nepakeist  
**list.cpp** - vector.cpp bet vietoj vektoriu naudojama list  
**deque.cpp** - vector.cpp bet vietoj vektoriu naudojama deque 

Instrukcijos 
==
Programos naudojimo gidas: 
1. Pasirenkama kokią programą pasileisti (vector, list ar deque)
2. Paleidus programa iškart vykdomas greičio matavimas pasirinkto failo
3. jei pasirinkta generuoti tai sugeneruos 5 naujus failus su dydžiais nuo 1000 iki 10000000
4. Programa nuskaičius faila surušiuoja viską ir atspausdina duomenis i **"kietekai.txt"** ir **"nevykeliai.txt"** failus
5. išspausdina skaitymą iš failo, rūšiavimą studentų, spausdinimą studentų bei visos programos veikimo laikus

Palyginimas klases ir strukturu su 100k ir 1mil dydžio failu
==

Visos programos veikimo laikas
---
<pre>
          Klases          Strukturos
1mil      2.4             2.107
100k      0.244           0.211

išvada - strukturos greitesnes uz klase
