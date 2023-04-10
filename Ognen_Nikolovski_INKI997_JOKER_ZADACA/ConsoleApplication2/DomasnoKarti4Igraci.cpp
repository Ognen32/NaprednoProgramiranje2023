// DomasnoKarti4Igraci.cpp : This file contains the 'main' function. Program execution begins and ends there.
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <string>
using namespace std;
#define Deck_Size 52

// Card struktura
struct Card {
    int rank;
    char suit;
};

// Deck struktura
struct Deck {
    Card cards[Deck_Size];
    int brojKarti;
    size_t i = 0;
    char a;
};


// Function za sozdavanje na deck 
void createDeck(Deck& deck) {
    deck.brojKarti = 52;
    int index = 0;
    for (int rank = 1; rank <= 13; ++rank) {
        deck.cards[index].rank = rank;
        deck.cards[index].suit = 'S';
        ++index;
        deck.cards[index].rank = rank;
        deck.cards[index].suit = 'H';
        ++index;
        deck.cards[index].rank = rank;
        deck.cards[index].suit = 'C';
        ++index;
        deck.cards[index].rank = rank;
        deck.cards[index].suit = 'D';
        ++index;
    }
}

// Funkcija za print na card
void printCard(const Card& card) {
    if (card.rank >= 2 && card.rank <= 10) {
        cout << card.rank;
    }
    else {
        switch (card.rank) {
        case 1:
            cout << 'A';
            break;
        case 11:
            cout << 'J';
            break;
        case 12:
            cout << 'Q';
            break;
        case 13:
            cout << 'K';
            break;
        default:
            cout << '?';
            break;
        }
    }
    cout << card.suit;
}

// Funkcija  za print na deck
void PrintDeck(Deck& deck) {
    for (int i = 0; i < Deck_Size; ++i) {
        printCard(deck.cards[i]);
        cout << " ";
        if ((i + 1) % 13 == 0) {
            cout << endl;
        }
    }
    cout << endl;
}

// Function to shuffle the deck
void shuffleDeck(Deck& deck) {
    for (int i = 0; i < deck.brojKarti; ++i) {
        int j = rand() % deck.brojKarti;
        Card temp = deck.cards[i];
        deck.cards[i] = deck.cards[j];
        deck.cards[j] = temp;
    }
}


// Funkcija za delenje na spilot na 4 igraci
void dealCards(Deck& deck) {
    int brojIgraci = 4;
    string boi[4] = {"\033[32m","\033[33m","\033[38;5;208m","\033[38;2;255;102;0m"}; //Zelena, Zoltra, Portokalova, Temna portokalova.
    int kartiNaIgrac = deck.brojKarti / brojIgraci;
    for (int i = 0; i < brojIgraci; ++i) {
        cout << boi[i];
        cout << "Player " << i + 1 << " cards: ";
        for (int j = 0; j < kartiNaIgrac; ++j) {
            int index = i * kartiNaIgrac + j;
            printCard(deck.cards[index]);
            cout << " ";
        }
        cout << "\033[0m";
        cout << endl;
    }
}

int main() {
   
    Deck deck;
    createDeck(deck);
    PrintDeck(deck);
    srand(time(NULL));
    shuffleDeck(deck);
    PrintDeck(deck);

    while (deck.i != 1)
    {
        
        cout << "Vnesi P, Q ili C.";
            cin >> deck.a;
            if (deck.a == 'P' || deck.a == 'p')

            {   
                dealCards(deck);
                shuffleDeck(deck);
                
            }
            else if (deck.a == 'C' || deck.a == 'c')
            {
#ifdef _WIN32
                system("cls");
#elif defined(__linux__) || defined(__APPLE__)
                system("clear");
#endif
                createDeck(deck);
                PrintDeck(deck);
            }
        else 
        {
            deck.i++;
            return 0;
        }
            
    }
}
