#include <iostream>
#include <fstream>
#include <string.h>
#include <string>
#include <ctime>
using namespace std;

time_t start_time = time(0);
char* start_timestamp = ctime(&start_time);

struct student {
    string ime;
    string prezime;
    string indeks;
};

char tocniPrvi[4] = { 'c', 'c', 'a', 'a' };
char tocniVtori[4] = { 'c', 'a', 'c', 'c' };
char tocniTreti[4] = { 'a', 'b', 'a', 'c' };

// Funkcija koja se koristi za primanje na vlez

void studentInput(student& lice) {
    cout << "Vnesete go imeto na studentot: ";
    cin >> lice.ime;
    cout << "Vnesete go prezimeto na studentot: ";
    cin >> lice.prezime;

    do {
        cout << "Vnesete go indeksot na studentot: ";
        cin >> lice.indeks;
    } while (lice.indeks.size() < 3);

}


// Funkcija koja se koristi za zapishuvanje na odgovorot vo datoteka

void writeOdgovor(fstream& file, char odg, int br) {
    file << br << ". " << odg << endl;
}
// Funkcija koja se koristi za proverka na odgovorot i boduvanje

float checkOdgovor(int brojnaprasanje, char answer) {


    if (brojnaprasanje <= 4) {

        if (answer == tocniPrvi[brojnaprasanje - 1])
            return 1.5;

    }
    else if (brojnaprasanje > 4 && brojnaprasanje <= 8) {
        if (answer == tocniVtori[brojnaprasanje - 5])
            return 3;
    }
    else if (brojnaprasanje > 8 && brojnaprasanje <= 12) {
        if (answer == tocniTreti[brojnaprasanje - 9])
            return 8;
    }
}
// Funkcija koja ovozmozuva proverka na vnes kaj odgovorot i ispishuvanje na odgovorot vo datoteka

float handleInput(int brojprasanje, fstream& file) {

    char odgovor;
    if (brojprasanje <= 4) {
        do {
            cout << "Vashiot odgovor: ";
            cin >> odgovor;
        } while (odgovor != 'a' && odgovor != 'b' && odgovor != 'c');
        writeOdgovor(file, odgovor, brojprasanje);

    }
    else if (brojprasanje > 4 && brojprasanje <= 8) {
        do {
            cout << "Vashiot odgovor: ";
            cin >> odgovor;
        } while (odgovor != 'a' && odgovor != 'b' && odgovor != 'c' && odgovor != 'd');
        writeOdgovor(file, odgovor, brojprasanje);
    }
    else if (brojprasanje > 8 && brojprasanje <= 12) {
        do {
            cout << "Vashiot odgovor: ";
            cin >> odgovor;
        } while (odgovor != 'a' && odgovor != 'b' && odgovor != 'c' && odgovor != 'd' && odgovor != 'e');
        writeOdgovor(file, odgovor, brojprasanje);
    }

    return checkOdgovor(brojprasanje, odgovor);
}

// Funkcija koja se koristi za proverka na poeni i vrakanje na vrednosta na ocenkata

int score(float poeni) {
    if (poeni >= 0 && poeni <= 24)
        return 5;
    else if (poeni >= 25 && poeni <= 32)
        return 6;
    else if (poeni >= 32.5 && poeni <= 37)
        return 7;
    else if (poeni >= 37.5 && poeni <= 40.5)
        return 8;
    else if (poeni >= 41 && poeni <= 45)
        return 9;
    else if (poeni >= 45.5 && poeni <= 50)
        return 10;
}
void vtorfile(fstream& vvtorFile, student& lice, char* start_timestamp, float poeni)
{
    if (vvtorFile)
        vvtorFile << "Ime: " << lice.ime << endl;
    vvtorFile << "Prezime: " << lice.prezime << endl;
    vvtorFile << "Vreme na start: " << start_timestamp << endl;
    vvtorFile << "Poeni: " << poeni << endl;
    vvtorFile << "Ocenka:" << score(poeni) << endl;
    vvtorFile << "------------------------------------\n\n\n";

}

void KrajVreme_Poeni(fstream& vvtorFile, float poeni, string line)
{
    for (int i = 1; i < 4; i++)
    {
        getline(vvtorFile, line);
    }
    time_t end_time = time(0);
    char* end_timestamp = ctime(&end_time);
    streampos get_pos = vvtorFile.tellg(); // Get the current position of the get pointer
    streampos put_pos = vvtorFile.tellp();
    vvtorFile.seekp(put_pos);
    vvtorFile << "Kraj na ispit:" << end_timestamp;
    vvtorFile << "Poeni:" << poeni << endl;
    vvtorFile << "Ocenka:" << score(poeni)<<endl;

}
// Funkcija za pechatenje na tabela so tochnite odgovori

void answersTable() {
    cout << "Tocni odgovori na prasanjata se:" << endl;
    for (int i = 1; i <= 12; i++) {
        if (i <= 4)
            cout << i << ". " << tocniPrvi[i - 1] << endl;
        else if (i > 4 && i <= 8)
            cout << i << ". " << tocniVtori[i - 5] << endl;
        else if (i > 8 && i <= 12)
            cout << i << ". " << tocniTreti[i - 9] << endl;
    }
   
}

void fileCheck(fstream& file, string filename)
{
    file.open(filename.c_str(), ios::in);
    if (file)
    {
        cout << "Vasiot ispit veke e prisuten. Programata se isklucuva." << endl;
        exit(0);
    }
    file.close();
    cout << "Start time: " << start_timestamp << endl;
}

int main() {

    time_t now = time(0);
    char* timestamp = ctime(&now);
    timestamp[strlen(timestamp) - 1] = '\0';
    fstream file, test, students_log;
    student lice;
    string prasanje, line, line2;
    int brojnaprasanje = 1, countt = 1;
    float poeni = 0;
    studentInput(lice);
    const string filename = lice.ime + lice.prezime + "INKI" + lice.indeks;
    fileCheck(file, filename);
    // Kreiranje na datotekata so ime i prezime na studentot


    file.open(filename.c_str(), ios::out);
    vtorfile(file, lice, start_timestamp, poeni);
    file.close();
    students_log.open("Students_Log.txt", ios::in);

    if (students_log.is_open()) {
        while (getline(students_log, line)) {
            countt++;

        }
        students_log.close();
    }

    students_log.open("Students_Log.txt", ios::app);
    if (students_log.is_open())
    {


        timestamp[strlen(timestamp) - 1] = '\0';
        students_log << countt << ".  " << timestamp << "  " << lice.ime << ", " << lice.prezime << ", " << "INKI" << lice.indeks << endl;
    }
    students_log.close();
    // Otvoranje na datotekata so prasanja i prevzemanje na soodvetnoto prasanje i negovite odgovori

    test.open("prasanja.txt", ios::in);
    while (getline(test, prasanje)) {
        for (int i = 0; i < prasanje.size(); i++) {
            if (prasanje[i] == ';') {
                cout << endl;
                i++;
            }
            else
                cout << prasanje[i];
        }
        cout << endl;

        file.open(filename.c_str(), ios::app);
        poeni += handleInput(brojnaprasanje, file);
        file.close();
        brojnaprasanje++;
    }
    test.close();
    file.open(filename.c_str(), ios::in | ios::out);
    KrajVreme_Poeni(file, poeni, line2);
    file.close();

    cout << "\nVashata ocenka: " << score(poeni) << endl;
    time_t end_time = time(0);
    char* end_timestamp = ctime(&end_time);
    cout << "End time: " << end_timestamp;
    answersTable();

    return 0;
}

