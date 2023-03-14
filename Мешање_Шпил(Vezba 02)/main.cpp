/*  Ognen Nikolovski INKi997 - Домашна задача / Печатење на сортиран шпил од карти, при потоа негово мешање со плус 2 Џокери

* Библиотеката <ctime> е стандардната библиотека во C++ која овозможува работа со временски функции и низи.
Оваа библиотека вклучува функции за работа со време како што се time(), ctime() и strftime(). Ни овозможува
мерење временски интервали, форматирање и парсирање на датуми и времиња и манипулирање со датуми и времиња.

 *  Во оваа програма застапена е во 39 линија ("time" и "NULL")

* Библиотеката cstdlib е стандардната библиотека во C++ која нуди различни функции за управување со меморијата, 
конверзии на броеви, генерирање на случајни броеви, и други. Во целост, cstdlib библиотеката е 
корисна за програмерите кои работат динамичка алокација на меморија, конверзии на броеви, 
генерирање на случајни броеви и извршување на команди на оперативниот систем.
  
 
 *  Во оваа програма е застапена во 29 линија (rand()) и исто така во 50 линија (srand(time(NULL)))
 * Ни овозможува рандом броеви врз основа на времето каде што моменталното време го претставува „Seed generator“.
 
 
*/

#include <iostream>
#include <cstdlib>
#include <ctime>
#include <string>
using namespace std;
const int DECK_SIZE = 54; // Големината на шпило плус 2 карти 
const int SUIT_SIZE = 13; 
string suits[6] = {"Hearts", "Diamonds", "Clubs", "Spades", "Joker One", "Joker Two"};
string ranks[SUIT_SIZE] = {"Ace", "2", "3", "4", "5", "6", "7", "8", "9", "10", "Jack", "Queen", "King"};

void shuffleDeck(string deck[], int size) { // Во Функцијата вршиме сортирање или поточно во овај случај. Мешање на карти
for (int i = 0; i < size; i++) {
int j = rand() % size;
swap(deck[i], deck[j]); // Функцијата swap() ни овозможува да си ги менаат местата (swap) каде што дава илузија на мешање на шпило

}
}
int main() {
string deck[DECK_SIZE];
int index = 0;
for (int i = 0; i < 4; i++) {
for (int j = 0; j < SUIT_SIZE; j++) {
    
deck[index] = ranks[j] + " of " + suits[i];
index++;
}} // Променливата deck е од типот на string така што ги групира suits и ranks, при тоа што го добиваме шпилот од карти.

deck[index] = suits[4]; index++;
deck[index] = suits[5]; 
// Ги додаваме двата Џокери во Шпило 
cout << "Cards of the deck:\n\n";

for (int i = 0; i < DECK_SIZE; i++) {
cout << deck[i] << endl; } // Првем го печати шпилот по ред.

srand(time(NULL)); // seed random number generator
cout << "\n\nShuffled Cards results:\n\n";

shuffleDeck(deck, DECK_SIZE);
for (int i = 0; i < DECK_SIZE; i++) {
cout << deck[i] << endl;    //Па го печати шпилот измешан.
}

return 0;}