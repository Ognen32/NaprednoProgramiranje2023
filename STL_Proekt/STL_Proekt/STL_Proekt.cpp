#include <iostream>
#include <fstream>
#include <unordered_map>
#include <string>
#include <vector>
#include <algorithm>
#include <iterator>
using namespace std;
//Potrebnite biblioteki za da ni funcionira programata i isto taka using namespace std; za da bidi kodot polesen za razbiranje i gledanje
int main() {
    // Se kreira mapata kade sto e od tip unordered kade sto so toa znaci deka nema da bidi potredena po stringot
    unordered_map<string, float> myMap{
      {"Skopje", 0},
      {"Bitola", 0},
      {"Stip", 0},
      {"Prilep", 0},
      {"Kumanovo", 0},
      {"Kicevo", 0},
      {"Ohrid", 0},
      {"Tetovo", 0}
    };

    // Programata go prasva korisnikot za koj den saka da bidat ispisani temperaturite vo gradovite
    cout << "!!Programa za ispisuvanje na temperaturite od 8 grada za mesecot maj.!!\n";
    int lineNumber;
    cout << "\nNapisete go denot na mesecot.(Mesecot Maj ima 31 dena.)\n";
    cin >> lineNumber;

    // Vo ovaj del se vrvat site prvi para ili potocno stringovi od mapata.
    for (auto& pair : myMap) {
        // Sekoj pat koke se vrvi eden string, se otvora togas potrebnata datoteka za da se prevzemi potrebniot den so temperatura od odredeniot grad
        string filename = pair.first + ".txt";
        ifstream inputFile(filename); // se vcituva fajlot kako na primer

        // So pomos na for loopot(vgnezden for loop), tuka se zema potrebnata linija od text fajlot  kade sto se naoga tempreraturata za toj den
        string line;
        for (int j = 1; j <= lineNumber; j++) {
            getline(inputFile, line);
        }

        // Se zemaa temperaturata za gradot, no za da ja pretvori od string vo cel broj(int) ja koristime komandata stoi() kade sto sekoj string vo forma na broj, se konverti vo int
        int value = stoi(line);
        pair.second = value;
    }

    // Mapata se ispizuva vo konzolata nepodredena
    cout << "Nepodredena mapa:" << endl;
    for (const auto& pair : myMap) {
        cout << pair.first << ": " << pair.second << " C " << endl;
    }

    // Nareden cekor e da kreirame vector kade sto ke gi prevzemi site para od nepodredenata mapa
    vector<pair<string, int>> pairs(myMap.begin(), myMap.end());

    // So pomos na vektorot, mozime da ja podredime mapata preku goleminata na temperaturata ili potocno se kazuva deka vektorot e podreden od strana na int vo mapata
    sort(pairs.begin(), pairs.end(), [](const auto& a, const auto& b) {
        return a.second > b.second;
        });

    // Pecatenje na sortiraniot vector
    cout << "\nMapata sortirana po vrednosta na temperaturi:" << endl;
    for (const auto& pair : pairs) {
        cout << pair.first << ": " << pair.second << " C " << endl;
    }

    // Programata bara od korisnikot da se napise negovoto Ime, Prezime i isto taka broj na index.
    string inki= "INKI", Ime="Ognen", prezime = "Nikolovski";
    float id, temp2, data;

    cout << "\nNapisi go vaseto ime, prezime i isto taka brojot od indeksot: ";
    cin >> Ime >> prezime >> id;
    int idint = (int)id;

    cout << "Napisidata na raganje:\n na primer: 19.01\n";
    cin >> data;

    // Se kreira biblioteka kade sto ke se zacuvaat temperaturite za site gradovi vo toj den
    fstream datoteka;
    string idd = to_string(idint); // Konverzija na int vo string
    string file = inki + "_" + idd + Ime + "_" + prezime + ".txt";
    datoteka.open(file.c_str(), ios::out);
    for (const auto& pair : myMap) {
        datoteka << pair.first << ": " << pair.second << " C " << endl;
    }
    

    // Dodavame uste plus dva para vo nasata mapa kade sto ke bidat ispisani posledni vo dadotekata
    myMap["INKI"] = id;
    myMap[Ime] = data;
    datoteka << "\nPoslednite dva elementi od dadotekata:" << endl;
    auto it = std::prev(myMap.end(), 2); // so pomos na iteratorot, odime 2 para pred krajot od mapata. 
    datoteka << it->first << "," << it->second << endl; // se ispisuva predposledniot 
    ++it; // se zgolemuva za za eden kade sto so to ke ne odnesi do posledniot par od mapata
    datoteka << it->first << " " << it->second << endl; // se ispisuva posledniot par vo datotekata

    return EXIT_SUCCESS;
}
