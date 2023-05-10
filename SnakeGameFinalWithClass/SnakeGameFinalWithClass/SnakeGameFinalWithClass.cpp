#include <iostream>
#include <conio.h>
#include <windows.h>
#define HEIGHT 20
#define WIDHT 20
// Potrebnite Funkcii za da funkcionira samata programa
using namespace std;

// Vo klasata se pretstaveni samite asssets kade sto se primenuvaat vo narednite funckii za realizacija na igrata
class SnakeGameAssets {
private:
    int snakeX=0, snakeY=0, fruitX=0, fruitY=0, score = 0;
    int tailX[100]={}, tailY[100] = {}, ntail = 0;

    enum  sDirection { STOP = 0, UP, DOWN, LEFT, RIGHT };
    sDirection sdir;

    friend void Setup(SnakeGameAssets& Snake);
    friend void Draw(SnakeGameAssets& Snake);
    friend void Input(SnakeGameAssets& Snake);
    friend void Logic(SnakeGameAssets& Snake);
public:
    bool gameOver = false;

};
// Pocetna funkcija kade  gi definira vrednostite na SnakeGameAssets
void Setup(SnakeGameAssets& Snake) {
    Snake.gameOver = false;
    Snake.sdir = Snake.STOP;
    Snake.snakeX = WIDHT / 2;
    Snake.snakeY = HEIGHT / 2;
    Snake.fruitX = rand() % (WIDHT - 2) + 1;;
    Snake.fruitY = rand() % (HEIGHT - 2) + 1;
}
void Draw(SnakeGameAssets& Snake) {
    system("CLS");

    for (int i = 0; i < WIDHT; i++) { // Се печати горниот и исто така долниот дел од рамката
        cout << "#";
    }cout << endl;
    for (int i = 0; i < HEIGHT; i++) { //Со помош на вгнездениот циклус, се печати целата рамкка и исто така елементите на змијата со храната.
        for (int j = 0; j < WIDHT; j++) { 
            if (j == 0 || j == WIDHT - 1) {
                cout << "#";
            }
            else if (i == Snake.snakeY && j == Snake.snakeX) {

                cout << "O"; // О ја претставува позицијата на змијата поточно главата
            }
            else if (i == Snake.fruitY && j == Snake.fruitX) {
                cout << "F"; // F ја претставува позицијата на храната

            }
            else {
                bool print = false;
                for (int k = 0; k < Snake.ntail; k++) {
                    if (i == Snake.tailY[k] && j == Snake.tailX[k]) {
                        cout << "o"; // се испишува телото на змијата
                        print = true;
                    }
                } if (!print) { cout << " "; } // ако останатите услови не се исполнуваат тогаш се печати празнина внатре во рамката
            }

        }cout << endl;
    }

    for (int i = 0; i < WIDHT; i++) {
        cout << "#";
    }cout << endl << endl;
    cout << "Score: " << Snake.score << endl;
}
void Input(SnakeGameAssets& Snake) { //  функцијата може да прочита податоци од стандардниот влез (тастатура) и да ги додели на променливи во програмата.
    if (_kbhit()) {
        switch (_getch())
        {
        case 'w':
            Snake.sdir = Snake.UP;
            break;

        case 'a':

            Snake.sdir = Snake.LEFT;
            break;

        case 'd':
            Snake.sdir = Snake.RIGHT;
            break;

        case 's':
            Snake.sdir = Snake.DOWN;
            break;


        default:
            break;
        }
    }

}
void Logic(SnakeGameAssets& Snake) { //  одговорна за движењето на главата и телото на змијата, како и за забележување на местата на кои змијата би можела да се храни со храна и да расте. 
    int prevX = Snake.tailX[0];     //   Змијата е составена од глава и тело, каде што телото се состои од еден или повеќе делови. Оваа функција го пресметува следното место каде што главата треба да се движи, со пресметување на позициите на секој дел од телото на змијата и нивното придвижување на позицијата на делот од змијата пред нив.
    int prevY = Snake.tailY[0];
    Snake.tailX[0] = Snake.snakeX;
    Snake.tailY[0] = Snake.snakeY;
    int prev2X, prev2Y;
    for (int i = 1; i < Snake.ntail; i++) {
        prev2X = Snake.tailX[i];
        prev2Y = Snake.tailY[i];
        Snake.tailX[i] = prevX;
        Snake.tailY[i] = prevY;
        prevX = prev2X;
        prevY = prev2Y;
    }

    switch (Snake.sdir)         // кој го променува правецот на движење на змијата во соодветната насока, во зависност од Snake.sdir (во кој правец треба да се движи змијата).
    {

    case Snake.UP:
        Snake.snakeY--;
        break;

    case Snake.DOWN:
        Snake.snakeY++;
        break;

    case Snake.LEFT:
        Snake.snakeX--;
        break;

    case Snake.RIGHT:
        Snake.snakeX++;
        break;
    default:
        break;
    }
   // Проверува дали змијата го удри ѕидот или опашката. Ако да, тогаш променливата gameOver преминува во true и играта се завршува
    if (Snake.snakeX < 0 || Snake.snakeX > WIDHT || Snake.snakeY < 0 || Snake.snakeY>HEIGHT) {
        Snake.gameOver = true;
    }

    for (int i = 0; i < Snake.ntail; i++)
    {
        if (Snake.snakeX == Snake.tailX[i] && Snake.snakeY == Snake.tailY[i]) {
            Snake.gameOver = true;
        }
    }
    // Се проверува дали змијата ја изедете храната. Со секое јадење на храната резултатот се зголемува за +1 и за крај го печати.
    if (Snake.snakeX == Snake.fruitX && Snake.snakeY == Snake.fruitY)
    {
        Snake.score += 1;
        Snake.fruitX = rand() % (WIDHT - 2) + 1;;
        Snake.fruitY = rand() % (HEIGHT - 2) + 1;
        Snake.ntail++;
    }
}

int main()
{
    SnakeGameAssets Snake;
    Setup(Snake);
    while (!Snake.gameOver) {
        srand(time(NULL));
        Draw(Snake);
        Input(Snake);
        Logic(Snake);
        Sleep(50);
    }
    return EXIT_SUCCESS;
}