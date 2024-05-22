// Pong.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <time.h>
#include <conio.h>
using namespace std;

// enum for direction
enum eDir { STOP = 0, LEFT = 1, UPLEFT = 2, DOWNLEFT = 3, RIGHT = 4, UPRIGHT = 5, DOWNRIGHT = 6 };


// class for the ball and various functions including direction change and positions
class cBall
{
    int x, y;
    int originalX, originalY;
    eDir direction;

public:
    cBall(int posX, int posY) 
    {
        originalX = posX; // variable declaration for x and y pos
        originalY = posY;
        x = posX; y = posY;
        direction = STOP;
    }
    void Reset()
    {
        x = originalX; y = originalY;
        direction = STOP;   
    }
    void changeDir(eDir d)
    {
        direction = d;
    }
    void randDir() 
    {
        direction = (eDir)((rand() % 6) + 1); 
    }
    inline int getX() { return x;}
    inline int getY() { return y;}
    inline eDir getDir() { return direction; }
    
    void move() {
        switch (direction)
        {
            case STOP:
                break;
            case LEFT:
                x--;
                break;
            case RIGHT:
                x++;
                break;
            case UPLEFT:
                x--; y--;
                break;
            case DOWNLEFT:
                x--; y++;
                break;
            case UPRIGHT:
                x++; y--;
                break;
            case DOWNRIGHT:
                x++; y++;
                break;
            default:
                break;
        }
    }
    friend ostream& operator<<(ostream& o, cBall c)
    {
        o << "Ball [" << c.x << "," << c.y << "][" << c.direction << "]" << endl;
        return o;
    }

};

class Paddle
{
private:
    int x, y;
    int originalX, originalY;
public:
    Paddle()
    {
        x = y = 0;

    }
    Paddle(int posX, int posY) : Paddle()
    {
        originalX = posX;
        originalY = posY;
        x = posX;
        y = posY;
    }
    inline void Reset() { x = originalX; y = originalY; }
    inline int getX() { return x; }
    inline int getY() { return y; }
    inline void moveUp() { y--; }
    inline void moveDown() { y++; }
    friend ostream & operator<<(ostream& o, Paddle p)
    {
        o << "Paddle [" << p.x << "," << p.y << "]" << endl;
        return o;
    }
};

class gameManager
{
private:
    int width, height;
    int score1, score2;
    char up1, up2, down1, down2;
    bool quit;
    cBall* ball;
    Paddle* p1;
    Paddle* p2;

public:
    gameManager(int w, int h)
    {
        srand(time(NULL));
        quit = false;
        up1 = 'w'; up2 = 'i';
        down1 = 's'; down2 = 'k';
        score1 = score2 = 0;
        width = w; height = h;
        ball = new cBall(w / 2, h / 2);
        p1 = new Paddle(1, h / 2 - 3);
        p2 = new Paddle(w - 2, h / 2 - 3);
    }
    ~gameManager()
    {
        delete ball, p1, p2;
    }
    void scoreUp(Paddle* player)
    {
        if (player == p1)
            score1++;
        else if (player == p2)
            score2++;

        ball->Reset();
        p1->Reset();
        p2->Reset();
    }
    void Draw()
    {
        system("cls");
        for (int i = 0; i < width + 2; i++)
            cout << "\xB1";
        cout << endl;

        for (int i = 0; i < height; i++)
        {
            for (int j = 0; j < width; j++)
            {
                int ballx = ball->getX();
                int bally = ball->getY();
                int player1x = p1->getX();
                int player2x = p2->getX();
                int player1y = p1->getY();
                int player2y = p2->getY();

                if (j == 0)
                    cout << "\xB1";

                if (ballx == j && bally == i)
                    cout << "O"; //ball
                else if (player1x == j && player1y == i)
                    cout << "\xDB"; //player1
                else if (player2x == j && player2y == i)
                    cout << "\xDB"; //player2

                else if (player1x == j && player1y +1 == i)
                    cout << "\xDB"; //player1
                else if (player1x == j && player1y +2 == i)
                    cout << "\xDB"; //player1
                else if (player1x == j && player1y +3 == i)
                    cout << "\xDB"; //player1
               
                else if (player2x == j && player2y + 1 == i)
                    cout << "\xDB"; //player2
                else if (player2x == j && player2y + 2 == i)
                    cout << "\xDB"; //player2
                else if (player2x == j && player2y + 3 == i)
                    cout << "\xDB"; //player2

                else
                    cout << " ";

                if (j == width - 1)
                    cout << "\xB1";
            }
            cout << endl;
        }

        for (int i = 0; i < width + 2; i++)
            cout << "\xB1";
        cout << endl;

        cout << "P1: " << score1 << endl << "P2: " << score2 << endl;

    }
    void Input()
    {
        ball->move();

        int ballx = ball->getX();
        int bally = ball->getY();
        int player1x = p1->getX();
        int player2x = p2->getX();
        int player1y = p1->getY();
        int player2y = p2->getY();

        if (_kbhit())
        {
            char current = _getch();
            if (current == up1)
                if (player1y > 0)
                    p1->moveUp();
            if (current == up2)
                if (player2y > 0)
                    p2->moveUp();
            if (current == down1)
                if (player1y + 4 < height )
                    p1->moveDown();
            if (current == down2)
                if (player2y + 4 < height)
                    p2->moveDown();

            if (ball->getDir() == STOP)
                ball->randDir();

            if (current == 'q')
                quit = true;

        }

   
    }
    void Logic()
    {

        int ballx = ball->getX();
        int bally = ball->getY();
        int player1x = p1->getX();
        int player2x = p2->getX();
        int player1y = p1->getY();
        int player2y = p2->getY();

        // left paddle
        for (int i = 0; i < 4; i++)
            if (ballx == player1x + 1)
                if (bally == player1y + i)
                    ball->changeDir((eDir)((rand() % 3) +4));

        // right paddle
        for (int i = 0; i < 4; i++)
            if (ballx == player2x - 1)
                if (bally == player2y + i)
                    ball->changeDir((eDir)((rand() % 3) + 1));

        // bottom wall
        if (bally == height - 1)
            ball->changeDir(ball->getDir() == DOWNRIGHT ? UPRIGHT : UPLEFT);
        // top wall
        if (bally == 0)
            ball->changeDir(ball->getDir() == UPRIGHT ? DOWNRIGHT : DOWNLEFT);
        // right wall
        if (ballx == width - 1)
            scoreUp(p1);
        // left wall
        if (ballx == 0)
            scoreUp(p2);
    }

    void Run()
    {
        while (!quit)
        {
            Draw();
            Input();
            Logic();
        }
    }
};
int main()
{
    gameManager c(40, 20);

    c.Run();

    return 0;
}

