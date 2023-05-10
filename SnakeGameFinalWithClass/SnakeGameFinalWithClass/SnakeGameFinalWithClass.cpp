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

    for (int i = 0; i < WIDHT; i++) { // �� ������ ������� � ���� ���� ������� ��� �� �������
        cout << "#";
    }cout << endl;
    for (int i = 0; i < HEIGHT; i++) { //�� ����� �� ����������� ������, �� ������ ������ ������ � ���� ���� ���������� �� ������ �� �������.
        for (int j = 0; j < WIDHT; j++) { 
            if (j == 0 || j == WIDHT - 1) {
                cout << "#";
            }
            else if (i == Snake.snakeY && j == Snake.snakeX) {

                cout << "O"; // � �� ����������� ��������� �� ������ ������� �������
            }
            else if (i == Snake.fruitY && j == Snake.fruitX) {
                cout << "F"; // F �� ����������� ��������� �� �������

            }
            else {
                bool print = false;
                for (int k = 0; k < Snake.ntail; k++) {
                    if (i == Snake.tailY[k] && j == Snake.tailX[k]) {
                        cout << "o"; // �� �������� ������ �� ������
                        print = true;
                    }
                } if (!print) { cout << " "; } // ��� ���������� ������ �� �� ����������� ����� �� ������ �������� ������ �� �������
            }

        }cout << endl;
    }

    for (int i = 0; i < WIDHT; i++) {
        cout << "#";
    }cout << endl << endl;
    cout << "Score: " << Snake.score << endl;
}
void Input(SnakeGameAssets& Snake) { //  ��������� ���� �� ������� �������� �� ������������ ���� (���������) � �� �� ������ �� ���������� �� ����������.
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
void Logic(SnakeGameAssets& Snake) { //  ��������� �� �������� �� ������� � ������ �� ������, ���� � �� ������������ �� ������� �� ��� ������ �� ������ �� �� ����� �� ����� � �� �����. 
    int prevX = Snake.tailX[0];     //   ������ � ��������� �� ����� � ����, ���� ��� ������ �� ������ �� ���� ��� ����� ������. ���� ������� �� ���������� �������� ����� ���� ��� ������� ����� �� �� �����, �� ������������ �� ��������� �� ���� ��� �� ������ �� ������ � ������� ������������ �� ��������� �� ����� �� ������ ���� ���.
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

    switch (Snake.sdir)         // �� �� ��������� �������� �� ������ �� ������ �� ����������� ������, �� ��������� �� Snake.sdir (�� �� ������ ����� �� �� ����� ������).
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
   // ��������� ���� ������ �� ���� ����� ��� ��������. ��� ��, ����� ������������ gameOver ��������� �� true � ������ �� ��������
    if (Snake.snakeX < 0 || Snake.snakeX > WIDHT || Snake.snakeY < 0 || Snake.snakeY>HEIGHT) {
        Snake.gameOver = true;
    }

    for (int i = 0; i < Snake.ntail; i++)
    {
        if (Snake.snakeX == Snake.tailX[i] && Snake.snakeY == Snake.tailY[i]) {
            Snake.gameOver = true;
        }
    }
    // �� ��������� ���� ������ �� ������� �������. �� ����� ����� �� ������� ���������� �� ��������� �� +1 � �� ��� �� ������.
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