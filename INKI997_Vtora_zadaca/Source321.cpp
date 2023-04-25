#include <iostream>
#include <cstdlib>
#include <fstream>
#include <string>
using namespace std;

int main() {
	fstream file;
	string recenica;
	cout << "Vneseteja vasata recenica:";
	getline(cin, recenica);
    file.open(recenica.c_str(), ios::in);
    if (file)
    {
        file.close();
        file.open(recenica.c_str(), ios::app);
        cout << "Fajlot veke e prisuten, se zapisuva recenicata sto ja zadadovte" << endl;
        file << recenica;
        file.close();
        exit(0);
        
        
    }
    else
    {
        file.open(recenica.c_str(), ios::out);
        cout << "Fajlot ne e prisuten, se kreira nov" << endl;
        file.close();
        exit(0);

    }   
}




